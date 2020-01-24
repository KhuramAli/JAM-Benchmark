/*
******************************************************************************
wav2mp3 1.xx
Wav to mp3 converter
Oct 06 2019
Developed by: Khuram Ali
******************************************************************************
*/


#include "lameWrapper.h"
#include <mutex>


static std::mutex encoderMutex;

int saveConvertedFile(lame_global_flags *gf, const PW::fmtChunk &fmt,
                      const PW::channls &pcm, int dataSize,
                      const std::string &filename) {
  const int dataSampleSize = dataSize / fmt.blockAlign;

  const int mp3BufferSize = dataSampleSize * 5 / 4 + 7200;
  auto *mp3Buffer = new unsigned char[mp3BufferSize];

  // converting to mp3 with LAME
  const int mp3size = lame_encode_buffer(gf, pcm.channel_1, pcm.channel_2,
                                   dataSampleSize, mp3Buffer, mp3BufferSize);
  if (mp3size <= 0) {
    delete[] mp3Buffer;
    std::cerr << "WAV data is not encoded by lame_encode_buffer. Return code: "
              << mp3size << '\n';
    return 1;
  }

  // writing encoded data to file.
  std::ofstream file;
  file.open(filename, std::ios::out | std::ios::binary);
  file.write(reinterpret_cast<char*>(mp3Buffer), mp3size);

  // get flush buffers.
  const int flushSize = lame_encode_flush(gf, mp3Buffer, mp3BufferSize);

  // write flushed buffers to file
  file.write(reinterpret_cast<char *>(mp3Buffer), flushSize);

  file.flush();
  file.close();
  delete[] mp3Buffer;
  return 0;
}

void *encoder(void *arg) {
  auto *args = static_cast<encoderArgs *>(arg); // parse arguments struct

  while (true) {
	  // determine which file to process next
	  bool foundWork = false;
	  int fileId = -1;

	  {
		  std::lock_guard<std::mutex> lock(encoderMutex);
		  for (int i = 0; i < args->numFiles; i++) {
			  if (!args->filesFinished.at(i)) {
				  args->filesFinished[i] = true; // mark as being worked on
				  fileId = i;
				  foundWork = true;
				  break;
			  }
		  }
	  }

	  // if still have work to do
	  if (!foundWork) {
		  return nullptr;
	  }
	  // adding file name and extension.
	  std::string myFile = args->filenames->at(fileId);
	  std::string myFileOut = myFile.substr(0, myFile.length() - 3) + "mp3";

	  // start working
	  PW::fmtChunk fmt;
	  PW::channls pcm;
	  // init encoding params
	  lame_global_flags* gf = lame_init();
	  lame_set_brate(gf, 192); // increase bitrate
	  lame_set_quality(gf, 2); // increase quality level
	  lame_set_bWriteVbrTag(gf, 0);

	  // parse wave file
	  int dataSize = -1;
	  if (PW::parseWave(myFile, fmt, pcm, dataSize) > 0) {
		  std::cerr << "Error in file" << myFile << ". Skipping.\n";
		  continue; // if there's more to do
	  }

	  lame_set_num_channels(gf, fmt.numOfChannel);
	  lame_set_num_samples(gf, dataSize / fmt.blockAlign);

	  if (lame_init_params(gf) != 0) {
		  std::cerr << "Invalid encoding parameters! Skipping file.\n";
		  continue;
	  }

	  // encode to mp3
	  if (saveConvertedFile(gf, fmt, pcm, dataSize, myFileOut) != 0) {
		  std::cerr << "Unable to encode mp3: " << myFileOut << '\n';
		  continue;
	  }
	{
	  std::lock_guard<std::mutex> lock(encoderMutex);
	  std::cout << args->threadId << " : " << myFile << " ...Done!\n";
	}
    ++args->processedFiles;

    lame_close(gf);
  }
}

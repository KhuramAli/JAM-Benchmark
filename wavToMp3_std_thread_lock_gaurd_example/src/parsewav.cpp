/*
******************************************************************************
wav2mp3 1.xx
Wav to mp3 converter
Oct 06 2019
Developed by: Khuram Ali
******************************************************************************
*/

#include "parsewav.h"
#include <cstring>

int PW::parseWave(const std::string &fileName, fmtChunk &fmt, channls &pcm,
                  int &dataSize) {
  std::ifstream file;
  file.open(fileName, std::ios::binary | std::ios::in);
  if (!file.is_open()) {
    std::cerr << "unable to open wave file: " << fileName << '\n';
    return 1;
  }

  file.seekg(0, std::ios::beg); // ensure that we are at the start of file.
  RiffHeader riff;
  file.read(reinterpret_cast<char *>(&riff), RIFF_HEADER_SIZE);
  // checking if we have a valid RIFF header.
  if (strncmp(riff.chunkId, "RIFF", 4) != 0 ||
      strncmp(riff.format, "WAVE", 4) != 0 || riff.chunkSize == 0) {
    std::cerr << "Invalid RIFF header.\n";
    file.close();
    return 1;
  }
  // std::cout << "RIFF header validated.\n";
  // read fmt sub chunk
  file.seekg(RIFF_HEADER_SIZE);
  file.read(reinterpret_cast<char *>(&fmt), FMT_CHUNK_SIZE);
  // checking if we have a valid fmt sub chunk
  /*
  std::cout << "***************\n";
  std::cout << "subChunkId: " <<fmt.subChunkID << '\n';
  std::cout << "subChunk1Size: " << fmt.subChunk1Size << '\n';
  std::cout << "samplesPerSec: " << fmt.samplesPerSec << '\n';
  std::cout << "numOfChannel: " << fmt.numOfChannel << '\n';
  std::cout << "bytesPerSec: " << fmt.bytesPerSec << '\n';
  std::cout << "blockAlign: " << fmt.blockAlign << '\n';
  std::cout << "bitsPerSample: " << fmt.bitsPerSample << '\n';
  std::cout << "audioFormat: " << fmt.audioFormat << '\n';
  */
  if (strncmp(fmt.subChunkID, "fmt", 3) != 0) {
    std::cerr << "Invalid FMT sub Chunk.\n";
    file.close();
    return 1;
  }
  if (fmt.numOfChannel == 0 || fmt.numOfChannel > 2) {
    std::cerr << "Invalid number of channels: " << fmt.numOfChannel << '\n';
    file.close();
    return 1;
  }
  if (fmt.audioFormat != 1) {
    std::cerr << "Only PCM format is supported.\n";
    file.close();
    return 1;
  }
  // std::cout << "FMT sub Chunk is validated.\n";
  // read data sub chunk
  dataChunk dchnk;
  file.seekg(RIFF_HEADER_SIZE + FMT_CHUNK_SIZE);
  file.read(reinterpret_cast<char *>(&dchnk), DATA_CHUNK_SIZE);
  // checking if we have a valid data sub chunk
  if (strncmp(dchnk.subchunk2ID, "data", 4) != 0) {
    std::cerr << "Invalid Data Sub Chunk.\n";
    file.close();
    return 1;
  }
  // std::cout << "Data sub Chunk is validated.\n";
  dataSize = static_cast<int>(dchnk.subchunk2Size);
  // PCM channels
  pcm.channel_1 =
      new int16_t[dchnk.subchunk2Size / fmt.numOfChannel / sizeof(int16_t)];
  if (pcm.channel_1 == nullptr) {
    std::cerr << "Bad allocation.\n";
    return 1;
  }
  // if we have stereo
  if (fmt.numOfChannel > 1) {
    pcm.channel_2 =
        new int16_t[dchnk.subchunk2Size / fmt.numOfChannel / sizeof(int16_t)];
    if (pcm.channel_2 == nullptr) {
      std::cerr << "Bad allocation.\n";
      return 1;
    }
  }

  // std::cout << "Reading data...\n";
  // read data
  const int dataSampleSize = dchnk.subchunk2Size / fmt.blockAlign;
  const int blockSize = fmt.blockAlign / fmt.numOfChannel;
  file.seekg(RIFF_HEADER_SIZE + FMT_CHUNK_SIZE + DATA_CHUNK_SIZE);
  if (fmt.numOfChannel == 1) {
    file.read(reinterpret_cast<char *>(pcm.channel_1),
              fmt.blockAlign * dataSampleSize);
  } else {
    for (int i = 0; i < dataSampleSize; ++i) {
      file.read(reinterpret_cast<char *>(&pcm.channel_1[i]), blockSize);
      // if stereo
      if (fmt.numOfChannel > 1) {
        file.read(reinterpret_cast<char *>(&pcm.channel_2[i]), blockSize);
      }
    }
  }
  // checking if stereo data is read correctly if applicable.
  if (fmt.numOfChannel > 1 && pcm.channel_2 == nullptr) {
    std::cerr << "unable to read stereo data.\n";
    return 1;
  }
  file.close();
  return 0;
}

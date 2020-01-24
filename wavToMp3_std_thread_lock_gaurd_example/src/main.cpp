/*
******************************************************************************
wav2mp3 1.xx
Wav to mp3 converter
Oct 06 2019
Developed by: Khuram Ali
******************************************************************************
*/



#include "lameWrapper.h"
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <thread>
#include <vector>


void getWavFiles(const std::string &path, std::vector<std::string> &fileList) {
  std::string fileExt;
  for (const auto &entry : std::filesystem::directory_iterator(path)) {
    if (entry.path().has_extension()) {
      fileExt = entry.path().extension().string();
      std::transform(fileExt.begin(), fileExt.end(), fileExt.begin(),
                     [](unsigned char c) noexcept { return std::tolower(c); } );
      if (fileExt == ".wav") {
        fileList.push_back(entry.path().string());
      }
    }
  }
}

int main(int argc, char **argv) {
	int numThreads = static_cast<int>(std::thread::hardware_concurrency()) ;
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " PATH [-jN]\n";
    std::cerr << "   PATH   required. Program looks here for .WAV files to "
                 "convert to .MP3.\n";
    std::cerr << "   [-jN]  optional. If specified, N threads will be used.\n";
    return 1;
  }
  std::cout << "Using LAME Library Version: " << get_lame_version() << '\n';
  // checking for -j options
  if (argc == 3) {
	  std::string arg2 = { argv[2] };
	  if (std::tolower(arg2.at(1)) == 'j') {
      arg2.erase(0, 2);
      if (std::atoi(arg2.c_str()) != 0) {
        numThreads = std::atoi(arg2.c_str());
      }
    }
  }
  std::cout << "Using " << numThreads << " Threads.\n";
  std::vector<std::string> wavFiles;
  getWavFiles(argv[1], wavFiles);
  const int numFiles = static_cast<int>(wavFiles.size());
  std::cout << "Found " << numFiles << " wave file(s) in " << argv[1] << '\n';
  if (numFiles <= 0) {
    return 0;
  }
  // initialize status of files to be converted.
  std::vector<bool> filesFinished(numFiles, false);

  // initialize threads and argument arrays
  std::vector<std::thread> threads;
  auto *threadArgs = new encoderArgs[numThreads];
  for (int i = 0; i < numThreads; ++i) {
    threadArgs[i].numFiles = numFiles;
    threadArgs[i].filenames = &wavFiles;
    threadArgs[i].filesFinished = filesFinished;
    threadArgs[i].threadId = i;
    threadArgs[i].processedFiles = 0;
  }

  // creating worker threads.
  for (int i = 0; i < numThreads; ++i) {
	  threads.push_back(std::thread(encoder, &threadArgs[i]));
  }
  std::cout << threads.size();
  // joining worker threads.
  for (auto& th : threads) {
    th.join();
  }

  // write results.
  for (int i = 0; i < numThreads; ++i) {
    std::cout << "Thread Number: " << i << " converted "
              << threadArgs[i].processedFiles << " files.\n";
  }
  std::cout << "Done.\n";

  return 0;
}

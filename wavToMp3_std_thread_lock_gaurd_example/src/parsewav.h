#ifndef PARSEWAV_H
#define PARSEWAV_H

/*
******************************************************************************
wav2mp3 1.xx
Wav to mp3 converter
Oct 06 2019
Developed by: Khuram Ali
******************************************************************************
*/


#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

namespace PW {

/*
 * Wave Format taken from http://soundfile.sapp.org/doc/WaveFormat/
 */

constexpr int RIFF_HEADER_SIZE = 12;
constexpr int FMT_CHUNK_SIZE = 24;
constexpr int DATA_CHUNK_SIZE = 8;

typedef struct {
  char chunkId[4] = {0};  // it should be "RIFF"
  uint32_t chunkSize = 0; // it is size of file - (file + chunkId).
  char format[4] = {0};   // it should be "WAVE" in our case.
} RiffHeader;

typedef struct {
  char subChunkID[4] = {0};   // fmt subchunk id.
  uint32_t subChunk1Size = 0; // Size of the fmt chunk
  uint16_t audioFormat = 0;   // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM
                              // Mu-Law, 258=IBM A-Law, 259=ADPCM
  uint16_t numOfChannel = 0;  // Number of channels 1=Mono 2=Stereo
  uint32_t samplesPerSec = 0; // Sampling Frequency in Hz
  uint32_t bytesPerSec = 0;   // bytes per second
  uint16_t blockAlign = 0;    // 2=16-bit mono, 4=16-bit stereo
  uint16_t bitsPerSample = 0; // Number of bits per sample
} fmtChunk;

typedef struct {
  char subchunk2ID[4] = {0};  // it should be "data"
  uint32_t subchunk2Size = 0; // Sampled data length
} dataChunk;

typedef struct {
  int16_t *channel_1 = nullptr; // left stereo or mono PCM array
  int16_t *channel_2 =
      nullptr; // right stereo or null in case of mono, PCM array
} channls;

int parseWave(const std::string &fileName, fmtChunk &fmt, channls &pcm,
              int &dataSize);
} // namespace PW

#endif // PARSEWAV_H

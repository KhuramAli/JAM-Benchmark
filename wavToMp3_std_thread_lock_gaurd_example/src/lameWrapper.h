#ifndef __LAME_WRAPPER_H_
#define __LAME_WRAPPER_H_

/*
******************************************************************************
wav2mp3 1.xx
Wav to mp3 converter
Oct 06 2019
Developed by: Khuram Ali
******************************************************************************
*/

#include "lame.h"
#include "parsewav.h"
#include <sstream>
#include <vector>
#include <thread>

/*
 * POSIX-compliant argument struct for worker function 'encoder'.
 */
typedef struct {
  std::vector<std::string> *filenames = nullptr;
  std::vector<bool> filesFinished;
  int numFiles = 0;
  int threadId = 0;
  int processedFiles = 0;
} encoderArgs;

/* POSIX-compliant worker function
 * take a list of files names and convert them to mp3.
 */
void *encoder(void *arg);

/* Wrapper function to LAME.
 *  take input data from parsewave, and convert and save it to mp3 format.
 *  Called LAME functions internally,
 * lame_encode_buffer, lame_encode_flush, and lame_mp3_tags_fid
 */
int saveConvertedFile(lame_global_flags *gf, const PW::fmtChunk &fmt,
                      const PW::channls &pcm, int dataSize,
                      const std::string &fileName);
#endif // __LAME_WRAPPER_H_

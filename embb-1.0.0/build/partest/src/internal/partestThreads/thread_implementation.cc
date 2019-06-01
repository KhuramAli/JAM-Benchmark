/*
 * Copyright (c) 2014, Siemens AG. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include<partest/internal/partestThreads/thread_implementation.h>

namespace partest {
namespace internal {
namespace partestthreads {

#ifdef PARTEST_THREADING_WINTHREADS

/**
 * Is used to offer a consistent thread start function signature. Windows threads
 * have a different signature than Pthreads and C11. This internal start
 * function for Windows threads just calls the client start function with given
 * argument.
 */
DWORD WINAPI InternalThreadStart(LPVOID internalArg) {
  int result = ((PartestInternalThreadArgs*)internalArg)->func(
      ((PartestInternalThreadArgs*)internalArg)->arg);
#if ! defined(__cplusplus)
  ExitThread((DWORD)result); /* In C, the return of result code doesn't work */
#endif
  return (DWORD)result;
}

bool ThreadImplementation::Create_thread(int(*function)(void*),void * args) {
  threadArgs_ = new PartestInternalThreadArgs;

  threadArgs_->func = function;
  threadArgs_->arg = args;

  threadHandle_ = CreateThread(
      0, /* no security */
      0, /* default stack size */
      InternalThreadStart, /* entry function */
      (LPVOID)threadArgs_, /* parameters */
      0, /* no creation arguments */
      0); /* no system thread ID */
  if (threadHandle_ == NULL) {
    return false;
  }
  return true;
}

bool ThreadImplementation::Join() {
  BOOL success;
  DWORD result;
  result = WaitForSingleObject(threadHandle_, INFINITE);
  delete threadArgs_;
  if (result != WAIT_OBJECT_0) { /* WAIT_OBJECT_0 indicates successful waiting */
    return false;
  }
  success = CloseHandle(threadHandle_);
  if (success == FALSE) {
    return false;
  }

  return true;
}

#endif /* PARTEST_THREADING_WINTHREADS */

#ifdef PARTEST_THREADING_POSIXTHREADS

/**
 * Is used to offer a consistent thread start function signature. POSIX threads
 * have a different signature than C11 threads. This internal start
 * function for POSIX threads just calls the client start function with given
 * argument.
 */
void* InternalThreadStart(void* internalArg) {
  ((PartestInternalThreadArgs*) internalArg)->result =
      ((PartestInternalThreadArgs*) internalArg)->func(
          ((PartestInternalThreadArgs*) internalArg)->arg);
  return NULL;
}

bool ThreadImplementation::Create_thread(int (*function)(void*), void * args) {
  /* Dynamic allocation of thread arguments. Freed on call of join. */
  threadArgs_ = new PartestInternalThreadArgs;
  threadArgs_->func = function;
  threadArgs_->arg = args;

  int status = pthread_create(&threadHandle_, /* pthread handle */
  NULL, /* not used */
  InternalThreadStart, /* thread start function */
  (void*) (threadArgs_)); /* arguments to thread start fct */

  if (status != 0)
    return false;
  return true;
}

bool ThreadImplementation::Join() {
  int status = 0;
  status = pthread_join(threadHandle_, NULL);

  delete threadArgs_;
  if (status != 0) {
    return false;
  }

  return true;
}

#endif /* PARTEST_THREADING_POSIXTHREADS */

} // namespace partestthreads
} // namespace internal
} // namespace partest

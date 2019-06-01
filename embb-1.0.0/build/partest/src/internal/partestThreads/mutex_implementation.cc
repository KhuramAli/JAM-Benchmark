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

#include<partest/internal/partestThreads/mutex_implementation.h>

namespace partest {
namespace internal {
namespace partestthreads {

#ifdef PARTEST_THREADING_WINTHREADS
MutexImplementation::MutexImplementation() {
  InitializeCriticalSection(&mutex_);
}

MutexImplementation::~MutexImplementation() {
  DeleteCriticalSection(&mutex_);
}

void MutexImplementation::Lock() {
  EnterCriticalSection(&mutex_);
}

bool MutexImplementation::TryLock() {
  BOOL success;
  success = TryEnterCriticalSection(&mutex_);
  if (success == FALSE) return false;
  return true;
}

void MutexImplementation::Unlock() {
  LeaveCriticalSection(&mutex_);
}

#endif /* PARTEST_THREADING_WINTHREADS */

#ifdef PARTEST_THREADING_POSIXTHREADS

MutexImplementation::MutexImplementation() {
  pthread_mutex_init(&mutex_, NULL);
}

MutexImplementation::~MutexImplementation() {
  pthread_mutex_destroy(&mutex_);
}

void MutexImplementation::Lock() {
  pthread_mutex_lock(&mutex_);
}

bool MutexImplementation::TryLock() {
  int result = pthread_mutex_trylock(&mutex_);
  if (result == 0) {
    return true;
  }
  if (result == EBUSY) {
    return false;
  }
  return false;
}

void MutexImplementation::Unlock() {
  pthread_mutex_unlock(&mutex_);
}

#endif /* PARTEST_THREADING_POSIXTHREADS */

} // namespace partestthreads
} // namespace internal
} // namespace partest

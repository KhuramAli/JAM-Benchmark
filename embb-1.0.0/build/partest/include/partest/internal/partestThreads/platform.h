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

#ifndef PARTEST_INTERNAL_PARTEST_THREADS_PLATFORM_H_
#define PARTEST_INTERNAL_PARTEST_THREADS_PLATFORM_H_

/**
 * @file Contains threading platform specific includes, typedefs, and defines.
 */
#include <partest/internal/partestThreads/config.h>

#include <limits.h>

#ifdef PARTEST_THREADING_WINTHREADS


#define NOMINMAX
#include <windows.h>

namespace partest {
namespace internal {
namespace partestthreads {

typedef struct PartestInternalThreadArgs {
  int(*func)(void*);
  void* arg;
  int result;
} PartestInternalThreadArgs;


typedef HANDLE PartestInternalThreadImpl;
typedef CRITICAL_SECTION PartestInternalMutexImpl;
typedef DWORD PartestInternalTSSImpl;
} // namespace partestthreads
} // namespace internal
} // namespace partest


#elif defined PARTEST_THREADING_POSIXTHREADS // PARTEST_THREADING_WINTHREADS

#include <pthread.h>
#include <errno.h>
#include <time.h>

namespace partest {
namespace internal {
namespace partestthreads {


typedef pthread_t PartestInternalThreadImpl;
typedef pthread_mutex_t PartestInternalMutexImpl;
typedef pthread_key_t PartestInternalTSSImpl;

/**
 * Used to wrap client thread start function and argument when calling internal
 * thread start function Partest_InternalThreadStart.
 */
typedef struct PartestInternalThreadArgs {
  int(*func)(void*);
  void* arg;
  int result;
} PartestInternalThreadArgs;

} // namespace partestthreads
} // namespace internal
} // namespace partest

#else // PARTEST_THREADING_POSIXTHREADS

#error "No threading platform defined!"

#endif // else


#endif /* PARTEST_INTERNAL_PARTEST_THREADS_PLATFORM_H_ */

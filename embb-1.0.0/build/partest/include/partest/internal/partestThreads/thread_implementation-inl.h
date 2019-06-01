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

#ifndef PARTEST_INTERNAL_PARTEST_THREADS_THREAD_IMPLEMENTATION_INL_H_
#define PARTEST_INTERNAL_PARTEST_THREADS_THREAD_IMPLEMENTATION_INL_H_

#include <partest/internal/partestThreads/thread_closures.h>
#include <partest/internal/exceptions.h>

namespace partest {
namespace internal {
namespace partestthreads {

template<typename Callable>
ThreadImplementation::ThreadImplementation(Callable function) :
    threadHandle_() {
  ThreadClosure<Callable>* closure = new ThreadClosure<Callable>(function);
  bool result = Create_thread(ThreadClosure<Callable>::ThreadStart,
      static_cast<void*>(closure));
  CheckThreadCreationErrors(result, closure);
}

template<typename Callable, typename Arg1>
ThreadImplementation::ThreadImplementation(Callable function, Arg1 arg1) :
    threadHandle_() {
  ThreadClosureArg1<Callable, Arg1>* closure = new ThreadClosureArg1<Callable,
      Arg1>(function, arg1);
  bool result = Create_thread(ThreadClosureArg1<Callable, Arg1>::ThreadStart,
      static_cast<void*>(closure));
  CheckThreadCreationErrors(result, closure);
}

template<typename Callable, typename Arg1, typename Arg2>
ThreadImplementation::ThreadImplementation(Callable function, Arg1 arg1,
    Arg2 arg2) :
    threadHandle_() {
  ThreadClosureArg2<Callable, Arg1, Arg2>* closure = new ThreadClosureArg2<
      Callable, Arg1, Arg2>(function, arg1, arg2);
  bool result = Create_thread(
      ThreadClosureArg2<Callable, Arg1, Arg2>::ThreadStart,
      static_cast<void*>(closure));
  CheckThreadCreationErrors(result, closure);
}

template<typename ThreadClosure>
void ThreadImplementation::CheckThreadCreationErrors(bool result,
    ThreadClosure* closure) {
  if (result != true) {
    if (closure != NULL) {
      delete closure;
    }
    const char* message = "Could not create thread.";
    throw ErrorException(message);
  }
}
} // namespace partestthreads
} // namespace internal
} // namespace partest

#endif /* PARTEST_INTERNAL_PARTEST_THREADS_THREAD_IMPLEMENTATION_INL_H_ */

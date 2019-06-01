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

#ifndef PARTEST_INTERNAL_PARTEST_THREADS_THREAD_IMPLEMENTATION_H_
#define PARTEST_INTERNAL_PARTEST_THREADS_THREAD_IMPLEMENTATION_H_

#include <partest/internal/partestThreads/platform.h>
#include <partest/internal/partestThreads/thread_closures.h>

namespace partest {
namespace internal {
namespace partestthreads {
/**
 * An object of this class represents a thread of execution.
 *
 */
class ThreadImplementation {

 public:
  /**
   * Creates and runs a thread with zero-argument thread start function.
   *
   * Pitfall: If function is constructed as temporary when creating a thread,
   * this might be interpreted as function definition. This is defined by the
   * standard and known as "most vexing parse". C++11 resolves this by using
   * curly braces for initialization.
   */
  template<typename Callable>
  ThreadImplementation(Callable function); /**<
   [IN] Callable (with no arguments) and copyable entity. */

  /**
   * Creates and runs a thread with one-argument thread start function.
   *
   * Pitfall: If function and arg are constructed as temporaries when creating
   * a thread, this might be interpreted as function definition. This is defined
   * by the standard and known as "most vexing parse". C++11 resolves this by using
   * curly braces for initialization.
   */
  template<typename Callable, typename Arg>
  ThreadImplementation(Callable function, /**<
   [IN] Callable (with one argument) and copyable entity. */
  Arg arg /**<
   [IN] Copyable argument for function. */
  );

  /**
   * Creates and runs a thread with two-argument thread start function.
   *
   * Pitfall: If function, arg1, and arg2 are constructed as temporaries when
   * creating a thread, this might be interpreted as function definition. This
   * is defined by the standard and known as "most vexing parse". C++11 resolves
   * this by using curly braces for initialization.
   */
  template<typename Callable, typename Arg1, typename Arg2>
  ThreadImplementation(Callable function, /**<
   [IN] Callable (with one argument) and copyable entity. */
  Arg1 arg1, /**<
   [IN] Copyable first argument for function. */
  Arg2 arg2 /**<
   [IN] Copyable second argument for function. */
  );

  /**
   * Join thread
   * Waits until the thread is completed (\c *this must not be empty).
   */
  bool Join();

 private:
  PartestInternalThreadImpl threadHandle_;
  PartestInternalThreadArgs *threadArgs_;

  bool Create_thread(int (*function)(void*), void * args);

  /**
   * Performs error checks and frees resources from thread constructor.
   */
  template<typename ThreadClosure>
  void CheckThreadCreationErrors(bool result, /**< [IN] Result value of creating thread with C API */
  ThreadClosure* closure /**< [IN] Closure used when creating thread */
  );

  ThreadImplementation();
  ThreadImplementation(const ThreadImplementation& thr);
  ThreadImplementation& operator=(const ThreadImplementation& thr);
};
}  // namespace partestthreads
}  // namespace internal
}  // namespace partest

#include<partest/internal/partestThreads/thread_implementation-inl.h>

#endif /* PARTEST_INTERNAL_PARTEST_THREADS_THREAD_IMPLEMENTATION_H_ */

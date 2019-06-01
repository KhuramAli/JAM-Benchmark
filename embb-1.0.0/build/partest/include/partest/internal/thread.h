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

#ifndef PARTEST_INTERNAL_THREAD_H_
#define PARTEST_INTERNAL_THREAD_H_

#include<partest/internal/partestThreads/thread_implementation.h>

namespace partest {
class TestInstanceInfo;
namespace internal {
/**
 * Wrapper class for threads.
 * An object of this class represents a thread of execution.
 */
class Thread {
 public:

  /**
   * Creates and runs a thread with one-argument thread start function.
   *
   * Pitfall: If function and arg are constructed as temporaries when creating
   * a thread, this might be interpreted as function definition. This is defined
   * by the standard and known as "most vexing parse". C++11 resolves this by using
   * curly braces for initialization.
   */
  Thread(int (*function)(partest::TestInstanceInfo*), /**<
   [IN] Callable (with one argument) and copyable entity. */
   partest::TestInstanceInfo* args /**<
   [IN] Copyable argument for function. */
  );


  /**
   * Creates and runs a thread with one-argument thread start function.
   *
   * Pitfall: If function and arg are constructed as temporaries when creating
   * a thread, this might be interpreted as function definition. This is defined
   * by the standard and known as "most vexing parse". C++11 resolves this by using
   * curly braces for initialization.
   */
  Thread(int (*function)(void*), /**<
   [IN] Callable (with one argument) and copyable entity. */
   void * args /**<
   [IN] Copyable argument for function. */
  );

  /**
   * Join thread
   * Waits until the thread is completed (\c *this must not be empty).
   */
  void Join();

 private:
  partestthreads::ThreadImplementation threadHandle_;

  /*
   * Disable empty constructor, copy constructor and assignment
   * */
  Thread();
  Thread(const Thread& thr);
  Thread& operator=(const Thread& thr);
};

}  // namespace internal
}  // namespace partest

#endif /* PARTEST_INTERNAL_THREAD_H_ */

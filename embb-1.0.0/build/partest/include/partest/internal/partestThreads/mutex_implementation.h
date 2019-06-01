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

#ifndef PARTEST_INTERNAL_PARTEST_THREADS_MUTEX_IMPLEMENTATION_H_
#define PARTEST_INTERNAL_PARTEST_THREADS_MUTEX_IMPLEMENTATION_H_

#include <partest/internal/partestThreads/platform.h>

namespace partest {
namespace internal {
namespace partestthreads {
/**
 * Implementation for non-recursive, exclusive mutex.
 */
class MutexImplementation {
 public:
  /**
   * Creates a mutex which is in unlocked state.
   */
  MutexImplementation();

  /**
   * Frees used resources.
   */
  ~MutexImplementation();

  /**
   * Waits until mutex is unlocked and locks it.
   *
   * Precondition: Mutex has not been locked by this thread. Otherwise undefined
   *   behavior.
   */
  void Lock();

  /**
   * Locks the mutex if unlocked and returns true in that case. Does not wait.
   *
   * Precondition: Mutex has not been locked by this thread. Otherwise undefined
   *   behavior.
   */
  bool TryLock();

  /**
   * Unlocks a locked mutex by the thread that locked it.
   *
   * Precondition: This thread has previously locked the mutex. Otherwise,
   * undefined behavior.
   */
  void Unlock();

 private:
  /**
   * Holds the actual mutex.
   */
  PartestInternalMutexImpl mutex_;

  /**
   * Disables copy construction and assignment.
   */
  MutexImplementation(const MutexImplementation&);
  MutexImplementation& operator=(const MutexImplementation&);
};
}  // namespace partestthreads
}  // namespace internal
}  // namespace partest
#endif /* PARTEST_INTERNAL_PARTEST_THREADS_MUTEX_IMPLEMENTATION_H_ */

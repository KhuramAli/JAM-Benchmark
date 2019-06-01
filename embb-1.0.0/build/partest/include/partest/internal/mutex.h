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

#ifndef PARTEST_INTERNAL_MUTEX_H_
#define PARTEST_INTERNAL_MUTEX_H_

#include <partest/internal/partestThreads/mutex_implementation.h>

namespace partest {
namespace internal {

/**
 * Abstraction for non-recursive, exclusive mutex.
 */
class Mutex {
 public:
  /**
   * Creates a mutex which is in unlocked state.
   */
  Mutex();

  /**
   * Frees used resources.
   */
  ~Mutex();

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
  partestthreads::MutexImplementation mutex_;

  /**
   * Disables copy construction and assignment.
   */
  Mutex(const Mutex&);
  Mutex& operator=(const Mutex&);
};

/**
 * Realizes a scoped lock (according to the RAII principle) using a mutex.
 *
 * The mutex is locked on construction and unlocked on leaving the scope of
 * definition of the lock guard, in its constructor.
 */
template<typename Mutex>
class LockGuard {
public:
  /**
   * Creates the lock and locks the mutex.
   */
  LockGuard(Mutex& mutex) :
      mutex_(mutex) {
    mutex_.Lock();
  }

  /**
   * Unlocks the mutex.
   */
  ~LockGuard() {
    mutex_.Unlock();
  }

private:
  /**
   * Holds reference to mutex realizing the lock.
   */
  Mutex& mutex_;

  /**
   * Disable copy construction and assignment.
   */
  LockGuard(const LockGuard<Mutex>&);
  LockGuard<Mutex>& operator=(const LockGuard<Mutex>&);
};

/**
 * Flexible ownership wrapper for a mutex.
 *
 * Unlocks an owned mutex on destruction.
 */
template<typename Mutex>
class UniqueLock {
public:
  /**
   * Creates the lock without a mutex.
   */
  UniqueLock() :
      mutex_(NULL) {
  }

  /**
   * Creates the lock with a mutex.
   */
  UniqueLock(Mutex& mutex) :
      mutex_(&mutex) {
  }

  /**
   * Unlocks the mutex, if owned.
   */
  ~UniqueLock();

  /**
   * Waits until mutex is unlocked and locks it.
   *
   * Throws an exception if there is no associated mutex or the associated mutex
   * has already been locked by the unique lock.
   */
  void Lock();

  /**
   * Locks the mutex if unlocked and returns true in that case.
   *        Does not wait.
   *
   * Throws an exception if there is no associated mutex.
   *
   * @return True, if the mutex could be locked. False, otherwise.
   */
  bool TryLock();

  /**
   * Unlocks a locked mutex by the thread that locked it.
   *
   * Throws an exception if the mutex was not locked by the unique lock.
   */
  void Unlock();

  /**
   * Gives up ownership to the mutex and returns the mutex.
   *
   * @return A pointer to the owned mutex or NULL, if no mutex was owned.
   */
  Mutex* Release();

  /**
   * Returns the mutex or NULL, if none is owned.
   *
   * @return Pointer to owned mutex or NULL, if none is owned.
   */
  Mutex* mutex() {
    return mutex_;
  }

  /**
   * Returns true, if a mutex is associated and owned.
   */
  bool ownsLock() {
    return (mutex_ != NULL) && locked_;
  }

private:
  /**
   * Holds reference to mutex realizing the lock.
   */
  Mutex* mutex_;

  /**
   * Stores information about whether the unique lock as locked the mutex.
   */
  bool locked_;

  /**
   * Disable copy construction and assignment.
   */
  UniqueLock(const UniqueLock<Mutex>&);
  UniqueLock<Mutex>& operator=(const UniqueLock<Mutex>&);
};

} // namespace internal
} // namespace partest

#include <partest/internal/mutex-inl.h>

#endif // PARTEST_INTERNAL_MUTEX_H_

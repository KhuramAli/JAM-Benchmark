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

#ifndef PARTEST_INTERNAL_THREAD_SPECIFIC_STORAGE_H_
#define PARTEST_INTERNAL_THREAD_SPECIFIC_STORAGE_H_

#include <partest/internal/partestThreads/thread_specific_storage_implementation.h>

namespace partest {
namespace internal {

/**
 * Provides a thread specific (or local) storage (TSS) abstraction.
 *
 * The TSS acts as a pointer and provides a similar interface. In order to add
 * a value to the TSS, the method Reset has to be used with a user allocated
 * memory for the value. The TSS takes care of deleting the memory then, or the
 * user (thread) can take over again by calling Release.
 */
template<typename Type>
class ThreadSpecificStorage {
 public:
  /**
   * Creates a TSS storage with NULL pointer as initial value.
   */
  ThreadSpecificStorage();

  /**
   * Destructs a TSS value, if not NULL.
   */
  ~ThreadSpecificStorage();

  /**
   * Returns a pointer to the value, by default NULL.
   */
  Type* get() const;

  /**
   * Returns pointer to value, enabling access to member of Type via ->.
   */
  Type* operator->() const;

  /**
   * Returns dereferenced pointer to value.
   *
   * Pre-condition: value needs to be unequal NULL.
   */
  Type& operator*();

  /**
   * Returns a pointer to the value and sets the value to be NULL.
   *
   * Does not delete the memory of the value.
   */
  Type* Release();

  /**
   * Replaces value by new one and deletes the previous value (if not NULL).
   */
  void Reset(Type* newValue = NULL);

 private:
  /**
   * Handle for the threading API.
   */
  partestthreads::ThreadSpecificStorageImplementation handle_;

  /**
    * Disallow copy constructor and assignment.
    */
  ThreadSpecificStorage(const ThreadSpecificStorage&);
  ThreadSpecificStorage& operator=(const ThreadSpecificStorage&);
};

} // namespace internal
} // namespace partest

#include <partest/internal/thread_specific_storage-inl.h>

#endif /* PARTEST_INTERNAL_THREAD_SPECIFIC_STORAGE_H_ */

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

#ifndef PARTEST_INTERNAL_PARTEST_THREADS__TSS_IMPLEMENTATION_H_
#define PARTEST_INTERNAL_PARTEST_THREADS__TSS_IMPLEMENTATION_H_

#include <partest/internal/partestThreads/platform.h>

namespace partest {
namespace internal {
namespace partestthreads {
/**
 * An object of this class represents a TSS Object
 */
class ThreadSpecificStorageImplementation {
 public:
  /**
   * Creates a TSS storage with NULL pointer as initial value.
   */
  ThreadSpecificStorageImplementation();

  /**
   * Destructs a TSS value, if not NULL.
   */
  ~ThreadSpecificStorageImplementation();

  /**
   * Returns a pointer to the value, by default NULL.
   */
  void set(void* newValue) const;

  /**
   * Returns a pointer to the value, by default NULL.
   */
  void* get() const;

 private:
  /**
   * Handle for the threading API.
   */
  PartestInternalTSSImpl handle_;

  /**
   * Disables copy construction and assignment.
   */
  ThreadSpecificStorageImplementation(const ThreadSpecificStorageImplementation&);
  ThreadSpecificStorageImplementation& operator=(
      const ThreadSpecificStorageImplementation&);
};
}  // namespace partestthreads
}  // namespace internal
}  // namespace partest
#endif /* PARTEST_INTERNAL_PARTEST_THREADS__TSS_IMPLEMENTATION_H_ */

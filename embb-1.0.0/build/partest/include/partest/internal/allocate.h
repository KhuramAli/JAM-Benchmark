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

#ifndef PARTEST_INTERNAL_ALLOCATE_H_
#define PARTEST_INTERNAL_ALLOCATE_H_

#include <cstdlib>

// Size of cache lines (usually at most 64 Bytes)
#define CACHE_LINE_SIZE 64

namespace partest {
namespace internal {
/** Create cache-aligned object.
 * This function is used to avoid false sharing, since it guarantees
 * that two different objects never share the same cache line.
 * \tparam T Type of object
 * \param init Initial value
 * \return Pointer to newly created object
 * \see aligned_delete
 */
template<typename T>
inline T* aligned_new(const T& init) {
#if _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
  void *ptr;
  if(posix_memalign(&ptr, CACHE_LINE_SIZE, sizeof(T)) != 0)
    throw;
  return new(ptr) T(init);
#else
  return new T(init);
#endif
}

/** Delete cache-aligned object.
 * Destroys a cache-aligned object and frees the memory.
 * \tparam T Type of object
 * \param ptr Pointer to object
 * \see aligned_new
 */
template<typename T>
inline void aligned_delete(T* ptr) {
#if _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
  ptr->~T();
  free(static_cast<void*>(ptr));
#else
  delete ptr;
#endif
}

}  // namespace internal
}  // namespace partest
#endif  // PARTEST_INTERNAL_ALLOCATE_H_

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

#ifndef PARTEST_INTERNAL_THREAD_SPECIFIC_STORAGE_INL_H_
#define PARTEST_INTERNAL_THREAD_SPECIFIC_STORAGE_INL_H_

namespace partest {
namespace internal {

template<typename Type>
ThreadSpecificStorage<Type>::ThreadSpecificStorage() :
    handle_() {
}

template<typename Type>
ThreadSpecificStorage<Type>::~ThreadSpecificStorage() {
  void* value = handle_.get();
  if (value != NULL) {
    delete static_cast<Type*>(value);
  }
}

template<typename Type>
Type* ThreadSpecificStorage<Type>::get() const {
  return static_cast<Type*>(handle_.get());
}

template<typename Type>
Type* ThreadSpecificStorage<Type>::operator->() const {
  return static_cast<Type*>(handle_.get());
}

template<typename Type>
Type& ThreadSpecificStorage<Type>::operator*() {
  return *static_cast<Type*>(handle_.get());
}

template<typename Type>
Type* ThreadSpecificStorage<Type>::Release() {
  Type* value = static_cast<Type*>(handle_.get());
  handle_.set(NULL);
  return value;
}

template<typename Type>
void ThreadSpecificStorage<Type>::Reset(Type* newValue) {
  Type* value = static_cast<Type*>(handle_.get());
  if (value != NULL)
    delete value;
  handle_.set(static_cast<void*>(newValue));
}

} // namespace internal
} // namespace partest

#endif /* PARTEST_INTERNAL_THREAD_SPECIFIC_STORAGE_INL_H_ */

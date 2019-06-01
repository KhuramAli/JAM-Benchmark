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

#ifndef PARTEST_INTERNAL_TEST_UNIT_INL_H_
#define PARTEST_INTERNAL_TEST_UNIT_INL_H_

namespace partest {

template<typename F>
TestUnit& TestUnit::Add(void (F::*member_function)(), F* object,
    size_t instances, size_t iterations) {
  Add(new TestMethod(member_function, object, instances, iterations));
  return *this;
}

template<typename F>
TestUnit& TestUnit::Add(F function_object, size_t instances,
    size_t iterations) {
  Add(new TestMethod(function_object, instances, iterations));
  return *this;
}

template<typename F>
TestUnit& TestUnit::Pre(void (F::*member_function)(), F* object) {
  AddPre(new TestMethod(member_function, object, 1, 1));
  return *this;
}

template<typename F>
TestUnit& TestUnit::Pre(F function_object) {
  AddPre(new TestMethod(function_object, 1, 1));
  return *this;
}

template<typename F>
TestUnit& TestUnit::Post(void (F::*member_function)(), F* object) {
  AddPost(new TestMethod(member_function, object, 1, 1));
  return *this;
}

template<typename F>
TestUnit& TestUnit::Post(F function_object) {
  AddPost(new TestMethod(function_object, 1, 1));
  return *this;
}

} // namespace partest

#endif /* PARTEST_INTERNAL_TEST_UNIT_INL_H_ */

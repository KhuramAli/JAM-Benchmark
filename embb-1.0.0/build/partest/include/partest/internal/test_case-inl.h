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

#ifndef PARTEST_INTERNAL_TEST_CASE_INL_H_
#define PARTEST_INTERNAL_TEST_CASE_INL_H_

namespace partest {

template<typename Unit>
Unit& TestCase::CreateUnit() {
  Unit *testUnit = new Unit();
  test_units_.push_back(testUnit);
  return *testUnit;
}

template<typename Unit, typename Arg1>
Unit& TestCase::CreateUnit(Arg1 arg1) {
  Unit *testUnit = new Unit(arg1);
  test_units_.push_back(testUnit);
  return *testUnit;
}

template<typename Unit, typename Arg1, typename Arg2>
Unit& TestCase::CreateUnit(Arg1 arg1, Arg2 arg2) {
  Unit *testUnit = new Unit(arg1, arg2);
  test_units_.push_back(testUnit);
  return *testUnit;
}

}  // namespace partest

#endif  // PARTEST_INTERNAL_TEST_CASE_INL_H_

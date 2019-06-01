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

#ifndef PARTEST_TEST_CASE_H_
#define PARTEST_TEST_CASE_H_

#include <vector>
#include <string>

namespace partest {

class TestUnit;

/** Creates, manages, and sequentially runs (related) test units.
 *
 * A test case can be either created as empty test case, or can be used to
 * derive a user test case by inheriting from it.
 *
 * Default (empty) test units or user defined test units can be created by a
 * test case and are managed and run by it in a sequential manner. The test
 * units of a test case can be run several times and are destructed on
 * destruction of the test case only.
 */
class TestCase {
 public:
  /** Constructs an empty test case.
   */
  TestCase();

  /** Deletes created test units.
   */
  virtual ~TestCase();

  /** Runs all created test units in a sequentialized order.
   */
  void Run();

  /** Creates a default (empty) test unit.
   *  @return Reference to created test unit.
   */
  TestUnit& CreateUnit(const std::string& name /**<
   [IN] Name or short description of test unit */
  );

  /** Creates a subclass of TestUnit using its default constructor.
   * Can be used to create user defined test units.
   */
  template<typename Unit>
  Unit& CreateUnit();

  /** Creates a subclass of TestUnit using its one argument constructor.
   *  Can be used to create user defined test units.
   */
  template<typename Unit, typename Arg1>
  Unit& CreateUnit(Arg1 arg1 /**<
   [IN] Copyable argument for the constructor of Unit */
  );

  /** Creates a subclass of TestUnit using its two arguments constructor.
   * Can be used to create user defined test units.
   */
  template<typename Unit, typename Arg1, typename Arg2>
  Unit& CreateUnit(Arg1 arg1, /**<
   [IN] Copyable first argument for the constructor of Unit */
  Arg2 arg2 /**<
   [IN] Copyable second argument for the constructor of Unit */
  );

 private:
  /** Contains all created test units.
   */
  std::vector<partest::TestUnit*> test_units_;
};

}  // namespace partest

#include <partest/internal/test_case-inl.h>

#endif  // PARTEST_TEST_CASE_H_

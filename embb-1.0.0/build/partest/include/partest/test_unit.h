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

#ifndef PARTEST_TEST_UNIT_H_
#define PARTEST_TEST_UNIT_H_

#include <partest/test_unit.h>
#include <partest/test_instance_info.h>
#include <vector>

namespace partest {

/** Gathers and executes (in parallel) all methods of one test.
 * A test unit defines one test, usually belonging to a test case. It can
 * consist of several methods that are executed in parallel by different threads.
 * In addition, a pre- and post-method can be set, which are executed before and
 * after the parallel test methods are executed.
 */
class TestUnit {
 public:
  /** Constructs an empty test unit.
   * Test methods, as well as pre- and post-methods have to be added.
   */
  TestUnit(const std::string& name);

  /** Destroys the test unit.
   */
  virtual ~TestUnit();

  /** Executes the added test methods in parallel by using threads.
   */
  void Run();

  /** Adds a test method for execution.
   */
  TestUnit& Add(void (*function)(), /**<
   [IN] Function pointer to method */
  size_t instances = 1, /**<
   [IN] Number of threads executing the method at the same time */
  size_t iterations = 1 /**<
   [IN] Number of times each thread calls the method */
  );

  /** Adds a member test method with calling object for execution.
   */
  template<typename F>
  TestUnit& Add(void (F::*member_function)(), /**<
   [IN] Member function pointer to method */
  F* object, /**<
   [IN] Object calling the member function */
  size_t instances = 1, /**<
   [IN] Number of threads executing the method at the same time */
  size_t iterations = 1 /**<
   [IN] Number of times each thread calls the method */
  );

  /** Adds a test functor for execution.
   */
  template<typename F>
  TestUnit& Add(F function_object, /**<
   [IN] Copyable functor defining the test method in operator() */
  size_t instances = 1, /**<
   [IN] Number of threads executing the method at the same time */
  size_t iterations = 1 /**<
   [IN] Number of times each thread calls the method */
  );

  /** Sets a method to be executed before the test methods.
   */
  TestUnit& Pre(void (*function)()); /**< [IN] Function pointer to method */

  /** Sets a member method to be executed before the test methods.
   */
  template<typename F>
  TestUnit& Pre(void (F::*member_function)(), /**<
   [IN] Member function pointer to method */
  F* object /**<
   [IN] Object calling the member function */
  );

  /** Sets a functor to be executed before the test methods.
   */
  template<typename F>
  TestUnit& Pre(F function_object); /**<
   [IN] Copyable functor defining operator() */

  /** Sets a method to be executed after the test methods.
   */
  TestUnit& Post(void (*function)());

  /** Sets a member method to be executed after the test methods.
   */
  template<typename F>
  TestUnit& Post(void (F::*member_function)(), /**<
   [IN] Member function pointer to method */
  F* object /**<
   [IN] Object calling the member function */
  );

  /** Sets a functor to be executed after the test methods.
   */
  template<typename F>
  TestUnit& Post(F function_object); /**<
   [IN] Copyable functor defining operator() */

 private:
  /** Disallow copy constructor and assignment.
   */
  TestUnit(const TestUnit&);
  TestUnit& operator=(const TestUnit&);

  /** Adds the provided test method to the set of test methods to be tested.
   * @param method Method to be added.
   */
  void Add(TestMethod* method);
  void AddPre(TestMethod* method);
  void AddPost(TestMethod* method);

  /** Name of the test unit
   */
  std::string name_;

  /** Method to be run before any other method is run
   Only when pre_method_ method terminates the rest of the methods will be executed
   */
  partest::TestMethod* pre_method_;

  /** Method to be run after all other methods are run
   Only when all other methods terminate the post method will be executed
   */
  partest::TestMethod* post_method_;

  /** All the test methods to be executed in parallel between the pre and post methods
   */
  std::vector<partest::TestMethod*> test_methods_;

};

}  // namespace partest

#include <partest/internal/test_unit-inl.h>

#endif  // PARTEST_TEST_UNIT_H_

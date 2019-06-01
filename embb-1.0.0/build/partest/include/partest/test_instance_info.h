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

#ifndef PARTEST_TEST_INSTANCE_INFO_H_
#define PARTEST_TEST_INSTANCE_INFO_H_

#include <cstddef>

#include <partest/test_method.h>

namespace partest {

/** Test instance Information.
 * A test instance represents an instance of a running test method. It contains all the information identifying the
 * instance (Testmethod,thread_num, instance_num, iteration_num, Affinity ).
 * Multiple instances of a test method may be executed in parallel.
 */

class TestInstanceInfo {
 public:
  /** Constructor.
   * Creates an instance of the specified test method.
   */
  TestInstanceInfo(const std::string& unit_name_,/**<
   [IN] Name of the test unit */
  TestMethod *ptr /**<
   [IN] Pointer to test instance */
  );

  /** Copy constructor.
   *  Creates a copy of the specified test instance.
   */
  TestInstanceInfo(const TestInstanceInfo& arguments /**<
   [IN] Test instance to be copied */
  );

  /** Destructor.
   * Destroys the test instance.
   */
  ~TestInstanceInfo();

  /** Returns name of test unit executing the test.
   */
  const std::string& GetUnitName() const {
    return unit_name_;
  }

  /** Get test method.
   * Returns a pointer to the corresponding test method.
   * @return Pointer to test method
   */
  TestMethod* GetTestMethod() const;

  /** Get thread number.
   * Returns the number of the thread executing the test instance.
   * Given \c n threads, the threads are numbered from \c 0 to \c n-1.
   * Hence, thread numbers can be used to access arrays of user defined data.
   * @return Number of thread
   */
  size_t GetThreadNum() const;

  /** Get instance number.
   * Returns the number of the test instance. Given \c n instances,
   * the instances are numbered from \c 0 to \c n-1. Hence, instance
   * numbers can be used to access arrays of user defined data.
   * Unlike thread numbers, however, instance numbers are not unique,
   * i.e., instances of different test methods might have the same numbers.
   * @return Number of instance
   */
  size_t GetInstanceNum() const;

  /** Get iteration number.
   * Returns the number of the iteration (starting with \c 0).
   * @return Number of iteration
   */
  size_t GetIterationNum() const;

  /** Set thread number.
   * Sets the the thread number this instance represents.
   */
  void SetThreadNum(size_t thread_num /**<
   [IN] Number of thread of iteration to be set. */
  );

  /**Set instance number.
   * Sets the the instance number this instance represents.
   */
  void SetInstanceNum(size_t instance_num /**<
   [IN] Number of the instance to be set.*/
  );

  /** Set iteration number.
   * Sets the the current iteration number.
   */
  void SetIterationNum(size_t iteration_num/**<
   [IN] Number of current iteration to be set */
  );

  /** Get test instance
   * Returns a pointer to the test instance executed by the calling thread.
   * Fails if there is no active test instance.
   * @return Pointer to test instance
   */
  static TestInstanceInfo* GetTestInstanceInfo();

 private:

  /** Disallow empty constructor
   */
  TestInstanceInfo();

  /** Disable assignment.
   */
  TestInstanceInfo& operator=(const TestInstanceInfo&);

  /** Name of the test unit assosiated with test instance*
   */
  std::string unit_name_;

  /** Pointer to test method this test instance is running.
   */
  TestMethod *test_method_ptr_;

  /** Thread number that represents this instance.
   */
  size_t thread_num_;

  /** Instance number of this instance, this is relative to the instances running the same test method.
   */
  size_t instance_num_;

  /** Current iteration number for running assigned test method.
   */
  size_t iteration_num_;
};

}  // namespace partest

#endif  // PARTEST_TEST_INSTANCE_INFO_H_

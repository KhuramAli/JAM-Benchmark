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

#ifndef PARTEST_TEST_SUITE_H_
#define PARTEST_TEST_SUITE_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

#include <partest/test_instance_info.h>

#include <partest/internal/mutex.h>

namespace partest {
/**
 * Test suite.
 * This class provides global functions and settings for all test cases.
 */
class TestSuite {
public:
  /**
   * Get output stream.
   * Returns the output stream for warnings and error messages (by default \c cerr).
   * @return Reference to the stream
   * @see set_stream
   */
  static std::ostream& GetStream();

  /**
   * Set output stream.
   * Sets the output stream for warnings and error messages.
   * @see get_stream
   */
  static void SetStream(std::ostream& output_stream); /**<
   [IN] Output stream for assertion messages */

  /**
   * Get passed expects.
   * Returns the number of expects that were passed successfully.
   * @return Number of passed expects
   * @see get_failed_expects
   */
  static size_t GetPassedExpects();

  /**
   * Get failed expects.
   * Returns the number of expects that were not passed successfully.
   * Unlike assertions, a failed expect does not cause the whole test to be aborted.
   * @return Number of failed expects
   * @see get_passed_expects
   */
  static size_t GetFailedExpects();

  /** Get passed asserts.
   * Returns the number of asserts that were passed successfully.
   * @return Number of passed asserts
   */
  static size_t GetPassedAsserts();

  /**
   * Get maximum failed expects.
   * Returns the maximum number of expects that may fail before the test is aborted.
   * @return Number of passed asserts
   * @see set_max_failed_expects
   */
  static size_t GetMaxFailedExpects();

  /**
   * Set maximum failed expects.
   * Sets the maximum number of expects that may fail before the test is aborted.
   * @see get_max_failed_expects
   */
  static void SetMaxFailedExpects(size_t max_failed_exp); /**<
   [IN] Maximum number of failed expects */

  /**
   * Report an exception.
   * This function is called when an exception is thrown but not caught by
   * the application.
   * @note This function is automatically called by the test framework.
   */
  static void ReportException(const char* what); /**<
   [IN] Error message */

  /**
   * Check result of Boolean assert/expect expression.
   * If \c result is \c false, emits an error/warning message and
   * terminates the program in case \c terminate is \c true.
   * @note Do not call this function directly. Use the PT macros instead.
   */
  static void Check(bool result,/**<
   [IN]  Result of assert/expect expression */
  const char* expr,/**<
   [IN] Pointer to string representing the expression */
  const char* file,/**<
   [IN] Name of file which contains the assert/expect expression */
  const char* func,/**<
   [IN] Name of function which contains the assert/expect expression */
  size_t line,/**<
   [IN] Number of line which contains the assert/expect expression */
  const char* message,/**<
   [IN] Optional user-defined message */
  bool terminate/**<
   [IN]  Boolean value indicating whether program should be terminated */
  );

  /* \briefCheck result of relational assert/expect expression.
   * If \c pred(value1,value2) is \c false, emits an error/warning message and
   * terminates the program in case \c terminate is \c true.
   * @note Do not call this function directly. Use the PT macros instead.
   */
  template<typename T1, typename P, typename T2>
  static void Check(T1 value1,/**<
   [IN] Left-hand side of expression */
  P pred,/**<
   [IN] Binary predicate */
  T2 value2,/**<
   [IN]  Right-hand side of expression */
  const char* expr1,/**<
   [IN] Pointer to string representing left-hand side of expression */
  const char* expr2,/**<
   [IN] Pointer to string representing right-hand side of expression */
  const char* file,/**<
   [IN]  Name of file which contains the assert/expect expression */
  const char* func,/**<
   [IN] Name of function which contains the assert/expect expression */
  size_t line,/**<
   [IN] Number of line which contains the assert/expect expression */
  const char* message,/**<
   [IN] Optional user-defined message */
  bool terminate/**<
   [IN] Boolean value indicating whether program should be terminated */
  );

  /**
   * Returns the default number of iterations.
   * The default number of iterations is set to 10.
   * */
  static size_t GetDefaultNumIterations() {
    return DefaultNumberIterations();
  }

  /**
   * Returns the default number of threads.
   * The default number of threads is set to 10.
   * */
  static size_t GetDefaultNumThreads() {
    return DefaultNumberThreads();
  }

  /**
   * Sets the default number of iterations.
   * The default number of iterations is set to 10.
   * */
  static void SetDefaultNumIterations(size_t num_iterations) {
    DefaultNumberIterations() = num_iterations;
  }

  /**
   * Sets the default number of threads.
   * The default number of threads is set to 10.
   * */
  static void SetDefaultNumThreads(size_t num_threads) {
    DefaultNumberThreads() = num_threads;
  }


  /**
   * Gets the current thread id.
   * The thread id is assigned by the test framework.
   */
  static size_t GetCurrentThreadID() {
    return TestInstanceInfo::GetTestInstanceInfo()->GetThreadNum();
  }

  /**
   * Gets the current instance ID.
   * Instance IDs are unique only within the same method.
   */
  static size_t GetCurrentTestInstanceID() {
    return TestInstanceInfo::GetTestInstanceInfo()->GetInstanceNum();
  }

private:
  /**
   * Disallow constructing Test Suite objects.
   */
  TestSuite();
  TestSuite(const TestSuite&);
  TestSuite& operator=(const TestSuite&);

  /**
   * No destructor defined.
   */
  ~TestSuite();

  /**
   * prints assertion message and updates assert and expect counters uppon error.
   */
  static void Emit(std::string string, const char* message, bool terminate);

  /**
   * Output stream for messages printed by test suite.
   */
  static std::ostream *ostr_;

  /**
   * Number of passed assrts, passed and failed expects.
   * Number of max failed expects, more than max failed expects are encountered the test terminates.
   */
  static size_t passed_expects_, failed_expects_, passed_asserts_,
      max_failed_expects_;

  /**
   * Helper variable set to true in case that the test terminates.
   */
  static bool stopped_;

  /**
   * Mutex to synchronize output stream and counters.
   */
  static internal::Mutex mtx_;

  /**
   * Returns a reference to the default number of iterations
   * */
  static size_t& DefaultNumberIterations() {
    static size_t default_num_iterations=10;
    return default_num_iterations;
  }

  /**
   * Returns a reference to the default number of threads
   * */
  static size_t& DefaultNumberThreads() {
    static size_t default_num_threads=10;
    return default_num_threads;
  }

};

template<typename T1, typename P, typename T2>
void TestSuite::Check(T1 value1, P pred, T2 value2, const char* expr1,
    const char* expr2, const char* file, const char* func, size_t line,
    const char* message, bool terminate) {
  if (pred(value1, value2)) {
    internal::LockGuard<internal::Mutex> lock(mtx_);
    if (terminate)
      passed_asserts_++;
    else
      passed_expects_++;
    return;
  }
  std::stringstream ss;
  ss << "CHECK FAILED" << std::endl;
  ss << "Expression: " << expr1 << " " << pred.get_op() << " " << expr2
      << std::endl;
  ss << "Values    : " << value1 << " " << typename P::inverse_t().get_op()
      << " " << value2 << std::endl;
  ss << "File      : " << file << std::endl;
  ss << "Method    : " << func << std::endl;
  ss << "Line      : " << line << std::endl;
  Emit(ss.str(), message, terminate);
}

}  // namespace partest

#endif  // PARTEST_TEST_SUITE_H_

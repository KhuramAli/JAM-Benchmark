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

#ifndef PARTEST_TEST_METHOD_H_
#define PARTEST_TEST_METHOD_H_

#include <cstddef>

#include <partest/internal/thread_specific_storage.h>
#include <partest/internal/function.h>

namespace partest {

class TestInstanceInfo;

/** Test Method.
 * An object of class TestMethod specifies the method to be tested, e.g.
 * a function, and related parameters such as the number of instances.
 */
class TestMethod {
 public:
  /** Constructor (for functions).
   * Creates a test method for the specified function.
   */
  TestMethod(
      void (*function)(), /**<
      [IN] Pointer to function. */
      size_t instances = 1,/**<
      [IN] Number of instances to be created. */
      size_t iterations = 1/**<
      [IN] Number of iterations to be performed.*/
      );

   /** Constructor (for member functions).
    * Creates a test method for the specified member function.
    */
  template <typename F>
  TestMethod(
      void (F::*member_function)(),/**<
      [IN] Pointer to member function */
      F* object, /**<
      [IN] Pointer to object */
      size_t instances = 1, /**<
      [IN] Number of instances to be created */
      size_t iterations = 1/**<
      [IN] Number of iterations to be performed */
      );


  /** Constructor (for function objects).
   *  Creates a test method for the specified function object.
   *  @note Function objects are copied. If a function object
   *  stores data and you want to access this data later on, wrap
   *  it into a reference using \c ref. Large objects may be
   *  passed as a constant reference using \c cref.
   */
  template <typename F>
  TestMethod(
      F function_object,/**<
      [IN] Function object */
      size_t instances = 1,/**<
      [IN] Number of instances to be created */
      size_t iterations = 1/**<
      [IN] Number of iterations to be performed */
      );


  /** Destructor.
   * Destroys the test method.
   */
  ~TestMethod();

  /** Get number of instances.
   * Returns the number of instances to be created.
   * @return Number of instances
   */
  size_t GetNumInstances() const;

  /** Get number of iterations.
   * Returns the number of iterations to be performed.
   * @return Number of iterations
   */
  size_t GetNumIterations() const;

  /** Get maximum number of instances.
   * Returns the maximum number of instances to be created.
   * @return Maximum number of instances
   * @see set_max_instances
   */
  static size_t GetMaxInstances();

  /** Set max. number of instances.
   * Sets the maximum number of instances to be created (0 = unlimited).
   * This function is useful if you want to perform both stress tests
   * and dynamic analysis of threading errors. For the latter, it
   * usually suffices to create only a small number of instances, since
   * the results of the tools are largely independent of the load.
   * Moreover, reducing the number of instances significantly speeds
   * up the analysis process. To sum up, set the value to 0 (no limit)
   * in case of stress tests, otherwise to a small value.
   * \see get_max_instances
   */
  static void SetMaxInstances(size_t max_instances); /**<
  [IN] Maximum number of instances */


  /** Get max. number of iterations.
   * Returns the maximum number of iterations to be performed.
   * @return Maximum number of iterations
   * @see set_max_iterations
   */
  static size_t GetMaxIterations();

  /** Set maximum number of iterations.
   * Sets the maximum number of iterations to be performed (0 = unlimited).
   * This function is useful if you want to perform both stress tests
   * and dynamic analysis of threading errors. For the latter, it
   * usually suffices to perform only a small number of iterations, since
   * the results of the tools are largely independent of the load.
   * Moreover, reducing the number of iterations significantly speeds
   * up the analysis process. To sum up, set the value to 0 (no limit)
   * in case of stress tests, otherwise to a small value.
   * \see get_max_iterations
  */
  static void SetMaxIterations(size_t max_iterations); /**<
  [IN] Maximum number of iterations */

   /** Get test instance.
    * Returns a pointer to the test instance executed by the calling thread.
    * @return Pointer to test instance
    */
  static TestInstanceInfo* GetTestInstanceInfo();

  /** Runs the test method.
   * Runs the test method for the specified number of iterations and instances.
   * Creates instances_ threads each running the method iterations_ times.
   */
  static int Run(TestInstanceInfo* ptr); /**<
  [IN] Pointer to the test instance to be run */

 private:
  /** Disallow empty constructor.
   */
  TestMethod();

  /** Disallow copy constructor and assingment.
   */
  TestMethod(const TestMethod& method);
  TestMethod& operator=(const TestMethod& method);

  /** Init method used in the constructor.
   */
  void Init(size_t instances, size_t iterations);

  /** Pointer to function this test method represents.
   */
  partest::internal::FunctionBase *fn_base_;

  /** number of instances and iterations for this test method.
   *  It will run instances_ threads, each running the test method iterations_times
   */
  size_t instances_, iterations_;

  /** maximum number of instances and iterations for all test methods.
   *  If it is set to 0 it represents INFINITE
   */
  static size_t max_inst, max_iter;

  /** Get the information for a running instance of this test method, depends on the running thread.
   */
  static internal::ThreadSpecificStorage<TestInstanceInfo> tls;

};

}  // namespace partest

#include <partest/internal/test_method-inl.h>

#endif  // PARTEST_TEST_METHOD_H_

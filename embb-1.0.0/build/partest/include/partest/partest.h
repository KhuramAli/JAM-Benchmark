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

#ifndef PARTEST_PARTEST_H_
#define PARTEST_PARTEST_H_

#include <partest/test_unit.h>
#include <partest/test_case.h>
#include <partest/test_suite.h>
#include <partest/test_instance_info.h>

// For some versions of Sun CC, __func__ is only defined if the option -features=extensions is specified.
#if defined(__GNUC__) || defined(__INTEL_COMPILER)
#define PT_FUNCTION __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
#define PT_FUNCTION __FUNCSIG__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#define PT_FUNCTION __func__
#else
#define PT_FUNCTION "<unknown>"
#endif

// Internal macros (should not be used by developers or testers)

#define PT_STR(STR) #STR

#define PT_CHECK(EXPR, MSG, TERM) \
  partest::TestSuite::Check(EXPR, PT_STR(EXPR), __FILE__, PT_FUNCTION, __LINE__, MSG, TERM);

#define PT_CHECK_OP(EXPR1, EXPR2, REL_OP, MSG, TERM) \
  partest::TestSuite::Check(EXPR1, REL_OP(), EXPR2, PT_STR(EXPR1), PT_STR(EXPR2), __FILE__, PT_FUNCTION, __LINE__, MSG, TERM);

#define PT_RUN(PT_TEST) \
( \
  (std::cout << "Running " << #PT_TEST << " ..." << std::endl), \
  (PT_TEST().Run()), \
  (std::cout << "Running " << #PT_TEST << " ..." << " done" << std::endl) \
)

#define PT_MAIN(component) \
void PartestRunTests(); \
int main(int argc, char** argv) { \
  std::cout << "Running "<< component <<" tests ..." << std::endl; \
  if (argc > 1) { \
    size_t num_threads = static_cast<size_t>(atoi(argv[1])); \
    partest::TestSuite::SetDefaultNumThreads(num_threads); \
  } \
  if (argc > 2) { \
    size_t num_iterations = static_cast<size_t>(atoi(argv[2])); \
    partest::TestSuite::SetDefaultNumIterations(num_iterations); \
  } \
  PartestRunTests(); \
  std::cout << "Running "<< component <<" tests ... done" << std::endl; \
  std::cout << "Failed checks: " << partest::TestSuite::GetFailedExpects() << \
  " out of " << partest::TestSuite::GetFailedExpects() + \
  partest::TestSuite::GetPassedExpects() + \
  partest::TestSuite::GetPassedAsserts() << " total checks" <<std::endl; \
  return static_cast<int>(partest::TestSuite::GetFailedExpects()); \
} \
void PartestRunTests()


namespace partest {
namespace internal {
  struct REL_EQ;
  struct REL_NE;
  struct REL_LT;
  struct REL_LE;
  struct REL_GT;
  struct REL_GE;

/** Comparison (equal).
 *
 */
struct REL_EQ {
  template<typename T1, typename T2>
  bool operator()(T1 value1, T2 value2) const {
    return value1 == value2;
  }
  const char* get_op() const {
    return "==";
  }
  typedef REL_NE inverse_t;
};

/** Comparison (not equal)
 *
 */
struct REL_NE {
  template<typename T1, typename T2>
  bool operator()(T1 value1, T2 value2) const {
    return value1 != value2;
  }
  const char* get_op() const {
    return "!=";
  }
  typedef REL_EQ inverse_t;
};

/** Comparison (less than)
 *
 */
struct REL_LT {
  template<typename T1, typename T2>
  bool operator()(T1 value1, T2 value2) const {
    return value1 < value2;
  }
  const char* get_op() const {
    return "<";
  }
  typedef REL_GE inverse_t;
};

/** Comparison (less than or equal)
 *
 */
struct REL_LE {
  template<typename T1, typename T2>
  bool operator()(T1 value1, T2 value2) const {
    return value1 <= value2;
  }
  const char* get_op() const {
    return "<=";
  }
  typedef REL_GT inverse_t;
};

/** Comparison (greater than)
 *
 */
struct REL_GT {
  template<typename T1, typename T2>
  bool operator()(T1 value1, T2 value2) const {
    return value1 > value2;
  }
  const char* get_op() const {
    return ">";
  }
  typedef REL_LE inverse_t;
};

/** Comparison (greater than or equal)
 *
 */
struct REL_GE {
  template<typename T1, typename T2>
  bool operator()(T1 value1, T2 value2) const {
    return value1 >= value2;
  }
  const char* get_op() const {
    return ">=";
  }
  typedef REL_LT inverse_t;
};

}  // namespace internal
}  // namespace partest

// Unary predicates

#define PT_ASSERT(EXPR) PT_CHECK(EXPR, NULL, true)
#define PT_EXPECT(EXPR) PT_CHECK(EXPR, NULL, false)

#define PT_ASSERT_MSG(EXPR, MSG) PT_CHECK(EXPR, MSG, true)
#define PT_EXPECT_MSG(EXPR, MSG) PT_CHECK(EXPR, MSG, false)

// Binary predicates (general)

#define PT_ASSERT_EQ(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_EQ, NULL, true)
#define PT_ASSERT_NE(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_NE, NULL, true)
#define PT_ASSERT_LT(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_LT, NULL, true)
#define PT_ASSERT_LE(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_LE, NULL, true)
#define PT_ASSERT_GT(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_GT, NULL, true)
#define PT_ASSERT_GE(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_GE, NULL, true)

#define PT_EXPECT_EQ(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_EQ, NULL, false)
#define PT_EXPECT_NE(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_NE, NULL, false)
#define PT_EXPECT_LT(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_LT, NULL, false)
#define PT_EXPECT_LE(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_LE, NULL, false)
#define PT_EXPECT_GT(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_GT, NULL, false)
#define PT_EXPECT_GE(EXPR1, EXPR2) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_GE, NULL, false)

// Binary predicates (general with messages)

#define PT_ASSERT_EQ_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_EQ, MSG, true)
#define PT_ASSERT_NE_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_NE, MSG, true)
#define PT_ASSERT_LT_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_LT, MSG, true)
#define PT_ASSERT_LE_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_LE, MSG, true)
#define PT_ASSERT_GT_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_GT, MSG, true)
#define PT_ASSERT_GE_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_GE, MSG, true)

#define PT_EXPECT_EQ_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_EQ, MSG, false)
#define PT_EXPECT_NE_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_NE, MSG, false)
#define PT_EXPECT_LT_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_LT, MSG, false)
#define PT_EXPECT_LE_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_LE, MSG, false)
#define PT_EXPECT_GT_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_GT, MSG, false)
#define PT_EXPECT_GE_MSG(EXPR1, EXPR2, MSG) PT_CHECK_OP(EXPR1, EXPR2, partest::internal::REL_GE, MSG, false)

#endif  // PARTEST_PARTEST_H_

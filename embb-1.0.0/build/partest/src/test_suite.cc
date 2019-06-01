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

#include <partest/test_suite.h>
#include <partest/test_unit.h>
#include <partest/test_instance_info.h>
#include <partest/test_case.h>

#include <partest/internal/mutex.h>

namespace partest {

void TestSuite::SetStream(std::ostream& output_stream) {
  ostr_ = &output_stream;
}

std::ostream& TestSuite::GetStream() {
  return *ostr_;
}

size_t TestSuite::GetPassedExpects() {
  return passed_expects_;
}

size_t TestSuite::GetFailedExpects() {
  return failed_expects_;
}

size_t TestSuite::GetPassedAsserts() {
  return passed_asserts_;
}

size_t TestSuite::GetMaxFailedExpects() {
  return max_failed_expects_;
}

void TestSuite::SetMaxFailedExpects(size_t max_failed_exp) {
  max_failed_expects_ = max_failed_exp;
}

void TestSuite::ReportException(const char* what) {
  Emit(std::string("Uncaught exception: ") + what, NULL, true);
}

void TestSuite::Check(bool result, const char* expr, const char* file,
    const char* func, size_t line, const char* message, bool terminate) {
  if (result) {
    internal::LockGuard<internal::Mutex> lock(mtx_);
    if (terminate)
      passed_asserts_++;
    else
      passed_expects_++;
    return;
  }
  std::stringstream ss;
  ss << "CHECK FAILED" << std::endl;
  ss << "Expression: " << expr << std::endl;
  ss << "File      : " << file << std::endl;
  ss << "Method    : " << func << std::endl;
  ss << "Line      : " << line << std::endl;
  Emit(ss.str(), message, terminate);
}

void TestSuite::Emit(std::string string, const char* message, bool terminate) {
  {
    internal::LockGuard<internal::Mutex> lock(mtx_);
    if (stopped_) {
      return;
    }
    if (failed_expects_ > 0) {
      *ostr_
          << "--------------------------------------------------------------------------------"
          << std::endl;
    }
    *ostr_ << string << std::endl;
    if (message != NULL) {
      *ostr_ << message << std::endl;
    }
    TestInstanceInfo* instance = TestMethod::GetTestInstanceInfo();
    if (instance != NULL) {
      *ostr_ << "Test unit: " << instance->GetUnitName() << std::endl;
      *ostr_ << "Method thread num: " << instance->GetInstanceNum() << std::endl;
      *ostr_ << "Method iteration num: " << instance->GetIterationNum()
          << std::endl;
    }
    if (!terminate) {
      failed_expects_++;
    }
    if (terminate
        || ((max_failed_expects_ > 0)
            && (failed_expects_ >= max_failed_expects_))) {
      stopped_ = true;
    }
  }
  if (stopped_) {
    exit(EXIT_FAILURE);
  }
}

std::ostream* TestSuite::ostr_(&std::cerr);
size_t TestSuite::passed_expects_(0);
size_t TestSuite::failed_expects_(0);
size_t TestSuite::passed_asserts_(0);
size_t TestSuite::max_failed_expects_(0);
bool TestSuite::stopped_(false);
internal::Mutex TestSuite::mtx_;

}  // namespace partest

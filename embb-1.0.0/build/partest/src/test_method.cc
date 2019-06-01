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

#include <partest/test_method.h>
#include <partest/test_instance_info.h>
#include <partest/test_suite.h>

#include <partest/internal/thread_specific_storage.h>

#include <algorithm>

namespace partest {

TestMethod::TestMethod(void (*function)(), size_t instances, size_t iterations) :
    fn_base_(new internal::Function(function)) {
  Init(instances, iterations);
}

TestMethod::~TestMethod() {
  delete fn_base_;
}

size_t TestMethod::GetNumInstances() const {
  return instances_;
}

size_t TestMethod::GetNumIterations() const {
  return iterations_;
}

size_t TestMethod::GetMaxInstances() {
  return max_inst;
}

void TestMethod::SetMaxInstances(size_t max_instances) {
  max_inst = max_instances;
}

size_t TestMethod::GetMaxIterations() {
  return max_iter;
}

void TestMethod::SetMaxIterations(size_t max_iterations) {
  max_iter = max_iterations;
}

void TestMethod::Init(size_t instances, size_t iterations) {
  if (instances == 0) {
    std::cerr << "Number of instances must be greater than zero" << std::endl;
    exit(EXIT_FAILURE);
  }
  instances_ = instances;

  if (iterations == 0) {
    std::cerr << "Number of iterations must be greater than zero" << std::endl;
    exit(EXIT_FAILURE);
  }
  iterations_ = iterations;
}

int TestMethod::Run(TestInstanceInfo* info) {
  TestMethod* method = info->GetTestMethod();
  size_t iterations =
      TestMethod::GetMaxIterations() > 0 ?
          std::min(method->GetNumIterations(), TestMethod::GetMaxIterations()) :
          method->GetNumIterations();
  tls.Reset(info);
#ifndef PARTEST_DISABLE_EXCEPTIONS
  try {
#endif
    for (info->SetIterationNum(0); info->GetIterationNum() < iterations;
        info->SetIterationNum((info->GetIterationNum() + 1))) {
      method->fn_base_->operator()();
    }
#ifndef PARTEST_DISABLE_EXCEPTIONS
  } catch (std::exception& e) {
    TestSuite::ReportException(e.what());
  } catch (...) {
    TestSuite::ReportException("unknown");
  }
#endif
  tls.Release(); // Tell tls to not to delete resources
  return 0;
}

internal::ThreadSpecificStorage<TestInstanceInfo> TestMethod::tls;

TestInstanceInfo* TestMethod::GetTestInstanceInfo() {
  return tls.get();
}

size_t TestMethod::max_inst(0);
size_t TestMethod::max_iter(0);
}  // namespace partest

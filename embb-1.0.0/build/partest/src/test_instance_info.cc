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

#include <partest/test_instance_info.h>
#include <partest/test_unit.h>
#include <partest/test_case.h>
#include <iostream>

namespace partest {

TestInstanceInfo::TestInstanceInfo(const std::string& unit_name,
    TestMethod *ptr) :
    unit_name_(unit_name), test_method_ptr_(ptr), thread_num_(0), instance_num_(
        0), iteration_num_(0) {
}

TestInstanceInfo::TestInstanceInfo(const TestInstanceInfo& test_case_arguments) :
    unit_name_(test_case_arguments.unit_name_), test_method_ptr_(
        test_case_arguments.test_method_ptr_), thread_num_(
        test_case_arguments.thread_num_), instance_num_(
        test_case_arguments.instance_num_), iteration_num_(
        test_case_arguments.iteration_num_) {
}

TestInstanceInfo::~TestInstanceInfo() {
}

TestMethod* TestInstanceInfo::GetTestMethod() const {
  return test_method_ptr_;
}

size_t TestInstanceInfo::GetThreadNum() const {
  return thread_num_;
}

size_t TestInstanceInfo::GetInstanceNum() const {
  return instance_num_;
}

size_t TestInstanceInfo::GetIterationNum() const {
  return iteration_num_;
}

void TestInstanceInfo::SetThreadNum(size_t thread_num) {
  this->thread_num_ = thread_num;
}

void TestInstanceInfo::SetInstanceNum(size_t instance_num) {
  this->instance_num_ = instance_num;
}

void TestInstanceInfo::SetIterationNum(size_t iteration_num) {
  this->iteration_num_ = iteration_num;
}

TestInstanceInfo* TestInstanceInfo::GetTestInstanceInfo() {
  TestInstanceInfo* instance(TestMethod::GetTestInstanceInfo());
  if (instance == NULL) {
    std::cerr << "No active test instance" << std::endl;
    exit(EXIT_FAILURE);
  }
  return instance;
}
}  // namespace partest

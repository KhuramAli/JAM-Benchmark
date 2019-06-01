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

#include <partest/test_unit.h>

#include <utility>
#include <cassert>
#include <algorithm>
#include <iostream>

#include <partest/partest.h>
#include <partest/test_instance_info.h>
#include <partest/test_method.h>
#include <partest/internal/allocate.h>

#include <partest/internal/thread.h>

namespace partest {

TestUnit::TestUnit(const std::string& name) :
    name_(name), pre_method_(NULL), post_method_(NULL) {
}

TestUnit::~TestUnit() {
  if (pre_method_ != NULL) {
    delete pre_method_;
  }
  if (post_method_ != NULL) {
    delete post_method_;
  }
  for (size_t i = 0; i < test_methods_.size(); i++) {
    delete (test_methods_[i]);
  }
}

void TestUnit::Add(TestMethod* unit) {
  test_methods_.push_back(unit);
}

void TestUnit::AddPre(TestMethod* unit) {
  PT_ASSERT_EQ_MSG(pre_method_, (partest::TestMethod*)NULL,
      "Can only add precondition once");
  pre_method_ = unit;
}

void TestUnit::AddPost(TestMethod* unit) {
  PT_ASSERT_EQ_MSG(post_method_, (partest::TestMethod*)NULL,
      "Can only add postcondition once");
  post_method_ = unit;
}

TestUnit& TestUnit::Add(void (*function)(), size_t instances,
    size_t iterations) {
  Add(new TestMethod(function, instances, iterations));
  return *this;
}

TestUnit& TestUnit::Pre(void (*function)()) {
  AddPre(new TestMethod(function, 1, 1));
  return *this;
}

TestUnit& TestUnit::Post(void (*function)()) {
  AddPost(new TestMethod(function, 1, 1));
  return *this;
}

void TestUnit::Run() {
  size_t thread_num = 0;
  typedef std::pair<TestInstanceInfo*, internal::Thread*> context_t;
  std::vector<context_t> context_vector;

  if (pre_method_ != NULL) { // Run pre method
    TestInstanceInfo* instance = internal::aligned_new(
        TestInstanceInfo(name_, pre_method_));
    instance->SetThreadNum(thread_num++);
    instance->SetInstanceNum(0);
    internal::Thread thread(&TestMethod::Run, instance);
    thread.Join();
    internal::aligned_delete(instance);
  }

  // Run test methods in parallel
  thread_num = 0;
  for (size_t i = 0; i < test_methods_.size(); i++) {
    TestMethod* method = test_methods_[i];
    size_t instances = method->GetNumInstances();
    if (TestMethod::GetMaxInstances() > 0) { // Larger zero means limit set
      instances = std::min(method->GetNumInstances(),
          TestMethod::GetMaxInstances());
    }
    for (size_t j = 0; j < instances; j++) {
      TestInstanceInfo* instance = internal::aligned_new(
          TestInstanceInfo(name_, method));
      instance->SetThreadNum(thread_num++);
      instance->SetInstanceNum(j);
      context_vector.push_back(
          context_t(instance,
              new internal::Thread(&TestMethod::Run, instance)));
    }
  }
  // Join test method threads and free memory
  for (size_t i = 0; i < context_vector.size(); i++) {
    context_vector[i].second->Join();
    assert(context_vector[i].first != NULL);
    internal::aligned_delete(context_vector[i].first);
    delete context_vector[i].second;
  }

  thread_num = 0;
  if (post_method_ != NULL) { // Run post method
    TestInstanceInfo* instance = internal::aligned_new(
        TestInstanceInfo(name_, post_method_));
    instance->SetThreadNum(thread_num++);
    instance->SetInstanceNum(0);
    internal::Thread thread(&TestMethod::Run, instance);
    thread.Join();
    internal::aligned_delete(instance);
  }
}

}  // namespace partest

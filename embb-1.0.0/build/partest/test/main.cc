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

#include <iostream>
#include <cassert>
#include <functional>

#include <partest/partest.h>

using namespace std;

void foo() {
  //cout << "foo" << endl;
  PT_EXPECT(true);
}

class bar {
public:
  bar() :
      cnt(0) {
  }
  void operator()() {
    //  cout << "bar" << endl;
    PT_EXPECT_MSG(1 == 0, "Not really true");
    PT_EXPECT_EQ(1 + 1, 0);
    cnt++;
  }
  int cnt;
};

bar b;

class test_incdec: public partest::TestUnit {

private:

  int counter;

  void inc() {
    volatile int i;
    for (i = 1; i < 10000; i++)
      ;
    PT_EXPECT_LT(string("cd"), string("cc"));
    counter++;
  }

  void dec() {
    volatile int i;
    for (i = 1; i < 10000; i++)
      ;
    PT_EXPECT(counter < 0);
    counter--;
  }

public:

  test_incdec() :
      partest::TestUnit("indec"), counter(0) {

    Add(&test_incdec::inc, this, 2, 3);
    Add(&test_incdec::dec, this, 2, 3);
    Add(&foo, 2);
    Add(b, 2);
    // add(test_unit("Bar2", bar(), 2));
    // add(test_unit("Lambda", [] {cout << "lambda" << endl;}));
  }

  ~test_incdec() {
    PT_ASSERT_EQ(counter, 1); // TODO
  }

};

PT_MAIN("Partest") {
  PT_RUN(test_incdec);
}

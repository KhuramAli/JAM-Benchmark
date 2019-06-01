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

#ifndef PARTEST_INTERNAL_FUNCTION_H_
#define PARTEST_INTERNAL_FUNCTION_H_

#include <iostream>
#include <cstddef>
#include <cstdlib>

namespace partest {
namespace internal {
/**
 * Base class for functions.
 * An object of this class represents an executable piece of code, e.g.,
 * an ordinary function, a member function or a function object / functor.
 * Only functions with \c void return type and zero parameters are supported.
 * Each object also contains a reference counter for memory management.
 */

class FunctionBase {
 public:
  /**
   * Default constructor.
   * Creates a new object and initializes the reference counter with one.
   */
  FunctionBase() {
  }

  /**
   *  Destructor.
   *  Destroys the object
   */
  virtual ~FunctionBase() {
  }

  /**
   *  Function operator.
   *  Calls the function.
   */
  virtual void operator()() = 0;

 private:
  /**
   * Disallow copy constructor and assignment.
   */
  FunctionBase(const FunctionBase&);
  FunctionBase& operator=(const FunctionBase&);
};

/**
 *  Subclass for functions.
 *  An object of this class represents an ordinary function.
 */
class Function: public FunctionBase {
public:
  /**
   *  Constructor.
   *  Creates a new object from a function pointer.
   *  \param function_ptr Pointer to function
   */
  Function(void (*function_ptr)()) :
      fn_ptr(function_ptr) {
    if (function_ptr == NULL) {
      std::cerr << "Invalid function pointer" << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  /** Function operator.
   * Calls the function.
   */
  void operator()() {
    (*fn_ptr)();
  }

private:
  void (*fn_ptr)();
  /**
   * Disallow copy constructor and assignment.
   */
  Function(const Function&);
  Function& operator=(const Function&);
};

/**
 * Subclass for member functions.
 * An object of this class represents a member function.
 * \tparam F Class of member function
 */
template<typename F>
class MemberFunction: public FunctionBase {
public:
  /**
   * Constructor.
   * Creates a new object from a pointer to a member function and a
   * Pointer to the associated object.
   * \param member_function_ptr Pointer to member function
   * \param object_ptr Pointer to object
   */
  MemberFunction(void (F::*member_function_ptr)(), F* object_ptr) :
      mem_fn_ptr(member_function_ptr), obj_ptr(object_ptr) {
    if (member_function_ptr == NULL || object_ptr == NULL) {
      std::cerr << "Invalid pointer to member function or object" << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  /**
   * Function operator.
   * Calls the member function.
   */
  void operator()() {
    (obj_ptr->*mem_fn_ptr)();
  }

private:
  void (F::*mem_fn_ptr)();
  F* obj_ptr;
  /**
   * Disallow copy constructor and assignment.
   */
  MemberFunction(const MemberFunction&);
  MemberFunction& operator=(const MemberFunction&);
};

/**
 *  Subclass for function objects.
 *  An object of this class represents a function object.
 *  \param F Class of function object.
 */
template<typename F>
class FunctionObject: public FunctionBase {
public:
  /**
   * Constructor.
   * Creates a new object from a function object.
   * \param function_obj Function object
   */
  explicit FunctionObject(F function_obj) :
      fn_obj(function_obj) {
  }

  /**
   * Function operator.
   * Calls the function object.
   */
  void operator()() {
    fn_obj();
  }
private:
  F fn_obj;
  /**
   * Disallow copy constructor and assignment.
   */
  FunctionObject(const FunctionObject&);
  FunctionObject& operator=(const FunctionObject&);
};

}  // namespace internal
}  // namespace partest

#endif  // PARTEST_INTERNAL_FUNCTION_H_

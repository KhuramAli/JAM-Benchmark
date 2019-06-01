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

#ifndef PARTEST_INTERNAL_EXCEPTIONS_H_
#define PARTEST_INTERNAL_EXCEPTIONS_H_

#include <string>
#include <exception>

namespace partest {
namespace internal {

/**
 * Abstract base class for any exception in PARTEST.
 */
class Exception : public std::exception {
 public:
  /**
   * Constructs an exception with a custom message.
   */
  Exception(const char* message) : message_(message) {}

  /**
   * Destructor.
   */
  virtual ~Exception() throw() {}

  /**
   * Copy constructor.
   */
  Exception(const Exception& e) : message_(e.message_) {}

  /**
   * Assignment operator.
   */
  Exception& operator=(const Exception& e) {
    message_ = e.message_;
    return *this;
  }

  /**
   * Returns exception message.
   */
  virtual const char* what() const throw() { return message_; }

 private:
  /**
   * Holds exception message.
   */
  const char* message_;
};

/**
 * Indicates a lack of memory neccessary to allocate a resource.
 */
class NoMemoryException : public Exception {
 public:
  NoMemoryException(const char* message) : Exception(message) {}
};

/**
 * Indicates the busyness and, hence, unavailability of a required resource.
 */
class ResourceBusyException : public Exception {
 public:
  ResourceBusyException(const char* message) : Exception(message) {}
};

/**
 * Indicates a numeric underflow.
 */
class UnderflowException : public Exception {
 public:
  UnderflowException(const char* message) : Exception(message) {}
};

/**
 * Indicates a numeric overflow.
 */
class OverflowException : public Exception {
 public:
  OverflowException(const char* message) : Exception(message) {}
};

/**
 * Indicates a general error.
 */
class ErrorException : public Exception {
 public:
  ErrorException(const char* message) : Exception(message) {}
};

} // namespace internal
} // namespace partest

#endif /* PARTEST_INTERNAL_EXCEPTIONS_H_ */

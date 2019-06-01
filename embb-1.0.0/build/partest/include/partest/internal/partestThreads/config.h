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

#ifndef PARTEST_INTERNAL_PARTEST_THREADS_CONFIG_H_
#define PARTEST_INTERNAL_PARTEST_THREADS_CONFIG_H_

/* Define names:
 * - threading platforms: PARTEST_THREADING_
 * - compilers: PARTEST_COMPILER_
 * - oprating systems: PARTEST_OS_
 */

#if __GNUC__
#define PARTEST_INLINE static inline
#define PARTEST_COMPILER_GNUC
#elif _MSC_VER
#define PARTEST_INLINE __inline
#define PARTEST_COMPILER_MSVC
#else
#define PARTEST_INLINE inline
#define PARTEST_COMPILER_UNKNOWN
#endif

#if defined(__x86_64__) || defined(_M_X64)
#define PARTEST_ARCH_X86_64
#define PARTEST_ARCH_X86
#define PARTEST_HAS_CAS_64
#elif defined(__i386) || defined(_M_IX86)
#define PARTEST_ARCH_X86_32
#define PARTEST_ARCH_X86
#else
#define PARTEST_ARCH_UNKNOWN
#endif

/*#define PARTEST_THREADING_CXX11*//* Enables C++11 implementation */

#if defined(PARTEST_COMPILER_MSVC)
#define PARTEST_THREADING_WINTHREADS
#elif defined(PARTEST_COMPILER_GNUC)
#define PARTEST_THREADING_POSIXTHREADS
#else
#error "No thread implementation could be determined"
#endif

/* Disable exceptions in STL of MSVC. Leads to errors when used like this!!! */
/*#if defined(PARTEST_COMPILER_MSVC) && !defined(PARTEST_USE_EXCEPTIONS)
 #define _HAS_EXCEPTIONS 0
 #endif*/

#endif /* PARTEST_INTERNAL_PARTEST_THREADS_CONFIG_H_ */

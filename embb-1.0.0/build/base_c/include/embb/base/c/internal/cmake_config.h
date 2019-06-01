/*
 * Copyright (c) 2014-2017, Siemens AG. All rights reserved.
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

#ifndef EMBB_BASE_C_INTERNAL_CMAKE_CONFIG_H_
#define EMBB_BASE_C_INTERNAL_CMAKE_CONFIG_H_

/* This file is used as input for CMake. CMake creates a file cmake_config.h in
   its current build directory under the path builddir/embb/base/internal/. From
   there, the cmake_config.h can be included as usual using
   #include <embb/base/c/internal/cmake_config.h>
 */ 

/**
 * Is used to get the number of cores on certain systems.
 */
#define EMBB_PLATFORM_HAS_HEADER_SYSINFO

/**
 * Is used to get the number of cores on certain systems.
 */
#define EMBB_PLATFORM_HAS_SC_NPROCESSORS_ONLN

/**
 * Is used to set thread affinities on certain systems.
 */
/* #undef EMBB_PLATFORM_HAS_HEADER_CPUSET */

/**
 * Is used to set thread affinities on certain systems.
 */
/* #undef EMBB_PLATFORM_HAS_HEADER_PTHREAD_NP */

/**
 * Is used for Linux thread affinities.
 */
#define EMBB_PLATFORM_HAS_GLIB_CPU

/**
 * Enables mutex-based implementation of all synchronization constructs.
 */
/* #undef EMBB_THREADING_ANALYSIS_MODE */

/* #undef EMBB_PLATFORM_USE_C11_CXX11 */

/**
 * Version defines.
 */
#define EMBB_BASE_VERSION_MAJOR 1
#define EMBB_BASE_VERSION_MINOR 0
#define EMBB_BASE_VERSION_PATCH 0


#endif /* EMBB_BASE_INTERNAL_CMAKE_CONFIG_H_ */

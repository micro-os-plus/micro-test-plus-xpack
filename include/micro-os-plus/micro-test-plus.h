/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief Main C++ header with the declarations for the µTest++ Testing
 * Framework.
 *
 * @details
 * This header serves as the principal entry point for the µTest++ testing
 * framework, purpose-built for both embedded and general C++ projects.
 *
 * It provides all essential declarations required to write and manage tests,
 * including test runner and reporter objects, test suite and test case
 * management, expectations, assumptions, comparators, logical operators,
 * exception verification, and utility functions.
 *
 * The header also incorporates all necessary dependencies and internal headers
 * to ensure the framework operates correctly and efficiently.
 *
 * All public API definitions reside within the
 * `micro_os_plus::micro_test_plus` namespace and its nested namespaces,
 * ensuring clear separation from user code and minimising the risk of naming
 * conflicts.
 *
 * This file is located in the top-level `include/micro-os-plus` folder; all
 * other header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured
 * and modular codebase.
 *
 * To access the complete functionality of the µTest++ framework, users should
 * include this header in their test projects.
 *
 * The implementation is significantly inspired by Boost UT, with adaptations
 * and extensions to address the requirements of embedded development and the
 * µTest++ framework.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
#if !(__cplusplus >= 202002L || (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L))
#error "C++20 or higher is required"
#endif // !(__cplusplus >= 202002L || (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L))
#endif // defined(__cplusplus)

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

// ----------------------------------------------------------------------------

#if defined(__DOXYGEN__)
// Present here solely for Doxygen, to document the macros.
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
#endif // defined(__DOXYGEN__)

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

// No deps.
#include "micro-test-plus/math.h"

// Requires math.h.
#include "micro-test-plus/values.h"

// Requires values.h.
#include "micro-test-plus/extension.h"

// No deps.
#include "micro-test-plus/reflection.h"

// Requires extension.h, reflection.h.
#include "micro-test-plus/detail.h"

// No deps.
#include "micro-test-plus/function-comparators.h"

// No deps.
#include "micro-test-plus/exceptions.h"

// Requires extension.h, detail.h + reflection.h.
#include "micro-test-plus/expression-formatter.h"

// No deps.
#include "micro-test-plus/runner-options.h"

// Requires extension.h, detail.h, expression-formatter.h, reflection.h,
// runner-options.h.
#include "micro-test-plus/reporter.h"

// Requires extension.h, reflection.h, expression-formatter.h.
#include "micro-test-plus/check-result.h"

// No deps.
#include "micro-test-plus/counters.h"

// Requires reporter.h, reflection.h.
#include "micro-test-plus/reporter-human.h"

// Requires reporter.h, reflection.h.
#include "micro-test-plus/reporter-tap.h"

// No deps.
#include "micro-test-plus/utility.h"

// Requires reporter.h, counters.h, reflection.h, extension.h and
// stopwatch.h + check-result.h, reporter.h.
#include "micro-test-plus/test.h"

// Requires stopwatch.h, test.h (top_suite), counters.h, reflection.h,
// runner-options.h.
#include "micro-test-plus/runner.h"

// Requires counters.h, extension.h, function-comparators.h, math.h,
// reflection.h, runner.h, stopwatch.h, test.h.
#include "micro-test-plus/deprecated.h"

// Defined in detail.h for the library formats only; the templates above
// have already been parsed, so keep it out of the application code.
#undef MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

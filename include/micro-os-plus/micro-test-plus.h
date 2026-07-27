/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
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
 * This file is located in the top-level `include/micro-os-plus` directory; all
 * other header files are organised within the
 * `include/micro-os-plus/micro-test-plus` directory to maintain a structured
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

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
#if !(__cplusplus >= 202002L || (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L))
#error "C++20 or higher is required"
#endif
#endif // defined(__cplusplus)

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

// ----------------------------------------------------------------------------

// No deps.
#include "micro-test-plus/math.h"

// Requires math.h.
#include "micro-test-plus/type-traits.h"

// No deps.
#include "micro-test-plus/reflection.h"

// Requires type-traits.h, reflection.h.
#include "micro-test-plus/detail.h"

// Requires type-traits.h, math.h.
#include "micro-test-plus/literals.h"

// No deps.
#include "micro-test-plus/function-comparators.h"

// No deps.
#include "micro-test-plus/exceptions.h"

// Requires type-traits.h + detail.h,
#include "micro-test-plus/operators.h"

// Requires type-traits.h, detail.h + reflection.h.
#include "micro-test-plus/expression-formatter.h"

// Requires type-traits.h, detail.h, expression-formatter.h, reflection.h.
#include "micro-test-plus/reporter.h"

// Requires type-traits.h, reflection.h, expression-formatter.h.
#include "micro-test-plus/deferred-reporter.h"

// No deps.
#include "micro-test-plus/runner-totals.h"

// Requires reporter.h, reflection.h.
#include "micro-test-plus/reporter-human.h"

// Requires reporter.h, reflection.h.
#include "micro-test-plus/reporter-tap.h"

// No deps.
#include "micro-test-plus/utility.h"

// Requires reporter.h, runner-totals.h, reflection.h, type-traits.h and
// timings.h + deferred-reporter.h, reporter.h.
#include "micro-test-plus/test.h"

// Requires timings.h, test.h (detail::test_node, top_suite), reflection.h.
#include "micro-test-plus/runner.h"

// ----------------------------------------------------------------------------

/**
 * @namespace micro_os_plus::micro_test_plus
 * @brief Primary namespace for the µTest++ testing framework.
 *
 * @details
 * The `micro_os_plus::micro_test_plus` namespace encapsulates all core
 * components, types, and utilities of the µTest++ testing framework, providing
 * a dedicated scope for its public API.
 *
 * This namespace is structured into several nested namespaces, each
 * responsible for a specific aspect of the framework, such as mathematical
 * utilities, type traits, literals, test suite and test case management, test
 * runners, test reporters, internal details, operators, and utility functions.
 *
 * By grouping all definitions within this namespace and its sub-namespaces,
 * the framework achieves clear code organisation, minimises naming conflicts,
 * and enhances maintainability. This modular structure supports robust,
 * scalable, and professional test development for both embedded and general
 * C++ projects.
 *
 * All public API definitions are implemented in the `include/micro-os-plus`
 * folder, ensuring a clear separation from user code and facilitating
 * straightforward integration with the wider µOS++ ecosystem.
 */

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

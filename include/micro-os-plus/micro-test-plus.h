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

#ifndef MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_
#define MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include "micro-test-plus/type-traits.h"
#include "micro-test-plus/reflection.h"

#include "micro-test-plus/detail.h"

#include "micro-test-plus/math.h"
#include "micro-test-plus/literals.h"
#include "micro-test-plus/function-comparators.h"
#include "micro-test-plus/exceptions.h"
#include "micro-test-plus/operators.h"

#include "micro-test-plus/deferred-reporter.h"
#include "micro-test-plus/test.h"

#include "micro-test-plus/runner.h"
#include "micro-test-plus/runner-totals.h"

#include "micro-test-plus/reporter.h"
#include "micro-test-plus/reporter-human.h"
#include "micro-test-plus/reporter-tap.h"

#include "micro-test-plus/utility.h"

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

// ============================================================================
// Templates & constexpr implementations.

#include <micro-os-plus/diag/trace.h>

// All inlines are included **after** all declarations.
#include "micro-test-plus/inlines/literals-inlines.h"
#include "micro-test-plus/inlines/math-inlines.h"

#include "micro-test-plus/inlines/reflection-inlines.h"

#include "micro-test-plus/inlines/deferred-reporter-inlines.h"
#include "micro-test-plus/inlines/reporter-inlines.h"

#include "micro-test-plus/inlines/function-comparators-inlines.h"
#include "micro-test-plus/inlines/runner-inlines.h"
#include "micro-test-plus/inlines/test-inlines.h"

#include "micro-test-plus/inlines/utility-inlines.h"

// ----------------------------------------------------------------------------

/**
 * @defgroup micro-test-plus-config Configuration Macros
 * @brief Preprocessor macros for controlling µTest++ behaviour.
 *
 * @details
 * The following macros may be defined in the project configuration header
 * (typically `<micro-os-plus/config.h>`) to customise the behaviour of the
 * µTest++ framework at compile time.
 *
 * Trace macros have effect only when `MICRO_OS_PLUS_TRACE` is also defined.
 */

/**
 * @def MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
 * @ingroup micro-test-plus-config
 * @brief Enable general trace output for µTest++ framework internals.
 *
 * @details
 * When this macro is defined alongside `MICRO_OS_PLUS_TRACE`, the µTest++
 * framework emits `trace::printf()` messages for key runtime events such
 * as test suite initialisation, argument parsing, and test execution entry
 * and exit points.
 *
 * This macro is intended for framework debugging and is not required for
 * normal test development. It should be defined in the platform-specific
 * `<micro-os-plus/config.h>` header.
 *
 * Example:
 * @code{.cpp}
 * #if defined(MICRO_OS_PLUS_TRACE)
 * #define MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
 * #endif
 * @endcode
 */

/**
 * @def MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
 * @ingroup micro-test-plus-config
 * @brief Enable trace output for µTest++ constructor and destructor calls.
 *
 * @details
 * When this macro is defined alongside `MICRO_OS_PLUS_TRACE`, each
 * constructor and destructor in the µTest++ framework emits a
 * `trace::printf()` line containing the function signature
 * (`__PRETTY_FUNCTION__`) and, where applicable, the object name or index.
 *
 * This macro provides fine-grained visibility into object lifetime and is
 * primarily useful for diagnosing construction order issues in complex
 * test hierarchies. It should be defined in the platform-specific
 * `<micro-os-plus/config.h>` header.
 *
 * Example:
 * @code{.cpp}
 * #if defined(MICRO_OS_PLUS_TRACE)
 * #define MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
 * #endif
 * @endcode
 */

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

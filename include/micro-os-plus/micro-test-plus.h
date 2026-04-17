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
#include "micro-test-plus/operators.h"

#include "micro-test-plus/deferred-reporter.h"
#include "micro-test-plus/test.h"

#include "micro-test-plus/runner.h"
#include "micro-test-plus/runner-totals.h"

#include "micro-test-plus/reporter.h"
#include "micro-test-plus/reporter-human.h"
#include "micro-test-plus/reporter-tap.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// ============================================================================

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

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // Public API.

#if defined(__cpp_exceptions)

  /**
   * @ingroup micro-test-plus-exceptions
   * @brief Check if a callable throws a specific exception.
   *
   * @tparam Exception_T The type of the exception expected to be thrown.
   * @tparam Callable_T The type of the callable object to be invoked.
   * @param [in] func The callable object to check for exception throwing
   * behaviour.
   * @return An output stream to write optional messages.
   */
  template <class Exception_T, class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func);

  /**
   * @ingroup micro-test-plus-exceptions
   * @brief Check if a callable throws an exception (any exception).
   *
   * @tparam Callable_T The type of the callable object to be invoked.
   * @param [in] func The callable object to check for exception throwing
   * behaviour.
   * @return An output stream to write optional messages.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func);

  /**
   * @ingroup micro-test-plus-exceptions
   * @brief Check if a callable does not throw an exception.
   *
   * @tparam Callable_T The type of the callable object to be invoked.
   * @param [in] func The callable object to check for exception safety.
   * @return An output stream to write optional messages.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  nothrow (const Callable_T& func);

#endif

  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::utility
   * @brief Utility functions for the µTest++ testing framework.
   *
   * @details
   * The `micro_os_plus::micro_test_plus::utility` namespace provides a suite
   * of helper functions designed to support advanced string operations and
   * other common tasks within the µTest++ framework.
   *
   * These utilities include functions for pattern matching—such as verifying
   * whether a string matches a specified pattern—and for splitting strings
   * into sub-strings based on delimiters. The implementations are efficient
   * and suitable for both embedded and general C++ projects.
   *
   * By encapsulating these helper functions within a dedicated namespace, the
   * framework maintains clear code organisation and minimises naming
   * conflicts.
   */
  namespace utility
  {
    /**
     * @ingroup micro-test-plus-utility-functions
     * @brief Extracts the file name component from a full path.
     *
     * @param [in] path A null-terminated file path string.
     * @return A pointer to the first character of the file name within
     * `path`, or `path` itself if no directory separator is found.
     */
    [[nodiscard]] const char*
    extract_file_name (const char* path) noexcept;

    /**
     * @ingroup micro-test-plus-utility-functions
     * @brief Check if a string matches a pattern.
     *
     * @param [in] input The string view to be checked.
     * @param [in] pattern The string view containing the pattern to match.
     * @return `true` if the input string matches the pattern; otherwise,
     * `false`.
     */
    [[nodiscard]] bool
    is_match (std::string_view input, std::string_view pattern);

    /**
     * @ingroup micro-test-plus-utility-functions
     * @brief Split a string into a vector of sub-strings.
     *
     * @tparam T Type of the input string.
     * @tparam Delim_T Type of the delimiter.
     *
     * @param [in] input Input string to split.
     * @param [in] delim Delimiter string.
     * @return A vector containing the resulting sub-strings.
     */
    template <class T, class Delim_T>
    [[nodiscard]] auto
    split (T input, Delim_T delim) -> std::vector<T>;

    // ------------------------------------------------------------------------
  } // namespace utility

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ============================================================================
// ===== Inlines & templates implementations ==================================

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

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

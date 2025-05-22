/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
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

/**
 * @mainpage
 * µTest++ is a modern C++ library designed to provide a lightweight and
 * efficient testing framework, purpose-built for embedded systems development.
 *
 * With its clean and expressive C++ API, µTest++ enables developers to write,
 * organise, and execute unit tests with minimal overhead. The framework
 * includes advanced features such as test suites, test cases, and detailed
 * reporting, all tailored to meet the specific needs of embedded environments.
 *
 * Output verbosity is fully configurable via command-line options, allowing
 * users to choose between concise summaries and comprehensive diagnostic
 * information to best suit their workflow.
 *
 * By adopting µTest++, you can achieve robust and maintainable code through
 * systematic and automated testing, supporting professional software
 * engineering practices across your entire project.
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

#include "micro-test-plus/test-suite.h"
#include "micro-test-plus/test-runner.h"
#include "micro-test-plus/test-reporter.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wctad-maybe-unsupported"
#endif
#endif

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

  extern test_runner runner;
  extern test_reporter reporter;
  extern test_suite_base* current_test_suite;

  // --------------------------------------------------------------------------
  // Public API.

  /**
   * @ingroup micro-test-plus-inits
   * @brief Initialise the µTest++ framework.
   *
   * @param [in] argc The number of command-line arguments.
   * @param [in] argv Array of pointers to null-terminated argument strings.
   * @param [in] name The name of the default test suite. Defaults to `"Main"`
   * if not specified.
   * @par Returns
   *  Nothing.
   */
  void
  initialize (int argc, char* argv[], const char* name = "Main");

  /**
   * @ingroup micro-test-plus-inits
   * @brief Complete the test run and return the exit code.
   *
   * @par Parameters
   *	 None.
   * @return 0 if all tests were successful, 1 if any test failed.
   */
  [[nodiscard]] int
  exit_code (void);

  /**
   * @ingroup micro-test-plus-test-case
   * @brief Define and execute a test case.
   *
   * @tparam Callable_T The type of the callable object to be executed as the
   * test case.
   * @tparam Args_T The types of the arguments to be passed to the callable.
   * @param [in] name The test case name or description, used in test reports.
   * @param [in] callable A generic callable object, usually a lambda, invoked
   * to perform the test.
   * @param [in] arguments A possibly empty list of arguments to be passed to
   * the callable.
   * @par Returns
   *  Nothing.
   */
  template <typename Callable_T, typename... Args_T>
  void
  test_case (const char* name, Callable_T&& callable, Args_T&&... arguments);

  /**
   * @ingroup micro-test-plus-expectations
   * @brief Evaluate a generic condition and report the results.
   *
   * @tparam Expr_T The type of the custom expression.
   * @tparam (SFINAE) Enabled only if `Expr_T` is derived from `detail::op` or
   * is convertible to `bool`.
   * @param [in] expr Logical expression to evaluate.
   * @param [in] sl Optional source location, defaulting to the current line.
   * @return An output stream to write optional messages.
   */
  template <class Expr_T, type_traits::requires_t<
                              type_traits::is_op_v<Expr_T>
                              or type_traits::is_convertible_v<Expr_T, bool>>
                          = 0>
  constexpr auto
  expect (const Expr_T& expr, const reflection::source_location& sl
                              = reflection::source_location::current ());

  /**
   * @ingroup micro-test-plus-assumptions
   * @brief Check a condition and, if false, abort test execution.
   *
   * @tparam Expr_T The type of the custom expression.
   * @tparam (SFINAE) Enabled only if `Expr_T` is derived from `detail::op` or
   * is convertible to `bool`.
   * @param [in] expr Logical expression to evaluate.
   * @param [in] sl Optional source location, defaulting to the current line.
   * @return An output stream to write optional messages.
   */
  template <class Expr_T, type_traits::requires_t<
                              type_traits::is_op_v<Expr_T>
                              or type_traits::is_convertible_v<Expr_T, bool>>
                          = 0>
  constexpr auto
  assume (const Expr_T& expr, const reflection::source_location& sl
                              = reflection::source_location::current ());

  // --------------------------------------------------------------------------

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

// ===== Inlines & templates implementations
// ====================================

// All inlines are included **after** all declarations.
#include "micro-test-plus/inlines/details-inlines.h"
#include "micro-test-plus/inlines/literals-inlines.h"
#include "micro-test-plus/inlines/math-inlines.h"

#include "micro-test-plus/inlines/reflection-inlines.h"
#include "micro-test-plus/inlines/test-reporter-inlines.h"

#include "micro-test-plus/inlines/function-comparators-inlines.h"
#include "micro-test-plus/inlines/test-suite-inlines.h"

#include "micro-test-plus/inlines/micro-test-plus-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

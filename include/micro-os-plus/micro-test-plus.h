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
 * @file micro-test-plus.h
 * @brief Principal public header for the µTest++ testing framework.
 *
 * @details
 * This header serves as the primary interface for the µTest++ testing
 * framework, intended for use in both embedded and general C++ projects.
 *
 * It encompasses all essential declarations, including test runner and
 * reporter objects, management of test suites and test cases, expectations,
 * assumptions, comparators, logical operators, exception verification, and
 * utility functions.
 *
 * The file also imports all requisite dependencies and internal headers
 * necessary for the operation of the framework.
 *
 * All public API definitions are contained within the
 * `micro_os_plus::micro_test_plus` namespace and its nested namespaces,
 * ensuring clear separation from user code and minimising the risk of naming
 * conflicts.
 *
 * Users should include this header in their test projects to access the
 * complete functionality of the µTest++ framework.
 */

#ifndef MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_
#define MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include "micro-test-plus/reflection.h"
#include "micro-test-plus/math.h"
#include "micro-test-plus/type-traits.h"
#include "micro-test-plus/literals.h"
#include "micro-test-plus/test-suite.h"
#include "micro-test-plus/test-runner.h"
#include "micro-test-plus/test-reporter.h"
#include "micro-test-plus/detail.h"

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
   * @details
   * The `initialize` function sets up the µTest++ testing framework, preparing
   * it for test execution. It processes command-line arguments, configures the
   * test environment, and establishes the default test suite name. This
   * function should be called at the beginning of the test program, typically
   * from the `main()` function, to ensure proper initialisation of all
   * framework components.
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
   * @details
   * The `exit_code` function finalises the execution of all registered test
   * suites and test cases within the µTest++ framework, and returns an
   * appropriate exit code to the operating system. This function should be
   * called at the end of the test program, typically from the `main()`
   * function, to ensure that all results are properly reported and the correct
   * status is communicated.
   *
   * The returned value indicates the overall success or failure of the test
   * run, allowing integration with build systems and continuous integration
   * environments.
   *
   * @return 0 if all tests were successful, 1 if any test failed.
   */
  [[nodiscard]] int
  exit_code (void);

  /**
   * @ingroup micro-test-plus-test-case
   * @brief Define and execute a test case.
   *
   * @details
   * The `test_case` function template registers and executes a test case
   * within the µTest++ framework. It accepts a descriptive name, a callable
   * object (such as a lambda or function pointer), and an optional list of
   * arguments to be passed to the callable. The test case is reported using
   * the provided name, and its execution is managed by the framework's test
   * runner.
   *
   * This function template enables flexible and expressive test case
   * definitions, supporting both parameterised and non-parameterised tests. It
   * is typically invoked at global scope or within test suite definitions to
   * ensure automatic registration and execution.
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
   * @details
   * The `expect` function template evaluates a logical condition or custom
   * expression and reports the result within the µTest++ framework. It is
   * designed to provide detailed diagnostics for test failures, including the
   * actual and expected values, when using the provided comparators (`eq()`,
   * `ne()`, `lt()`, `le()`, `gt()`, `ge()`) or custom operators.
   *
   * The function template can be used with any expression that evaluates to a
   * boolean or with custom comparators/operators derived from the local
   * `detail::op` type. For complex checks performed outside the `expect()`
   * logical expression (such as within `if` or `try`/`catch` statements), the
   * result can be reported by calling `expect(true)` or `expect(false)`.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report.
   *
   * @tparam Expr_T The type of the custom expression.
   * @tparam (SFINAE) Enabled only if `Expr_T` is derived from `detail::op` or
   * is convertible to `bool`.
   * @param [in] expr Logical expression to evaluate.
   * @param [in] sl Optional source location, defaulting to the current line.
   * @return An output stream to write optional messages.
   *
   * @par Example
   *
   * @code{.cpp}
   * namespace mt = micro_os_plus::micro_test_plus;
   * mt::expect(compute_answer() == 42) << "answer is 42";
   * @endcode
   */
  template <class Expr_T, type_traits::requires_t<
                              type_traits::is_op_v<Expr_T>
                              or type_traits::is_convertible_v<Expr_T, bool>>
                          = 0>
  constexpr auto
  expect (const Expr_T& expr, const reflection::source_location& sl
                              = reflection::source_location::current ())
  {
    return detail::deferred_reporter<Expr_T>{ expr, false, sl };
  }

  /**
   * @ingroup micro-test-plus-assumptions
   * @brief Check a condition and, if false, abort test execution.
   *
   * @details
   * The `assume` function template evaluates a logical condition or custom
   * expression and, if the condition is false, aborts the current test case
   * within the µTest++ framework. This mechanism is intended for preconditions
   * or assumptions that must hold for the test to be meaningful. If the
   * assumption fails, the test case is terminated early and reported as
   * skipped or failed, depending on the framework configuration.
   *
   * The function template can be used with any expression that evaluates to a
   * boolean or with custom comparators/operators derived from the local
   * `detail::op` type. It returns an output stream, allowing optional messages
   * to be appended to the test report for diagnostic purposes.
   *
   * @tparam Expr_T The type of the custom expression.
   * @tparam (SFINAE) Enabled only if `Expr_T` is derived from `detail::op` or
   * is convertible to `bool`.
   * @param [in] expr Logical expression to evaluate.
   * @param [in] sl Optional source location, defaulting to the current line.
   * @return An output stream to write optional messages.
   *
   * @par Example
   *
   * @code{.cpp}
   * namespace mt = micro_os_plus::micro_test_plus;
   * mt::assume(compute_answer() == 42) << "answer is 42";
   * @endcode
   */
  template <class Expr_T, type_traits::requires_t<
                              type_traits::is_op_v<Expr_T>
                              or type_traits::is_convertible_v<Expr_T, bool>>
                          = 0>
  constexpr auto
  assume (const Expr_T& expr, const reflection::source_location& sl
                              = reflection::source_location::current ())
  {
    return detail::deferred_reporter<Expr_T>{ expr, true, sl };
  }

  // --------------------------------------------------------------------------

#if defined(__cpp_exceptions)

  /**
   * @ingroup micro-test-plus-exceptions
   * @brief Check if a callable throws a specific exception.
   *
   * @details
   * The `throws` function template verifies whether invoking the provided
   * callable object results in the throwing of a specific exception type
   * within the µTest++ framework. This is useful for testing error handling
   * and exception safety in code under test.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report for diagnostic purposes.
   *
   * @tparam Exception_T The type of the exception expected to be thrown.
   * @tparam Callable_T The type of the callable object to be invoked.
   * @param [in] func The callable object to check for exception throwing
   * behaviour.
   * @return An output stream to write optional messages.
   */
  template <class Exception_T, class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func)
  {
    return detail::throws_<Callable_T, Exception_T>{ func };
  }

  /**
   * @ingroup micro-test-plus-exceptions
   * @brief Check if a callable throws an exception (any exception).
   *
   * @details
   * The `throws` function template verifies whether invoking the provided
   * callable object results in the throwing of any exception within the
   * µTest++ framework. This is useful for testing general exception safety and
   * ensuring that code under test properly signals error conditions.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report for diagnostic purposes.
   *
   * @tparam Callable_T The type of the callable object to be invoked.
   * @param [in] func The callable object to check for exception throwing
   * behaviour.
   * @return An output stream to write optional messages.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  throws (const Callable_T& func)
  {
    return detail::throws_<Callable_T>{ func };
  }

  /**
   * @ingroup micro-test-plus-exceptions
   * @brief Check if a callable does not throw an exception.
   *
   * @details
   * The `nothrow` function template verifies whether invoking the provided
   * callable object does not result in the throwing of any exception within
   * the µTest++ framework. This is useful for testing exception safety and
   * ensuring that code under test does not unexpectedly signal error
   * conditions.
   *
   * The function returns an output stream, allowing optional messages to be
   * appended to the test report for diagnostic purposes.
   *
   * @tparam Callable_T The type of the callable object to be invoked.
   * @param [in] func The callable object to check for exception safety.
   * @return An output stream to write optional messages.
   */
  template <class Callable_T>
  [[nodiscard]] constexpr auto
  nothrow (const Callable_T& func)
  {
    return detail::nothrow_{ func };
  }

#endif

  // --------------------------------------------------------------------------

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic equality comparator for non-pointer types.
   *
   * @details
   * The `eq` function template provides a generic equality comparator for any
   * non-pointer types. It constructs a comparator object that can be used
   * within the µTest++ framework to assert that two values are equal. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return A comparator object that evaluates to true if the operands are
   * equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Pointer equality comparator for any pointer types.
   *
   * @details
   * The `eq` function template provides a pointer equality comparator for any
   * pointer types. It constructs a comparator object that can be used within
   * the µTest++ framework to assert that two pointers are equal. This function
   * is typically used in test expectations and assertions to compare the
   * addresses of objects or resources.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   * @param [in] lhs Left hand side pointer operand.
   * @param [in] rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the pointers are
   * equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  eq (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::eq_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic non-equality comparator.
   *
   * @details
   * The `ne` function template provides a generic non-equality comparator for
   * any types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that two values are not equal. This function
   * is typically used in test expectations and assertions to compare the
   * actual and expected values.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return A comparator object that evaluates to true if the operands are not
   * equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ne_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Pointer non-equality comparator.
   *
   * @details
   * The `ne` function template provides a pointer non-equality comparator for
   * any pointer types. It constructs a comparator object that can be used
   * within the µTest++ framework to assert that two pointers are not equal.
   * This function is typically used in test expectations and assertions to
   * compare the addresses of objects or resources.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   * @param [in] lhs Left hand side pointer operand.
   * @param [in] rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the pointers are not
   * equal.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ne (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ne_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic greater than comparator.
   *
   * @details
   * The `gt` function template provides a generic greater than comparator for
   * any types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that one value is greater than another. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return A comparator object that evaluates to true if `lhs` is greater
   * than `rhs`.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::gt_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Pointer greater than comparator.
   *
   * @details
   * The `gt` function template provides a pointer greater than comparator for
   * any pointer types. It constructs a comparator object that can be used
   * within the µTest++ framework to assert that one pointer is greater than
   * another. This function is typically used in test expectations and
   * assertions to compare the addresses of objects or resources.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   * @param [in] lhs Left hand side pointer operand.
   * @param [in] rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the left hand side
   * pointer is greater than the right hand side pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  gt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::gt_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic greater than or equal comparator.
   *
   * @details
   * The `ge` function template provides a generic greater than or equal
   * comparator for any types. It constructs a comparator object that can be
   * used within the µTest++ framework to assert that one value is greater than
   * or equal to another. This function is typically used in test expectations
   * and assertions to compare the actual and expected values.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return A comparator object that evaluates to true if `lhs` is greater
   * than or equal to `rhs`.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::ge_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Pointer greater than or equal comparator.
   *
   * @details
   * The `ge` function template provides a pointer greater than or equal
   * comparator for any pointer types. It constructs a comparator object that
   * can be used within the µTest++ framework to assert that one pointer is
   * greater than or equal to another. This function is typically used in test
   * expectations and assertions to compare the addresses of objects or
   * resources.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   * @param [in] lhs Left hand side pointer operand.
   * @param [in] rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the left hand side
   * pointer is greater than or equal to the right hand side pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  ge (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::ge_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic less than comparator.
   *
   * @details
   * The `lt` function template provides a generic less than comparator for any
   * types. It constructs a comparator object that can be used within the
   * µTest++ framework to assert that one value is less than another. This
   * function is typically used in test expectations and assertions to compare
   * the actual and expected values.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return A comparator object that evaluates to true if `lhs` is less than
   * `rhs`.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::lt_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Pointer less than comparator.
   *
   * @details
   * The `lt` function template provides a pointer less than comparator for any
   * pointer types. It constructs a comparator object that can be used within
   * the µTest++ framework to assert that one pointer is less than another.
   * This function is typically used in test expectations and assertions to
   * compare the addresses of objects or resources.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   * @param [in] lhs Left hand side pointer operand.
   * @param [in] rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the left hand side
   * pointer is less than the right hand side pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  lt (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::lt_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Generic less than or equal comparator.
   *
   * @details
   * The `le` function template provides a generic less than or equal
   * comparator for any types. It constructs a comparator object that can be
   * used within the µTest++ framework to assert that one value is less than or
   * equal to another. This function is typically used in test expectations and
   * assertions to compare the actual and expected values.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return A comparator object that evaluates to true if `lhs` is less than
   * or equal to `rhs`.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::le_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-function-comparators
   * @brief Pointer less than or equal comparator.
   *
   * @details
   * The `le` function template provides a pointer less than or equal
   * comparator for any pointer types. It constructs a comparator object that
   * can be used within the µTest++ framework to assert that one pointer is
   * less than or equal to another. This function is typically used in test
   * expectations and assertions to compare the addresses of objects or
   * resources.
   *
   * @tparam Lhs_T Type of the left hand side pointer operand.
   * @tparam Rhs_T Type of the right hand side pointer operand.
   * @param [in] lhs Left hand side pointer operand.
   * @param [in] rhs Right hand side pointer operand.
   * @return A comparator object that evaluates to true if the left hand side
   * pointer is less than or equal to the right hand side pointer.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  le (Lhs_T* lhs, Rhs_T* rhs)
  {
    return detail::le_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-logical-functions
   * @brief Generic logical **not** operation.
   *
   * @details
   * The `_not` function template provides a generic logical negation for any
   * expression type. It constructs a logical negator object that can be used
   * within the µTest++ framework to assert that a given condition is false.
   * This function is typically used in test expectations and assertions to
   * invert logical expressions or custom comparators.
   *
   * The underscore in the function name is intentional to differentiate it
   * from the standard logical not operator.
   *
   * @tparam Expr_T Type of the operand.
   * @param [in] expr Logical expression to be negated.
   * @return An object that evaluates to true if the operand is false.
   */
  template <class Expr_T>
  [[nodiscard]] constexpr auto
  _not (const Expr_T& expr)
  {
    return detail::not_{ expr };
  }

  /**
   * @ingroup micro-test-plus-logical-functions
   * @brief Generic logical **and** operation.
   *
   * @details
   * The `_and` function template provides a generic logical conjunction for
   * any expression types. It constructs a logical conjunction object that can
   * be used within the µTest++ framework to assert that both given conditions
   * are true. This function is typically used in test expectations and
   * assertions to combine logical expressions or custom comparators.
   *
   * The underscore in the function name is intentional to differentiate it
   * from the standard logical and operator.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return An object that evaluates to true if both operand expressions are
   * true.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _and (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::and_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-logical-functions
   * @brief Generic logical **or** operation.
   *
   * @details
   * The `_or` function template provides a generic logical disjunction for any
   * expression types. It constructs a logical disjunction object that can be
   * used within the µTest++ framework to assert that at least one of the given
   * conditions is true. This function is typically used in test expectations
   * and assertions to combine logical expressions or custom comparators.
   *
   * The underscore in the function name is intentional to differentiate it
   * from the standard logical or operator.
   *
   * @tparam Lhs_T Type of the left hand side operand.
   * @tparam Rhs_T Type of the right hand side operand.
   * @param [in] lhs Left hand side operand.
   * @param [in] rhs Right hand side operand.
   * @return An object that evaluates to true if at least one of the operand
   * expressions is true.
   */
  template <class Lhs_T, class Rhs_T>
  [[nodiscard]] constexpr auto
  _or (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return detail::or_{ lhs, rhs };
  }

  /**
   * @ingroup micro-test-plus-utility-functions
   * @brief Generic mutator to remove const qualification from any type.
   *
   * @details
   * The `mut` function template provides a safe and generic mechanism to
   * remove the `const` qualifier from any type. It returns a non-const
   * reference to the input object, enabling modification of objects that were
   * originally declared as `const`. This utility is particularly useful in
   * testing scenarios where controlled mutation of test data is required.
   *
   * @tparam T The type of the input object.
   * @param [in] t The object from which to remove const qualification.
   * @return A non-const reference to the input object.
   */
  template <class T>
  [[nodiscard]] constexpr auto
  mut (const T& t) noexcept -> T&
  {
    return const_cast<T&> (t);
  }

  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::operators
   * @brief Custom operator overloads for expressive and type-safe test
   * assertions.
   *
   * @details
   * The `micro_os_plus::micro_test_plus::operators` namespace provides a
   * comprehensive set of custom operator overloads designed to enable
   * expressive, concise, and type-safe test assertions within the µTest++
   * framework.
   *
   * This namespace includes equality, inequality, relational, and logical
   * operators tailored for use with the framework’s custom types, containers,
   * and string views. These operators facilitate the creation of clear and
   * readable test expressions, supporting both strongly-typed constants (via
   * user-defined literals) and dynamic values (via wrappers).
   *
   * @warning Please be aware that these operators
   * may conflict with other operators defined within the application under
   * test.
   *
   * To minimise conflicts with application-defined operators, these overloads
   * are enabled only for specific types recognised by the framework, such as
   * those derived from the local `op` base type or identified as containers or
   * string views. Constants typically require a literal suffix (e.g., `1_i`),
   * while dynamic values should be wrapped using the provided casting
   * utilities (e.g., `mt::to_i{...}`).
   *
   * All definitions within this namespace are implemented in the
   * `include/micro-os-plus/micro-test-plus` folder, ensuring a modular and
   * maintainable codebase.
   */
  namespace operators
  {
    /**
     * @ingroup micro-test-plus-string-operators
     * @brief Equality operator for `string_view` objects.
     *
     * @details
     * This overload of the equality operator enables direct comparison of two
     * `std::string_view` objects within the µTest++ framework. It constructs a
     * comparator object that can be used in test expectations and assertions
     * to verify that two string views are equal.
     *
     * @param [in] lhs The left hand side `std::string_view` operand.
     * @param [in] rhs The right hand side `std::string_view` operand.
     * @return A comparator object that evaluates to true if the string views
     * are equal.
     */
    [[nodiscard]] constexpr auto
    operator== (std::string_view lhs, std::string_view rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-string-operators
     * @brief Non-equality operator for `string_view` objects.
     *
     * @details
     * This overload of the non-equality operator enables direct comparison of
     * two `std::string_view` objects within the µTest++ framework. It
     * constructs a comparator object that can be used in test expectations and
     * assertions to verify that two string views are not equal.
     *
     * @param [in] lhs The left hand side `std::string_view` operand.
     * @param [in] rhs The right hand side `std::string_view` operand.
     * @return A comparator object that evaluates to true if the string views
     * are not equal.
     */
    [[nodiscard]] constexpr auto
    operator!= (std::string_view lhs, std::string_view rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-container-operators
     * @brief Equality operator for containers.
     *
     * @details
     * This overload of the equality operator enables direct comparison of two
     * container objects within the µTest++ framework. It constructs a
     * comparator object that can be used in test expectations and assertions
     * to verify that two containers are equal in content and order.
     *
     * The operator is enabled only for types recognised as containers by the
     * framework's type traits.
     *
     * @tparam T The container type, constrained to recognised container types.
     * @param [in] lhs The left hand side container operand.
     * @param [in] rhs The right hand side container operand.
     * @return A comparator object that evaluates to true if the containers are
     * equal.
     */
    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator== (T&& lhs, T&& rhs)
    {
      return detail::eq_{ static_cast<T&&> (lhs), static_cast<T&&> (rhs) };
    }

    /**
     * @ingroup micro-test-plus-container-operators
     * @brief Non-equality operator for containers.
     *
     * @details
     * This overload of the non-equality operator enables direct comparison of
     * two container objects within the µTest++ framework. It constructs a
     * comparator object that can be used in test expectations and assertions
     * to verify that two containers are not equal in content or order.
     *
     * The operator is enabled only for types recognised as containers by the
     * framework's type traits.
     *
     * @tparam T The container type, constrained to recognised container types.
     * @param [in] lhs The left hand side container operand.
     * @param [in] rhs The right hand side container operand.
     * @return A comparator object that evaluates to true if the containers are
     * not equal.
     */
    template <class T,
              type_traits::requires_t<type_traits::is_container_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator!= (T&& lhs, T&& rhs)
    {
      return detail::ne_{ static_cast<T&&> (lhs), static_cast<T&&> (rhs) };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Equality operator for custom types. Matches only if at least one
     * operand is of local type.
     *
     * @details
     * This overload of the equality operator enables comparison between two
     * operands, where at least one is a local type derived from the local `op`
     * base. It constructs a comparator object that can be used within the
     * µTest++ framework to assert that the operands are equal. This operator
     * is intended for use with the framework's strongly-typed constants,
     * wrappers, or other custom types, ensuring type-safe and expressive test
     * assertions.
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the operands are
     * equal.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator== (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::eq_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Non-equality operator for custom types. Matches only if at least
     * one operand is of local type.
     *
     * @details
     * This overload of the non-equality operator enables comparison between
     * two operands, where at least one is a local type derived from the local
     * `op` base. It constructs a comparator object that can be used within the
     * µTest++ framework to assert that the operands are not equal. This
     * operator is intended for use with the framework's strongly-typed
     * constants, wrappers, or other custom types, ensuring type-safe and
     * expressive test assertions.
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the operands are
     * not equal.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator!= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ne_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Greater than operator. Matches only if at least one operand is of
     * local type (derived from local `op`).
     *
     * @details
     * This overload of the greater than operator enables comparison between
     * two operands, where at least one is a local type derived from the local
     * `op` base. It constructs a comparator object that can be used within the
     * µTest++ framework to assert that the left hand side operand is greater
     * than the right hand side operand. This operator is intended for use with
     * the framework's strongly-typed constants, wrappers, or other custom
     * types, ensuring type-safe and expressive test assertions.
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is greater than the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator> (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::gt_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Greater than or equal operator. Matches only if at least one
     * operand is of local type (derived from local `op`).
     *
     * @details
     * This overload of the greater than or equal operator enables comparison
     * between two operands, where at least one is a local type derived from
     * the local `op` base. It constructs a comparator object that can be used
     * within the µTest++ framework to assert that the left hand side operand
     * is greater than or equal to the right hand side operand. This operator
     * is intended for use with the framework's strongly-typed constants,
     * wrappers, or other custom types, ensuring type-safe and expressive test
     * assertions.
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is greater than or equal to the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator>= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::ge_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Less than operator. Matches only if at least one operand is of
     * local type (derived from local `op`).
     *
     * @details
     * This overload of the less than operator enables comparison between two
     * operands, where at least one is a local type derived from the local `op`
     * base. It constructs a comparator object that can be used within the
     * µTest++ framework to assert that the left hand side operand is less than
     * the right hand side operand. This operator is intended for use with the
     * framework's strongly-typed constants, wrappers, or other custom types,
     * ensuring type-safe and expressive test assertions.
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is less than the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator< (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::lt_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Less than or equal operator. Matches only if at least one operand
     * is of local type (derived from local `op`).
     *
     * @details
     * This overload of the less than or equal operator enables comparison
     * between two operands, where at least one is a local type derived from
     * the local `op` base. It constructs a comparator object that can be used
     * within the µTest++ framework to assert that the left hand side operand
     * is less than or equal to the right hand side operand. This operator is
     * intended for use with the framework's strongly-typed constants,
     * wrappers, or other custom types, ensuring type-safe and expressive test
     * assertions.
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A comparator object that evaluates to true if the left hand side
     * operand is less than or equal to the right hand side operand.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator<= (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::le_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Logical `&&` (and) operator. Matches only if at least one operand
     * is of local type (derived from local `op`).
     *
     * @details
     * This overload of the logical `&&` (and) operator enables conjunction
     * between two operands, where at least one is a local type derived from
     * the local `op` base. It constructs a logical conjunction object that can
     * be used within the µTest++ framework to assert that both operands
     * evaluate to true. This operator is intended for use with the framework's
     * strongly-typed constants, wrappers, or other custom types, ensuring
     * type-safe and expressive test assertions.
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A logical conjunction object that evaluates to true if both
     * operands are true.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator and (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::and_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Logical `||` (or) operator. Matches only if at least one operand
     * is of local type (derived from local `op`).
     *
     * @details
     * This overload of the logical `||` (or) operator enables disjunction
     * between two operands, where at least one is a local type derived from
     * the local `op` base. It constructs a logical disjunction object that can
     * be used within the µTest++ framework to assert that at least one operand
     * evaluates to true. This operator is intended for use with the
     * framework's strongly-typed constants, wrappers, or other custom types,
     * ensuring type-safe and expressive test assertions.
     *
     * @tparam Lhs_T Type of the left hand side operand.
     * @tparam Rhs_T Type of the right hand side operand.
     * @param [in] lhs Left hand side operand.
     * @param [in] rhs Right hand side operand.
     * @return A logical disjunction object that evaluates to true if at least
     * one operand is true.
     */
    template <class Lhs_T, class Rhs_T,
              type_traits::requires_t<type_traits::is_op_v<Lhs_T>
                                      or type_traits::is_op_v<Rhs_T>>
              = 0>
    [[nodiscard]] constexpr auto
    operator or (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return detail::or_{ lhs, rhs };
    }

    /**
     * @ingroup micro-test-plus-operators
     * @brief Logical `!` (not) operator. Matches only if the operand is of
     * local type (derived from local `op`).
     *
     * @details
     * This overload of the logical `!` (not) operator enables logical negation
     * of an operand, provided it is a local type derived from the local `op`
     * base. It constructs a logical negator object that can be used within the
     * µTest++ framework to assert that a given condition is false. This
     * operator is intended for use with the framework's strongly-typed
     * constants, wrappers, or other custom types, ensuring type-safe and
     * expressive test assertions.
     *
     * @tparam T Type of the operand, constrained to types derived from the
     * local `op` base.
     * @param [in] t Operand to be logically negated.
     * @return A logical negator object that evaluates to true if the operand
     * is false.
     */
    template <class T, type_traits::requires_t<type_traits::is_op_v<T>> = 0>
    [[nodiscard]] constexpr auto
    operator not(const T& t)
    {
      return detail::not_{ t };
    }
  } // namespace operators

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
     * @details
     * The `is_match` function determines whether the specified input string
     * matches the given pattern. This utility is particularly useful for
     * validating string content against wildcard or template patterns within
     * test cases in the µTest++ framework.
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
     * @details
     * The `split` function template divides the input string into a vector of
     * sub-strings, using the specified delimiter. This utility is particularly
     * useful for parsing and processing delimited data within test cases in
     * the µTest++ framework.
     *
     * @tparam T Type of the input string.
     * @tparam Delim_T Type of the delimiter.
     * @param [in] input Input string to split.
     * @param [in] delim Delimiter string.
     * @return A vector containing the resulting sub-strings.
     */
    template <class T, class Delim_T>
    [[nodiscard]] auto
    split (T input, Delim_T delim) -> std::vector<T>;

  } // namespace utility

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ===== Inline & template implementations ====================================

#include "micro-test-plus/test-reporter-inlines.h"

// All other inlines.
#include "micro-test-plus/inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

// ----------------------------------------------------------------------------

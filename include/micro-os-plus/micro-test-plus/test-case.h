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
 * @brief C++ header file with declarations for the µTest++ test case.
 *
 */

#ifndef MICRO_TEST_PLUS_TEST_CASE_H_
#define MICRO_TEST_PLUS_TEST_CASE_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include "test-runner-totals.h"
#include "deferred-reporter.h"

#include <functional>
#include <vector>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#if !defined(__clang__) // GCC only
#pragma GCC diagnostic ignored "-Wsuggest-final-types"
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#endif
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

namespace micro_os_plus::micro_test_plus2
{
  class test_suite_base;
  class test_reporter;
  class test_runner_totals;

  // --------------------------------------------------------------------------

  /**
   * @brief Base class for all test cases.
   *
   * @details
   * The `test_case_base` class provides the foundational interface for
   * managing test cases within the µTest++ framework. It maintains counters
   * for successful and failed checks, tracks test cases, and offers methods
   * for marking the commencement and completion of test cases and suites.
   *
   * This class ensures consistent state management and reporting for all
   * derived test cases. It also provides utility methods for querying the
   * case's name, the number of successful and failed checks, the number of
   * test cases, and the overall result of the case.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus2` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class test_case_base
  {
  public:
    /**
     * @brief Constructs a test case.
     *
     * @param [in] name The test case name.
     *
     * @details
     * The rule of five is enforced to prevent accidental copying or moving.
     */
    test_case_base (const char* name, test_suite_base& test_suite,
                    size_t own_index, size_t nesting_depth = 1);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    test_case_base (const test_case_base&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    test_case_base (test_case_base&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    test_case_base&
    operator= (const test_case_base&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_case_base&
    operator= (test_case_base&&) = delete;

    /**
     * @brief Virtual destructor for the test_case_base class.
     */
    virtual ~test_case_base ();

    // ------------------------------------------------------------------------

    /**
     * @brief Creates and runs a named child test case.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param [in] name The child test case name or description.
     * @param [in] callable A generic callable object, usually a lambda,
     * invoked to perform the test.
     * @param [in] arguments A possibly empty list of arguments to be passed
     * to the callable.
     * @par Returns
     *  Nothing.
     */
    template <typename Callable_T, typename... Args_T>
    void
    test_case (const char* name, Callable_T&& callable, Args_T&&... arguments);

    // ------------------------------------------------------------------------

    /**
     * @ingroup micro-test-plus-expectations
     * @brief Evaluate a generic condition and report the results.
     *
     * @tparam Expr_T The type of the custom expression.
     *
     * @par SFINAE
     * Enabled only if `Expr_T` is derived from `detail::op` or
     * is convertible to `bool`.
     *
     * @param [in] expr Logical expression to evaluate.
     * @param [in] sl Optional source location, defaulting to the current line.
     * @return An output stream to write optional messages.
     *
     * @details
     * The `expect` function template evaluates a logical condition or custom
     * expression and reports the result within the µTest++ framework. It is
     * designed to provide detailed diagnostics for test failures, including
     * the actual and expected values, when using the provided comparators
     * (`eq()`, `ne()`, `lt()`, `le()`, `gt()`, `ge()`) or custom operators.
     *
     * The function template can be used with any expression that evaluates to
     * a boolean or with custom comparators/operators derived from the local
     * `detail::op` type. For complex checks performed outside the `expect()`
     * logical expression (such as within `if` or `try`/`catch` statements),
     * the result can be reported by calling `expect(true)` or `expect(false)`.
     *
     * The function returns an output stream, allowing optional messages to be
     * appended to the test report.
     *
     * **Example**
     *
     * @code{.cpp}
     * namespace mt = micro_os_plus::micro_test_plus2;
     * mt::expect(compute_answer() == 42) << "answer is 42";
     * @endcode
     */
    template <class Expr_T,
              type_traits::requires_t<
                  type_traits::is_op_v<Expr_T>
                  or type_traits::is_convertible_v<Expr_T, bool>> = 0>
    constexpr auto
    expect (const Expr_T& expr, const reflection::source_location& sl
                                = reflection::source_location::current ())
    {
      return detail::deferred_reporter<Expr_T>{ expr, false, sl, *this };
    }

    /**
     * @ingroup micro-test-plus-assumptions
     * @brief Check a condition and, if false, abort test execution.
     *
     * @tparam Expr_T The type of the custom expression.
     *
     * @par SFINAE
     * Enabled only if `Expr_T` is derived from `detail::op` or
     * is convertible to `bool`.
     *
     * @param [in] expr Logical expression to evaluate.
     * @param [in] sl Optional source location, defaulting to the current line.
     * @return An output stream to write optional messages.
     *
     * @details
     * The `assume` function template evaluates a logical condition or custom
     * expression and reports the result within the µTest++ framework. It is
     * designed to provide detailed diagnostics for test failures, including
     * the actual and expected values, when using the provided comparators
     * (`eq()`, `ne()`, `lt()`, `le()`, `gt()`, `ge()`) or custom operators.
     *
     * The function template can be used with any expression that evaluates to
     * a boolean or with custom comparators/operators derived from the local
     * `detail::op` type. For complex checks performed outside the `expect()`
     * logical expression (such as within `if` or `try`/`catch` statements),
     * the result can be reported by calling `expect(true)` or `expect(false)`.
     *
     * The function returns an output stream, allowing optional messages to be
     * appended to the test report.
     *
     * **Example**
     *
     * @code{.cpp}
     * namespace mt = micro_os_plus::micro_test_plus2;
     * mt::assume(compute_answer() == 42) << "answer is 42";
     * @endcode
     */
    template <class Expr_T,
              type_traits::requires_t<
                  type_traits::is_op_v<Expr_T>
                  or type_traits::is_convertible_v<Expr_T, bool>> = 0>
    constexpr auto
    assume (const Expr_T& expr, const reflection::source_location& sl
                                = reflection::source_location::current ())
    {
      return detail::deferred_reporter<Expr_T>{ expr, true, sl, *this };
    }

    // ------------------------------------------------------------------------

    /**
     * @brief Executes the test case.
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     *
     * @details
     * The `run` method is a pure virtual function that must be implemented by
     * derived test case classes. It is responsible for executing the test case
     * logic, including any assertions and child test cases.
     */
    virtual void
    run (void) = 0;

    /**
     * @brief Gets the suite name.
     *
     * @par Parameters
     *	None.
     * @return A pointer to the null-terminated test suite name.
     */
    [[nodiscard]] constexpr const char*
    name (void) const
    {
      return name_;
    }

    [[nodiscard]] constexpr test_suite_base&
    test_suite ()
    {
      return test_suite_;
    }

    [[nodiscard]] test_reporter&
    reporter ();

    [[nodiscard]] constexpr size_t
    nesting_depth ()
    {
      return nesting_depth_;
    }

    [[nodiscard]] constexpr size_t
    own_index ()
    {
      return own_index_;
    }

    [[nodiscard]] constexpr size_t
    current_child_index ()
    {
      return child_index_;
    }

    constexpr size_t
    increment_child_index ()
    {
      return ++child_index_;
    }

    [[nodiscard]] constexpr size_t
    test_cases_count (void) const
    {
      return test_cases_.size ();
    }

  public:
    /**
     * @brief Totals for the test case, including nested cases.
     */
    test_runner_totals totals;

  protected:
    /**
     * @brief The test case name.
     */
    const char* name_;

    /**
     * @brief The test case's own index within the suite, counting from 1.
     */
    size_t own_index_;

    /**
     * @brief The child index, counting from 1.
     *
     * @details
     * This index is used for reporting and tracking the execution order of
     * test cases within a suite, especially when nested test cases are
     * involved. It is incremented for each test case created, allowing for
     * clear identification of test cases in reports and diagnostics.
     */
    size_t child_index_ = 0;

    /**
     * @brief Reference to the parent test suite, allowing access to
     * suite-level information and operations.
     */
    test_suite_base& test_suite_;

    /**
     * @brief The nesting depth of the test case within the suite.
     */
    size_t nesting_depth_;

    std::vector<test_case_base*> test_cases_;
  };

  /**
   * @ingroup micro-test-plus-test-cases
   * @brief Represents a named group of test checks.
   *
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class test_case_callable : public test_case_base
  {
  public:
    /**
     * @brief Class template constructor for test_case_callable.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param [in] name The test case name or description, used in reports.
     * @param [in] callable A generic callable object, usually a lambda,
     * invoked to perform the test.
     * @param [in] arguments A possibly empty list of arguments to be passed to
     * the callable.
     *
     * @details
     * The rule of five is enforced to prevent accidental copying or moving.
     */
    template <typename Callable_T, typename... Args_T>
    test_case_callable (const char* name, test_suite_base& test_suite,
                        size_t own_index, size_t nesting_depth,
                        Callable_T&& callable, Args_T&&... arguments);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    test_case_callable (const test_case_callable&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    test_case_callable (test_case_callable&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    test_case_callable&
    operator= (const test_case_callable&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_case_callable&
    operator= (test_case_callable&&) = delete;

    /**
     * @brief Virtual destructor for the test_case_callable class.
     */
    virtual ~test_case_callable () override;

    /**
     * @brief Creates and runs a named nested test case.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param [in] name The nested test case name or description.
     * @param [in] callable A generic callable object, usually a lambda,
     * invoked to perform the test.
     * @param [in] arguments A possibly empty list of arguments to be passed
     * to the callable.
     * @par Returns
     *  Nothing.
     */
    template <typename Callable_T, typename... Args_T>
    void
    test_case (const char* name, Callable_T&& callable, Args_T&&... arguments)
    {
      test_case_base::test_case (name, std::forward<Callable_T> (callable),
                                 std::forward<Args_T> (arguments)...);
    }

    /**
     * @brief Runs the sequence of test cases in the suite by invoking the
     * stored callable.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    virtual void
    run (void) override;

  protected:
    /**
     * @brief Callable object representing the test case's execution logic.
     */
    std::function<void (test_case_callable&)> callable_;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus2

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_SUITE_H_

// ----------------------------------------------------------------------------

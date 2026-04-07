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
 * @brief C++ header file with declarations for the µTest++ test suite.
 *
 * @details
 * This header provides the declarations for the test suite facilities used
 * within the µTest++ framework. It defines the interfaces for constructing,
 * registering, and managing test suites and their associated test cases. The
 * core classes, `test_node` and `suite`, offer mechanisms for
 * tracking test case execution, managing counters for successful and failed
 * checks, and supporting automated registration and discovery of test suites.
 *
 * The design ensures that test suites are non-copyable and non-movable,
 * maintaining unique ownership and consistent state. Flexible support for
 * callable objects enables a wide range of test suite definitions,
 * facilitating expressive and maintainable test organisation across embedded
 * and general C++ projects.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_TEST_H_
#define MICRO_TEST_PLUS_TEST_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include "runner-totals.h"
#include "timings.h"

#include <functional>
#include <memory>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#else // GCC only
#pragma GCC diagnostic ignored "-Wsuggest-final-types"
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#pragma GCC diagnostic ignored "-Wredundant-tags"
#endif
#endif

// =============================================================================

namespace micro_os_plus::micro_test_plus
{
  class runner;
  class static_runner;
  class reporter;
  class runner_totals;
  class suite;

  // --------------------------------------------------------------------------

  /**
   * @brief Base class for all test suites.
   *
   * @details
   * The `test_node` class provides the foundational interface for
   * managing test suites within the µTest++ framework. It maintains counters
   * for successful and failed checks, tracks test cases, and offers methods
   * for marking the commencement and completion of test cases and suites.
   *
   * This class ensures consistent state management and reporting for all
   * derived test suites. It also provides utility methods for querying the
   * suite's name, the number of successful and failed checks, the number of
   * test cases, and the overall result of the suite.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class test_node
  {
  public:
    /**
     * @brief Constructs a test suite.
     *
     * @param [in] name The test suite name.
     *
     * @details
     * The rule of five is enforced to prevent accidental copying or moving.
     */
    test_node (const char* name);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    test_node (const test_node&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    test_node (test_node&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    test_node&
    operator= (const test_node&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_node&
    operator= (test_node&&) = delete;

    /**
     * @brief Virtual destructor for the test_node class.
     */
    virtual ~test_node ();

    // ------------------------------------------------------------------------

    /**
     * @brief Gets the suite name.
     *
     * @par Parameters
     *	None.
     * @return A pointer to the null-terminated test suite name.
     */
    [[nodiscard]] const char*
    name (void) const
    {
      return name_;
    }

  public:
    /**
     * @brief Totals for the test suite, including nested cases.
     */
    runner_totals totals;

    timestamps timings;

  protected:
    /**
     * @brief The test suite name.
     */
    const char* name_;
  };

  // ==========================================================================

  class runnable_base : public test_node
  {
  public:
    runnable_base (const char* name, runner& runner, size_t own_index);

    runnable_base (const runnable_base&) = delete;
    runnable_base (runnable_base&&) = delete;
    runnable_base&
    operator= (const runnable_base&) = delete;
    runnable_base&
    operator= (runnable_base&&) = delete;

    virtual ~runnable_base () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Gets the test runner associated with this test suite.
     *
     * @par Parameters
     *	None.
     * @return A reference to the test runner.
     */
    [[nodiscard]] class runner&
    runner (void)
    {
      return runner_;
    }

    /**
     * @brief Gets the test reporter associated with this test suite.
     *
     * @par Parameters
     *	None.
     * @return A reference to the test reporter.
     */
    [[nodiscard]] class reporter&
    reporter (void);

    [[nodiscard]] size_t
    own_index ()
    {
      return own_index_;
    }

    [[nodiscard]] size_t
    current_subtest_index ()
    {
      return current_subtest_index_;
    }

    size_t
    increment_subtest_index ()
    {
      return ++current_subtest_index_;
    }

    [[nodiscard]] size_t
    children_subtests_count (void) const
    {
      return children_subtests_.size ();
    }

    void
    after_subtest_create (std::unique_ptr<class subtest> child_test,
                          suite& suite);

  protected:
    /**
     * @brief Reference to the test runner.
     */
    class runner& runner_;

    /**
     * @brief The test suite index, counting from 1.
     */
    size_t own_index_;

    /**
     * @brief The subtest index, counting from 1.
     *
     * @details
     * This index is used for reporting and tracking the execution order of
     * subtests within a suite, especially when nested subtests are
     * involved. It is incremented for each subtest created, allowing for
     * clear identification of subtests in reports and diagnostics.
     */
    size_t current_subtest_index_ = 0;

    std::vector<std::unique_ptr<subtest>> children_subtests_;
  };

  // ==========================================================================

  /**
   * @ingroup micro-test-plus-test-suites
   * @brief CRTP base class factoring out callable storage, rule-of-five, and
   * `run()` logic shared by `test` and `static_suite`.
   *
   * @tparam Self_T The concrete derived class type (CRTP pattern). The stored
   * callable receives a `Self_T&` reference when the suite is executed.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  template <typename Self_T>
  class runnable : public runnable_base
  {
  public:
    /**
     * @brief Class template constructor.
     *
     * @tparam Callable_T The callable type.
     * @tparam Args_T The additional argument types.
     *
     * @param [in] name The test suite name, used in reports.
     * @param [in] runner The test runner managing this suite.
     * @param [in] own_index The suite index within the runner.
     * @param [in] callable The callable invoked when the suite runs.
     * @param [in] arguments Additional arguments forwarded to the callable
     * after the leading `Self_T&` reference.
     *
     * @details
     * The rule of five is enforced to prevent accidental copying or moving.
     */
    template <typename Callable_T, typename... Args_T>
    runnable (const char* name, class runner& runner, size_t own_index,
              Callable_T&& callable, Args_T&&... arguments);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    runnable (const runnable&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    runnable (runnable&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    runnable&
    operator= (const runnable&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    runnable&
    operator= (runnable&&) = delete;

    /**
     * @brief Virtual destructor.
     */
    virtual ~runnable () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Runs the test function by invoking the stored callable with the
     * derived self instance.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    virtual void
    run (void) = 0;

  protected:
    /**
     * @brief Callable storing the test suite body and any bound arguments.
     * Invoked with a reference to the derived `Self_T` instance.
     */
    std::function<void (Self_T&)> callable_;
  };

  // ==========================================================================

  /**
   * @ingroup micro-test-plus-test-suites
   * @brief Represents a named group of test cases that self-register to the
   * runner.
   *
   * @details
   * The `test_suite` class extends `test_node` and enables the
   * registration and execution of callable objects (such as lambdas or
   * function pointers) as test suites. Upon construction, each test suite
   * automatically registers itself with the test runner, facilitating
   * automated test discovery and execution across different components and
   * folders of a project.
   *
   * This class template provides a flexible mechanism for grouping related
   * test cases and managing their execution within the µTest++ framework. It
   * ensures that test suites are non-copyable and non-movable, maintaining
   * unique ownership and consistent state.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class subtest : public runnable<subtest>
  {
  public:
    /**
     * @brief Class template constructor for test.
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
    subtest (const char* name, class runner& runner, suite& parent_suite,
             size_t own_index, size_t nesting_depth, Callable_T&& callable,
             Args_T&&... arguments);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    subtest (const subtest&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    subtest (subtest&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    subtest&
    operator= (const subtest&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    subtest&
    operator= (subtest&&) = delete;

    /**
     * @brief Virtual destructor.
     */
    virtual ~subtest () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Adds a test case to the suite.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param [in] name The test case name or description, used in reports.
     * @param [in] callable A generic callable object, usually a lambda,
     * invoked to perform the test.
     * @param [in] arguments A possibly empty list of arguments to be passed to
     * the callable.
     */
    template <typename Callable_T, typename... Args_T>
    void
    test (const char* name, Callable_T&& callable, Args_T&&... arguments);

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
     * namespace mt = micro_os_plus::micro_test_plus;
     * mt::expect(compute_answer() == 42) << "answer is 42";
     * @endcode
     */
    template <class Expr_T,
              type_traits::requires_t<
                  type_traits::is_op_v<Expr_T>
                  or type_traits::is_convertible_v<Expr_T, bool>> = 0>
    auto
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
     * namespace mt = micro_os_plus::micro_test_plus;
     * mt::assume(compute_answer() == 42) << "answer is 42";
     * @endcode
     */
    template <class Expr_T,
              type_traits::requires_t<
                  type_traits::is_op_v<Expr_T>
                  or type_traits::is_convertible_v<Expr_T, bool>> = 0>
    auto
    assume (const Expr_T& expr, const reflection::source_location& sl
                                = reflection::source_location::current ())
    {
      return detail::deferred_reporter<Expr_T>{ expr, true, sl, *this };
    }

    // ------------------------------------------------------------------------

    virtual void
    run (void) override;

    [[nodiscard]] suite&
    parent_suite (void) const
    {
      return parent_suite_;
    }

    [[nodiscard]] size_t
    nesting_depth ()
    {
      return nesting_depth_;
    }

  protected:
    suite& parent_suite_;

    /**
     * @brief The nesting depth of the test case within the suite.
     */
    size_t nesting_depth_;
  };

  // ==========================================================================

  class suite : public runnable<suite>
  {
  public:
    template <typename Callable_T, typename... Args_T>
    suite (const char* name, class runner& runner, size_t own_index,
           Callable_T&& callable, Args_T&&... arguments);

    suite (const suite&) = delete;
    suite (suite&&) = delete;
    suite&
    operator= (const suite&) = delete;
    suite&
    operator= (suite&&) = delete;

    virtual ~suite () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Adds a test case to the suite.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param [in] name The test case name or description, used in reports.
     * @param [in] callable A generic callable object, usually a lambda,
     * invoked to perform the test.
     * @param [in] arguments A possibly empty list of arguments to be passed to
     * the callable.
     */
    template <typename Callable_T, typename... Args_T>
    void
    test (const char* name, Callable_T&& callable, Args_T&&... arguments);

    // ------------------------------------------------------------------------
    virtual void
    run (void) override;
  };

  // ==========================================================================

  class top_suite : public suite
  {
  public:
    top_suite (const char* name, class runner& runner);

    top_suite (const top_suite&) = delete;
    top_suite (top_suite&&) = delete;
    top_suite&
    operator= (const top_suite&) = delete;
    top_suite&
    operator= (top_suite&&) = delete;

    virtual ~top_suite () override;
  };

  // ==========================================================================

  class static_suite : public suite
  {
  public:
    /**
     * @brief Class template constructor for static_suite.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param [in] name The test suite name or description, used in reports.
     * @param [in] runner The static test runner managing this suite.
     * @param [in] callable A generic callable object, usually a lambda or
     * function, invoked to perform the test suite.
     * @param [in] arguments A possibly empty list of arguments to be passed to
     * the callable.
     *
     * @details
     * The rule of five is enforced to prevent accidental copying or moving.
     * Upon construction, the suite is automatically registered with the
     * runner.
     */
    template <typename Callable_T, typename... Args_T>
    static_suite (const char* name, static_runner& runner,
                  Callable_T&& callable, Args_T&&... arguments);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    static_suite (const static_suite&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    static_suite (static_suite&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    static_suite&
    operator= (const static_suite&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    static_suite&
    operator= (static_suite&&) = delete;

    /**
     * @brief Virtual destructor.
     */
    virtual ~static_suite () override;

    // ------------------------------------------------------------------------

    void
    update_own_index (size_t offset);

    virtual void
    run (void) override;

  protected:
    /**
     * @brief Callable storing the static suite body and any bound arguments.
     * Invoked with a reference to the concrete `static_suite` instance.
     */
    std::function<void (static_suite&)> static_callable_;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_H_

// ----------------------------------------------------------------------------

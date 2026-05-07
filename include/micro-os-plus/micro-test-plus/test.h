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

#if !defined(MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_)
// clang-format off
#error "Do not include this file directly; use <micro-os-plus/micro-test-plus.h>."
// clang-format on
#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

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
   * @brief Base class for runners and runable tests.
   *
   * @details
   * The `test_node` class provides the foundational interface for
   * managing test within the µTest++ framework. It maintains counters
   * for successful and failed checks, tracks test cases, and offers methods
   * for marking the commencement and completion of test cases and suites.
   *
   * This class ensures consistent state management and reporting for all
   * derived classes. It also provides utility methods for querying the
   * node's name, the number of successful and failed checks, the number of
   * test cases, and the overall result of the node.
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
     * @brief Constructs a test node.
     *
     * @param [in] name The test node name.
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
     * @brief Gets the node name.
     *
     * @par Parameters
     *	None.
     * @return A pointer to the null-terminated test node name.
     */
    [[nodiscard]] const char*
    name (void) const noexcept;

  public:
    /**
     * @brief Gets the totals for the test.
     *
     * @par Parameters
     *	None.
     * @return A reference to the runner_totals instance.
     */
    [[nodiscard]] runner_totals&
    totals () noexcept;

    /**
     * @brief Gets the totals for the test (const overload).
     *
     * @par Parameters
     *	None.
     * @return A const reference to the runner_totals instance.
     */
    [[nodiscard]] const runner_totals&
    totals () const noexcept;

  protected:
    /**
     * @brief The test node name.
     *
     * @note Derived classes may access this member directly in
     * addition to the public `name()` getter.
     */
    const char* name_;

    /**
     * @brief Totals for the test node, including nested cases.
     */
    runner_totals totals_;
  };

  // ==========================================================================

  /**
   * @brief Non-template base for all runnable objects (suites and subtests).
   *
   * @details
   * `runnable_base` extends `test_node` with the state that is shared by
   * every runnable object but does not depend on the CRTP self-type:
   * - a reference to the owning `runner`,
   * - the object's own index within its parent container,
   * - a sequential subtest index used when creating nested subtests, and
   * - an owning vector of child `subtest` instances.
   *
   * Concrete runnable classes (`suite`, `subtest`) derive from
   * `runnable<Self_T>` which in turn derives from `runnable_base`.
   *
   * The class is non-copyable and non-movable to preserve unique ownership
   * and consistent state throughout the test session.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class runnable_base : public test_node
  {
  public:
    /**
     * @brief Constructs a `runnable_base` with a name, runner, and index.
     *
     * @param name The name used in reports.
     * @param runner The test runner managing this object.
     * @param own_index The positional index of this object within its parent.
     */
    runnable_base (const char* name, runner& runner, size_t own_index);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    runnable_base (const runnable_base&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    runnable_base (runnable_base&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    runnable_base&
    operator= (const runnable_base&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    runnable_base&
    operator= (runnable_base&&) = delete;

    /**
     * @brief Virtual destructor.
     */
    virtual ~runnable_base () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Returns the positional index of this object within its parent.
     *
     * @par Parameters
     *   None.
     * @return The one-based own index.
     */
    [[nodiscard]] size_t
    own_index () const noexcept;

    /**
     * @brief Sets the positional index of this object within its parent.
     *
     * @note This overload follows the same-name getter/setter pattern
     * used throughout the framework: the getter is the `const` overload
     * and the setter is the non-`const` single-argument overload.
     *
     * @param index The new index value.
     * @par Returns
     *   Nothing.
     */
    void
    own_index (size_t index) noexcept;

    /**
     * @brief Returns the index of the most recently created child subtest.
     *
     * @par Parameters
     *   None.
     * @return The current child subtest sequential index.
     */
    [[nodiscard]] size_t
    current_subtest_index () const noexcept;

    /**
     * @brief Increments and returns the child subtest sequential index.
     *
     * @par Parameters
     *   None.
     * @return The new index value after incrementing.
     */
    size_t
    increment_subtest_index () noexcept;

    /**
     * @brief Returns the number of direct child subtests owned by this node.
     *
     * @par Parameters
     *   None.
     * @return The number of child subtests.
     */
    [[nodiscard]] size_t
    children_subtests_count (void) const noexcept;

    /**
     * @brief Gets the test reporter associated with this test runnable.
     *
     * @par Parameters
     *	None.
     * @return A reference to the test reporter.
     */
    [[nodiscard]] class reporter&
    reporter (void) const noexcept;

    /**
     * @brief Aborts test execution via the owning runner.
     *
     * @param sl The source location from which the abort is triggered.
     * @par Returns
     *   Does not return.
     */
    [[noreturn]] void
    abort (const reflection::source_location& sl
           = reflection::source_location::current ());

    /**
     * @brief Gets the test runner associated with this test runnable.
     *
     * @par Parameters
     *	None.
     * @return A reference to the test runner.
     */
    [[nodiscard]] class runner&
    runner (void) const noexcept;

  protected:
    /**
     * @brief Registers a newly constructed child subtest and executes it
     * immediately.
     *
     * @param child_test Owning pointer to the newly created `subtest`.
     * @param suite The parent `suite` to which execution results are reported.
     * @par Returns
     *   Nothing.
     */
    void
    after_subtest_create_ (std::unique_ptr<class subtest> child_test,
                           suite& suite);

  protected:
    /**
     * @brief Reference to the test runner that owns this object.
     */
    class runner& runner_;

    /**
     * @brief The test index, counting from 1.
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

    /**
     * @brief Owning collection of direct child subtests.
     *
     * @details
     * Each call to `test()` appends a new `subtest` to this vector and
     * runs it immediately. The vector retains ownership for the lifetime of
     * the parent runnable.
     */
    std::vector<std::unique_ptr<subtest>> children_subtests_;
  };

  // ==========================================================================

  /**
   * @brief CRTP base class factoring out callable storage, rule-of-five, and
   * `run()` logic shared by `subtest` and `suite`.
   *
   * @tparam Self_T The concrete derived class type (CRTP pattern). The stored
   * callable receives a `Self_T&` reference when the test is executed.
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
     * @param [in] name The test name, used in reports.
     * @param [in] runner The test runner managing this test.
     * @param [in] own_index The test index within the runner.
     * @param [in] callable The callable invoked when the test runs.
     * @param [in] arguments Additional arguments forwarded to the callable
     * after the leading `Self_T&` reference.
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
     * @brief Callable storing the test body and any bound arguments.
     * Invoked with a reference to the derived `Self_T` instance.
     */
    std::function<void (Self_T&)> callable_;
  };

  // ==========================================================================

  /**
   * @ingroup micro-test-plus-test-case
   * @brief A named, runnable test case that lives inside a `suite`.
   *
   * @details
   * `subtest` represents a single, named test case or a nested group of
   * checks within a parent `suite` or `subtest. It is constructed by calling
   * `suite::test()` or `subtest::test()`, both of which create the object,
   * immediately execute its callable body via `run()`, and register the
   * result with the parent node.
   *
   * The body of the subtest is supplied as a callable (typically a lambda)
   * that receives a `subtest&` reference as its first argument. Inside the
   * body, `expect()` and `assume()` are used to evaluate conditions and
   * record the results. Subtests may be nested to an arbitrary depth.
   *
   * The class is non-copyable and non-movable to preserve unique ownership
   * and consistent state throughout the test session.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class subtest : public runnable<subtest>
  {
  public:
    /**
     * @brief Constructs a subtest with a name, runner, parent suite, index,
     * nesting depth, and callable.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param [in] name The subtest name or description, used in reports.
     * @param [in] runner The test runner managing this subtest.
     * @param [in] parent_suite The suite that owns this subtest.
     * @param [in] own_index The one-based positional index within the parent.
     * @param [in] nesting_depth The depth of nesting; 1 for top-level
     * subtests.
     * @param [in] callable A generic callable object, usually a lambda,
     * invoked when the subtest executes.
     * @param [in] arguments A possibly empty list of arguments forwarded to
     * the callable after the leading `subtest&` reference.
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
     * @par Constraints
     * Enabled only if `Expr_T` is derived from `detail::op` or
     * is convertible to `bool` (enforced via a C++20 `requires` clause).
     *
     * @param [in] expr Logical expression to evaluate.
     * @param [in] sl Optional source location, defaulting to the current line.
     * @return An output stream to write optional messages.
     */
    template <class Expr_T>
      requires type_traits::checkable<Expr_T>
    auto
    expect (const Expr_T& expr, const reflection::source_location& sl
                                = reflection::source_location::current ());

    /**
     * @ingroup micro-test-plus-assumptions
     * @brief Check a condition and, if false, abort test execution.
     *
     * @tparam Expr_T The type of the custom expression.
     *
     * @par Constraints
     * Enabled only if `Expr_T` is derived from `detail::op` or
     * is convertible to `bool` (enforced via a C++20 `requires` clause).
     *
     * @param [in] expr Logical expression to evaluate.
     * @param [in] sl Optional source location, defaulting to the current line.
     * @return An output stream to write optional messages.
     */
    template <class Expr_T>
      requires type_traits::checkable<Expr_T>
    auto
    assume (const Expr_T& expr, const reflection::source_location& sl
                                = reflection::source_location::current ());

    // ------------------------------------------------------------------------

    /**
     * @brief Executes the subtest body by invoking the stored callable.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    virtual void
    run (void) override;

    /**
     * @brief Returns the nesting depth of this subtest.
     *
     * @par Parameters
     *   None.
     * @return The nesting depth (1 = top-level).
     */
    [[nodiscard]] size_t
    nesting_depth () const noexcept;

  protected:
    /**
     * @brief Reference to the parent suite that owns this subtest.
     */
    suite& parent_suite_;

    /**
     * @brief The nesting depth of this subtest within the suite.
     */
    size_t nesting_depth_;
  };

  // ==========================================================================

  /**
   * @ingroup micro-test-plus-test-suites
   * @brief A named, runnable test suite registered with the test runner.
   *
   * @details
   * `suite` represents a top-level named group of related test cases within
   * the µTest++ framework. It is created by calling `runner::suite()`, which
   * constructs the object, stores it in the runner's collection, and runs it
   * immediately. Each suite records its own timing information and propagates
   * its results to the owning `runner`.
   *
   * The body of a suite is supplied as a callable (typically a lambda) that
   * receives a `suite&` reference as its first argument. Inside the body,
   * `suite::test()` is called to create and run individual subtests.
   *
   * The class is non-copyable and non-movable to preserve unique ownership
   * and consistent state throughout the test session.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class suite : public runnable<suite>
  {
  public:
    /**
     * @brief Constructs a suite with a name, runner, and callable body.
     *
     * @tparam Callable_T The type of the callable object.
     * @tparam Args_T The types of any additional callable arguments.
     *
     * @param [in] name The suite name or description, used in reports.
     * @param [in] runner The test runner managing this suite.
     * @param [in] callable A generic callable object, usually a lambda,
     * invoked when the suite executes. Its first parameter must be
     * `suite&`.
     * @param [in] arguments A possibly empty list of arguments forwarded to
     * the callable after the leading `suite&` reference.
     */
    template <typename Callable_T, typename... Args_T>
    suite (const char* name, class runner& runner, Callable_T&& callable,
           Args_T&&... arguments);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    suite (const suite&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    suite (suite&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    suite&
    operator= (const suite&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    suite&
    operator= (suite&&) = delete;

    /**
     * @brief Virtual destructor.
     */
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

    /**
     * @brief Gets the timings for this suite.
     *
     * @par Parameters
     *	None.
     * @return A reference to the timestamps instance.
     */
    [[nodiscard]] timestamps&
    timings () noexcept;

    /**
     * @brief Gets the timings for this suite (const overload).
     *
     * @par Parameters
     *	None.
     * @return A const reference to the timestamps instance.
     */
    [[nodiscard]] const timestamps&
    timings () const noexcept;

    /**
     * @brief Executes the suite body by invoking the stored callable.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    virtual void
    run (void) override;

  protected:
    /**
     * @brief Timing measurements for this suite's execution.
     */
    timestamps timings_;
  };

  // ==========================================================================

  /**
   * @brief The implicit top-level suite owned by every `runner` instance.
   *
   * @details
   * `top_suite` is a thin specialisation of `suite` used as the implicit
   * root context for the `runner`. It is created by the `runner` constructor
   * and is available to user code via `runner::initialise()`, which returns
   * a reference to it. Unlike regular `suite` objects, `top_suite` is not
   * stored in the runner's child-suite vector; instead it is a direct member
   * of `runner`.
   *
   * Users do not normally construct `top_suite` directly.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class top_suite : public suite
  {
  public:
    /**
     * @brief Constructs the top-level suite with a name and runner reference.
     *
     * @param name The suite name used in reports.
     * @param runner The test runner that owns this suite.
     */
    top_suite (const char* name, class runner& runner);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    top_suite (const top_suite&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    top_suite (top_suite&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    top_suite&
    operator= (const top_suite&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    top_suite&
    operator= (top_suite&&) = delete;

    /**
     * @brief Virtual destructor.
     */
    virtual ~top_suite () override;
  };

  // ==========================================================================

  /**
   * @ingroup micro-test-plus-test-suites
   * @brief A test suite designed for static (namespace-scope) registration
   * with a `static_runner`.
   *
   * @details
   * `static_suite` extends `suite` to support the pattern where test suites
   * are declared as namespace-scope objects and therefore constructed before
   * or after the `static_runner` instance, in unspecified
   * static-initialisation order.
   *
   * Upon construction, the suite automatically registers itself with the
   * supplied `static_runner` by calling
   * `static_runner::register_suite_()`. The runner defers execution of all
   * registered static suites until `static_runner::run_suites_()` is invoked,
   * which typically happens inside the implicit `main()` provided by the
   * framework.
   *
   * In addition to the standard callable body inherited from `suite`, a
   * `static_suite` may carry a second, statically-registered callable stored
   * in `static_callable_`. The overridden `run()` method invokes both bodies
   * in sequence, allowing the suite to integrate both dynamic and static
   * registration patterns.
   *
   * The class is non-copyable and non-movable to preserve unique ownership
   * and consistent state throughout the test session.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
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

    /**
     * @brief Executes the static suite body using the stored static callable.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
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

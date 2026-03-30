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
 * core classes, `test_suite_base` and `test_suite`, offer mechanisms for
 * tracking test case execution, managing counters for successful and failed
 * checks, and supporting automated registration and discovery of test suites.
 *
 * The design ensures that test suites are non-copyable and non-movable,
 * maintaining unique ownership and consistent state. Flexible support for
 * callable objects enables a wide range of test suite definitions,
 * facilitating expressive and maintainable test organisation across embedded
 * and general C++ projects.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus2`
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

#ifndef MICRO_TEST_PLUS_TEST_SUITE_H_
#define MICRO_TEST_PLUS_TEST_SUITE_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include "test-runner-totals.h"
#include "test-case.h"
#include "timings.h"

#include <functional>

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

// =============================================================================

namespace micro_os_plus::micro_test_plus2
{
  class test_runner;
  class static_test_runner;
  class test_reporter;
  class test_runner_totals;

  // --------------------------------------------------------------------------

  /**
   * @brief Base class for all test suites.
   *
   * @details
   * The `test_suite_base` class provides the foundational interface for
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
   * `micro_os_plus::micro_test_plus2` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class test_suite_base
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
    test_suite_base (const char* name, test_runner& runner, size_t own_index);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    test_suite_base (const test_suite_base&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    test_suite_base (test_suite_base&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    test_suite_base&
    operator= (const test_suite_base&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_suite_base&
    operator= (test_suite_base&&) = delete;

    /**
     * @brief Virtual destructor for the test_suite_base class.
     */
    virtual ~test_suite_base ();

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
    test_case (const char* name, Callable_T&& callable, Args_T&&... arguments);

    // ------------------------------------------------------------------------
    /**
     * @brief Runs the sequence of test cases in the suite.
     *
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     *
     * @details
     * The `run` method is a pure virtual function that must be implemented by
     * derived test suite classes. It is responsible for executing the test
     * suite logic, including child test cases.
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

    /**
     * @brief Gets the test runner associated with this test suite.
     *
     * @par Parameters
     *	None.
     * @return A reference to the test runner.
     */
    [[nodiscard]] constexpr test_runner&
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
    [[nodiscard]] test_reporter&
    reporter (void);

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
     * @brief The test suite index, counting from 1.
     */
    size_t own_index_;

    /**
     * @brief Totals for the test suite, including nested cases.
     */
    test_runner_totals totals;

    timestamps timings;

  protected:
    /**
     * @brief The test suite name.
     */
    const char* name_;

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
     * @brief Reference to the test runner.
     */
    test_runner& runner_;

    /**
     * @brief The current test case name.
     */
    //    const char* test_case_name_;

    std::vector<test_case_base*> test_cases_;
  };

  class test_suite_top : public test_suite_base
  {
  public:
    /**
     * @brief Class template constructor for test_suite.
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
    test_suite_top (const char* name, test_runner& runner, size_t own_index);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    test_suite_top (const test_suite_top&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    test_suite_top (test_suite_top&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    test_suite_top&
    operator= (const test_suite_top&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_suite_top&
    operator= (test_suite_top&&) = delete;

    /**
     * @brief Virtual destructor for the test_suite_top class.
     */
    virtual ~test_suite_top () override;

    // ------------------------------------------------------------------------
    virtual void
    run (void) override;
  };

  // ==========================================================================

  /**
   * @ingroup micro-test-plus-test-suites
   * @brief CRTP base class factoring out callable storage, rule-of-five, and
   * `run()` logic shared by `test_suite_callable` and `static_test_suite`.
   *
   * @tparam Self_T The concrete derived class type (CRTP pattern). The stored
   * callable receives a `Self_T&` reference when the suite is executed.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  template <typename Self_T>
  class test_suite_callable_common : public test_suite_base
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
    test_suite_callable_common (const char* name, test_runner& runner,
                                size_t own_index, Callable_T&& callable,
                                Args_T&&... arguments);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    test_suite_callable_common (const test_suite_callable_common&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    test_suite_callable_common (test_suite_callable_common&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    test_suite_callable_common&
    operator= (const test_suite_callable_common&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_suite_callable_common&
    operator= (test_suite_callable_common&&) = delete;

    /**
     * @brief Virtual destructor.
     */
    virtual ~test_suite_callable_common () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Runs the test suite by invoking the stored callable with the
     * derived `Self_T` instance.
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
     * @brief Callable storing the test suite body and any bound arguments.
     * Invoked with a reference to the derived `Self_T` instance.
     */
    std::function<void (Self_T&)> callable_;
  };

  /**
   * @ingroup micro-test-plus-test-suites
   * @brief Represents a named group of test cases that self-register to the
   * runner.
   *
   * @details
   * The `test_suite` class extends `test_suite_base` and enables the
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
   * `micro_os_plus::micro_test_plus2` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class test_suite_callable
      : public test_suite_callable_common<test_suite_callable>
  {
  public:
    /**
     * @brief Class template constructor for test_suite_callable.
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
    test_suite_callable (const char* name, test_runner& runner,
                         size_t own_index, Callable_T&& callable,
                         Args_T&&... arguments);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    test_suite_callable (const test_suite_callable&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    test_suite_callable (test_suite_callable&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    test_suite_callable&
    operator= (const test_suite_callable&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_suite_callable&
    operator= (test_suite_callable&&) = delete;

    /**
     * @brief Virtual destructor.
     */
    virtual ~test_suite_callable () override;
  };

  // ==========================================================================

  class static_test_suite
      : public test_suite_callable_common<static_test_suite>
  {
  public:
    /**
     * @brief Class template constructor for static_test_suite.
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
    static_test_suite (const char* name, static_test_runner& runner,
                       Callable_T&& callable, Args_T&&... arguments);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    static_test_suite (const static_test_suite&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    static_test_suite (static_test_suite&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    static_test_suite&
    operator= (const static_test_suite&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    static_test_suite&
    operator= (static_test_suite&&) = delete;

    /**
     * @brief Virtual destructor.
     */
    virtual ~static_test_suite () override;

    void
    update_own_index (size_t offset);
  };

  // class static_test_suites_registry
  // {
  // public:
  //   static_test_suites_registry ();

  //   static_test_suites_registry (const static_test_suites_registry&) =
  //   delete; static_test_suites_registry (static_test_suites_registry&&) =
  //   delete; static_test_suites_registry& operator= (const
  //   static_test_suites_registry&) = delete; static_test_suites_registry&
  //   operator= (static_test_suites_registry&&) = delete;

  //   ~static_test_suites_registry ();

  //   //
  //   ------------------------------------------------------------------------

  //   static void
  //   static_test_suites_registry_ensure_initialised (
  //       static_test_suites_registry& registry);

  //   //
  //   ------------------------------------------------------------------------

  //   [[nodiscard]] std::vector<test_suite_base*>&
  //   test_suites (void)
  //   {
  //     return *test_suites_;
  //   }

  //   void
  //   register_test_suite (test_suite_base& test_suite);

  // private:
  //   // This MUST NOT be explicitly initialised, is must be
  //   default-initialised
  //   // to nullptr by the startup code, as BSS.
  //   std::vector<test_suite_base*>* test_suites_;
  // };

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

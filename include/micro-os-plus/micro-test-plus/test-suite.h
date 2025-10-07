/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2025 Liviu Ionescu. All rights reserved.
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

#ifndef MICRO_TEST_PLUS_TEST_SUITE_H_
#define MICRO_TEST_PLUS_TEST_SUITE_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

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

namespace micro_os_plus::micro_test_plus
{
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
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
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
    test_suite_base (const char* name);

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
    operator= (const test_suite_base&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_suite_base&
    operator= (test_suite_base&&)
        = delete;

    /**
     * @brief Virtual destructor for the test_suite_base class.
     */
    virtual ~test_suite_base ();

    /**
     * @brief Runs the sequence of test cases in the suite.
     *
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    virtual void
    run (void);

    /**
     * @brief Marks the beginning of a named test case.
     *
     * @param [in] name The test case name.
     * @par Returns
     *  Nothing.
     */
    void
    begin_test_case (const char* name);

    /**
     * @brief Marks the end of a test case.
     *
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.     */
    void
    end_test_case (void);

    /**
     * @brief Gets the suite name.
     *
     * @par Parameters
     *	None.
     * @return A pointer to the null-terminated test suite name.
     */
    [[nodiscard]] constexpr const char*
    name (void)
    {
      return name_;
    }

    /**
     * @brief Increments the count of passed test conditions.
     *
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    void
    increment_successful (void);

    /**
     * @brief Increments the count of failed test conditions.
     *
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    void
    increment_failed (void);

    /**
     * @brief Gets the number of conditions that passed.
     *
     * @par Parameters
     *	 None.
     * @return An integer with the number of checks that passed.
     */
    [[nodiscard]] constexpr int
    successful_checks (void)
    {
      return successful_checks_;
    }

    /**
     * @brief Gets the number of test conditions that failed.
     *
     * @par Parameters
     *	None.
     * @return An integer with the number of checks that failed.
     */
    [[nodiscard]] constexpr int
    failed_checks (void)
    {
      return failed_checks_;
    }

    /**
     * @brief Gets the number of test cases.
     *
     * @par Parameters
     *	None.
     * @return An integer with the number of test cases.
     */
    [[nodiscard]] constexpr int
    test_cases (void)
    {
      return test_cases_;
    }

    /**
     * @brief Begins the execution of the test suite.
     *
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    void
    begin_test_suite (void);

    /**
     * @brief Marks the end of the test suite.
     *
     * @par Parameters
     *	None.
     * @par Returns
     *  Nothing.
     */
    void
    end_test_suite (void);

    /**
     * @brief Gets the test suite result.
     *
     * @par Parameters
     *	None.
     * @return True if the test suite was successful.
     */
    [[nodiscard]] constexpr bool
    was_successful (void)
    {
      // Also fail if none passed.
      return (failed_checks_ == 0 && successful_checks_ != 0);
    }

    /**
     * @brief Checks if the test suite was not used.
     *
     * @par Parameters
     *	None.
     * @return True if the test suite is not used.
     */
    [[nodiscard]] constexpr bool
    unused (void)
    {
      return (failed_checks_ == 0 && successful_checks_ == 0
              && test_cases_ == 0);
    }

  protected:
    /**
     * @brief The test suite name.
     */
    const char* name_;

    /**
     * @brief The current test case name.
     */
    const char* test_case_name_;

    /**
     * @brief Count of test conditions that passed.
     */
    int successful_checks_ = 0;

    /**
     * @brief Count of test conditions that failed.
     */
    int failed_checks_ = 0;

    /**
     * @brief Count of test cases in the test suite.
     */
    int test_cases_ = 0;

  public:
    /**
     * @brief Indicates whether to process deferred begin for test cases.
     */
    bool process_deferred_begin = true;

    /**
     * @brief Structure holding the current test case's check counters.
     *
     * @details
     * Tracks the number of successful and failed checks for the currently
     * running test case.
     */
    struct
    {
      /**
       * @brief Number of successful checks in the current test case.
       */
      int successful_checks;

      /**
       * @brief Number of failed checks in the current test case.
       */
      int failed_checks;
    } current_test_case{};
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
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class test_suite : public test_suite_base
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
    template <typename Callable_T, typename... Args_T>
    test_suite (const char* name, Callable_T&& callable,
                Args_T&&... arguments);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    test_suite (const test_suite&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    test_suite (test_suite&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    test_suite&
    operator= (const test_suite&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_suite&
    operator= (test_suite&&)
        = delete;

    /**
     * @brief Virtual destructor for the test_suite class.
     */
    virtual ~test_suite () override;

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
     * @brief Callable object representing the test suite's execution logic.
     */
    std::function<void (void)> callable_;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_SUITE_H_

// ----------------------------------------------------------------------------

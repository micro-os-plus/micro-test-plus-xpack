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
 * @brief C++ header file with declarations for the µTest++ test runner.
 *
 * @details
 * This header provides the declarations for the test runner facilities used
 * within the µTest++ framework. It defines the interface for managing the
 * registration and execution of test suites, supporting automated discovery
 * and orchestration of tests across a project.
 *
 * The test runner is responsible for initialising the test environment,
 * registering test suites, managing command-line arguments, and determining
 * the overall test result via an exit code. It also provides mechanisms for
 * aborting test execution and retrieving the default suite name.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_TEST_RUNNER_H_
#define MICRO_TEST_PLUS_TEST_RUNNER_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <functional>
#include <time.h>

#include "test-suite.h"
#include "test-reporter.h"
#include "timings.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#else
#pragma GCC diagnostic ignored "-Wsuggest-final-types"
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @brief The test runner for the µTest++ framework.
   *
   * @details
   * The `runner` class is responsible for managing the registration and
   * execution of test suites within the µTest++ framework. It maintains a
   * collection of test suites, each of which registers itself automatically
   * upon construction, enabling seamless integration and execution of tests
   * across different components and folders of a project.
   *
   * The test runner provides methods for initialising the test environment,
   * registering test suites, retrieving the runner's name, and determining the
   * overall test result via an exit code. It also offers an abort mechanism
   * for terminating test execution in exceptional circumstances.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class runner
  {
  public:
    /**
     * @brief Default constructor for the runner class.
     *
     * @details
     * The rule of five is enforced to prevent accidental copying or moving.
     */
    runner (const char* top_suite_name);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    runner (const runner&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    runner (runner&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    runner&
    operator= (const runner&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    runner&
    operator= (runner&&) = delete;

    /**
     * @brief Destructor for the runner class.
     */
    virtual ~runner ();

    /**
     * @brief Initialises the test runner with command-line arguments and an
     * optional suite name.
     *
     * @param argc The argument count from main().
     * @param argv The argument vector from main().
     * @param name The name of the default test suite.
     * @par Returns
     *   Nothing.
     */
    test_suite_top&
    initialise (int argc, char* argv[]);

    /**
     * @brief Returns 0 if all tests were successful, 1 otherwise.
     *
     * @par Parameters
     *	 None.
     * @return Integer exit code representing the overall test result.
     */
    int
    exit_code (void);

    template <typename Callable_T, typename... Args_T>
    void
    test_suite (const char* name, Callable_T&& callable,
                Args_T&&... arguments);

    [[nodiscard]] size_t
    test_suites_count (void) const;

    [[nodiscard]] virtual size_t
    total_test_suites_count (void) const;

    /**
     * @brief Aborts test execution immediately.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    [[noreturn]] void
    abort (void);

    /**
     * @brief Returns a reference to the test reporter.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Reference to the test reporter.
     */
    [[nodiscard]] constexpr test_reporter&
    reporter (void) const
    {
      return *reporter_;
    }

    [[nodiscard]] constexpr test_suite_top&
    top_suite (void) const
    {
      return *top_suite_;
    }

    // ------------------------------------------------------------------------
  public:
    /**
     * @brief Array of registered test suites.
     */
    std::vector<test_suite_base*> test_suites;

    /**
     * @brief Totals for the test runner.
     *
     * @details
     * This class holds the cumulative totals for all test suites. It is
     * updated as each test suite is executed, allowing for a comprehensive
     * summary of the test results at the end of the test run. The totals
     * include counts for all test cases executed, including nested cases,
     * providing a complete overview of the testing outcomes.
     */
    test_runner_totals totals;

    timestamps timings;

  protected:
    /**
     * @brief Pointer to the test reporter used for outputting test results.
     */
    test_reporter* reporter_{ nullptr };

    /**
     * @brief Stores the argument count passed to the test runner.
     */
    int argc_ = 0;

    /**
     * @brief Stores the argument vector passed to the test runner.
     */
    char** argv_ = nullptr;

    /**
     * @brief Pointer to the top-level test suite.
     */
    test_suite_top* top_suite_;
  };

  class static_runner final : public runner
  {
  public:
    static_runner (const char* top_suite_name);
    ~static_runner () override;

    // ------------------------------------------------------------------------

    [[nodiscard]] std::vector<static_test_suite*>&
    static_test_suites (void)
    {
      return *static_test_suites_;
    }

    static void
    register_static_test_suite (static_test_runner& runner,
                                static_test_suite& test_suite);

    [[nodiscard]] size_t
    static_test_suites_count (void) const;

    [[nodiscard]] virtual size_t
    total_test_suites_count (void) const final override;

    void
    run_static_test_suites (void);

  private:
    // This MUST NOT be explicitly initialised, is must be default-initialised
    // to nullptr by the startup code, as BSS.
    std::vector<static_test_suite*>* static_test_suites_;
  };

} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_RUNNER_H_

// ----------------------------------------------------------------------------

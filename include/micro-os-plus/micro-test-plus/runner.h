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
#include <memory>
#include <time.h>

#include "reporter.h"
#include "timings.h"
#include "test.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#else // GCC only
#pragma GCC diagnostic ignored "-Wsuggest-final-types"
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#pragma GCC diagnostic ignored "-Wchanges-meaning"
#pragma GCC diagnostic ignored "-Wredundant-tags"
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
  class runner : public test_node
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
    virtual ~runner () override;

    /**
     * @brief Initialises the test runner with command-line arguments and an
     * optional suite name.
     *
     * @param argc The argument count from main().
     * @param argv The argument vector from main().
     * @param name The name of the default test suite.
     * @return Reference to the top-level test suite.
     */
    suite&
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

    /**
     * @brief Adds a test suite to the runner.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param [in] name The test suite name or description, used in reports.
     * @param [in] callable A generic callable object, usually a lambda,
     * invoked to perform the test suite.
     * @param [in] arguments A possibly empty list of arguments to be passed to
     * the callable.
     */
    template <typename Callable_T, typename... Args_T>
    void
    suite (const char* name, Callable_T&& callable, Args_T&&... arguments);

    /**
     * @brief Registers a test suite with the runner.
     *
     * @param [in] suite The test suite to register.
     */
    void
    register_suite (class suite& suite);

    // ------------------------------------------------------------------------

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

    // ------------------------------------------------------------------------
    // Getters.

    [[nodiscard]] constexpr const char*
    name (void) const
    {
      return name_;
    }

    [[nodiscard]] virtual size_t
    total_suites_count (void) const;

    [[nodiscard]] constexpr top_suite&
    top_suite (void)
    {
      return top_suite_;
    }

    [[nodiscard]] constexpr size_t
    current_suite_index ()
    {
      return suite_index_;
    }

    constexpr size_t
    increment_suite_index ()
    {
      return ++suite_index_;
    }

    /**
     * @brief Returns a reference to the test reporter.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Reference to the test reporter.
     */
    [[nodiscard]] constexpr class reporter&
    reporter (void) const
    {
      return *reporter_;
    }

    /**
     * @brief Returns a reference to the vector of child test suites.
     *
     * @par Parameters
     *	 None.
     * @return Reference to the vector of child test suites.
     */
    [[nodiscard]] std::vector<class suite*>&
    suites (void)
    {
      return children_suites_;
    }

    /**
     * @brief Returns the count of child test suites.
     *
     * @par Parameters
     *	 None.
     * @return The number of child test suites.
     */
    [[nodiscard]] size_t
    suites_count (void) const;

  protected:
    /**
     * @brief Runs all registered  test suites.
     *
     * @par Parameters
     *	 None.
     */
    void
    run_suites_ (void);

    /**
     * @brief Runs all registered static test suites.
     *
     * @par Parameters
     *	 None.
     */
    void
    run_static_suites_ (void);

    // ------------------------------------------------------------------------
  protected:
    class top_suite top_suite_;

    size_t suite_index_ = 0;

    std::vector<class suite*> children_suites_;

    /**
     * @brief Pointer to the vector of registered static test suites.
     *
     * This pointer is default-initialised to nullptr by the startup code, as
     * it resides in the BSS segment. It is populated with the addresses of
     * registered static test suites during the static initialization phase,
     * before main() is called.
     *
     * This MUST NOT be explicitly initialised, is must be default-initialised
     * to nullptr by the startup code, as BSS.
     */
    std::vector<static_suite*>* static_children_suites_;

    bool has_static_suites_ = false;

    /**
     * @brief Pointer to the test reporter used for outputting test results.
     */
    std::unique_ptr<class reporter> reporter_;

    /**
     * @brief Stores the argument count passed to the test runner.
     */
    int argc_ = 0;

    /**
     * @brief Stores the argument vector passed to the test runner.
     */
    char** argv_ = nullptr;
  };

  // ==========================================================================

  class static_runner final : public runner
  {
  public:
    static_runner (const char* top_suite_name);

    static_runner (const static_runner&) = delete;
    static_runner (static_runner&&) = delete;
    static_runner&
    operator= (const static_runner&) = delete;
    static_runner&
    operator= (static_runner&&) = delete;

    virtual ~static_runner () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Returns a pointer to the vector of registered static test suites.
     *
     * @par Parameters
     *	 None.
     * @return Pointer to the vector of registered static test suites.
     */
    [[nodiscard]] std::vector<static_suite*>*
    static_suites (void)
    {
      return static_children_suites_;
    }

    /**
     * @brief Registers a static test suite with the runner.
     *
     * @param [in] runner The static runner instance.
     * @param [in] suite The static test suite to register.
     */
    static void
    register_static_suite (static_runner& runner, static_suite& suite);

    /**
     * @brief Returns the total count of registered static test suites.
     *
     * @par Parameters
     *	 None.
     * @return The total number of registered static test suites.
     */
    [[nodiscard]] size_t
    static_suites_count (void) const;

    /**
     * @brief Returns the total count of all test suites, including static and
     * dynamic.
     *
     * @par Parameters
     *	 None.
     * @return The total number of test suites.
     */
    [[nodiscard]] virtual size_t
    total_suites_count (void) const final override;
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

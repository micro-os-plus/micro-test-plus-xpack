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

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  // Forward definition.
  class test_suite_base;

  // --------------------------------------------------------------------------

  /**
   * @brief The test runner for the µTest++ framework.
   *
   * @details
   * The `test_runner` class is responsible for managing the registration and
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
  class test_runner
  {
  public:
    /**
     * @brief Default constructor for the test_runner class.
     *
     * @details
     * The rule of five is enforced to prevent accidental copying or moving.
     */
    test_runner ();

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    test_runner (const test_runner&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    test_runner (test_runner&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    test_runner&
    operator= (const test_runner&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_runner&
    operator= (test_runner&&)
        = delete;

    /**
     * @brief Destructor for the test_runner class.
     */
    ~test_runner () = default;

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
    void
    initialize (int argc, char* argv[], const char* name);

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
     * @brief Registers a test suite with the runner.
     *
     * @param suite Pointer to the test suite to register.
     * @par Returns
     *   Nothing.
     */
    void
    register_test_suite (test_suite_base* suite);

    /**
     * @brief Retrieves the name of the default test suite.
     *
     * @par Parameters
     *	 None.
     * @return The name of the default test suite as a constant character
     * pointer.
     */
    constexpr const char*
    name (void)
    {
      return default_suite_name_;
    }

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

  protected:
    /**
     * @brief Stores the argument count passed to the test runner.
     */
    int argc_ = 0;

    /**
     * @brief Stores the argument vector passed to the test runner.
     */
    char** argv_ = nullptr;

    /**
     * @brief The name of the default test suite.
     */
    const char* default_suite_name_ = "Test";

    /**
     * @brief Pointer to the default test suite which groups the main tests.
     */
    test_suite_base* default_test_suite_;

    /**
     * @brief Pointer to the array of registered test suites.
     *
     * @details
     * Statically initialised to zero as BSS, such that test suites defined as
     * static objects in different compilation units can be automatically
     * executed.
     */
    std::vector<test_suite_base*>* suites_;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_RUNNER_H_

// ----------------------------------------------------------------------------

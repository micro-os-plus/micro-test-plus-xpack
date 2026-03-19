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
 * @brief C++ header file with declarations for the µTest++ basic test
 * reporter.
 *
 * @details
 * This header provides the declaration for `test_reporter_basic`, the default
 * concrete implementation of the `test_reporter` abstract interface. It
 * formats and presents test results using `printf`-based standard output,
 * accumulating output in an internal string buffer and supporting
 * colour-coded diagnostics and multiple verbosity levels.
 *
 * Users who require custom output behaviour (e.g. redirecting to a serial
 * port on bare-metal targets) may derive a new class from `test_reporter`
 * instead of using this class.
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

#ifndef MICRO_TEST_PLUS_TEST_REPORTER_BASIC_H_
#define MICRO_TEST_PLUS_TEST_REPORTER_BASIC_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include "test-reporter.h"

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

  /**
   * @brief Basic (standard output) implementation of `test_reporter`.
   *
   * @details
   * `test_reporter_basic` provides the default concrete implementation of the
   * `test_reporter` abstract interface, formatting and presenting test results
   * using `printf`-based output. It accumulates output in an internal string
   * buffer and writes it to the standard output stream, supporting
   * colour-coded diagnostics and multiple verbosity levels.
   *
   * Users who require custom output behaviour (e.g. redirecting to a serial
   * port on bare-metal targets) may derive a new class from `test_reporter`
   * and supply an instance via the `reporter` global pointer before calling
   * `initialize()`.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class test_reporter_basic final : public test_reporter
  {
  public:
    /**
     * @brief Default constructor for the test_reporter_basic class.
     *
     * @details
     * The rule of five is enforced to prevent accidental copying or moving.
     */
    test_reporter_basic () = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    test_reporter_basic (const test_reporter_basic&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    test_reporter_basic (test_reporter_basic&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    test_reporter_basic&
    operator= (const test_reporter_basic&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_reporter_basic&
    operator= (test_reporter_basic&&)
        = delete;

    /**
     * @brief Destructor for the test_reporter_basic class.
     */
    ~test_reporter_basic () override = default;

    /**
     * @brief Inserts a line ending into the output buffer.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    endline (void) override;

    /**
     * @brief Mark the beginning of a test case.
     *
     * @param name The name of the test case.
     * @par Returns
     *   Nothing.
     */
    void
    begin_test_case (const char* name) override;

    /**
     * @brief Mark the end of a test case.
     *
     * @param name The name of the test case.
     * @par Returns
     *   Nothing.
     */
    void
    end_test_case (const char* name) override;

    /**
     * @brief Mark the beginning of a test suite.
     *
     * @param name The name of the test suite.
     * @par Returns
     *   Nothing.
     */
    void
    begin_test_suite (const char* name) override;

    /**
     * @brief Mark the end of a test suite.
     *
     * @param suite Reference to the test suite base.
     * @par Returns
     *   Nothing.
     */
    void
    end_test_suite (test_suite_base& suite) override;

    /**
     * @brief Mark the beginning of a test.
     *
     * @param test_suites_count The number of test suites, or zero if unknown.
     * @par Returns
     *   Nothing.
     */
    void
    begin_test (size_t test_suites_count) override;

    /**
     * @brief Mark the end of a test.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    void
    end_test (test_runner& runner) override;

    /**
     * @brief Flush the current buffered content.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    flush (void) override;

    /**
     * @brief Output the current buffered content.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    output (void) override;

  protected:
    /**
     * @brief Outputs the prefix for a passing condition.
     *
     * @param message The message to display.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_prefix_ (std::string& message) override;

    /**
     * @brief Outputs the suffix for a passing condition.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_suffix_ (void) override;

    /**
     * @brief Outputs the prefix for a failing condition.
     *
     * @param message The message to display.
     * @param location The source location of the failure.
     * @par Returns
     *   Nothing.
     */
    void
    output_fail_prefix_ (std::string& message,
                         const reflection::source_location& location) override;

    /**
     * @brief Outputs the suffix for a failing condition.
     *
     * @param abort Whether to abort execution after failure.
     * @par Returns
     *   Nothing.
     */
    void
    output_fail_suffix_ (bool abort) override;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_REPORTER_BASIC_H_

// ----------------------------------------------------------------------------

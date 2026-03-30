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

// =============================================================================

namespace micro_os_plus::micro_test_plus2
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
   * `micro_os_plus::micro_test_plus2` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class test_reporter_basic final : public test_reporter
  {
  public:
    /**
     * @brief Constructor for the test_reporter_basic class.
     *
     * @details
     * The rule of five is enforced to prevent accidental copying or moving.
     */
    test_reporter_basic ();

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
    operator= (const test_reporter_basic&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    test_reporter_basic&
    operator= (test_reporter_basic&&) = delete;

    /**
     * @brief Destructor for the test_reporter_basic class.
     */
    ~test_reporter_basic () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Output operator for the `indent_t` manipulator.
     *
     * @param m The indentation manipulator produced by `indent(n)`.
     * @return Reference to the current test_reporter instance.
     */
    test_reporter_basic&
    operator<< (indent_t m);

    // Bring base class operator<< overloads into scope to prevent name hiding.
    using test_reporter::operator<<;

    // ------------------------------------------------------------------------

    /**
     * @brief Mark the beginning of a test.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    void
    begin_test (test_runner& runner) override;

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
     * @brief Mark the beginning of a test suite.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    void
    begin_test_suite (test_suite_base& suite) override;

    /**
     * @brief Mark the end of a test suite.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    void
    end_test_suite (test_suite_base& suite) override;

    /**
     * @brief Mark the beginning of a test case.
     *
     * @param test_case Reference to the test case.
     * @par Returns
     *   Nothing.
     */
    void
    begin_test_case (test_case_base& test_case) override;

    /**
     * @brief Mark the end of a test case.
     *
     * @param test_case Reference to the test case.
     * @par Returns
     *   Nothing.
     */
    void
    end_test_case (test_case_base& test_case) override;

  protected:
    /**
     * @brief Outputs the prefix for a passing condition.
     *
     * @param message The message to display.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_prefix_ (std::string& message,
                         test_case_base& test_case) override;

    /**
     * @brief Outputs the suffix for a passing condition.
     *
     * @par Parameters
     *	 None.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_suffix_ (test_case_base& test_case) override;

    /**
     * @brief Outputs the prefix for a failing condition.
     *
     * @param message The message to display.
     * @param hasExpression Whether the failure is associated with an
     * expression.
     * @param location The source location of the failure.
     * @par Returns
     *   Nothing.
     */
    void
    output_fail_prefix_ (std::string& message, const bool hasExpression,
                         const reflection::source_location& location,
                         test_case_base& test_case) override;

    /**
     * @brief Outputs the suffix for a failing condition.
     *
     * @param location The source location of the failure.
     * @param abort Whether to abort execution after failure.
     * @par Returns
     *   Nothing.
     */
    void
    output_fail_suffix_ (const reflection::source_location& location,
                         bool abort, test_case_base& test_case) override;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus2

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_REPORTER_BASIC_H_

// ----------------------------------------------------------------------------

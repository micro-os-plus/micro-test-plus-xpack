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
 * @brief C++ header file with declarations for the µTest++ TAP test reporter.
 *
 * @details
 * This header provides the declaration for `reporter_tap`, a concrete
 * implementation of the `reporter` abstract interface that formats test
 * results according to the Test Anything Protocol (TAP).
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace, since the reporters
 * are internal to the framework.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_TAP_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_TAP_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "reporter.h"
#include "reflection.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus::detail
{
  // ==========================================================================

  /**
   * @brief TAP (Test Anything Protocol) implementation of `reporter`.
   *
   * @details
   * `reporter_tap` provides a concrete implementation of the
   * `reporter` abstract interface that formats test results according to
   * the Test Anything Protocol (TAP). It accumulates output in an internal
   * string buffer and writes it to the standard output stream.
   *
   * The reporter is created by the runner, as selected by the
   * `--reporter` command-line option. A different output format requires
   * a new class derived from `reporter`, and an extension of the runner
   * to create it.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus::detail` namespace, since the reporters
   * are internal to the framework.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class reporter_tap final : public reporter
  {
  public:
    /**
     * @brief Constructor for the reporter_tap class.
     *
     * @param opts The session options, passed to `runner::initialise()`
     * or parsed by it from the command line.
     */
    explicit reporter_tap (const runner_options& opts);

    /**
     * @brief Deleted copy constructor to prevent copying.
     *
     * @details
     * The reporter owns the output buffer and the output file, which
     * must not be shared.
     */
    reporter_tap (const reporter_tap&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     *
     * @details
     * The reporter is owned by the runner, through a pointer, and is
     * never relocated.
     */
    reporter_tap (reporter_tap&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     *
     * @details
     * The reporter owns the output buffer and the output file, which
     * must not be shared.
     */
    reporter_tap&
    operator= (const reporter_tap&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     *
     * @details
     * The reporter is owned by the runner, through a pointer, and is
     * never relocated.
     */
    reporter_tap&
    operator= (reporter_tap&&)
        = delete;

    /**
     * @brief Destructor for the reporter_tap class.
     *
     * @details
     * The output file, if any, is closed by the base class destructor.
     */
    ~reporter_tap () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Output operator for the `indent_t` manipulator.
     *
     * @param m The indentation manipulator produced by `indent(n)`.
     * @return Reference to the current reporter instance.
     */
    reporter_tap&
    operator<< (indent_t m);

    // Bring base class operator<< overloads into scope to prevent name hiding.
    using reporter::operator<<;

    // ------------------------------------------------------------------------

    /**
     * @brief Mark the beginning of a test session.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    void
    begin_session (runner& runner) override;

    /**
     * @brief Mark the end of a test session.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    void
    end_session (runner& runner) override;

    /**
     * @brief Mark the beginning of a test suite.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    virtual void
    begin_suite (suite& suite) override;

    /**
     * @brief Mark the end of a test suite.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    virtual void
    end_suite (suite& suite) override;

    /**
     * @brief Report a test suite skipped by the filter.
     *
     * @details
     * Displays an `ok <index> - <name> # SKIP filtered` line, instead of
     * the suite body and results.
     *
     * @param suite Reference to the skipped test suite.
     * @par Returns
     *   Nothing.
     */
    virtual void
    skip_suite (suite& suite) override;

    /**
     * @brief Mark the beginning of a test case.
     *
     * @param test_case Reference to the test case.
     * @par Returns
     *   Nothing.
     */
    virtual void
    begin_test_case (test_case& test_case) override;

    /**
     * @brief Mark the end of a test case.
     *
     * @param test_case Reference to the test case.
     * @par Returns
     *   Nothing.
     */
    virtual void
    end_test_case (test_case& test_case) override;

    /**
     * @brief Report a test case skipped by the filter.
     *
     * @details
     * Displays an `ok <index> - <name> # SKIP filtered` line,
     * indented by its nesting depth.
     *
     * @param test_case Reference to the skipped test case.
     * @par Returns
     *   Nothing.
     */
    virtual void
    skip_test_case (test_case& test_case) override;

    /**
     * @brief Returns the TAP comment prefix string `"# "`.
     *
     * @par Parameters
     *   None.
     * @return The string `"# "`, used to prefix comment lines in TAP
     * output.
     */
    virtual const char*
    get_comment_prefix (void) override;

  protected:
    /**
     * @brief Outputs the prefix for a passing condition.
     *
     * @param message The message to display.
     * @param test_case The test case that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_prefix_ (std::string& message, test_case& test_case) override;

    /**
     * @brief Outputs the suffix for a passing condition.
     *
     * @param test_case The test case that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_suffix_ (test_case& test_case) override;

    /**
     * @brief Outputs the prefix for a failing condition.
     *
     * @param message The message to display.
     * @param has_expression Whether the failure is associated with an
     * expression.
     * @param location The source location of the failure.
     * @param test_case The test case that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    output_fail_prefix_ (std::string& message, const bool has_expression,
                         const reflection::source_location& location,
                         test_case& test_case) override;

    /**
     * @brief Outputs the suffix for a failing condition.
     *
     * @param location The source location of the failure.
     * @param abort Whether to abort execution after failure.
     * @param test_case The test case that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    output_fail_suffix_ (const reflection::source_location& location,
                         bool abort, test_case& test_case) override;

    /**
     * @brief Writes the results buffered for the outer test case before
     * a nested test case begins.
     *
     * @details
     * Keeps the TAP stream in execution order, with the checks of the
     * outer test case before the nested test case, as node-tap does.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    commit_buffer_ (void);
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_TAP_H_

// ----------------------------------------------------------------------------

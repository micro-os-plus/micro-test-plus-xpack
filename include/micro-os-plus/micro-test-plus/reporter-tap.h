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
     * @brief Mark the beginning of a test session.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    void
    begin_session (const runner& runner) override;

    /**
     * @brief Mark the end of a test session.
     *
     * @param runner Reference to the test runner.
     * @par Returns
     *   Nothing.
     */
    void
    end_session (const runner& runner) override;

    /**
     * @brief Mark the beginning of a test suite.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    void
    begin_suite (const suite& suite) override;

    /**
     * @brief Mark the end of a test suite.
     *
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    void
    end_suite (const suite& suite) override;

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
    void
    skip_suite (const suite& suite) override;

    /**
     * @brief Report a failure of a test suite outside its test cases.
     *
     * @details
     * Adds a `not ok <n> - <message>` test point, at the indentation of
     * the test cases, to the output buffer, which `end_suite()` displays.
     *
     * @param message The message to display.
     * @param suite Reference to the test suite.
     * @par Returns
     *   Nothing.
     */
    void
    fail_suite (const std::string& message, const suite& suite) override;

    /**
     * @brief Mark the beginning of a test case.
     *
     * @param test_case Reference to the test case.
     * @par Returns
     *   Nothing.
     */
    void
    begin_test_case (const test_case& test_case) override;

    /**
     * @brief Mark the end of a test case.
     *
     * @param test_case Reference to the test case.
     * @par Returns
     *   Nothing.
     */
    void
    end_test_case (const test_case& test_case) override;

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
    void
    skip_test_case (const test_case& test_case) override;

    /**
     * @brief Report the abort of the test execution.
     *
     * @details
     * Displays the buffered check results, followed by a `Bail out!`
     * line with the location of the failed requirement, or of the
     * `runner::abort()` call.
     *
     * @param location The source location of the failed requirement,
     * or of the `runner::abort()` call.
     * @param is_requirement `true` if the abort is caused by a failed
     * requirement.
     * @par Returns
     *   Nothing.
     */
    void
    abort_session (const reflection::source_location& location,
                   bool is_requirement) override;

    /**
     * @brief Returns the TAP comment prefix string `"# "`.
     *
     * @par Parameters
     *   None.
     * @return The string `"# "`, used to prefix comment lines in TAP
     * output.
     */
    const char*
    comment_prefix (void) const override;

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
    output_pass_prefix_ (const std::string& message,
                         const test_case& test_case) override;

    /**
     * @brief Outputs the suffix for a passing condition.
     *
     * @param test_case The test case that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    output_pass_suffix_ (const test_case& test_case) override;

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
    output_fail_prefix_ (const std::string& message, const bool has_expression,
                         const reflection::source_location& location,
                         const test_case& test_case) override;

    /**
     * @brief Outputs the suffix for a failing condition.
     *
     * @param location The source location of the failure.
     * @param kind The kind of the check; not used, since a failed
     * requirement is reported like any other failed check.
     * @param test_case The test case that owns this check.
     * @par Returns
     *   Nothing.
     */
    void
    output_fail_suffix_ (const reflection::source_location& location,
                         check_kind kind, const test_case& test_case) override;

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

    /**
     * @brief The position in the buffer where the description of a
     * passed check begins.
     *
     * @details
     * Set by `output_pass_prefix_()` and used by `output_pass_suffix_()`
     * to escape the description, which is the message, or the expression
     * appended between the two calls when there is no message.
     */
    size_t description_begin_ = 0;

    /**
     * @brief The position in the buffer where the expression of a
     * failed check begins.
     *
     * @details
     * Set by `output_fail_prefix_()`, after the `condition:` key, and
     * used by `output_fail_suffix_()` to write the expression appended
     * between the two calls as a YAML double-quoted scalar. It is
     * `std::string::npos` when the failure has no expression.
     */
    size_t condition_begin_ = std::string::npos;
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

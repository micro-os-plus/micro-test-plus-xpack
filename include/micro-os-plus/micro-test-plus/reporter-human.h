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
 * @brief C++ header file with declarations for the µTest++ human test
 * reporter.
 *
 * @details
 * This header provides the declaration for `reporter_human`, a concrete
 * implementation of the `reporter` abstract interface, selected with the
 * `--reporter=human` command-line option (the default is TAP). It
 * formats and presents test results in a human-readable form on the
 * standard output, accumulating output in an internal string buffer and
 * supporting colour-coded diagnostics and multiple verbosity levels.
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_HUMAN_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_HUMAN_H_

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
   * @brief Human (standard output) implementation of `reporter`.
   *
   * @details
   * `reporter_human` provides a concrete implementation of the `reporter`
   * abstract interface, formatting and presenting test results in a
   * human-readable form. It accumulates output in an internal string
   * buffer and writes it to the standard output stream, supporting
   * colour-coded diagnostics (when the output is a terminal) and multiple
   * verbosity levels.
   *
   * The reporter is intended for the people who read the console output.
   * Most writes to the optional output file follow the console verbosity,
   * so the file receives the full report only with normal or verbose
   * verbosity; for the integration with other tools, the TAP reporter,
   * whose output file is always complete, is the one to use.
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
  class reporter_human final : public reporter
  {
  public:
    /**
     * @brief Constructor for the reporter_human class.
     *
     * @param opts The session options, passed to `runner::initialise()`
     * or parsed by it from the command line.
     */
    explicit reporter_human (const runner_options& opts);

    /**
     * @brief Deleted copy constructor to prevent copying.
     *
     * @details
     * The reporter owns the output buffer and the output file, which
     * must not be shared.
     */
    reporter_human (const reporter_human&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     *
     * @details
     * The reporter is owned by the runner, through a pointer, and is
     * never relocated.
     */
    reporter_human (reporter_human&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     *
     * @details
     * The reporter owns the output buffer and the output file, which
     * must not be shared.
     */
    reporter_human&
    operator= (const reporter_human&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     *
     * @details
     * The reporter is owned by the runner, through a pointer, and is
     * never relocated.
     */
    reporter_human&
    operator= (reporter_human&&)
        = delete;

    /**
     * @brief Destructor for the reporter_human class.
     *
     * @details
     * The output file, if any, is closed by the base class destructor.
     */
    ~reporter_human () override;

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
     * @brief Mark the beginning of a suite.
     *
     * @param suite Reference to the suite.
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
     * Displays a `"• <name> - skipped (filtered)"` line, instead of the
     * suite body and results.
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
     * Adds a `"✗ <message> FAILED"` line, at the indentation of the
     * test cases, to the output buffer, which `end_suite()` displays.
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
     * Displays a `"• <name> - skipped (filtered)"` line,
     * indented by its nesting depth.
     *
     * @param test_case Reference to the skipped test case.
     * @par Returns
     *   Nothing.
     */
    void
    skip_test_case (const test_case& test_case) override;

    /**
     * @brief Report a test case stopped by a failed requirement.
     *
     * @details
     * Displays the names of the open test cases not yet displayed,
     * followed by the buffered check results.
     *
     * @param location The source location of the failed requirement.
     * @param test_case Reference to the stopped test case.
     * @par Returns
     *   Nothing.
     */
    void
    abort_test_case (const reflection::source_location& location,
                     const test_case& test_case) override;

    /**
     * @brief Returns an empty comment prefix string.
     *
     * @par Parameters
     *   None.
     * @return An empty string, as the human-readable format does not
     * use a comment prefix.
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
     * @param kind The kind of the check; for `check_kind::requirement`,
     * the effect that follows (the test case is stopped, or the test
     * execution is aborted) is displayed.
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
     * Keeps the report in execution order, with the checks of the outer
     * test case before the nested test case.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    commit_buffer_ (void);

    /**
     * @brief Displays the names of the open test cases not yet displayed.
     *
     * @details
     * With normal verbosity, the test case names are displayed only for
     * failures; a failure in a nested test case also fails the outer ones,
     * so their names are displayed first, outermost first, to show where
     * the failure is.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    display_open_names_ (void);

    /**
     * @brief A test case that has begun and not yet ended.
     *
     * @details
     * Recorded by `begin_test_case()` and removed by `end_test_case()`.
     */
    struct open_test_case
    {
      /**
       * @brief The test case.
       *
       * @details
       * Used to display its name when its results are committed.
       */
      const test_case* test;

      /**
       * @brief Whether the name of the test case was displayed.
       *
       * @details
       * Always true with verbose verbosity; with normal verbosity, set
       * when failed results are committed before a nested test case, so
       * that `end_test_case()` does not display the name again.
       */
      bool name_displayed;
    };

    /**
     * @brief The test cases that have begun and not yet ended, outermost
     * first.
     *
     * @details
     * The last element is the test case that owns the buffered results.
     */
    std::vector<open_test_case> open_test_cases_{};
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_REPORTER_HUMAN_H_

// ----------------------------------------------------------------------------

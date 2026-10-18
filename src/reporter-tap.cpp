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
 * @brief C++ source file with implementations for the µTest++ TAP test
 * reporter methods.
 *
 * @details
 * This source file contains the implementations for `reporter_tap`,
 * a concrete implementation of the `reporter` abstract interface that
 * formats test results according to the Test Anything Protocol (TAP),
 * version 14. It is the default reporter, also selected with the
 * `--reporter=tap` command-line option.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace, since the reporters
 * are internal to the framework.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/reporter-tap.h"
#include "micro-os-plus/micro-test-plus/runner.h"
#include "micro-os-plus/micro-test-plus/test.h"
#include "micro-os-plus/micro-test-plus/utility.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus::detail
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * Delegates construction to the `reporter` base class with the supplied
   * options. If tracing is enabled, the function signature is
   * output for diagnostic purposes.
   */
  reporter_tap::reporter_tap (const runner_options& opts) : reporter{ opts }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * No resources are owned directly by `reporter_tap`; the destructor
   * performs no explicit clean-up. If tracing is enabled, the function
   * signature is output for diagnostic purposes.
   */
  reporter_tap::~reporter_tap ()
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * If verbosity is not silent, emits a blank line to `stdout` and then
   * calls `write_info_()` to output build and environment information.
   * The TAP version header `"TAP version 14"` is then written to the
   * output file (if open) and, unless verbosity is silent, to `stdout`.
   * The `add_empty_line_` flag
   * is cleared so that the first suite header is not separated by an
   * extra blank line.
   */
  void
  reporter_tap::begin_session ([[maybe_unused]] const runner& runner)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (verbosity_ != verbosity::silent)
      {
        write_console_ ("\n");
      }

    write_info_ ();

    const char* message = "TAP version 14";
    write_file_ ("%s\n", message);

    if (verbosity_ != verbosity::silent)
      {
        write_console_ ("%s\n", message);

        flush_streams ();
      }

    add_empty_line_ = false;
  }

  /**
   * @details
   * Emits the TAP plan line (`1..N`, where N is the total number of test
   * suites) followed by a comment line summarising successful checks,
   * failed checks, executed test cases, suite count, and elapsed time.
   * The numbers of test cases and of suites skipped by the filter follow
   * the respective counts, only when not zero.
   * Both lines are written to the output file when one is open, and,
   * unless verbosity is silent, to `stdout`. With quiet verbosity, the
   * plan matches the `ok`/`not ok` lines of the suites displayed by
   * `end_suite()` and `skip_suite()`, so that the console output is a
   * complete TAP document, which node-tap and the other TAP consumers
   * read as failed when a suite failed; no empty line precedes it.
   */
  void
  reporter_tap::end_session (const runner& runner)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    size_t total_suites_count = runner.total_suites_count ();

    char message_summary[32];
    snprintf (message_summary, sizeof (message_summary), "1..%zu",
              total_suites_count);

    char message_skipped_test_cases[40] = "";
    if (runner.totals ().skipped_test_cases () > 0)
      {
        snprintf (message_skipped_test_cases,
                  sizeof (message_skipped_test_cases), ", %zu skipped",
                  runner.totals ().skipped_test_cases ());
      }

    char message_skipped_suites[40] = "";
    if (runner.skipped_suites_count () > 0)
      {
        snprintf (message_skipped_suites, sizeof (message_skipped_suites),
                  ", %zu skipped", runner.skipped_suites_count ());
      }

    char message_totals[240];
    snprintf (message_totals, sizeof (message_totals),
              "total: %zu check%s passed, %zu failed, in %zu test "
              "case%s%s, %zu test suite%s%s",
              runner.totals ().successful_checks (),
              runner.totals ().successful_checks () == 1 ? "" : "s",
              runner.totals ().failed_checks (),
              runner.totals ().executed_test_cases (),
              runner.totals ().executed_test_cases () == 1 ? "" : "s",
              message_skipped_test_cases, total_suites_count,
              total_suites_count == 1 ? "" : "s", message_skipped_suites);

    char message_time[elapsed_time_size_];
    format_elapsed_time_ (runner.stopwatch_, message_time);

    write_file_ ("%s\n# { %s%s }\n", message_summary, message_totals,
                 message_time);

    if (verbosity_ != verbosity::silent)
      {
        if (add_empty_line_ && verbosity_ != verbosity::quiet)
          {
            write_console_ ("\n");
          }

        write_console_ ("%s\n# { %s%s }\n", message_summary, message_totals,
                        message_time);

        flush_streams ();
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Emits a `"# Subtest: <name>"` comment line to mark the start of a
   * TAP test case block for the suite. The line is written to the output
   * file when one is open. Under normal or verbose verbosity, it is also
   * written to `stdout`, preceded by a blank line when `add_empty_line_`
   * is set.
   */
  void
  reporter_tap::begin_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    write_file_ ("# Subtest: %s\n", suite.name ());

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("# Subtest: %s\n", suite.name ());

        flush_streams ();

        add_empty_line_ = true;
      }
  }

  /**
   * @details
   * Emits the TAP plan line for the suite's test cases, and for the
   * failure of the suite body, if any (see `fail_suite()`), followed by an
   * `ok`/`not ok` result line that includes the suite index, name,
   * pass/fail status, check counts, test case count, and elapsed time.
   * Any output accumulated in `buffer_` is written to the output file
   * and, with normal or verbose verbosity, when verbosity is verbose or
   * the suite failed, to `stdout` as well; the plan and result lines are
   * written to `stdout` with normal or verbose verbosity. With quiet
   * verbosity, only the result line is written to `stdout`, without the
   * plan and without an empty line, so that the session plan written by
   * `end_session()` counts the displayed lines. The buffer is cleared on
   * exit.
   */
  void
  reporter_tap::end_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf (
        "%s '%s' +%zu -%zu in xc%zu, xs%zu | cs%zu\n", __PRETTY_FUNCTION__,
        suite.name (), suite.totals ().successful_checks (),
        suite.totals ().failed_checks (), suite.totals ().executed_checks (),
        suite.totals ().executed_test_cases (),
        suite.child_test_cases_count ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    std::string indent (indent_size_, ' ');

    // The test cases skipped by the filter, only when not zero.
    char message_skipped[40] = "";
    if (suite.totals ().skipped_test_cases () > 0)
      {
        snprintf (message_skipped, sizeof (message_skipped), ", %zu skipped",
                  suite.totals ().skipped_test_cases ());
      }

    // The name is not included, since its length is not bounded; it is
    // passed to each write.
    const char* result;
    char message_totals[160];
    if (suite.totals ().passed ()) [[likely]]
      {
        result = "ok";
        snprintf (message_totals, sizeof (message_totals),
                  "# { passed, %zu check%s in %zu test case%s%s",
                  suite.totals ().successful_checks (),
                  suite.totals ().successful_checks () == 1 ? "" : "s",
                  suite.totals ().executed_test_cases (),
                  suite.totals ().executed_test_cases () == 1 ? "" : "s",
                  message_skipped);
      }
    else
      {
        result = "not ok";
        snprintf (message_totals, sizeof (message_totals),
                  "# { FAILED, %zu check%s passed, %zu failed, in %zu "
                  "test case%s%s",
                  suite.totals ().successful_checks (),
                  suite.totals ().successful_checks () == 1 ? "" : "s",
                  suite.totals ().failed_checks (),
                  suite.totals ().executed_test_cases (),
                  suite.totals ().executed_test_cases () == 1 ? "" : "s",
                  message_skipped);
      }

    char message_time[elapsed_time_size_];
    format_elapsed_time_ (suite.stopwatch_, message_time);

    write_buffer_to_file_ ();

    // The plan counts the test cases and the failure of the suite body,
    // if any, which is numbered after them.
    write_file_ ("%s1..%zu\n%s %zu - %s %s%s }\n", indent.c_str (),
                 suite.test_point_number (), result, suite.own_index (),
                 suite.name (), message_totals, message_time);

    // At this point, the buffer may contain output from the test case, which
    // should be displayed.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_ && suite.totals ().executed_test_cases () > 0)
          {
            write_console_ ("\n");
          }

        if (suite.totals ().passed ()) [[likely]]
          {
            // Successful test suite.

            if (verbosity_ == verbosity::verbose)
              {
                // With verbosity, show full TAP output accumulated in the
                // buffer.
                write_buffer_to_console ();
              }
          }
        else
          {
            // Failed test suite.

            // Show full TAP output accumulated in the buffer for failed suite
            // cases, as it may contain useful information about the failure.
            write_buffer_to_console ();
          }

        write_console_ ("%s1..%zu\n%s %zu - %s %s%s }\n", indent.c_str (),
                        suite.test_point_number (), result, suite.own_index (),
                        suite.name (), message_totals, message_time);

        flush_streams ();
      }
    else if (verbosity_ == verbosity::quiet)
      {
        // Only the test point of the suite, counted by the session plan.
        write_console_ ("%s %zu - %s %s%s }\n", result, suite.own_index (),
                        suite.name (), message_totals, message_time);

        flush_streams ();
      }

    clear_buffer_ ();

    add_empty_line_ = true;
  }

  /**
   * @details
   * Emits an `ok <index> - <name> # SKIP filtered` line, without a
   * test case block, so that the suite keeps its place in the TAP plan of
   * the session. The line is written to the output file when one is
   * open. Unless verbosity is silent, it is also written to `stdout`;
   * under normal or verbose verbosity, it is preceded by a blank line when
   * `add_empty_line_` is set. With quiet verbosity, it is written as the
   * result lines of `end_suite()`, which the session plan counts.
   */
  void
  reporter_tap::skip_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    write_file_ ("ok %zu - %s # SKIP filtered\n", suite.own_index (),
                 suite.name ());

    if (verbosity_ != verbosity::silent)
      {
        if (add_empty_line_ && verbosity_ != verbosity::quiet)
          {
            write_console_ ("\n");
          }

        write_console_ ("ok %zu - %s # SKIP filtered\n", suite.own_index (),
                        suite.name ());

        flush_streams ();
      }

    add_empty_line_ = true;
  }

  /**
   * @details
   * Adds a `not ok <n> - <message>` line to the output buffer, indented
   * as the test cases of the suite, where `<n>` is the current test point
   * number of the suite, which follows the test cases already run, and is
   * therefore counted in the plan of the suite. Since there is no source
   * location, no YAML diagnostics block follows. The line is displayed by
   * `end_suite()`, with the other buffered output of the failed suite.
   */
  void
  reporter_tap::fail_suite (const std::string& message, const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    *this << indent (1) << "not ok " << suite.test_point_number () << " - "
          << message << endl;

    buffer_has_failures_ = true;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * For a nested test case, the results of the checks already performed by
   * the outer test case, if any, are written first (see `commit_buffer_()`),
   * so that the output follows the execution order. For a top-level
   * test case, the output buffer must be empty; if it is not, the buffer is
   * written to `stdout`, the stream is flushed, and execution is aborted
   * with `runner::abort()`, which calls the handler set by
   * `runner::set_abort_handler()`, if any.
   *
   * A `"# Subtest: <name>"` comment line (indented according to nesting
   * depth) is then written to the output file and, under normal or
   * verbose verbosity, to `stdout` as well.
   */
  void
  reporter_tap::begin_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (!buffer_.empty ())
      {
        if (test_case.nesting_depth () > 1)
          {
            // The outer test case performed checks before this nested one.
            commit_buffer_ ();
          }
        else
          {
            // Each top-level test case should start with an empty buffer.
            write_buffer_to_console ();
            flush_streams ();
            test_case.abort ();
          }
      }

    std::string indent (indent_size_ * test_case.nesting_depth (), ' ');

    write_file_ ("%s# Subtest: %s\n", indent.c_str (), test_case.name ());

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("%s# Subtest: %s\n", indent.c_str (),
                        test_case.name ());

        flush_streams ();

        add_empty_line_ = false;
      }
  }

  /**
   * @details
   * Emits the TAP plan line for the test case's checks and nested test cases,
   * followed by an `ok`/`not ok` result line that includes the test case
   * index, name, pass/fail status, and check counts. As in node-tap, the
   * result is `not ok` when a check or a nested test case failed; the number
   * of failed nested test cases is added when it is not zero. Any output
   * accumulated in `buffer_` is written to the output file and, with
   * normal or verbose verbosity, when verbosity is verbose or the test case
   * failed, to `stdout` as well. With normal verbosity, for a passing
   * test case, the plan written to `stdout` counts only the nested test cases,
   * since the individual check lines are not displayed. The buffer is
   * cleared on exit.
   */
  void
  reporter_tap::end_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s' i%zu +%zu -%zu in xc%zu, xs%zu | cs%zu\n",
                   __PRETTY_FUNCTION__, test_case.name (),
                   test_case.nesting_depth (),
                   test_case.totals ().successful_checks (),
                   test_case.totals ().failed_checks (),
                   test_case.totals ().executed_checks (),
                   test_case.totals ().executed_test_cases (),
                   test_case.child_test_cases_count ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    std::string indent (indent_size_ * test_case.nesting_depth (), ' ');
    std::string indent2 (indent_size_ * (test_case.nesting_depth () + 1), ' ');

    // The nested test cases skipped by the filter keep their index, and are
    // counted in the plan.
    size_t plan_count = test_case.totals ().executed_checks ()
                        + test_case.totals ().executed_test_cases ()
                        + test_case.totals ().skipped_test_cases ();

    // The name and the indentation are not included, since their lengths
    // are not bounded; they are passed to each write.
    const char* result;
    char message_totals[160];
    if (test_case.totals ().passed ()) [[likely]]
      {
        result = "ok";
        snprintf (message_totals, sizeof (message_totals),
                  "# { passed, %zu check%s }",
                  test_case.totals ().successful_checks (),
                  test_case.totals ().successful_checks () == 1 ? "" : "s");
      }
    else
      {
        // The nested failures are mentioned only when present, since a
        // test case may fail because of a nested one alone.
        char message_test_cases[48] = "";
        if (test_case.totals ().failed_test_cases () > 0)
          {
            snprintf (message_test_cases, sizeof (message_test_cases),
                      ", %zu test case%s failed",
                      test_case.totals ().failed_test_cases (),
                      test_case.totals ().failed_test_cases () == 1 ? ""
                                                                    : "s");
          }

        result = "not ok";
        snprintf (message_totals, sizeof (message_totals),
                  "# { FAILED, %zu check%s passed, %zu failed%s }",
                  test_case.totals ().successful_checks (),
                  test_case.totals ().successful_checks () == 1 ? "" : "s",
                  test_case.totals ().failed_checks (), message_test_cases);
      }

    write_buffer_to_file_ ();

    write_file_ ("%s1..%zu\n%s%s %zu - %s %s\n", indent2.c_str (), plan_count,
                 indent.c_str (), result, test_case.own_index (),
                 test_case.name (), message_totals);

    // At this point, the buffer may contain output from the test case, which
    // should be displayed.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        if (test_case.totals ().passed ()) [[likely]]
          {
            // Successful test case.
            if (verbosity_ == verbosity::verbose)
              {
                // With verbosity, show full TAP output accumulated in the
                // buffer.
                write_buffer_to_console ();

                write_console_ ("%s1..%zu\n", indent2.c_str (), plan_count);
              }
            else
              {
                // Without verbosity, show only the summary line
                // and count only test cases, not checks, as the TAP output is
                // not shown.
                write_console_ (
                    "%s1..%zu\n", indent2.c_str (),
                    test_case.totals ().executed_test_cases ()
                        + test_case.totals ().skipped_test_cases ());
              }
          }
        else
          {
            // Failed test case.

            // Show full TAP output accumulated in the buffer for failed
            // test cases, as it may contain useful information about the
            // failure.
            write_buffer_to_console ();

            write_console_ ("%s1..%zu\n", indent2.c_str (), plan_count);
          }

        write_console_ ("%s%s %zu - %s %s\n", indent.c_str (), result,
                        test_case.own_index (), test_case.name (),
                        message_totals);

        flush_streams ();
      }

    clear_buffer_ ();

    add_empty_line_ = true;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Returns `"# "`. The TAP reporter prefixes all comment lines,
   * including the informational lines emitted by `write_info_()`, with
   * the TAP comment marker.
   */
  const char*
  reporter_tap::comment_prefix (void) const
  {
    return "# ";
  }

  /**
   * @details
   * This method outputs the prefix for a passing check result, as a TAP
   * `"ok <n> - "` line, where `<n>` is the index of the check within the
   * test case, indented one level deeper than the test case, followed by the
   * message, if provided. No colours are used.
   *
   * The prefix/suffix methods help shorten the code
   * generated by the template methods.
   */
  void
  reporter_tap::output_pass_prefix_ (const std::string& message,
                                     const test_case& test_case)
  {
    size_t level = test_case.nesting_depth ();
    *this << indent (level + 1) << "ok " << test_case.test_point_number ()
          << " - ";
    if (!message.empty ())
      {
        *this << message;
      }
  }

  /**
   * @details
   * Completes the pass output by appending `endl`, which adds a line
   * ending to the buffer, and flushes the output streams.
   *
   * The prefix/suffix methods help shorten the code
   * generated by the template methods.
   */
  void
  reporter_tap::output_pass_suffix_ (
      [[maybe_unused]] const test_case& test_case)
  {
    *this << endl;

    flush_streams ();
  }

  /**
   * @details
   * This method outputs the prefix for a failing check result, as a TAP
   * `"not ok <n>"` line, indented one level deeper than the test case,
   * followed by the message, if provided. It then opens the TAP 14 YAML
   * diagnostics block (`---`) and, when the failure has an expression,
   * starts a `condition:` field, so that the expression follows on the
   * same line. No colours are used.
   */
  void
  reporter_tap::output_fail_prefix_ (
      const std::string& message, const bool has_expression,
      [[maybe_unused]] const reflection::source_location& location,
      const test_case& test_case)
  {
    size_t level = test_case.nesting_depth ();
    *this << indent (level + 1) << "not ok " << test_case.test_point_number ();

    if (!message.empty ())
      {
        *this << " - " << message;
      }
    *this << endl;

    // https://testanything.org/tap-version-14-specification.html
    // 2-space indentation for YAML diagnostics.
    *this << indent (level + 1) << "  ---";
    if (has_expression)
      {
        *this << endl;
        *this << indent (level + 1) << "  condition: ";
      }
  }

  /**
   * @details
   * Completes TAP14 YAML diagnostics for a failing check, appends an
   * "aborted..." marker if the check is a requirement, emits source
   * filename/line fields, closes the YAML block, and flushes the stream.
   */
  void
  reporter_tap::output_fail_suffix_ (
      const reflection::source_location& location, check_kind kind,
      const test_case& test_case)
  {
    size_t level = test_case.nesting_depth ();
    if (kind == check_kind::requirement)
      {
        *this << " aborted...";
      }
    *this << endl;

    // https://testanything.org/tap-version-14-specification.html
    // 2-space indentation for YAML diagnostics.

    *this << indent (level + 1) << "  at:" << endl;
    *this << indent (level + 1) << "    filename: "
          << utility::extract_file_name (location.file_name ()) << endl;
    *this << indent (level + 1) << "    line: " << location.line () << endl;

    *this << indent (level + 1) << "  ..." << endl;

    flush_streams ();
  }

  /**
   * @details
   * As in `begin_test_case()`, for a nested test case, the results of the
   * checks already performed by the outer test case, if any, are written
   * first (see `commit_buffer_()`), so that the output follows the
   * execution order; for a top-level test case, the output buffer must be
   * empty, otherwise execution is aborted.
   *
   * An `ok <index> - <name> # SKIP filtered` line, indented according to
   * the nesting depth, without a test case block, is then written to the
   * output file and, under normal or verbose verbosity, to `stdout`,
   * preceded by a blank line when `add_empty_line_` is set.
   */
  void
  reporter_tap::skip_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (!buffer_.empty ())
      {
        if (test_case.nesting_depth () > 1)
          {
            // The outer test case performed checks before this nested one.
            commit_buffer_ ();
          }
        else
          {
            // Each top-level test case should start with an empty buffer.
            write_buffer_to_console ();
            flush_streams ();
            test_case.abort ();
          }
      }

    std::string indent (indent_size_ * test_case.nesting_depth (), ' ');

    write_file_ ("%sok %zu - %s # SKIP filtered\n", indent.c_str (),
                 test_case.own_index (), test_case.name ());

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("%sok %zu - %s # SKIP filtered\n", indent.c_str (),
                        test_case.own_index (), test_case.name ());

        flush_streams ();
      }

    add_empty_line_ = true;
  }

  /**
   * @details
   * Since `end_test_case()` is not called for the stopped test case, this
   * method writes the buffered lines, which end with the failed
   * requirement, in its place, followed by an unindented
   * `Bail out! Requirement failed at <file>:<line>` line, which tells the
   * TAP consumers that the run stopped early (see the TAP 14
   * specification), not that the output was truncated.
   *
   * Both are always written to the output file, as in `end_test_case()`,
   * and, unless the verbosity is silent, to `stdout`, preceded by an empty
   * line when `add_empty_line_` is set. With quiet verbosity, which
   * otherwise displays only the summary, they are displayed as well, since
   * the summary is never reached.
   */
  void
  reporter_tap::abort_test_case (const reflection::source_location& location,
                                 [[maybe_unused]] const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    // The type of `line()` depends on the toolchain (`uint_least32_t` for
    // `std::source_location`); widen it implicitly, without a cast that
    // would be useless on some platforms.
    const unsigned long line = location.line ();
    const char* file_name = utility::extract_file_name (location.file_name ());

    write_buffer_to_file_ ();

    write_file_ ("Bail out! Requirement failed at %s:%lu\n", file_name, line);

    if (verbosity_ != verbosity::silent)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_buffer_to_console ();

        write_console_ ("Bail out! Requirement failed at %s:%lu\n", file_name,
                        line);
      }

    flush_streams ();
  }

  /**
   * @details
   * The buffered `ok`/`not ok` lines of the outer test case are written to
   * the output file and, with verbose verbosity, or with normal verbosity
   * when they include a failure, to `stdout`, preceded by an empty line
   * when `add_empty_line_` is set. The buffer is then cleared, so that
   * the nested test case starts with an empty buffer, and the remaining
   * lines of the outer test case are written by its `end_test_case()`.
   *
   * With normal verbosity, the passed checks committed here are not
   * displayed, even if the outer test case fails later; the output file
   * always contains them.
   */
  void
  reporter_tap::commit_buffer_ (void)
  {
    write_buffer_to_file_ ();

    if (verbosity_ == verbosity::verbose
        || (verbosity_ == verbosity::normal && buffer_has_failures_))
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
            add_empty_line_ = false;
          }

        write_buffer_to_console ();
      }

    flush_streams ();

    clear_buffer_ ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

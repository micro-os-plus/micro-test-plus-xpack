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

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

// For the PRIu32 macro used in snprintf() formatting of uint32_t values.
#include <cinttypes>

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

  constexpr size_t indent_size = 4;

  /**
   * @details
   * This operator overload appends spaces to the internal output buffer
   * corresponding to `m.level` four-space indentation levels, allowing
   * `*this << indent(n) << "text"` chaining; four spaces is the TAP 14
   * test case indentation.
   */
  reporter_tap&
  reporter_tap::operator<< (indentation m)
  {
    buffer_.append (m.level * indent_size, ' ');
    return *this;
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
   * unless verbosity is silent, to `stdout`. When verbosity is set to
   * quiet, the plan written to `stdout` is replaced by `1..0`, since no
   * `ok`/`not ok` lines were displayed, producing a valid skipped-test TAP
   * document.
   */
  void
  reporter_tap::end_session (const runner& runner)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    size_t total_suites_count = runner.total_suites_count ();

    uint32_t milliseconds = 0;
    uint32_t microseconds = 0;
    if (runner.stopwatch_.has_elapsed ())
      {
        const auto elapsed = runner.stopwatch_.elapsed ().count ();
        milliseconds = static_cast<uint32_t> (elapsed / 1000);
        microseconds = static_cast<uint32_t> (elapsed % 1000);
      }

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

    char message_time[120] = "";
    if (milliseconds > 0 || microseconds > 0)
      {
        snprintf (message_time, sizeof (message_time),
                  ", time: %" PRIu32 ".%03" PRIu32 " ms", milliseconds,
                  microseconds);
      }

    write_file_ ("%s\n# { %s%s }\n", message_summary, message_totals,
                 message_time);

    if (verbosity_ != verbosity::silent)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        if (verbosity_ != verbosity::quiet)
          {
            write_console_ ("%s\n", message_summary);
          }
        else
          {
            // With quiet verbosity, there are no ok/not ok lines, so the TAP
            // plan should look like a skipped test.
            write_console_ ("1..0\n");
          }

        write_console_ ("# { %s%s }\n", message_totals, message_time);

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

    char message_test_case[120];
    snprintf (message_test_case, sizeof (message_test_case), "# Subtest: %s",
              suite.name ());

    write_file_ ("%s\n", message_test_case);

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("%s\n", message_test_case);

        flush_streams ();

        add_empty_line_ = true;
      }
  }

  /**
   * @details
   * Emits the TAP plan line for the suite's test cases followed by an
   * `ok`/`not ok` result line that includes the suite index, name,
   * pass/fail status, check counts, test case count, and elapsed time.
   * Any output accumulated in `buffer_` is written to the output file
   * and, with normal or verbose verbosity, when verbosity is verbose or
   * the suite failed, to `stdout` as well; the plan and result lines are
   * written to `stdout` only with normal or verbose verbosity. The buffer
   * is cleared on exit.
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

    uint32_t milliseconds = 0;
    uint32_t microseconds = 0;
    if (suite.stopwatch_.has_elapsed ())
      {
        const auto elapsed = suite.stopwatch_.elapsed ().count ();
        milliseconds = static_cast<uint32_t> (elapsed / 1000);
        microseconds = static_cast<uint32_t> (elapsed % 1000);
      }

    std::string indent (indent_size, ' ');

    char message_summary[40];
    snprintf (message_summary, sizeof (message_summary), "%s1..%zu",
              indent.c_str (), suite.child_test_cases_count ());

    // The test cases skipped by the filter, only when not zero.
    char message_skipped[40] = "";
    if (suite.totals ().skipped_test_cases () > 0)
      {
        snprintf (message_skipped, sizeof (message_skipped), ", %zu skipped",
                  suite.totals ().skipped_test_cases ());
      }

    char message_totals[160];
    if (suite.totals ().passed ()) [[likely]]
      {
        snprintf (message_totals, sizeof (message_totals),
                  "ok %zu - %s # { passed, %zu check%s in %zu "
                  "test case%s%s",
                  suite.own_index (), suite.name (),
                  suite.totals ().successful_checks (),
                  suite.totals ().successful_checks () == 1 ? "" : "s",
                  suite.totals ().executed_test_cases (),
                  suite.totals ().executed_test_cases () == 1 ? "" : "s",
                  message_skipped);
      }
    else
      {
        snprintf (message_totals, sizeof (message_totals),
                  "not ok %zu - %s # { FAILED, %zu check%s "
                  "passed, %zu failed, in %zu test case%s%s",
                  suite.own_index (), suite.name (),
                  suite.totals ().successful_checks (),
                  suite.totals ().successful_checks () == 1 ? "" : "s",
                  suite.totals ().failed_checks (),
                  suite.totals ().executed_test_cases (),
                  suite.totals ().executed_test_cases () == 1 ? "" : "s",
                  message_skipped);
      }

    char message_time[120] = "";
    if (milliseconds > 0 || microseconds > 0)
      {
        snprintf (message_time, sizeof (message_time),
                  ", time: %" PRIu32 ".%03" PRIu32 " ms", milliseconds,
                  microseconds);
      }

    write_buffer_to_file_ ();

    write_file_ ("%s\n%s%s }\n", message_summary, message_totals,
                 message_time);

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

            write_console_ ("%s\n%s%s }\n", message_summary, message_totals,
                            message_time);
          }
        else
          {
            // Failed test suite.

            // Show full TAP output accumulated in the buffer for failed suite
            // cases, as it may contain useful information about the failure.
            write_buffer_to_console ();

            write_console_ ("%s\n%s%s }\n", message_summary, message_totals,
                            message_time);
          }

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
   * open. Under normal or verbose verbosity, it is also written to
   * `stdout`, preceded by a blank line when `add_empty_line_` is set.
   */
  void
  reporter_tap::skip_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    char message_skipped[160];
    snprintf (message_skipped, sizeof (message_skipped),
              "ok %zu - %s # SKIP filtered", suite.own_index (),
              suite.name ());

    write_file_ ("%s\n", message_skipped);

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("%s\n", message_skipped);

        flush_streams ();
      }

    add_empty_line_ = true;
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

    std::string indent (indent_size * test_case.nesting_depth (), ' ');

    char message_test_case[120];
    snprintf (message_test_case, sizeof (message_test_case), "%s# Subtest: %s",
              indent.c_str (), test_case.name ());

    write_file_ ("%s\n", message_test_case);

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("%s\n", message_test_case);

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

    std::string indent (indent_size * test_case.nesting_depth (), ' ');
    std::string indent2 (indent_size * (test_case.nesting_depth () + 1), ' ');

    char message_summary[40];
    // The nested test cases skipped by the filter keep their index, and are
    // counted in the plan.
    snprintf (message_summary, sizeof (message_summary), "%s1..%zu",
              indent2.c_str (),
              test_case.totals ().executed_checks ()
                  + test_case.totals ().executed_test_cases ()
                  + test_case.totals ().skipped_test_cases ());

    char message_totals[300];
    if (test_case.totals ().passed ()) [[likely]]
      {
        snprintf (message_totals, sizeof (message_totals),
                  "%sok %zu - %s # { passed, %zu check%s }", indent.c_str (),
                  test_case.own_index (), test_case.name (),
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

        snprintf (message_totals, sizeof (message_totals),
                  "%snot ok %zu - %s # { FAILED, %zu check%s "
                  "passed, %zu failed%s }",
                  indent.c_str (), test_case.own_index (), test_case.name (),
                  test_case.totals ().successful_checks (),
                  test_case.totals ().successful_checks () == 1 ? "" : "s",
                  test_case.totals ().failed_checks (), message_test_cases);
      }

    write_buffer_to_file_ ();

    write_file_ ("%s\n%s\n", message_summary, message_totals);

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

                write_console_ ("%s\n", message_summary);
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

            write_console_ ("%s\n", message_totals);
          }
        else
          {
            // Failed test case.

            // Show full TAP output accumulated in the buffer for failed
            // test cases, as it may contain useful information about the
            // failure.
            write_buffer_to_console ();

            write_console_ ("%s\n%s\n", message_summary, message_totals);
          }

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
    *this << indent (level + 1) << "ok "
          << static_cast<int> (test_case.test_point_number ()) << " - ";
    if (!message.empty ())
      {
        *this << message.c_str ();
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
    *this << indent (level + 1) << "not ok "
          << static_cast<int> (test_case.test_point_number ());

    if (!message.empty ())
      {
        *this << " - " << message.c_str ();
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
    *this << indent (level + 1)
          << "    filename: " << reflection::short_name (location.file_name ())
          << endl;
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

    std::string indent (indent_size * test_case.nesting_depth (), ' ');

    char message_skipped[160];
    snprintf (message_skipped, sizeof (message_skipped),
              "%sok %zu - %s # SKIP filtered", indent.c_str (),
              test_case.own_index (), test_case.name ());

    write_file_ ("%s\n", message_skipped);

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("%s\n", message_skipped);

        flush_streams ();
      }

    add_empty_line_ = true;
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

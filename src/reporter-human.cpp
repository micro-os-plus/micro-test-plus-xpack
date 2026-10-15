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
 * @brief C++ source file with implementations for the µTest++ human test
 * reporter methods.
 *
 * @details
 * This source file contains the implementations for `reporter_human`,
 * the concrete implementation of the `reporter` abstract interface that
 * presents test results in a human-readable form on the standard output,
 * accumulating output in an internal string buffer and supporting
 * colour-coded diagnostics and multiple verbosity levels.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace, since the reporters
 * are internal to the framework.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/reporter-human.h"
#include "micro-os-plus/micro-test-plus/runner.h"
#include "micro-os-plus/micro-test-plus/test.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

// For the PRIu32 macro used in snprintf() formatting of uint32_t values.
#include <cinttypes>

#if defined(__APPLE__) || defined(__linux__) || defined(__unix__)
// For isatty() to detect if stdout is a terminal, enabling colour output.
#include <unistd.h>
#endif // defined(__APPLE__) || defined(__linux__) || defined(__unix__)

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
   * options. On POSIX platforms, if `stdout` is connected to a
   * terminal (`isatty()`), colour output is enabled by selecting the
   * red/green colour scheme. If tracing is enabled, the function
   * signature is output for diagnostic purposes.
   */
  reporter_human::reporter_human (const runner_options& opts)
      : reporter{ opts }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

#if defined(__APPLE__) || defined(__linux__) || defined(__unix__)
    if (isatty (fileno (stdout)))
      {
        colours_ = colours_red_green;
      }
#endif // defined(__APPLE__) || defined(__linux__) || defined(__unix__)
  }

  /**
   * @details
   * No resources are owned directly by `reporter_human`; the destructor
   * performs no explicit clean-up. If tracing is enabled, the function
   * signature is output for diagnostic purposes.
   */
  reporter_human::~reporter_human ()
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  // --------------------------------------------------------------------------

  /**
   * @brief Number of spaces per indentation level.
   *
   * @details
   * Used by `operator<<(indentation)` and related methods to compute
   * the leading whitespace for each nesting depth.
   */
  constexpr size_t indent_size = 4;

  /**
   * @details
   * This operator overload appends spaces to the internal output buffer
   * corresponding to `m.level` four-space indentation levels, allowing
   * `*this << indent(n) << "text"` chaining.
   */
  reporter_human&
  reporter_human::operator<< (indentation m)
  {
    buffer_.append (m.level * indent_size, ' ');
    return *this;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * If verbosity is not silent, a blank line is printed to `stdout`
   * before the build-information block emitted by `write_info_()`. A
   * fixed "µTest++ human report" heading is then written to the output
   * file (if open) and, unless verbosity is silent, to `stdout`. The
   * `add_empty_line_` flag is set so that subsequent suite output is
   * visually separated.
   */
  void
  reporter_human::begin_session ([[maybe_unused]] runner& runner)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (verbosity_ != verbosity::silent)
      {
        write_console_ ("\n");
      }

    write_info_ ();

    const char* message = "µTest++ human report";
    write_file_ ("%s\n", message);

    if (verbosity_ != verbosity::silent)
      {
        write_console_ ("%s\n", message);

        flush_streams ();
      }

    add_empty_line_ = true;
  }

  /**
   * @details
   * Unless verbosity is silent, prints a summary line to `stdout` (and to
   * the output file if open) showing the total number of successful
   * checks, failed checks, executed test cases, and test suites, each
   * count followed by the number skipped by the filter (only when not
   * zero), together with the elapsed time when timing data is
   * available. The line is
   * prefixed with a green `✓` tick on success or a red `✗` cross on
   * failure, using ANSI colour codes when colour output is enabled.
   */
  void
  reporter_human::end_session (runner& runner)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (verbosity_ != verbosity::silent)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        size_t total_suites_count = runner.total_suites_count ();

        uint32_t milliseconds = 0;
        uint32_t microseconds = 0;
        if (runner.stopwatch_.has_elapsed ())
          {
            const auto elapsed = runner.stopwatch_.elapsed ().count ();
            milliseconds = static_cast<uint32_t> (elapsed / 1000);
            microseconds = static_cast<uint32_t> (elapsed % 1000);
          }

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

        char message_totals[300];
        snprintf (message_totals, sizeof (message_totals),
                  "Total: %zu check%s passed, %zu failed, in %zu test "
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

        if (runner.totals ().passed ()) [[likely]]
          {
            write_file_ ("✓ %s%s\n", message_totals, message_time);

            write_console_ ("%s✓%s %s%s\n", colours_.pass, colours_.none,
                            message_totals, message_time);
          }
        else
          {
            write_file_ ("✗ %s%s\n", message_totals, message_time);

            write_console_ ("%s✗%s %s%s\n", colours_.fail, colours_.none,
                            message_totals, message_time);
          }

        flush_streams ();
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * With normal or verbose verbosity, this method writes a `"• <name>"`
   * line, marking the beginning of the test suite, to the output file (if
   * open) and to `stdout`, preceded on `stdout` by an empty line when
   * `add_empty_line_` is set. For silent or quiet verbosity levels, no
   * output is produced.
   */
  void
  reporter_human::begin_suite (suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_file_ ("• %s\n", suite.name ());

        write_console_ ("• %s\n", suite.name ());

        flush_streams ();

        add_empty_line_ = true;
      }
  }

  /**
   * @details
   * With normal or verbose verbosity, this method summarises the results of
   * the test suite, with appropriate formatting and colour coding; for
   * silent or quiet verbosity levels, no output is produced. An empty line
   * is first added if the suite executed any test cases.
   *
   * For suites without failed checks, a `"✓ <name> - passed"` line is
   * displayed, including the number of checks and test cases; the buffered
   * check results are written to `stdout` only with verbose verbosity.
   * Otherwise, a `"✗ <name> - FAILED"` line is shown, detailing the number
   * of successful and failed checks and the number of test cases, preceded
   * by the buffered check results. The buffered results are always written
   * to the output file. The elapsed time is appended when available.
   *
   * Finally, the streams are flushed and the buffer is cleared.
   */
  void
  reporter_human::end_suite (suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    uint32_t milliseconds = 0;
    uint32_t microseconds = 0;
    if (suite.stopwatch_.has_elapsed ())
      {
        const auto elapsed = suite.stopwatch_.elapsed ().count ();
        milliseconds = static_cast<uint32_t> (elapsed / 1000);
        microseconds = static_cast<uint32_t> (elapsed % 1000);
      }

    char message_time[120] = "";
    if (milliseconds > 0 || microseconds > 0)
      {
        snprintf (message_time, sizeof (message_time),
                  ", time: %" PRIu32 ".%03" PRIu32 " ms", milliseconds,
                  microseconds);
      }

    // At this point, the buffer may contain output from the test case, which
    // should be displayed.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        std::string indent (indent_size, ' ');

        // The test cases skipped by the filter, only when not zero.
        char message_skipped[40] = "";
        if (suite.totals ().skipped_test_cases () > 0)
          {
            snprintf (message_skipped, sizeof (message_skipped),
                      ", %zu skipped", suite.totals ().skipped_test_cases ());
          }

        if (suite.totals ().executed_test_cases () > 0)
          {
            write_console_ ("\n");
          }

        if (suite.totals ().passed ()) [[likely]]
          {
            // Successful test suite.

            char message_totals[300];
            snprintf (message_totals, sizeof (message_totals),
                      "(%zu check%s in %zu test case%s%s)",
                      suite.totals ().successful_checks (),
                      suite.totals ().successful_checks () == 1 ? "" : "s",
                      suite.totals ().executed_test_cases (),
                      suite.totals ().executed_test_cases () == 1 ? "" : "s",
                      message_skipped);

            write_buffer_to_file_ ();

            write_file_ ("✓ %s - passed %s%s\n", suite.name (), message_totals,
                         message_time);

            if (verbosity_ == verbosity::verbose)
              {
                // With verbosity, show full TAP output accumulated in the
                // buffer.
                write_buffer_to_console ();
              }

            write_console_ ("%s✓%s %s - passed %s%s\n", colours_.pass,
                            colours_.none, suite.name (), message_totals,
                            message_time);
          }
        else
          {
            // Failed test suite.

            char message_totals[300];
            snprintf (message_totals, sizeof (message_totals),
                      "(%zu check%s passed, %zu "
                      "failed, in %zu test case%s%s)",
                      suite.totals ().successful_checks (),
                      suite.totals ().successful_checks () == 1 ? "" : "s",
                      suite.totals ().failed_checks (),
                      suite.totals ().executed_test_cases (),
                      suite.totals ().executed_test_cases () == 1 ? "" : "s",
                      message_skipped);

            write_buffer_to_file_ ();

            write_file_ ("✗ %s - FAILED %s%s\n", suite.name (), message_totals,
                         message_time);

            // Show full TAP output accumulated in the buffer for failed suite
            // cases, as it may contain useful information about the failure.
            write_buffer_to_console ();

            write_console_ ("%s✗%s %s - %sFAILED%s %s%s\n", colours_.fail,
                            colours_.none, suite.name (), colours_.fail,
                            colours_.none, message_totals, message_time);
          }
      }

    flush_streams ();

    // Clear residual content when less verbose.
    clear_buffer_ ();

    add_empty_line_ = true;
  }

  /**
   * @details
   * With normal or verbose verbosity, this method writes a
   * `"• <name> - skipped (filtered)"` line, instead of the suite body and
   * results, to the output file (if open) and to `stdout`, preceded on
   * `stdout` by an empty line when `add_empty_line_` is set. For silent
   * or quiet verbosity levels, no output is produced.
   */
  void
  reporter_human::skip_suite (suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_file_ ("• %s - skipped (filtered)\n", suite.name ());

        write_console_ ("• %s - skipped (filtered)\n", suite.name ());

        flush_streams ();

        add_empty_line_ = true;
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * This method marks the beginning of a test case. For a nested test
   * case, the results of the checks already performed by the outer test
   * case, if any, are written first (see `commit_buffer_()`), so that the
   * output follows the execution order. For a top-level test case, the
   * output buffer must be empty; if it is not, its content is written to
   * `stderr` and execution is aborted with `runner::abort()`, which calls
   * the handler set by `runner::set_abort_handler()`, if any.
   *
   * A `"• <name>"` line, indented according to the nesting depth, is
   * written to the output file (if open) and, with verbose verbosity, to
   * `stdout`, preceded by an empty line when `add_empty_line_` is set.
   */
  void
  reporter_human::begin_test_case (test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (!buffer_.empty ())
      {
        if (test_case.nesting_depth () > 1 && !open_test_cases_.empty ())
          {
            // The outer test case performed checks before this nested one.
            commit_buffer_ ();
          }
        else
          {
            // Each top-level test case should start with an empty buffer.
            fprintf (stderr,
                     "Buffer not empty at the beginning of a test case:\n"
                     "%s\n",
                     buffer_.c_str ());
            flush_streams ();
            test_case.abort ();
          }
      }

    open_test_cases_.push_back (
        { &test_case, verbosity_ == verbosity::verbose });

    std::string indent (indent_size * test_case.nesting_depth (), ' ');

    write_file_ ("%s• %s\n", indent.c_str (), test_case.name ());

    if (verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("%s• %s\n", indent.c_str (), test_case.name ());

        add_empty_line_ = false;
      }

    flush_streams ();
  }

  /**
   * @details
   * With normal or verbose verbosity, this method summarises the outcome of
   * the test case, with appropriate formatting and colour coding; for
   * silent or quiet verbosity levels, no output is produced.
   *
   * For passing test cases, a `"✓ <name> - passed"` line is shown with the
   * number of checks; the buffered check results are written to `stdout`
   * only with verbose verbosity. A test case fails when one of its checks
   * or one of its nested test cases failed. For failing test cases, the
   * buffered check results are always shown (preceded, with normal
   * verbosity, by the names of the test case and of the outer test cases,
   * if not already displayed), followed by a `"✗ <name> - FAILED"` line
   * with the number of successful and failed checks, and of the failed
   * nested test cases, when not zero. The buffered results are always
   * written to the output file.
   *
   * Finally, the streams are flushed and the buffer is cleared.
   */
  void
  reporter_human::end_test_case (test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s' i%zu\n", __PRETTY_FUNCTION__, test_case.name (),
                   test_case.nesting_depth ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    // At this point, the buffer may contain output from the test case, which
    // should be displayed.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        std::string indent (indent_size * test_case.nesting_depth (), ' ');
        std::string indent2 (indent_size * (test_case.nesting_depth () + 1),
                             ' ');

        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        if (test_case.totals ().passed ()) [[likely]]
          {
            // Successful test case.

            char message_totals[300];
            snprintf (message_totals, sizeof (message_totals),
                      "%s - passed (%zu check%s)", test_case.name (),
                      test_case.totals ().successful_checks (),
                      test_case.totals ().successful_checks () == 1 ? ""
                                                                    : "s");

            write_buffer_to_file_ ();

            write_file_ ("%s✓ %s\n", indent.c_str (), message_totals);

            if (verbosity_ == verbosity::verbose)
              {
                // With verbosity, show full TAP output accumulated in the
                // buffer.
                write_buffer_to_console ();

                write_console_ ("%s%s✓%s %s\n", indent.c_str (), colours_.pass,
                                colours_.none, message_totals);

                add_empty_line_ = true;
              }
            else
              {
                write_console_ ("%s%s✓%s %s\n", indent.c_str (), colours_.pass,
                                colours_.none, message_totals);

                add_empty_line_ = false;
              }
          }
        else
          {
            // Failed test case.

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

            char message_totals[300];
            snprintf (message_totals, sizeof (message_totals),
                      "(%zu check%s passed, %zu failed%s)",
                      test_case.totals ().successful_checks (),
                      test_case.totals ().successful_checks () == 1 ? "" : "s",
                      test_case.totals ().failed_checks (),
                      message_test_cases);

            write_buffer_to_file_ ();

            write_file_ ("%s✗ %s - FAILED %s\n", indent.c_str (),
                         test_case.name (), message_totals);

            if (verbosity_ == verbosity::normal)
              {
                // This test case and the outer ones, whose names may have
                // been displayed already, by `commit_buffer_()` or by a
                // failed sibling.
                display_open_names_ ();
              }

            // Show full output accumulated in the buffer for failed
            // test cases, as it may contain useful information about the
            // failure.
            write_buffer_to_console ();

            write_console_ ("%s%s✗%s %s - %sFAILED%s %s\n", indent.c_str (),
                            colours_.fail, colours_.none, test_case.name (),
                            colours_.fail, colours_.none, message_totals);

            add_empty_line_ = true;
          }
      }

    flush_streams ();

    // Clear residual content when less verbose.
    clear_buffer_ ();

    if (!open_test_cases_.empty ())
      {
        open_test_cases_.pop_back ();
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Returns an empty string. The human reporter does not prefix comment
   * lines; the `write_info_()` output appears as plain text.
   */
  const char*
  reporter_human::comment_prefix (void) const
  {
    return "";
  }

  /**
   * @details
   * This method outputs the prefix for a passing check result, indented one
   * level deeper than the test case. The prefix includes a tick symbol
   * (`✓`), in the pass colour, and, if provided, the associated message.
   * Colour formatting is reset immediately after the symbol.
   *
   * The prefix/suffix methods help shorten the code
   * generated by the template methods.
   */
  void
  reporter_human::output_pass_prefix_ (std::string& message,
                                       test_case& test_case)
  {
    size_t level = test_case.nesting_depth ();

    *this << indent (level + 1);
    *this << colours_.pass << "✓" << colours_.none << " ";
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
  reporter_human::output_pass_suffix_ ([[maybe_unused]] test_case& test_case)
  {
    *this << endl;

    flush_streams ();
  }

  /**
   * @details
   * This method outputs the prefix for a failing check result, indented one
   * level deeper than the test case. The prefix includes a cross symbol
   * (`✗`), an optional message, and the label "FAILED", both symbol and
   * label in the fail colour. The source location (file name and line
   * number) follows, after an opening parenthesis; when the failure has an
   * expression, a comma separator is added, so that the expression follows
   * inside the parentheses.
   */
  void
  reporter_human::output_fail_prefix_ (
      std::string& message, const bool has_expression,
      const reflection::source_location& location, test_case& test_case)
  {
#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wsign-conversion"
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wnarrowing"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

    size_t level = test_case.nesting_depth ();

    *this << indent (level + 1);
    *this << colours_.fail << "✗" << colours_.none << " ";
    if (!message.empty ())
      {
        *this << message.c_str ();
        *this << " ";
      }
    *this << colours_.fail << "FAILED" << colours_.none;
    *this << " (" << reflection::short_name (location.file_name ()) << ":"
          << location.line ();
    if (has_expression)
      {
        *this << ", ";
      }
  }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

  /**
   * @details
   * This method outputs the suffix for a failing check result by closing the
   * parenthesis, appending an "aborted..." message if the check was
   * aborted, and then appending `endl`, which adds a line ending, and
   * flushes the output streams.
   */
  void
  reporter_human::output_fail_suffix_ (
      [[maybe_unused]] const reflection::source_location& location, bool abort,
      [[maybe_unused]] test_case& test_case)
  {
    *this << ")";
    if (abort)
      {
        *this << " aborted...";
      }
    *this << endl;

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
   * With normal or verbose verbosity, a `"• <name> - skipped (filtered)"`
   * line, indented according to the nesting depth, is then written to the
   * output file (if open) and to `stdout`, preceded on `stdout` by an
   * empty line when `add_empty_line_` is set. For silent or quiet
   * verbosity levels, no output is produced.
   */
  void
  reporter_human::skip_test_case (test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (!buffer_.empty ())
      {
        if (test_case.nesting_depth () > 1 && !open_test_cases_.empty ())
          {
            // The outer test case performed checks before this nested one.
            commit_buffer_ ();
          }
        else
          {
            // Each top-level test case should start with an empty buffer.
            fprintf (stderr,
                     "Buffer not empty at the beginning of a test case:\n"
                     "%s\n",
                     buffer_.c_str ());
            flush_streams ();
            test_case.abort ();
          }
      }

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        std::string indent (indent_size * test_case.nesting_depth (), ' ');

        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_file_ ("%s• %s - skipped (filtered)\n", indent.c_str (),
                     test_case.name ());

        write_console_ ("%s• %s - skipped (filtered)\n", indent.c_str (),
                        test_case.name ());

        // As for a passed test case.
        add_empty_line_ = (verbosity_ == verbosity::verbose);
      }

    flush_streams ();
  }

  /**
   * @details
   * The buffered results of the outer test case are written to the output
   * file, with normal or verbose verbosity (as `end_test_case()` does), and,
   * with verbose verbosity, to `stdout`. With normal verbosity,
   * they are written to `stdout` only when they include a failure,
   * preceded by the name of the outer test case, which this verbosity
   * otherwise displays only when the test case ends. The buffer is then
   * cleared, so that the nested test case starts with an empty buffer,
   * and the remaining results of the outer test case are written by its
   * `end_test_case()`.
   *
   * With normal verbosity, the passed checks committed here are not
   * displayed, even if the outer test case fails later; the output file
   * always contains them.
   */
  void
  reporter_human::commit_buffer_ (void)
  {
    // As in `end_test_case()`, the results reach the output file only with
    // normal or verbose verbosity.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        write_buffer_to_file_ ();
      }

    if (verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
            add_empty_line_ = false;
          }

        write_buffer_to_console ();
      }
    else if (verbosity_ == verbosity::normal && buffer_has_failures_)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        display_open_names_ ();

        write_buffer_to_console ();

        add_empty_line_ = true;
      }

    flush_streams ();

    clear_buffer_ ();
  }

  /**
   * @details
   * Walks `open_test_cases_` from the outermost test case and displays, on
   * `stdout`, the indented `"• <name>"` line of each one whose name was
   * not displayed yet, marking it as displayed. An empty line is written
   * before the first name, unless `add_empty_line_` is set, in which case
   * the caller has already written it.
   */
  void
  reporter_human::display_open_names_ (void)
  {
    bool is_first = true;
    for (open_test_case& open : open_test_cases_)
      {
        if (open.name_displayed)
          {
            continue;
          }

        if (is_first && !add_empty_line_)
          {
            write_console_ ("\n");
          }
        is_first = false;

        std::string indent (indent_size * open.test->nesting_depth (), ' ');
        write_console_ ("%s• %s\n", indent.c_str (), open.test->name ());

        open.name_displayed = true;
      }
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

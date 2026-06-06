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
 * @brief C++ source file with implementations for the µTest++ TAP suite
 * reporter methods.
 *
 * @details
 * This source file contains the implementations for `reporter_tap`,
 * a concrete implementation of the `reporter` abstract interface that
 * formats suite results according to the Test Anything Protocol (TAP).
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

// For the PRIu32 macro used in snprintf() formatting of uint32_t values.
#include <cinttypes>

#if __has_include(<micro-os-plus/config.h>)
#include <micro-os-plus/config.h>
#endif // __has_include(<micro-os-plus/config.h>)

#if defined(MICRO_OS_PLUS_TRACE)
#include <micro-os-plus/diag/trace.h>
#endif // MICRO_OS_PLUS_TRACE

#include "micro-os-plus/micro-test-plus/reporter-tap.h"
#include "micro-os-plus/micro-test-plus/runner.h"
#include "micro-os-plus/micro-test-plus/test.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// =============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * Delegates construction to the `reporter` base class with the supplied
   * argument vector. If tracing is enabled, the function signature is
   * output for diagnostic purposes.
   */
  reporter_tap::reporter_tap (
      std::unique_ptr<std::vector<std::string_view>> argvs)
      : reporter{ std::move (argvs) }
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  /**
   * @details
   * No resources are owned directly by `reporter_tap`; the destructor
   * performs no explicit clean-up. If tracing is enabled, the function
   * signature is output for diagnostic purposes.
   */
  reporter_tap::~reporter_tap ()
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  // --------------------------------------------------------------------------

  constexpr size_t indent_size = 4;

  /**
   * @details
   * This operator overload appends spaces to the internal output buffer
   * corresponding to `m.level` four-space indentation levels. It enables
   * structured, readable nesting of suite output across all test cases and
   * folders by allowing `*this << indent(n) << "text"` chaining.
   */
  reporter_tap&
  reporter_tap::operator<< (detail::indent_t m)
  {
    buffer_.append (m.level * indent_size, ' ');
    return *this;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * If verbosity is not silent, emits a blank line to `stdout` and then
   * calls `write_info_()` to output build and environment information.
   * The TAP version header `"TAP version 14"` is then written to both
   * the output file (if open) and `stdout`. The `add_empty_line_` flag
   * is cleared so that the first suite header is not separated by an
   * extra blank line.
   */
  void
  reporter_tap::begin_session ([[maybe_unused]] runner& runner)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif

    if (verbosity_ != verbosity::silent)
      {
        printf ("\n");
      }

    write_info_ ();

    const char* message = "TAP version 14";
    if (output_file_ != nullptr)
      {
        fprintf (output_file_, "%s\n", message);
      }

    if (verbosity_ != verbosity::silent)
      {
        printf ("%s\n", message);

        flush ();
      }

    add_empty_line_ = false;

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
  }

  /**
   * @details
   * Emits the TAP plan line (`1..N`, where N is the total number of test
   * suites) followed by a comment line summarising successful checks,
   * failed checks, executed test cases, elapsed time, and suite count.
   * Both lines are written to the output file when one is open. When
   * verbosity is set to quiet, the plan is replaced by `1..0` to
   * produce a valid skipped-test TAP document.
   */
  void
  reporter_tap::end_session (runner& runner)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif

    size_t total_suites_count = runner.total_suites_count ();

    uint32_t milliseconds = 0;
    uint32_t microseconds = 0;
    if (runner.timings ().has_timestamps ())
      {
        runner.timings ().compute_elapsed_time (milliseconds, microseconds);
      }

    char message_summary[32];
    snprintf (message_summary, sizeof (message_summary), "1..%zu",
              total_suites_count);

    char message_totals[160];
    snprintf (message_totals, sizeof (message_totals),
              "total: %zu check%s passed, %zu failed, in %zu test "
              "case%s, %zu test suite%s",
              runner.totals ().successful_checks (),
              runner.totals ().successful_checks () == 1 ? "" : "s",
              runner.totals ().failed_checks (),
              runner.totals ().executed_subtests (),
              runner.totals ().executed_subtests () == 1 ? "" : "s",
              total_suites_count, total_suites_count == 1 ? "" : "s");

    char message_time[120] = "";
    if (milliseconds > 0 || microseconds > 0)
      {
        snprintf (message_time, sizeof (message_time),
                  ", time: %" PRIu32 ".%03" PRIu32 " ms", milliseconds,
                  microseconds);
      }

    if (output_file_ != nullptr)
      {
        fprintf (output_file_, "%s\n# { %s%s }\n", message_summary,
                 message_totals, message_time);
      }

    if (verbosity_ != verbosity::silent)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

        if (verbosity_ != verbosity::quiet)
          {
            printf ("%s\n", message_summary);
          }
        else
          {
            // With quiet verbosity, there are no ok/not ok lines, so the TAP
            // plan should look like a skipped test.
            printf ("1..0\n");
          }

        printf ("# { %s%s }\n", message_totals, message_time);

        flush ();
      }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Emits a `"# Subtest: <name>"` comment line to mark the start of a
   * TAP subtest block for the suite. The line is written to the output
   * file when one is open. Under normal or verbose verbosity, it is also
   * written to `stdout`, preceded by a blank line when `add_empty_line_`
   * is set.
   */
  void
  reporter_tap::begin_suite (suite& suite)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif

    char message_subtest[120];
    snprintf (message_subtest, sizeof (message_subtest), "# Subtest: %s",
              suite.name ());

    if (output_file_ != nullptr)
      {
        fprintf (output_file_, "%s\n", message_subtest);
      }

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

        printf ("%s\n", message_subtest);

        flush ();

        add_empty_line_ = true;
      }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
  }

  /**
   * @details
   * Emits the TAP plan line for the suite's subtests followed by an
   * `ok`/`not ok` result line that includes the suite index, name,
   * pass/fail status, check counts, subtest count, and elapsed time.
   * Any output accumulated in `buffer_` is flushed to the output file
   * and, when verbosity is verbose or the suite failed, to `stdout`
   * as well. The buffer is cleared on exit.
   */
  void
  reporter_tap::end_suite (suite& suite)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    trace::printf (
        "%s '%s' +%zu -%zu in xc%zu, xs%zu | cs%zu\n", __PRETTY_FUNCTION__,
        suite.name (), suite.totals ().successful_checks (),
        suite.totals ().failed_checks (), suite.totals ().executed_checks (),
        suite.totals ().executed_subtests (),
        suite.children_subtests_count ());

#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif

    uint32_t milliseconds = 0;
    uint32_t microseconds = 0;
    if (suite.timings ().has_timestamps ())
      {
        suite.timings ().compute_elapsed_time (milliseconds, microseconds);
      }

    std::string indent (indent_size, ' ');

    char message_summary[40];
    snprintf (message_summary, sizeof (message_summary), "%s1..%zu",
              indent.c_str (), suite.children_subtests_count ());
    char message_totals[120];
    if (suite.totals ().was_successful ()) [[likely]]
      {
        snprintf (message_totals, sizeof (message_totals),
                  "ok %zu - %s # { passed, %zu check%s in %zu "
                  "test case%s",
                  suite.own_index (), suite.name (),
                  suite.totals ().successful_checks (),
                  suite.totals ().successful_checks () == 1 ? "" : "s",
                  suite.totals ().executed_subtests (),
                  suite.totals ().executed_subtests () == 1 ? "" : "s");
      }
    else
      {
        snprintf (message_totals, sizeof (message_totals),
                  "not ok %zu - %s # { FAILED, %zu check%s "
                  "passed, %zu failed, in %zu test case%s",
                  suite.own_index (), suite.name (),
                  suite.totals ().successful_checks (),
                  suite.totals ().successful_checks () == 1 ? "" : "s",
                  suite.totals ().failed_checks (),
                  suite.totals ().executed_subtests (),
                  suite.totals ().executed_subtests () == 1 ? "" : "s");
      }

    char message_time[120] = "";
    if (milliseconds > 0 || microseconds > 0)
      {
        snprintf (message_time, sizeof (message_time),
                  ", time: %" PRIu32 ".%03" PRIu32 " ms", milliseconds,
                  microseconds);
      }

    if (output_file_ != nullptr)
      {
        write_buffer_to_file_ ();

        fprintf (output_file_, "%s\n%s%s }\n", message_summary, message_totals,
                 message_time);
      }

    // At this point, the buffer may contain output from the test case, which
    // should be displayed.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_ && suite.totals ().executed_subtests () > 0)
          {
            printf ("\n");
          }

        if (suite.totals ().was_successful ()) [[likely]]
          {
            // Successful test suite.

            if (verbosity_ == verbosity::verbose)
              {
                // With verbosity, show full TAP output accumulated in the
                // buffer.
                write_buffer_to_stdout ();
              }

            printf ("%s\n%s%s }\n", message_summary, message_totals,
                    message_time);
          }
        else
          {
            // Failed test suite.

            // Show full TAP output accumulated in the buffer for failed suite
            // cases, as it may contain useful information about the failure.
            write_buffer_to_stdout ();

            printf ("%s\n%s%s }\n", message_summary, message_totals,
                    message_time);
          }

        flush ();
      }

    buffer_.clear ();

    add_empty_line_ = true;

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Validates that the output buffer is empty at subtest start; if not,
   * the buffer is written to `stdout`, the stream is flushed, and
   * execution is aborted. A `"# Subtest: <name>"` comment line
   * (indented according to nesting depth) is written to the output file
   * and, under normal or verbose verbosity, to `stdout` as well.
   */
  void
  reporter_tap::begin_subtest (subtest& subtest)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, subtest.name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif

    if (!buffer_.empty ())
      {
        // Each suite should start with an empty buffer.
        write_buffer_to_stdout ();
        flush ();
        abort ();
      }

    std::string indent (indent_size * subtest.nesting_depth (), ' ');

    char message_subtest[120];
    snprintf (message_subtest, sizeof (message_subtest), "%s# Subtest: %s",
              indent.c_str (), subtest.name ());

    if (output_file_ != nullptr)
      {
        fprintf (output_file_, "%s\n", message_subtest);
      }

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

        printf ("%s\n", message_subtest);

        flush ();

        add_empty_line_ = false;
      }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
  }

  /**
   * @details
   * Emits the TAP plan line for the subtest's checks followed by an
   * `ok`/`not ok` result line that includes the subtest index, name,
   * pass/fail status, and check counts. Any output accumulated in
   * `buffer_` is flushed to the output file and, when verbosity is
   * verbose or the subtest failed, to `stdout` as well. The buffer is
   * cleared on exit.
   */
  void
  reporter_tap::end_subtest (subtest& subtest)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    trace::printf ("%s '%s' i%zu +%zu -%zu in xc%zu, xs%zu | cs%zu\n",
                   __PRETTY_FUNCTION__, subtest.name (),
                   subtest.nesting_depth (),
                   subtest.totals ().successful_checks (),
                   subtest.totals ().failed_checks (),
                   subtest.totals ().executed_checks (),
                   subtest.totals ().executed_subtests (),
                   subtest.children_subtests_count ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif

    std::string indent (indent_size * subtest.nesting_depth (), ' ');
    std::string indent2 (indent_size * (subtest.nesting_depth () + 1), ' ');

    char message_summary[40];
    snprintf (message_summary, sizeof (message_summary), "%s1..%zu",
              indent2.c_str (),
              subtest.totals ().executed_checks ()
                  + subtest.totals ().executed_subtests ());

    char message_totals[120];
    if (subtest.totals ().was_successful ()) [[likely]]
      {
        snprintf (message_totals, sizeof (message_totals),
                  "%sok %zu - %s # { passed, %zu check%s }", indent.c_str (),
                  subtest.own_index (), subtest.name (),
                  subtest.totals ().successful_checks (),
                  subtest.totals ().successful_checks () == 1 ? "" : "s");
      }
    else
      {
        snprintf (message_totals, sizeof (message_totals),
                  "%snot ok %zu - %s # { FAILED, %zu check%s "
                  "passed, %zu failed }",
                  indent.c_str (), subtest.own_index (), subtest.name (),
                  subtest.totals ().successful_checks (),
                  subtest.totals ().successful_checks () == 1 ? "" : "s",
                  subtest.totals ().failed_checks ());
      }

    if (output_file_ != nullptr)
      {
        write_buffer_to_file_ ();

        fprintf (output_file_, "%s\n%s\n", message_summary, message_totals);
      }

    // At this point, the buffer may contain output from the subtest, which
    // should be displayed.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

        if (subtest.totals ().was_successful ()) [[likely]]
          {
            // Successful subtest.
            if (verbosity_ == verbosity::verbose)
              {
                // With verbosity, show full TAP output accumulated in the
                // buffer.
                write_buffer_to_stdout ();

                printf ("%s\n", message_summary);
              }
            else
              {
                // Without verbosity, show only the summary line
                // and count only subtests, not checks, as the TAP output is
                // not shown.
                printf ("%s1..%zu\n", indent2.c_str (),
                        subtest.totals ().executed_subtests ());
              }

            printf ("%s\n", message_totals);
          }
        else
          {
            // Failed subtest.

            // Show full TAP output accumulated in the buffer for failed
            // subtests, as it may contain useful information about the
            // failure.
            write_buffer_to_stdout ();

            printf ("%s\n%s\n", message_summary, message_totals);
          }

        flush ();
      }

    buffer_.clear ();

    add_empty_line_ = true;

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Returns `"# "`. The TAP reporter prefixes all comment lines,
   * including the informational lines emitted by `write_info_()`, with
   * the TAP comment marker.
   */
  const char*
  reporter_tap::get_comment_prefix (void)
  {
    return "# ";
  }

  /**
   * @details
   * This method outputs the prefix for a passing check result, applying the
   * appropriate colour formatting and symbols to clearly indicate success. If
   * the output occurs within a subtest, additional indentation is applied
   * for readability. The prefix includes a tick symbol (`✓`) and, if provided,
   * an associated message. Colour formatting is reset after the prefix to
   * maintain consistent output style across all test cases and folders.
   *
   * The prefix/suffix methods help shorten the code
   * generated by the template methods.
   */
  void
  reporter_tap::output_pass_prefix_ (std::string& message, subtest& subtest)
  {
    size_t level = subtest.nesting_depth ();
    *this << indent (level + 1) << "ok "
          << static_cast<int> (subtest.current_subtest_index ()) << " - ";
    if (!message.empty ())
      {
        *this << message.c_str ();
      }
  }

  /**
   * @details
    * Completes pass output by appending `endl` and flushing buffered
    * content to the configured sinks.

   * The prefix/suffix methods help shorten the code
   * generated by the template methods.
   */
  void
  reporter_tap::output_pass_suffix_ ([[maybe_unused]] subtest& subtest)
  {
    *this << endl;

    flush ();
  }

  /**
   * @details
   * This method outputs the prefix for a failing check result, applying the
   * appropriate colour formatting and symbols to clearly indicate failure. If
   * the output occurs within a subtest, additional indentation is applied
   * for readability. The prefix includes a cross symbol (`✗`), an optional
   * message, and YAML diagnostics preamble. Colour formatting and line
   * structure are arranged to conform to TAP14 diagnostics output.
   */
  void
  reporter_tap::output_fail_prefix_ (
      std::string& message, const bool has_expression,
      [[maybe_unused]] const reflection::source_location& location,
      subtest& subtest)
  {
    size_t level = subtest.nesting_depth ();
    *this << indent (level + 1) << "not ok "
          << static_cast<int> (subtest.current_subtest_index ());

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
   * Completes TAP14 YAML diagnostics for a failing check, optionally appends
   * an "aborted..." marker, emits source filename/line fields, closes the
   * YAML block, and flushes the stream.
   */
  void
  reporter_tap::output_fail_suffix_ (
      const reflection::source_location& location, bool abort,
      subtest& subtest)
  {
    size_t level = subtest.nesting_depth ();
    if (abort)
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

    flush ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

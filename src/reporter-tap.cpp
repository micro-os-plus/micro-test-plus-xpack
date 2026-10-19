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

#include <string>
#include <string_view>

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

  namespace
  {
    /**
     * @brief Prepares a text for a single TAP line.
     *
     * @details
     * Each line break (`\\n`, `\\r`, or the `\\r\\n` pair) is replaced by
     * a space, so that the text does not end the line. When @p escape is
     * true, each `\\` is written as `\\\\` and each `#` as `\\#`, as the
     * TAP 14 specification recommends for the test point descriptions and
     * the reasons, so that a `#` in the text does not start a directive
     * (for example `# TODO`, which would hide a failure). The
     * `# Subtest:` comments are not escaped, since the specification
     * defines no escapes in comments, and the node-tap parser uses their
     * text as it is.
     *
     * @param text The text to prepare.
     * @param escape Whether to escape the `\\` and `#` characters.
     * @return The text, without line breaks, and escaped if requested.
     */
    std::string
    tap_text (std::string_view text, bool escape)
    {
      std::string result;
      result.reserve (text.size ());

      for (size_t i = 0; i < text.size (); ++i)
        {
          const char c = text[i];
          if (c == '\n' || c == '\r')
            {
              // The `\r\n` pair is a single line break.
              if (c == '\r' && i + 1 < text.size () && text[i + 1] == '\n')
                {
                  ++i;
                }
              result.push_back (' ');
            }
          else if (escape && (c == '\\' || c == '#'))
            {
              result.push_back ('\\');
              result.push_back (c);
            }
          else
            {
              result.push_back (c);
            }
        }

      return result;
    }

    /**
     * @brief Formats a text as a YAML double-quoted scalar.
     *
     * @details
     * The text is enclosed in `"`, with each `\\` written as `\\\\`, each
     * `"` as `\\"`, and each control character (including the line
     * breaks, the tab, and `DEL`) as a YAML escape sequence (`\\0`,
     * `\\t`, `\\n`, `\\r`, `\\e`, and so on, or `\\xHH` for the others),
     * so that the value is a single line, and is valid YAML whatever it
     * contains. As plain scalars, the values starting with `{`, `[`,
     * or `'`, or containing `: ` or ` #`, would be rejected or
     * truncated by the YAML parsers used by the TAP consumers. The
     * bytes above `0x7F` are written as they are, since they are
     * expected to be parts of UTF-8 sequences.
     *
     * @param text The text to format.
     * @return The double-quoted scalar.
     */
    std::string
    yaml_double_quoted (std::string_view text)
    {
      constexpr std::string_view digits{ "0123456789ABCDEF" };

      std::string result;
      result.reserve (text.size () + 2);

      result.push_back ('"');
      for (const char c : text)
        {
          const auto u = static_cast<unsigned char> (c);
          switch (c)
            {
            case '\\':
              result.append ("\\\\");
              break;
            case '"':
              result.append ("\\\"");
              break;
            case '\0':
              result.append ("\\0");
              break;
            case '\a':
              result.append ("\\a");
              break;
            case '\b':
              result.append ("\\b");
              break;
            case '\t':
              result.append ("\\t");
              break;
            case '\n':
              result.append ("\\n");
              break;
            case '\v':
              result.append ("\\v");
              break;
            case '\f':
              result.append ("\\f");
              break;
            case '\r':
              result.append ("\\r");
              break;
            case '\x1B':
              result.append ("\\e");
              break;
            default:
              if (u < 0x20 || u == 0x7F)
                {
                  result.append ("\\x");
                  result.push_back (digits[static_cast<std::size_t> (u >> 4)]);
                  result.push_back (
                      digits[static_cast<std::size_t> (u & 0x0F)]);
                }
              else
                {
                  result.push_back (c);
                }
              break;
            }
        }
      result.push_back ('"');

      return result;
    }
  } // namespace

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
   * TAP test case block for the suite; the line breaks in the name are
   * replaced by spaces (see `tap_text()`). The line is written to the
   * output file when one is open. Under normal or verbose verbosity, it is
   * also written to `stdout`, preceded by a blank line when
   * `add_empty_line_` is set.
   */
  void
  reporter_tap::begin_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    const std::string name = tap_text (suite.name (), false);

    write_file_ ("# Subtest: %s\n", name.c_str ());

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("# Subtest: %s\n", name.c_str ());

        flush_streams ();

        add_empty_line_ = true;
      }
  }

  /**
   * @details
   * Emits the TAP plan line for the suite's test cases, and for the
   * failure of the suite body, if any (see `fail_suite()`), followed by an
   * `ok`/`not ok` result line that includes the suite index, name,
   * pass/fail status, check counts, test case count, and elapsed time;
   * the name is escaped (see `tap_text()`). Any output accumulated in
   * `buffer_` is written to the output file and, with normal or verbose
   * verbosity, when verbosity is verbose or the suite failed, to `stdout`
   * as well; the plan and result lines are written to `stdout` with
   * normal or verbose verbosity. With quiet verbosity, only the result
   * line is written to `stdout`, without the plan and without an empty
   * line, so that the session plan written by `end_session()` counts the
   * displayed lines. The buffer is cleared on exit.
   */
  void
  reporter_tap::end_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf (
        "%s '%s' +%zu -%zu in xc%zu, xs%zu | cs%zu\n", __PRETTY_FUNCTION__,
        suite.name (), suite.totals ().successful_checks (),
        suite.totals ().failed_checks (), suite.totals ().executed_checks (),
        suite.totals ().executed_test_cases (), suite.child_test_cases_count_);
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

    const std::string name = tap_text (suite.name (), true);

    write_buffer_to_file_ ();

    // The plan counts the test cases and the failure of the suite body,
    // if any, which is numbered after them.
    write_file_ ("%s1..%zu\n%s %zu - %s %s%s }\n", indent.c_str (),
                 suite.test_point_number_, result, suite.own_index_,
                 name.c_str (), message_totals, message_time);

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
                        suite.test_point_number_, result, suite.own_index_,
                        name.c_str (), message_totals, message_time);

        flush_streams ();
      }
    else if (verbosity_ == verbosity::quiet)
      {
        // Only the test point of the suite, counted by the session plan.
        write_console_ ("%s %zu - %s %s%s }\n", result, suite.own_index_,
                        name.c_str (), message_totals, message_time);

        flush_streams ();
      }

    clear_buffer_ ();

    add_empty_line_ = true;
  }

  /**
   * @details
   * Emits an `ok <index> - <name> # SKIP filtered` line, with the name
   * escaped (see `tap_text()`), without a test case block, so that the
   * suite keeps its place in the TAP plan of the session. The line is
   * written to the output file when one is open. Unless verbosity is
   * silent, it is also written to `stdout`; under normal or verbose
   * verbosity, it is preceded by a blank line when `add_empty_line_` is
   * set. With quiet verbosity, it is written as the result lines of
   * `end_suite()`, which the session plan counts.
   */
  void
  reporter_tap::skip_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    const std::string name = tap_text (suite.name (), true);

    write_file_ ("ok %zu - %s # SKIP filtered\n", suite.own_index_,
                 name.c_str ());

    if (verbosity_ != verbosity::silent)
      {
        if (add_empty_line_ && verbosity_ != verbosity::quiet)
          {
            write_console_ ("\n");
          }

        write_console_ ("ok %zu - %s # SKIP filtered\n", suite.own_index_,
                        name.c_str ());

        flush_streams ();
      }

    add_empty_line_ = true;
  }

  /**
   * @details
   * Adds a `not ok <n> - <message>` line, with the message escaped (see
   * `tap_text()`), to the output buffer, indented as the test cases of the
   * suite, where `<n>` is the current test point number of the suite,
   * which follows the test cases already run, and is therefore counted in
   * the plan of the suite. Since there is no source
   * location, no YAML diagnostics block follows. The line is displayed by
   * `end_suite()`, with the other buffered output of the failed suite.
   */
  void
  reporter_tap::fail_suite (const std::string& message, const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    *this << indent (1) << "not ok " << suite.test_point_number_ << " - "
          << tap_text (message, true) << endl;

    buffer_has_failures_ = true;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * For a nested test case, the results of the checks already performed by
   * the outer test case, if any, are written first (see `commit_buffer_()`),
   * so that the output follows the execution order. For a top-level
   * test case, the output buffer is expected to be empty, since the checks
   * are performed only by the test cases, and each one writes its results
   * when it ends; should it not be, its content is written in the same
   * way, rather than lost or attributed to this test case, and the run
   * continues.
   *
   * A `"# Subtest: <name>"` comment line (indented according to nesting
   * depth), with the line breaks in the name replaced by spaces, is then
   * written to the output file and, under normal or verbose verbosity, to
   * `stdout` as well.
   */
  void
  reporter_tap::begin_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (!buffer_.empty ())
      {
        // Normally, the outer test case performed checks before this
        // nested one.
        commit_buffer_ ();
      }

    std::string indent (indent_size_ * test_case.nesting_depth (), ' ');

    const std::string name = tap_text (test_case.name (), false);

    write_file_ ("%s# Subtest: %s\n", indent.c_str (), name.c_str ());

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("%s# Subtest: %s\n", indent.c_str (), name.c_str ());

        flush_streams ();

        add_empty_line_ = false;
      }
  }

  /**
   * @details
   * Emits the TAP plan line for the test case's checks and nested test cases,
   * followed by an `ok`/`not ok` result line that includes the test case
   * index, escaped name, pass/fail status, and check counts. As in
   * node-tap, the result is `not ok` when a check or a nested test case
   * failed; the number of failed nested test cases is added when it is
   * not zero. Any output accumulated in `buffer_` is written to the
   * output file and, with normal or verbose verbosity, when verbosity is
   * verbose or the test case failed, to `stdout` as well. With normal
   * verbosity, for a passing test case, the plan written to `stdout`
   * counts only the nested test cases, since the individual check lines
   * are not displayed. The buffer is cleared on exit.
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
                   test_case.child_test_cases_count_);
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

    const std::string name = tap_text (test_case.name (), true);

    write_buffer_to_file_ ();

    write_file_ ("%s1..%zu\n%s%s %zu - %s %s\n", indent2.c_str (), plan_count,
                 indent.c_str (), result, test_case.own_index_, name.c_str (),
                 message_totals);

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
                        test_case.own_index_, name.c_str (), message_totals);

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
   * The position where the description begins is kept in
   * `description_begin_`, since, when there is no message, the caller
   * appends the expression after this method returns.
   *
   * The prefix/suffix methods help shorten the code
   * generated by the template methods.
   */
  void
  reporter_tap::output_pass_prefix_ (const std::string& message,
                                     const test_case& test_case)
  {
    size_t level = test_case.nesting_depth ();
    *this << indent (level + 1) << "ok " << test_case.test_point_number_
          << " - ";
    description_begin_ = buffer_.size ();
    if (!message.empty ())
      {
        *this << message;
      }
  }

  /**
   * @details
   * The description, either the message or the expression, which follows
   * `description_begin_` in the buffer, is replaced by its escaped form
   * (see `tap_text()`), so that a `#` does not start a directive and a
   * line break does not end the test point line. The pass output is then
   * completed by appending `endl`, which adds a line ending to the
   * buffer, and the output streams are flushed.
   *
   * The prefix/suffix methods help shorten the code
   * generated by the template methods.
   */
  void
  reporter_tap::output_pass_suffix_ (
      [[maybe_unused]] const test_case& test_case)
  {
    const std::string description = tap_text (
        std::string_view{ buffer_ }.substr (description_begin_), true);
    buffer_.replace (description_begin_, std::string::npos, description);

    *this << endl;

    flush_streams ();
  }

  /**
   * @details
   * This method outputs the prefix for a failing check result, as a TAP
   * `"not ok <n>"` line, indented one level deeper than the test case,
   * followed by the message, if provided, escaped (see `tap_text()`), so
   * that a `#` does not start a directive and a line break does not end
   * the test point line. It then opens the TAP 14 YAML
   * diagnostics block (`---`) and, when the failure has an expression,
   * starts a `condition:` field, so that the expression follows on the
   * same line; the position where the expression begins is kept in
   * `condition_begin_`, so that `output_fail_suffix_()` can quote it.
   * Without an expression, `condition_begin_` is set to
   * `std::string::npos`. No colours are used.
   */
  void
  reporter_tap::output_fail_prefix_ (
      const std::string& message, const bool has_expression,
      [[maybe_unused]] const reflection::source_location& location,
      const test_case& test_case)
  {
    size_t level = test_case.nesting_depth ();
    *this << indent (level + 1) << "not ok " << test_case.test_point_number_;

    if (!message.empty ())
      {
        *this << " - " << tap_text (message, true);
      }
    *this << endl;

    // https://testanything.org/tap-version-14-specification.html
    // 2-space indentation for YAML diagnostics.
    *this << indent (level + 1) << "  ---";
    condition_begin_ = std::string::npos;
    if (has_expression)
      {
        *this << endl;
        *this << indent (level + 1) << "  condition: ";
        condition_begin_ = buffer_.size ();
      }
  }

  /**
   * @details
   * Completes the TAP 14 YAML diagnostics block of a failing check, by
   * ending the line opened by the prefix (the `---` line, or the
   * `condition:` field), adding the `at:` field with the file name and
   * the line number, and closing the block (`...`); the stream is then
   * flushed.
   *
   * The location fields are named `fileName:` and `lineNumber:`, as
   * written by node-tap; its reporters (for example the JUnit one, used
   * by the CI systems to annotate the failures) read the file name only
   * from `fileName:` or `file:`, not from `filename:`. There is no
   * `columnNumber:`, since `reflection::source_location` does not
   * provide a column.
   *
   * The expression, which follows `condition_begin_` in the buffer, is
   * first replaced by its YAML double-quoted form (see
   * `yaml_double_quoted()`), so that the operands that start a YAML flow
   * collection or a quoted scalar (for example `{1, 2}` or `'a'`), or
   * contain `: ` or ` #`, do not make the diagnostics block invalid.
   *
   * A failed requirement is reported like any other failed check, as
   * node-tap does for a failed assertion followed by a throw; no marker
   * is added, since any text after `---` or after the condition would
   * make the block, or the value, invalid. That the test case stopped is
   * shown by the plan, which follows this test point; without
   * exceptions, the abort of the test execution is reported by the
   * `Bail out!` line written by `abort_session()`.
   */
  void
  reporter_tap::output_fail_suffix_ (
      const reflection::source_location& location,
      [[maybe_unused]] check_kind kind, const test_case& test_case)
  {
    if (condition_begin_ != std::string::npos)
      {
        const std::string condition = yaml_double_quoted (
            std::string_view{ buffer_ }.substr (condition_begin_));
        buffer_.replace (condition_begin_, std::string::npos, condition);
        condition_begin_ = std::string::npos;
      }

    size_t level = test_case.nesting_depth ();
    *this << endl;

    // https://testanything.org/tap-version-14-specification.html
    // 2-space indentation for YAML diagnostics.

    *this << indent (level + 1) << "  at:" << endl;
    *this << indent (level + 1) << "    fileName: "
          << utility::extract_file_name (location.file_name ()) << endl;
    *this << indent (level + 1) << "    lineNumber: " << location.line ()
          << endl;

    *this << indent (level + 1) << "  ..." << endl;

    flush_streams ();
  }

  /**
   * @details
   * As in `begin_test_case()`, for a nested test case, the results of the
   * checks already performed by the outer test case, if any, are written
   * first (see `commit_buffer_()`), so that the output follows the
   * execution order.
   *
   * An `ok <index> - <name> # SKIP filtered` line, with the name escaped,
   * indented according to the nesting depth, without a test case block,
   * is then written to the output file and, under normal or verbose
   * verbosity, to `stdout`, preceded by a blank line when
   * `add_empty_line_` is set.
   */
  void
  reporter_tap::skip_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (!buffer_.empty ())
      {
        // Normally, the outer test case performed checks before this
        // nested one.
        commit_buffer_ ();
      }

    std::string indent (indent_size_ * test_case.nesting_depth (), ' ');

    const std::string name = tap_text (test_case.name (), true);

    write_file_ ("%sok %zu - %s # SKIP filtered\n", indent.c_str (),
                 test_case.own_index_, name.c_str ());

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_console_ ("%sok %zu - %s # SKIP filtered\n", indent.c_str (),
                        test_case.own_index_, name.c_str ());

        flush_streams ();
      }

    add_empty_line_ = true;
  }

  /**
   * @details
   * Since `end_test_case()` is not called for the running test cases,
   * this method writes the buffered lines, if any, in its place (after a
   * failed requirement, they end with it), followed by an unindented
   * `Bail out! <reason> at <file>:<line>` line, with the file name escaped
   * as the reason, which tells the TAP consumers that the run stopped
   * early (see the TAP 14 specification), not that the output was
   * truncated. The reason is `Requirement failed` after a failed
   * requirement, and `Test execution aborted` for an explicit call of
   * `runner::abort()`.
   *
   * Both are always written to the output file, as in `end_test_case()`,
   * and, unless the verbosity is silent, to `stdout`, preceded by an empty
   * line when `add_empty_line_` is set. With quiet verbosity, which
   * otherwise displays only the summary, they are displayed as well, since
   * the summary is never reached.
   *
   * The buffer is then cleared, so that its lines are not written again,
   * should the abort handler throw an exception that the application
   * catches.
   */
  void
  reporter_tap::abort_session (const reflection::source_location& location,
                               bool is_requirement)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    // The type of `line()` depends on the toolchain (`uint_least32_t` for
    // `std::source_location`); widen it implicitly, without a cast that
    // would be useless on some platforms.
    const unsigned long line = location.line ();
    // The reason is escaped, as the descriptions.
    const std::string file_name
        = tap_text (utility::extract_file_name (location.file_name ()), true);
    const char* reason
        = is_requirement ? "Requirement failed" : "Test execution aborted";

    write_buffer_to_file_ ();

    write_file_ ("Bail out! %s at %s:%lu\n", reason, file_name.c_str (), line);

    if (verbosity_ != verbosity::silent)
      {
        if (add_empty_line_)
          {
            write_console_ ("\n");
          }

        write_buffer_to_console ();

        write_console_ ("Bail out! %s at %s:%lu\n", reason, file_name.c_str (),
                        line);
      }

    flush_streams ();

    clear_buffer_ ();
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

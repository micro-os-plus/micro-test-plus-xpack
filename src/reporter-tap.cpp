/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ source file with implementations for the µTest++ TAP test
 * reporter member functions.
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

  /**
   * @brief Local helpers of the TAP reporter.
   *
   * @details
   * The unnamed namespace gives the helpers internal linkage, so that they
   * are visible only in this translation unit, and cannot conflict with
   * the names of the application or of the other source files of the
   * framework. They are not declared in any header.
   *
   * It contains the functions that make the texts safe to write in the
   * TAP output: `tap_text()`, for the test point descriptions, the
   * reasons, and the comments, and `yaml_double_quoted()`, for the
   * values of the YAML diagnostic blocks.
   */
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
   * calls `write_info()` to output build and environment information.
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

    const bool to_console = route (record_kind::total).console;

    if (to_console)
      {
        write_console ("\n");
      }

    write_info ();

    write_line (to_console, "TAP version 14\n");

    flush_streams ();

    add_empty_line_ = false;
  }

  /**
   * @details
   * Emits the TAP plan line (`1..N`, where N is the total number of test
   * suites) followed by a comment line summarising passed checks,
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

    char message_summary[32];
    snprintf (message_summary, sizeof (message_summary),
              "1..%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE,
              runner.total_suites_count ());

    char message_totals[totals_size_];
    format_session_totals (runner, message_totals);

    char message_time[elapsed_time_size_];
    format_elapsed_time (runner.stopwatch_, message_time);

    const bool to_console = route (record_kind::total).console;

    if (add_empty_line_ && route (record_kind::suite_result).console)
      {
        write_console ("\n");
      }

    write_line (to_console, "%s\n# { total: %s%s }\n", message_summary,
                message_totals, message_time);

    flush_streams ();
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

    const bool to_console = route (record_kind::suite_heading).console;

    if (to_console && add_empty_line_)
      {
        write_console ("\n");
      }

    write_line (to_console, "# Subtest: %s\n", name.c_str ());

    flush_streams ();

    if (to_console)
      {
        add_empty_line_ = true;
      }

    enter_suite (suite, to_console);
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
   * displayed lines; the failure of the suite body, if any, precedes it,
   * as comments (see `write_quiet_failures()`). The buffer is cleared on
   * exit.
   */
  void
  reporter_tap::end_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf (
        "%s '%s' +%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
        " -%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
        " in xc%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
        ", xs%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
        " | cs%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
        __PRETTY_FUNCTION__, suite.name (), suite.totals ().passed_checks (),
        suite.totals ().failed_checks (), suite.totals ().executed_checks (),
        suite.totals ().executed_test_cases (), suite.child_test_cases_count_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    std::string indent (indent_size_, ' ');

    // The name is not included, since its length is not bounded; it is
    // passed to each write.
    const bool passed = suite.totals ().passed ();
    const char* result = passed ? "ok" : "not ok";
    const char* status = passed ? "passed" : "FAILED";

    char message_totals[totals_size_];
    format_suite_totals (suite, message_totals);

    char message_time[elapsed_time_size_];
    format_elapsed_time (suite.stopwatch_, message_time);

    const std::string name = tap_text (suite.name (), true);

    write_buffer_to_file ();

    const bool to_console = route (record_kind::suite_result).console;

    // At this point, the buffer may contain output from the test case, which
    // should be displayed.
    if (to_console)
      {
        if (add_empty_line_ && suite.totals ().executed_test_cases () > 0)
          {
            write_console ("\n");
          }

        // With verbosity, the full TAP output accumulated in the buffer;
        // for a failed suite, as it may contain useful information about
        // the failure.
        write_console_text (console_lines (!passed));
      }
    else
      {
        write_quiet_failures ();
      }

    // The plan counts the test cases and the failure of the suite body,
    // if any, which is numbered after them.
    write_line (to_console,
                "%s1..%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                "\n%s %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                " - %s # { %s, %s%s }\n",
                indent.c_str (), suite.test_point_number_, result,
                suite.own_index_, name.c_str (), status, message_totals,
                message_time);

    if (!to_console && route (record_kind::total).console)
      {
        // Quiet: only the test point of the suite, counted by the session
        // plan.
        write_console ("%s %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                       " - %s # { %s, %s%s }\n",
                       result, suite.own_index_, name.c_str (), status,
                       message_totals, message_time);
      }

    flush_streams ();

    clear_buffer ();

    add_empty_line_ = true;

    current_suite_ = nullptr;
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

    // The skipped suites are counted by the session plan, so they are
    // displayed with quiet verbosity too.
    const bool to_console = route (record_kind::total).console;

    if (add_empty_line_ && route (record_kind::skipped).console)
      {
        write_console ("\n");
      }

    write_line (to_console,
                "ok %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                " - %s # SKIP filtered\n",
                suite.own_index_, name.c_str ());

    flush_streams ();

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

    const size_t begin = buffer_.size ();

    *this << indent (1) << "not ok " << suite.test_point_number_ << " - "
          << tap_text (message, true) << endl;

    mark_failure (begin);
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * For a nested test case, the results of the checks already performed by
   * the outer test case, if any, are written first (see
   * `commit_outer_results()`), so that the output follows the execution
   * order.
   *
   * A `"# Subtest: <name>"` comment line (indented according to nesting
   * depth), with the line breaks in the name replaced by spaces, is then
   * written to the output file and, under verbose verbosity, to `stdout`
   * as well. With the other verbosity levels, the heading is displayed
   * later, only if something is displayed under it (see
   * `display_open_headers()`).
   */
  void
  reporter_tap::begin_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    commit_outer_results ();

    const bool to_console = route (record_kind::test_case_heading).console;

    open_test_cases_.push_back ({ &test_case, to_console });

    std::string indent (indent_size_ * test_case.nesting_depth (), ' ');

    const std::string name = tap_text (test_case.name (), false);

    if (to_console && add_empty_line_)
      {
        write_console ("\n");
      }

    write_line (to_console, "%s# Subtest: %s\n", indent.c_str (),
                name.c_str ());

    flush_streams ();

    if (to_console)
      {
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
   * not zero. Any output accumulated in `buffer_` and the two lines are
   * always written to the output file.
   *
   * With normal verbosity, a passed test case that has nothing displayed
   * under it (no nested test case, and no committed checks) is displayed
   * as a single test point, the `ok` line, without the `# Subtest:`
   * heading, the plan, and the checks; this is a valid test point, and it
   * keeps the console output short. Otherwise, with normal or verbose
   * verbosity, the test case is displayed as a complete block, with the
   * headings of the outer test cases first, if not displayed yet, all the
   * buffered checks, the plan, and the result line, so that the plan
   * matches the displayed test points, with the test point numbers
   * unchanged. With quiet verbosity, only the failed checks are displayed,
   * as comments (see `write_quiet_failures()`).
   *
   * The buffer is cleared on exit.
   */
  void
  reporter_tap::end_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s' i%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                   " +%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                   " -%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                   " in xc%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                   ", xs%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                   " | cs%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
                   __PRETTY_FUNCTION__, test_case.name (),
                   test_case.nesting_depth (),
                   test_case.totals ().passed_checks (),
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
    const bool passed = test_case.totals ().passed ();
    const char* result = passed ? "ok" : "not ok";
    const char* status = passed ? "passed" : "FAILED";

    char message_totals[totals_size_];
    format_test_case_totals (test_case, message_totals);

    const std::string name = tap_text (test_case.name (), true);

    write_buffer_to_file ();

    const bool to_console = route (record_kind::test_case_result).console;

    // A passed test case without anything displayed under it is a single
    // test point.
    const bool is_single_point
        = to_console && passed
          && (open_test_cases_.empty ()
              || !open_test_cases_.back ().name_displayed);

    if (to_console)
      {
        if (is_single_point)
          {
            // The headings of the outer test cases, to keep the test point
            // in their block.
            display_open_headers (false);
          }
        else
          {
            // The heading of this test case too, if not displayed yet.
            display_open_headers (true);

            if (add_empty_line_)
              {
                write_console ("\n");
              }

            // The full TAP output accumulated in the buffer, as the
            // plan counts it.
            write_console_text (console_lines (true));

            write_console ("%s1..%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                           "\n",
                           indent2.c_str (), plan_count);
          }
      }
    else
      {
        write_quiet_failures ();
      }

    write_file ("%s1..%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
                indent2.c_str (), plan_count);

    write_line (to_console,
                "%s%s %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                " - %s # { %s, %s }\n",
                indent.c_str (), result, test_case.own_index_, name.c_str (),
                status, message_totals);

    flush_streams ();

    clear_buffer ();

    add_empty_line_ = true;

    if (!open_test_cases_.empty ())
      {
        open_test_cases_.pop_back ();
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Returns `"# "`. The TAP reporter prefixes all comment lines,
   * including the informational lines emitted by `write_info()`, with
   * the TAP comment marker.
   */
  const char*
  reporter_tap::comment_prefix (void) const noexcept
  {
    return "# ";
  }

  /**
   * @details
   * This member function outputs the prefix for a passing check result, as a
   * TAP `"ok <n> - "` line, where `<n>` is the test point number of the
   * check, which counts the checks and the nested test cases of the test
   * case, indented one level deeper than the test case, followed by the
   * message, if provided. No colours are used.
   *
   * The position where the description begins is kept in
   * `description_begin_`, since, when there is no message, the caller
   * appends the expression after this member function returns.
   *
   * The prefix/suffix member functions help shorten the code
   * generated by the template member functions.
   */
  void
  reporter_tap::output_pass_prefix (const std::string& message,
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
   * buffer. The streams are not flushed, since nothing was written to
   * them; the buffer is written, and the streams flushed, when the test
   * case ends.
   *
   * The prefix/suffix member functions help shorten the code
   * generated by the template member functions.
   */
  void
  reporter_tap::output_pass_suffix (
      [[maybe_unused]] const test_case& test_case)
  {
    const std::string description = tap_text (
        std::string_view{ buffer_ }.substr (description_begin_), true);
    buffer_.replace (description_begin_, std::string::npos, description);

    *this << endl;
  }

  /**
   * @details
   * This member function outputs the prefix for a failing check result, as a
   * TAP `"not ok <n>"` line, indented one level deeper than the test case,
   * followed by the message, if provided, escaped (see `tap_text()`), so that
   * a `#` does not start a directive and a line break does not end the test
   * point line. It then opens the TAP 14 YAML diagnostics block (`---`) and,
   * when the failure has an expression, starts a `condition:` field, so that
   * the expression follows on the same line; the position where the
   * expression begins is kept in `condition_begin_`, so that
   * `output_fail_suffix()` can quote it. Without an expression,
   * `condition_begin_` is set to `std::string::npos`. No colours are used.
   */
  void
  reporter_tap::output_fail_prefix (
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
   * the line number, and closing the block (`...`). As for a pass, the
   * streams are flushed when the test case ends.
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
  reporter_tap::output_fail_suffix (
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
  }

  /**
   * @details
   * As in `begin_test_case()`, for a nested test case, the results of the
   * checks already performed by the outer test case, if any, are written
   * first (see `commit_outer_results()`), so that the output follows the
   * execution order.
   *
   * An `ok <index> - <name> # SKIP filtered` line, with the name escaped,
   * indented according to the nesting depth, without a test case block,
   * is then written to the output file and, under normal or verbose
   * verbosity, to `stdout`, after the headings of the outer test cases,
   * if not displayed yet, and, under verbose verbosity, preceded by a
   * blank line when `add_empty_line_` is set.
   */
  void
  reporter_tap::skip_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    commit_outer_results ();

    std::string indent (indent_size_ * test_case.nesting_depth (), ' ');

    const std::string name = tap_text (test_case.name (), true);

    const bool to_console = route (record_kind::skipped).console;

    if (to_console)
      {
        display_open_headers (true);

        if (add_empty_line_ && route (record_kind::test_case_heading).console)
          {
            write_console ("\n");
          }
      }

    write_line (to_console,
                "%sok %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                " - %s # SKIP filtered\n",
                indent.c_str (), test_case.own_index_, name.c_str ());

    flush_streams ();

    add_empty_line_ = true;
  }

  /**
   * @details
   * Since `end_test_case()` is not called for the running test cases, this
   * member function writes the buffered lines, if any, in its place (after a
   * failed requirement, they end with it), preceded, with normal or verbose
   * verbosity, by the headings of the open test cases, if not displayed yet,
   * followed by an unindented
   * `Bail out! <reason> at <file>:<line>` line, with the file name escaped
   * as the reason, which tells the TAP consumers that the run stopped early
   * (see the TAP 14 specification), not that the output was truncated. The
   * reason is `Requirement failed` after a failed requirement, and
   * `Test execution aborted` for an explicit call of `runner::abort()`.
   *
   * Both are always written to the output file, as in `end_test_case()`,
   * and, unless the verbosity is silent, to `stdout`, preceded by an empty
   * line when `add_empty_line_` is set. With quiet verbosity, which
   * otherwise displays only the summary, the failed checks are displayed
   * as comments, and the `Bail out!` line as well, since the summary is
   * never reached.
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

    write_buffer_to_file ();

    const bool to_console = route (record_kind::abort).console;

    if (to_console)
      {
        if (route (record_kind::suite_result).console)
          {
            display_open_headers (true);

            if (add_empty_line_)
              {
                write_console ("\n");
              }

            write_console_text (console_lines (true));
          }
        else
          {
            write_quiet_failures ();
          }
      }

    write_line (to_console, "Bail out! %s at %s:%lu\n", reason,
                file_name.c_str (), line);

    flush_streams ();

    clear_buffer ();

    // Should the abort handler throw, nothing may refer to the objects
    // that are unwound.
    open_test_cases_.clear ();
    current_suite_ = nullptr;
  }

  /**
   * @details
   * The buffered `ok`/`not ok` lines of the outer test case are always
   * written to the output file and, with normal or verbose verbosity, to
   * `stdout`, after the headings of the outer test cases, if not
   * displayed yet, and preceded by an empty line when `add_empty_line_`
   * is set. They are displayed even if all the checks passed, since the
   * outer test case, which contains a nested test case, is displayed as a
   * block, whose plan counts them. With quiet verbosity, only the failed
   * checks are displayed, as comments. The buffer is then cleared, so that
   * the nested test case starts with an empty buffer, and the remaining
   * lines of the outer test case are written by its `end_test_case()`.
   */
  void
  reporter_tap::commit_buffer (void)
  {
    write_buffer_to_file ();

    if (route (record_kind::test_case_result).console)
      {
        display_open_headers (true);

        if (add_empty_line_)
          {
            write_console ("\n");
            add_empty_line_ = false;
          }

        write_console_text (console_lines (true));
      }
    else
      {
        write_quiet_failures ();
      }

    flush_streams ();

    clear_buffer ();
  }

  /**
   * @details
   * Walks `open_test_cases_` from the outermost test case and writes, to
   * `stdout`, the indented `"# Subtest: <name>"` line of each one whose
   * heading was not displayed yet, with the line breaks in the name
   * replaced by spaces, marking it as displayed. Each heading is preceded
   * by a blank line when `add_empty_line_` is set; the flag is then
   * cleared, so that the content of the block follows its heading.
   */
  void
  reporter_tap::display_open_headers (bool include_last)
  {
    const size_t count = include_last || open_test_cases_.empty ()
                             ? open_test_cases_.size ()
                             : open_test_cases_.size () - 1;
    for (size_t i = 0; i < count; ++i)
      {
        open_test_case& open = open_test_cases_[i];
        if (open.name_displayed)
          {
            continue;
          }

        if (add_empty_line_)
          {
            write_console ("\n");
          }

        std::string indent (indent_size_ * open.test->nesting_depth (), ' ');
        const std::string name = tap_text (open.test->name (), false);
        write_console ("%s# Subtest: %s\n", indent.c_str (), name.c_str ());

        open.name_displayed = true;
        add_empty_line_ = false;
      }
  }

  /**
   * @details
   * Writes a comment line with the names of the suite and of the open
   * test cases, separated by `" > "`, with the line breaks replaced by
   * spaces, then the lines of `failures_`, each prefixed by the comment
   * prefix. The lines of the failed checks keep their indentation, after
   * the prefix, so that the YAML diagnostics blocks remain readable. The
   * output is not buffered; `failures_` is not cleared.
   */
  void
  reporter_tap::write_quiet_failures (void)
  {
    if (failures_.empty ())
      {
        return;
      }

    std::string path;
    if (current_suite_ != nullptr)
      {
        path = tap_text (current_suite_->name (), false);
      }
    for (const open_test_case& open : open_test_cases_)
      {
        if (!path.empty ())
          {
            path.append (" > ");
          }
        path.append (tap_text (open.test->name (), false));
      }
    write_console ("%s%s\n", comment_prefix (), path.c_str ());

    std::string_view rest{ failures_ };
    while (!rest.empty ())
      {
        const size_t end = rest.find ('\n');
        const size_t length
            = (end == std::string_view::npos) ? rest.size () : end + 1;
        write_console ("%s", comment_prefix ());
        write_console_text (rest.substr (0, length));
        rest.remove_prefix (length);
      }
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

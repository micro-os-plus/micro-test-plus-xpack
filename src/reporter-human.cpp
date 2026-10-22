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
 * @brief C++ source file with implementations for the µTest++ human test
 * reporter member functions.
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
#include "micro-os-plus/micro-test-plus/utility.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

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
   * options. Colour output is enabled, by selecting the red/green colour
   * scheme, when `opts.colour` is `colour_mode::always`, or when it
   * is `colour_mode::automatic` and, on POSIX platforms, `stdout` is
   * connected to a terminal (`isatty()`). If tracing is enabled, the
   * function signature is output for diagnostic purposes.
   */
  reporter_human::reporter_human (const runner_options& opts)
      : reporter{ opts }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

    bool use_colours = (opts.colour == colour_mode::always);

#if defined(__APPLE__) || defined(__linux__) || defined(__unix__)
    if (opts.colour == colour_mode::automatic && isatty (fileno (stdout)))
      {
        use_colours = true;
      }
#endif // defined(__APPLE__) || defined(__linux__) || defined(__unix__)

    if (use_colours)
      {
        colours_ = colours_red_green;
      }
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
   * @details
   * If verbosity is not silent, a blank line is printed to `stdout`
   * before the build-information block emitted by `write_info()`. A
   * fixed "µTest++ human report" heading is then written to the output
   * file (if open) and, unless verbosity is silent, to `stdout`. The
   * `add_empty_line_` flag is set so that subsequent suite output is
   * visually separated.
   */
  void
  reporter_human::begin_session ([[maybe_unused]] const runner& runner)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (verbosity_ != verbosity::silent)
      {
        write_console ("\n");
      }

    write_info ();

    write_line (verbosity_ != verbosity::silent, "µTest++ human report\n");

    flush_streams ();

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
  reporter_human::end_session (const runner& runner)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (verbosity_ != verbosity::silent)
      {
        if (add_empty_line_)
          {
            write_console ("\n");
          }

        char message_totals[totals_size_];
        format_session_totals (runner, message_totals);

        char message_time[elapsed_time_size_];
        format_elapsed_time (runner.stopwatch_, message_time);

        if (runner.totals ().passed ()) [[likely]]
          {
            write_line (true, "%s✓%s Total: %s%s\n", colours_.pass,
                        colours_.none, message_totals, message_time);
          }
        else
          {
            write_line (true, "%s✗%s Total: %s%s\n", colours_.fail,
                        colours_.none, message_totals, message_time);
          }

        flush_streams ();
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * With normal or verbose verbosity, this member function writes a
   * `"• <name>"` line, marking the beginning of the test suite, to the
   * output file (if open) and to `stdout`, preceded on `stdout` by an empty
   * line when `add_empty_line_` is set. For silent or quiet verbosity
   * levels, no output is produced.
   */
  void
  reporter_human::begin_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console ("\n");
          }

        write_line (true, "• %s\n", suite.name ());

        flush_streams ();

        add_empty_line_ = true;
      }
  }

  /**
   * @details
   * With normal or verbose verbosity, this member function summarises the
   * results of the test suite, with appropriate formatting and colour coding;
   * for silent or quiet verbosity levels, no output is produced. An empty
   * line is first added if the suite executed any test cases.
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
  reporter_human::end_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    char message_time[elapsed_time_size_];
    format_elapsed_time (suite.stopwatch_, message_time);

    // At this point, the buffer may contain output from the test case, which
    // should be displayed.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        char message_totals[totals_size_];
        format_suite_totals (suite, message_totals);

        if (suite.totals ().executed_test_cases () > 0)
          {
            write_console ("\n");
          }

        if (suite.totals ().passed ()) [[likely]]
          {
            // Successful test suite.

            write_buffer_to_file ();

            if (verbosity_ == verbosity::verbose)
              {
                // With verbosity, show the full output accumulated in the
                // buffer.
                write_buffer_to_console ();
              }

            write_line (true, "%s✓%s %s - passed (%s)%s\n", colours_.pass,
                        colours_.none, suite.name (), message_totals,
                        message_time);
          }
        else
          {
            // Failed test suite.

            write_buffer_to_file ();

            // Show the full output accumulated in the buffer for a failed
            // suite, as it may contain useful information about the failure.
            write_buffer_to_console ();

            write_line (true, "%s✗%s %s - %sFAILED%s (%s)%s\n", colours_.fail,
                        colours_.none, suite.name (), colours_.fail,
                        colours_.none, message_totals, message_time);
          }
      }

    flush_streams ();

    // Clear residual content when less verbose.
    clear_buffer ();

    add_empty_line_ = true;
  }

  /**
   * @details
   * With normal or verbose verbosity, this member function writes a
   * `"• <name> - skipped (filtered)"` line, instead of the suite body and
   * results, to the output file (if open) and to `stdout`, preceded on
   * `stdout` by an empty line when `add_empty_line_` is set. For silent
   * or quiet verbosity levels, no output is produced.
   */
  void
  reporter_human::skip_suite (const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console ("\n");
          }

        write_line (true, "• %s - skipped (filtered)\n", suite.name ());

        flush_streams ();

        add_empty_line_ = true;
      }
  }

  /**
   * @details
   * Adds a `"✗ <message> FAILED"` line to the output buffer, indented as
   * the test cases of the suite, with the same colours as the failed
   * checks; since there is no source location, no parenthesised location
   * follows. The line is displayed by `end_suite()`, with the other
   * buffered output of the failed suite.
   */
  void
  reporter_human::fail_suite (const std::string& message,
                              [[maybe_unused]] const suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    *this << indent (1) << colours_.fail << "✗" << colours_.none << " "
          << message << " " << colours_.fail << "FAILED" << colours_.none
          << endl;

    buffer_has_failures_ = true;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * This member function marks the beginning of a test case. For a nested test
   * case, the results of the checks already performed by the outer test
   * case, if any, are written first (see `commit_outer_results()`), so that
   * the output follows the execution order.
   *
   * A `"• <name>"` line, indented according to the nesting depth, is
   * written to the output file (if open) and, with verbose verbosity, to
   * `stdout`, preceded by an empty line when `add_empty_line_` is set.
   */
  void
  reporter_human::begin_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    commit_outer_results ();

    open_test_cases_.push_back (
        { &test_case, verbosity_ == verbosity::verbose });

    std::string indent (indent_size_ * test_case.nesting_depth (), ' ');

    const bool to_console = (verbosity_ == verbosity::verbose);

    if (to_console && add_empty_line_)
      {
        write_console ("\n");
      }

    write_line (to_console, "%s• %s\n", indent.c_str (), test_case.name ());

    if (to_console)
      {
        add_empty_line_ = false;
      }

    flush_streams ();
  }

  /**
   * @details
   * With normal or verbose verbosity, this member function summarises the
   * outcome of the test case, with appropriate formatting and colour coding;
   * for silent or quiet verbosity levels, no output is produced.
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
  reporter_human::end_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s' i%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
                   __PRETTY_FUNCTION__, test_case.name (),
                   test_case.nesting_depth ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    // At this point, the buffer may contain output from the test case, which
    // should be displayed.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        std::string indent (indent_size_ * test_case.nesting_depth (), ' ');

        // The name is not included, since its length is not bounded;
        // it is passed to each write.
        char message_totals[totals_size_];
        format_test_case_totals (test_case, message_totals);

        if (add_empty_line_)
          {
            write_console ("\n");
          }

        if (test_case.totals ().passed ()) [[likely]]
          {
            // Successful test case.

            write_buffer_to_file ();

            if (verbosity_ == verbosity::verbose)
              {
                // With verbosity, show the full output accumulated in the
                // buffer.
                write_buffer_to_console ();
              }

            write_line (true, "%s%s✓%s %s - passed (%s)\n", indent.c_str (),
                        colours_.pass, colours_.none, test_case.name (),
                        message_totals);

            add_empty_line_ = (verbosity_ == verbosity::verbose);
          }
        else
          {
            // Failed test case.

            write_buffer_to_file ();

            if (verbosity_ == verbosity::normal)
              {
                // This test case and the outer ones, whose names may have
                // been displayed already, by `commit_buffer()` or by a
                // failed sibling.
                display_open_names ();
              }

            // Show full output accumulated in the buffer for failed
            // test cases, as it may contain useful information about the
            // failure.
            write_buffer_to_console ();

            write_line (true, "%s%s✗%s %s - %sFAILED%s (%s)\n",
                        indent.c_str (), colours_.fail, colours_.none,
                        test_case.name (), colours_.fail, colours_.none,
                        message_totals);

            add_empty_line_ = true;
          }
      }

    flush_streams ();

    // Clear residual content when less verbose.
    clear_buffer ();

    if (!open_test_cases_.empty ())
      {
        open_test_cases_.pop_back ();
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Returns an empty string. The human reporter does not prefix comment
   * lines; the `write_info()` output appears as plain text.
   */
  const char*
  reporter_human::comment_prefix (void) const noexcept
  {
    return "";
  }

  /**
   * @details
   * The buffered check results are written, to the output file and to
   * `stdout`, only with normal or verbose verbosity; with normal
   * verbosity, the passed checks are displayed when the test case fails.
   * With quiet verbosity, only the buffer of an aborted test execution
   * is displayed (see `abort_session()`), which then includes only the
   * failed checks.
   */
  bool
  reporter_human::writes_passed_checks (void) const noexcept
  {
    return verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose;
  }

  /**
   * @details
   * This member function outputs the prefix for a passing check result,
   * indented one level deeper than the test case. The prefix includes a tick
   * symbol (`✓`), in the pass colour, and, if provided, the associated
   * message. Colour formatting is reset immediately after the symbol.
   *
   * The prefix/suffix member functions help shorten the code
   * generated by the template member functions.
   */
  void
  reporter_human::output_pass_prefix (const std::string& message,
                                      const test_case& test_case)
  {
    size_t level = test_case.nesting_depth ();

    *this << indent (level + 1);
    *this << colours_.pass << "✓" << colours_.none << " ";
    if (!message.empty ())
      {
        *this << message;
      }
  }

  /**
   * @details
   * Completes the pass output by appending `endl`, which adds a line
   * ending to the buffer. The streams are not flushed, since nothing was
   * written to them; the buffer is written, and the streams flushed, when
   * the test case ends.
   *
   * The prefix/suffix member functions help shorten the code
   * generated by the template member functions.
   */
  void
  reporter_human::output_pass_suffix (
      [[maybe_unused]] const test_case& test_case)
  {
    *this << endl;
  }

  /**
   * @details
   * This member function outputs the prefix for a failing check result,
   * indented one level deeper than the test case. The prefix includes a cross
   * symbol (`✗`), an optional message, and the label "FAILED", both symbol
   * and label in the fail colour. The source location (file name and line
   * number) follows, after an opening parenthesis; when the failure has an
   * expression, a comma separator is added, so that the expression follows
   * inside the parentheses.
   */
  void
  reporter_human::output_fail_prefix (
      const std::string& message, const bool has_expression,
      const reflection::source_location& location, const test_case& test_case)
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
        *this << message;
        *this << " ";
      }
    *this << colours_.fail << "FAILED" << colours_.none;
    *this << " (" << utility::extract_file_name (location.file_name ()) << ":"
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
   * This member function outputs the suffix for a failing check result by
   * closing the parenthesis, appending, if the check is a requirement, the
   * effect that follows, and then appending `endl`, which adds a line
   * ending. As for a pass, the streams are flushed when the test case
   * ends.
   *
   * The effect depends on the build, as in `check_result`: with
   * exceptions, only the test case is stopped (`" - test case stopped"`),
   * and the run continues with the next test case; without, the test
   * execution is aborted (`" - test execution aborted"`).
   */
  void
  reporter_human::output_fail_suffix (
      [[maybe_unused]] const reflection::source_location& location,
      check_kind kind, [[maybe_unused]] const test_case& test_case)
  {
    *this << ")";
    if (kind == check_kind::requirement)
      {
#if defined(__cpp_exceptions)
        *this << " - test case stopped";
#else
        *this << " - test execution aborted";
#endif // defined(__cpp_exceptions)
      }
    *this << endl;
  }

  /**
   * @details
   * As in `begin_test_case()`, for a nested test case, the results of the
   * checks already performed by the outer test case, if any, are written
   * first (see `commit_outer_results()`), so that the output follows the
   * execution order.
   *
   * With normal or verbose verbosity, a `"• <name> - skipped (filtered)"`
   * line, indented according to the nesting depth, is then written to the
   * output file (if open) and to `stdout`, preceded on `stdout` by an
   * empty line when `add_empty_line_` is set. For silent or quiet
   * verbosity levels, no output is produced.
   */
  void
  reporter_human::skip_test_case (const test_case& test_case)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, test_case.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    commit_outer_results ();

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        std::string indent (indent_size_ * test_case.nesting_depth (), ' ');

        if (add_empty_line_)
          {
            write_console ("\n");
          }

        write_line (true, "%s• %s - skipped (filtered)\n", indent.c_str (),
                    test_case.name ());

        // As for a passed test case.
        add_empty_line_ = (verbosity_ == verbosity::verbose);
      }

    flush_streams ();
  }

  /**
   * @details
   * Since `end_test_case()` is not called for the running test cases, this
   * member function writes the buffered results in its place; after a failed
   * requirement, they end with it. As in `end_test_case()`, they are written
   * to the output file only with normal or verbose verbosity.
   *
   * Unless the verbosity is silent, the names of the open test cases that
   * were not displayed yet (all of them, with normal or quiet verbosity)
   * are written to `stdout`, followed by the buffered results, so that a
   * failure is not attributed to the previous test case. With quiet
   * verbosity, which otherwise displays only the summary, the results are
   * displayed as well, since the summary is never reached; this includes
   * the passed checks, which give the context of the failure.
   *
   * In place of the summary, a `✗ Test execution aborted at
   * <file>:<line>` line is then written, as the summary is, unless the
   * verbosity is silent, to the output file and to `stdout`. After a
   * failed requirement, the location is the same as in the failure
   * line, which is already marked `- test execution aborted`; for an
   * explicit call of `runner::abort()`, it is the only report of the
   * abort.
   *
   * The buffer is then cleared, so that its results are not written
   * again, should the abort handler throw an exception that the
   * application catches.
   */
  void
  reporter_human::abort_session (const reflection::source_location& location,
                                 [[maybe_unused]] bool is_requirement)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        write_buffer_to_file ();
      }

    if (verbosity_ != verbosity::silent)
      {
        // Whether names or results are displayed before the final line.
        bool has_results = !buffer_.empty ();
        for (const open_test_case& open : open_test_cases_)
          {
            has_results = has_results || !open.name_displayed;
          }

        if (add_empty_line_)
          {
            write_console ("\n");
          }

        display_open_names ();

        write_buffer_to_console ();

        // Separate the final line by an empty line, as the summary, unless
        // it was already written above.
        if (has_results || !add_empty_line_)
          {
            write_console ("\n");
          }

        // The type of `line()` depends on the toolchain (`uint_least32_t`
        // for `std::source_location`); widen it implicitly, without a cast
        // that would be useless on some platforms.
        const unsigned long line = location.line ();
        const char* file_name
            = utility::extract_file_name (location.file_name ());

        write_line (true, "%s✗%s Test execution aborted at %s:%lu\n",
                    colours_.fail, colours_.none, file_name, line);
      }

    flush_streams ();

    clear_buffer ();
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
  reporter_human::commit_buffer (void)
  {
    // As in `end_test_case()`, the results reach the output file only with
    // normal or verbose verbosity.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        write_buffer_to_file ();
      }

    if (verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            write_console ("\n");
            add_empty_line_ = false;
          }

        write_buffer_to_console ();
      }
    else if (verbosity_ == verbosity::normal && buffer_has_failures_)
      {
        if (add_empty_line_)
          {
            write_console ("\n");
          }

        display_open_names ();

        write_buffer_to_console ();

        add_empty_line_ = true;
      }

    flush_streams ();

    clear_buffer ();
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
  reporter_human::display_open_names (void)
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
            write_console ("\n");
          }
        is_first = false;

        std::string indent (indent_size_ * open.test->nesting_depth (), ' ');
        write_console ("%s• %s\n", indent.c_str (), open.test->name ());

        open.name_displayed = true;
      }
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

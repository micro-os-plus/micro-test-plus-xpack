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
 * the default concrete implementation of the `reporter` abstract
 * interface. It formats and presents test results using `printf`-based
 * standard output, accumulating output in an internal string buffer and
 * supporting colour-coded diagnostics and multiple verbosity levels.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

#if defined(__APPLE__) || defined(__linux__) || defined(__unix__)
// For isatty() to detect if stdout is a terminal, enabling colour output.
#include <unistd.h>
#endif

// ----------------------------------------------------------------------------

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  reporter_human::reporter_human (
      std::unique_ptr<std::vector<std::string_view>> argvs)
      : reporter{ std::move (argvs) }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

#if defined(__APPLE__) || defined(__linux__) || defined(__unix__)
    if (isatty (fileno (stdout)))
      {
        colours_ = colours_red_green;
      }
#endif
  }

  reporter_human::~reporter_human ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  // --------------------------------------------------------------------------

  constexpr size_t indent_size = 4;

  /**
   * @details
   * This operator overload appends spaces to the internal output buffer
   * corresponding to `m.level` two-space indentation levels. It enables
   * structured, readable nesting of test output across all test cases and
   * folders by allowing `*this << indent(n) << "text"` chaining.
   */
  reporter_human&
  reporter_human::operator<< (indent_t m)
  {
    buffer_.append (m.level * indent_size, ' ');
    return *this;
  }

  // --------------------------------------------------------------------------

  void
  reporter_human::begin_session ([[maybe_unused]] runner& runner)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (verbosity_ != verbosity::silent)
      {
        if (output_file_ != nullptr)
          {
            fprintf (stderr, "warning: --output-file is not supported by "
                             "the human reporter; ignoring\n");
            fclose (output_file_);
            output_file_ = nullptr;
          }

        printf ("\n");
        write_info_ ();
        printf ("µTest++ human report\n");

        flush ();
      }
    add_empty_line_ = true;
  }

  void
  reporter_human::end_session (runner& runner)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (verbosity_ != verbosity::silent)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

        size_t total_suites_count = runner.total_suites_count ();

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

        if (runner.totals ().was_successful ()) [[likely]]
          {
            printf ("%s✓%s Total: %zu check%s passed, %zu failed, in %zu test "
                    "case%s, %zu test suite%s\n",
                    colours_.pass, colours_.none,
                    runner.totals ().successful_checks (),
                    runner.totals ().successful_checks () == 1 ? "" : "s",
                    runner.totals ().failed_checks (),
                    runner.totals ().executed_subtests (),
                    runner.totals ().executed_subtests () == 1 ? "" : "s",
                    total_suites_count, total_suites_count == 1 ? "" : "s");
          }
        else
          {
            printf ("%s✗%s Total: %zu check%s passed, %zu failed, in %zu test "
                    "case%s, %zu test suite%s\n",
                    colours_.fail, colours_.none,
                    runner.totals ().successful_checks (),
                    runner.totals ().successful_checks () == 1 ? "" : "s",
                    runner.totals ().failed_checks (),
                    runner.totals ().executed_subtests (),
                    runner.totals ().executed_subtests () == 1 ? "" : "s",
                    total_suites_count, total_suites_count == 1 ? "" : "s");
          }

#pragma GCC diagnostic pop

        flush ();
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * This method marks the beginning of a test suite, ensuring that output is
   * properly separated and clearly presented. If there is pending output, the
   * stream is flushed and an empty line is added for clarity. For silent or
   * quiet verbosity levels, output is suppressed. Otherwise, a message
   * indicating the start of the test suite is displayed. This approach
   * enhances the organisation and readability of test results across all test
   * cases and folders.
   */
  void
  reporter_human::begin_suite ([[maybe_unused]] suite& suite)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
        printf ("• %s\n", suite.name ());
#pragma GCC diagnostic pop

        flush ();

        add_empty_line_ = true;
      }
  }

  /**
   * @details
   * This method marks the end of a test suite, summarising the overall results
   * and presenting them with appropriate formatting and colour coding. If the
   * suite contains test cases and the verbosity is not set to quiet, an empty
   * line is added for clarity. For suites with no failed checks and at least
   * one successful check, a success message is displayed, including the number
   * of checks and test cases. Otherwise, a failure message is shown, detailing
   * the number of successful and failed checks, as well as the total number of
   * test cases. The output is immediately flushed to ensure prompt and
   * organised reporting across all test cases and folders.
   */
  void
  reporter_human::end_suite (suite& suite)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    // At this point, the buffer may contain output from the test case, which
    // should be displayed.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        std::string indent (indent_size, ' ');

        if (/* add_empty_line_ && */ suite.totals ().executed_subtests () > 0)
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

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

            printf ("%s✓%s %s - passed (%zu check%s in %zu test "
                    "case%s)\n",
                    colours_.pass, colours_.none, suite.name (),
                    suite.totals ().successful_checks (),
                    suite.totals ().successful_checks () == 1 ? "" : "s",
                    suite.totals ().executed_subtests (),
                    suite.totals ().executed_subtests () == 1 ? "" : "s");

#pragma GCC diagnostic pop
          }
        else
          {
            // Failed test suite.

            // Show full TAP output accumulated in the buffer for failed suite
            // cases, as it may contain useful information about the failure.
            write_buffer_to_stdout ();

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

            printf ("%s✗%s %s - %sFAILED%s (%zu check%s passed, %zu "
                    "failed, "
                    "in %zu test case%s)\n",
                    colours_.fail, colours_.none, suite.name (), colours_.fail,
                    colours_.none, suite.totals ().successful_checks (),
                    suite.totals ().successful_checks () == 1 ? "" : "s",
                    suite.totals ().failed_checks (),
                    suite.totals ().executed_subtests (),
                    suite.totals ().executed_subtests () == 1 ? "" : "s");

#pragma GCC diagnostic pop
          }
      }

    flush ();

    // Clear residual content when less verbose.
    buffer_.clear ();

    add_empty_line_ = true;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * This method marks the beginning of a test case, setting the internal state
   * to indicate that test output is now within a test case context. If there
   * is pending output and the verbosity level is set to verbose, it ensures
   * that output is properly separated and displayed, adding an empty line if
   * necessary. The output buffer is cleared and the stream is flushed to
   * guarantee that all previous output is visible before the new test case
   * begins. This approach enhances the clarity and organisation of test
   * results across all test cases and folders.
   */
  void
  reporter_human::begin_subtest ([[maybe_unused]] subtest& subtest)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, subtest.name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (!buffer_.empty ())
      {
        // Each suite should start with an empty buffer.
        printf ("Buffer not empty at the beginning of a test case:\n%s\n",
                buffer_.c_str ());
        flush ();
        abort ();
      }

    if (verbosity_ == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

        std::string indent (indent_size * subtest.nesting_depth (), ' ');

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
        printf ("%s• %s\n", indent.c_str (), subtest.name ());

#pragma GCC diagnostic pop

        add_empty_line_ = false;
      }

    flush ();
  }

  /**
   * @details
   * This method marks the end of a test case, summarising its outcome and
   * outputting the results with appropriate formatting and colour coding. If
   * any checks have failed, a failure message is displayed, including the
   * number of successful and failed checks. For passing test cases, a success
   * message is shown with the total number of checks. The output is adjusted
   * according to the verbosity level, and additional spacing is managed for
   * clarity. The output buffer is cleared and the stream is flushed to ensure
   * all results are immediately visible, supporting clear and organised
   * reporting across all test cases and folders.
   */
  void
  reporter_human::end_subtest (subtest& subtest)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' i%zu\n", __PRETTY_FUNCTION__, subtest.name (),
            subtest.nesting_depth ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    // At this point, the buffer may contain output from the subtest, which
    // should be displayed.
    if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
      {
        std::string indent (indent_size * subtest.nesting_depth (), ' ');
        std::string indent2 (indent_size * (subtest.nesting_depth () + 1),
                             ' ');

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
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

                write_buffer_to_stdout ();

                printf ("%s%s✓%s %s - passed (%zu check%s)\n", indent.c_str (),
                        colours_.pass, colours_.none, subtest.name (),
                        subtest.totals ().successful_checks (),
                        subtest.totals ().successful_checks () == 1 ? ""
                                                                    : "s");

#pragma GCC diagnostic pop
                add_empty_line_ = true;
              }
            else
              {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

                printf ("%s%s✓%s %s - passed (%zu check%s)\n", indent.c_str (),
                        colours_.pass, colours_.none, subtest.name (),
                        subtest.totals ().successful_checks (),
                        subtest.totals ().successful_checks () == 1 ? ""
                                                                    : "s");

#pragma GCC diagnostic pop

                add_empty_line_ = false;
              }
          }
        else
          {
            // Failed subtest.

            // Show full TAP output accumulated in the buffer for failed
            // subtests, as it may contain useful information about the
            // failure.
            write_buffer_to_stdout ();

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

            printf ("%s%s✗%s %s - %sFAILED%s (%zu check%s passed, %zu "
                    "failed)\n",
                    indent.c_str (), colours_.fail, colours_.none,
                    subtest.name (), colours_.fail, colours_.none,
                    subtest.totals ().successful_checks (),
                    subtest.totals ().successful_checks () == 1 ? "" : "s",
                    subtest.totals ().failed_checks ());

#pragma GCC diagnostic pop

            add_empty_line_ = true;
          }
      }

    flush ();

    // Clear residual content when less verbose.
    buffer_.clear ();
  }

  // --------------------------------------------------------------------------

  const char*
  reporter_human::get_comment_prefix (void)
  {
    return "";
  }

  /**
   * @details
   * This method outputs the prefix for a passing test result, applying the
   * appropriate colour formatting and symbols to clearly indicate success. If
   * the output occurs within a test case, additional indentation is applied
   * for readability. The prefix includes a tick symbol (`✓`) and, if provided,
   * an associated message. Colour formatting is reset after the prefix to
   * maintain consistent output style across all test cases and folders.
   *
   * The prefix/suffix methods help shorten the code
   * generated by the template methods.
   */
  void
  reporter_human::output_pass_prefix_ (std::string& message,
                                       [[maybe_unused]] subtest& subtest)
  {
    size_t level = subtest.nesting_depth ();

    *this << indent (level + 1);
    *this << colours_.pass << "✓" << colours_.none << " ";
    if (!message.empty ())
      {
        *this << message.c_str ();
      }
  }

  /**
   * @details
   * The `endl` function acts as a stream manipulator for the `reporter`,
   * inserting a line ending into the output buffer and flushing the current
   * content if necessary. This ensures that test report output is clearly
   * separated and formatted, improving readability and professionalism in the
   * presentation of test results.
   *
   * Using `endl` in conjunction with the `reporter` output operators
   * provides a familiar and convenient mechanism for managing line breaks,
   * similar to standard C++ stream manipulators.
   *
   * The prefix/suffix methods help shorten the code
   * generated by the template methods.
   */
  void
  reporter_human::output_pass_suffix_ ([[maybe_unused]] subtest& subtest)
  {
    *this << endl;

    flush ();
  }

  /**
   * @details
   * This method outputs the prefix for a failing test result, applying the
   * appropriate colour formatting and symbols to clearly indicate failure. If
   * the output occurs within a test case, additional indentation is applied
   * for readability. The prefix includes a cross symbol (`✗`), an optional
   * message, and the label "FAILED". The source location is appended in
   * parentheses, showing the file or folder name and line number where the
   * failure occurred. Colour formatting is reset after the prefix to maintain
   * consistent output style across all test cases and folders.
   */
  void
  reporter_human::output_fail_prefix_ (
      std::string& message, const bool hasExpression,
      const reflection::source_location& location,
      [[maybe_unused]] subtest& subtest)
  {
    size_t level = subtest.nesting_depth ();

    *this << indent (level + 1);
    *this << colours_.fail << "✗" << colours_.none << " ";
    if (!message.empty ())
      {
        *this << message.c_str ();
        *this << " ";
      }
    *this << colours_.fail << "FAILED" << colours_.none;
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wsign-conversion"
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wnarrowing"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#endif
    *this << " (" << reflection::short_name (location.file_name ()) << ":"
          << type_traits::genuine_integral_value<unsigned int>{
               location.line ()
             };
#pragma GCC diagnostic pop
    if (hasExpression)
      {
        *this << ", ";
      }
  }

  /**
   * @details
   * This method outputs the suffix for a failing test result by closing the
   * location information, appending an "aborted..." message if the test was
   * aborted, and then adding a newline to the test output. The output stream
   * is flushed to ensure immediate visibility. This approach guarantees that
   * failure results are clearly separated, promptly reported, and easily
   * distinguishable across all test cases and folders.
   */
  void
  reporter_human::output_fail_suffix_ (
      [[maybe_unused]] const reflection::source_location& location, bool abort,
      [[maybe_unused]] subtest& subtest)
  {
    *this << ")";
    if (abort)
      {
        *this << " aborted...";
      }
    *this << endl;

    flush ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

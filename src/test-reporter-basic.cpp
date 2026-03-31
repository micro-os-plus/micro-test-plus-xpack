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
 * @brief C++ source file with implementations for the µTest++ basic test
 * reporter methods.
 *
 * @details
 * This source file contains the implementations for `test_reporter_basic`,
 * the default concrete implementation of the `test_reporter` abstract
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

  test_reporter_basic::test_reporter_basic (void)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
    colors_ = colors_red_green;
  }

  test_reporter_basic::~test_reporter_basic ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
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
  test_reporter_basic&
  test_reporter_basic::operator<< (indent_t m)
  {
    out_.append (m.level * indent_size, ' ');
    return *this;
  }

  // --------------------------------------------------------------------------

  void
  test_reporter_basic::begin_session ([[maybe_unused]] runner& runner)
  {
    // Nothing to do.
  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
  void
  test_reporter_basic::end_session ([[maybe_unused]] runner& runner)
  {
    // Nothing to do.
  }
#pragma GCC diagnostic pop

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
  test_reporter_basic::begin_test_suite (test_suite_base& test_suite)
  {
    if (add_empty_line)
      {
        flush ();
        printf ("\n");
      }

    if (verbosity == verbosity::silent || verbosity == verbosity::quiet)
      {
        add_empty_line = false;
        return;
      }

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("• %s - test suite started\n", test_suite.name ());
#pragma GCC diagnostic pop

    add_empty_line = true;
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
  test_reporter_basic::end_test_suite (test_suite_base& test_suite)
  {
    if (verbosity == verbosity::silent)
      {
        return;
      }

    if (test_suite.totals.executed_test_cases () > 0
        && verbosity != verbosity::quiet)
      {
        printf ("\n");
        add_empty_line = true;
      }

    // Also fail if none passed.
    if (test_suite.totals.failed_checks () == 0
        && test_suite.totals.successful_checks () != 0)
      {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
        printf (
            "%s✓%s %s - test suite passed (%zu check%s in %zu test case%s)\n",
            colors_.pass, colors_.none, test_suite.name (),
            test_suite.totals.successful_checks (),
            test_suite.totals.successful_checks () == 1 ? "" : "s",
            test_suite.totals.executed_test_cases (),
            test_suite.totals.executed_test_cases () == 1 ? "" : "s");
#pragma GCC diagnostic pop
      }
    else
      {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
        printf ("%s✗%s %s - test suite %sFAILED%s (%zu check%s passed, %zu "
                "failed, "
                "in %zu test case%s)\n",
                colors_.fail, colors_.none, test_suite.name (), colors_.fail,
                colors_.none, test_suite.totals.successful_checks (),
                test_suite.totals.successful_checks () == 1 ? "" : "s",
                test_suite.totals.failed_checks (),
                test_suite.totals.executed_test_cases (),
                test_suite.totals.executed_test_cases () == 1 ? "" : "s");
#pragma GCC diagnostic pop
      }

    flush ();
  }

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
  test_reporter_basic::begin_test_case (
      [[maybe_unused]] test_case_base& test_case)
  {
    if (!out_.empty ())
      {
        // Each test should start with an empty buffer.
        output ();
        abort ();
      }

    // TODO: remove it if the previous test proves it is useless.
    if (!out_.empty () && (verbosity == verbosity::verbose))
      {
        if (add_empty_line)
          {
            printf ("\n");
          }
        output ();
        add_empty_line = true;
      }

    out_.clear ();

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
  test_reporter_basic::end_test_case (
      [[maybe_unused]] test_case_base& test_case)
  {
    if (verbosity == verbosity::normal || verbosity == verbosity::verbose)
      {
        std::string indent (indent_size * test_case.nesting_depth (), ' ');

        if (test_case.totals.failed_checks () > 0)
          {
            if (true /* add_empty_line */)
              {
                printf ("\n");
              }
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
            printf ("%s• %s - test case started\n", indent.c_str (),
                    test_case.name ());
            output ();
            printf (
                "%s%s✗%s %s - test case %sFAILED%s (%zu check%s passed, %zu "
                "failed)\n",
                indent.c_str (), colors_.fail, colors_.none, test_case.name (),
                colors_.fail, colors_.none,
                test_case.totals.successful_checks (),
                test_case.totals.successful_checks () == 1 ? "" : "s",
                test_case.totals.failed_checks ());
#pragma GCC diagnostic pop
            add_empty_line = true;
          }
        else
          {
            if (add_empty_line)
              {
                printf ("\n");
              }
            if (verbosity == verbosity::verbose)
              {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
                printf ("%s• %s - test case started\n", indent.c_str (),
                        test_case.name ());
                output ();
                printf ("%s%s✓%s %s - test case passed (%zu check%s)\n",
                        indent.c_str (), colors_.pass, colors_.none,
                        test_case.name (),
                        test_case.totals.successful_checks (),
                        test_case.totals.successful_checks () == 1 ? "" : "s");
#pragma GCC diagnostic pop
                add_empty_line = true;
              }
            else
              {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
                printf ("%s%s✓%s %s - test case passed (%zu check%s)\n",
                        indent.c_str (), colors_.pass, colors_.none,
                        test_case.name (),
                        test_case.totals.successful_checks (),
                        test_case.totals.successful_checks () == 1 ? "" : "s");
#pragma GCC diagnostic pop

                add_empty_line = false;
              }
          }
      }

    out_.clear ();
    flush ();

    is_in_test_case_ = false;
  }

  // --------------------------------------------------------------------------

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
  test_reporter_basic::output_pass_prefix_ (
      std::string& message, [[maybe_unused]] test_case_base& test_case)
  {
    size_t level = test_case.nesting_depth ();

    *this << colors_.pass;
    *this << indent (level + 1) << "✓ ";
    *this << colors_.none;
    if (!message.empty ())
      {
        *this << message.c_str ();
      }
  }

  /**
   * @details
   * The `endl` function acts as a stream manipulator for the `test_reporter`,
   * inserting a line ending into the output buffer and flushing the current
   * content if necessary. This ensures that test report output is clearly
   * separated and formatted, improving readability and professionalism in the
   * presentation of test results.
   *
   * Using `endl` in conjunction with the `test_reporter` output operators
   * provides a familiar and convenient mechanism for managing line breaks,
   * similar to standard C++ stream manipulators.
   *
   * The prefix/suffix methods help shorten the code
   * generated by the template methods.
   */
  void
  test_reporter_basic::output_pass_suffix_ (
      [[maybe_unused]] test_case_base& test_case)
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
  test_reporter_basic::output_fail_prefix_ (
      std::string& message, const bool hasExpression,
      const reflection::source_location& location,
      [[maybe_unused]] test_case_base& test_case)
  {
    size_t level = test_case.nesting_depth ();

    *this << colors_.fail;
    *this << indent (level + 1) << "✗ ";
    *this << colors_.none;
    if (!message.empty ())
      {
        *this << message.c_str ();
        *this << " ";
      }
    *this << colors_.fail << "FAILED" << colors_.none;
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
  test_reporter_basic::output_fail_suffix_ (
      [[maybe_unused]] const reflection::source_location& location, bool abort,
      [[maybe_unused]] test_case_base& test_case)
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

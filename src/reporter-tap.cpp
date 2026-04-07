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

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

#include <time.h>

// ----------------------------------------------------------------------------

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif

// =============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  reporter_tap::reporter_tap (int argc, char* argv[]) : reporter{ argc, argv }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
  }

  reporter_tap::~reporter_tap ()
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
   * corresponding to `m.level` four-space indentation levels. It enables
   * structured, readable nesting of suite output across all test cases and
   * folders by allowing `*this << indent(n) << "text"` chaining.
   */
  reporter_tap&
  reporter_tap::operator<< (indent_t m)
  {
    buffer_.append (m.level * indent_size, ' ');
    return *this;
  }

  // --------------------------------------------------------------------------

  void
  reporter_tap::begin_session ([[maybe_unused]] runner& runner)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (verbosity != verbosity::silent)
      {
        printf ("\n");
      }

    write_info ();

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

    const char* message = "TAP version 14\n";
    if (output_file_ != nullptr)
      {
        fprintf (output_file_, "%s", message);
      }

    if (verbosity != verbosity::silent)
      {
        printf ("%s", message);

        flush ();
      }

#pragma GCC diagnostic pop

    add_empty_line_ = false;
  }

  void
  reporter_tap::end_session (runner& runner_)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    size_t total_suites_count = runner_.total_suites_count ();

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

    char message_summary[32];
    snprintf (message_summary, sizeof (message_summary), "1..%zu\n",
              total_suites_count);

    long milliseconds = 0;
    long microseconds = 0;
    if (runner_.timings.has_timestamps ())
      {
        runner_.timings.compute_elapsed_time (milliseconds, microseconds);
      }

    char message_totals[160];
    snprintf (message_totals, sizeof (message_totals),
              "# { total: %zu check%s passed, %zu failed, in %zu test "
              "case%s, %zu test suite%s",
              runner_.totals.successful_checks (),
              runner_.totals.successful_checks () == 1 ? "" : "s",
              runner_.totals.failed_checks (),
              runner_.totals.executed_subtests (),
              runner_.totals.executed_subtests () == 1 ? "" : "s",
              total_suites_count, total_suites_count == 1 ? "" : "s");

    char message_time[120] = "";
    if (milliseconds > 0 || microseconds > 0)
      {
        snprintf (message_time, sizeof (message_time), ", time: %ld.%03ld ms",
                  milliseconds, microseconds);
      }

    if (output_file_ != nullptr)
      {
        fprintf (output_file_, "%s%s }\n", message_summary, message_totals);
      }

    if (verbosity != verbosity::silent)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

        if (verbosity != verbosity::quiet)
          {
            printf ("%s", message_summary);
          }
        else
          {
            // With quiet verbosity, there are no ok/not ok lines, so the TAP
            // plan should look like a skipped test.
            printf ("1..0\n");
          }

        printf ("%s%s }\n", message_totals, message_time);

#pragma GCC diagnostic pop

        flush ();
      }
  }

  // --------------------------------------------------------------------------

  void
  reporter_tap::begin_suite (suite& suite)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

    char message_subtest[120];
    snprintf (message_subtest, sizeof (message_subtest), "# Subtest: %s\n",
              suite.name ());

    if (output_file_ != nullptr)
      {
        fprintf (output_file_, "%s", message_subtest);
      }

    if (verbosity == verbosity::normal || verbosity == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

        printf ("%s", message_subtest);

        flush ();

        add_empty_line_ = true;
      }

#pragma GCC diagnostic pop
  }

  void
  reporter_tap::end_suite (suite& suite)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

    std::string indent (indent_size, ' ');

    char message_summary[40];
    snprintf (message_summary, sizeof (message_summary), "%s1..%zu\n",
              indent.c_str (), suite.children_subtests_count ());

    long milliseconds = 0;
    long microseconds = 0;
    if (suite.timings.has_timestamps ())
      {
        suite.timings.compute_elapsed_time (milliseconds, microseconds);
      }

    char message_totals[120];
    if (suite.totals.was_successful ()) [[likely]]
      {
        snprintf (message_totals, sizeof (message_totals),
                  "ok %zu - %s # { passed, %zu check%s in %zu "
                  "test case%s",
                  suite.own_index (), suite.name (),
                  suite.totals.successful_checks (),
                  suite.totals.successful_checks () == 1 ? "" : "s",
                  suite.totals.executed_subtests (),
                  suite.totals.executed_subtests () == 1 ? "" : "s");
      }
    else
      {
        snprintf (message_totals, sizeof (message_totals),
                  "not ok %zu - %s # { FAILED, %zu check%s "
                  "passed, %zu failed, in %zu test case%s",
                  suite.own_index (), suite.name (),
                  suite.totals.successful_checks (),
                  suite.totals.successful_checks () == 1 ? "" : "s",
                  suite.totals.failed_checks (),
                  suite.totals.executed_subtests (),
                  suite.totals.executed_subtests () == 1 ? "" : "s");
      }

    char message_time[120] = "";
    if (milliseconds > 0 || microseconds > 0)
      {
        snprintf (message_time, sizeof (message_time), ", time: %ld.%03ld ms",
                  milliseconds, microseconds);
      }

    if (output_file_ != nullptr)
      {
        write_buffer_to_file ();

        fprintf (output_file_, "%s%s }\n", message_summary, message_totals);
      }

    // At this point, the buffer may contain output from the test case, which
    // should be displayed.
    if (verbosity == verbosity::normal || verbosity == verbosity::verbose)
      {
        if (add_empty_line_ && suite.totals.executed_subtests () > 0)
          {
            printf ("\n");
          }

        if (suite.totals.was_successful ()) [[likely]]
          {
            // Successful test suite.

            if (verbosity == verbosity::verbose)
              {
                // With verbosity, show full TAP output accumulated in the
                // buffer.
                write_buffer_to_stdout ();
              }

            printf ("%s%s%s }\n", message_summary, message_totals,
                    message_time);
          }
        else
          {
            // Failed test suite.

            // Show full TAP output accumulated in the buffer for failed suite
            // cases, as it may contain useful information about the failure.
            write_buffer_to_stdout ();

            printf ("%s%s%s }\n", message_summary, message_totals,
                    message_time);
          }

        flush ();
      }

#pragma GCC diagnostic pop

    buffer_.clear ();

    add_empty_line_ = true;
  }

  // --------------------------------------------------------------------------

  void
  reporter_tap::begin_subtest (subtest& subtest)
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
        write_buffer_to_stdout ();
        abort ();
      }

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

    std::string indent (indent_size * subtest.nesting_depth (), ' ');

    char message_subtest[120];
    snprintf (message_subtest, sizeof (message_subtest), "%s# Subtest: %s\n",
              indent.c_str (), subtest.name ());

    if (output_file_ != nullptr)
      {
        fprintf (output_file_, "%s", message_subtest);
      }

    if (verbosity == verbosity::normal || verbosity == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

        printf ("%s", message_subtest);

        flush ();

        add_empty_line_ = false;
      }

#pragma GCC diagnostic pop
  }

  void
  reporter_tap::end_subtest (subtest& subtest)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, subtest.name (),
            subtest.nesting_depth ());
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

    std::string indent (indent_size * subtest.nesting_depth (), ' ');
    std::string indent2 (indent_size * (subtest.nesting_depth () + 1), ' ');

    char message_summary[40];
    snprintf (message_summary, sizeof (message_summary), "%s1..%zu\n",
              indent2.c_str (),
              subtest.totals.executed_checks ()
                  + subtest.totals.executed_subtests ());

    char message_totals[120];
    if (subtest.totals.was_successful ()) [[likely]]
      {
        snprintf (message_totals, sizeof (message_totals),
                  "%sok %zu - %s # { passed, %zu check%s }\n", indent.c_str (),
                  subtest.own_index (), subtest.name (),
                  subtest.totals.successful_checks (),
                  subtest.totals.successful_checks () == 1 ? "" : "s");
      }
    else
      {
        snprintf (message_totals, sizeof (message_totals),
                  "%snot ok %zu - %s # { FAILED, %zu check%s "
                  "passed, %zu failed }\n",
                  indent.c_str (), subtest.own_index (), subtest.name (),
                  subtest.totals.successful_checks (),
                  subtest.totals.successful_checks () == 1 ? "" : "s",
                  subtest.totals.failed_checks ());
      }

    if (output_file_ != nullptr)
      {
        write_buffer_to_file ();

        fprintf (output_file_, "%s%s", message_summary, message_totals);
      }

    // At this point, the buffer may contain output from the subtest, which
    // should be displayed.
    if (verbosity == verbosity::normal || verbosity == verbosity::verbose)
      {
        if (add_empty_line_)
          {
            printf ("\n");
          }

        if (subtest.totals.was_successful ()) [[likely]]
          {
            // Successful subtest.
            if (verbosity == verbosity::verbose)
              {
                // With verbosity, show full TAP output accumulated in the
                // buffer.
                write_buffer_to_stdout ();

                printf ("%s", message_summary);
              }
            else
              {
                // Without verbosity, show only the summary line
                // and count only subtests, not checks, as the TAP output is
                // not shown.
                printf ("%s1..%zu\n", indent2.c_str (),
                        subtest.children_subtests_count ());
              }

            printf ("%s", message_totals);
          }
        else
          {
            // Failed subtest.

            // Show full TAP output accumulated in the buffer for failed
            // subtests, as it may contain useful information about the
            // failure.
            write_buffer_to_stdout ();

            printf ("%s%s", message_summary, message_totals);
          }

        flush ();
      }

#pragma GCC diagnostic pop

    buffer_.clear ();

    add_empty_line_ = true;
  }

  // --------------------------------------------------------------------------

  const char*
  reporter_tap::get_comment_prefix (void)
  {
    return "# ";
  }

  /**
   * @details
   * This method outputs the prefix for a passing suite result, applying the
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
   * The `endl` function acts as a stream manipulator for the `reporter`,
   * inserting a line ending into the output buffer and flushing the current
   * content if necessary. This ensures that suite report output is clearly
   * separated and formatted, improving readability and professionalism in the
   * presentation of suite results.
   *
   * Using `endl` in conjunction with the `reporter` output operators
   * provides a familiar and convenient mechanism for managing line breaks,
   * similar to standard C++ stream manipulators.
   *
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
   * This method outputs the prefix for a failing suite result, applying the
   * appropriate colour formatting and symbols to clearly indicate failure. If
   * the output occurs within a test case, additional indentation is applied
   * for readability. The prefix includes a cross symbol (`✗`), an optional
   * message, and the label "FAILED". The source location is appended in
   * parentheses, showing the file or folder name and line number where the
   * failure occurred. Colour formatting is reset after the prefix to maintain
   * consistent output style across all test cases and folders.
   */
  void
  reporter_tap::output_fail_prefix_ (
      std::string& message, [[maybe_unused]] const bool hasExpression,
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
    if (hasExpression)
      {
        *this << endl;
        *this << indent (level + 1) << "  condition: ";
      }
  }

  /**
   * @details
   * This method outputs the suffix for a failing suite result by closing the
   * location information, appending an "aborted..." message if the suite was
   * aborted, and then adding a newline to the suite output. The output stream
   * is flushed to ensure immediate visibility. This approach guarantees that
   * failure results are clearly separated, promptly reported, and easily
   * distinguishable across all test cases and folders.
   */
  void
  reporter_tap::output_fail_suffix_ (
      const reflection::source_location& location, bool abort,
      [[maybe_unused]] subtest& subtest)
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
    *this << indent (level + 1) << "    line: "
          << type_traits::genuine_integral_value<unsigned int>{ location
                                                                    .line () }
          << endl;

    *this << indent (level + 1) << "  ..." << endl;

    flush ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

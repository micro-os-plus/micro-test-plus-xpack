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
 * @brief C++ source file with implementations for the µTest++ test reporter
 * member functions.
 *
 * @details
 * This source file contains the core implementations for the test reporting
 * facilities of the µTest++ framework. It provides lifecycle and utility
 * behaviour for reporters, including output-file handling, informational
 * banner emission, buffering helpers, stream operators, the formatting of
 * the totals and of the elapsed times, and pass/fail dispatch to
 * reporter-specific prefix/suffix hooks. The command-line options are
 * parsed by the runner.
 *
 * Concrete formatting behaviour is implemented by derived reporters
 * (`reporter_human` and `reporter_tap`).
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace, since the reporters
 * are internal to the framework.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/counters.h"
#include "micro-os-plus/micro-test-plus/reporter.h"
#include "micro-os-plus/micro-test-plus/runner.h"
#include "micro-os-plus/micro-test-plus/stopwatch.h"
#include "micro-os-plus/micro-test-plus/test.h"
#include "micro-os-plus/micro-test-plus/utility.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

#include <cstdarg>
// For the PRIu32 macro used in snprintf() formatting of uint32_t values.
#include <cinttypes>
#include <limits>

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
   * @brief Local helpers of the reporter base class.
   *
   * @details
   * The unnamed namespace gives the helpers internal linkage, so that they
   * are visible only in this translation unit, and cannot conflict with
   * the names of the application or of the other source files of the
   * framework. They are not declared in any header.
   *
   * The namespace is opened twice in this file, each time before the
   * code that uses its helpers; Doxygen merges the two parts. The first
   * part contains `write_without_colours()`, which copies the console
   * output to the output file. The second part contains the helpers of
   * the totals lines: `fragment_size`, `plural()`, and
   * `format_skipped()`.
   */
  namespace
  {
    /**
     * @brief Writes a text to a file, without the ANSI colour sequences.
     *
     * @details
     * The text may contain ANSI colour sequences, added when the console
     * is a terminal, which must not reach the file. They are removed
     * while writing: each `ESC [`, followed by any digits and semicolons,
     * and terminated by `m`, is skipped, and the text between the
     * sequences is written unchanged. Any other use of `ESC` is written
     * as is. No line ending is appended.
     *
     * @param file The file to write to; must not be null.
     * @param text The text to write.
     * @par Returns
     *   Nothing.
     */
    void
    write_without_colours (FILE* file, std::string_view text)
    {
      size_t start = 0;
      size_t pos = text.find ('\033');
      while (pos != std::string_view::npos)
        {
          // Parse `ESC [ <digits and semicolons> m`.
          size_t end = pos + 1;
          if (end < text.size () && text[end] == '[')
            {
              ++end;
              while (end < text.size ()
                     && ((text[end] >= '0' && text[end] <= '9')
                         || text[end] == ';'))
                {
                  ++end;
                }
              if (end < text.size () && text[end] == 'm')
                {
                  // A colour sequence; write the preceding text and skip
                  // it.
                  const std::string_view chunk
                      = text.substr (start, pos - start);
                  fwrite (chunk.data (), 1, chunk.size (), file);
                  start = end + 1;
                }
            }
          pos = text.find ('\033', pos + 1);
        }

      const std::string_view chunk = text.substr (start);
      fwrite (chunk.data (), 1, chunk.size (), file);
    }
  } // namespace

  // --------------------------------------------------------------------------

  /**
   * @details
   * Copies the verbosity and the view of the command-line arguments from
   * the session options, and opens the output file, if a non-empty path
   * was given, keeping a copy of the path. If the file cannot be opened,
   * an error message is written to `stderr`, the report is written only to
   * the console, and `has_output_file_error()` returns `true`. The
   * internal string buffer is pre-allocated to reduce dynamic allocation
   * overhead.
   */
  reporter::reporter (const runner_options& opts)
      : verbosity_{ opts.verbosity_level }, arguments_{ opts.arguments }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

    if (opts.output_file_path != nullptr && opts.output_file_path[0] != '\0')
      {
        output_file_ = fopen (opts.output_file_path, "w");
        if (output_file_ == nullptr)
          {
            fprintf (stderr, "error: Failed to open output file '%s'\n",
                     opts.output_file_path);
            has_output_file_error_ = true;
          }
        else
          {
            output_file_path_ = opts.output_file_path;
          }
      }

    // Pre-allocate buffer to reduce dynamic allocations.
    buffer_.reserve (128);
  }

  /**
   * @details
   * If an output file was opened, it is flushed and closed, and a
   * confirmation message naming the output file is written to `stdout`,
   * except with the `silent` verbosity, which writes nothing to the
   * console. If tracing is enabled, the function signature is output for
   * diagnostic purposes.
   */
  reporter::~reporter ()
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

    if (output_file_ != nullptr)
      {
        fflush (output_file_);
        fclose (output_file_);

        if (verbosity_ != verbosity::silent)
          {
            write_console ("Test output written to '%s'.\n",
                           output_file_path_.c_str ());
          }

        output_file_ = nullptr;
        output_file_path_.clear ();
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * The `endl` function calls `reporter::end_line()`, which appends a
   * newline character to the buffer of the specified `reporter`.
   */
  reporter&
  endl (reporter& stream)
  {
    stream.end_line ();
    return stream;
  }

  /**
   * @details
   * This member function appends a newline character to the internal output
   * buffer of the `reporter`. The buffer itself is written later, by the
   * concrete reporters, at the end of each test case or suite, which then
   * also flush the streams.
   */
  void
  reporter::end_line (void)
  {
    buffer_.append ("\n");
  }

  /**
   * @details
   * The file receives all the records, when it is open, so that its
   * content does not depend on the verbosity (a file of a `silent` run is
   * as complete as that of a `verbose` one). The console follows the
   * verbosity levels, as documented in the declaration.
   */
  output_route
  reporter::route (record_kind kind) const noexcept
  {
    bool console;
    if (kind == record_kind::failed_check || kind == record_kind::total
        || kind == record_kind::abort)
      {
        console = (verbosity_ != verbosity::silent);
      }
    else if (kind == record_kind::test_case_heading
             || kind == record_kind::passed_check)
      {
        console = (verbosity_ == verbosity::verbose);
      }
#if defined(MICRO_OS_PLUS_STARTUP_ENABLED) \
    && defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)
    else if (kind == record_kind::info)
      {
        // The startup code already displays this information.
        console = false;
      }
#endif // defined(MICRO_OS_PLUS_STARTUP_ENABLED) && ...
    else
      {
        console = (verbosity_ == verbosity::normal
                   || verbosity_ == verbosity::verbose);
      }

    return { console, output_file_ != nullptr };
  }

  /**
   * @details
   * The passed checks are written to the output file, when it is open,
   * whatever the verbosity; to the console only with the verbose
   * verbosity level. With the normal verbosity, only the failed checks
   * (with the names of the open test cases) are displayed, so the passed
   * checks are only counted, without formatting them.
   */
  bool
  reporter::writes_passed_checks (void) const noexcept
  {
    return output_file_ != nullptr || verbosity_ == verbosity::verbose;
  }

  /**
   * @details
   * The quiet verbosity displays the failed checks, and the buffer may
   * also contain the passed checks, for the output file; the lines of the
   * failed checks are therefore kept separately, in `failures_`.
   */
  std::string_view
  reporter::console_lines (bool failed) const noexcept
  {
    if (verbosity_ == verbosity::verbose)
      {
        return buffer_;
      }
    if (verbosity_ == verbosity::normal)
      {
        return failed ? std::string_view{ buffer_ } : std::string_view{};
      }
    if (verbosity_ == verbosity::quiet)
      {
        return failures_;
      }
    return {};
  }

  /**
   * @details
   * The text is written with its size, not as a C string, so that a zero
   * character in a message does not end the output.
   */
  void
  reporter::write_console_text (std::string_view text)
  {
    // Pass only the text, do not add an `\n` here.
    fwrite (text.data (), 1, text.size (), stdout);
  }

  /**
   * @details
   * Only the quiet verbosity needs the copy, since the other levels
   * display the buffer as a whole, or nothing.
   */
  void
  reporter::mark_failure (size_t begin)
  {
    if (verbosity_ == verbosity::quiet)
      {
        failures_.append (buffer_, begin, std::string::npos);
      }
    buffer_has_failures_ = true;
  }

  /**
   * @details
   * Records the suite and whether its heading was displayed; the
   * quiet verbosity displays it later, if the suite has a failure.
   */
  void
  reporter::enter_suite (const suite& suite, bool displayed)
  {
    current_suite_ = &suite;
    suite_displayed_ = displayed;
  }

  /**
   * @details
   * Writes the contents of `buffer_` to `output_file_` without appending
   * a newline. If `output_file_` is null, the call is a no-op.
   *
   * The buffer may contain ANSI colour sequences, added when the console
   * is a terminal, which must not reach the file; they are removed by
   * `write_without_colours()`.
   */
  void
  reporter::write_buffer_to_file (void)
  {
    if (output_file_ == nullptr)
      {
        return;
      }

    // Pass only the string, do not add an `\n` here.
    write_without_colours (output_file_, buffer_);
  }

  /**
   * @details
   * The arguments are forwarded to `vfprintf()` on `stdout`. The stream
   * is explicit, so the compiler does not rewrite the call into
   * `puts()` or `putchar()`, and all console output shares the same
   * `FILE`-based path.
   */
  void
  reporter::write_console (const char* format, ...)
  {
    va_list args;
    va_start (args, format);
    vfprintf (stdout, format, args);
    va_end (args);
  }

  /**
   * @details
   * The arguments are forwarded to `vfprintf()` on `output_file_`. If
   * `output_file_` is null, the arguments are ignored.
   */
  void
  reporter::write_file (const char* format, ...)
  {
    if (output_file_ == nullptr)
      {
        return;
      }

    va_list args;
    va_start (args, format);
    vfprintf (output_file_, format, args);
    va_end (args);
  }

  /**
   * @details
   * The text is formatted with `vsnprintf()` into a local array, which
   * holds the usual lines without an allocation; a longer text, for
   * example with a long test name, is formatted again, from a copy of the
   * arguments, into a string of the exact length. The array is kept
   * small, since the lines that end the nested test cases are written at
   * the deepest point of the stack. The text is then
   * written with its length to the output file, without the colour
   * sequences (see `write_without_colours()`), and, when requested, to
   * `stdout`, unchanged. When there is nowhere to write, or the
   * formatting fails, nothing is written.
   */
  void
  reporter::write_line (bool to_console, const char* format, ...)
  {
    if (output_file_ == nullptr && !to_console)
      {
        return;
      }

    va_list args;
    va_start (args, format);
    va_list args_copy;
    va_copy (args_copy, args);

    char local_text[128];
    const int length
        = vsnprintf (local_text, sizeof (local_text), format, args);
    va_end (args);

    if (length < 0)
      {
        va_end (args_copy);
        return;
      }

    const size_t size = static_cast<size_t> (length);
    std::string long_text;
    std::string_view text{ local_text, size };
    if (size >= sizeof (local_text))
      {
        // The terminating null character is written over the one kept by
        // the string after its content.
        long_text.resize (size);
        vsnprintf (long_text.data (), size + 1, format, args_copy);
        text = long_text;
      }
    va_end (args_copy);

    if (output_file_ != nullptr)
      {
        write_without_colours (output_file_, text);
      }

    if (to_console)
      {
        fwrite (text.data (), 1, text.size (), stdout);
      }
  }

  /**
   * @details
   * Constructs and emits two informational lines, each prefixed by
   * `comment_prefix()`: the first lists the program name (without
   * the path) and any command-line arguments; the second identifies the
   * compiler (Clang, GCC, or MSVC) together with the version string,
   * floating-point availability on bare-metal targets, exception support,
   * and any active debug or trace macros. Both lines are written to the
   * output file when one is open, and to `stdout` when the verbosity is
   * `normal` or `verbose` (see `route()`), except when both
   * `MICRO_OS_PLUS_STARTUP_ENABLED` and `MICRO_OS_PLUS_DIAG_TRACE_ENABLED`
   * are defined, since the startup code already displays this
   * information.
   */
  void
  reporter::write_info (void)
  {
    const bool to_console = route (record_kind::info).console;

    if (!arguments_.empty ())
      {
        std::string line;
        line.reserve (256);
        line.append (comment_prefix ());
        line.append ("Running: ");

        // Append only the file name part of argv[0].
        line.append (utility::extract_file_name (arguments_[0]));

        for (const char* argument : arguments_.subspan (1))
          {
            line.append (" ");
            line.append (argument);
          }
        line.append ("\n");

        write_line (to_console, "%s", line.c_str ());
      }

    {
      // Build the "Built with ..." line, including the compiler version
      // (via __VERSION__); the same line goes to the file and to stdout.
      std::string line;
      line.reserve (256);
      line.append (comment_prefix ());
      line.append ("Built with ");
#if defined(__clang__)
      line.append ("clang " __VERSION__);
#elif defined(__GNUC__)
      line.append ("GCC " __VERSION__);
#elif defined(_MSC_VER)
      line.append ("MSVC");
      char msvc_ver[16];
      snprintf (msvc_ver, sizeof (msvc_ver), " - %d", _MSC_VER);
      line.append (msvc_ver);
#else
      line.append ("an unknown compiler");
#endif // defined(__clang__)
#if !(defined(__APPLE__) || defined(__linux__) || defined(__unix__) \
      || defined(_WIN32))
      // This is relevant only on bare-metal.
#if defined(__ARM_PCS_VFP) || defined(__ARM_FP)
      line.append (", with FP");
#else
      line.append (", no FP");
#endif // defined(__ARM_PCS_VFP) || defined(__ARM_FP)
#endif // bare-metal only
#if defined(__cpp_exceptions)
      line.append (", with exceptions");
#else
      line.append (", no exceptions");
#endif // defined(__cpp_exceptions)
#if defined(MICRO_OS_PLUS_DEBUG_ENABLED)
      line.append (", with MICRO_OS_PLUS_DEBUG_ENABLED");
#endif // defined(MICRO_OS_PLUS_DEBUG_ENABLED)
#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)
      line.append (", with MICRO_OS_PLUS_DIAG_TRACE_ENABLED");
#endif // defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

      write_line (to_console, "%s\n", line.c_str ());
    }
  }

  /**
   * @details
   * This member function flushes the `stdout` stream and, if open, the output
   * file, so that everything already written to them becomes visible. It
   * does not write the contents of the internal buffer.
   */
  void
  reporter::flush_streams (void)
  {
    fflush (stdout);
    if (output_file_ != nullptr)
      {
        fflush (output_file_);
      }
  }

  /**
   * @details
   * Returns the flag set by the constructor when `fopen()` failed.
   */
  bool
  reporter::has_output_file_error (void) const noexcept
  {
    return has_output_file_error_;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * This operator overload enables manipulators, such as `endl`, to be used
   * with the `reporter` stream in a manner similar to standard C++
   * streams. When a manipulator function is passed, it is invoked with the
   * current `reporter` instance.
   */
  reporter&
  reporter::operator<< (reporter& (*func) (reporter&))
  {
    // Call the endl function.
    (*func) (*this);
    return *this;
  }

  /**
   * @details
   * This operator overload appends spaces to the internal output buffer,
   * `indent_size_` for each of the `m.level` indentation levels, allowing
   * `*this << indent(n) << "text"` chaining in both reporters.
   */
  reporter&
  reporter::operator<< (indentation m)
  {
    buffer_.append (m.level * indent_size_, ' ');
    return *this;
  }

  /**
   * @details
   * This operator overload appends the contents of the provided
   * `std::string_view` to the internal output buffer of the `reporter`.
   */
  reporter&
  reporter::operator<< (std::string_view sv)
  {
    buffer_.append (sv);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the specified character to the internal
   * output buffer of the `reporter`.
   */
  reporter&
  reporter::operator<< (char c)
  {
    buffer_.append (1, c);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the contents of the provided C-style string
   * to the internal output buffer of the `reporter`, or `"nullptr"` for a
   * null pointer, as the expression formatter does; the `char*` values also
   * reach this overload, and `std::string::append()` must not be called
   * with a null pointer.
   */
  reporter&
  reporter::operator<< (const char* s)
  {
    if (s == nullptr)
      {
        buffer_.append ("nullptr");
      }
    else
      {
        buffer_.append (s);
      }
    return *this;
  }

  /**
   * @details
   * This operator overload appends `"true"` or `"false"` to the internal
   * output buffer of the `reporter`, as the expression formatter does.
   * Being a non-template function, it is selected for `bool` values
   * instead of the arithmetic template, which would format them as
   * numbers.
   */
  reporter&
  reporter::operator<< (bool v)
  {
    buffer_.append (v ? "true" : "false");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string `"nullptr"` to the internal
   * output buffer of the `reporter`, as the expression formatter does.
   */
  reporter&
  reporter::operator<< (std::nullptr_t)
  {
    buffer_.append ("nullptr");
    return *this;
  }

  /**
   * @details
   * Outputs a pass prefix, followed by either the provided message or, if
   * the message is empty, the evaluated expression string itself. A pass
   * suffix is then appended to complete the output.
   */
  void
  reporter::pass (const std::string& message, const std::string& expression,
                  const test_case& test_case)
  {
    output_pass_prefix (message, test_case);

    if (message.empty ())
      {
        *this << expression;
      }

    output_pass_suffix (test_case);
  }

  /**
   * @details
   * Outputs a fail prefix (which includes the message and the source
   * location), followed, when `failure.has_expression` is true, by the
   * pre-formatted expression string, and a fail suffix.
   */
  void
  reporter::fail (const failure_info& failure, const std::string& expression,
                  const test_case& test_case)
  {
    const size_t begin = buffer_.size ();

    output_fail_prefix (failure.message, failure.has_expression,
                        failure.location, test_case);

    if (failure.has_expression)
      {
        *this << expression;
      }

    output_fail_suffix (failure.location, failure.kind, test_case);

    mark_failure (begin);
  }

  /**
   * @details
   * Empties `buffer_` and `failures_`, keeping their capacity, and resets
   * `buffer_has_failures_`.
   */
  void
  reporter::clear_buffer (void)
  {
    buffer_.clear ();
    failures_.clear ();
    buffer_has_failures_ = false;
  }

  /**
   * @details
   * The elapsed time, in microseconds, is displayed in milliseconds, with
   * three decimals. When it is zero, either because the stopwatch has no
   * readings or because the interval was shorter than a microsecond, the
   * text is empty.
   */
  void
  reporter::format_elapsed_time (const stopwatch& stopwatch,
                                 char (&message)[elapsed_time_size_])
  {
    const auto elapsed = stopwatch.elapsed ().count ();
    if (elapsed > 0)
      {
        snprintf (message, sizeof (message),
                  ", time: %" PRIu32 ".%03" PRIu32 " ms",
                  static_cast<uint32_t> (elapsed / 1000),
                  static_cast<uint32_t> (elapsed % 1000));
      }
    else
      {
        message[0] = '\0';
      }
  }

  // --------------------------------------------------------------------------

  namespace
  {
    /**
     * @brief Size of the array that receives a fragment of the totals.
     *
     * @details
     * Large enough for `", N test cases failed"`, the longest fragment
     * (20 characters and the count), and the terminator, with the count of
     * the largest `size_t` value (10 digits on 32-bit targets, 20 on
     * 64-bit ones, as in `", 18446744073709551615 test cases failed"`).
     */
    constexpr size_t fragment_size
        = 21 + (std::numeric_limits<size_t>::digits10 + 1);

    /**
     * @brief Returns the plural suffix for a count.
     *
     * @details
     * The totals lines are in English, where only the count 1 takes the
     * singular form.
     *
     * @param count The count that precedes the noun.
     * @return `""` for 1, and `"s"` otherwise.
     */
    constexpr const char*
    plural (size_t count) noexcept
    {
      return count == 1 ? "" : "s";
    }

    /**
     * @brief Formats the number of items skipped by the filter.
     *
     * @details
     * The text is `", <count> skipped"`, appended to the count of the
     * items, or empty when no item was skipped, so that the totals lines
     * of the runs without a filter are not longer.
     *
     * @param count The number of skipped items.
     * @param message The character array that receives the
     * null-terminated text.
     * @par Returns
     *   Nothing.
     */
    void
    format_skipped (size_t count, char (&message)[fragment_size])
    {
      if (count > 0)
        {
          snprintf (message, sizeof (message),
                    ", %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE " skipped",
                    count);
        }
      else
        {
          message[0] = '\0';
        }
    }
  } // namespace

  /**
   * @details
   * The suites are counted by `runner::total_suites_count()`, which
   * includes the suites skipped by the filter, counted separately by
   * `runner::skipped_suites_count()`.
   */
  void
  reporter::format_session_totals (const runner& runner,
                                   char (&message)[totals_size_])
  {
    // The fixed text, four counts, two fragments, and the terminator.
    static_assert (totals_size_
                       >= 54 + 4 * (std::numeric_limits<size_t>::digits10 + 1)
                              + 2 * (fragment_size - 1),
                   "totals_size_ too small for the session totals");

    const counters& totals = runner.totals ();
    const size_t suites_count = runner.total_suites_count ();

    char message_skipped_test_cases[fragment_size];
    format_skipped (totals.skipped_test_cases (), message_skipped_test_cases);

    char message_skipped_suites[fragment_size];
    format_skipped (runner.skipped_suites_count (), message_skipped_suites);

    snprintf (message, sizeof (message),
              "%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
              " check%s passed, %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
              " failed, in %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
              " test case%s%s, %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE " "
              "test suite%s%s",
              totals.passed_checks (), plural (totals.passed_checks ()),
              totals.failed_checks (), totals.executed_test_cases (),
              plural (totals.executed_test_cases ()),
              message_skipped_test_cases, suites_count, plural (suites_count),
              message_skipped_suites);
  }

  /**
   * @details
   * A passed suite has no failed checks, so only the number of checks is
   * shown.
   */
  void
  reporter::format_suite_totals (const suite& suite,
                                 char (&message)[totals_size_])
  {
    const counters& totals = suite.totals ();

    char message_skipped[fragment_size];
    format_skipped (totals.skipped_test_cases (), message_skipped);

    if (totals.passed ()) [[likely]]
      {
        snprintf (message, sizeof (message),
                  "%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                  " check%s in %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                  " test case%s%s",
                  totals.passed_checks (), plural (totals.passed_checks ()),
                  totals.executed_test_cases (),
                  plural (totals.executed_test_cases ()), message_skipped);
      }
    else
      {
        snprintf (message, sizeof (message),
                  "%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                  " check%s passed, %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                  " failed, in %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                  " test case%s%s",
                  totals.passed_checks (), plural (totals.passed_checks ()),
                  totals.failed_checks (), totals.executed_test_cases (),
                  plural (totals.executed_test_cases ()), message_skipped);
      }
  }

  /**
   * @details
   * A passed test case has no failed checks and no failed nested test
   * cases, so only the number of checks is shown.
   */
  void
  reporter::format_test_case_totals (const test_case& test_case,
                                     char (&message)[totals_size_])
  {
    const counters& totals = test_case.totals ();

    if (totals.passed ()) [[likely]]
      {
        snprintf (message, sizeof (message),
                  "%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE " check%s",
                  totals.passed_checks (), plural (totals.passed_checks ()));
      }
    else
      {
        char message_test_cases[fragment_size] = "";
        if (totals.failed_test_cases () > 0)
          {
            snprintf (message_test_cases, sizeof (message_test_cases),
                      ", %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                      " test case%s failed",
                      totals.failed_test_cases (),
                      plural (totals.failed_test_cases ()));
          }

        snprintf (message, sizeof (message),
                  "%" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                  " check%s passed, %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                  " failed%s",
                  totals.passed_checks (), plural (totals.passed_checks ()),
                  totals.failed_checks (), message_test_cases);
      }
  }

  /**
   * @details
   * For a nested test case, the outer test case may have performed
   * checks before it; their results are written first, by
   * `commit_buffer()`. For a top-level test case, the buffer is expected
   * to be empty, since the checks are performed only by the test cases,
   * and each one writes its results when it ends; should it not be, its
   * content is written in the same way, rather than lost or attributed
   * to the next test case, and the run continues.
   */
  void
  reporter::commit_outer_results (void)
  {
    if (!buffer_.empty ())
      {
        commit_buffer ();
      }
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

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
 * @brief C++ source file with implementations for the µTest++ test reporter
 * methods.
 *
 * @details
 * This source file contains the core implementations for the test reporting
 * facilities of the µTest++ framework. It provides lifecycle and utility
 * behaviour for reporters, including command-line option parsing,
 * output-file handling, informational banner emission, buffering helpers,
 * stream operators, and pass/fail dispatch to reporter-specific prefix/
 * suffix hooks.
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

#include "micro-os-plus/micro-test-plus/reporter.h"
#include "micro-os-plus/micro-test-plus/stopwatch.h"
#include "micro-os-plus/micro-test-plus/utility.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

#include <cstdarg>
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
   * confirmation message naming the output file is written to `stdout`.
   * If tracing is enabled, the function signature is output for
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

        write_console_ ("Test output written to '%s'.\n",
                        output_file_path_.c_str ());

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
   * This method appends a newline character to the internal output buffer of
   * the `reporter`. The buffer itself is written later, by the concrete
   * reporters, at the end of each test case or suite, which then also
   * flush the streams.
   */
  void
  reporter::end_line (void)
  {
    buffer_.append ("\n");
  }

  /**
   * @details
   * This method writes the contents of the internal output buffer to the
   * console without appending a newline character. The buffer is not
   * cleared; the caller is responsible for clearing it when appropriate.
   */
  void
  reporter::write_buffer_to_console (void)
  {
    // Pass only the string, do not add an `\n` here.
    fputs (buffer_.c_str (), stdout);
  }

  /**
   * @details
   * Writes the contents of `buffer_` to `output_file_` without appending
   * a newline. If `output_file_` is null, the call is a no-op.
   *
   * The buffer may contain ANSI colour sequences, added when the console
   * is a terminal, which must not reach the file. They are removed while
   * writing: each `ESC [`, followed by any digits and semicolons, and
   * terminated by `m`, is skipped, and the text between the sequences is
   * written unchanged. Any other use of `ESC` is written as is.
   */
  void
  reporter::write_buffer_to_file_ (void)
  {
    if (output_file_ == nullptr)
      {
        return;
      }

    // Pass only the string, do not add an `\n` here.
    const std::string_view text{ buffer_ };
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
                // A colour sequence; write the preceding text and skip it.
                const std::string_view chunk
                    = text.substr (start, pos - start);
                fwrite (chunk.data (), 1, chunk.size (), output_file_);
                start = end + 1;
              }
          }
        pos = text.find ('\033', pos + 1);
      }

    const std::string_view chunk = text.substr (start);
    fwrite (chunk.data (), 1, chunk.size (), output_file_);
  }

  /**
   * @details
   * The arguments are forwarded to `vfprintf()` on `stdout`. The stream
   * is explicit, so the compiler does not rewrite the call into
   * `puts()` or `putchar()`, and all console output shares the same
   * `FILE`-based path.
   */
  void
  reporter::write_console_ (const char* format, ...)
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
  reporter::write_file_ (const char* format, ...)
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
   * Constructs and emits two informational lines, each prefixed by
   * `comment_prefix()`: the first lists the program name (without
   * the path) and any command-line arguments; the second identifies the
   * compiler (Clang, GCC, or MSVC) together with the version string,
   * floating-point availability on bare-metal targets, exception support,
   * and any active debug or trace macros. Both lines are written to the
   * output file when one is open, and to `stdout` when the verbosity is
   * `normal` or `verbose`, except when both `MICRO_OS_PLUS_STARTUP_ENABLED`
   * and `MICRO_OS_PLUS_DIAG_TRACE_ENABLED` are defined, since the startup
   * code already displays this information.
   */
  void
  reporter::write_info_ (void)
  {
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

        write_file_ ("%s", line.c_str ());

#if !(defined(MICRO_OS_PLUS_STARTUP_ENABLED) \
      && defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED))
        if (verbosity_ == verbosity::normal
            || verbosity_ == verbosity::verbose)
          write_console_ ("%s", line.c_str ());
#endif // !defined(MICRO_OS_PLUS_STARTUP_ENABLED)
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
      || defined(WIN32))
      // This is relevant only on bare-metal.
#if defined(__ARM_PCS_VFP) || defined(__ARM_FP)
      line.append (", with FP");
#else
      line.append (", no FP");
#endif // defined(__ARM_PCS_VFP) || defined(__ARM_FP)
#endif // !(defined(__APPLE__) || defined(__linux__) || defined(__unix__) || defined(WIN32))
#if defined(__EXCEPTIONS)
      line.append (", with exceptions");
#else
      line.append (", no exceptions");
#endif // defined(__EXCEPTIONS)
#if defined(MICRO_OS_PLUS_DEBUG_ENABLED)
      line.append (", with MICRO_OS_PLUS_DEBUG_ENABLED");
#endif // defined(MICRO_OS_PLUS_DEBUG_ENABLED)
#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)
      line.append (", with MICRO_OS_PLUS_DIAG_TRACE_ENABLED");
#endif // defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)

      write_file_ ("%s\n", line.c_str ());

#if !(defined(MICRO_OS_PLUS_STARTUP_ENABLED) \
      && defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED))
      if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
        {
          write_console_ ("%s\n", line.c_str ());
        }
#endif // !defined(MICRO_OS_PLUS_STARTUP_ENABLED)
    }
  }

  /**
   * @details
   * This method flushes the `stdout` stream and, if open, the output
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
    output_pass_prefix_ (message, test_case);

    if (message.empty ())
      {
        *this << expression;
      }

    output_pass_suffix_ (test_case);
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
    output_fail_prefix_ (failure.message, failure.has_expression,
                         failure.location, test_case);

    if (failure.has_expression)
      {
        *this << expression;
      }

    output_fail_suffix_ (failure.location, failure.kind, test_case);

    buffer_has_failures_ = true;
  }

  /**
   * @details
   * Empties `buffer_`, keeping its capacity, and resets
   * `buffer_has_failures_`.
   */
  void
  reporter::clear_buffer_ (void)
  {
    buffer_.clear ();
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
  reporter::format_elapsed_time_ (const stopwatch& stopwatch,
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
} // namespace micro_os_plus::micro_test_plus::detail

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

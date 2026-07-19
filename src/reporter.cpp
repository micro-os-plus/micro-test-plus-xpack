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
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#if __has_include(<micro-os-plus/project-config.h>)
#include <micro-os-plus/project-config.h>
#elif __has_include(<micro-os-plus/config.h>)
#pragma message \
    "micro-os-plus/config.h is deprecated, rename to micro-os-plus/project-config.h and include it instead of micro-os-plus/config.h"
#include <micro-os-plus/config.h>
#endif // __has_include(<micro-os-plus/project-config.h>)

#if __has_include(<micro-os-plus/micro-test-plus-defines.h>)
#include <micro-os-plus/micro-test-plus-defines.h>
#endif // __has_include(<micro-os-plus/micro-test-plus-defines.h>)

#include <micro-os-plus/diag/trace.h>

#include "micro-os-plus/micro-test-plus/reporter.h"

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
   * Moves the supplied argument vector into `argvs_` and scans it for
   * the `--verbose`, `--quiet`, `--silent`, and `--output-file=` options,
   * adjusting `verbosity_` and optionally opening the output file. If
   * the output file path is specified but the file cannot be opened, the
   * process exits with a diagnostic error message. The internal string
   * buffer is pre-allocated to reduce dynamic allocation overhead.
   */
  reporter::reporter (std::unique_ptr<std::vector<std::string_view>> argvs)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

    std::string_view output_file_sv{};

    argvs_ = std::move (argvs);

    static constexpr std::string_view output_file_prefix{ "--output-file=" };
    if (argvs_)
      {
        const auto& args = *argvs_;
        for (size_t i = 0; i < args.size (); ++i)
          {
            if (args[i] == "--verbose")
              {
                verbosity_ = verbosity::verbose;
              }
            else if (args[i] == "--quiet")
              {
                verbosity_ = verbosity::quiet;
              }
            else if (args[i] == "--silent")
              {
                verbosity_ = verbosity::silent;
              }
            else if (args[i].starts_with (output_file_prefix))
              {
                output_file_sv = args[i].substr (output_file_prefix.size ());
              }
            else if (args[i]
                     == output_file_prefix.substr (
                         0, output_file_prefix.size () - 1))
              {
                if (i + 1 < args.size ())
                  {
                    output_file_sv = args[++i];
                  }
                else
                  {
                    fprintf (stderr, "error: --output-file option requires a "
                                     "file path argument\n");
                    exit (1);
                  }
              }
          }
      }

    if (!output_file_sv.empty ())
      {
        // .data() is safe: all string_views are views into argv[]
        // entries, which are null-terminated C strings.
        output_file_ = fopen (output_file_sv.data (), "w");
        if (output_file_ == nullptr)
          {
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
            fprintf (stderr, "error: Failed to open output file '%.*s'\n",
                     static_cast<int> (output_file_sv.size ()),
                     output_file_sv.data ());
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
            exit (1);
          }
        // The original string is zero terminated, so we can safely use .data()
        // here.
        output_file_path_ = output_file_sv.data ();
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

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
        printf ("Test output written to '%s'.\n", output_file_path_);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

        output_file_ = nullptr;
        output_file_path_ = nullptr;
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * The `endl` function inserts a newline character into the specified
   * `reporter` stream and flushes its output buffer. This operation
   * ensures that each test output line is clearly separated and immediately
   * visible, facilitating the readability and clarity of test results across
   * all test cases and folders within the µTest++ framework.
   */
  reporter&
  endl (reporter& stream)
  {
    stream.endline ();
    return stream;
  }

  /**
   * @details
   * This method appends a newline character to the internal output buffer of
   * the `reporter` and immediately flushes the stream. This ensures that
   * each line of test output is clearly separated and promptly displayed,
   * enhancing the readability and organisation of test results across all test
   * cases and folders.
   */
  void
  reporter::endline (void)
  {
    buffer_.append ("\n");
    flush ();
  }

  /**
   * @details
   * This method writes the contents of the internal output buffer to the
   * standard output stream without appending a newline character. After
   * outputting the buffer, it is cleared to prepare for subsequent output.
   * This approach ensures that test results are presented promptly and
   * efficiently, supporting clear and organised reporting across all test
   * cases and folders.
   */
  void
  reporter::write_buffer_to_stdout (void)
  {
    // Pass only the string, do not add an `\n` here.
    printf ("%s", buffer_.c_str ());
  }

  /**
   * @details
   * Writes the contents of `buffer_` to `output_file_` using `fprintf`
   * without appending a newline. If `output_file_` is null, the call is
   * a no-op.
   */
  void
  reporter::write_buffer_to_file_ (void)
  {
    // Pass only the string, do not add an `\n` here.
    if (output_file_ != nullptr)
      {
        fprintf (output_file_, "%s", buffer_.c_str ());
      }
  }

  /**
   * @details
   * Constructs and emits two informational lines: the first lists the
   * programme name and any command-line arguments; the second identifies
   * the compiler (Clang, GCC, or MSVC) together with the version string,
   * floating-point availability on bare-metal targets, exception support,
   * and any active debug or trace macros. Both lines are written to the
   * output file when one is open, and to `stdout` unless verbosity is
   * set to `silent`.
   */
  void
  reporter::write_info_ (void)
  {
    if (argvs_ && !argvs_->empty ())
      {
        const auto& args = *argvs_;
        std::string line;
        line.reserve (256);
        line.append (get_comment_prefix ());
        line.append ("Running: ");

        // Append only the file name part of argv[0].
        const std::string_view arg0 = args[0];
        const auto sep = arg0.rfind ('/');
        line.append ((sep != std::string_view::npos) ? arg0.substr (sep + 1)
                                                     : arg0);

        for (size_t i = 1; i < args.size (); ++i)
          {
            line.append (" ");
            line.append (args[i]);
          }
        line.append ("\n");

        if (output_file_ != nullptr)
          fprintf (output_file_, "%s", line.c_str ());

#if !(defined(MICRO_OS_PLUS_STARTUP_ENABLED) \
      && defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED))
        if (verbosity_ == verbosity::normal
            || verbosity_ == verbosity::verbose)
          printf ("%s", line.c_str ());
#endif // !defined(MICRO_OS_PLUS_STARTUP_ENABLED)
      }

    {
      // Build the "Built with ..." line. For the output file the compiler
      // version is omitted; for stdout it is appended via __VERSION__.
      std::string line;
      line.reserve (256);
      line.append (get_comment_prefix ());
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
#endif
#if !(defined(__APPLE__) || defined(__linux__) || defined(__unix__) \
      || defined(WIN32))
      // This is relevant only on bare-metal.
#if defined(__ARM_PCS_VFP) || defined(__ARM_FP)
      line.append (", with FP");
#else
      line.append (", no FP");
#endif
#endif
#if defined(__EXCEPTIONS)
      line.append (", with exceptions");
#else
      line.append (", no exceptions");
#endif
#if defined(MICRO_OS_PLUS_DEBUG)
      line.append (", with MICRO_OS_PLUS_DEBUG");
#endif
#if defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED)
      line.append (", with MICRO_OS_PLUS_DIAG_TRACE_ENABLED");
#endif

      if (output_file_ != nullptr)
        {
          fprintf (output_file_, "%s\n", line.c_str ());
        }

#if !(defined(MICRO_OS_PLUS_STARTUP_ENABLED) \
      && defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED))
      if (verbosity_ == verbosity::normal || verbosity_ == verbosity::verbose)
        {
          printf ("%s\n", line.c_str ());
        }
#endif // !defined(MICRO_OS_PLUS_STARTUP_ENABLED)
    }
  }

  /**
   * @details
   * This method flushes the output buffer of the `reporter` by
   * synchronising it with the standard output stream. This guarantees that all
   * pending test output is immediately written and visible, ensuring prompt
   * and reliable reporting of test results across all test cases and folders.
   */
  void
  reporter::flush (void)
  {
    fflush (stdout);
    if (output_file_ != nullptr)
      {
        fflush (output_file_);
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * This operator overload enables manipulators, such as `endl`, to be used
   * with the `reporter` stream in a manner similar to standard C++
   * streams. When a manipulator function is passed, it is invoked with the
   * current `reporter` instance, allowing for seamless integration of
   * stream operations and improved readability of test output across all test
   * cases and folders.
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
   * This operator overload appends the contents of the provided
   * `std::string_view` to the internal output buffer of the `reporter`.
   * It enables seamless streaming of string data into the reporter, supporting
   * clear and efficient formatting of test output across all test cases and
   * folders.
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
   * output buffer of the `reporter`. It enables efficient streaming of
   * individual characters into the reporter, supporting precise and flexible
   * formatting of test output across all test cases and folders.
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
   * to the internal output buffer of the `reporter`. It enables efficient
   * streaming of string literals and character arrays into the reporter,
   * supporting clear and flexible formatting of test output across all test
   * cases and folders.
   */
  reporter&
  reporter::operator<< (const char* s)
  {
    buffer_.append (s);
    return *this;
  }

  /**
   * @details
   * Outputs a pass prefix, followed by either the provided message or, if
   * the message is empty, the evaluated expression string itself. A pass
   * suffix is then appended to complete the output.
   */
  void
  reporter::pass (std::string& message, const std::string& expression,
                  subtest& subtest)
  {
    output_pass_prefix_ (message, subtest);

    if (message.empty ())
      {
        *this << expression;
      }

    output_pass_suffix_ (subtest);
  }

  /**
   * @details
   * Reports a test failure, formatting the output with source location and,
   * when `has_expression` is true, the pre-formatted expression string.
   */
  void
  reporter::fail (bool abort, std::string& message,
                  const std::string& expression, bool has_expression,
                  const reflection::source_location& location,
                  subtest& subtest)
  {
    output_fail_prefix_ (message, has_expression, location, subtest);

    if (has_expression)
      {
        *this << expression;
      }

    output_fail_suffix_ (location, abort, subtest);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

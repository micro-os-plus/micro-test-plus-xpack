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
 * facilities of the µTest++ framework. It provides the logic for formatting
 * and outputting test results, including operator overloads for a wide range
 * of value types, containers, and comparison expressions, as well as
 * structured output for logical and exception-related assertions.
 *
 * The test reporter is responsible for presenting test outcomes in a clear,
 * consistent, and expressive manner, supporting both value and pointer
 * semantics, and providing detailed diagnostics for both successful and failed
 * test cases. Special attention is given to formatting, colour highlighting,
 * and extensibility, enabling professional and readable test reports suitable
 * for embedded and general C++ development.
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

// =============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  reporter::reporter (std::unique_ptr<std::vector<std::string_view>> argvs)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

    verbosity = verbosity::normal;
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
                verbosity = verbosity::verbose;
              }
            else if (args[i] == "--quiet")
              {
                verbosity = verbosity::quiet;
              }
            else if (args[i] == "--silent")
              {
                verbosity = verbosity::silent;
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
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
            fprintf (stderr, "error: Failed to open output file '%.*s'\n",
                     static_cast<int> (output_file_sv.size ()),
                     output_file_sv.data ());
#pragma GCC diagnostic pop
            exit (1);
          }
      }

    // Pre-allocate buffer to reduce dynamic allocations.
    buffer_.reserve (128);
  }

  reporter::~reporter ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS

    if (output_file_ != nullptr)
      {
        fflush (output_file_);
        fclose (output_file_);

        output_file_ = nullptr;
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
  endl (reporter& reporter)
  {
    reporter.endline ();
    return reporter;
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

  void
  reporter::write_buffer_to_file (void)
  {
    // Pass only the string, do not add an `\n` here.
    if (output_file_ != nullptr)
      {
        fprintf (output_file_, "%s", buffer_.c_str ());
      }
  }

  void
  reporter::write_info (void)
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

#if !(defined(MICRO_OS_PLUS_INCLUDE_STARTUP) && defined(MICRO_OS_PLUS_TRACE))
        if (verbosity == verbosity::normal || verbosity == verbosity::verbose)
          printf ("%s", line.c_str ());
#endif // !defined(MICRO_OS_PLUS_INCLUDE_STARTUP)
      }

    {
      // Build the "Built with ..." line. For the output file the compiler
      // version is omitted; for stdout it is appended via __VERSION__.
      std::string line;
      line.reserve (256);
      line.append (get_comment_prefix ());
      line.append ("Built with ");
#if defined(__clang__)
      line.append ("clang");
#elif defined(__GNUC__)
      line.append ("GCC");
#elif defined(_MSC_VER)
      line.append ("MSVC");
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

      if (output_file_ != nullptr)
        {
          fprintf (output_file_, "%s\n", line.c_str ());
        }

#if !(defined(MICRO_OS_PLUS_INCLUDE_STARTUP) && defined(MICRO_OS_PLUS_TRACE))
      if (verbosity == verbosity::normal || verbosity == verbosity::verbose)
        {
#if defined(__clang__) || defined(__GNUC__)
          line.append (" - " __VERSION__);
#elif defined(_MSC_VER)
          char msvc_ver[16];
          snprintf (msvc_ver, sizeof (msvc_ver), " - %d", _MSC_VER);
          line.append (msvc_ver);
#endif
          printf ("%s\n", line.c_str ());
        }
#endif // !defined(MICRO_OS_PLUS_INCLUDE_STARTUP)
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
    fflush (stdout); // Sync STDOUT.
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
   * This operator overload appends the string representation of the specified
   * boolean value to the internal output buffer of the `reporter`. It
   * enables clear and direct streaming of boolean results into the reporter,
   * supporting precise and readable formatting of test output across all test
   * cases and folders.
   */
  reporter&
  reporter::operator<< (bool v)
  {
    buffer_.append (v ? "true" : "false");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string "nullptr" to the internal output
   * buffer of the `reporter`. It enables clear and explicit streaming of
   * null pointer values into the reporter, supporting precise and readable
   * formatting of test output across all test cases and folders.
   */
  reporter&
  reporter::operator<< (std::nullptr_t)
  {
    buffer_.append ("nullptr");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed character to the internal output buffer of the `reporter`. It
   * enables precise and readable streaming of character values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  reporter&
  reporter::operator<< (signed char c)
  {
    append_number (buffer_, c);
    buffer_.append ("c");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned character to the internal output buffer of the `reporter`.
   * It enables precise and readable streaming of unsigned character values
   * into the reporter, supporting clear formatting of test output across all
   * test cases and folders.
   */
  reporter&
  reporter::operator<< (unsigned char c)
  {
    append_number (buffer_, c);
    buffer_.append ("uc");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed short integer to the internal output buffer of the `reporter`.
   * It enables precise and readable streaming of signed short values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  reporter&
  reporter::operator<< (signed short v)
  {
    append_number (buffer_, v);
    buffer_.append ("s");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned short integer to the internal output buffer of the
   * `reporter`. It enables precise and readable streaming of unsigned
   * short values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  reporter&
  reporter::operator<< (unsigned short v)
  {
    append_number (buffer_, v);
    buffer_.append ("us");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed integer to the internal output buffer of the `reporter`. It
   * enables precise and readable streaming of signed integer values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  reporter&
  reporter::operator<< (signed int v)
  {
    append_number (buffer_, v);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned integer to the internal output buffer of the `reporter`. It
   * enables precise and readable streaming of unsigned integer values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  reporter&
  reporter::operator<< (unsigned int v)
  {
    append_number (buffer_, v);
    buffer_.append ("u");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed long integer to the internal output buffer of the `reporter`.
   * It enables precise and readable streaming of signed long values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  reporter&
  reporter::operator<< (signed long v)
  {
    append_number (buffer_, v);
    buffer_.append ("l");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned long integer to the internal output buffer of the
   * `reporter`. It enables precise and readable streaming of unsigned
   * long values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  reporter&
  reporter::operator<< (unsigned long v)
  {
    append_number (buffer_, v);
    buffer_.append ("ul");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed long long integer to the internal output buffer of the
   * `reporter`. It enables precise and readable streaming of signed long
   * long values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  reporter&
  reporter::operator<< (signed long long v)
  {
    append_number (buffer_, v);
    buffer_.append ("ll");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned long long integer to the internal output buffer of the
   * `reporter`. It enables precise and readable streaming of unsigned
   * long long values into the reporter, supporting clear formatting of test
   * output across all test cases and folders.
   */
  reporter&
  reporter::operator<< (unsigned long long v)
  {
    append_number (buffer_, v);
    buffer_.append ("ull");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * floating-point value to the internal output buffer of the `reporter`,
   * followed by the character 'f' to indicate a float type. It enables precise
   * and readable streaming of float values into the reporter, supporting clear
   * formatting of test output across all test cases and folders.
   */
  reporter&
  reporter::operator<< (float v)
  {
    append_number (buffer_, v);
    buffer_.append ("f");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * double-precision floating-point value to the internal output buffer of the
   * `reporter`. It enables precise and readable streaming of double
   * values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  reporter&
  reporter::operator<< (double v)
  {
    append_number (buffer_, v);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * long double-precision floating-point value to the internal output buffer
   * of the `reporter`, followed by the character 'l' to indicate a long
   * double type. It enables precise and readable streaming of long double
   * values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  reporter&
  reporter::operator<< (long double v)
  {
    append_number (buffer_, v);
    buffer_.append ("l");
    return *this;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

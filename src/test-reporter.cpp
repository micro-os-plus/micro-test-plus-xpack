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

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  test_reporter::~test_reporter () = default;

  // --------------------------------------------------------------------------

  /**
   * @details
   * The `endl` function inserts a newline character into the specified
   * `test_reporter` stream and flushes its output buffer. This operation
   * ensures that each test output line is clearly separated and immediately
   * visible, facilitating the readability and clarity of test results across
   * all test cases and folders within the µTest++ framework.
   */
  test_reporter&
  endl (test_reporter& stream)
  {
    reporter->endline ();
    return stream;
  }

  /**
   * @details
   * This operator overload enables manipulators, such as `endl`, to be used
   * with the `test_reporter` stream in a manner similar to standard C++
   * streams. When a manipulator function is passed, it is invoked with the
   * current `test_reporter` instance, allowing for seamless integration of
   * stream operations and improved readability of test output across all test
   * cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (test_reporter& (*func) (test_reporter&))
  {
    // Call the endl function.
    (*func) (*this);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the contents of the provided
   * `std::string_view` to the internal output buffer of the `test_reporter`.
   * It enables seamless streaming of string data into the reporter, supporting
   * clear and efficient formatting of test output across all test cases and
   * folders.
   */
  test_reporter&
  test_reporter::operator<< (std::string_view sv)
  {
    out_.append (sv);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the specified character to the internal
   * output buffer of the `test_reporter`. It enables efficient streaming of
   * individual characters into the reporter, supporting precise and flexible
   * formatting of test output across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (char c)
  {
    out_.append (1, c);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the contents of the provided C-style string
   * to the internal output buffer of the `test_reporter`. It enables efficient
   * streaming of string literals and character arrays into the reporter,
   * supporting clear and flexible formatting of test output across all test
   * cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (const char* s)
  {
    out_.append (s);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the contents of the provided modifiable
   * C-style string to the internal output buffer of the `test_reporter`. It
   * enables efficient streaming of mutable string data into the reporter,
   * supporting clear and flexible formatting of test output across all test
   * cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (char* s)
  {
    out_.append (s);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * boolean value to the internal output buffer of the `test_reporter`. It
   * enables clear and direct streaming of boolean results into the reporter,
   * supporting precise and readable formatting of test output across all test
   * cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (bool v)
  {
    out_.append (v ? "true" : "false");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string "nullptr" to the internal output
   * buffer of the `test_reporter`. It enables clear and explicit streaming of
   * null pointer values into the reporter, supporting precise and readable
   * formatting of test output across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (std::nullptr_t)
  {
    out_.append ("nullptr");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed character to the internal output buffer of the `test_reporter`. It
   * enables precise and readable streaming of character values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  test_reporter&
  test_reporter::operator<< (signed char c)
  {
    out_.append (std::to_string (c));
    out_.append ("c");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned character to the internal output buffer of the `test_reporter`.
   * It enables precise and readable streaming of unsigned character values
   * into the reporter, supporting clear formatting of test output across all
   * test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (unsigned char c)
  {
    out_.append (std::to_string (static_cast<int> (c)));
    out_.append ("uc");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed short integer to the internal output buffer of the `test_reporter`.
   * It enables precise and readable streaming of signed short values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  test_reporter&
  test_reporter::operator<< (signed short v)
  {
    out_.append (std::to_string (v));
    out_.append ("s");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned short integer to the internal output buffer of the
   * `test_reporter`. It enables precise and readable streaming of unsigned
   * short values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (unsigned short v)
  {
    out_.append (std::to_string (static_cast<long> (v)));
    out_.append ("us");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed integer to the internal output buffer of the `test_reporter`. It
   * enables precise and readable streaming of signed integer values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  test_reporter&
  test_reporter::operator<< (signed int v)
  {
    out_.append (std::to_string (v));
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned integer to the internal output buffer of the `test_reporter`. It
   * enables precise and readable streaming of unsigned integer values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  test_reporter&
  test_reporter::operator<< (unsigned int v)
  {
    out_.append (std::to_string (v));
    out_.append ("u");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed long integer to the internal output buffer of the `test_reporter`.
   * It enables precise and readable streaming of signed long values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  test_reporter&
  test_reporter::operator<< (signed long v)
  {
    out_.append (std::to_string (v));
    out_.append ("l");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned long integer to the internal output buffer of the
   * `test_reporter`. It enables precise and readable streaming of unsigned
   * long values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (unsigned long v)
  {
    out_.append (std::to_string (v));
    out_.append ("ul");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed long long integer to the internal output buffer of the
   * `test_reporter`. It enables precise and readable streaming of signed long
   * long values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (signed long long v)
  {
    out_.append (std::to_string (v));
    out_.append ("ll");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned long long integer to the internal output buffer of the
   * `test_reporter`. It enables precise and readable streaming of unsigned
   * long long values into the reporter, supporting clear formatting of test
   * output across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (unsigned long long v)
  {
    out_.append (std::to_string (v));
    out_.append ("ull");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * floating-point value to the internal output buffer of the `test_reporter`,
   * followed by the character 'f' to indicate a float type. It enables precise
   * and readable streaming of float values into the reporter, supporting clear
   * formatting of test output across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (float v)
  {
    out_.append (std::to_string (v));
    out_.append ("f");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * double-precision floating-point value to the internal output buffer of the
   * `test_reporter`. It enables precise and readable streaming of double
   * values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (double v)
  {
    out_.append (std::to_string (v));
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * long double-precision floating-point value to the internal output buffer
   * of the `test_reporter`, followed by the character 'l' to indicate a long
   * double type. It enables precise and readable streaming of long double
   * values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (long double v)
  {
    out_.append (std::to_string (v));
    out_.append ("l");
    return *this;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// =============================================================================

namespace micro_os_plus::micro_test_plus2
{
  // --------------------------------------------------------------------------

  test_reporter::~test_reporter ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  // --------------------------------------------------------------------------

  void
  test_reporter::maybe_end_top_suite (test_suite_base& test_suite)
  {
    if (must_end_top_suite_)
      {
        // End the top suite, if not already ended.
        end_test_suite (test_suite);
        must_end_top_suite_ = false;
      }
  }
  /**
   * @details
   * The `endl` function inserts a newline character into the specified
   * `test_reporter` stream and flushes its output buffer. This operation
   * ensures that each test output line is clearly separated and immediately
   * visible, facilitating the readability and clarity of test results across
   * all test cases and folders within the µTest++ framework.
   */
  test_reporter&
  endl (test_reporter& reporter)
  {
    reporter.endline ();
    return reporter;
  }

  /**
   * @details
   * This method appends a newline character to the internal output buffer of
   * the `test_reporter` and immediately flushes the stream. This ensures that
   * each line of test output is clearly separated and promptly displayed,
   * enhancing the readability and organisation of test results across all test
   * cases and folders.
   */
  void
  test_reporter::endline (void)
  {
    out_.append ("\n");
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
  test_reporter::output (void)
  {
    printf ("%s", out_.c_str ()); // No `\n` here.
    out_.clear ();
  }

  /**
   * @details
   * This method flushes the output buffer of the `test_reporter` by
   * synchronising it with the standard output stream. This guarantees that all
   * pending test output is immediately written and visible, ensuring prompt
   * and reliable reporting of test results across all test cases and folders.
   */
  void
  test_reporter::flush (void)
  {
    fflush (stdout); // Sync STDOUT.
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * This operator overload enables manipulators, such as `endl`, to be used
   * with the `test_reporter` stream in a manner similar to standard C++
   * streams. When a manipulator function is passed, it is invoked with the
   * current `test_reporter` instance, allowing for seamless integration of
   * stream operations and improved readability of test output across all test
   * cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (test_reporter& (*func) (test_reporter&))
  {
    // Call the endl function.
    (*func) (*this);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the contents of the provided
   * `std::string_view` to the internal output buffer of the `test_reporter`.
   * It enables seamless streaming of string data into the reporter, supporting
   * clear and efficient formatting of test output across all test cases and
   * folders.
   */
  test_reporter&
  test_reporter::operator<< (std::string_view sv)
  {
    out_.append (sv);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the specified character to the internal
   * output buffer of the `test_reporter`. It enables efficient streaming of
   * individual characters into the reporter, supporting precise and flexible
   * formatting of test output across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (char c)
  {
    out_.append (1, c);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the contents of the provided C-style string
   * to the internal output buffer of the `test_reporter`. It enables efficient
   * streaming of string literals and character arrays into the reporter,
   * supporting clear and flexible formatting of test output across all test
   * cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (const char* s)
  {
    out_.append (s);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the contents of the provided modifiable
   * C-style string to the internal output buffer of the `test_reporter`. It
   * enables efficient streaming of mutable string data into the reporter,
   * supporting clear and flexible formatting of test output across all test
   * cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (char* s)
  {
    out_.append (s);
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * boolean value to the internal output buffer of the `test_reporter`. It
   * enables clear and direct streaming of boolean results into the reporter,
   * supporting precise and readable formatting of test output across all test
   * cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (bool v)
  {
    out_.append (v ? "true" : "false");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string "nullptr" to the internal output
   * buffer of the `test_reporter`. It enables clear and explicit streaming of
   * null pointer values into the reporter, supporting precise and readable
   * formatting of test output across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (std::nullptr_t)
  {
    out_.append ("nullptr");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed character to the internal output buffer of the `test_reporter`. It
   * enables precise and readable streaming of character values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  test_reporter&
  test_reporter::operator<< (signed char c)
  {
    out_.append (std::to_string (c));
    out_.append ("c");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned character to the internal output buffer of the `test_reporter`.
   * It enables precise and readable streaming of unsigned character values
   * into the reporter, supporting clear formatting of test output across all
   * test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (unsigned char c)
  {
    out_.append (std::to_string (static_cast<int> (c)));
    out_.append ("uc");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed short integer to the internal output buffer of the `test_reporter`.
   * It enables precise and readable streaming of signed short values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  test_reporter&
  test_reporter::operator<< (signed short v)
  {
    out_.append (std::to_string (v));
    out_.append ("s");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned short integer to the internal output buffer of the
   * `test_reporter`. It enables precise and readable streaming of unsigned
   * short values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (unsigned short v)
  {
    out_.append (std::to_string (static_cast<long> (v)));
    out_.append ("us");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed integer to the internal output buffer of the `test_reporter`. It
   * enables precise and readable streaming of signed integer values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  test_reporter&
  test_reporter::operator<< (signed int v)
  {
    out_.append (std::to_string (v));
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned integer to the internal output buffer of the `test_reporter`. It
   * enables precise and readable streaming of unsigned integer values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  test_reporter&
  test_reporter::operator<< (unsigned int v)
  {
    out_.append (std::to_string (v));
    out_.append ("u");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed long integer to the internal output buffer of the `test_reporter`.
   * It enables precise and readable streaming of signed long values into the
   * reporter, supporting clear formatting of test output across all test cases
   * and folders.
   */
  test_reporter&
  test_reporter::operator<< (signed long v)
  {
    out_.append (std::to_string (v));
    out_.append ("l");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned long integer to the internal output buffer of the
   * `test_reporter`. It enables precise and readable streaming of unsigned
   * long values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (unsigned long v)
  {
    out_.append (std::to_string (v));
    out_.append ("ul");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * signed long long integer to the internal output buffer of the
   * `test_reporter`. It enables precise and readable streaming of signed long
   * long values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (signed long long v)
  {
    out_.append (std::to_string (v));
    out_.append ("ll");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * unsigned long long integer to the internal output buffer of the
   * `test_reporter`. It enables precise and readable streaming of unsigned
   * long long values into the reporter, supporting clear formatting of test
   * output across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (unsigned long long v)
  {
    out_.append (std::to_string (v));
    out_.append ("ull");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * floating-point value to the internal output buffer of the `test_reporter`,
   * followed by the character 'f' to indicate a float type. It enables precise
   * and readable streaming of float values into the reporter, supporting clear
   * formatting of test output across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (float v)
  {
    out_.append (std::to_string (v));
    out_.append ("f");
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * double-precision floating-point value to the internal output buffer of the
   * `test_reporter`. It enables precise and readable streaming of double
   * values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (double v)
  {
    out_.append (std::to_string (v));
    return *this;
  }

  /**
   * @details
   * This operator overload appends the string representation of the specified
   * long double-precision floating-point value to the internal output buffer
   * of the `test_reporter`, followed by the character 'l' to indicate a long
   * double type. It enables precise and readable streaming of long double
   * values into the reporter, supporting clear formatting of test output
   * across all test cases and folders.
   */
  test_reporter&
  test_reporter::operator<< (long double v)
  {
    out_.append (std::to_string (v));
    out_.append ("l");
    return *this;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus2

// ----------------------------------------------------------------------------

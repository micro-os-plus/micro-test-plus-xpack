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

#if !defined(MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_)
// clang-format off
#error "Do not include this file directly; use <micro-os-plus/micro-test-plus.h>."
// clang-format on
#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

/**
 * @file
 * @brief C++ header file with inline implementations for the µTest++ test
 * reporter.
 *
 * @details
 * This header provides the inline implementations for the test reporting
 * facilities used within the µTest++ framework. It defines the logic for
 * formatting and outputting test results, including operator overloads for
 * various value types, containers, and comparison expressions, as well as
 * structured output for logical and exception-related assertions.
 *
 * The implementations ensure that test outcomes are presented in a clear,
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
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_TEST_REPORTER_INLINES_H_
#define MICRO_TEST_PLUS_TEST_REPORTER_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <cstdio>
#include <cstring>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // ==========================================================================

  /**
   * @details
   * Returns the verbosity level stored in `verbosity_`.
   */
  inline auto
  reporter::verbosity () const -> micro_test_plus::verbosity
  {
    return verbosity_;
  }

  /**
   * @details
   * Returns the ANSI colour code for pass or fail, depending on the boolean
   * condition provided.
   */
  [[nodiscard]] inline auto
  reporter::colour_ (const bool cond) const
  {
    return cond ? colours_.pass : colours_.fail;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * This operator overload enables the `reporter` to output pointer
   * values in a consistent and readable format.
   *
   * Null pointers are always rendered as the string `"nullptr"`,
   * regardless of the platform, avoiding platform-specific behaviour
   * such as `"(nil)"` on Linux/glibc or `"0x0"` on macOS.
   *
   * Non-null pointers are formatted as a hexadecimal address using
   * `snprintf` with the `%p` format specifier. The resulting string is
   * appended to the internal output buffer, allowing pointer values to be
   * included in test reports and diagnostics.
   *
   * This approach provides clear and unambiguous representation of pointer
   * addresses, which is particularly useful for debugging and verifying
   * pointer-related test cases.
   */
  template <typename T>
  reporter&
  reporter::operator<< (T* v)
  {
    if (v == nullptr)
      {
        // Explicitly render null pointers as "0x0" to avoid platform-specific
        // representations such as "(nil)" on Linux/glibc.
        buffer_.append ("0x0");
        return *this;
      }
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    char buff[20];
    snprintf (buff, sizeof (buff), "%p", reinterpret_cast<void*> (v));
    buffer_.append (buff);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

    return *this;
  }

  /**
   * @details
   * This template operator overload allows the `reporter` to output values of
   * any arithmetic type (integral or floating-point) in a consistent and
   * readable format. The value is formatted using the `append_number_` helper
   * function, which handles the conversion to a string representation with
   * appropriate type suffixes where applicable (e.g., "f" for float, "l" for
   * long double). This enables numeric values to be included in test reports
   * and diagnostics in a clear and unambiguous manner, supporting the
   * verification of test cases that involve arithmetic expressions and
   * comparisons.
   */
  template <class T>
    requires std::is_arithmetic_v<T>
  reporter&
  reporter::operator<< (T v)
  {
    detail::append_number_ (buffer_, v);
    return *this;
  }

  /**
   * @details
   * Outputs a pass prefix, followed by either the provided message or, if
   * the message is empty, the evaluated expression itself. A pass suffix is
   * then appended to complete the output, ensuring that successful test
   * outcomes are presented in a clear and consistent manner.
   */
  template <class Expr_T>
  void
  reporter::pass (Expr_T& expr, std::string& message, subtest& subtest)
  {
    //    current_test_suite->current_test_case.index++;

    output_pass_prefix_ (message, subtest);

    if (message.empty ())
      {
        // If there is no message, display the evaluated expression.
        formatter_.clear ();
        formatter_ << expr;
        *this << formatter_.str ();
      }

    output_pass_suffix_ (subtest);
  }

  /**
   * @details
   * This function reports a test failure and formats the output in a clear and
   * consistent manner. It provides contextual information, including the
   * precise source location, and appends the evaluated expression when
   * applicable. The failure handling process ensures uniformity in the
   * presentation of unsuccessful test cases, aiding in the rapid
   * identification and diagnosis of issues within test reports.
   */
  template <class Expr_T>
  void
  reporter::fail (Expr_T& expr, bool abort, std::string& message,
                  const reflection::source_location& location,
                  subtest& subtest)
  {
    // current_test_suite->current_test_case.index++;

    const bool hasExpression = type_traits::is_op<Expr_T>;
    output_fail_prefix_ (message, hasExpression, location, subtest);

    if constexpr (type_traits::is_op<Expr_T>)
      {
        formatter_.clear ();
        formatter_ << expr;
        *this << formatter_.str ();
      }

    output_fail_suffix_ (location, abort, subtest);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_REPORTER_INLINES_H_

// ----------------------------------------------------------------------------

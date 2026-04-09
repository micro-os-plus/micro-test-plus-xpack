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
 * All definitions reside within the `micro_os_plus::micro_test_plus::detail`
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

#include <stdio.h>
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
  // --------------------------------------------------------------------------

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
  template <class T>
  void
  reporter::append_number (std::string& buffer, const T v)
  {
    char buf[32];
    const auto [ptr, ec] = std::to_chars (buf, buf + sizeof (buf), v);
    if (ec == std::errc{})
      buffer.append (buf, ptr);
  }
#pragma GCC diagnostic pop

  // --------------------------------------------------------------------------

  /**
   * @details
   * This operator overload enables the `reporter` to output pointer
   * values in a consistent and readable format.
   *
   * Null pointers are always rendered as the string `"nullptr"`,
   * regardless of the platform, avoiding platform-specific behaviour
   * such as `"0x0"` on Linux or `"(nil)"` on macOS.
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
        // pointer representations like "(nil)" on macOS.
        buffer_.append ("0x0");
        return *this;
      }
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    char buff[20];
    snprintf (buff, sizeof (buff), "%p", reinterpret_cast<void*> (v));
    buffer_.append (buff);
#pragma GCC diagnostic pop

    return *this;
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output any type that is
   * supported by the `detail::get` mechanism, ensuring consistent formatting
   * and extensibility.
   *
   * By delegating to `detail::get`, the operator allows for custom formatting
   * and extraction of values, supporting a wide range of types including
   * user-defined and framework-specific types. The resulting value is then
   * forwarded to the appropriate output handler, ensuring seamless integration
   * into test reports and diagnostics.
   *
   * This approach promotes flexibility and maintainability, allowing new types
   * to be supported with minimal changes to the reporting infrastructure.
   */
  template <class T>
    requires type_traits::is_op_v<T>
  reporter&
  reporter::operator<< (const T& t)
  {
    *this << detail::get (t);
    return *this;
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output
   * strongly-typed integral values in a clear and consistent decimal format.
   *
   * The value is converted to a string using `std::to_string` after being cast
   * to `long long`, ensuring accurate formatting and compatibility across
   * platforms. The resulting string is appended to the internal output buffer,
   * allowing integral values to be included in test reports and diagnostics.
   *
   * This approach ensures precise and unambiguous representation of integral
   * values, which is particularly advantageous for verifying test results and
   * facilitating debugging.
   */
  template <class T>
  reporter&
  reporter::operator<< (const type_traits::genuine_integral_value<T>& v)
  {
    append_number (buffer_, static_cast<long long> (v.get ()));
    return *this;
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output container
   * types in a structured and readable format.
   *
   * The contents of the container are enclosed in curly braces and each
   * element is separated by a comma and a space. The operator iterates over
   * the container, formatting each element in sequence, which ensures clarity
   * and consistency in test reports and diagnostics.
   *
   * This approach provides a clear visual representation of container
   * contents, making it easier to interpret test results and debug issues
   * involving collections of values.
   */
  template <class T>
    requires (type_traits::container_like<T> and not type_traits::has_npos<T>)
  reporter&
  reporter::operator<< (const T& t)
  {
    *this << '{';
    auto first = true;
    for (const auto& arg : t)
      {
        *this << (first ? "" : ", ") << arg;
        first = false;
      }
    *this << '}';
    return *this;
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output equality
   * comparison expressions in a clear and expressive format.
   *
   * The left-hand side and right-hand side values are formatted and separated
   * by the equality operator (`==`), with appropriate colour highlighting
   * applied for improved readability in test reports and diagnostics. This
   * structured output assists in quickly identifying the values involved in
   * equality assertions and facilitates efficient debugging of test failures.
   */
  template <class Lhs_T, class Rhs_T>
  reporter&
  reporter::operator<< (const detail::eq_<Lhs_T, Rhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " == " << op.rhs ()
                  << colors_.none);
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output inequality
   * comparison expressions in a clear and expressive format.
   *
   * The left-hand side and right-hand side values are formatted and separated
   * by the inequality operator (`!=`), with appropriate colour highlighting
   * applied for improved readability in test reports and diagnostics. This
   * structured output assists in quickly identifying the values involved in
   * inequality assertions and facilitates efficient debugging of test
   * failures.
   */
  template <class Lhs_T, class Rhs_T>
  reporter&
  reporter::operator<< (const detail::ne_<Lhs_T, Rhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " != " << op.rhs ()
                  << colors_.none);
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output greater-than
   * comparison expressions in a clear and expressive format.
   *
   * The left-hand side and right-hand side values are formatted and separated
   * by the greater-than operator (`>`), with appropriate colour highlighting
   * applied for improved readability in test reports and diagnostics. This
   * structured output assists in quickly identifying the values involved in
   * greater-than assertions and facilitates efficient debugging of test
   * failures.
   */
  template <class Lhs_T, class Rhs_T>
  reporter&
  reporter::operator<< (const detail::gt_<Lhs_T, Rhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " > " << op.rhs ()
                  << colors_.none);
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output
   * greater-than-or-equal-to comparison expressions in a clear and expressive
   * format.
   *
   * The left-hand side and right-hand side values are formatted and separated
   * by the greater-than-or-equal-to operator (`>=`), with appropriate colour
   * highlighting applied for improved readability in test reports and
   * diagnostics. This structured output assists in quickly identifying the
   * values involved in greater-than-or-equal-to assertions and facilitates
   * efficient debugging of test failures.
   */
  template <class Lhs_T, class Rhs_T>
  reporter&
  reporter::operator<< (const detail::ge_<Lhs_T, Rhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " >= " << op.rhs ()
                  << colors_.none);
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output less-than
   * comparison expressions in a clear and expressive format.
   *
   * The left-hand side and right-hand side values are formatted and separated
   * by the less-than operator (`<`), with appropriate colour highlighting
   * applied for improved readability in test reports and diagnostics. This
   * structured output assists in quickly identifying the values involved in
   * less-than assertions and facilitates efficient debugging of test failures.
   */
  template <class Lhs_T, class Rhs_T>
  reporter&
  reporter::operator<< (const detail::lt_<Rhs_T, Lhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " < " << op.rhs ()
                  << colors_.none);
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output
   * less-than-or-equal-to comparison expressions in a clear and expressive
   * format.
   *
   * The left-hand side and right-hand side values are formatted and separated
   * by the less-than-or-equal-to operator (`<=`), with appropriate colour
   * highlighting applied for improved readability in test reports and
   * diagnostics. This structured output assists in quickly identifying the
   * values involved in less-than-or-equal-to assertions and facilitates
   * efficient debugging of test failures.
   */
  template <class Lhs_T, class Rhs_T>
  reporter&
  reporter::operator<< (const detail::le_<Rhs_T, Lhs_T>& op)
  {
    return (*this << color (op) << op.lhs () << " <= " << op.rhs ()
                  << colors_.none);
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output logical
   * conjunction (AND) expressions in a clear and structured format.
   *
   * The left-hand side and right-hand side expressions are enclosed in
   * parentheses and separated by the word "and", with appropriate colour
   * highlighting applied for improved readability in test reports and
   * diagnostics. This presentation assists in quickly identifying the
   * components of logical assertions and facilitates efficient debugging of
   * test failures involving compound conditions.
   */
  template <class Lhs_T, class Rhs_T>
  reporter&
  reporter::operator<< (const detail::and_<Lhs_T, Rhs_T>& op)
  {
    return (*this << '(' << op.lhs () << color (op) << " and " << colors_.none
                  << op.rhs () << ')');
  }

  /**
   * @details
   * This operator overload enables the `reporter` to output logical
   * disjunction (OR) expressions in a clear and structured format.
   *
   * The left-hand side and right-hand side expressions are enclosed in
   * parentheses and separated by the word "or", with appropriate colour
   * highlighting applied for improved readability in test reports and
   * diagnostics. This presentation assists in quickly identifying the
   * components of logical assertions and facilitates efficient debugging of
   * test failures involving compound conditions.
   */
  template <class Lhs_T, class Rhs_T>
  reporter&
  reporter::operator<< (const detail::or_<Lhs_T, Rhs_T>& op)
  {
    return (*this << '(' << op.lhs () << color (op) << " or " << colors_.none
                  << op.rhs () << ')');
  }

  /**
   * @details
   * This operator overload enhances readability and clarity by formatting the
   * output when handling negated expressions. It applies colour styling for
   * improved distinction and appends the negated value accordingly, ensuring
   * that logical negations are clearly represented in test reports and
   * diagnostics.
   */
  template <class T>
  reporter&
  reporter::operator<< (const detail::not_<T>& op)
  {
    return (*this << color (op) << "not " << op.operand () << colors_.none);
  }

#if defined(__cpp_exceptions)
  /**
   * @details
   * This operator overload provides structured output for expressions that may
   * throw exceptions. It applies colour styling for clarity and includes the
   * exception type name for precise identification.
   *
   * When invoked, the output highlights the `throws` qualifier along with the
   * specific exception type, making it immediately apparent which exception is
   * expected. This enhances the readability and professionalism of test
   * reports, and assists in the precise identification and debugging of
   * exception-related test cases.
   */
  template <class Expr_T, class Exception_T>
  reporter&
  reporter::operator<< (const detail::throws_<Expr_T, Exception_T>& op)
  {
    return (*this << color (op) << "throws<"
                  << reflection::type_name<Exception_T> () << ">"
                  << colors_.none);
  }

  /**
   * @details
   * This operator overload formats output for expressions that may throw
   * exceptions. It applies colour styling for clarity and ensures a structured
   * representation of the exception handling mechanism.
   *
   * When invoked, the output highlights the `throws` qualifier, making it
   * immediately apparent when an expression is expected to throw, thereby
   * improving the readability and professionalism of the test output.
   */
  template <class Expr_T>
  reporter&
  reporter::operator<< (const detail::throws_<Expr_T, void>& op)
  {
    return (*this << color (op) << "throws" << colors_.none);
  }

  /**
   * @details
   * This operator overload formats output for expressions that do not throw
   * exceptions. It applies colour styling for clarity and ensures a structured
   * and concise representation of exception safety within test reports.
   *
   * The output highlights the `nothrow` qualifier, making it immediately
   * apparent when an expression is guaranteed not to throw, thereby improving
   * the readability and professionalism of the test output.
   */
  template <class Expr_T>
  reporter&
  reporter::operator<< (const detail::nothrow_<Expr_T>& op)
  {
    return (*this << color (op) << "nothrow" << colors_.none);
  }
#endif

  /**
   * @details
   * This operator overload formats output for expressions that do not throw
   * exceptions. It applies colour styling for clarity and ensures a structured
   * representation of exception safety.
   *
   * When invoked, the function outputs a pass prefix, followed by either the
   * provided message or, if the message is empty, the evaluated expression
   * itself. It then appends a pass suffix to complete the output. This
   * approach guarantees that successful test outcomes are presented in a clear
   * and consistent manner, enhancing the readability and professionalism of
   * test reports.
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
        *this << expr;
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

    const bool hasExpression = type_traits::is_op_v<Expr_T>;
    output_fail_prefix_ (message, hasExpression, location, subtest);

    if constexpr (type_traits::is_op_v<Expr_T>)
      {
        *this << expr;
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

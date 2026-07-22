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
 * @brief C++ header file with inline implementations for the µTest++
 * expression formatter.
 *
 * @details
 * This header provides the inline and template method implementations for
 * `expression_formatter`. The buffer accessors (`str()`, `c_str()`,
 * `clear()`, `empty()`, `append()`, `reserve()`) are defined as inline
 * functions for zero-overhead access. The template operators —
 * `operator<<(T*)`, `operator<<(is_op<T>)`,
 * `operator<<(genuine_integral_value<T>)`, and `operator<<(container)` —
 * are instantiated per concrete type at each call site.
 *
 * The `append_number_()` helper is also a template, selecting between a
 * `std::to_chars` path for standard numeric types and an `snprintf` fallback
 * for `long double` on platforms where `std::to_chars` lacks support for
 * 80-bit extended precision.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_INLINES_EXPRESSION_FORMATTER_INLINES_H_
#define MICRO_TEST_PLUS_INLINES_EXPRESSION_FORMATTER_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <cstdio>

#include "micro-os-plus/micro-test-plus/reflection.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus::detail
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * Initializes the `colours_` reference with the provided `colours` instance.
   * The internal buffer is default-initialized to an empty string.
   */
  inline expression_formatter::expression_formatter (colours& colours) noexcept
      : colours_ (colours)
  {
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Returns the ANSI colour code for pass or fail, depending on the boolean
   * condition provided.
   */
  inline auto
  expression_formatter::colour_ (const bool cond) const
  {
    return cond ? colours_.pass : colours_.fail;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Returns a const reference to the internal `buffer_` string.
   */
  inline const std::string&
  expression_formatter::str () const noexcept
  {
    return buffer_;
  }

  /**
   * @details
   * Returns `buffer_.c_str()`, providing a pointer to the
   * null-terminated contents of the internal buffer.
   */
  inline const char*
  expression_formatter::c_str () const noexcept
  {
    return buffer_.c_str ();
  }

  /**
   * @details
   * Calls `buffer_.clear()`, resetting the buffer length to zero
   * without releasing the allocated storage.
   */
  inline void
  expression_formatter::clear () noexcept
  {
    buffer_.clear ();
  }

  /**
   * @details
   * Returns `buffer_.empty()`, indicating whether the accumulated
   * string has zero length.
   */
  inline bool
  expression_formatter::empty () const noexcept
  {
    return buffer_.empty ();
  }

  /**
   * @details
   * Appends @p count repetitions of @p ch to the internal buffer by
   * delegating to `buffer_.append(count, ch)`.
   */
  inline void
  expression_formatter::append (size_t count, char ch)
  {
    buffer_.append (count, ch);
  }

  /**
   * @details
   * Calls `buffer_.reserve(capacity)` to pre-allocate storage,
   * reducing subsequent dynamic allocations.
   */
  inline void
  expression_formatter::reserve (size_t capacity)
  {
    buffer_.reserve (capacity);
  }

  // --------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif

  // --------------------------------------------------------------------------

  /**
   * @details
   * Null pointers are rendered as `"0x0"` to avoid platform-specific
   * representations such as `"(nil)"` on Linux/glibc. Non-null pointers
   * are formatted as a hexadecimal address using `snprintf` with the
   * `%p` specifier.
   */
  template <typename T>
  expression_formatter&
  expression_formatter::operator<< (T* v)
  {
    if (v == nullptr)
      {
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
   * Delegates to `detail::get(t)` to obtain the displayable value
   * of an op expression, then streams it through `operator<<` to
   * format it into the buffer.
   */
  template <class T>
    requires type_traits::is_op<T>
  expression_formatter&
  expression_formatter::operator<< (const T& t)
  {
    *this << detail::get (t);
    return *this;
  }

  /**
   * @details
   * Casts the underlying integral value to `long long` and formats
   * it without a type suffix, appending the result to the buffer.
   */
  template <class T>
  expression_formatter&
  expression_formatter::operator<< (
      const type_traits::genuine_integral_value<T>& v)
  {
    detail::append_number_ (buffer_, static_cast<long long> (v.get ()));
    return *this;
  }

  /**
   * @details
   * Iterates the container and formats each element separated by
   * `", "`, surrounded by `{` and `}`. Each element is streamed
   * through `operator<<`, which recurses as needed for nested types.
   */
  template <class T>
    requires (type_traits::container_like<T> and not type_traits::has_npos<T>)
  expression_formatter&
  expression_formatter::operator<< (const T& t)
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

  // --------------------------------------------------------------------------
  // Compound expression operators (without colour codes).

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
  expression_formatter&
  expression_formatter::operator<< (const detail::eq_<Lhs_T, Rhs_T>& op)
  {
    return (*this << colour_ (op) << op.lhs () << " == " << op.rhs ()
                  << colours_.none);
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
  expression_formatter&
  expression_formatter::operator<< (const detail::ne_<Lhs_T, Rhs_T>& op)
  {
    return (*this << colour_ (op) << op.lhs () << " != " << op.rhs ()
                  << colours_.none);
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
  expression_formatter&
  expression_formatter::operator<< (const detail::gt_<Lhs_T, Rhs_T>& op)
  {
    return (*this << colour_ (op) << op.lhs () << " > " << op.rhs ()
                  << colours_.none);
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
  expression_formatter&
  expression_formatter::operator<< (const detail::ge_<Lhs_T, Rhs_T>& op)
  {
    return (*this << colour_ (op) << op.lhs () << " >= " << op.rhs ()
                  << colours_.none);
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
  expression_formatter&
  expression_formatter::operator<< (const detail::lt_<Rhs_T, Lhs_T>& op)
  {
    return (*this << colour_ (op) << op.lhs () << " < " << op.rhs ()
                  << colours_.none);
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
  expression_formatter&
  expression_formatter::operator<< (const detail::le_<Rhs_T, Lhs_T>& op)
  {
    return (*this << colour_ (op) << op.lhs () << " <= " << op.rhs ()
                  << colours_.none);
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
  expression_formatter&
  expression_formatter::operator<< (const detail::and_<Lhs_T, Rhs_T>& op)
  {
    return (*this << '(' << op.lhs () << colour_ (op) << " and "
                  << colours_.none << op.rhs () << ')');
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
  expression_formatter&
  expression_formatter::operator<< (const detail::or_<Lhs_T, Rhs_T>& op)
  {
    return (*this << '(' << op.lhs () << colour_ (op) << " or "
                  << colours_.none << op.rhs () << ')');
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
  expression_formatter&
  expression_formatter::operator<< (const detail::not_<T>& op)
  {
    return (*this << colour_ (op) << "not " << op.operand () << colours_.none);
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
  template <class Callable_T, class Exception_T>
  expression_formatter&
  expression_formatter::operator<< (
      const detail::throws_<Callable_T, Exception_T>& op)
  {
    return (*this << colour_ (op) << "throws<"
                  << reflection::type_name<Exception_T> () << ">"
                  << colours_.none);
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
  template <class Callable_T>
  expression_formatter&
  expression_formatter::operator<< (
      const detail::throws_<Callable_T, void>& op)
  {
    return (*this << colour_ (op) << "throws" << colours_.none);
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
  template <class Callable_T>
  expression_formatter&
  expression_formatter::operator<< (const detail::nothrow_<Callable_T>& op)
  {
    return (*this << colour_ (op) << "nothrow" << colours_.none);
  }
#endif

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_INLINES_EXPRESSION_FORMATTER_INLINES_H_

// ----------------------------------------------------------------------------

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
 * `operator<<(T*)`, `operator<<(is_op<T>)`, and `operator<<(container)` —
 * are instantiated per concrete type at each call site.
 *
 * The compound expression operators format comparator expressions and wrap
 * them in the pass/fail colour codes of the owning reporter.
 *
 * Numbers and pointers are formatted with the `detail::append_number()`
 * and `detail::append_pointer()` helpers, defined in `detail-inlines.h`
 * and shared with the reporter.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_EXPRESSION_FORMATTER_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_EXPRESSION_FORMATTER_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/reflection.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus::detail
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * Initialises the `colours_` reference with the provided `colours`
   * instance. The internal buffer is default-initialised to an empty string.
   */
  inline expression_formatter::expression_formatter (
      const colours& colours) noexcept
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
  expression_formatter::str (void) const noexcept
  {
    return buffer_;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * The address is formatted by the `detail::append_pointer()` helper,
   * shared with the `detail::reporter`.
   */
  template <typename T>
    requires (not std::is_same_v<T, char>)
  expression_formatter&
  expression_formatter::operator<< (T* v)
  {
    detail::append_pointer (buffer_, v);
    return *this;
  }

  /**
   * @details
   * Delegates to `detail::unwrap(t)` to obtain the displayable value
   * of an op expression, then streams it through `operator<<` to
   * format it into the buffer.
   */
  template <class T>
    requires extension::is_op<T>
  expression_formatter&
  expression_formatter::operator<< (const T& t)
  {
    *this << detail::unwrap (t);
    return *this;
  }

  /**
   * @details
   * Iterates the container and formats each element separated by
   * `", "`, surrounded by `{` and `}`. Each element is streamed
   * through `operator<<`, which recurses as needed for nested types.
   */
  template <class T>
    requires (detail::container_like<T> and not detail::has_npos<T>)
  expression_formatter&
  expression_formatter::operator<< (const T& t)
  {
    *this << "{";
    auto first = true;
    for (const auto& arg : t)
      {
        *this << (first ? "" : ", ") << arg;
        first = false;
      }
    *this << "}";
    return *this;
  }

  /**
   * @details
   * Converts the value with `static_cast` to the underlying type, and
   * streams the result through `operator<<`, which selects the overload
   * of that type.
   */
  template <class T>
    requires (std::is_enum_v<T>
              and not std::is_convertible_v<T, std::underlying_type_t<T>>)
  expression_formatter&
  expression_formatter::operator<< (T v)
  {
    return *this << static_cast<std::underlying_type_t<T>> (v);
  }

  /**
   * @details
   * Writes the opening parenthesis, the two members through
   * `append_elements_()`, and the closing parenthesis.
   */
  template <class T1, class T2>
  expression_formatter&
  expression_formatter::operator<< (const std::pair<T1, T2>& p)
  {
    *this << "(";
    append_elements_ (p, std::index_sequence_for<T1, T2>{});
    *this << ")";
    return *this;
  }

  /**
   * @details
   * Writes the opening parenthesis, the elements through
   * `append_elements_()`, and the closing parenthesis.
   */
  template <class... Ts>
  expression_formatter&
  expression_formatter::operator<< (const std::tuple<Ts...>& t)
  {
    *this << "(";
    append_elements_ (t, std::index_sequence_for<Ts...>{});
    *this << ")";
    return *this;
  }

  /**
   * @details
   * Streams the contained value through `operator<<` if there is one,
   * otherwise streams `std::nullopt`.
   */
  template <class T>
  expression_formatter&
  expression_formatter::operator<< (const std::optional<T>& o)
  {
    if (o.has_value ())
      {
        return *this << *o;
      }
    return *this << std::nullopt;
  }

  /**
   * @details
   * Expands the indices in a fold expression over the comma operator,
   * so the elements are written in order; the separator is omitted
   * before the first element. For an empty tuple, nothing is written.
   */
  template <class Tuple_T, std::size_t... Is>
  void
  expression_formatter::append_elements_ ([[maybe_unused]] const Tuple_T& t,
                                          std::index_sequence<Is...>)
  {
    ((*this << (Is == 0 ? "" : ", ") << std::get<Is> (t)), ...);
  }

  // --------------------------------------------------------------------------
  // Compound expression operators (with pass/fail colour codes).

  /**
   * @details
   * This operator overload enables the `reporter` to output relational
   * comparison expressions in a clear and expressive format.
   *
   * The left-hand side and right-hand side values are formatted and separated
   * by the operator symbol of the tag (`==`, `!=`, `>`, `>=`, `<`, or `<=`),
   * with appropriate colour highlighting applied for improved readability in
   * test reports and diagnostics. This structured output assists in quickly
   * identifying the values involved in the assertions and facilitates
   * efficient debugging of test failures.
   */
  template <class Lhs_T, class Rhs_T, class Compare_T>
  expression_formatter&
  expression_formatter::operator<< (
      const detail::compare_op<Lhs_T, Rhs_T, Compare_T>& op)
  {
    return (*this << colour_ (op) << op.lhs () << Compare_T::symbol
                  << op.rhs () << colours_.none);
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
  expression_formatter::operator<< (const detail::and_op<Lhs_T, Rhs_T>& op)
  {
    return (*this << "(" << op.lhs () << colour_ (op) << " and "
                  << colours_.none << op.rhs () << ")");
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
  expression_formatter::operator<< (const detail::or_op<Lhs_T, Rhs_T>& op)
  {
    return (*this << "(" << op.lhs () << colour_ (op) << " or "
                  << colours_.none << op.rhs () << ")");
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
  expression_formatter::operator<< (const detail::not_op<T>& op)
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
   * expected, and assists in the precise identification and debugging of
   * exception-related test cases.
   */
  template <class Callable_T, class Exception_T>
  expression_formatter&
  expression_formatter::operator<< (
      const detail::throws_op<Callable_T, Exception_T>& op)
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
   * immediately apparent when an expression is expected to throw.
   */
  template <class Callable_T>
  expression_formatter&
  expression_formatter::operator<< (
      const detail::throws_op<Callable_T, void>& op)
  {
    return (*this << colour_ (op) << "throws" << colours_.none);
  }

  /**
   * @details
   * This operator overload formats output for expressions that are expected
   * not to throw exceptions. It applies colour styling for clarity.
   *
   * The output highlights the `nothrow` qualifier, making it immediately
   * apparent when an expression is expected not to throw.
   */
  template <class Callable_T>
  expression_formatter&
  expression_formatter::operator<< (const detail::nothrow_op<Callable_T>& op)
  {
    return (*this << colour_ (op) << "nothrow" << colours_.none);
  }
#endif // defined(__cpp_exceptions)

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_EXPRESSION_FORMATTER_INLINES_H_

// ----------------------------------------------------------------------------

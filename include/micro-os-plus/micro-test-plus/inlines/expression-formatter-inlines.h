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
 * This header provides the inline and template member function
 * implementations for `expression_formatter`: the constructors, the
 * `str()` accessor, and the template operators (for the pointers, the
 * value wrappers, the ranges, the scoped enumerations, the pairs, the
 * tuples, the optionals, and the expressions), which are instantiated
 * for each concrete type. It also defines `plain_text::append()`.
 *
 * The compound expression operators format comparator expressions and wrap
 * them in the pass/fail colour codes of the owning reporter.
 *
 * Numbers and pointers are formatted with the `detail::append_number()`
 * and `detail::append_pointer()` helpers, defined in `detail-inlines.h`
 * and shared with the reporter.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace.
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

  /**
   * @details
   * Takes over the text of @p buffer, without copying it, refers to the
   * `colours_none` set, and sets the plain mode.
   */
  inline expression_formatter::expression_formatter (
      std::string&& buffer) noexcept
      : colours_ (colours_none), buffer_ (std::move (buffer)), plain_ (true)
  {
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Returns the ANSI colour code for pass or fail, depending on the boolean
   * condition provided.
   */
  inline auto
  expression_formatter::colour (const bool cond) const
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
   * of a value wrapper, then streams it through `operator<<` to
   * format it into the buffer. The `get()` constraint guarantees that
   * `detail::unwrap(t)` returns the wrapped value, not the wrapper
   * itself, which would select this overload again.
   */
  template <class T>
    requires (extension::is_op<T> and requires (const T& v) { v.get (); })
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
   *
   * The range-based `for` statement uses the `begin()` and `end()`
   * members, or, if there are none, the functions found by
   * argument-dependent lookup, as `detail::formattable_range` does.
   */
  template <class T>
    requires detail::formattable_range<T>
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
   * `append_elements()`, and the closing parenthesis.
   */
  template <class T1, class T2>
  expression_formatter&
  expression_formatter::operator<< (const std::pair<T1, T2>& p)
  {
    *this << "(";
    append_elements (p, std::index_sequence_for<T1, T2>{});
    *this << ")";
    return *this;
  }

  /**
   * @details
   * Writes the opening parenthesis, the elements through
   * `append_elements()`, and the closing parenthesis.
   */
  template <class... Ts>
  expression_formatter&
  expression_formatter::operator<< (const std::tuple<Ts...>& t)
  {
    *this << "(";
    append_elements (t, std::index_sequence_for<Ts...>{});
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
  expression_formatter::append_elements ([[maybe_unused]] const Tuple_T& t,
                                         std::index_sequence<Is...>)
  {
    ((*this << (Is == 0 ? "" : ", ") << std::get<Is> (t)), ...);
  }

  // --------------------------------------------------------------------------
  // Compound expression operators (with pass/fail colour codes).

  /**
   * @details
   * The left-hand side and right-hand side values are formatted and
   * separated by the operator symbol of the tag (`==`, `!=`, `>`, `>=`,
   * `<`, or `<=` for the built-in tags, or the symbol of an application
   * tag), in the colour of the result (green for passed, red for failed,
   * when colours are enabled).
   */
  template <class Lhs_T, class Rhs_T, class Compare_T>
  expression_formatter&
  expression_formatter::operator<< (
      const detail::compare_op<Lhs_T, Rhs_T, Compare_T>& op)
  {
    return (*this << colour (op) << op.lhs () << Compare_T::symbol << op.rhs ()
                  << colours_.none);
  }

  /**
   * @details
   * Formats the operands of an approximate comparison as
   * `lhs ~ (rhs +/- epsilon)`, in the colour of the result, as the
   * relational comparisons are.
   */
  template <class Lhs_T, class Rhs_T, class Epsilon_T>
  expression_formatter&
  expression_formatter::operator<< (
      const detail::approx_op<Lhs_T, Rhs_T, Epsilon_T>& op)
  {
    return (*this << colour (op) << op.lhs () << " ~ (" << op.rhs () << " +/- "
                  << op.epsilon () << ")" << colours_.none);
  }

  /**
   * @details
   * The left-hand side and right-hand side expressions are formatted as
   * they are, enclosed in parentheses, and separated by the word `and`,
   * written in the colour of the result of the conjunction.
   */
  template <class Lhs_T, class Rhs_T>
  expression_formatter&
  expression_formatter::operator<< (const detail::and_op<Lhs_T, Rhs_T>& op)
  {
    return (*this << "(" << op.lhs () << colour (op) << " and "
                  << colours_.none << op.rhs () << ")");
  }

  /**
   * @details
   * The left-hand side and right-hand side expressions are formatted as
   * they are, enclosed in parentheses, and separated by the word `or`,
   * written in the colour of the result of the disjunction.
   */
  template <class Lhs_T, class Rhs_T>
  expression_formatter&
  expression_formatter::operator<< (const detail::or_op<Lhs_T, Rhs_T>& op)
  {
    return (*this << "(" << op.lhs () << colour (op) << " or " << colours_.none
                  << op.rhs () << ")");
  }

  /**
   * @details
   * Writes the word `not`, followed by the operand, in the colour of the
   * result of the negation.
   */
  template <class T>
  expression_formatter&
  expression_formatter::operator<< (const detail::not_op<T>& op)
  {
    return (*this << colour (op) << "not " << op.operand () << colours_.none);
  }

  /**
   * @details
   * Writes the symbol of the tag, followed by the operand, with the same
   * colour highlighting as the logical negation, so that the predicates of
   * the application are reported as the built-in expressions are.
   */
  template <class T, class Predicate_T>
  expression_formatter&
  expression_formatter::operator<< (
      const detail::predicate_op<T, Predicate_T>& op)
  {
    return (*this << colour (op) << Predicate_T::symbol << op.operand ()
                  << colours_.none);
  }

#if defined(__cpp_exceptions)
  /**
   * @details
   * Writes `throws`, followed, when a specific exception type is
   * expected, by its name between angle brackets, as returned by
   * `reflection::type_name()`, in the colour of the result.
   */
  template <class Exception_T>
  expression_formatter&
  expression_formatter::operator<< (const detail::throws_op<Exception_T>& op)
  {
    if constexpr (std::is_void_v<Exception_T>)
      {
        return (*this << colour (op) << "throws" << colours_.none);
      }
    else
      {
        return (*this << colour (op) << "throws<"
                      << reflection::type_name<Exception_T> () << ">"
                      << colours_.none);
      }
  }

  /**
   * @details
   * Writes `nothrow`, in the colour of the result.
   *
   * It is defined inline, not in the library sources, so that it is
   * available to the applications built with exceptions even when the
   * library is built without them.
   */
  inline expression_formatter&
  expression_formatter::operator<< (const detail::nothrow_op& op)
  {
    return (*this << colour (op) << "nothrow" << colours_.none);
  }
#endif // defined(__cpp_exceptions)

  // --------------------------------------------------------------------------

  /**
   * @details
   * The text is moved into a formatter in the plain mode, the value is
   * appended with the same `operator<<` overloads as the messages, and
   * the text is moved back.
   */
  template <class T>
    requires extension::printable<T>
  void
  plain_text::append (std::string& text, const T& value)
  {
    expression_formatter formatter{ std::move (text) };
    formatter << value;
    text = std::move (formatter.buffer_);
  }

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

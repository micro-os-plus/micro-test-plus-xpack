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
 * This file is included by `expression-formatter.h`; the applications include
 * `micro-os-plus/micro-test-plus.h`, not this file.
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
   * Refers to the `colours_none` set, so that nothing is coloured; the
   * internal buffer is empty and the mode is not plain.
   */
  inline expression_formatter::expression_formatter (void) noexcept
      : colours_ (colours_none)
  {
  }

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
  inline expression_formatter::colour_code
  expression_formatter::colour (const bool cond) const
  {
    return colour_code{ cond ? colours_.pass : colours_.fail };
  }

  /**
   * @details
   * Returns the reset code of the colours of the formatter.
   */
  inline expression_formatter::colour_code
  expression_formatter::colour_none (void) const
  {
    return colour_code{ colours_.none };
  }

  /**
   * @details
   * Appends the escape sequence to the buffer as it is, without the
   * escaping of the control characters that the string overloads apply.
   */
  inline expression_formatter&
  expression_formatter::operator<< (colour_code code)
  {
    buffer_.append (code.sequence);
    return *this;
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

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
  /**
   * @details
   * Forwards to `str().c_str()`.
   */
  // Deprecated since 6.0.0; use str().c_str().
  inline const char*
  expression_formatter::c_str (void) const noexcept
  {
    return buffer_.c_str ();
  }

  /**
   * @details
   * Forwards to `str().empty()`.
   */
  // Deprecated since 6.0.0; use str().empty().
  inline bool
  expression_formatter::empty (void) const noexcept
  {
    return buffer_.empty ();
  }
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

  // --------------------------------------------------------------------------

  /**
   * @details
   * The text is not bounded, so it must be null-terminated; the
   * overload for the arrays is more specialised, so it is selected for
   * the arrays, which cannot be read beyond their end.
   */
  template <typename Pointer_T>
    requires detail::character_pointer<Pointer_T>
  expression_formatter&
  expression_formatter::operator<< (Pointer_T s)
  {
    append_c_string (s, std::string_view::npos);
    return *this;
  }

  /**
   * @details
   * The size of the array limits the characters read, so that an array
   * that is full, without a terminator, is not read beyond its end.
   */
  template <typename Char_T, std::size_t N>
    requires (detail::character<Char_T> and not std::is_volatile_v<Char_T>)
  expression_formatter&
  expression_formatter::operator<< (const Char_T (&s)[N])
  {
    append_c_string (static_cast<const Char_T*> (s), N);
    return *this;
  }

  /**
   * @details
   * The address is formatted by the `detail::append_pointer()` helper,
   * shared with the `detail::reporter`.
   */
  template <typename T>
    requires (not detail::character_pointer<T*>)
  expression_formatter&
  expression_formatter::operator<< (T* v)
  {
    detail::append_pointer (buffer_, v);
    return *this;
  }

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
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
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

  /**
   * @details
   * Iterates the container and formats each element separated by
   * `", "`, surrounded by `{` and `}`. Each element is streamed
   * through `operator<<`, which recurses as needed for nested types.
   *
   * Only the first `max_range_elements_` elements are written; if there
   * are more, the elements are still counted, and the text
   * `", ... (<count> elements)"` is written after the last one, so that
   * a check on a large buffer neither exhausts the memory nor buries the
   * report. The elements of the types `signed char` and `unsigned char`
   * (such as `std::uint8_t`) are bytes, not numbers with a type, so they
   * are written without the type suffix.
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
    size_t count = 0;
    for (const auto& arg : t)
      {
        if (count < max_range_elements_)
          {
            *this << (count == 0 ? "" : ", ");
            using element_type = std::remove_cvref_t<decltype (arg)>;
            if constexpr (std::is_same_v<element_type, signed char>
                          or std::is_same_v<element_type, unsigned char>)
              {
                *this << static_cast<int> (arg);
              }
            else
              {
                append_value (arg);
              }
          }
        ++count;
      }
    if (count > max_range_elements_)
      {
        *this << ", ... (";
        detail::append_number (buffer_, count);
        *this << " elements)";
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
    requires (extension::printable<T1> and extension::printable<T2>)
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
    requires (extension::printable<Ts> and ...)
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
    requires extension::printable<T>
  expression_formatter&
  expression_formatter::operator<< (const std::optional<T>& o)
  {
    if (o.has_value ())
      {
        append_value (*o);
        return *this;
      }
    return *this << std::nullopt;
  }

  /**
   * @details
   * Writes the count with `append_number()`, without a type suffix, then
   * the unit selected from the period; the periods without a standard
   * unit are written as the ratio, `[N/D]s`, with the numerator and the
   * denominator also written with `append_number()`, without type
   * suffixes.
   */
  template <class Rep, class Period>
    requires std::is_arithmetic_v<Rep>
  expression_formatter&
  expression_formatter::operator<< (
      const std::chrono::duration<Rep, Period>& d)
  {
    detail::append_number (buffer_, d.count ());

    if constexpr (std::is_same_v<Period, std::nano>)
      {
        return *this << "ns";
      }
    else if constexpr (std::is_same_v<Period, std::micro>)
      {
        return *this << "us";
      }
    else if constexpr (std::is_same_v<Period, std::milli>)
      {
        return *this << "ms";
      }
    else if constexpr (std::is_same_v<Period, std::ratio<1>>)
      {
        return *this << "s";
      }
    else if constexpr (std::is_same_v<Period, std::ratio<60>>)
      {
        return *this << "min";
      }
    else if constexpr (std::is_same_v<Period, std::ratio<3600>>)
      {
        return *this << "h";
      }
    else
      {
        *this << "[";
        detail::append_number (buffer_,
                               static_cast<long long> (Period::num));
        *this << "/";
        detail::append_number (buffer_,
                               static_cast<long long> (Period::den));
        return *this << "]s";
      }
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
    ((*this << (Is == 0 ? "" : ", "), append_value (std::get<Is> (t))), ...);
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Appends the characters of the string, quoted and escaped as the
   * overload for the string view of the character type does (without
   * quotes in the plain mode, with only the control characters escaped),
   * or `"nullptr"` for a null pointer, as the other operator overloads
   * do for these values.
   */
  template <character Char_T>
  expression_formatter&
  expression_formatter::operator<< (const basic_c_string<Char_T>& s)
  {
    if (s.is_null ())
      {
        buffer_.append ("nullptr");
      }
    else
      {
        *this << s.view ();
      }
    return *this;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * The pointers to the character types are written as C strings, quoted
   * and escaped as the `std::string` values are, with a null pointer
   * written as `nullptr`; all the other values are written by
   * `append_operand()`.
   * In the plain mode, used for the messages, the strings are not quoted.
   */
  template <class T>
  void
  expression_formatter::append_value (const T& value)
  {
    using pointee_type = std::remove_cv_t<std::remove_pointer_t<T>>;
    if constexpr (std::is_pointer_v<T> and detail::character<pointee_type>)
      {
        *this << detail::basic_c_string<pointee_type>{ value };
      }
    else
      {
        append_operand (value);
      }
  }

  /**
   * @details
   * The operands of the types that the formatter writes itself are
   * passed to its `operator<<`; the other ones, the application types,
   * are written by `plain_text::append()`, which hands to their
   * `operator<<` a formatter in the plain mode. A type with a free
   * `operator<<` is an application type, even if a template of the
   * formatter accepts it too (a scoped enumeration, or a type with
   * `begin()` and `end()`), since a call on this formatter would select
   * the function of the application, which would write on the formatter
   * of the report with its decorations.
   */
  template <class T>
  void
  expression_formatter::append_operand (const T& value)
  {
    if constexpr (detail::member_printable<T>
                  and not detail::free_printable<T>)
      {
        *this << value;
      }
    else
      {
        plain_text::append (buffer_, value);
      }
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
   *
   * If an equality compares two ranges that are written truncated, the
   * index of the first difference is appended, if the elements written
   * do not show it (see `append_first_difference()`).
   */
  template <class Lhs_T, class Rhs_T, class Compare_T>
  expression_formatter&
  expression_formatter::operator<< (
      const detail::compare_op<Lhs_T, Rhs_T, Compare_T>& op)
  {
    *this << colour (op);
    append_operand (op.lhs ());
    // A tag without a symbol is rejected when the expression is built, and
    // must not give a second error here.
    if constexpr (detail::tag_has_symbol<Compare_T>)
      {
        *this << Compare_T::symbol;
      }
    append_operand (op.rhs ());
    using lhs_type = std::remove_cvref_t<decltype (op.lhs ())>;
    using rhs_type = std::remove_cvref_t<decltype (op.rhs ())>;
    if constexpr (std::is_same_v<Compare_T, detail::equal_to>
                  and detail::formattable_range<lhs_type>
                  and detail::formattable_range<rhs_type>
                  and requires (const lhs_type& l, const rhs_type& r) {
                        {
                          *std::begin (l) == *std::begin (r)
                        } -> std::convertible_to<bool>;
                      })
      {
        append_first_difference (op.lhs (), op.rhs ());
      }
    return (*this << colour_none ());
  }

  /**
   * @details
   * Walks both ranges in step up to the first pair of elements that
   * differ, or up to the end of the shorter one. The elements are compared
   * as the comparator does, with `equal_to::apply()`, so that integers of
   * different signedness are compared by value.
   */
  template <class Lhs_T, class Rhs_T>
  void
  expression_formatter::append_first_difference (const Lhs_T& lhs,
                                                 const Rhs_T& rhs)
  {
    auto l = std::begin (lhs);
    const auto l_end = std::end (lhs);
    auto r = std::begin (rhs);
    const auto r_end = std::end (rhs);

    size_t index = 0;
    while (l != l_end and r != r_end and detail::equal_to::apply (*l, *r))
      {
        l = std::next (l);
        r = std::next (r);
        ++index;
      }

    if (index < max_range_elements_ or (l == l_end and r == r_end))
      {
        return;
      }

    *this << " (first difference at index ";
    detail::append_number (buffer_, index);
    *this << ")";
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
                  << op.epsilon () << ")" << colour_none ());
  }

  /**
   * @details
   * The operands, written by `append_and_operand()`, are separated by
   * the word `and`, in the colour of the result of each conjunction; a
   * chain of conjunctions is enclosed in a single pair of parentheses,
   * which are not coloured.
   */
  template <class Lhs_T, class Rhs_T>
  expression_formatter&
  expression_formatter::operator<< (const detail::and_op<Lhs_T, Rhs_T>& op)
  {
    *this << "(";
    append_and_operand (op);
    return (*this << ")");
  }

  /**
   * @details
   * The generic operand is written through the usual overloads.
   */
  template <class T>
  void
  expression_formatter::append_and_operand (const T& t)
  {
    append_operand (t);
  }

  /**
   * @details
   * The left operand is written first, as the operands of a chain if it is
   * a logical AND too, then the word `and`, coloured by the result of this
   * operation, and the right operand.
   */
  template <class Lhs_T, class Rhs_T>
  void
  expression_formatter::append_and_operand (
      const detail::and_op<Lhs_T, Rhs_T>& op)
  {
    append_and_operand (op.lhs ());
    *this << colour (op) << " and " << colour_none ();
    append_operand (op.rhs ());
  }

  /**
   * @details
   * The operands, written by `append_or_operand()`, are separated by
   * the word `or`, in the colour of the result of each disjunction; a
   * chain of disjunctions is enclosed in a single pair of parentheses,
   * which are not coloured.
   */
  template <class Lhs_T, class Rhs_T>
  expression_formatter&
  expression_formatter::operator<< (const detail::or_op<Lhs_T, Rhs_T>& op)
  {
    *this << "(";
    append_or_operand (op);
    return (*this << ")");
  }

  /**
   * @details
   * The generic operand is written through the usual overloads.
   */
  template <class T>
  void
  expression_formatter::append_or_operand (const T& t)
  {
    append_operand (t);
  }

  /**
   * @details
   * The left operand is written first, as the operands of a chain if it is
   * a logical OR too, then the word `or`, coloured by the result of this
   * operation, and the right operand.
   */
  template <class Lhs_T, class Rhs_T>
  void
  expression_formatter::append_or_operand (
      const detail::or_op<Lhs_T, Rhs_T>& op)
  {
    append_or_operand (op.lhs ());
    *this << colour (op) << " or " << colour_none ();
    append_operand (op.rhs ());
  }

  /**
   * @details
   * Writes the word `not`, followed by the operand, in the colour of the
   * result of the negation. A comparison is written between parentheses
   * (see `append_not_operand()`).
   */
  template <class T>
  expression_formatter&
  expression_formatter::operator<< (const detail::not_op<T>& op)
  {
    const colour_code not_colour = colour (op);
    *this << not_colour << "not ";
    append_not_operand (op.operand (), not_colour);
    return (*this << colour_none ());
  }

  /**
   * @details
   * Written as `append_operand()` writes it.
   */
  template <class T>
  void
  expression_formatter::append_not_operand (const T& t,
                                            [[maybe_unused]] colour_code)
  {
    append_operand (t);
  }

  /**
   * @details
   * The comparison writes its own colours; the opening parenthesis is
   * written in the colour of the negation, which is still active, and,
   * since the comparison resets the colour at its end, the colour is
   * written again before the closing parenthesis.
   */
  template <class Lhs_T, class Rhs_T, class Compare_T>
  void
  expression_formatter::append_not_operand (
      const detail::compare_op<Lhs_T, Rhs_T, Compare_T>& op,
      colour_code outer_colour)
  {
    *this << "(" << op << outer_colour << ")";
  }

  /**
   * @details
   * As for the relational comparisons, the colour of the negation is
   * written again before the closing parenthesis, since the comparison
   * resets it.
   */
  template <class Lhs_T, class Rhs_T, class Epsilon_T>
  void
  expression_formatter::append_not_operand (
      const detail::approx_op<Lhs_T, Rhs_T, Epsilon_T>& op,
      colour_code outer_colour)
  {
    *this << "(" << op << outer_colour << ")";
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
    *this << colour (op);
    if constexpr (detail::tag_has_symbol<Predicate_T>)
      {
        *this << Predicate_T::symbol;
      }
    append_operand (op.operand ());
    return (*this << colour_none ());
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
        *this << colour (op) << "throws";
      }
    else
      {
        // The type name is not a string operand, so it is not quoted.
        *this << colour (op) << "throws<";
        buffer_.append (reflection::type_name<Exception_T> ());
        *this << ">";
      }
    append_throw_reason (op);
    return (*this << colour_none ());
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
    *this << colour (op) << "nothrow";
    append_throw_reason (op);
    return (*this << colour_none ());
  }

  /**
   * @details
   * The `what()` of the exception is written as a string operand, quoted
   * and escaped. Defined inline, not in the library sources, for the same
   * reason as the `operator<<` overloads that call it.
   */
  inline void
  expression_formatter::append_throw_reason (const detail::callable_op& op)
  {
    if (static_cast<bool> (op))
      {
        return;
      }

    if (op.outcome () == detail::throw_outcome::std_exception)
      {
        buffer_.append (", but a std::exception was thrown: ");
        *this << std::string_view{ op.what () };
      }
    else if (op.outcome () == detail::throw_outcome::unknown_exception)
      {
        buffer_.append (", but an exception of unknown type was thrown");
      }
    else
      {
        buffer_.append (", but nothing was thrown");
      }
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

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
 * mathematical utilities.
 *
 * @details
 * This header provides the inline implementations for the mathematical utility
 * templates used within the µTest++ framework. It defines constexpr logic for
 * common mathematical operations, including absolute value, minimum value
 * selection, exponentiation, and compile-time parsing of numeric values from
 * character sequences.
 *
 * These utilities are designed to be lightweight and suitable for embedded
 * environments, supporting both integral and floating-point types, and
 * enabling expressive, type-safe, and efficient compile-time computations.
 * Special attention is given to constexpr compatibility and minimal reliance
 * on the standard library, ensuring portability and performance.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail::math` namespace, since they are
 * implementation details of the literals and of the comparisons, not part
 * of the public API.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_MATH_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_MATH_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include <cstdint>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wc++20-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  namespace detail::math
  {

    /**
     * @details
     * This function template provides a generic, constexpr implementation for
     * obtaining the absolute value of any type that supports comparison and
     * unary negation.
     *
     * The function returns the non-negative value of the input. If the input
     * is less than the default-constructed value of its type (typically zero),
     * the negated value is returned; otherwise, the original value is
     * returned.
     *
     * This utility is designed to be lightweight and suitable for embedded
     * environments, where standard library alternatives may be unavailable,
     * less efficient, or not constexpr.
     */
    template <class T>
    constexpr auto
    abs (const T t) noexcept -> T
    {
      return t < T{} ? -t : t;
    }

    /**
     * @details
     * This function template provides a generic, constexpr implementation for
     * determining the minimum of two values of any type that supports
     * comparison.
     *
     * The function returns a reference to the lesser of the two input values,
     * as determined by the `<` operator. If the second argument is less than
     * the first, it is returned; otherwise, the first argument is returned.
     *
     * This utility is designed to be lightweight and suitable for embedded
     * environments, where standard library alternatives may be unavailable,
     * less efficient, or not constexpr.
     */
    template <class T>
    constexpr auto
    min_value (const T& lhs, const T& rhs) noexcept -> const T&
    {
      return (rhs < lhs) ? rhs : lhs;
    }

    /**
     * @details
     * This function template provides a constexpr implementation for raising a
     * base value to a given exponent, supporting any types that allow
     * multiplication.
     *
     * The function starts from one and multiplies the result by the base
     * `exp` times. If the exponent is zero (or negative), the function
     * returns one (the multiplicative identity for the type).
     *
     * This utility is designed to be lightweight and suitable for embedded
     * environments, where standard library alternatives may be unavailable,
     * less efficient, or not constexpr.
     */
    template <class T, class Exp_T>
    constexpr auto
    pow (const T base, const Exp_T exp) noexcept -> T
    {
      T result{ 1 };
      for (Exp_T i{}; i < exp; ++i)
        result *= base;
      return result;
    }

    /**
     * @details
     * Walks the characters once, counting the decimal digits before the
     * first decimal point (`Fraction` false) or after it (`Fraction`
     * true); the digit separators are skipped.
     */
    template <bool Fraction, char... Cs>
    consteval auto
    count_literal_digits (void) -> std::size_t
    {
      std::size_t count = 0;
      bool is_fraction = false;
      for (const char c : { Cs... })
        {
          if (c == '.')
            {
              is_fraction = true;
            }
          else if (c >= '0' and c <= '9' and is_fraction == Fraction)
            {
              ++count;
            }
        }
      return count;
    }

    /**
     * @details
     * This function template performs compile-time parsing of a numeric value
     * from a sequence of characters, typically provided as a template
     * parameter pack.
     *
     * The characters must be decimal digits, a dot (`.`), or digit
     * separators (`'`), which are skipped; otherwise (e.g. an exponent) the
     * compilation fails with an explicit message, as it does if the
     * integral part has more digits than `T` can always hold. Parsing stops
     * at the first dot, allowing the function to extract only the integral
     * part of the number.
     *
     * This utility is particularly useful for user-defined literals and other
     * compile-time constant expressions, enabling efficient and type-safe
     * conversion from character sequences to integral values.
     */
    template <class T, char... Cs>
    consteval auto
    num (void) -> T
    {
      static_assert (
          ((Cs == '.' or Cs == '\'' or (Cs >= '0' and Cs <= '9')) and ...),
          "µTest++: a floating-point literal must be written with decimal "
          "digits and a decimal point, without an exponent");
      static_assert (
          count_literal_digits<false, Cs...> ()
              <= static_cast<std::size_t> (std::numeric_limits<T>::digits10),
          "µTest++: the floating-point literal has too many "
          "digits before the decimal point");
      T result{};
      for (const char c : { Cs... })
        {
          if (c == '.')
            {
              break;
            }
          if (c >= '0' and c <= '9')
            {
              result = static_cast<T> (result * static_cast<T> (10)
                                       + static_cast<T> (c - '0'));
            }
        }
      return result;
    }

    /**
     * @details
     * This function template performs compile-time extraction of the decimal
     * (fractional) part from a sequence of characters, typically provided as a
     * template parameter pack.
     *
     * The function expects the character sequence to represent a numeric
     * value, where all characters are either digits, a dot (`.`), or an
     * apostrophe (`'`). Parsing begins after the first dot, accumulating the
     * decimal digits as an integer value and skipping the digit separators;
     * the result is then multiplied by ten (e.g. `1.25` yields 250),
     * matching the scale returned by `den_size()`, so that
     * `den() / 10^den_size()` gives the fraction. If the result could
     * exceed `T`, the compilation fails with an explicit message.
     *
     * This utility is particularly useful for user-defined literals and other
     * compile-time constant expressions, enabling efficient and type-safe
     * conversion from character sequences to the decimal part of numeric
     * values.
     */
    template <class T, char... Cs>
    consteval auto
    den (void) -> T
    {
      static_assert ((... || (Cs == '.')),
                     "den(): no decimal point in literal");
      // The result has one more digit than the decimals (it is scaled by
      // ten), and it must fit in `T`.
      static_assert (
          count_literal_digits<true, Cs...> () + 1
              <= static_cast<std::size_t> (std::numeric_limits<T>::digits10),
          "µTest++: the floating-point literal has too many "
          "decimals");
      T result{};
      bool is_fraction = false;
      for (const char c : { Cs... })
        {
          if (c == '.')
            {
              is_fraction = true;
            }
          else if (is_fraction and c >= '0' and c <= '9')
            {
              // The digit separators are skipped.
              result = static_cast<T> (result * static_cast<T> (10)
                                       + static_cast<T> (c - '0'));
            }
        }
      return static_cast<T> (result * static_cast<T> (10));
    }

    /**
     * @details
     * This function template determines, at compile time, the number of
     * decimal (fractional) digits present in a numeric value represented by a
     * character sequence, typically provided as a template parameter pack.
     *
     * The function expects the character sequence to represent a numeric
     * value, where all characters are either digits, a dot (`.`), or an
     * apostrophe (`'`). It returns the number of digits that follow the
     * first dot (the digit separators are not counted) plus one (e.g. 3 for
     * `1.25`), which is the scale used by `den()`; the actual number of
     * decimal places is one less.
     *
     * This utility is particularly useful for user-defined literals and other
     * compile-time constant expressions, enabling efficient and type-safe
     * determination of decimal precision from character sequences.
     */
    template <class T, char... Cs>
    consteval auto
    den_size (void) -> T
    {
      static_assert ((... || (Cs == '.')),
                     "den_size(): no decimal point in literal");
      return static_cast<T> (count_literal_digits<true, Cs...> () + 1);
    }

    /**
     * @details
     * This function template determines the number of decimal (fractional)
     * digits present in a floating-point value, with a precision of about
     * seven digits. Being `constexpr`, it can also be evaluated at compile
     * time.
     *
     * The function repeatedly multiplies the absolute value by ten,
     * incrementing a counter until the distance to the nearest integer is
     * at most a defined precision threshold (1e-7). Using the distance to
     * the nearest integer, not the fractional part, prevents the rounding
     * noise of a value just below an integer (e.g. 2674.9999999999995) from
     * being taken as more decimals.
     *
     * The loop also stops when the value reaches the magnitude from which
     * the type can represent only integers (2^23 for `float`, 2^52 for
     * `double`), limited to 2^63 so that the conversion to
     * `unsigned long long` is always defined. This bounds the number of
     * steps for large values, infinities, and NaNs, for which the result
     * is one.
     *
     * This utility is particularly useful for user-defined literals and
     * compile-time constant expressions, enabling efficient and type-safe
     * determination of decimal precision from floating-point values.
     */
    template <class T, class Value_T>
    constexpr auto
    den_size (Value_T value) -> T
    {
      constexpr auto precision = Value_T (1e-7);
      // From this magnitude upwards all values are integers.
      constexpr auto integral_limit
          = min_value (Value_T (1) / std::numeric_limits<Value_T>::epsilon (),
                       Value_T (1ULL << 63));

      value = abs (value);
      T result{};
      for (;;)
        {
          value *= 10;
          ++result;

          // Also true for infinities and NaNs.
          if (not (value < integral_limit))
            {
              break;
            }

          const auto fraction
              = value
                - static_cast<Value_T> (
                    static_cast<unsigned long long> (value));
          if (min_value (fraction, Value_T (1) - fraction) <= precision)
            {
              break;
            }
        }

      return result;
    }

    /**
     * @details
     * The characters are those of a valid C++ literal, already checked by
     * the compiler (digits valid for the base, digit separators in valid
     * positions). The base is given by the prefix: `0x` or `0X` for
     * hexadecimal, `0b` or `0B` for binary, a leading `0` for octal, and
     * none for decimal. The digit separators (`'`) are skipped.
     *
     * Any other character (a decimal point, an exponent, or a digit not
     * valid for the base, as in the floating-point literal `09.5`) marks
     * the literal as not an integer. The value is accumulated in
     * `unsigned long long`, and the accumulation stops if it would
     * overflow.
     */
    template <char... Cs>
    consteval auto
    parse_integer_literal (void) -> integer_literal
    {
      constexpr std::array<char, sizeof...(Cs)> cs{ Cs... };
      constexpr unsigned long long max_value
          = std::numeric_limits<unsigned long long>::max ();

      integer_literal result{ 0, true, false };

      unsigned long long base = 10;
      std::size_t i = 0;
      if (cs.size () > 1 && cs[0] == '0')
        {
          if (cs[1] == 'x' || cs[1] == 'X')
            {
              base = 16;
              i = 2;
            }
          else if (cs[1] == 'b' || cs[1] == 'B')
            {
              base = 2;
              i = 2;
            }
          else
            {
              base = 8;
              i = 1;
            }
        }

      for (; i < cs.size (); ++i)
        {
          const char c = cs[i];
          if (c == '\'')
            {
              continue;
            }

          unsigned long long digit = 0;
          if (c >= '0' && c <= '9')
            {
              digit = static_cast<unsigned long long> (c - '0');
            }
          else if (base == 16 && c >= 'a' && c <= 'f')
            {
              digit = static_cast<unsigned long long> (c - 'a' + 10);
            }
          else if (base == 16 && c >= 'A' && c <= 'F')
            {
              digit = static_cast<unsigned long long> (c - 'A' + 10);
            }
          else
            {
              // A decimal point, an exponent, or a suffix character.
              result.is_integer = false;
              return result;
            }

          if (digit >= base)
            {
              // Possible only in a floating-point literal, like `09.5`.
              result.is_integer = false;
              return result;
            }

          if (result.value > (max_value - digit) / base)
            {
              result.is_too_large = true;
              return result;
            }

          result.value = result.value * base + digit;
        }

      return result;
    }

    /**
     * @details
     * The literal must be an integer literal, in any of the C++ forms
     * (decimal, hexadecimal, binary, or octal, with digit separators), and
     * its value must fit in `T`; otherwise the compilation fails with an
     * explicit message. Negative values are obtained with the unary minus,
     * so the literal itself is never negative; the minimum value of a
     * signed type (e.g. -128 for `int8_t`) cannot be written as a literal of
     * that type, as its absolute value does not fit.
     */
    template <class T, char... Cs>
    consteval auto
    integer (void) -> T
    {
      constexpr integer_literal literal = parse_integer_literal<Cs...> ();

      static_assert (literal.is_integer,
                     "µTest++: an integer literal must not have a decimal "
                     "point or an exponent");
      static_assert (!literal.is_integer || !literal.is_too_large,
                     "µTest++: the integer literal is too large");
      static_assert (!literal.is_integer || literal.is_too_large
                         || literal.value <= static_cast<unsigned long long> (
                                std::numeric_limits<T>::max ()),
                     "µTest++: the integer literal value does not fit in the "
                     "type of the literal");

      return static_cast<T> (literal.value);
    }

    // ------------------------------------------------------------------------
  } // namespace detail::math

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_MATH_INLINES_H_

// ----------------------------------------------------------------------------

/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
 */

// ----------------------------------------------------------------------------

/**
 * @file math.h
 * @brief Mathematical utilities for the µTest++ testing framework.
 *
 * @details
 * This header provides a suite of constexpr mathematical function templates
 * and utilities for use within the µTest++ framework.
 *
 * The functions defined herein include generic implementations for absolute
 * value, minimum value, exponentiation, and compile-time parsing of numeric
 * values from character arrays. These utilities are designed to be lightweight
 * and suitable for embedded environments, where standard library alternatives
 * may be unavailable, less efficient, or not constexpr.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus::math`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * The implementation draws inspiration from Boost UT, adapting relevant
 * concepts to address the requirements of embedded development and the µTest++
 * framework.
 *
 * All related source files are organised within the `include/micro-os-plus`
 * folder to maintain a structured and modular codebase.
 *
 * This file is intended for internal use within the framework and should not
 * be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_MATH_H_
#define MICRO_TEST_PLUS_MATH_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <array>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::math
   * @brief Mathematical utilities for the µTest++ testing framework.
   *
   * @details
   * The `math` namespace offers a suite of constexpr mathematical
   * function templates and utilities for use within the µTest++ framework.
   *
   * These functions include generic implementations for absolute value,
   * minimum value, exponentiation, and compile-time parsing of numeric values
   * from character arrays. The utilities are designed to be lightweight and
   * suitable for embedded environments, where standard library alternatives
   * may be unavailable, less efficient, or not constexpr.
   *
   * All definitions within this namespace are intended to facilitate
   * mathematical operations in a type-safe and efficient manner, and are
   * implemented in the `include/micro-os-plus` folder to maintain a structured
   * and modular codebase.
   */
  namespace math
  {
    /**
     * @brief Computes the absolute value of a given comparable value.
     *
     * @tparam T The type of the input value. Must support comparison and unary
     * negation.
     *
     * @param t The value for which the absolute value is to be computed.
     * @return The absolute value of the input.
     *
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
    [[nodiscard]] constexpr auto
    abs (const T t) -> T
    {
      return t < T{} ? -t : t;
    }

    /**
     * @brief Computes the minimum of two comparable values.
     *
     * @tparam T The type of the input values. Must support comparison via the
     * `<` operator.
     *
     * @param lhs The first value to compare.
     * @param rhs The second value to compare.
     * @return A reference to the minimum of the two input values.
     *
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
    [[nodiscard]] constexpr auto
    min_value (const T& lhs, const T& rhs) -> const T&
    {
      return (rhs < lhs) ? rhs : lhs;
    }

    /**
     * @brief Generic exponentiation function to compute the power of a base
     * raised to an exponent.
     *
     * @tparam T The type of the base value. Must support multiplication and
     * construction from an integer.
     * @tparam Exp_T The type of the exponent. Must support subtraction and
     * comparison to zero.
     *
     * @param base The base value to be raised to the power of \p exp.
     * @param exp The exponent value.
     * @return The result of raising \p base to the power of \p exp.
     *
     * @details
     * This function template provides a constexpr implementation for raising a
     * base value to a given exponent, supporting any types that allow
     * multiplication and subtraction.
     *
     * The function recursively multiplies the base by itself exponent times.
     * If the exponent is zero, the function returns one (the multiplicative
     * identity for the type).
     *
     * This utility is designed to be lightweight and suitable for embedded
     * environments, where standard library alternatives may be unavailable,
     * less efficient, or not constexpr.
     */
    template <class T, class Exp_T>
    [[nodiscard]] constexpr auto
    pow (const T base, const Exp_T exp) -> T
    {
      // If the exponent is 0, return 1, otherwise recurse.
      return exp ? T (base * pow (base, exp - Exp_T (1))) : T (1);
    }

    /**
     * @brief Computes the integral value of a number represented as an array
     * of characters.
     *
     * @tparam T The target integral type for the result.
     * @tparam Cs The character pack representing the numeric value.
     *
     * @par Parameters
     *	 None.
     * @return The parsed integral value of type \c T.
     *
     * @details
     * This function template performs compile-time parsing of a numeric value
     * from a sequence of characters, typically provided as a template
     * parameter pack.
     *
     * The function assumes that all characters are either digits, a dot (`.`),
     * or an apostrophe (`'`). Parsing stops at the first dot, allowing the
     * function to extract only the integral part of the number.
     *
     * This utility is particularly useful for user-defined literals and other
     * compile-time constant expressions, enabling efficient and type-safe
     * conversion from character sequences to integral values.
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    num (void) -> T
    {
      // Assume all are digits or dot or apostrophe.
      static_assert (
          ((Cs == '.' or Cs == '\'' or (Cs >= '0' and Cs <= '9')) and ...));
      T result{};
      for (const char c : { Cs... })
        {
          if (c == '.')
            {
              break;
            }
          if (c >= '0' and c <= '9')
            {
              result = result * T (10) + T (c - '0');
            }
        }
      return result;
    }

    /**
     * @brief Computes the decimal part of a number represented as an array of
     * characters.
     *
     * @tparam T The target integral type for the result.
     * @tparam Cs The character pack representing the numeric value.
     *
     * @par Parameters
     *	 None.
     * @return The parsed decimal part as an integral value of type \c T.
     *
     * @details
     * This function template performs compile-time extraction of the decimal
     * (fractional) part from a sequence of characters, typically provided as a
     * template parameter pack.
     *
     * The function expects the character sequence to represent a numeric
     * value, where all characters are either digits, a dot (`.`), or an
     * apostrophe (`'`). Parsing begins after the first dot, accumulating the
     * decimal digits as an integer value, each weighted by its decimal
     * position.
     *
     * This utility is particularly useful for user-defined literals and other
     * compile-time constant expressions, enabling efficient and type-safe
     * conversion from character sequences to the decimal part of numeric
     * values.
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    den (void) -> T
    {
      constexpr const std::array cs{ Cs... };
      T result{};
      auto i = 0u;
      while (cs[i++] != '.')
        {
        }

      for (auto j = i; j < sizeof...(Cs); ++j)
        {
          result += pow (T (10), sizeof...(Cs) - j) * T (cs[j] - '0');
        }
      return result;
    }

    /**
     * @brief Computes the number of decimal places in a number represented as
     * an array of characters.
     *
     * @tparam T The integral type for the result.
     * @tparam Cs The character pack representing the numeric value.
     *
     * @par Parameters
     *	 None.
     * @return The number of decimal places as a value of type \c T.
     *
     * @details
     * This function template determines, at compile time, the number of
     * decimal (fractional) digits present in a numeric value represented by a
     * character sequence, typically provided as a template parameter pack.
     *
     * The function expects the character sequence to represent a numeric
     * value, where all characters are either digits, a dot (`.`), or an
     * apostrophe (`'`). It locates the first dot and counts the number of
     * digits that follow, returning the count as the number of decimal places.
     *
     * This utility is particularly useful for user-defined literals and other
     * compile-time constant expressions, enabling efficient and type-safe
     * determination of decimal precision from character sequences.
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    den_size (void) -> T
    {
      constexpr const std::array cs{ Cs... };
      T i{};
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
      while (cs[i++] != '.')
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
        {
        }

      return T (sizeof...(Cs)) - i + T (1);
    }

    /**
     * @brief Computes the number of decimal places of a value, up to 7 digits.
     *
     * @tparam T The integral type for the result.
     * @tparam Value_T The type of the input value, typically a floating-point
     * type.
     *
     * @param value The value whose decimal precision is to be determined.
     * @return The number of decimal places, as a value of type \c T, up to a
     * maximum of seven.
     *
     * @details
     * This function template determines, at compile time, the number of
     * decimal (fractional) digits present in a floating-point value, up to a
     * maximum of seven digits of precision.
     *
     * The function repeatedly multiplies the input value by ten, incrementing
     * a counter until the fractional part is less than a defined precision
     * threshold (1e-7). This approach provides a robust means of estimating
     * decimal precision for values where exact representation is not possible
     * due to floating-point limitations.
     *
     * This utility is particularly useful for user-defined literals and
     * compile-time constant expressions, enabling efficient and type-safe
     * determination of decimal precision from floating-point values.
     */
    template <class T, class Value_T>
    [[nodiscard]] constexpr auto
    den_size (Value_T value) -> T
    {
      constexpr auto precision = Value_T (1e-7);
      T result{};
      Value_T tmp{};
      do
        {
          value *= 10;
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if !defined(__clang__) // GCC only
#pragma GCC diagnostic ignored "-Warith-conversion"
#endif
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#endif
#endif
          tmp = value - T (value);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
          ++result;
        }
      while (tmp > precision);

      return result;
    }

  } // namespace math

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_MATH_H_

// ----------------------------------------------------------------------------

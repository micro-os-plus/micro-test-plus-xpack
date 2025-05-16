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
     * @brief Generic absolute of any comparable value.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    abs (const T t) -> T
    {
      return t < T{} ? -t : t;
    }

    /**
     * @brief Generic minimum of two comparable values.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    min_value (const T& lhs, const T& rhs) -> const T&
    {
      return (rhs < lhs) ? rhs : lhs;
    }

    /**
     * @brief Generic 'power of', to raise base to exponent (base ^ exp).
     */
    template <class T, class Exp_T>
    [[nodiscard]] constexpr auto
    pow (const T base, const Exp_T exp) -> T
    {
      // If the exponent is 0, return 1, otherwise recurse.
      return exp ? T (base * pow (base, exp - Exp_T (1))) : T (1);
    }

    /**
     * @brief Compute the integral value of a number represented as
     * an array of characters.
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    num () -> T
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
     * @brief Compute the decimals of a number represented as
     * an array of characters.
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    den () -> T
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
     * @brief Compute the number of decimal places of a number represented as
     * an array of characters.
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    den_size () -> T
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
     * @brief Compute the number of decimal places of a value,
     * up to 7 digits.
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

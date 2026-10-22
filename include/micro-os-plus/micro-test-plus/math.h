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
 * @brief C++ header file with declarations for the µTest++ mathematical
 * utilities.
 *
 * @details
 * This header provides the declarations for the mathematical utility templates
 * used within the µTest++ framework. It defines interfaces for a suite of
 * constexpr mathematical functions, including absolute value, minimum value
 * selection, exponentiation, and compile-time parsing of numeric values from
 * character sequences.
 *
 * These utilities are lightweight, `constexpr` or `consteval`, and
 * support both integral and floating-point types; they depend only on
 * `<array>` and `<limits>`.
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_MATH_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_MATH_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include <array>
#include <limits>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wpadded"
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

  /**
   * @namespace micro_os_plus::micro_test_plus::detail::math
   * @brief Internal mathematical utilities for the µTest++ testing framework.
   *
   * @details
   * The `detail::math` namespace offers a suite of constexpr mathematical
   * function templates and utilities, used by the literals and by the
   * floating-point comparisons of the µTest++ framework.
   *
   * These functions include generic implementations for absolute value,
   * minimum value, exponentiation, and compile-time parsing of numeric values
   * from character arrays. The utilities are designed to be lightweight and
   * suitable for embedded environments, where standard library alternatives
   * may be unavailable, less efficient, or not constexpr.
   *
   * The names of these functions suggest general mathematical functions,
   * but their scope is limited to the needs of the framework (for example,
   * `pow()` accepts only integral exponents); like everything in `detail`,
   * they are not part of the public API and may be modified without prior
   * notice.
   */
  namespace detail::math
  {
    /**
     * @brief Computes the absolute value of a given comparable value.
     *
     * @tparam T The type of the input value. Must support comparison and unary
     * negation.
     *
     * @param t The value for which the absolute value is to be computed.
     * @return The absolute value of the input.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    abs (const T t) noexcept -> T;

    /**
     * @brief Computes the minimum of two comparable values.
     *
     * @tparam T The type of the input values. Must support comparison via the
     * `<` operator.
     *
     * @param lhs The first value to compare.
     * @param rhs The second value to compare.
     * @return A reference to the minimum of the two input values.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    min_value (const T& lhs, const T& rhs) noexcept -> const T&;

    /**
     * @brief Generic exponentiation function to compute the power of a base
     * raised to an exponent.
     *
     * @tparam T The type of the base value. Must support multiplication
     * assignment and construction from an integer.
     * @tparam Exp_T The type of the exponent. Must be default-constructible
     * (to zero), and support the `<` and prefix `++` operators.
     *
     * @param base The base value to be raised to the power of \p exp.
     * @param exp The exponent value.
     * @return The result of raising \p base to the power of \p exp.
     */
    template <class T, class Exp_T>
    [[nodiscard]] constexpr auto
    pow (const T base, const Exp_T exp) noexcept -> T;

    /**
     * @brief Counts the decimal digits of a floating-point literal, before
     * or after the decimal point.
     *
     * @details
     * The digit separators (`'`) are not counted.
     *
     * @tparam Fraction `true` to count the digits after the decimal point,
     * `false` to count those before it.
     * @tparam Cs The characters of the literal.
     *
     * @par Parameters
     *   None.
     * @return The number of digits.
     */
    template <bool Fraction, char... Cs>
    [[nodiscard]] consteval auto
    count_literal_digits (void) -> std::size_t;

    /**
     * @brief Computes the integral part of a decimal floating-point number
     * represented as an array of characters.
     *
     * @details
     * Used by the floating-point literal operators; the integer literals
     * use `integer_magnitude()`, which also accepts the C++ prefixes and
     * checks the range.
     *
     * @tparam T The target integral type for the result.
     * @tparam Cs The character pack representing the numeric value.
     *
     * @par Parameters
     *   None.
     * @return The parsed integral value of type \c T.
     */
    template <class T, char... Cs>
    [[nodiscard]] consteval auto
    num (void) -> T;

    /**
     * @brief Computes the decimal part of a number represented as an array
     * of characters.
     *
     * @tparam T The target integral type for the result.
     * @tparam Cs The character pack representing the numeric value; it must
     * contain a decimal point.
     *
     * @par Parameters
     *   None.
     * @return The digits after the decimal point, as an integral value of
     * type \c T (e.g. 25 for `1.25`), to be divided by ten raised to the
     * power returned by `den_size()`.
     */
    template <class T, char... Cs>
    [[nodiscard]] consteval auto
    den (void) -> T;

    /**
     * @brief Counts the decimal places of a number represented as an array
     * of characters.
     *
     * @tparam T The integral type for the result.
     * @tparam Cs The character pack representing the numeric value; it must
     * contain a decimal point.
     *
     * @par Parameters
     *   None.
     * @return The number of decimal places (e.g. 2 for `1.25`), as a value
     * of type \c T; it is the scale of the value returned by `den()`.
     */
    template <class T, char... Cs>
    [[nodiscard]] consteval auto
    den_size (void) -> T;

    /**
     * @brief Computes the number of decimal places of a value, with a
     * precision of about seven digits.
     *
     * @tparam T The integral type for the result.
     * @tparam Value_T The type of the input value, a floating-point type.
     *
     * @param value The value whose decimal precision is to be determined;
     * it may be negative, infinite, or a NaN.
     * @return The number of decimal places, as a value of type \c T, at
     * least one, or zero for a zero value; the leading zeros of a value
     * below one are counted; it is limited by the magnitude from which
     * `Value_T` represents only integers.
     */
    template <class T, class Value_T>
    [[nodiscard]] constexpr auto
    count_decimals (Value_T value) -> T;

    /**
     * @brief Computes the default comparison tolerance of a floating-point
     * value, one unit of its last decimal.
     *
     * @tparam Value_T The type of the value, a floating-point type.
     *
     * @param value The value whose tolerance is to be determined; it may
     * be negative, infinite, or a NaN.
     * @return Ten raised to minus the number of decimal places returned by
     * `count_decimals()` (0.01 for `1.25`, 1e-12 for `1e-12`), or zero, which
     * means an exact comparison, for a zero value and for a value whose
     * tolerance would be below the range of `Value_T`.
     */
    template <class Value_T>
    [[nodiscard]] constexpr auto
    decimal_epsilon (Value_T value) -> Value_T;

    /**
     * @brief The result of parsing the characters of an integer literal.
     *
     * @details
     * Returned by `parse_integer_literal()`; the checks of
     * `integer_magnitude()` are based on it.
     */
    struct integer_literal
    {
      /**
       * @brief The value of the literal.
       *
       * @details
       * Valid only if `is_integer` is true and `is_too_large` is false.
       */
      unsigned long long value;

      /**
       * @brief Whether the characters form an integer literal.
       *
       * @details
       * False for the floating-point literals (with a decimal point or an
       * exponent), which the literal operator templates also receive.
       */
      bool is_integer;

      /**
       * @brief Whether the value exceeds `unsigned long long`.
       *
       * @details
       * Detected while the digits are accumulated.
       */
      bool is_too_large;
    };

    /**
     * @brief Parses the characters of an integer literal.
     *
     * @tparam Cs The characters of the literal, as received by a literal
     * operator template.
     *
     * @par Parameters
     *   None.
     * @return The value, and whether the characters form an integer literal
     * and whether its value fits in `unsigned long long`.
     */
    template <char... Cs>
    [[nodiscard]] consteval auto
    parse_integer_literal (void) -> integer_literal;

    /**
     * @brief Computes the value of an integer literal of type @c T, before
     * any negation.
     *
     * @tparam T The integral type of the literal.
     * @tparam Cs The characters of the literal, as received by a literal
     * operator template.
     *
     * @par Parameters
     *   None.
     * @return The value of the literal, up to `max ()` of \c T, or, for the
     * signed types, up to `max () + 1`, the absolute value of the minimum.
     */
    template <class T, char... Cs>
    [[nodiscard]] consteval auto
    integer_magnitude (void) -> unsigned long long;

    // ------------------------------------------------------------------------
  } // namespace detail::math

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/math-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_MATH_H_

// ----------------------------------------------------------------------------

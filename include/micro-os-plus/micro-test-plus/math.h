/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
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
 * These utilities are designed to be lightweight and suitable for embedded
 * environments, supporting both integral and floating-point types, and
 * enabling expressive, type-safe, and efficient compile-time computations.
 * Special attention is given to constexpr compatibility and minimal reliance
 * on the standard library, ensuring portability and performance across a wide
 * range of platforms.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus::math`
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
     */
    template <class T>
    [[nodiscard]] constexpr auto
    abs (const T t) -> T;

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
    min_value (const T& lhs, const T& rhs) -> const T&;

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
     */
    template <class T, class Exp_T>
    [[nodiscard]] constexpr auto
    pow (const T base, const Exp_T exp) -> T;

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
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    num (void) -> T;

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
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    den (void) -> T;

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
     */
    template <class T, char... Cs>
    [[nodiscard]] constexpr auto
    den_size (void) -> T;

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
     */
    template <class T, class Value_T>
    [[nodiscard]] constexpr auto
    den_size (Value_T value) -> T;

    // ------------------------------------------------------------------------
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

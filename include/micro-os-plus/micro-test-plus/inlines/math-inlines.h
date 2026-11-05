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
 * These utilities are lightweight, `constexpr` or `consteval`, and
 * support both integral and floating-point types.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail::math` namespace, since they are
 * implementation details of the literals and of the comparisons, not part
 * of the public API.
 *
 * This file is included by `math.h`; the applications include
 * `micro-os-plus/micro-test-plus.h`, not this file.
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
     */
    template <class T>
    constexpr auto
    abs (const T t) noexcept -> T
    {
      return t < T{} ? -t : t;
    }

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @details
     * This function template provides a generic, constexpr implementation for
     * determining the minimum of two values of any type that supports
     * comparison.
     *
     * The function returns a reference to the lesser of the two input values,
     * as determined by the `<` operator. If the second argument is less than
     * the first, it is returned; otherwise, the first argument is returned.
     */
    template <class T>
    constexpr auto
    min_value (const T& lhs, const T& rhs) noexcept -> const T&
    {
      return (rhs < lhs) ? rhs : lhs;
    }
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

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

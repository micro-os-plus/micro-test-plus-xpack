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
 * This header provides the declaration of the mathematical utility template
 * used within the µTest++ framework: the absolute value, used by the
 * approximate comparison; and, only if the deprecated functionality is
 * enabled, the minimum value, used by the tolerance of the deprecated
 * wrappers. The exponentiation and the compile-time parsing of the numeric
 * literals, which serve only the deprecated wrappers and literals, are
 * declared in `deprecated.h`.
 *
 * These utilities are lightweight, `constexpr`, and support both integral
 * and floating-point types.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail::math` namespace, since they are
 * implementation details of the comparisons, not part of the public API.
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

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
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
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

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

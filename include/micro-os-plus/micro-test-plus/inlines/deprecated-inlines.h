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
 * @brief C++ header file with inline implementations for the deprecated
 * µTest++ definitions.
 *
 * @details
 * This header provides the inline implementations for the deprecated
 * definitions declared in `deprecated.h`: the v5.0.1 names of the
 * logical functions (`_not`, `_and`, and `_or`), which forward to
 * `negate()`, `all_of()`, and `any_of()`, and the members of the
 * `detail::timestamp` class.
 *
 * The constructor of `detail::timestamp` that reads the system clock is
 * defined in `src/deprecated.cpp`, with `detail::read_clock()`, the
 * clock access used by `detail::stopwatch`.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DEPRECATED_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DEPRECATED_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * Forwards to `negate()`, so the returned expression is the same, and
   * is reported in the same way.
   */
  // Deprecated since 5.1.0; use negate().
  template <class Expr_T>
  constexpr auto
  _not (Expr_T&& expr)
  {
    return negate (std::forward<Expr_T> (expr));
  }

  /**
   * @details
   * Forwards to `all_of()`, so the returned expression is the same, and
   * is reported in the same way.
   */
  // Deprecated since 5.1.0; use all_of().
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  _and (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return all_of (std::forward<Lhs_T> (lhs), std::forward<Rhs_T> (rhs));
  }

  /**
   * @details
   * Forwards to `any_of()`, so the returned expression is the same, and
   * is reported in the same way.
   */
  // Deprecated since 5.1.0; use any_of().
  template <class Lhs_T, class Rhs_T>
  constexpr auto
  _or (Lhs_T&& lhs, Rhs_T&& rhs)
  {
    return any_of (std::forward<Lhs_T> (lhs), std::forward<Rhs_T> (rhs));
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ============================================================================

namespace micro_os_plus::micro_test_plus::detail
{
  // ==========================================================================

  /**
   * @details
   * Copies @p ts into the stored value.
   */
  // Deprecated since 5.1.0, as the whole `timestamp` class; the timings are
  // internal.
  inline timestamp::timestamp (const timespec& ts) noexcept : value_{ ts }
  {
  }

  /**
   * @details
   * Returns `true` if either the seconds or the nanoseconds member is
   * not zero.
   */
  // Deprecated since 5.1.0, as the whole `timestamp` class; the timings are
  // internal.
  inline bool
  timestamp::has_clock (void) const noexcept
  {
    return value_.tv_sec != 0 || value_.tv_nsec != 0;
  }

  /**
   * @details
   * The caller may modify the stored time through the returned
   * reference.
   */
  // Deprecated since 5.1.0, as the whole `timestamp` class; the timings are
  // internal.
  inline timespec&
  timestamp::value (void) noexcept
  {
    return value_;
  }

  /**
   * @details
   * The returned reference is valid as long as the object exists.
   */
  // Deprecated since 5.1.0, as the whole `timestamp` class; the timings are
  // internal.
  inline const timespec&
  timestamp::value (void) const noexcept
  {
    return value_;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_DEPRECATED_INLINES_H_

// ----------------------------------------------------------------------------

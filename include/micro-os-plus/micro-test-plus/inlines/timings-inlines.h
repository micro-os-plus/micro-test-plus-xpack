/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ header file with inline implementations for the µTest++
 * timing utilities.
 *
 * @details
 * This header provides the inline method bodies for the `timestamp` and
 * `timestamps` classes, separated from the class declarations in
 * `timings.h` to enforce the project convention that declarations reside
 * in headers and implementations reside in inline files.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising
 * the risk of naming conflicts.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TIMINGS_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TIMINGS_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus::detail
{
  // ==========================================================================

  /**
   * @details
   * Stores the supplied `timespec` value in the `value_` member.
   */
  inline timestamp::timestamp (const timespec& ts) noexcept : value_{ ts }
  {
  }

  /**
   * @details
   * Returns a mutable reference to the `value_` member.
   */
  inline timespec&
  timestamp::value () noexcept
  {
    return value_;
  }

  /**
   * @details
   * Returns a const reference to the `value_` member.
   */
  inline const timespec&
  timestamp::value () const noexcept
  {
    return value_;
  }

  // ==========================================================================

  /**
   * @details
   * Returns `true` when `begin_time_` holds a value, i.e. when
   * `timestamp_begin()` has previously been called.
   */
  inline bool
  timestamps::has_begin () const noexcept
  {
    return begin_time_.has_value ();
  }

  /**
   * @details
   * Returns `true` when `end_time_` holds a value, i.e. when
   * `timestamp_end()` has previously been called.
   */
  inline bool
  timestamps::has_end () const noexcept
  {
    return end_time_.has_value ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TIMINGS_INLINES_H_

// ----------------------------------------------------------------------------

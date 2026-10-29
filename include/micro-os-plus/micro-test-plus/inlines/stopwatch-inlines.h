// ----------------------------------------------------------------------------
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
 * stopwatch.
 *
 * @details
 * This header provides the inline member function bodies of the
 * `stopwatch` class, separated from the class declaration in
 * `stopwatch.h` to enforce the project convention that declarations
 * reside in headers and implementations reside in inline files.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace, ensuring clear
 * separation from user code and minimising
 * the risk of naming conflicts.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_STOPWATCH_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_STOPWATCH_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
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
   * Returns `true` only when both the start and the stop readings were
   * recorded, as determined by `is_recorded()`.
   */
  inline bool
  stopwatch::has_elapsed (void) const noexcept
  {
    return is_recorded (start_time_) && is_recorded (stop_time_);
  }

  /**
   * @details
   * Returns `true` if at least one of the `tv_sec` or `tv_nsec` members
   * of @p ts is non-zero, indicating that a clock reading was captured.
   */
  inline bool
  stopwatch::is_recorded (const timespec& ts) noexcept
  {
    return ts.tv_sec != 0 || ts.tv_nsec != 0;
  }

  // --------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
  /**
   * @details
   * Returns `true` if the start reading was recorded, as determined by
   * `is_recorded()`.
   */
  // Deprecated since 6.0.0; use has_elapsed().
  inline bool
  stopwatch::has_begin (void) const noexcept
  {
    return is_recorded (start_time_);
  }

  /**
   * @details
   * Returns `true` if the stop reading was recorded, as determined by
   * `is_recorded()`.
   */
  // Deprecated since 6.0.0; use has_elapsed().
  inline bool
  stopwatch::has_end (void) const noexcept
  {
    return is_recorded (stop_time_);
  }

  /**
   * @details
   * Forwards to `has_elapsed()`.
   */
  // Deprecated since 6.0.0; use has_elapsed().
  inline bool
  stopwatch::has_timestamps (void) const noexcept
  {
    return has_elapsed ();
  }

  /**
   * @details
   * Divides the microseconds count returned by `elapsed()` by 1000; the
   * conversions to `uint32_t` truncate the intervals longer than about
   * 49 days, as in v5.0.1.
   */
  // Deprecated since 6.0.0; use elapsed().
  inline void
  stopwatch::compute_elapsed_time (uint32_t& milliseconds,
                                   uint32_t& microseconds) const noexcept
  {
    const auto count = elapsed ().count ();
    milliseconds = static_cast<uint32_t> (count / 1000);
    microseconds = static_cast<uint32_t> (count % 1000);
  }

  /**
   * @details
   * Stores @p ts only if `is_recorded()` reports no start reading.
   */
  // Deprecated since 6.0.0; use start().
  inline void
  stopwatch::timestamp_begin (const timespec& ts) noexcept
  {
    if (!is_recorded (start_time_))
      {
        start_time_ = ts;
      }
  }

  /**
   * @details
   * Stores @p ts only if `is_recorded()` reports no stop reading.
   */
  // Deprecated since 6.0.0; use stop().
  inline void
  stopwatch::timestamp_end (const timespec& ts) noexcept
  {
    if (!is_recorded (stop_time_))
      {
        stop_time_ = ts;
      }
  }
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_STOPWATCH_INLINES_H_

// ----------------------------------------------------------------------------

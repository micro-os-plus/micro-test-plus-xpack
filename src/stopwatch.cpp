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
 * @brief C++ source file with implementations for the µTest++ stopwatch.
 *
 * @details
 * This source file contains the implementation of the `stopwatch` class
 * of the µTest++ framework. It provides the member functions that read
 * the system clock (monotonic on POSIX) at the start and at the end of
 * the measured interval, and that compute the elapsed time between the
 * two readings, and `read_clock()`, which isolates the platform-specific
 * access to the system clock.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/stopwatch.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus::detail
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * On Windows, the current time is captured via `timespec_get()` with
   * `TIME_UTC`. On POSIX platforms with `CLOCK_MONOTONIC` defined,
   * `clock_gettime(CLOCK_MONOTONIC)` is used to obtain a monotonic
   * reading. On platforms where neither macro is defined, @p ts is
   * left unchanged.
   */
  void
  read_clock (timespec& ts) noexcept
  {
#if defined(_WIN32)
    timespec_get (&ts, TIME_UTC);
#elif defined(CLOCK_MONOTONIC)
    clock_gettime (CLOCK_MONOTONIC, &ts);
#else
    (void)ts;
#endif // defined(_WIN32) || defined(CLOCK_MONOTONIC)
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Clears both readings, then reads the system clock into
   * `start_time_`. The readings are cleared first because
   * `read_clock()` leaves its argument unchanged on the platforms
   * without a clock, where a previous reading would otherwise survive.
   */
  void
  stopwatch::start (void) noexcept
  {
    start_time_ = {};
    stop_time_ = {};
    read_clock (start_time_);
  }

  /**
   * @details
   * Clears the stop reading, then reads the system clock into
   * `stop_time_`, for the same reason as in `start()`. The start
   * reading is not changed.
   */
  void
  stopwatch::stop (void) noexcept
  {
    stop_time_ = {};
    read_clock (stop_time_);
  }

  /**
   * @details
   * Converts the differences of the seconds and of the nanoseconds
   * members to a single nanoseconds duration, so that a negative
   * nanoseconds difference borrows from the seconds without explicit
   * normalisation, and truncates the result to whole microseconds. If
   * `has_elapsed()` is `false`, the result is zero.
   */
  std::chrono::microseconds
  stopwatch::elapsed (void) const noexcept
  {
    if (!has_elapsed ())
      {
        return std::chrono::microseconds::zero ();
      }

    const std::chrono::nanoseconds delta = std::chrono::seconds{
      stop_time_.tv_sec - start_time_.tv_sec
    } + std::chrono::nanoseconds{ stop_time_.tv_nsec - start_time_.tv_nsec };

    return std::chrono::duration_cast<std::chrono::microseconds> (delta);
  }

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
  /**
   * @details
   * Reads the system clock into `start_time_` only if `is_recorded()`
   * reports no start reading; since the reading is zero in that case,
   * it need not be cleared first, as in `start()`.
   */
  // Deprecated since 6.0.0; use start().
  void
  stopwatch::timestamp_begin (void) noexcept
  {
    if (!is_recorded (start_time_))
      {
        read_clock (start_time_);
      }
  }

  /**
   * @details
   * Reads the system clock into `stop_time_` only if `is_recorded()`
   * reports no stop reading, for the same reason as in
   * `timestamp_begin()`.
   */
  // Deprecated since 6.0.0; use stop().
  void
  stopwatch::timestamp_end (void) noexcept
  {
    if (!is_recorded (stop_time_))
      {
        read_clock (stop_time_);
      }
  }
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

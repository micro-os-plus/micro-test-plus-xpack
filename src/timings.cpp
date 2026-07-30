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
 * @brief C++ source file with implementations for the µTest++ timings
 * methods.
 *
 * @details
 * This source file contains the implementations for the `timestamp` and
 * `timestamps` classes of the µTest++ framework. It provides methods
 * for capturing monotonic clock values, checking whether valid
 * timestamps have been recorded, and computing the elapsed time in
 * milliseconds and microseconds between a begin and an end timestamp.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus` namespace.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/timings.h"

#include <cassert>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

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
   * timestamp. On platforms where neither macro is defined, `value_`
   * remains zero-initialised.
   */
  timestamp::timestamp () noexcept
  {
#if defined(_WIN32)
    timespec_get (&value_, TIME_UTC);
#elif defined(CLOCK_MONOTONIC)
    clock_gettime (CLOCK_MONOTONIC, &value_);
#endif
  }

  /**
   * @details
   * Returns `true` if at least one of the `tv_sec` or `tv_nsec` fields
   * of the underlying `timespec` is non-zero, indicating that a valid
   * clock reading was successfully captured.
   */
  bool
  timestamp::has_clock (void) const noexcept
  {
    return value_.tv_sec != 0 || value_.tv_nsec != 0;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * If the begin timestamp has not yet been set, a `timestamp` is
   * constructed in-place using the default constructor, which captures
   * the current monotonic time. Subsequent calls are silently ignored,
   * ensuring idempotent behaviour.
   */
  void
  timestamps::timestamp_begin (void) noexcept
  {
    // Ensure it is timestamped only once.
    if (!begin_time_.has_value ())
      {
        begin_time_.emplace ();
      }
  }

  /**
   * @details
   * If the begin timestamp has not yet been set, a `timestamp` is
   * constructed in-place from the supplied `timespec` value. Subsequent
   * calls are silently ignored, ensuring idempotent behaviour.
   */
  void
  timestamps::timestamp_begin (const timespec& ts) noexcept
  {
    // Ensure it is timestamped only once.
    if (!begin_time_.has_value ())
      {
        begin_time_.emplace (ts);
      }
  }

  /**
   * @details
   * If the end timestamp has not yet been set, a `timestamp` is
   * constructed in-place using the default constructor, which captures
   * the current monotonic time. Subsequent calls are silently ignored,
   * ensuring idempotent behaviour.
   */
  void
  timestamps::timestamp_end (void) noexcept
  {
    // Ensure it is timestamped only once.
    if (!end_time_.has_value ())
      {
        end_time_.emplace ();
      }
  }

  /**
   * @details
   * If the end timestamp has not yet been set, a `timestamp` is
   * constructed in-place from the supplied `timespec` value. Subsequent
   * calls are silently ignored, ensuring idempotent behaviour.
   */
  void
  timestamps::timestamp_end (const timespec& ts) noexcept
  {
    // Ensure it is timestamped only once.
    if (!end_time_.has_value ())
      {
        end_time_.emplace (ts);
      }
  }

  /**
   * @details
   * Returns `true` only when both the begin and end optional timestamps
   * are engaged and each contains a valid (non-zero) clock reading, as
   * determined by `timestamp::has_clock()`.
   */
  bool
  timestamps::has_timestamps (void) const noexcept
  {
    return begin_time_.has_value () && begin_time_->has_clock ()
           && end_time_.has_value () && end_time_->has_clock ();
  }

  /**
   * @details
   * Subtracts the begin timestamp from the end timestamp in nanoseconds.
   * If the nanosecond difference is negative, one second is borrowed
   * from the seconds delta to normalise the result. The total elapsed
   * duration in microseconds is then split into whole milliseconds
   * (written to @p milliseconds) and the remainder microseconds (written
   * to @p microseconds). Requires `has_timestamps()` to be `true`;
   * behaviour is undefined otherwise.
   */
  void
  timestamps::compute_elapsed_time (uint32_t& milliseconds,
                                    uint32_t& microseconds) const
  {
    assert (has_timestamps ());

    // Precondition: has_timestamps() must be true before calling this method.
    // Invoking it with disengaged optionals is undefined behaviour.
    long long delta_ns
        = end_time_->value ().tv_nsec - begin_time_->value ().tv_nsec;
    long long delta_s
        = end_time_->value ().tv_sec - begin_time_->value ().tv_sec;
    if (delta_ns < 0)
      {
        delta_ns += 1000000000LL;
        --delta_s;
      }

    // Split into milliseconds and microseconds.
    const long long total_us = delta_s * 1000000LL + delta_ns / 1000LL;
    milliseconds = static_cast<uint32_t> (total_us / 1000LL);
    microseconds = static_cast<uint32_t> (total_us % 1000LL);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

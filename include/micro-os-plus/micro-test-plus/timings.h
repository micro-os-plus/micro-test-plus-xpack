
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
 * @brief C++ header file with declarations for the µTest++ timing utilities.
 *
 * @details
 * This header provides two lightweight classes used to measure the elapsed
 * time of test suites and test sessions within the µTest++ framework:
 *
 * - `timestamp` wraps a single `timespec` value and records one point in
 *   time. The default constructor reads the clock; the class is trivially
 *   copyable.
 * - `timestamps` pairs a begin and an end `timestamp` (both stored as
 *   `std::optional<timestamp>`) and exposes methods for recording the
 *   start and finish of an operation, querying whether both timestamps are
 *   available, and computing the elapsed time in milliseconds and
 *   microseconds.
 *
 * Timing support relies on `clock_gettime(CLOCK_MONOTONIC, ...)` on POSIX
 * platforms and on `timespec_get(..., TIME_UTC)` on Windows. If no clock is
 * available (e.g. on bare-metal targets without an RTC), the recorded
 * values remain zero, `has_timestamps()` returns `false`, and no timing
 * information is reported.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_TIMINGS_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TIMINGS_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include <cstdint>
#include <optional>
#include <ctime>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  namespace detail
  {
    // ========================================================================

    /**
     * @brief A single point-in-time measurement, wrapping a `timespec` value.
     *
     * @details
     * `timestamp` stores one `timespec` sample obtained from the system clock.
     * The default constructor captures the current time; the class is
     * copy-constructible and move-constructible, so that it can be used
     * efficiently in `std::optional<timestamp>` containers.
     *
     * The `has_clock()` predicate allows callers to determine whether the
     * stored value is a valid clock reading, since on targets without a
     * clock the value remains zero.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class timestamp
    {
    public:
      /**
       * @brief Default constructor. Captures the current time.
       *
       * @details
       * On targets without a clock, the internal `timespec` remains
       * zero-initialised.
       */
      timestamp () noexcept;

      /**
       * @brief Constructs a timestamp from an existing `timespec` value.
       *
       * @param ts The `timespec` value to store.
       */
      timestamp (const timespec& ts) noexcept;

      // `timespec` is trivially copyable, so copy and move are safe to
      // default. Defaulting these operations allows `timestamp` to be used in
      // contexts that require copyability or movability (e.g. containers,
      // algorithms).
      /**
       * @brief Defaulted copy constructor.
       *
       * @details
       * Copies the stored `timespec` value member-wise.
       */
      timestamp (const timestamp&) = default;

      /**
       * @brief Defaulted move constructor.
       *
       * @details
       * Equivalent to a copy, since `timespec` is trivially copyable.
       */
      timestamp (timestamp&&) = default;

      /**
       * @brief Defaulted copy assignment operator.
       *
       * @details
       * Copies the stored `timespec` value member-wise.
       *
       * @return Reference to this instance.
       */
      timestamp&
      operator= (const timestamp&)
          = default;

      /**
       * @brief Defaulted move assignment operator.
       *
       * @details
       * Equivalent to a copy, since `timespec` is trivially copyable.
       *
       * @return Reference to this instance.
       */
      timestamp&
      operator= (timestamp&&)
          = default;

      /**
       * @brief Defaulted destructor.
       *
       * @details
       * No resources are owned, so there is nothing to release.
       */
      ~timestamp () = default;

      /**
       * @brief Checks whether the stored value is a valid clock reading.
       *
       * @par Parameters
       *   None.
       * @retval true  A clock is available and the stored value is valid.
       * @retval false No clock is available; timing data should be ignored.
       */
      bool
      has_clock (void) const noexcept;

      /**
       * @brief Returns a mutable reference to the underlying `timespec` value.
       *
       * @par Parameters
       *   None.
       * @return A reference to the stored `timespec`.
       */
      [[nodiscard]] timespec&
      value () noexcept;

      /**
       * @brief Returns a const reference to the underlying `timespec` value.
       *
       * @par Parameters
       *   None.
       * @return A const reference to the stored `timespec`.
       */
      [[nodiscard]] const timespec&
      value () const noexcept;

    protected:
      /**
       * @brief The underlying `timespec` value.
       *
       * @details
       * Zero-initialised, then set by the constructors; a zero value means
       * that no clock reading is available.
       */
      timespec value_{};
    };

    // ========================================================================

    /**
     * @brief A begin/end timestamp pair used to measure elapsed time.
     *
     * @details
     * `timestamps` stores an optional begin `timestamp` and an optional end
     * `timestamp`. When both are available, `compute_elapsed_time()` derives
     * the elapsed interval in milliseconds and microseconds.
     *
     * Typical usage in the framework:
     * 1. Call `timestamp_begin()` just before the test suite or session
     *    body executes.
     * 2. Call `timestamp_end()` immediately after it completes.
     * 3. Pass the elapsed values to the reporter.
     *
     * If the platform does not provide a clock, the recorded timestamps hold
     * zero values and `has_timestamps()` returns `false`, so that the
     * reporter can skip timing output.
     *
     * The class is non-copyable and non-movable to prevent accidental sharing
     * of live timing state.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class timestamps
    {
    public:
      /**
       * @brief Default constructor.
       *
       * @details
       * Both optional timestamps are initially empty; they are set by
       * `timestamp_begin()` and `timestamp_end()`.
       */
      timestamps () = default;

      /**
       * @brief Deleted copy constructor to prevent copying.
       *
       * @details
       * The timing state belongs to a single test node.
       */
      timestamps (const timestamps&) = delete;

      /**
       * @brief Deleted move constructor to prevent moving.
       *
       * @details
       * The instance is a member of a node that is itself non-movable.
       */
      timestamps (timestamps&&) = delete;

      /**
       * @brief Deleted copy assignment operator to prevent copying.
       *
       * @details
       * The timing state belongs to a single test node.
       */
      timestamps&
      operator= (const timestamps&)
          = delete;

      /**
       * @brief Deleted move assignment operator to prevent moving.
       *
       * @details
       * The instance is a member of a node that is itself non-movable.
       */
      timestamps&
      operator= (timestamps&&)
          = delete;

      /**
       * @brief Defaulted destructor.
       *
       * @details
       * No resources are owned, so there is nothing to release.
       */
      ~timestamps () = default;

      /**
       * @brief Records the begin timestamp using the current system clock.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      void
      timestamp_begin (void) noexcept;

      /**
       * @brief Records the begin timestamp from a caller-supplied value.
       *
       * @param ts The `timespec` value to use as the begin timestamp.
       * @par Returns
       *   Nothing.
       */
      void
      timestamp_begin (const timespec& ts) noexcept;

      /**
       * @brief Records the end timestamp using the current system clock.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      void
      timestamp_end (void) noexcept;

      /**
       * @brief Records the end timestamp from a caller-supplied value.
       *
       * @param ts The `timespec` value to use as the end timestamp.
       * @par Returns
       *   Nothing.
       */
      void
      timestamp_end (const timespec& ts) noexcept;

      /**
       * @brief Returns true if the begin timestamp has been recorded.
       *
       * @par Parameters
       *   None.
       * @retval true  `timestamp_begin()` has been called.
       * @retval false `timestamp_begin()` has not been called.
       */
      bool
      has_begin () const noexcept;

      /**
       * @brief Returns true if the end timestamp has been recorded.
       *
       * @par Parameters
       *   None.
       * @retval true  `timestamp_end()` has been called.
       * @retval false `timestamp_end()` has not been called.
       */
      bool
      has_end () const noexcept;

      /**
       * @brief Returns true if both begin and end timestamps are available.
       *
       * @par Parameters
       *   None.
       * @retval true  Both timestamps are present and elapsed time can be
       *               computed.
       * @retval false At least one timestamp is absent; elapsed time is not
       *               available.
       */
      bool
      has_timestamps (void) const noexcept;

      /**
       * @brief Computes the elapsed time between begin and end timestamps.
       *
       * @param[out] milliseconds The elapsed time in whole milliseconds.
       * @param[out] microseconds The sub-millisecond remainder in
       * microseconds.
       * @par Returns
       *   Nothing.
       *
       * @pre `has_timestamps()` returns `true`.
       */
      void
      compute_elapsed_time (uint32_t& milliseconds,
                            uint32_t& microseconds) const;

    protected:
      /**
       * @brief The timestamp recorded at the beginning of the measured
       * interval.
       *
       * @details
       * Empty until `timestamp_begin()` is called; set only once.
       */
      std::optional<timestamp> begin_time_;

      /**
       * @brief The timestamp recorded at the end of the measured interval.
       *
       * @details
       * Empty until `timestamp_end()` is called; set only once.
       */
      std::optional<timestamp> end_time_;
    };

    // ------------------------------------------------------------------------
  } // namespace detail
  // ==========================================================================
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/timings-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TIMINGS_H_

// ----------------------------------------------------------------------------

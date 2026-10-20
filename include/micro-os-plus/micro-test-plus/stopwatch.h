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
 * @brief C++ header file with the declaration of the µTest++ stopwatch.
 *
 * @details
 * This header provides the `stopwatch` class, used to measure the
 * elapsed time of the test suites and of the test session within the
 * µTest++ framework. The stopwatch is started before the measured
 * operation, stopped after it, and then reports the elapsed time as a
 * `std::chrono::microseconds` duration.
 *
 * Timing support relies on `clock_gettime(CLOCK_MONOTONIC, ...)` on POSIX
 * platforms and on `timespec_get(..., TIME_UTC)` on Windows. If no clock is
 * available (e.g. on bare-metal targets without an RTC), the readings
 * remain zero, `has_elapsed()` returns `false`, and no timing information
 * is reported.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_STOPWATCH_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_STOPWATCH_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include <chrono>
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
     * @brief Measures the elapsed time of an operation.
     *
     * @details
     * `start()` reads the system clock just before the measured operation
     * and `stop()` just after it; when both readings are available,
     * `elapsed()` returns the interval between them.
     *
     * Each call reads the clock again: `start()` restarts the
     * measurement, discarding both previous readings, and `stop()`
     * replaces the previous stop reading, if any. A zero reading means
     * that the clock was not read, either because the stopwatch was not
     * started (or stopped), or because the platform has no clock; in both
     * cases `has_elapsed()` returns `false`, so that the reporters can
     * skip the timing output.
     *
     * Typical usage in the framework:
     * 1. Call `start()` just before the test suite or session body
     *    executes.
     * 2. Call `stop()` immediately after it completes.
     * 3. The reporters display `elapsed()`, when `has_elapsed()`.
     *
     * The class is non-copyable and non-movable to prevent accidental
     * sharing of live timing state.
     *
     * The non-public members are `protected`, not `private`, only so that
     * the unit tests can derive from the class and set known readings;
     * the class is not meant to be extended otherwise.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class stopwatch
    {
    public:
      /**
       * @brief Default constructor.
       *
       * @details
       * Both readings are initially zero; they are set by `start()` and
       * `stop()`.
       */
      stopwatch (void) = default;

      /**
       * @brief Deleted copy constructor to prevent copying.
       *
       * @details
       * The timing state belongs to a single suite or runner.
       */
      stopwatch (const stopwatch&) = delete;

      /**
       * @brief Deleted move constructor to prevent moving.
       *
       * @details
       * The instance is a member of an object that is itself non-movable.
       */
      stopwatch (stopwatch&&) = delete;

      /**
       * @brief Deleted copy assignment operator to prevent copying.
       *
       * @details
       * The timing state belongs to a single suite or runner.
       */
      stopwatch&
      operator= (const stopwatch&)
          = delete;

      /**
       * @brief Deleted move assignment operator to prevent moving.
       *
       * @details
       * The instance is a member of an object that is itself non-movable.
       */
      stopwatch&
      operator= (stopwatch&&)
          = delete;

      /**
       * @brief Defaulted destructor.
       *
       * @details
       * No resources are owned, so there is nothing to release.
       */
      ~stopwatch () = default;

      /**
       * @brief Records the start time, from the system clock.
       *
       * @details
       * Each call restarts the measurement: the stop reading is cleared,
       * so `has_elapsed()` is `false` until the next `stop()`.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      void
      start (void) noexcept;

      /**
       * @brief Records the stop time, from the system clock.
       *
       * @details
       * Each call replaces the previous stop reading, if any, so the
       * elapsed time is measured from the start to the last `stop()`.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      void
      stop (void) noexcept;

      /**
       * @brief Checks whether the elapsed time is available.
       *
       * @details
       * The elapsed time is available after both `start()` and `stop()`
       * were called, on a platform with a clock.
       *
       * @par Parameters
       *   None.
       * @retval true  Both readings are available; `elapsed()` returns
       *               the measured interval.
       * @retval false At least one reading is absent; `elapsed()` returns
       *               zero.
       */
      [[nodiscard]] bool
      has_elapsed (void) const noexcept;

      /**
       * @brief Gets the time elapsed between `start()` and `stop()`.
       *
       * @details
       * The interval is truncated to whole microseconds. Without both
       * readings (see `has_elapsed()`), the elapsed time is zero.
       *
       * @par Parameters
       *   None.
       * @return The elapsed time, in microseconds.
       */
      [[nodiscard]] std::chrono::microseconds
      elapsed (void) const noexcept;

    protected:
      /**
       * @brief Checks whether a clock reading was recorded.
       *
       * @details
       * A zero `timespec` means that the clock was not read, or that the
       * platform has no clock.
       *
       * @param ts The clock reading to check.
       * @retval true  At least one of the members is not zero.
       * @retval false Both members are zero.
       */
      [[nodiscard]] static bool
      is_recorded (const timespec& ts) noexcept;

      /**
       * @brief The clock reading at the start of the measured interval.
       *
       * @details
       * Zero until `start()` is called; set again by each `start()`.
       */
      timespec start_time_{};

      /**
       * @brief The clock reading at the end of the measured interval.
       *
       * @details
       * Zero until `stop()` is called; set again by each `stop()`, and
       * cleared by `start()`.
       */
      timespec stop_time_{};
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

#include "inlines/stopwatch-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_STOPWATCH_H_

// ----------------------------------------------------------------------------

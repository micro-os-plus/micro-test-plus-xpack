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
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace, ensuring clear
 * separation from user code and minimising the
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
#include <cstdint>
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
     * @brief Reads the system clock.
     *
     * @details
     * Isolates the platform-specific access to the system clock, used by
     * `stopwatch` and by the deprecated `timestamp` class. The clock is
     * monotonic on POSIX; without a clock, @p ts is left unchanged, so
     * the callers clear it first when a zero value must mean that the
     * clock was not read.
     *
     * @param[out] ts The `timespec` where the reading is stored.
     * @par Returns
     *   Nothing.
     */
    void
    read_clock (timespec& ts) noexcept;

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
     * The class is `final`; the non-public members are `private`, and
     * only the unit tests, through a friend, set known readings.
     *
     * The public members of the v5.0.1 `detail::timestamps` class
     * (`timestamp_begin()`, `timestamp_end()`, `has_begin()`, `has_end()`,
     * `has_timestamps()`, and `compute_elapsed_time()`) are kept,
     * deprecated, for the applications that used the deprecated
     * `timings()` of the runner and of the suites, which return a
     * reference to this class.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class stopwatch final
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

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
      /**
       * @brief Deprecated check of the start reading.
       *
       * @details
       * Kept from the v5.0.1 `detail::timestamps` class. The start
       * reading is available after `start()`, on a platform with a
       * clock; in v5.0.1, it was also reported without a clock.
       *
       * @par Parameters
       *   None.
       * @retval true  The start reading is available.
       * @retval false The start reading is absent.
       */
      [[deprecated ("use has_elapsed() (since 5.1.0)"), nodiscard]] bool
      has_begin (void) const noexcept;

      /**
       * @brief Deprecated check of the stop reading.
       *
       * @details
       * Kept from the v5.0.1 `detail::timestamps` class. The stop
       * reading is available after `stop()`, on a platform with a clock,
       * until the next `start()`; in v5.0.1, it was also reported
       * without a clock.
       *
       * @par Parameters
       *   None.
       * @retval true  The stop reading is available.
       * @retval false The stop reading is absent.
       */
      [[deprecated ("use has_elapsed() (since 5.1.0)"), nodiscard]] bool
      has_end (void) const noexcept;

      /**
       * @brief Deprecated name of `has_elapsed()`.
       *
       * @details
       * Kept from the v5.0.1 `detail::timestamps` class; calls
       * `has_elapsed()`.
       *
       * @par Parameters
       *   None.
       * @return The value returned by `has_elapsed()`.
       */
      [[deprecated ("use has_elapsed() (since 5.1.0)"), nodiscard]] bool
      has_timestamps (void) const noexcept;

      /**
       * @brief Deprecated split of the elapsed time.
       *
       * @details
       * Kept from the v5.0.1 `detail::timestamps` class. Splits the value
       * returned by `elapsed()` into whole milliseconds and the remaining
       * microseconds. Without both readings, both are zero; in v5.0.1,
       * the call was not allowed (it asserted).
       *
       * @param[out] milliseconds The whole milliseconds of the elapsed
       * time.
       * @param[out] microseconds The remaining microseconds, from 0 to
       * 999.
       * @par Returns
       *   Nothing.
       */
      [[deprecated ("use elapsed() (since 5.1.0)")]] void
      compute_elapsed_time (uint32_t& milliseconds,
                            uint32_t& microseconds) const noexcept;

      /**
       * @brief Deprecated recording of the start time, from the system
       * clock.
       *
       * @details
       * Kept from the v5.0.1 `detail::timestamps` class. Unlike
       * `start()`, it reads the clock only if the start reading is absent,
       * and it does not clear the stop reading. In v5.0.1, a reading taken
       * without a clock was also kept; here, the next call reads the clock
       * again.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      [[deprecated ("use start() (since 5.1.0)")]] void
      timestamp_begin (void) noexcept;

      /**
       * @brief Deprecated recording of a given start time.
       *
       * @details
       * Kept from the v5.0.1 `detail::timestamps` class. Stores @p ts as
       * the start reading, only if the start reading is absent; the stop
       * reading is not changed. A zero @p ts leaves the reading absent; in
       * v5.0.1, it was stored, and reported by `has_begin()`.
       *
       * @param ts The start time.
       * @par Returns
       *   Nothing.
       */
      [[deprecated ("use start() (since 5.1.0)")]] void
      timestamp_begin (const timespec& ts) noexcept;

      /**
       * @brief Deprecated recording of the stop time, from the system
       * clock.
       *
       * @details
       * Kept from the v5.0.1 `detail::timestamps` class. Unlike `stop()`,
       * it reads the clock only if the stop reading is absent, so the
       * elapsed time is measured to the first call, not to the last one.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      [[deprecated ("use stop() (since 5.1.0)")]] void
      timestamp_end (void) noexcept;

      /**
       * @brief Deprecated recording of a given stop time.
       *
       * @details
       * Kept from the v5.0.1 `detail::timestamps` class. Stores @p ts as
       * the stop reading, only if the stop reading is absent. A zero
       * @p ts leaves the reading absent; in v5.0.1, it was stored, and
       * reported by `has_end()`.
       *
       * @param ts The stop time.
       * @par Returns
       *   Nothing.
       */
      [[deprecated ("use stop() (since 5.1.0)")]] void
      timestamp_end (const timespec& ts) noexcept;
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    private:
      /**
       * @brief The unit tests helper, which sets known readings.
       *
       * @details
       * It is declared here, and defined by the unit tests only, so that
       * the tests can inject readings without deriving from the class.
       */
      friend struct stopwatch_test_access;

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

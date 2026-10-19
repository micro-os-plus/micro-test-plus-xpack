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

#include "unit-test.h"

#include <ctime>

using namespace micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------
// Helper subclass of stopwatch that allows injecting known clock readings,
// for deterministic testing without relying on the system clock.

class test_stopwatch : public detail::stopwatch
{
public:
  void
  set_times (const timespec& start, const timespec& stop) noexcept
  {
    start_time_ = start;
    stop_time_ = stop;
  }
};

// ----------------------------------------------------------------------------

static static_suite ts_stopwatch{ "Stopwatch suite", tr, [] (auto& ts)
  {
    const counters& current_suite_totals = ts.totals ();

    local_counts = {};

    // ------------------------------------------------------------------------

    ts.test ("stopwatch::start() and stop()", [] (auto& t)
      {
        detail::stopwatch sw{};

        // Freshly constructed: nothing recorded, no elapsed time.
        t.expect (!sw.has_elapsed ()) << "fresh: has_elapsed false";
        local_counts.passed_checks++;
        t.expect (eq (sw.elapsed ().count (), 0)) << "fresh: elapsed 0 µs";
        local_counts.passed_checks++;

        // Started only: the stop time is still absent.
        sw.start ();
        t.expect (!sw.has_elapsed ()) << "started only: has_elapsed false";
        local_counts.passed_checks++;

        // Stopped: both readings are available only on platforms with a
        // clock; without a clock, they remain zero.
        sw.stop ();
#if defined(_WIN32) || defined(CLOCK_MONOTONIC)
        constexpr bool has_clock = true;
#else
        constexpr bool has_clock = false;
#endif // defined(_WIN32) || defined(CLOCK_MONOTONIC)
        t.expect (eq (sw.has_elapsed (), has_clock))
            << "started and stopped: has_elapsed if clock";
        local_counts.passed_checks++;
        t.expect (ge (sw.elapsed ().count (), 0))
            << "started and stopped: elapsed >= 0 µs";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // ------------------------------------------------------------------------

    ts.test ("stopwatch::has_elapsed() state", [] (auto& t)
      {
        // Both readings present.
        test_stopwatch sw1{};
        sw1.set_times ({ 1, 0 }, { 2, 0 });
        t.expect (sw1.has_elapsed ()) << "both readings: has_elapsed true";
        local_counts.passed_checks++;

        // Zero start reading.
        test_stopwatch sw2{};
        sw2.set_times ({ 0, 0 }, { 1, 0 });
        t.expect (!sw2.has_elapsed ()) << "zero start: has_elapsed false";
        local_counts.passed_checks++;

        // Zero stop reading.
        test_stopwatch sw3{};
        sw3.set_times ({ 1, 0 }, { 0, 0 });
        t.expect (!sw3.has_elapsed ()) << "zero stop: has_elapsed false";
        local_counts.passed_checks++;

        // tv_sec==0 but tv_nsec!=0: the nsec branch of the || is exercised.
        test_stopwatch sw4{};
        sw4.set_times ({ 0, 1 }, { 0, 2 });
        t.expect (sw4.has_elapsed ())
            << "tv_sec==0, tv_nsec!=0: has_elapsed true";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // ------------------------------------------------------------------------

    ts.test ("stopwatch::start() idempotency", [] (auto& t)
      {
        // Pre-set the readings with known values, then call start() again.
        // The second call must be a no-op, leaving the start unchanged.
        test_stopwatch sw{};
        sw.set_times ({ 1, 0 }, { 2, 0 });

        sw.start (); // must not overwrite the pre-set start time

        t.expect (eq (sw.elapsed ().count (), 1000000))
            << "second start ignored: 1000000 µs";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // ------------------------------------------------------------------------

    ts.test ("stopwatch::stop() idempotency", [] (auto& t)
      {
        // Pre-set the readings with known values, then call stop() again.
        // The second call must be a no-op, leaving the stop unchanged.
        test_stopwatch sw{};
        sw.set_times ({ 1, 0 }, { 2, 0 });

        sw.stop (); // must not overwrite the pre-set stop time

        t.expect (eq (sw.elapsed ().count (), 1000000))
            << "second stop ignored: 1000000 µs";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // ------------------------------------------------------------------------

    ts.test ("stopwatch::elapsed()", [] (auto& t)
      {
        // Whole seconds: 1 s -> 1000000 µs.
        test_stopwatch sw1;
        sw1.set_times ({ 1, 0 }, { 2, 0 });
        t.expect (eq (sw1.elapsed ().count (), 1000000))
            << "1 s -> 1000000 µs";
        local_counts.passed_checks++;

        // Sub-second: 500 ms -> 500000 µs.
        test_stopwatch sw2;
        sw2.set_times ({ 1, 0 }, { 1, 500000000 });
        t.expect (eq (sw2.elapsed ().count (), 500000))
            << "500 ms -> 500000 µs";
        local_counts.passed_checks++;

        // Fractional: 2.5 ms -> 2500 µs.
        test_stopwatch sw3;
        sw3.set_times ({ 1, 0 }, { 1, 2500000 });
        t.expect (eq (sw3.elapsed ().count (), 2500)) << "2.5 ms -> 2500 µs";
        local_counts.passed_checks++;

        // Nanosecond borrow: end nsec < begin nsec.
        test_stopwatch sw4;
        sw4.set_times ({ 1, 500000000 }, { 2, 100000000 });
        t.expect (eq (sw4.elapsed ().count (), 600000))
            << "ns borrow -> 600000 µs";
        local_counts.passed_checks++;

        // Truncation to whole microseconds.
        test_stopwatch sw5;
        sw5.set_times ({ 1, 0 }, { 1, 1999 });
        t.expect (eq (sw5.elapsed ().count (), 1)) << "1999 ns -> 1 µs";
        local_counts.passed_checks++;

        // Zero elapsed.
        test_stopwatch sw6;
        sw6.set_times ({ 1, 0 }, { 1, 0 });
        t.expect (eq (sw6.elapsed ().count (), 0)) << "zero elapsed -> 0 µs";
        local_counts.passed_checks++;

        // Without both readings, the elapsed time is zero.
        test_stopwatch sw7;
        sw7.set_times ({ 1, 0 }, { 0, 0 });
        t.expect (eq (sw7.elapsed ().count (), 0)) << "no stop -> 0 µs";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // ------------------------------------------------------------------------
  } };

// ----------------------------------------------------------------------------

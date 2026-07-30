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

#include <cstdint>

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
// Helper subclass of timestamp that allows zeroing the stored value, enabling
// deterministic testing of has_clock() without relying on the system clock.

class test_timestamp : public detail::timestamp
{
public:
  void
  zero () noexcept
  {
    value_ = {};
  }

  void
  set (const timespec& ts) noexcept
  {
    value_ = ts;
  }
};

// ----------------------------------------------------------------------------
// Helper subclass of timestamps that allows injecting known timespec values
// and inspecting internal state for deterministic unit testing.

class test_timestamps : public detail::timestamps
{
public:
  void
  set_times (const timespec& begin, const timespec& end) noexcept
  {
    begin_time_.emplace ();
    begin_time_->value () = begin;
    end_time_.emplace ();
    end_time_->value () = end;
  }
};

// ----------------------------------------------------------------------------

static static_suite ts_timings{ "Timings suite", tr, [] (auto& ts)
  {
    detail::runner_totals& current_suite_totals = ts.totals ();

    local_counts = {};

    // ------------------------------------------------------------------------

    ts.test ("timestamp::has_clock()", [] (auto& t)
      {
#if defined(_WIN32) || defined(CLOCK_MONOTONIC)
        // Default constructor captures the real clock — has_clock() is true.
        detail::timestamp ts_real{};
#else
        // On platforms without a real clock, set a non-zero time to make
        // has_clock() true.
        detail::timestamp ts_real{ { 1, 2 } };
#endif // defined(_WIN32) || defined(CLOCK_MONOTONIC)
        t.expect (ts_real.has_clock ()) << "default ctor -> has_clock true";
        local_counts.successful_checks++;

        // Zeroing the stored value makes has_clock() return false.
        test_timestamp ts_zero{};
        ts_zero.zero ();
        t.expect (!ts_zero.has_clock ()) << "zeroed value -> has_clock false";
        local_counts.successful_checks++;

        // tv_sec==0 but tv_nsec!=0 — the nsec branch of the || is exercised.
        test_timestamp ts_nsec_only{};
        ts_nsec_only.set ({ 0, 1 });
        t.expect (ts_nsec_only.has_clock ())
            << "tv_sec==0, tv_nsec==1 -> has_clock true";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------

    ts.test ("timestamp copy semantics", [] (auto& t)
      {
#if defined(_WIN32) || defined(CLOCK_MONOTONIC)
        detail::timestamp t1{};
#else
        detail::timestamp t1{ { 1, 2 } };
#endif // defined(_WIN32) || defined(CLOCK_MONOTONIC)

        // Copy constructor produces an identical timespec.
        detail::timestamp t2{ t1 };
        t.expect (eq (t2.value ().tv_sec, t1.value ().tv_sec))
            << "copy ctor: tv_sec matches";
        local_counts.successful_checks++;
        t.expect (eq (t2.value ().tv_nsec, t1.value ().tv_nsec))
            << "copy ctor: tv_nsec matches";
        local_counts.successful_checks++;

        // Copy assignment produces an identical timespec.
        detail::timestamp t3{};
        t3 = t1;
        t.expect (eq (t3.value ().tv_sec, t1.value ().tv_sec))
            << "copy assign: tv_sec matches";
        local_counts.successful_checks++;
        t.expect (eq (t3.value ().tv_nsec, t1.value ().tv_nsec))
            << "copy assign: tv_nsec matches";
        local_counts.successful_checks++;

        // const value() accessor is accessible.
        const detail::timestamp& ct = t1;
        t.expect (eq (ct.value ().tv_sec, t1.value ().tv_sec))
            << "const value() accessor";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------

    ts.test ("timestamps::has_timestamps() state", [] (auto& t)
      {
        test_timestamps tts{};

        // Freshly constructed: no optionals set, no timestamps.
        t.expect (!tts.has_timestamps ()) << "fresh: has_timestamps false";
        local_counts.successful_checks++;

        // After timestamp_begin() only: begin is set, end is not.
        tts.timestamp_begin ({ 1, 0 });
        t.expect (!tts.has_timestamps ())
            << "after begin only: has_timestamps false";
        local_counts.successful_checks++;

        // After timestamp_end() too: both are set and real clock is present.
        tts.timestamp_end ({ 2, 0 });
        t.expect (tts.has_timestamps ()) << "after both: has_timestamps true";
        local_counts.successful_checks++;

        // begin set but clock zeroed: has_timestamps must be false.
        // set_times({0,0},{1,0}) — begin tv_sec=0, tv_nsec=0 => zeroed clock.
        test_timestamps tts3{};
        tts3.set_times ({ 0, 0 }, { 1, 0 });
        t.expect (!tts3.has_timestamps ())
            << "zeroed begin, real end: has_timestamps false";
        local_counts.successful_checks++;

        // Both set but end clock zeroed: has_timestamps must be false.
        // set_times({1,0},{0,0}) — end tv_sec=0, tv_nsec=0 => zeroed clock.
        test_timestamps tts4{};
        tts4.set_times ({ 1, 0 }, { 0, 0 });
        t.expect (!tts4.has_timestamps ())
            << "real begin, zeroed end: has_timestamps false";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------

    ts.test ("timestamps::timestamp_begin() idempotency", [] (auto& t)
      {
        // Pre-set times with known values, then call timestamp_begin()
        // again. The second call must be a no-op, leaving the stored begin
        // unchanged.
        test_timestamps tts{};
        tts.set_times ({ 1, 0 }, { 2, 0 });

        tts.timestamp_begin (); // must not overwrite the pre-set begin time

        uint32_t ms{};
        uint32_t us{};
        tts.compute_elapsed_time (ms, us);
        t.expect (eq (ms, 1000u)) << "second begin ignored: ms unchanged";
        local_counts.successful_checks++;
        t.expect (eq (us, 0u)) << "second begin ignored: us unchanged";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------

    ts.test ("timestamps::timestamp_end() idempotency", [] (auto& t)
      {
        // Pre-set times with known values, then call timestamp_end() again.
        // The second call must be a no-op, leaving the stored end unchanged.
        test_timestamps tts{};
        tts.set_times ({ 1, 0 }, { 2, 0 });

        tts.timestamp_end (); // must not overwrite the pre-set end time

        uint32_t ms{};
        uint32_t us{};
        tts.compute_elapsed_time (ms, us);
        t.expect (eq (ms, 1000u)) << "second end ignored: ms unchanged";
        local_counts.successful_checks++;
        t.expect (eq (us, 0u)) << "second end ignored: us unchanged";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------

    ts.test ("timestamps::compute_elapsed_time()", [] (auto& t)
      {
        uint32_t ms{};
        uint32_t us{};

        // Whole seconds: 1 s -> 1000 ms, 0 µs.
        test_timestamps tt1;
        tt1.set_times ({ 1, 0 }, { 2, 0 });
        tt1.compute_elapsed_time (ms, us);
        t.expect (eq (ms, 1000u)) << "1 s -> 1000 ms";
        local_counts.successful_checks++;
        t.expect (eq (us, 0u)) << "1 s -> 0 µs";
        local_counts.successful_checks++;

        // Sub-second: 500 ms -> 500 ms, 0 µs.
        test_timestamps tt2;
        tt2.set_times ({ 1, 0 }, { 1, 500000000 });
        tt2.compute_elapsed_time (ms, us);
        t.expect (eq (ms, 500u)) << "500 ms -> 500 ms";
        local_counts.successful_checks++;
        t.expect (eq (us, 0u)) << "500 ms -> 0 µs";
        local_counts.successful_checks++;

        // Fractional: 2.5 ms -> 2 ms, 500 µs.
        test_timestamps tt3;
        tt3.set_times ({ 1, 0 }, { 1, 2500000 });
        tt3.compute_elapsed_time (ms, us);
        t.expect (eq (ms, 2u)) << "2.5 ms -> 2 ms";
        local_counts.successful_checks++;
        t.expect (eq (us, 500u)) << "2.5 ms -> 500 µs";
        local_counts.successful_checks++;

        // Nanosecond borrow: end nsec < begin nsec.
        test_timestamps tt4;
        tt4.set_times ({ 1, 500000000 }, { 2, 100000000 });
        tt4.compute_elapsed_time (ms, us);
        t.expect (eq (ms, 600u)) << "ns borrow -> 600 ms";
        local_counts.successful_checks++;
        t.expect (eq (us, 0u)) << "ns borrow -> 0 µs";
        local_counts.successful_checks++;

        // Zero elapsed.
        test_timestamps tt5;
        tt5.set_times ({ 1, 0 }, { 1, 0 });
        tt5.compute_elapsed_time (ms, us);
        t.expect (eq (ms, 0u)) << "zero elapsed -> 0 ms";
        local_counts.successful_checks++;
        t.expect (eq (us, 0u)) << "zero elapsed -> 0 µs";
        local_counts.successful_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------
  } };

// ----------------------------------------------------------------------------

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

// The deprecated features, kept for compatibility with the previous
// releases, are all checked here, and only here, so that the other files
// use only the current API, and the whole file can be removed when the
// deprecated features are removed.
//
// The checks that need a runner use local, silent runners, so that they
// do not write to the test output.

#include "unit-test.h"

#include <cstdint>
#include <ctime>
#include <string_view>
#include <type_traits>
#include <utility>

using namespace std::literals;
using namespace micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

// Suite functions with a `static_suite&` first parameter, as in v5.0.1.

static bool static_suite_function_ran = false;

static void
static_suite_function (static_suite& ss)
{
  static_suite_function_ran = true;
  ss.test ("Local test", [] (auto& lt) { lt.expect (true); });
}

// The arguments are copies, as in v5.0.1: a reference parameter refers to
// the copy, not to the caller's object.
static void
static_suite_function_with_arguments (static_suite& ss, int value, int& copy,
                                      int* out)
{
  copy = value + 1;
  *out = copy;
  ss.test ("Local test", [] (auto& lt) { lt.expect (true); });
}

// ----------------------------------------------------------------------------

namespace
{
  // A stopwatch with known readings, for the deprecated members kept
  // from the v5.0.1 `detail::timestamps`.
  class known_stopwatch : public detail::stopwatch
  {
  public:
    void
    set_times (const timespec& start, const timespec& stop) noexcept
    {
      start_time_ = start;
      stop_time_ = stop;
    }
  };
} // namespace

// Without a clock, the readings remain zero.
#if defined(_WIN32) || defined(CLOCK_MONOTONIC)
static constexpr bool has_clock = true;
#else
static constexpr bool has_clock = false;
#endif // defined(_WIN32) || defined(CLOCK_MONOTONIC)

// ----------------------------------------------------------------------------

static static_suite ts_deprecated{ "Deprecated suite", tr, [] (auto& ts)
  {
    const counters& current_suite_totals = ts.totals ();

    local_counts = {};

    // ------------------------------------------------------------------------

    // The name given to the deprecated constructor is used when
    // `initialise()` does not get one, and is replaced when it does.
    ts.test ("runner (const char*)", [] (auto& t)
      {
        runner_options options{};
        options.verbosity_level = verbosity::silent;

        runner named_runner{ "Constructor name" };
        auto& named_ts = named_runner.initialise (options);

        t.expect (eq (named_ts.name (), "Constructor name"))
            << "name given to the constructor";
        local_counts.passed_checks++;

        runner overridden_runner{ "Constructor name" };
        auto& overridden_ts
            = overridden_runner.initialise (options, "Initialise name");

        t.expect (eq (overridden_ts.name (), "Initialise name"))
            << "name given to initialise() replaces it";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated `static_runner` is an alias of `runner`.
    ts.test ("static_runner", [] (auto& t)
      {
        static_assert (std::is_same_v<static_runner, runner>,
                       "static_runner is an alias of runner");

        runner_options options{};
        options.verbosity_level = verbosity::silent;

        static_runner local_runner;
        auto& local_ts = local_runner.initialise (options, "Static runner");
        local_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (local_runner.run (), 0)) << "static_runner session";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated `exit_code()` runs the session, as `run()` does; the
    // later calls return the same code without running the suites again.
    ts.test ("runner::exit_code()", [] (auto& t)
      {
        runner_options options{};
        options.verbosity_level = verbosity::silent;

        runner passed_runner;
        auto& passed_ts = passed_runner.initialise (options, "Passed");
        passed_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (passed_runner.exit_code (), 0)) << "passed session";
        local_counts.passed_checks++;

        t.expect (eq (passed_runner.exit_code (), 0)
                  and eq (passed_runner.run (), 0)
                  and eq (passed_runner.totals ().executed_test_cases (), 1u))
            << "later calls do not run the suites again";
        local_counts.passed_checks++;

        runner failed_runner;
        auto& failed_ts = failed_runner.initialise (options, "Failed");
        failed_ts.test ("Local test", [] (auto& lt) { lt.expect (false); });

        t.expect (eq (failed_runner.exit_code (), 1)) << "failed session";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated names of `add_suite()`, `verbosity_level()`, and
    // `added_suites_count()`; `suites_count()` also counts the top suite.
    ts.test ("runner::suite()", [] (auto& t)
      {
        runner_options options{};
        options.verbosity_level = verbosity::silent;

        runner local_runner;
        auto& local_ts = local_runner.initialise (options, "Local");

        t.expect (local_runner.verbosity () == verbosity::silent)
            << "verbosity()";
        local_counts.passed_checks++;

        bool suite_ran = false;
        local_runner.suite ("Deprecated", [&suite_ran] (suite& s)
          {
            suite_ran = true;
            s.test ("Deprecated test", [] (auto& lt) { lt.expect (true); });
          });

        local_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (local_runner.suites_count (), 2u)
                  and eq (local_runner.suites_count (),
                          local_runner.added_suites_count () + 1))
            << "suites_count() counts the top suite";
        local_counts.passed_checks++;

        t.expect (eq (local_runner.run (), 0)) << "local session passed";
        local_counts.passed_checks++;

        t.expect (suite_ran) << "suite() added the suite";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The suite functions with a `static_suite&` first parameter select
    // the deprecated constructor, and receive the suite and the arguments.
    ts.test ("static_suite& suite functions", [] (auto& t)
      {
        static_assert (
            detail::static_suite_body<decltype (static_suite_function)&>,
            "a static_suite& function selects the deprecated constructor");
        static_assert (!detail::static_suite_body<void (&) (suite&)>,
                       "a suite& function selects the current constructor");

        runner_options options{};
        options.verbosity_level = verbosity::silent;

        runner local_runner;
        local_runner.initialise (options, "Local");

        static_suite_function_ran = false;
        int original = 0;
        int out = 0;
        {
          static_suite without_arguments{ "Without arguments", local_runner,
                                          static_suite_function };
          static_suite with_arguments{ "With arguments",
                                       local_runner,
                                       static_suite_function_with_arguments,
                                       42,
                                       original,
                                       &out };

          t.expect (eq (local_runner.run (), 0)) << "local session passed";
          local_counts.passed_checks++;
        }

        t.expect (static_suite_function_ran) << "function without arguments";
        local_counts.passed_checks++;

        t.expect (eq (out, 43) and eq (original, 0))
            << "function with arguments, which are copies";
        local_counts.passed_checks++;

        t.expect (eq (local_runner.totals ().executed_test_cases (), 2u))
            << "the test cases of both suites ran";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated names of `passed_checks()`,
    // `increment_passed_checks()`, `executed_test_cases()`,
    // `increment_executed_test_cases()`, and `passed()`.
    ts.test ("counters", [] (auto& t)
      {
        counters local_counters{};
        local_counters.increment_passed_checks (3);

        t.expect (eq (local_counters.successful_checks (), 3u))
            << "successful_checks()";
        local_counts.passed_checks++;

        local_counters.increment_successful_checks (2);

        t.expect (eq (local_counters.passed_checks (), 5u))
            << "increment_successful_checks()";
        local_counts.passed_checks++;

        local_counters.increment_executed_test_cases (3);

        t.expect (eq (local_counters.executed_subtests (), 3u))
            << "executed_subtests()";
        local_counts.passed_checks++;

        local_counters.increment_executed_subtests (2);

        t.expect (eq (local_counters.executed_test_cases (), 5u))
            << "increment_executed_subtests()";
        local_counts.passed_checks++;

        t.expect (local_counters.was_successful ())
            << "was_successful() without failures";
        local_counts.passed_checks++;

        local_counters.increment_failed_checks ();

        t.expect (!local_counters.was_successful ()
                  and !local_counters.passed ())
            << "was_successful() with a failed check";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The v5.0.1 non-`const` reference to the totals of a node, with the
    // deprecated class name; the modifications reach the live totals, and
    // decide the exit code, as in v5.0.1.
    ts.test ("non-const totals(), detail::runner_totals", [] (auto& t)
      {
        static_assert (std::is_same_v<detail::runner_totals, counters>,
                       "runner_totals is an alias of counters");
        static_assert (std::is_same_v<decltype (t.totals ()), counters&>,
                       "the non-const totals() returns a reference");
        static_assert (std::is_same_v<decltype (std::as_const (t).totals ()),
                                      const counters&>,
                       "the const totals() returns a const reference");

        runner_options options{};
        options.verbosity_level = verbosity::silent;

        runner local_runner;
        auto& local_ts = local_runner.initialise (options, "Local");
        local_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        // The v5.0.1 binding.
        detail::runner_totals& local_totals = local_ts.totals ();

        t.expect (&local_totals == &std::as_const (local_ts).totals ()
                  and eq (local_totals.passed_checks (), 1u)
                  and eq (local_totals.executed_test_cases (), 1u))
            << "runner_totals& refers to the live totals";
        local_counts.passed_checks++;

        // The modifications through the v5.0.1 reference.
        local_totals.increment_passed_checks (2);
        local_totals.increment_executed_test_cases ();

        t.expect (eq (local_ts.totals ().passed_checks (), 3u)
                  and eq (local_ts.totals ().executed_test_cases (), 2u)
                  and local_ts.totals ().passed ())
            << "runner_totals& modifies the live totals";
        local_counts.passed_checks++;

        local_totals.increment_failed_checks ();

        t.expect (eq (local_runner.run (), 1)
                  and eq (local_runner.totals ().failed_checks (), 1u))
            << "a failed check added to the totals fails the session";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The v5.0.1 timings of the session and of the suites, with the
    // deprecated class name; they refer to the stopwatches shown by the
    // reporters, started and stopped by the runner.
    ts.test ("timings(), detail::timestamps", [] (auto& t)
      {
        static_assert (std::is_same_v<detail::timestamps, detail::stopwatch>,
                       "timestamps is an alias of stopwatch");
        static_assert (
            std::is_same_v<decltype (std::declval<runner&> ().timings ()),
                           detail::stopwatch&>,
            "the non-const runner::timings() returns a reference");
        static_assert (std::is_same_v<decltype (std::declval<const runner&> ()
                                                    .timings ()),
                                      const detail::stopwatch&>,
                       "the const runner::timings() returns a const "
                       "reference");
        static_assert (
            std::is_same_v<decltype (std::declval<suite&> ().timings ()),
                           detail::stopwatch&>,
            "the non-const suite::timings() returns a reference");
        static_assert (
            std::is_same_v<decltype (std::declval<const suite&> ().timings ()),
                           const detail::stopwatch&>,
            "the const suite::timings() returns a const "
            "reference");

        runner_options options{};
        options.verbosity_level = verbosity::silent;

        runner local_runner;
        auto& local_ts = local_runner.initialise (options, "Local");
        local_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        const detail::stopwatch* added_timings = nullptr;
        bool added_started = false;
        local_runner.add_suite ("Added", [&] (suite& s)
          {
            // The v5.0.1 binding.
            detail::timestamps& timings = s.timings ();
            added_timings = &timings;
            added_started
                = (timings.has_begin () == has_clock) && !timings.has_end ();
            s.test ("Added test", [] (auto& lt) { lt.expect (true); });
          });

        // The v5.0.1 bindings.
        detail::timestamps& session_timings = local_runner.timings ();
        const detail::timestamps& top_timings
            = std::as_const (local_ts).timings ();

        t.expect (&session_timings == &std::as_const (local_runner).timings ()
                  and &top_timings == &local_ts.timings ())
            << "both overloads refer to the same timings";
        local_counts.passed_checks++;

        t.expect (eq (session_timings.has_begin (), has_clock)
                  and !session_timings.has_end ()
                  and !session_timings.has_timestamps ()
                  and eq (top_timings.has_begin (), has_clock)
                  and !top_timings.has_end ()
                  and !top_timings.has_timestamps ())
            << "the timings are started by initialise()";
        local_counts.passed_checks++;

        t.expect (eq (local_runner.run (), 0)) << "local session passed";
        local_counts.passed_checks++;

        t.expect (added_started) << "the suite timings are started";
        local_counts.passed_checks++;

        t.expect (eq (session_timings.has_timestamps (), has_clock)
                  and eq (session_timings.has_end (), has_clock)
                  and eq (top_timings.has_timestamps (), has_clock)
                  and added_timings != nullptr
                  and eq (added_timings->has_timestamps (), has_clock))
            << "the timings are stopped by run()";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated members kept from the v5.0.1 `detail::timestamps`,
    // with known readings.
    ts.test ("timestamps::compute_elapsed_time()", [] (auto& t)
      {
        known_stopwatch sw{};
        uint32_t milliseconds = 1;
        uint32_t microseconds = 1;

        sw.compute_elapsed_time (milliseconds, microseconds);

        t.expect (!sw.has_begin () and !sw.has_end () and !sw.has_timestamps ()
                  and eq (milliseconds, 0u) and eq (microseconds, 0u))
            << "no readings, zero elapsed time";
        local_counts.passed_checks++;

        sw.set_times ({ 1, 0 }, { 0, 0 });

        t.expect (sw.has_begin () and !sw.has_end () and !sw.has_timestamps ())
            << "start reading only";
        local_counts.passed_checks++;

        // 1.001235 seconds, with a borrow from the seconds.
        sw.set_times ({ 1, 999'999'000 }, { 3, 1'234'000 });
        sw.compute_elapsed_time (milliseconds, microseconds);

        t.expect (sw.has_begin () and sw.has_end () and sw.has_timestamps ()
                  and eq (milliseconds, 1001u) and eq (microseconds, 235u))
            << "both readings, elapsed time split";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated name of `require()`.
    ts.test ("assume()", [] (auto& t)
      {
        t.assume (true) << "passed assumption";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

#if defined(__cpp_exceptions)
    // As a failed `require()`, a failed `assume()` stops the test case;
    // without exceptions, it aborts the test execution.
    ts.test ("Failed assume()", [] (auto& t)
      {
        // Counted before, since the statement does not return.
        local_counts.failed_checks++;
        t.assume (false) << "failed assumption";

        t.expect (false) << "check after the assumption";
      });
    local_counts.executed_test_cases++;
#endif // defined(__cpp_exceptions)

    // The deprecated name of `utility::extract_file_name()`.
    ts.test ("reflection::short_name()", [] (auto& t)
      {
        // Path with slash — returns filename component.
        t.expect (eq (
            std::string_view{ reflection::short_name ("/some/path/file.cpp") },
            "file.cpp"sv));
        local_counts.passed_checks++;

        // Path without slash — returns original.
        t.expect (eq (std::string_view{ reflection::short_name ("file.cpp") },
                      "file.cpp"sv));
        local_counts.passed_checks++;

        // Windows-style path — returns filename component, as
        // utility::extract_file_name() does.
        t.expect (eq (std::string_view{ reflection::short_name (
                          "C:\\some\\path\\file.cpp") },
                      "file.cpp"sv));
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated names of `both()`, `either()`, and `negate()`; they
    // return the same expressions, so they are reported in the same way.
    ts.test ("_and(), _or(), _not()", [] (auto& t)
      {
        static_assert (std::is_same_v<decltype (_and (eq (1, 1), eq (2, 2))),
                                      decltype (both (eq (1, 1), eq (2, 2)))>,
                       "_and() returns the same expression as both()");
        static_assert (
            std::is_same_v<decltype (_or (eq (1, 1), eq (2, 2))),
                           decltype (either (eq (1, 1), eq (2, 2)))>,
            "_or() returns the same expression as either()");
        static_assert (std::is_same_v<decltype (_not (eq (1, 1))),
                                      decltype (negate (eq (1, 1)))>,
                       "_not() returns the same expression as negate()");

        int one = 1;

        t.expect (_and (eq (one, 1), ne (one, 2)));
        local_counts.passed_checks++;

        t.expect (_or (eq (one, 2), eq (one, 1)));
        local_counts.passed_checks++;

        t.expect (_not (eq (one, 2)));
        local_counts.passed_checks++;

        t.expect (!_and (eq (one, 1), eq (one, 2))
                  and !_or (eq (one, 2), eq (one, 3)) and !_not (eq (one, 1)))
            << "false results";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated names of the `to_*` wrappers and of `to_t<T>`; they
    // are the same types, so they are compared and reported in the same
    // way.
    ts.test ("_i, _f, ..., _t<T>", [] (auto& t)
      {
        static_assert (std::is_same_v<_b, to_b>);
        static_assert (std::is_same_v<_c, to_c>);
        static_assert (std::is_same_v<_sc, to_sc>);
        static_assert (std::is_same_v<_s, to_s>);
        static_assert (std::is_same_v<_i, to_i>);
        static_assert (std::is_same_v<_l, to_l>);
        static_assert (std::is_same_v<_ll, to_ll>);
        static_assert (std::is_same_v<_u, to_u>);
        static_assert (std::is_same_v<_uc, to_uc>);
        static_assert (std::is_same_v<_us, to_us>);
        static_assert (std::is_same_v<_ul, to_ul>);
        static_assert (std::is_same_v<_ull, to_ull>);
        static_assert (std::is_same_v<_i8, to_i8>);
        static_assert (std::is_same_v<_i16, to_i16>);
        static_assert (std::is_same_v<_i32, to_i32>);
        static_assert (std::is_same_v<_i64, to_i64>);
        static_assert (std::is_same_v<_u8, to_u8>);
        static_assert (std::is_same_v<_u16, to_u16>);
        static_assert (std::is_same_v<_u32, to_u32>);
        static_assert (std::is_same_v<_u64, to_u64>);
        static_assert (std::is_same_v<_f, to_f>);
        static_assert (std::is_same_v<_d, to_d>);
        static_assert (std::is_same_v<_ld, to_ld>);
        static_assert (std::is_same_v<_t<int>, to_t<int>>);

        int one = 1;
        double half = 0.5;

        // The v5.0.1 functional cast notation.
        t.expect (eq (_i (one), 1));
        local_counts.passed_checks++;

        t.expect (eq (_d (half), 0.5));
        local_counts.passed_checks++;

        t.expect (eq (_t<int>{ one }, 1));
        local_counts.passed_checks++;

        t.expect (!eq (_i (one), 2) and !eq (_t<int>{ one }, 2))
            << "false results";
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

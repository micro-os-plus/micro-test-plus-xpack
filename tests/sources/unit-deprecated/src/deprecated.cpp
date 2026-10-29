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

#include "unit-deprecated-test.h"

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
#pragma GCC diagnostic ignored "-Wfloat-equal"
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

// A test case function with a `subtest&` parameter, as in v5.0.1.
static void
subtest_function (subtest& t)
{
  t.expect (true);
}

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus::detail
{
  // Sets known readings of a stopwatch, which the v5.0.1 tests did by
  // deriving from the class.
  struct stopwatch_test_access
  {
    static void
    set_times (stopwatch& sw, const timespec& start,
               const timespec& stop) noexcept
    {
      sw.start_time_ = start;
      sw.stop_time_ = stop;
    }
  };
} // namespace micro_os_plus::micro_test_plus::detail

namespace
{
  // A timestamp with a known value, set through the protected member, as
  // the v5.0.1 unit tests did.
  class known_timestamp : public detail::timestamp
  {
  public:
    void
    set (const timespec& ts) noexcept
    {
      value_ = ts;
    }
  };

  // A type with a non-static member named `value`, which satisfied the
  // v5.0.1 `type_traits::has_value`.
  struct with_value_member
  {
    int value;
  };

  // Mock functions that simulate code computing integers and floats.
  template <typename T = int>
  T
  my_actual_integral ()
  {
    return 42;
  }

  template <typename T = int>
  T
  my_actual_integral_less ()
  {
    return 41;
  }

  template <typename T = int>
  T
  my_actual_integral_more ()
  {
    return 43;
  }

  template <typename T>
  T
  my_actual_float ()
  {
    return 42.0;
  }

  // A comparator, a predicate, and an operator of the application, as the
  // applications built them with the literals and the wrappers.
  struct divides_tag
  {
    static constexpr const char* symbol = " divides ";

    template <class Lhs_T, class Rhs_T>
    static constexpr bool
    apply (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return rhs % lhs == 0;
    }
  };

  struct even_tag
  {
    static constexpr const char* symbol = "even ";

    template <class T>
    static constexpr bool
    apply (const T& t)
    {
      return t % 2 == 0;
    }
  };

  template <class Lhs_T, class Rhs_T>
  constexpr auto
  divides (const Lhs_T& lhs, const Rhs_T& rhs)
  {
    return extension::compare_op{ lhs, rhs, divides_tag{} };
  }

  template <class T>
  constexpr auto
  even (const T& t)
  {
    return extension::predicate_op{ t, even_tag{} };
  }

  namespace custom_operators
  {
    // `a | b` reads "a divides b"; enabled only when an operand is a
    // framework type, as the operators of the framework are.
    template <class Lhs_T, class Rhs_T>
      requires extension::any_op<Lhs_T, Rhs_T>
    constexpr auto
    operator| (const Lhs_T& lhs, const Rhs_T& rhs)
    {
      return extension::compare_op{ lhs, rhs, divides_tag{} };
    }
  } // namespace custom_operators

  // A user-defined type that counts its copies.
  int counted_copies = 0;

  struct counted
  {
    explicit counted (int v) : number{ v }
    {
    }

    counted (const counted& other) : number{ other.number }
    {
      ++counted_copies;
    }

    counted&
    operator= (const counted& other)
    {
      number = other.number;
      ++counted_copies;
      return *this;
    }

    int number;
  };

  constexpr bool
  operator== (const counted& lhs, const counted& rhs)
  {
    return lhs.number == rhs.number;
  }

  expression_formatter&
  operator<< (expression_formatter& formatter, const counted& c)
  {
    return formatter << c.number;
  }
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
    // `add_top_suite()` does not get one, and is replaced when it does.
    ts.test ("runner (const char*)", [] (auto& t)
      {
        runner_options options{};
        options.verbosity_level = verbosity::silent;

        runner named_runner{ "Constructor name" };
        named_runner.initialise (options);
        auto& named_ts = named_runner.add_top_suite ();

        t.expect (eq (named_ts.name (), "Constructor name"))
            << "name given to the constructor";
        local_counts.passed_checks++;

        runner overridden_runner{ "Constructor name" };
        overridden_runner.initialise (options);
        auto& overridden_ts = overridden_runner.add_top_suite ("Top name");

        t.expect (eq (overridden_ts.name (), "Top name"))
            << "name given to add_top_suite() replaces it";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated `initialise()` with the command line and the name
    // also adds the top suite, and returns it.
    ts.test ("initialise (argc, argv, name)", [] (auto& t)
      {
        char arg_name[] = "local.elf";
        char arg_silent[] = "--silent";
        char* local_argv[] = { arg_name, arg_silent, nullptr };

        runner local_runner;
        auto& local_ts = local_runner.initialise (2, local_argv, "Local");
        local_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (local_ts.name (), "Local")
                  and local_runner.verbosity_level () == verbosity::silent)
            << "the options are parsed and the top suite is added";
        local_counts.passed_checks++;

        t.expect (eq (local_runner.total_suites_count (), 1u))
            << "the top suite is counted";
        local_counts.passed_checks++;

        t.expect (&local_runner.initialise (2, local_argv, "Other")
                  == &local_ts)
            << "a second call returns the same top suite";
        local_counts.passed_checks++;

        t.expect (eq (local_runner.run_suites (), 0)) << "the session passes";
        local_counts.passed_checks++;

        runner unnamed_runner;
        auto& unnamed_ts = unnamed_runner.initialise (2, local_argv, "");

        t.expect (eq (unnamed_ts.name (), "local"))
            << "the top suite is named after argv[0]";
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
        local_runner.initialise (options);
        auto& local_ts = local_runner.add_top_suite ("Static runner");
        local_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (local_runner.run_suites (), 0))
            << "static_runner session";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated `exit_code()` runs the session, as `run_suites()` does;
    // the later calls return the same code without running the suites again.
    ts.test ("runner::exit_code()", [] (auto& t)
      {
        runner_options options{};
        options.verbosity_level = verbosity::silent;

        runner passed_runner;
        passed_runner.initialise (options);
        auto& passed_ts = passed_runner.add_top_suite ("Passed");
        passed_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (passed_runner.exit_code (), 0)) << "passed session";
        local_counts.passed_checks++;

        t.expect (eq (passed_runner.exit_code (), 0)
                  and eq (passed_runner.run_suites (), 0)
                  and eq (passed_runner.totals ().executed_test_cases (), 1u))
            << "later calls do not run the suites again";
        local_counts.passed_checks++;

        runner failed_runner;
        failed_runner.initialise (options);
        auto& failed_ts = failed_runner.add_top_suite ("Failed");
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
        local_runner.initialise (options);
        auto& local_ts = local_runner.add_top_suite ("Local");

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

        t.expect (eq (local_runner.run_suites (), 0))
            << "local session passed";
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
        local_runner.initialise (options);
        local_runner.add_top_suite ("Local");

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

          t.expect (eq (local_runner.run_suites (), 0))
              << "local session passed";
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

    // The deprecated `subtest` is an alias of `test_case`, so the
    // functions and the lambdas with a `subtest&` parameter are test case
    // bodies, in suites and in test cases.
    ts.test ("subtest", [] (auto& t)
      {
        static_assert (std::is_same_v<subtest, test_case>,
                       "subtest is an alias of test_case");

        runner_options options{};
        options.verbosity_level = verbosity::silent;

        runner local_runner;
        local_runner.initialise (options);
        auto& local_ts = local_runner.add_top_suite ("Local");

        // A function passed directly, as the v5.0.1 unit tests did.
        local_ts.test ("Function", subtest_function);
        local_ts.test ("Lambda", [] (subtest& lt)
          { lt.test ("Nested function", subtest_function); });

        t.expect (eq (local_runner.run_suites (), 0))
            << "local session passed";
        local_counts.passed_checks++;

        t.expect (eq (local_runner.totals ().executed_test_cases (), 3u)
                  and eq (local_runner.totals ().passed_checks (), 2u))
            << "the function ran in the suite and in the lambda";
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

    // The totals of a node are read-only, even for a non-`const` node, so
    // that a test case cannot erase its own failures; the v5.0.1 code that
    // bound a non-`const` reference no longer compiles.
    ts.test ("read-only totals()", [] (auto& t)
      {
        static_assert (std::is_same_v<decltype (t.totals ()), const counters&>,
                       "the totals() of a non-const node is read-only");
        static_assert (std::is_same_v<decltype (std::as_const (t).totals ()),
                                      const counters&>,
                       "the totals() of a const node is read-only");

        t.expect (&t.totals () == &std::as_const (t).totals ())
            << "both refer to the live totals";
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
        local_runner.initialise (options);
        auto& local_ts = local_runner.add_top_suite ("Local");
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

        t.expect (eq (local_runner.run_suites (), 0))
            << "local session passed";
        local_counts.passed_checks++;

        t.expect (added_started) << "the suite timings are started";
        local_counts.passed_checks++;

        t.expect (eq (session_timings.has_timestamps (), has_clock)
                  and eq (session_timings.has_end (), has_clock)
                  and eq (top_timings.has_timestamps (), has_clock)
                  and added_timings != nullptr
                  and eq (added_timings->has_timestamps (), has_clock))
            << "the timings are stopped by run_suites()";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated members kept from the v5.0.1 `detail::timestamps`,
    // with known readings.
    ts.test ("timestamps::compute_elapsed_time()", [] (auto& t)
      {
        detail::stopwatch sw{};
        uint32_t milliseconds = 1;
        uint32_t microseconds = 1;

        sw.compute_elapsed_time (milliseconds, microseconds);

        t.expect (!sw.has_begin () and !sw.has_end () and !sw.has_timestamps ()
                  and eq (milliseconds, 0u) and eq (microseconds, 0u))
            << "no readings, zero elapsed time";
        local_counts.passed_checks++;

        detail::stopwatch_test_access::set_times (sw, { 1, 0 }, { 0, 0 });

        t.expect (sw.has_begin () and !sw.has_end () and !sw.has_timestamps ())
            << "start reading only";
        local_counts.passed_checks++;

        // 1.001235 seconds, with a borrow from the seconds.
        detail::stopwatch_test_access::set_times (sw, { 1, 999'999'000 },
                                                  { 3, 1'234'000 });
        sw.compute_elapsed_time (milliseconds, microseconds);

        t.expect (sw.has_begin () and sw.has_end () and sw.has_timestamps ()
                  and eq (milliseconds, 1001u) and eq (microseconds, 235u))
            << "both readings, elapsed time split";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The deprecated writers kept from the v5.0.1 `detail::timestamps`;
    // unlike `start()` and `stop()`, they record only absent readings.
    ts.test ("timestamps::timestamp_begin(), timestamp_end()", [] (auto& t)
      {
        uint32_t milliseconds = 0;
        uint32_t microseconds = 0;

        detail::stopwatch sw{};
        sw.timestamp_begin ({ 1, 0 });
        sw.timestamp_begin ({ 5, 0 });

        t.expect (sw.has_begin () and !sw.has_end ())
            << "the first start time is kept";
        local_counts.passed_checks++;

        // 1.5 seconds.
        sw.timestamp_end ({ 2, 500'000'000 });
        sw.timestamp_end ({ 9, 0 });
        sw.compute_elapsed_time (milliseconds, microseconds);

        t.expect (sw.has_timestamps () and eq (milliseconds, 1500u)
                  and eq (microseconds, 0u))
            << "the first stop time is kept";
        local_counts.passed_checks++;

        // Present readings are not replaced by the clock.
        detail::stopwatch_test_access::set_times (sw, { 1, 0 }, { 2, 0 });
        sw.timestamp_begin ();
        sw.timestamp_end ();
        sw.compute_elapsed_time (milliseconds, microseconds);

        t.expect (eq (milliseconds, 1000u) and eq (microseconds, 0u))
            << "the clock does not replace the readings";
        local_counts.passed_checks++;

        // The start reading does not clear the stop reading, as start()
        // does.
        detail::stopwatch_test_access::set_times (sw, { 0, 0 }, { 2, 0 });
        sw.timestamp_begin ({ 1, 0 });
        sw.compute_elapsed_time (milliseconds, microseconds);

        t.expect (sw.has_end () and eq (milliseconds, 1000u))
            << "the stop reading is kept";
        local_counts.passed_checks++;

        // A zero time is not a reading.
        detail::stopwatch zero_sw{};
        zero_sw.timestamp_begin ({ 0, 0 });
        zero_sw.timestamp_end ({ 0, 0 });

        t.expect (!zero_sw.has_begin () and !zero_sw.has_end ())
            << "zero times are not readings";
        local_counts.passed_checks++;

        detail::stopwatch clock_sw{};
        clock_sw.timestamp_begin ();
        clock_sw.timestamp_end ();

        t.expect (eq (clock_sw.has_begin (), has_clock)
                  and eq (clock_sw.has_end (), has_clock)
                  and eq (clock_sw.has_timestamps (), has_clock))
            << "the readings of the clock";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The v5.0.1 `detail::timestamp` class, no longer used by the
    // framework.
    ts.test ("detail::timestamp", [] (auto& t)
      {
        static_assert (std::is_copy_constructible_v<detail::timestamp>
                           and std::is_copy_assignable_v<detail::timestamp>,
                       "timestamp is copyable");
        static_assert (std::is_convertible_v<timespec, detail::timestamp>,
                       "a timespec converts to timestamp");
        static_assert (
            std::is_same_v<
                decltype (std::declval<detail::timestamp&> ().value ()),
                timespec&>,
            "the non-const value() returns a reference");
        static_assert (
            std::is_same_v<
                decltype (std::declval<const detail::timestamp&> ().value ()),
                const timespec&>,
            "the const value() returns a const reference");

        detail::timestamp now{};
        t.expect (eq (now.has_clock (), has_clock))
            << "the default constructor reads the clock";
        local_counts.passed_checks++;

        detail::timestamp given{ { 1, 2 } };
        t.expect (given.has_clock () and eq (given.value ().tv_sec, 1)
                  and eq (given.value ().tv_nsec, 2))
            << "the time given to the constructor";
        local_counts.passed_checks++;

        detail::timestamp copy{ given };
        detail::timestamp assigned{};
        assigned = given;
        t.expect (eq (copy.value ().tv_sec, 1)
                  and eq (copy.value ().tv_nsec, 2)
                  and eq (assigned.value ().tv_sec, 1)
                  and eq (assigned.value ().tv_nsec, 2))
            << "copied and assigned";
        local_counts.passed_checks++;

        given.value () = { 3, 4 };
        t.expect (eq (std::as_const (given).value ().tv_sec, 3)
                  and eq (std::as_const (given).value ().tv_nsec, 4))
            << "modified through value()";
        local_counts.passed_checks++;

        // The v5.0.1 derived class, which sets the protected member.
        known_timestamp known{};
        known.set ({ 0, 0 });
        t.expect (!known.has_clock ()) << "zero value, no clock";
        local_counts.passed_checks++;

        known.set ({ 0, 1 });
        t.expect (known.has_clock ()) << "non-zero nanoseconds, a clock";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The v5.0.1 reporter of the session, used to read the verbosity;
    // it is created by `initialise()`, from the session options.
    ts.test ("runner::reporter()", [] (auto& t)
      {
        static_assert (std::is_same_v<decltype (std::declval<const runner&> ()
                                                    .reporter ()),
                                      detail::reporter&>,
                       "runner::reporter() returns a reference");

        runner_options options{};
        options.verbosity_level = verbosity::silent;
        options.selected_reporter = reporter_kind::human;

        runner human_runner;
        human_runner.initialise (options);
        human_runner.add_top_suite ("Human");

        options.selected_reporter = reporter_kind::tap;

        runner tap_runner;
        tap_runner.initialise (options);
        tap_runner.add_top_suite ("TAP");

        // The v5.0.1 expression.
        t.expect (human_runner.reporter ().verbosity () == verbosity::silent
                  and tap_runner.reporter ().verbosity () == verbosity::silent)
            << "the verbosity of the session options";
        local_counts.passed_checks++;

        t.expect (tr.reporter ().verbosity () == tr.verbosity_level ())
            << "the verbosity of the command line";
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

    // The deprecated names of `all_of()`, `any_of()`, and `negate()`; they
    // return the same expressions, so they are reported in the same way.
    ts.test ("_and(), _or(), _not()", [] (auto& t)
      {
        static_assert (
            std::is_same_v<decltype (_and (eq (1, 1), eq (2, 2))),
                           decltype (all_of (eq (1, 1), eq (2, 2)))>,
            "_and() returns the same expression as all_of()");
        static_assert (
            std::is_same_v<decltype (_or (eq (1, 1), eq (2, 2))),
                           decltype (any_of (eq (1, 1), eq (2, 2)))>,
            "_or() returns the same expression as any_of()");
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

    // The v5.0.1 `type_traits` namespace; the names that still exist refer
    // to the current concepts and templates, so they have the current
    // semantics.
    ts.test ("type_traits", [] (auto& t)
      {
        // The concepts.
        static_assert (type_traits::is_op<detail::op>);
        static_assert (type_traits::is_op<to_i>);
        static_assert (not type_traits::is_op<int>);
        static_assert (type_traits::any_op<int, to_i>);
        static_assert (not type_traits::any_op<int, int>);
        static_assert (type_traits::checkable<bool>);
        static_assert (type_traits::checkable<to_b>);
        static_assert (type_traits::printable<int>);
        static_assert (type_traits::printable<std::string_view>);
        static_assert (type_traits::has_epsilon<to_d>);
        static_assert (not type_traits::has_epsilon<to_i>);
        static_assert (type_traits::container_like<std::string_view>);
        static_assert (not type_traits::container_like<int>);
        static_assert (type_traits::has_npos<std::string_view>);
        static_assert (not type_traits::has_npos<int>);
        static_assert (type_traits::has_value<detail::integral_constant<42>>);
        static_assert (not type_traits::has_value<to_i>);
        // As in v5.0.1, the application types with a `value` member are
        // included; the framework uses `detail::has_value`, which
        // excludes them.
        static_assert (type_traits::has_value<with_value_member>);
        static_assert (not detail::has_value<with_value_member>);
        static_assert (not type_traits::has_value<int>);
        static_assert (not type_traits::has_value<void>);
        static_assert (type_traits::is_floating_point<double>);
        static_assert (not type_traits::is_floating_point<int>);

        // The restored helpers.
        static_assert (
            std::is_same_v<type_traits::identity<int, char>::type, int>);
        static_assert (
            std::is_same_v<type_traits::list<>,
                           type_traits::function_traits<void ()>::args>);
        static_assert (
            std::is_same_v<
                void, type_traits::function_traits<void ()>::result_type>);
        static_assert (
            std::is_same_v<
                type_traits::list<int, const float&>,
                type_traits::function_traits<void (int, const float&)>::args>);
        static_assert (std::is_same_v<int, type_traits::function_traits<
                                               int (*) (char)>::result_type>);
        // The type of the lambda depends on the parameter of the test case.
        auto lambda = [] (int, char) { return 1.0; };
        using lambda_traits = type_traits::function_traits<decltype (lambda)>;
        static_assert (std::is_same_v<type_traits::list<int, char>,
                                      typename lambda_traits::args>);
        static_assert (
            std::is_same_v<double, typename lambda_traits::result_type>);

        // The base of the expressions and the value wrappers.
        static_assert (std::is_same_v<type_traits::op, detail::op>);
        static_assert (
            std::is_same_v<type_traits::value<int>, detail::value<int>>);
        static_assert (
            std::is_same_v<type_traits::value<double>, detail::value<double>>);
        static_assert (std::is_same_v<type_traits::value_base_<int>,
                                      detail::value_base<int>>);
        static_assert (std::is_same_v<type_traits::genuine_integral_value<int>,
                                      detail::value<int>>);
        static_assert (std::is_same_v<type_traits::integral_constant<42>,
                                      detail::integral_constant<42>>);
        static_assert (std::is_same_v<
                       type_traits::floating_point_constant<double, 1, 5, 1>,
                       detail::floating_point_constant<double, 1, 5, 1>>);

        int one = 1;

        t.expect (eq (type_traits::value<int>{ one }, 1)
                  and eq (type_traits::genuine_integral_value<int>{ one }, 1))
            << "the wrapped values are compared";
        local_counts.passed_checks++;

        t.expect (!eq (type_traits::value<int>{ one }, 2)) << "false results";
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
    // The operators, the literals, and the type wrappers, deprecated in
    // favour of the function comparators, `eq()`, `ne()`, ..., and
    // `approx()`, which compare and report the plain values.
    // ------------------------------------------------------------------------

    ts.test ("Integer comparisons with literals", [] (auto& t)
      {
        using namespace literals;

        t.expect (eq (42_i, 42_i));
        local_counts.passed_checks++;

        t.expect (eq (42, 42_i)) << "42 == 42_i";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Failed integer comparisons with literals", [] (auto& t)
      {
        using namespace literals;

        t.expect (ne (42_i, 42_i)) << "42_i != 42_i";
        local_counts.failed_checks++;

        t.expect (ne (42, 42_i)) << "42 != 42_i";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Float comparisons with literals and wrappers", [] (auto& t)
      {
        using namespace literals;

        t.expect (eq (to_f (42.101f), 42.101_f)) << "42.101f == 42.101_f";
        local_counts.passed_checks++;

        t.expect (eq (to_f (42.101f, 0.01f), 42.10_f))
            << "42.101f epsilon 0.01f == 42.10_f";
        local_counts.passed_checks++;

        t.expect (ne (to_f (42.101f, 0.1f), 42.1000_f))
            << "42.101f epsilon 0.1f != 42.10_f";
        local_counts.passed_checks++;

        t.expect (eq (to_f (42.1010001f, 0.1f), 42.1_f))
            << "42.1010001f epsilon 0.1f == 42.1_f";
        local_counts.passed_checks++;

        t.expect (ne (to_f (42.101f), 42.10_f)) << "42.101f != 42.10_f";
        local_counts.passed_checks++;

        t.expect (ne (to_f (42.101f), 42.100_f)) << "42.101f != 42.100_f";
        local_counts.passed_checks++;

        t.expect (eq (to_f (42.10f), 42.1_f)) << "42.10f == 42.1_f";
        local_counts.passed_checks++;

        t.expect (eq (to_f (42.42f), 42.42_f)) << "42.42f == 42.42_f";
        local_counts.passed_checks++;

        t.expect (eq (to_d (42.42), 42.420_d)) << "42.42 == 42.420_d";
        local_counts.passed_checks++;

        t.expect (eq (to_d (42.0), 42.0_d)) << "42.0 == 42.0_d";
        local_counts.passed_checks++;

        t.expect (eq (to_d (42.), 42._d)) << "42. == 42._d";
        local_counts.passed_checks++;

        t.expect (eq (to_ld (42.42L), 42.42_ld)) << "42.42 == 42.42_ld";
        local_counts.passed_checks++;

        t.expect (eq (1234._f, 1234.f)) << "1234._f == 1234.f";
        local_counts.passed_checks++;

        t.expect (eq (1234.56_f, 1234.56f)) << "1234.56_f == 1234.56f";
        local_counts.passed_checks++;

        t.expect (eq (12345678.9f, 12345678.9_f))
            << "12345678.9f == 12345678.9_f";
        local_counts.passed_checks++;

        t.expect (eq (111111.42f, 111111.42_f)) << "111111.42f == 111111.42_f";
        local_counts.passed_checks++;

        t.expect (eq (1111111111.42, 1111111111.42_d))
            << "1111111111.42 == 1111111111.42_d";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Failed float comparisons with literals and wrappers",
             [] (auto& t)
      {
        using namespace literals;

        t.expect (ne (to_f (42.101f), 42.101_f)) << "42.101f != 42.101_f";
        local_counts.failed_checks++;

        t.expect (ne (to_f (42.101f, 0.01f), 42.10_f))
            << "42.101f epsilon 0.01f != 42.10_f";
        local_counts.failed_checks++;

        t.expect (eq (to_f (42.101f, 0.1f), 42.1000_f))
            << "42.101f epsilon 0.1f == 42.10_f";
        local_counts.failed_checks++;

        t.expect (ne (to_f (42.1010001f, 0.1f), 42.1_f))
            << "42.1010001f epsilon 0.1f != 42.1_f";
        local_counts.failed_checks++;

        t.expect (eq (to_f (42.101f), 42.10_f)) << "42.101f == 42.10_f";
        local_counts.failed_checks++;

        t.expect (eq (to_f (42.101f), 42.100_f)) << "42.101f == 42.100_f";
        local_counts.failed_checks++;

        t.expect (ne (to_f (42.10f), 42.1_f)) << "42.10f == 42.1_f";
        local_counts.failed_checks++;

        t.expect (ne (to_f (42.42f), 42.42_f)) << "42.42f == 42.42_f";
        local_counts.failed_checks++;

        t.expect (ne (to_d (42.42), 42.420_d)) << "42.42 == 42.420_d";
        local_counts.failed_checks++;

        t.expect (ne (to_d (42.0), 42.0_d)) << "42.0 == 42.0_d";
        local_counts.failed_checks++;

        t.expect (ne (to_d (42.), 42._d)) << "42. == 42._d";
        local_counts.failed_checks++;

        t.expect (ne (to_ld (42.42L), 42.42_ld)) << "42.42 == 42.42_ld";
        local_counts.failed_checks++;

        t.expect (ne (1234._f, 1234.f)) << "1234._f == 1234.f";
        local_counts.failed_checks++;

        t.expect (ne (1234.56_f, 1234.56f)) << "1234.56_f == 1234.56f";
        local_counts.failed_checks++;

        t.expect (ne (12345678.9f, 12345678.9_f))
            << "12345678.9f == 12345678.9_f";
        local_counts.failed_checks++;

        t.expect (ne (111111.42f, 111111.42_f)) << "111111.42f == 111111.42_f";
        local_counts.failed_checks++;

        t.expect (ne (1111111111.42, 1111111111.42_d))
            << "1111111111.42 == 1111111111.42_d";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Approximate comparisons with literals and wrappers", [] (auto& t)
      {
        using namespace literals;

        t.expect (approx (42_i, 43, 2)) << "42_i ~ 43 +/- 2";
        local_counts.passed_checks++;

        t.expect (approx (to_u16 (500), 512, 13)) << "500 ~ 512 +/- 13";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("to_* modern wrappers", [] (auto& t)
      {
        // Verify runtime wrapping of floating-point values.
        float f = 42.0f;
        t.expect (eq (to_f{ f }, 42.0f)) << "to_f wraps float for eq";
        local_counts.passed_checks++;

        double d = 42.0;
        t.expect (eq (to_d{ d }, 42.0)) << "to_d wraps double for eq";
        local_counts.passed_checks++;

        // Generic to_t<T> wrapper in a runtime expectation.
        int x = 42;
        t.expect (eq (to_t<int>{ x }, 42)) << "to_t<int> generic wrapper";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // All six comparisons apply the tolerance of the floating-point literals
    // and wrappers consistently: values within the tolerance are equal, and
    // neither less nor greater; `approx()` makes the tolerance explicit.
    ts.test ("Floating-point tolerance", [] (auto& t)
      {
        using namespace literals;

        // `1.5_d` has a tolerance of 0.1, so 1.45 is equal to it.
        t.expect (eq (1.45, 1.5_d)) << "1.45 == 1.5_d";
        t.expect (negate (lt (1.45, 1.5_d))) << "not 1.45 < 1.5_d";
        t.expect (le (1.45, 1.5_d)) << "1.45 <= 1.5_d";
        t.expect (negate (gt (1.45, 1.5_d))) << "not 1.45 > 1.5_d";
        t.expect (ge (1.45, 1.5_d)) << "1.45 >= 1.5_d";
        t.expect (lt (1.3, 1.5_d)) << "1.3 < 1.5_d (outside the tolerance)";
        local_counts.passed_checks += 6;

        // The tolerance of a wrapper is also derived from the number of
        // decimals, for negative values too, and the rounding noise of 0.011
        // does not make it 1e-18.
        t.expect (eq (-1.45, to_d{ -1.5 })) << "-1.45 == to_d{ -1.5 }";
        t.expect (eq (0.0111, to_d{ 0.011 })) << "0.0111 == to_d{ 0.011 }";
        t.expect (lt (0.009, to_d{ 0.011 })) << "0.009 < to_d{ 0.011 }";
        local_counts.passed_checks += 3;

        // The leading zeros of a small wrapper value are counted, so its
        // tolerance is not 0.1, a zero wrapper compares exactly, and a
        // whole value keeps one decimal, as `42.0_d`.
        t.expect (ne (to_d{ 1e-12 }, 0.05)) << "to_d{ 1e-12 } != 0.05";
        t.expect (lt (to_d{ 1e-12 }, 2.5e-12)) << "to_d{ 1e-12 } < 2.5e-12";
        t.expect (eq (to_d{ 1e-12 }, 1.5e-12)) << "to_d{ 1e-12 } == 1.5e-12";
        t.expect (ne (to_d{ 1e-9 }, 0.05)) << "to_d{ 1e-9 } != 0.05";
        t.expect (ne (to_d{ 0.0 }, 0.09)) << "to_d{ 0.0 } != 0.09";
        t.expect (lt (to_d{ 0.0 }, 0.09)) << "to_d{ 0.0 } < 0.09";
        t.expect (lt (to_d{ 0.0 }, 1e-300)) << "to_d{ 0.0 } < 1e-300";
        t.expect (eq (to_d{ 0.0 }, 0.0)) << "to_d{ 0.0 } == 0.0";
        t.expect (eq (to_d{ 0.0 }, -0.0)) << "to_d{ 0.0 } == -0.0";
        t.expect (eq (to_d{ 42.0 }, 42.09)) << "to_d{ 42.0 } == 42.09";
        local_counts.passed_checks += 10;

        // An explicit tolerance of 0.01.
        t.expect (ne (1.45, approx (1.5, 0.01)))
            << "1.45 != approx (1.5, 0.01)";
        t.expect (lt (1.45, approx (1.5, 0.01)))
            << "1.45 < approx (1.5, 0.01)";
        t.expect (eq (1.495, approx (1.5, 0.01)))
            << "1.495 == approx (1.5, 0.01)";
        t.expect (negate (lt (1.495, approx (1.5, 0.01))))
            << "not 1.495 < approx (1.5, 0.01)";
        t.expect (eq (0.1f + 0.2f, approx (0.3f, 1e-6f)))
            << "0.1f + 0.2f == approx (0.3f, 1e-6f)";
        local_counts.passed_checks += 5;

        // A zero tolerance compares the values exactly.
        t.expect (eq (1.5, approx (1.5, 0.0))) << "1.5 == approx (1.5, 0.0)";
        t.expect (negate (ne (1.5, approx (1.5, 0.0))))
            << "not 1.5 != approx (1.5, 0.0)";
        t.expect (le (1.5, approx (1.5, 0.0))) << "1.5 <= approx (1.5, 0.0)";
        t.expect (ge (1.5, approx (1.5, 0.0))) << "1.5 >= approx (1.5, 0.0)";
        local_counts.passed_checks += 4;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Operators", [] (auto& t)
      {
        using namespace operators;
        using namespace literals;

        t.expect (my_actual_integral () == 42_i) << "actual == 42";
        local_counts.passed_checks++;

        t.expect (my_actual_integral_more<int> () == 42)
            << "actual+1 == 42 with scalar";
        local_counts.failed_checks++;

        t.expect (my_actual_integral_more<int> () == 42_i)
            << "actual+1 == 42 with _i literal";
        local_counts.failed_checks++;

        t.expect (to_i (my_actual_integral_more<int> ()) == 42)
            << "actual+1 == 42 with to_i()";
        local_counts.failed_checks++;

        t.expect (my_actual_integral_more<int> () != 42_i) << "actual+1 != 42";
        local_counts.passed_checks++;

        t.expect (my_actual_integral_less<int> () < 42_i) << "actual-1 < 42";
        local_counts.passed_checks++;

        t.expect (my_actual_integral () <= 42_i) << "actual <= 42";
        local_counts.passed_checks++;

        t.expect (my_actual_integral_more<int> () > 42_i) << "actual+1 > 42";
        local_counts.passed_checks++;

        t.expect (my_actual_integral () >= 42_i) << "actual >= 42";
        local_counts.passed_checks++;

        t.expect (!(my_actual_integral () != 42_i)) << "not (actual != 42)";
        local_counts.passed_checks++;

        t.expect (!(my_actual_integral () == 42_i)) << "not (actual == 42)";
        local_counts.failed_checks++;

        // A double negation is not reduced to a single one, by copying
        // the inner negation.
        t.expect (!!(my_actual_integral () == 42_i))
            << "not not (actual == 42)";
        local_counts.passed_checks++;

        t.expect (((my_actual_integral () == 42_i)
                   && (my_actual_float<float> () == 42.0_d)))
            << "(actual == 42) and (actual == 42.0)";
        local_counts.passed_checks++;

        t.expect (((my_actual_integral () == 42_i)
                   && (my_actual_float<float> () != 42.0_d)))
            << "(actual == 42) and (actual != 42.0)";
        local_counts.failed_checks++;

        t.expect (((my_actual_integral () != 42_i)
                   && (my_actual_float<float> () == 42.0_d)))
            << "(actual != 42) and (actual == 42.0)";
        local_counts.failed_checks++;

        t.expect (((my_actual_integral () != 42_i)
                   && (my_actual_float<float> () != 42.0_d)))
            << "(actual != 42) and (actual != 42.0)";
        local_counts.failed_checks++;

        t.expect (((my_actual_integral () == 42_i)
                   && (my_actual_float<float> () == 42.0_d)));
        local_counts.passed_checks++;

        t.expect (((my_actual_integral () == 42_i)
                   && (my_actual_float<float> () != 42.0_d)));
        local_counts.failed_checks++;

        t.expect (((my_actual_integral () == 42)
                   || (my_actual_float<float> () == 42.0f)))
            << "(actual == 42) or (actual == 42.0)";
        local_counts.passed_checks++;

        t.expect (((my_actual_integral () == 42)
                   || (my_actual_float<float> () != 42.0f)))
            << "(actual == 42) or (actual != 42.0)";
        local_counts.passed_checks++;

        t.expect (((my_actual_integral () != 42)
                   || (my_actual_float<float> () == 42.0f)))
            << "(actual != 42) or (actual == 42.0)";
        local_counts.passed_checks++;

        t.expect ((my_actual_integral () != 42_i
                   || my_actual_float<float> () != 42.0_f))
            << "(actual != 42) or (actual != 42.0)";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // There are no string view operators; the standard ones are selected,
    // so the failed checks show no operands.
    ts.test ("String view operators", [] (auto& t)
      {
        using namespace operators;

        t.expect (std::string_view{ "hello" } == std::string_view{ "hello" })
            << "equal string views with ==";
        local_counts.passed_checks++;

        t.expect (std::string_view{ "hello" } == std::string_view{ "world" })
            << "unequal string views with ==";
        local_counts.failed_checks++;

        t.expect (std::string_view{ "hello" } != std::string_view{ "world" })
            << "unequal string views with !=";
        local_counts.passed_checks++;

        t.expect (std::string_view{ "hello" } != std::string_view{ "hello" })
            << "equal string views with !=";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The named boolean constants are reported by their names; they
    // previously recursed in the expression formatter, until the stack
    // overflowed.
    ts.test ("Named boolean literals", [] (auto& t)
      {
        using namespace literals;

        bool enabled = true;
        bool disabled = false;

        t.expect ("named"_b) << "named alone";
        local_counts.passed_checks++;

        t.expect (eq ("enabled"_b, enabled)) << "eq with true";
        local_counts.passed_checks++;

        t.expect (eq ("disabled"_b, disabled)) << "eq with false";
        local_counts.failed_checks++;

        t.expect (ne ("disabled"_b, disabled)) << "ne with false";
        local_counts.passed_checks++;

        {
          using namespace operators;

          t.expect ("enabled"_b == enabled) << "== with true";
          local_counts.passed_checks++;

          t.expect ("disabled"_b == disabled) << "== with false";
          local_counts.failed_checks++;

          t.expect (disabled == "disabled"_b) << "reversed == with false";
          local_counts.failed_checks++;

          t.expect ("enabled"_b != enabled) << "!= with true";
          local_counts.failed_checks++;

          t.expect (not "named"_b) << "not";
          local_counts.failed_checks++;

          t.expect ("first"_b == "second"_b) << "two named literals";
          local_counts.passed_checks++;
        }

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The framework constants and wrappers compare as before next to the
    // application types.
    ts.test ("Constants and wrappers", [] (auto& t)
      {
        using namespace literals;

        t.expect (eq (to_i{ 42 }, 42)) << "to_i{ 42 } == 42";
        local_counts.passed_checks++;

        t.expect (eq (42_i, 42_i)) << "42_i == 42_i";
        local_counts.passed_checks++;

        t.expect (eq (to_d{ 1.5 }, 1.54)) << "to_d{ 1.5 } == 1.54";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The literals and the wrappers can be streamed into the messages.
    ts.test ("Wrappers in messages", [] (auto& t)
      {
        using namespace literals;

        t.expect (true) << "wrappers " << 42_i << ' ' << 1.5_d;
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // The operators of the application are enabled by the framework types
    // of their operands, the literals and the wrappers.
    ts.test ("Custom comparators with wrappers", [] (auto& t)
      {
        using namespace literals;
        using namespace custom_operators;

        t.expect (divides (3_i, to_i{ 12 })) << "3_i divides to_i{ 12 }";
        local_counts.passed_checks++;

        t.expect (even (to_i{ 4 })) << "even to_i{ 4 }";
        local_counts.passed_checks++;

        t.expect (3_i | 12) << "3_i | 12";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    ts.test ("Failed custom comparators with wrappers", [] (auto& t)
      {
        using namespace literals;
        using namespace custom_operators;

        t.expect (even (to_i{ 7 }));
        local_counts.failed_checks++;

        t.expect (5_i | 12);
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // A wrapped operand is referred to, not copied.
    ts.test ("Operand copies of wrappers", [] (auto& t)
      {
        const counted a{ 1 };
        const counted b{ 1 };
        const to_t<counted> wrapped{ a };

        counted_copies = 0;
        t.expect (eq (wrapped, b)) << "wrapped operand";
        local_counts.passed_checks++;
        const int copies = counted_copies;

        t.expect (eq (copies, 0)) << "wrapped operand not copied";
        local_counts.passed_checks++;

        local_counts.executed_test_cases++;
      });

    // The helpers removed from the public API in 6.0.0 whose forwarders
    // are kept: `mut()`, `runner::name()`, the read-only functions of the
    // nodes, and the text accessors of the formatter.
    ts.test ("Kept helpers", [] (auto& t)
      {
        int value = 1;
        const int& const_ref = value;
        mut (const_ref) = 2;
        t.expect (eq (value, 2)) << "mut()";
        local_counts.passed_checks++;

        runner_options options{};
        options.verbosity_level = verbosity::silent;

        runner local_runner;
        local_runner.initialise (options);
        auto& local_ts = local_runner.add_top_suite ("Local");

        t.expect (eq (std::string_view{ local_runner.name () }, "runner"sv))
            << "runner::name()";
        local_counts.passed_checks++;

        local_ts.test ("Local test", [] (auto& lt) { lt.expect (true); });

        t.expect (eq (local_ts.own_index (), 1u)) << "own_index()";
        local_counts.passed_checks++;

        t.expect (eq (local_ts.children_subtests_count (), 1u))
            << "children_subtests_count()";
        local_counts.passed_checks++;

        t.expect (eq (local_ts.current_subtest_index (), 1u))
            << "current_subtest_index()";
        local_counts.passed_checks++;

        t.expect (eq (local_runner.run_suites (), 0))
            << "local session passed";
        local_counts.passed_checks++;

        detail::colours no_colours{};
        expression_formatter f{ no_colours };
        t.expect (f.empty ()) << "empty formatter";
        local_counts.passed_checks++;

        f << "abc";
        t.expect (eq (std::string_view{ f.c_str () }, "abc"sv)) << "c_str()";
        local_counts.passed_checks++;

        t.expect (eq (f.empty (), false)) << "not empty";
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

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

#include <string_view>
#include <type_traits>

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

    // The deprecated names of `passed_checks()` and
    // `increment_passed_checks()`.
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

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // ------------------------------------------------------------------------
  } };

// ----------------------------------------------------------------------------

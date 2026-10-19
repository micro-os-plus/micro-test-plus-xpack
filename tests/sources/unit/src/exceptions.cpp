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

#if defined(__EXCEPTIONS)

#include <stdexcept>

using namespace micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wsign-compare"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-bind-to-temporary-copy"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

static void
exercise_throw (bool mustThrow)
{
  if (mustThrow)
    {
      throw "kaboom";
    }
}

static void
exercise_throw_runtime_error (bool mustThrow)
{
  if (mustThrow)
    {
      throw std::runtime_error{ "boom" };
    }
}

// ----------------------------------------------------------------------------

static static_suite ts_exceptions{ "Exceptions suite", tr,
                                   [] (auto& ts) noexcept
  {
    const counters& current_suite_totals = ts.totals ();

    local_counts = {};

    // ------------------------------------------------------------------------

    ts.test ("thrown exceptions", [] (auto& t)
      {
        t.expect (throws ([] { exercise_throw (true); }))
            << "exception thrown";
        local_counts.passed_checks++;

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

        t.expect (throws<std::runtime_error> ([]
          { throw std::runtime_error{ "" }; }))
            << "std::runtime_error thrown";

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

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

    ts.test ("Failed thrown exceptions", [] (auto& t)
      {
        t.expect (throws ([] { exercise_throw (false); }))
            << "exception thrown";
        local_counts.failed_checks++;

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

        t.expect (throws<std::runtime_error> ([] ()
          { throw std::invalid_argument{ "" }; }))
            << "std::runtime_error thrown";

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // ------------------------------------------------------------------------

    ts.test ("Not thrown exceptions", [] (auto& t)
      {
        t.expect (nothrow ([] { exercise_throw (false); }))
            << "exception not thrown";
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

    ts.test ("Failed not thrown exceptions", [] (auto& t)
      {
        t.expect (nothrow ([] { exercise_throw (true); }))
            << "exception not thrown";
        local_counts.failed_checks++;

        local_counts.executed_test_cases++;
      });

    test_assert (current_suite_totals.passed_checks ()
                 == local_counts.passed_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_test_cases ()
                 == local_counts.executed_test_cases);

    // ------------------------------------------------------------------------

    // An exception escaping a test case is reported as a failed check, at
    // the location of the test() call, and the run continues with the next
    // test case (API-REVIEW.md #14).
    {
      const size_t failed_test_cases_before
          = current_suite_totals.failed_test_cases ();

      ts.test ("Unexpected std::exception", [] (auto& t)
        {
          t.expect (true) << "check before the exception";
          local_counts.passed_checks++;

          // Reported as `unexpected exception: boom`.
          exercise_throw_runtime_error (true);

          t.expect (false) << "check after the exception";
        });
      // The exception, counted here since the body did not reach its end.
      local_counts.failed_checks++;
      local_counts.executed_test_cases++;

      ts.test ("Unexpected exception of unknown type", [] (auto& t)
        {
          // Reported as `unexpected exception of unknown type`.
          exercise_throw (true);

          t.expect (false) << "check after the exception";
        });
      local_counts.failed_checks++;
      local_counts.executed_test_cases++;

      // The nested test case catches its own exception; the outer test
      // case continues, and fails because of the failed nested test case.
      ts.test ("Unexpected exception in nested test case", [] (auto& t)
        {
          t.test ("nested test case",
                  [] (auto&) { exercise_throw_runtime_error (true); });
          local_counts.failed_checks++;
          local_counts.executed_test_cases++; // nested

          t.expect (true) << "check after the nested test case";
          local_counts.passed_checks++;
        });
      local_counts.executed_test_cases++; // outer

      test_assert (current_suite_totals.passed_checks ()
                   == local_counts.passed_checks);
      test_assert (current_suite_totals.failed_checks ()
                   == local_counts.failed_checks);
      test_assert (current_suite_totals.executed_test_cases ()
                   == local_counts.executed_test_cases);
      // The two test cases, and the nested and the outer test cases.
      test_assert (current_suite_totals.failed_test_cases ()
                   == failed_test_cases_before + 4);
    }

    // ------------------------------------------------------------------------

    // A failed require() stops only the current test case, as the fatal
    // assertions of the other frameworks do, and the run continues with the
    // next test case (API-REVIEW.md #22).
    {
      const size_t failed_test_cases_before
          = current_suite_totals.failed_test_cases ();

      ts.test ("Failed require", [] (auto& t)
        {
          t.expect (true) << "check before the requirement";
          local_counts.passed_checks++;

          try
            {
              // Counted before, since the statement does not return.
              local_counts.failed_checks++;
              t.require (false) << "failed requirement";
            }
          catch (const std::exception&)
            {
              // Not a std::exception, so not caught here.
              t.expect (false) << "requirement caught as std::exception";
            }

          t.expect (false) << "check after the requirement";
        });
      local_counts.executed_test_cases++;

      ts.test ("Failed deprecated assume", [] (auto& t)
        {
          local_counts.failed_checks++;
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif // defined(__GNUC__)
          t.assume (false) << "failed assumption";
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

          t.expect (false) << "check after the assumption";
        });
      local_counts.executed_test_cases++;

      // The nested test case is stopped; the outer test case continues,
      // and fails because of the failed nested test case.
      ts.test ("Failed require in nested test case", [] (auto& t)
        {
          t.test ("nested test case", [] (auto& nt)
            {
              local_counts.failed_checks++;
              nt.require (false) << "failed nested requirement";

              nt.expect (false) << "check after the nested requirement";
            });
          local_counts.executed_test_cases++; // nested

          t.expect (true) << "check after the nested test case";
          local_counts.passed_checks++;
        });
      local_counts.executed_test_cases++; // outer

      // A kept result is reported during the stack unwinding caused by
      // another exception; it must not throw, which would terminate.
      ts.test ("Failed require during unwinding", [] (auto& t)
        {
          // Bound directly to the returned temporary, which lives until
          // the end of the body.
          auto&& kept = t.require (false);
          kept << "failed kept requirement";
          local_counts.failed_checks++;

          // Reported as `unexpected exception: boom`.
          exercise_throw_runtime_error (true);
        });
      local_counts.failed_checks++; // the exception
      local_counts.executed_test_cases++;

      // An exception that escapes a suite body, outside its test cases, is
      // reported as a failed check of the suite, and the following suites
      // still run (API-REVIEW.md #5).
      ts.test ("Exception in a suite body", [] (auto& t)
        {
          runner_options options{};
          options.selected_reporter = reporter_kind::human;
          options.verbosity_level = verbosity::silent;

          int later_runs = 0;

          // The suites run sorted by name.
          runner local_runner;
          local_runner.initialise (options, "Local");
          local_runner.add_suite ("A throwing suite", [] (suite& s)
            {
              s.test ("Local test", [] (auto& lt) { lt.expect (true); });
              throw 42;
            });
          local_runner.add_suite ("B later suite", [&later_runs] (suite& s)
            {
              ++later_runs;
              s.test ("Local test", [] (auto& lt) { lt.expect (true); });
            });

          t.expect (eq (local_runner.run (), 1)) << "session failed";
          local_counts.passed_checks++;

          t.expect (eq (later_runs, 1)) << "later suite run";
          local_counts.passed_checks++;

          t.expect (eq (local_runner.totals ().passed_checks (), 2u)
                    and eq (local_runner.totals ().failed_checks (), 1u)
                    and eq (local_runner.totals ().executed_test_cases (), 2u))
              << "exception counted as a failed check";
          local_counts.passed_checks++;
        });
      local_counts.executed_test_cases++;

      test_assert (current_suite_totals.passed_checks ()
                   == local_counts.passed_checks);
      test_assert (current_suite_totals.failed_checks ()
                   == local_counts.failed_checks);
      test_assert (current_suite_totals.executed_test_cases ()
                   == local_counts.executed_test_cases);
      // Three test cases, and the nested and the outer test cases.
      test_assert (current_suite_totals.failed_test_cases ()
                   == failed_test_cases_before + 5);
    }
  } };

// An exception that escapes the suite body, outside its test cases, is
// reported as `unexpected exception in the suite body: boom`, after the
// test cases already run; the following test cases are not run, and the
// session continues with the next suite (API-REVIEW.md #5). The body must
// not be declared `noexcept`, which would terminate the program.
static static_suite ts_exceptions_body{ "Exceptions suite body", tr,
                                        [] (auto& ts)
  {
    ts.test ("Test case before the exception", [] (auto& t)
      { t.expect (true) << "check before the exception"; });

    exercise_throw_runtime_error (true);

    ts.test ("Test case after the exception", [] (auto& t)
      { t.expect (false) << "check after the exception"; });
  } };

#endif // __EXCEPTIONS

// ----------------------------------------------------------------------------

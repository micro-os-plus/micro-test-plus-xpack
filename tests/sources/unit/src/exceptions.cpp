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
    const detail::runner_totals& current_suite_totals = ts.totals ();

    local_counts = {};

    // ------------------------------------------------------------------------

    ts.test ("thrown exceptions", [] (auto& t)
      {
        t.expect (throws ([] { exercise_throw (true); }))
            << "exception thrown";
        local_counts.successful_checks++;

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

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------

    ts.test ("Not thrown exceptions", [] (auto& t)
      {
        t.expect (nothrow ([] { exercise_throw (false); }))
            << "exception not thrown";
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

    ts.test ("Failed not thrown exceptions", [] (auto& t)
      {
        t.expect (nothrow ([] { exercise_throw (true); }))
            << "exception not thrown";
        local_counts.failed_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    // ------------------------------------------------------------------------

    // An exception escaping a test case is reported as a failed check, at
    // the location of the test() call, and the run continues with the next
    // test case (API-REVIEW.md #14).
    {
      const size_t failed_subtests_before
          = current_suite_totals.failed_subtests ();

      ts.test ("Unexpected std::exception", [] (auto& t)
        {
          t.expect (true) << "check before the exception";
          local_counts.successful_checks++;

          // Reported as `unexpected exception: boom`.
          exercise_throw_runtime_error (true);

          t.expect (false) << "check after the exception";
        });
      // The exception, counted here since the body did not reach its end.
      local_counts.failed_checks++;
      local_counts.executed_subtest++;

      ts.test ("Unexpected exception of unknown type", [] (auto& t)
        {
          // Reported as `unexpected exception of unknown type`.
          exercise_throw (true);

          t.expect (false) << "check after the exception";
        });
      local_counts.failed_checks++;
      local_counts.executed_subtest++;

      // The nested test case catches its own exception; the outer test
      // case continues, and fails because of the failed nested test case.
      ts.test ("Unexpected exception in nested test case", [] (auto& t)
        {
          t.test ("nested test case", [] (auto&)
            { exercise_throw_runtime_error (true); });
          local_counts.failed_checks++;
          local_counts.executed_subtest++; // nested

          t.expect (true) << "check after the nested test case";
          local_counts.successful_checks++;
        });
      local_counts.executed_subtest++; // outer

      test_assert (current_suite_totals.successful_checks ()
                   == local_counts.successful_checks);
      test_assert (current_suite_totals.failed_checks ()
                   == local_counts.failed_checks);
      test_assert (current_suite_totals.executed_subtests ()
                   == local_counts.executed_subtest);
      // The two test cases, and the nested and the outer test cases.
      test_assert (current_suite_totals.failed_subtests ()
                   == failed_subtests_before + 4);
    }
  } };

#endif // __EXCEPTIONS

// ----------------------------------------------------------------------------

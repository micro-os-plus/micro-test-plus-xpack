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
#endif
#endif

// ----------------------------------------------------------------------------

static void
exercise_throw (bool mustThrow)
{
  if (mustThrow)
    {
      throw "kaboom";
    }
}

// ----------------------------------------------------------------------------

static static_suite ts_exceptions{ "Exceptions suite", tr,
                                   [] ([[maybe_unused]] auto& ts) noexcept
  {
    runner_totals& current_suite_totals = ts.totals ();

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
#endif
#endif
        t.expect (throws<std::runtime_error> ([]
          { throw std::runtime_error{ "" }; }))
            << "std::runtime_error thrown";
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

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
#endif
#endif
        t.expect (throws<std::runtime_error> ([] ()
          { throw std::invalid_argument{ "" }; }))
            << "std::runtime_error thrown";
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

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
  } };

#endif // __EXCEPTIONS

// ----------------------------------------------------------------------------

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

using namespace micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wfloat-equal"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

static static_suite ts_operators{ "Operators suite", tr, [] (auto& ts)
  {
    const counters& current_suite_totals = ts.totals ();

    local_counts = {};

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
                   || (my_actual_float<float> () == 42.0)))
            << "(actual == 42) or (actual == 42.0)";
        local_counts.passed_checks++;

        t.expect (((my_actual_integral () == 42)
                   || (my_actual_float<float> () != 42.0)))
            << "(actual == 42) or (actual != 42.0)";
        local_counts.passed_checks++;

        t.expect (((my_actual_integral () != 42)
                   || (my_actual_float<float> () == 42.0)))
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
  } };

// ----------------------------------------------------------------------------

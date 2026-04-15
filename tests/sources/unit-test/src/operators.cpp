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
#endif
#endif

// ----------------------------------------------------------------------------

static static_suite ts_exceptions{ "Operators suite", tr, [] (auto& ts)
  {
    runner_totals& current_suite_totals = ts.totals ();

    local_counts = {};

    ts.test ("Operators", [] (auto& t)
      {
        using namespace operators;
        using namespace literals;

        t.expect (my_actual_integral () == 42_i) << "actual == 42";
        local_counts.successful_checks++;

        t.expect (my_actual_integral_more<int> () == 42)
            << "actual+1 == 42 with scalar";
        local_counts.failed_checks++;

        t.expect (my_actual_integral_more<int> () == 42_i)
            << "actual+1 == 42 with _i literal";
        local_counts.failed_checks++;

        t.expect (_i (my_actual_integral_more<int> ()) == 42)
            << "actual+1 == 42 with _i()";
        local_counts.failed_checks++;

        t.expect (my_actual_integral_more<int> () != 42_i) << "actual+1 != 42";
        local_counts.successful_checks++;

        t.expect (my_actual_integral_less<int> () < 42_i) << "actual-1 < 42";
        local_counts.successful_checks++;

        t.expect (my_actual_integral () <= 42_i) << "actual <= 42";
        local_counts.successful_checks++;

        t.expect (my_actual_integral_more<int> () > 42_i) << "actual+1 > 42";
        local_counts.successful_checks++;

        t.expect (my_actual_integral () >= 42_i) << "actual >= 42";
        local_counts.successful_checks++;

        t.expect (!(my_actual_integral () != 42_i)) << "not (actual != 42)";
        local_counts.successful_checks++;

        t.expect (!(my_actual_integral () == 42_i)) << "not (actual == 42)";
        local_counts.failed_checks++;

        t.expect (((my_actual_integral () == 42_i)
                   && (my_actual_float<float> () == 42.0_d)))
            << "(actual == 42) and (actual == 42.0)";
        local_counts.successful_checks++;

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
        local_counts.successful_checks++;

        t.expect (((my_actual_integral () == 42_i)
                   && (my_actual_float<float> () != 42.0_d)));
        local_counts.failed_checks++;

        t.expect (((my_actual_integral () == 42)
                   || (my_actual_float<float> () == 42.0)))
            << "(actual == 42) or (actual == 42.0)";
        local_counts.successful_checks++;

        t.expect (((my_actual_integral () == 42)
                   || (my_actual_float<float> () != 42.0)))
            << "(actual == 42) or (actual != 42.0)";
        local_counts.successful_checks++;

        t.expect (((my_actual_integral () != 42)
                   || (my_actual_float<float> () == 42.0)))
            << "(actual != 42) or (actual == 42.0)";
        local_counts.successful_checks++;

        t.expect ((my_actual_integral () != 42_i
                   || my_actual_float<float> () != 42.0_f))
            << "(actual != 42) or (actual != 42.0)";
        local_counts.failed_checks++;

        local_counts.executed_subtest++;
      });

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("String view operators", [] (auto& t)
      {
        using namespace operators;

        t.expect (std::string_view{ "hello" } == std::string_view{ "hello" })
            << "equal string views with ==";
        local_counts.successful_checks++;

        t.expect (std::string_view{ "hello" } == std::string_view{ "world" })
            << "unequal string views with ==";
        local_counts.failed_checks++;

        t.expect (std::string_view{ "hello" } != std::string_view{ "world" })
            << "unequal string views with !=";
        local_counts.successful_checks++;

        t.expect (std::string_view{ "hello" } != std::string_view{ "hello" })
            << "equal string views with !=";
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

// ----------------------------------------------------------------------------

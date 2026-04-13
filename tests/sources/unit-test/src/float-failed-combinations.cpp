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

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wsign-compare"

// ----------------------------------------------------------------------------

template <typename T>
static void
test_case_expect_floats_failed_combinatorial (subtest& t)
{
  t.expect (
      ne (my_actual_float<T> (), my_expected_integral<signed long long> ()))
      << "42.0 == 42 signed long long";
  local_counts.failed_checks++;

  t.expect (
      ne (my_actual_float<T> (), my_expected_integral<unsigned long long> ()))
      << "42.0 == 42 unsigned long long";
  local_counts.failed_checks++;

  t.expect (ne (my_actual_float<T> (), my_expected_integral<signed long> ()))
      << "42.0 == 42 signed long";
  local_counts.failed_checks++;

  t.expect (ne (my_actual_float<T> (), my_expected_integral<unsigned long> ()))
      << "42.0 == 42 unsigned long";
  local_counts.failed_checks++;

  t.expect (ne (my_actual_float<T> (), my_expected_integral<signed int> ()))
      << "42.0 == 42 signed int";
  local_counts.failed_checks++;

  t.expect (ne (my_actual_float<T> (), my_expected_integral<unsigned int> ()))
      << "42.0 == 42 unsigned int";
  local_counts.failed_checks++;

  t.expect (ne (my_actual_float<T> (), my_expected_integral<signed short> ()))
      << "42.0 == 42 signed short";
  local_counts.failed_checks++;

  t.expect (
      ne (my_actual_float<T> (), my_expected_integral<unsigned short> ()))
      << "42.0 == 42 unsigned short";
  local_counts.failed_checks++;

  t.expect (ne (my_actual_float<T> (), my_expected_integral<signed char> ()))
      << "42.0 == 42 signed char";
  local_counts.failed_checks++;

  t.expect (ne (my_actual_float<T> (), my_expected_integral<unsigned char> ()))
      << "42.0 == 42 unsigned char";
  local_counts.failed_checks++;

  // --------------------------------------------------------------------------

  t.expect (gt (my_actual_float<T> (), my_expected_integral<signed int> ()))
      << "42.0 <= 42 signed int";
  local_counts.failed_checks++;

  t.expect (lt (my_actual_float<T> (), my_expected_integral<signed int> ()))
      << "42.0 >= 42 signed int";
  local_counts.failed_checks++;

  t.expect (
      eq (my_actual_float_more<T> (), my_expected_integral<signed int> ()))
      << "43.0 != 42 signed int";
  local_counts.failed_checks++;

  t.expect (
      ge (my_actual_float_less<T> (), my_expected_integral<signed int> ()))
      << "41.0 < 42 signed int";
  local_counts.failed_checks++;

  t.expect (
      le (my_actual_float_more<T> (), my_expected_integral<signed int> ()))
      << "43.0 > 42 signed int";
  local_counts.failed_checks++;

  // --------------------------------------------------------------------------

  t.expect (gt (my_actual_float<T> (), my_expected_integral<unsigned int> ()))
      << "42.0 <= 42 unsigned int";
  local_counts.failed_checks++;

  t.expect (lt (my_actual_float<T> (), my_expected_integral<unsigned int> ()))
      << "42.0 >= 42 unsigned int";
  local_counts.failed_checks++;

  t.expect (
      eq (my_actual_float_more<T> (), my_expected_integral<unsigned int> ()))
      << "43.0 != 42 unsigned int";
  local_counts.failed_checks++;

  t.expect (
      ge (my_actual_float_less<T> (), my_expected_integral<unsigned int> ()))
      << "41.0 < 42 unsigned int";
  local_counts.failed_checks++;

  t.expect (
      le (my_actual_float_more<T> (), my_expected_integral<unsigned int> ()))
      << "43.0 > 42 unsigned int";
  local_counts.failed_checks++;

  // ---

  t.expect (ne (42, my_expected_float<T> ())) << "42 == 42.0";
  local_counts.failed_checks++;

  // ---

  local_counts.executed_subtest++;
}

// ----------------------------------------------------------------------------

static static_suite ts_failed_floats{ "Failed combinatorial floats suite", tr,
                                      [] (auto& ts)
  {
    runner_totals& current_suite_totals = ts.totals ();

    local_counts = {};

    ts.test ("Combinatorial floats",
             test_case_expect_floats_failed_combinatorial<float>);

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Combinatorial doubles",
             test_case_expect_floats_failed_combinatorial<double>);

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);
  } };

// ----------------------------------------------------------------------------

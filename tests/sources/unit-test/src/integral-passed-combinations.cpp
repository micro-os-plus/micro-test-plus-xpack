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
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
#endif

// ----------------------------------------------------------------------------

template <typename T>
static void
test_case_expect_integrals_passed_combinations (subtest& t)
{
  t.expect (
      eq (my_actual_integral<T> (), my_expected_integral<signed long long> ()))
      << "eq matches signed long long";
  local_counts.successful_checks++;

  t.expect (eq (my_actual_integral<T> (),
                my_expected_integral<unsigned long long> ()))
      << "eq matches unsigned long long";
  local_counts.successful_checks++;

  t.expect (
      eq (my_actual_integral<T> (), my_expected_integral<signed long> ()))
      << "eq matches signed long";
  local_counts.successful_checks++;

  t.expect (
      eq (my_actual_integral<T> (), my_expected_integral<unsigned long> ()))
      << "eq matches unsigned long";
  local_counts.successful_checks++;

  t.expect (eq (my_actual_integral<T> (), my_expected_integral<signed int> ()))
      << "eq matches signed int";
  local_counts.successful_checks++;

  t.expect (
      eq (my_actual_integral<T> (), my_expected_integral<unsigned int> ()))
      << "eq matches unsigned int";
  local_counts.successful_checks++;

  t.expect (
      eq (my_actual_integral<T> (), my_expected_integral<signed short> ()))
      << "eq matches signed short";
  local_counts.successful_checks++;

  t.expect (
      eq (my_actual_integral<T> (), my_expected_integral<unsigned short> ()))
      << "eq matches unsigned short";
  local_counts.successful_checks++;

  t.expect (
      eq (my_actual_integral<T> (), my_expected_integral<signed char> ()))
      << "eq matches signed char";
  local_counts.successful_checks++;

  t.expect (
      eq (my_actual_integral<T> (), my_expected_integral<unsigned char> ()))
      << "eq matches unsigned char";
  local_counts.successful_checks++;

  // --------------------------------------------------------------------------

  t.expect (le (my_actual_integral<T> (), my_expected_integral<signed int> ()))
      << "le matches signed int";
  local_counts.successful_checks++;

  t.expect (ge (my_actual_integral<T> (), my_expected_integral<signed int> ()))
      << "ge matches signed int";
  local_counts.successful_checks++;

  t.expect (
      ne (my_actual_integral_more<T> (), my_expected_integral<signed int> ()))
      << "ne matches signed int";
  local_counts.successful_checks++;

  t.expect (
      lt (my_actual_integral_less<T> (), my_expected_integral<signed int> ()))
      << "lt matches signed int";
  local_counts.successful_checks++;

  t.expect (
      gt (my_actual_integral_more<T> (), my_expected_integral<signed int> ()))
      << "gt matches signed int";
  local_counts.successful_checks++;

  // --------------------------------------------------------------------------

  t.expect (
      le (my_actual_integral<T> (), my_expected_integral<unsigned int> ()))
      << "le matches unsigned int";
  local_counts.successful_checks++;

  t.expect (
      ge (my_actual_integral<T> (), my_expected_integral<unsigned int> ()))
      << "ge matches unsigned int";
  local_counts.successful_checks++;

  t.expect (ne (my_actual_integral_more<T> (),
                my_expected_integral<unsigned int> ()))
      << "ne matches unsigned int";
  local_counts.successful_checks++;

  t.expect (lt (my_actual_integral_less<T> (),
                my_expected_integral<unsigned int> ()))
      << "lt matches unsigned int";
  local_counts.successful_checks++;

  t.expect (gt (my_actual_integral_more<T> (),
                my_expected_integral<unsigned int> ()))
      << "gt matches unsigned int";
  local_counts.successful_checks++;

  local_counts.executed_subtest++;
}

// ----------------------------------------------------------------------------

static static_suite ts_passed_integral{ "Combinatorial integrals suite", tr,
                                        [] (auto& ts)
  {
    detail::runner_totals& current_suite_totals = ts.totals ();

    local_counts = {};

    ts.test ("Combinatorial integrals with signed long long",
             test_case_expect_integrals_passed_combinations<signed long long>);

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test (
        "Combinatorial integrals unsigned long long",
        test_case_expect_integrals_passed_combinations<unsigned long long>);

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Combinatorial integrals with signed int",
             test_case_expect_integrals_passed_combinations<signed int>);

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Combinatorial integrals with unsigned int",
             test_case_expect_integrals_passed_combinations<unsigned int>);

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Combinatorial integrals with signed short",
             test_case_expect_integrals_passed_combinations<signed short>);

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Combinatorial integrals with unsigned short",
             test_case_expect_integrals_passed_combinations<unsigned short>);

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Combinatorial integrals with signed char",
             test_case_expect_integrals_passed_combinations<signed char>);

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);

    ts.test ("Combinatorial integrals with unsigned char",
             test_case_expect_integrals_passed_combinations<unsigned char>);

    test_assert (current_suite_totals.successful_checks ()
                 == local_counts.successful_checks);
    test_assert (current_suite_totals.failed_checks ()
                 == local_counts.failed_checks);
    test_assert (current_suite_totals.executed_subtests ()
                 == local_counts.executed_subtest);
  } };

// ----------------------------------------------------------------------------

/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 */

// ----------------------------------------------------------------------------

// #include <micro-os-plus/config.h> in micro-test-plus.h
#include <micro-os-plus/micro-test-plus.h>

#include <cassert>
#include <cstring>
#include <stdio.h>

using namespace micro_os_plus;

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif

// ----------------------------------------------------------------------------

// Each test case exercises a method or a family of methods.
// After each test case, the caller checks if the counts of
// passed/failed test cases matches the local counts.

static struct local_counts_s
{
  int test_cases;
  int passed;
  int failed;
} local_counts;

static void
test_case_pass (micro_test_plus::session& t)
{
  t.pass ("it passed");
  local_counts.passed++;

  MTP_PASS (t, "it passed with macro");
  local_counts.passed++;

  local_counts.test_cases++;
}

static void
test_case_fail (micro_test_plus::session& t)
{
  t.fail ("it failed");
  local_counts.failed++;

  MTP_FAIL (t, "it failed with macro");
  local_counts.failed++;

  local_counts.test_cases++;
}

static void
test_case_expect_true (micro_test_plus::session& t)
{
  t.expect_true (true, "true passed");
  local_counts.passed++;

  t.expect_true (false, "false failed");
  local_counts.failed++;

  MTP_EXPECT_TRUE (t, false, "false with macro failed");
  local_counts.failed++;

  local_counts.test_cases++;
}

template <typename T>
T
my_actual_integral (void)
{
  return 42;
}

template <typename T>
T
my_expected_integral (void)
{
  return 42;
}

static void
test_case_expect_eq_integrals (micro_test_plus::session& t)
{
  t.expect_equal (1, 1, "1 == 1");
  local_counts.passed++;

  t.expect_equal (2, 1, "2 != 1");
  local_counts.failed++;

  MTP_EXPECT_EQUAL (t, 2, 1, "2 != 1 with macro");
  local_counts.failed++;

  t.expect_equal (1L, 1L, "1L == 1L");
  local_counts.passed++;

  t.expect_equal (2L, 1L, "2L != 1L");
  local_counts.failed++;

  MTP_EXPECT_EQUAL (t, 2L, 1L, "2L != 1L with macro");
  local_counts.failed++;

  local_counts.test_cases++;
}

template <typename T>
static void
test_case_expect_eq_integrals_combinatoric (micro_test_plus::session& t)
{

  t.expect_equal (my_actual_integral<T> (),
                  my_expected_integral<signed long long> (),
                  "matches signed long long");
  local_counts.passed++;

  t.expect_equal (my_actual_integral<T> (),
                  my_expected_integral<unsigned long long> (),
                  "matches unsigned long long");
  local_counts.passed++;

  t.expect_equal (my_actual_integral<T> (),
                  my_expected_integral<signed long> (), "matches signed long");
  local_counts.passed++;

  t.expect_equal (my_actual_integral<T> (),
                  my_expected_integral<unsigned long> (),
                  "matches unsigned long");
  local_counts.passed++;

  t.expect_equal (my_actual_integral<T> (),
                  my_expected_integral<signed int> (), "matches signed int");
  local_counts.passed++;

  t.expect_equal (my_actual_integral<T> (),
                  my_expected_integral<unsigned int> (),
                  "matches unsigned int");
  local_counts.passed++;

  t.expect_equal (my_actual_integral<T> (),
                  my_expected_integral<signed short> (),
                  "matches signed short");
  local_counts.passed++;

  t.expect_equal (my_actual_integral<T> (),
                  my_expected_integral<unsigned short> (),
                  "matches unsigned short");
  local_counts.passed++;

  t.expect_equal (my_actual_integral<T> (),
                  my_expected_integral<signed char> (), "matches signed char");
  local_counts.passed++;

  t.expect_equal (my_actual_integral<T> (),
                  my_expected_integral<unsigned char> (),
                  "matches unsigned char");
  local_counts.passed++;

  local_counts.test_cases++;
}

static void
a_func (void)
{
}

static void
test_case_expect_eq_pointers (micro_test_plus::session& t)
{
  void* a_nullptr = nullptr;

  t.expect_equal (a_nullptr, nullptr, "a_nullptr == nullptr");
  local_counts.passed++;

  void* a_non_nullptr = &a_nullptr;

  t.expect_equal (a_non_nullptr, nullptr, "a_non_nullptr != nullptr");
  local_counts.failed++;

  MTP_EXPECT_EQUAL (t, a_non_nullptr, nullptr,
                    "a_non_nullptr != nullptr with macro");
  local_counts.failed++;

  void (*pfunc) (void) = nullptr;
  t.expect_equal (pfunc, nullptr, "pfunc == nullptr");
  local_counts.passed++;

  pfunc = a_func;
  t.expect_equal (pfunc, nullptr, "pfunc != nullptr");
  local_counts.failed++;

  int one = 1;
  int* ptr1 = &one;
  int* ptr2 = &one;

  t.expect_equal (ptr1, &one, "ptr1 == &one");
  local_counts.passed++;

  t.expect_equal (ptr1, ptr2, "ptr1 == ptr2");
  local_counts.passed++;

  t.expect_equal (ptr1, a_non_nullptr, "ptr1 != a_non_nullptr");
  local_counts.failed++;

  t.expect_equal (pfunc, a_func, "pfunc == afunc");
  local_counts.passed++;

  t.expect_equal (pfunc, a_non_nullptr, "pfunc != a_non_nullptr");
  local_counts.failed++;

  t.expect_equal (pfunc, &local_counts, "pfunc != &local_counts");
  local_counts.failed++;

  local_counts.test_cases++;
}

static void
test_case_expect_eq_strings (micro_test_plus::session& t)
{
  t.expect_equal ("aaa", "aaa", "'aaa' == 'aaa'");
  local_counts.passed++;

  t.expect_equal ("aab", "aaa", "'aab' != 'aaa'");
  local_counts.failed++;

  MTP_EXPECT_EQUAL (t, "aac", "aaa", "'aac' != 'aaa'");
  local_counts.failed++;

  char str[10];
  strcpy (str, "aaa");
  t.expect_equal (str, "aaa", "str == 'aaa' with aaa");
  local_counts.passed++;

  strcpy (str, "aac");
  t.expect_equal (str, "aaa", "str == 'aaa' with aac");
  local_counts.failed++;

  MTP_EXPECT_EQUAL (t, str, "aaa", "str == 'aaa' with aac");
  local_counts.failed++;

  local_counts.test_cases++;
}

template <typename T>
T
my_actual_float (void)
{
  return 42.0;
}

template <typename T>
T
my_expected_float (void)
{
  return 42.0;
}

template <typename T>
static void
test_case_expect_eq_floats_combinatoric (micro_test_plus::session& t)
{
  t.expect_equal (my_actual_float<T> (),
                  my_expected_integral<signed long long> (),
                  "42.0 == 42 signed long long");
  local_counts.passed++;

  t.expect_equal (my_actual_float<T> (),
                  my_expected_integral<unsigned long long> (),
                  "42.0 == 42 unsigned long long");
  local_counts.passed++;

  t.expect_equal (my_actual_float<T> (), my_expected_integral<signed long> (),
                  "42.0 == 42 signed long");
  local_counts.passed++;

  t.expect_equal (my_actual_float<T> (),
                  my_expected_integral<unsigned long> (),
                  "42.0 == 42 unsigned long");
  local_counts.passed++;

  t.expect_equal (my_actual_float<T> (), my_expected_integral<signed int> (),
                  "42.0 == 42 signed int");
  local_counts.passed++;

  t.expect_equal (my_actual_float<T> (), my_expected_integral<unsigned int> (),
                  "42.0 == 42 unsigned int");
  local_counts.passed++;

  t.expect_equal (my_actual_float<T> (), my_expected_integral<signed short> (),
                  "42.0 == 42 signed short");
  local_counts.passed++;

  t.expect_equal (my_actual_float<T> (),
                  my_expected_integral<unsigned short> (),
                  "42.0 == 42 unsigned short");
  local_counts.passed++;

  t.expect_equal (my_actual_float<T> (), my_expected_integral<signed char> (),
                  "42.0 == 42 signed char");
  local_counts.passed++;

  t.expect_equal (my_actual_float<T> (),
                  my_expected_integral<unsigned char> (),
                  "42.0 == 42 unsigned char");
  local_counts.passed++;

  t.expect_equal (42, my_expected_float<T> (), "42 == 42.0");
  local_counts.passed++;

  local_counts.test_cases++;
}

static void
test_case_check_floats (micro_test_plus::session& t)
{
  t.expect_equal (my_actual_float<float> (), my_expected_float<float> (),
                  "both floats");
  local_counts.failed++;

  t.expect_equal (my_actual_float<float> (), my_expected_float<double> (),
                  "float and double");
  local_counts.failed++;

  t.expect_equal (my_actual_float<double> (), my_expected_float<float> (),
                  "both doubles");
  local_counts.failed++;

  t.expect_equal (my_actual_float<double> (), my_expected_float<double> (),
                  "fail with double and float");
  local_counts.failed++;

  local_counts.test_cases++;
}

static void
test_case_check_non_scalar (micro_test_plus::session& t)
{
  MTP_EXPECT_EQUAL (t, local_counts, nullptr, "non-scalar T");
  local_counts.failed++;

  MTP_EXPECT_EQUAL (t, nullptr, local_counts, "non-scalar U");
  local_counts.failed++;

  local_counts.test_cases++;
}
// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  micro_test_plus::session t (argc, argv);

  printf ("\nµTest++ self test started\n");

  t.start_suite ("Inner test, expected to fail in various ways,");

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case ("Check if t.pass() always succeeds", test_case_pass);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case ("Check if t.fail() always fails", test_case_fail);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case ("Check t.expect_true(condition)", test_case_expect_true);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case ("Check t.expect_equal(actual, expected) with integers",
                   test_case_expect_eq_integrals);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case (
      "Check t.expect_equal(actual, expected) with signed long long",
      test_case_expect_eq_integrals_combinatoric<signed long long>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case (
      "Check t.expect_equal(actual, expected) with unsigned long long",
      test_case_expect_eq_integrals_combinatoric<unsigned long long>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case ("Check t.expect_equal(actual, expected) with signed long",
                   test_case_expect_eq_integrals_combinatoric<signed long>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case ("Check t.expect_equal(actual, expected) with unsigned long",
                   test_case_expect_eq_integrals_combinatoric<unsigned long>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case ("Check t.expect_equal(actual, expected) with signed int",
                   test_case_expect_eq_integrals_combinatoric<signed int>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case ("Check t.expect_equal(actual, expected) with unsigned int",
                   test_case_expect_eq_integrals_combinatoric<unsigned int>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case ("Check t.expect_equal(actual, expected) with signed short",
                   test_case_expect_eq_integrals_combinatoric<signed short>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case (
      "Check t.expect_equal(actual, expected) with unsigned short",
      test_case_expect_eq_integrals_combinatoric<unsigned short>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case ("Check t.expect_equal(actual, expected) with signed char",
                   test_case_expect_eq_integrals_combinatoric<signed char>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case ("Check t.expect_equal(actual, expected) with unsigned char",
                   test_case_expect_eq_integrals_combinatoric<unsigned char>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case ("Check t.expect_equal(actual, expected) with pointers",
                   test_case_expect_eq_pointers);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case ("Check t.expect_equal(actual, expected) with strings",
                   test_case_expect_eq_strings);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case (
      "Check t.expect_equal(actual, expected) with float and integrals",
      test_case_expect_eq_floats_combinatoric<float>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case (
      "Check t.expect_equal(actual, expected) with double and integrals",
      test_case_expect_eq_floats_combinatoric<double>);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  t.run_test_case ("Check t.expect_equal(actual, expected) with floats",
                   test_case_check_floats);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case ("Check if non-scalar parameters fail",
                   test_case_check_non_scalar);

  assert (t.passed () == local_counts.passed);
  assert (t.failed () == local_counts.failed);
  assert (t.test_cases () == local_counts.test_cases);

  // --------------------------------------------------------------------------

  // The inner test should return failure.
  assert (t.result () != 0);

  // On failure it aborts before reaching this point.
  printf ("\nµTest++ self test passed\n");

  return 0;
}

// ----------------------------------------------------------------------------

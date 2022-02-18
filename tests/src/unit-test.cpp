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

// ----------------------------------------------------------------------------

void
test_case_pass (micro_test_plus::session& t);

void
test_case_fail (micro_test_plus::session& t);

void
test_case_expect_true (micro_test_plus::session& t);

void
test_case_expect_eq (micro_test_plus::session& t);

void
test_case_expect_eq_strings (micro_test_plus::session& t);

void
test_case_check_non_scalar (micro_test_plus::session& t);

// ----------------------------------------------------------------------------

static struct
{
  int test_cases;
  int passed;
  int failed;
} my;

// Each test case exercises a method or a family of methods.
// After each test case, the caller checks the counts of
// passed/failed test cases.

void
test_case_pass (micro_test_plus::session& t)
{
  t.pass ("it passed");
  my.passed++;

  MTP_PASS (t, "it passed with macro");
  my.passed++;

  my.test_cases++;
}

void
test_case_fail (micro_test_plus::session& t)
{
  t.fail ("it failed");
  my.failed++;

  MTP_FAIL (t, "it failed with macro");
  my.failed++;

  my.test_cases++;
}

void
test_case_expect_true (micro_test_plus::session& t)
{
  t.expect_true (true, "true passed");
  my.passed++;

  t.expect_true (false, "false failed");
  my.failed++;

  MTP_EXPECT_TRUE (t, false, "false with macro failed");
  my.failed++;

  my.test_cases++;
}

void
test_case_expect_eq (micro_test_plus::session& t)
{
  t.expect_eq (1, 1, "1 == 1");
  my.passed++;

  t.expect_eq (2, 1, "2 != 1");
  my.failed++;

  MTP_EXPECT_EQ (t, 2, 1, "2 != 1 with macro");
  my.failed++;

  t.expect_eq (1L, 1L, "1L == 1L");
  my.passed++;

  t.expect_eq (2L, 1L, "2L != 1L");
  my.failed++;

  MTP_EXPECT_EQ (t, 2L, 1L, "2L != 1L with macro");
  my.failed++;

  my.test_cases++;
}

void
test_case_expect_eq_strings (micro_test_plus::session& t)
{
  t.expect_eq ("aaa", "aaa", "'aaa' == 'aaa'");
  my.passed++;

  t.expect_eq ("aab", "aaa", "'aab' != 'aaa'");
  my.failed++;

  MTP_EXPECT_EQ (t, "aac", "aaa", "'aac' != 'aaa'");
  my.failed++;

  char str[10];
  strcpy (str, "aaa");
  t.expect_eq (str, "aaa", "str == 'aaa' with aaa");
  my.passed++;

  strcpy (str, "aac");
  t.expect_eq (str, "aaa", "str == 'aaa' with aac");
  my.failed++;

  MTP_EXPECT_EQ (t, str, "aaa", "str == 'aaa' with aac");
  my.failed++;

  my.test_cases++;
}

void
test_case_check_non_scalar (micro_test_plus::session& t)
{

#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

  MTP_EXPECT_EQ (t, my, nullptr, "non-scalar T");
  my.failed++;

  MTP_EXPECT_EQ (t, nullptr, my, "non-scalar U");
  my.failed++;

#pragma GCC diagnostic pop

  my.test_cases++;
}
// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  micro_test_plus::session t (argc, argv);

  printf ("\nµTest++ self test started\n");

  t.start_suite ("Inner test, expected to fail in various ways,");

  assert (t.passed () == my.passed);
  assert (t.failed () == my.failed);
  assert (t.test_cases () == my.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_pass, "Check if t.pass() always succeeds");

  assert (t.passed () == my.passed);
  assert (t.failed () == my.failed);
  assert (t.test_cases () == my.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_fail, "Check if t.fail() always fails");

  assert (t.passed () == my.passed);
  assert (t.failed () == my.failed);
  assert (t.test_cases () == my.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_expect_true, "Check t.expect_true(condition)");

  assert (t.passed () == my.passed);
  assert (t.failed () == my.failed);
  assert (t.test_cases () == my.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_expect_eq,
                   "Check t.expect_eq(actual, expected) with integers");

  assert (t.passed () == my.passed);
  assert (t.failed () == my.failed);
  assert (t.test_cases () == my.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_expect_eq_strings,
                   "Check t.expect_eq(actual, expected) with strings");

  assert (t.passed () == my.passed);
  assert (t.failed () == my.failed);
  assert (t.test_cases () == my.test_cases);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_check_non_scalar,
                   "Check if non-scalar parameters fail");

  assert (t.passed () == my.passed);
  assert (t.failed () == my.failed);
  assert (t.test_cases () == my.test_cases);

  // --------------------------------------------------------------------------

  // The inner test should return failure.
  assert (t.result () != 0);

  // On failure it aborts before reaching this point.
  printf ("\nµTest++ self test passed\n");

  return 0;
}

// ----------------------------------------------------------------------------

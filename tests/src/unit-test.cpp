/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <micro-os-plus/micro-test-plus.h>

#include <cassert>
#include <stdio.h>

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

// Each test case exercises a method or a family of methods.
// After each test case, the caller checks the counts of
// passed/failed test cases.

void
test_case_pass (micro_test_plus::session& t)
{
  t.pass ("it passed");
  MTP_PASS (t, "it passed with macro");
}

void
test_case_fail (micro_test_plus::session& t)
{
  t.fail ("it failed");
  MTP_FAIL (t, "it failed with macro");
}

void
test_case_expect_true (micro_test_plus::session& t)
{
  t.expect_true (true, "true passed");
  t.expect_true (false, "false failed");
  MTP_EXPECT_TRUE (t, false, "false with macro failed");
}

void
test_case_expect_eq (micro_test_plus::session& t)
{
  t.expect_eq (1, 1, "1 == 1");
  t.expect_eq (2, 1, "2 != 1");
  MTP_EXPECT_EQ (t, 2, 1, "2 != 1 with macro");

  t.expect_eq (1L, 1L, "1L == 1L");
  t.expect_eq (2L, 1L, "2L != 1L");
  MTP_EXPECT_EQ (t, 2L, 1L, "2L != 1L with macro");
}

void
test_case_expect_eq_strings (micro_test_plus::session& t)
{
  t.expect_eq ("aaa", "aaa", "'aaa' == 'aaa'");
  t.expect_eq ("aab", "aaa", "'aab' != 'aaa'");
  MTP_EXPECT_EQ (t, "aac", "aaa", "'aac' != 'aaa'");

  char* str = (char*)"aaa";
  t.expect_eq (str, "aaa", "str == 'aaa' with aaa");
  str = (char*)"aac";
  t.expect_eq (str, "aaa", "str == 'aaa' with aac");
  MTP_EXPECT_EQ (t, str, "aaa", "str == 'aaa' with aac");
}

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  micro_test_plus::session t (argc, argv);

  printf ("\nµTest++ self test started\n");

  t.start_suite ("Inner test, expected to fail in various ways,");

  assert (t.passed () == 0);
  assert (t.failed () == 0);
  assert (t.test_cases () == 0);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_pass, "Check if t.pass() always succeeds");

  assert (t.passed () == 2);
  assert (t.failed () == 0);
  assert (t.test_cases () == 1);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_fail, "Check if t.fail() always fails");

  assert (t.passed () == 2);
  assert (t.failed () == 2);
  assert (t.test_cases () == 2);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_expect_true, "Check t.expect_true(condition)");

  assert (t.passed () == 3);
  assert (t.failed () == 4);
  assert (t.test_cases () == 3);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_expect_eq,
                   "Check t.expect_eq(actual, expected) with integers");

  assert (t.passed () == 5);
  assert (t.failed () == 8);
  assert (t.test_cases () == 4);

  // --------------------------------------------------------------------------

  t.run_test_case (test_case_expect_eq_strings,
                   "Check t.expect_eq(actual, expected) with strings");

  assert (t.passed () == 7);
  assert (t.failed () == 12);
  assert (t.test_cases () == 5);

  // --------------------------------------------------------------------------

  // The inner test should return failure.
  assert (t.result () != 0);

  // On failure it aborts before reaching this point.
  printf ("\nµTest++ self test passed\n");

  return 0;
}

// ----------------------------------------------------------------------------

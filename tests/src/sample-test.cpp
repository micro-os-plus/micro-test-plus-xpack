/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

// Forward definitions of the test cases.
void
test_case_something (micro_test_plus::session& t);

void
test_case_parameterised (micro_test_plus::session& t, int n);

void
test_case_main_args (micro_test_plus::session& t, int argc, char* argv[]);

#if defined(__EXCEPTIONS)

void
test_case_exception_thrown (micro_test_plus::session& t);

void
test_case_exception_not_thrown (micro_test_plus::session& t);

#endif // defined(__EXCEPTIONS)

int
compute_one (void);

const char*
compute_aaa (void);

bool
compute_condition (void);

#if defined(__EXCEPTIONS)

void
exercise_throw (bool mustThrow);

#endif // defined(__EXCEPTIONS)

// ----------------------------------------------------------------------------

// The test suite.
int
main (int argc, char* argv[])
{
  micro_test_plus::session t (argc, argv);

  t.start_suite ("Sample test");

  t.run_test_case ("Check various conditions", test_case_something);

  t.run_test_case ("Check parameterised", test_case_parameterised, 42);

  t.run_test_case ("Check args", test_case_main_args, argc, argv);

#if defined(__EXCEPTIONS)

  t.run_test_case ("Check if exceptions are thrown",
                   test_case_exception_thrown);

  t.run_test_case ("Check if exceptions are not thrown",
                   test_case_exception_not_thrown);

#endif // defined(__EXCEPTIONS)

  return t.result ();
}

// ----------------------------------------------------------------------------

// Simple examples of functions to be tested.
int
compute_one (void)
{
  return 1;
}

const char*
compute_aaa (void)
{
  return "aaa";
}

bool
compute_condition (void)
{
  return true;
}

#if defined(__EXCEPTIONS)

void
exercise_throw (bool mustThrow)
{
  if (mustThrow)
    {
      throw "kaboom";
    }
}

#endif // defined(__EXCEPTIONS)

// ----------------------------------------------------------------------------

// Test equality or logical conditions.
void
test_case_something (micro_test_plus::session& t)
{
  // Currently only int and long values can be compared.
  // For everything else use casts.
  MTP_EXPECT_EQUAL (t, compute_one (), 1, "compute_one() == 1");

  // Strings can also be compared (via `strcmp()`).
  MTP_EXPECT_EQUAL (t, compute_aaa (), "aaa", "compute_aaa() == 'aaa'");

  // More complex conditions are passed as booleans.
  MTP_EXPECT_TRUE (t, compute_condition (), "condition() is true");
}

void
test_case_parameterised (micro_test_plus::session& t, int n)
{
  MTP_EXPECT_EQUAL (t, n, 42, "parameter is 42");
}

void
test_case_main_args (micro_test_plus::session& t, int argc, char* argv[])
{
  MTP_EXPECT_EQUAL (t, argc, 3, "argc == 3");

  if (argc > 1)
    {
      MTP_EXPECT_EQUAL (t, argv[1], "one", "argv[1] == 'one'");
    }

  if (argc > 2)
    {
      MTP_EXPECT_EQUAL (t, argv[2], "two", "argv[2] == 'two'");
    }
}

// ----------------------------------------------------------------------------

#if defined(__EXCEPTIONS)

// Test is something throws exceptions.
void
test_case_exception_thrown (micro_test_plus::session& t)
{
  try
    {
      // Do something that throws.
      exercise_throw (true);

      // If we reached here, the exception was not thrown.
      MTP_FAIL (t, "exception not thrown");
    }
  catch (...)
    {
      // Got it.
      MTP_PASS (t, "exception thrown");
    }
}

void
test_case_exception_not_thrown (micro_test_plus::session& t)
{
  try
    {
      // Do something that may throw, but it doesn't.
      exercise_throw (false);

      // If we reached here, everything is fine.
      MTP_PASS (t, "exception not thrown");
    }
  catch (...)
    {
      MTP_FAIL (t, "exception thrown");
    }
}

#endif // defined(__EXCEPTIONS)

// ----------------------------------------------------------------------------

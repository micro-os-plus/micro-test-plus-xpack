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

#pragma GCC diagnostic ignored "-Wc++98-compat"
#pragma GCC diagnostic ignored "-Wshadow-uncaptured-local"

// ----------------------------------------------------------------------------

// Simple examples of functions to be tested.
static int
compute_one (void)
{
  return 1;
}

static const char*
compute_aaa (void)
{
  return "aaa";
}

static bool
compute_condition (void)
{
  return true;
}

#if defined(__EXCEPTIONS)

static void
exercise_throw (bool mustThrow)
{
  if (mustThrow)
    {
      throw "kaboom";
    }
}

#endif // defined(__EXCEPTIONS)

// ----------------------------------------------------------------------------

// The test suite.
int
main (int argc, char* argv[])
{
  micro_test_plus::init (argc, argv);

  micro_test_plus::start_suite ("Sample test");

  // --------------------------------------------------------------------------

  // Test equality or logical conditions.
  micro_test_plus::test_case ("Check various conditions", [] {
    // Currently only int and long values can be compared.
    // For everything else use casts.
    micro_test_plus::expect_equal (compute_one (), 1, "compute_one() == 1");

    // Strings can also be compared (via `strcmp()`).
    micro_test_plus::expect_equal (compute_aaa (), "aaa",
                                   "compute_aaa() == 'aaa'");

    // More complex conditions are passed as booleans.
    micro_test_plus::expect_true (compute_condition (), "condition() is true");

    auto f = [] (int i) { return i + 42; };

    micro_test_plus::expect_equal (f (1), 43, "lambda == 43");

    micro_test_plus::expect_true (f (2) == 44, "lambda == 44");
  });

  // --------------------------------------------------------------------------

  // Check main arguments.
  micro_test_plus::test_case (
      "Check args",
      [] (int argc, char* argv[]) {
        micro_test_plus::expect_equal (argc, 3, "argc == 3");

        if (argc > 1)
          {
            micro_test_plus::expect_equal (argv[1], "one", "argv[1] == 'one'");
          }

        if (argc > 2)
          {
            micro_test_plus::expect_equal (argv[2], "two", "argv[2] == 'two'");
          }
      },
      argc, argv);

  // --------------------------------------------------------------------------

#if defined(__EXCEPTIONS)

  micro_test_plus::test_case ("Check if exceptions are thrown", [] {
    try
      {
        // Do something that throws.
        exercise_throw (true);

        // If we reached here, the exception was not thrown.
        micro_test_plus::fail ("exception not thrown");
      }
    catch (...)
      {
        // Got it.
        micro_test_plus::pass ("exception thrown");
      }
  });

  micro_test_plus::test_case ("Check if exceptions are not thrown", [] {
    try
      {
        // Do something that may throw, but it doesn'runner.
        exercise_throw (false);

        // If we reached here, everything is fine.
        micro_test_plus::pass ("exception not thrown");
      }
    catch (...)
      {
        micro_test_plus::fail ("exception thrown");
      }
  });

#endif // defined(__EXCEPTIONS)

  // --------------------------------------------------------------------------

  return micro_test_plus::result ();
}

// ----------------------------------------------------------------------------

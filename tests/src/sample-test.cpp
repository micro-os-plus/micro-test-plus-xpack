/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

#include <string_view>
#include <stdexcept>

using namespace std::literals;

using namespace micro_os_plus;

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wshadow-uncaptured-local"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif

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
  // Construct it from parts, otherwise the compiler will coalesce strings
  // and comparing addresses will match.
  static char str[10];
  strcpy (str, "aa");
  strcat (str, "a");
  return str;
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
// Suite

using namespace micro_test_plus;

static test_suite ts = { "My test suite", [] {
                          test_case ("Check one", [] { pass ("Passed"); });
                          test_case ("Check two", [] { pass ("Passed"); });
                        } };

// ----------------------------------------------------------------------------

// The test suite.
int
main (int argc, char* argv[])
{
  initialize ("Sample Test", argc, argv);

  // --------------------------------------------------------------------------

  // Test equality or logical conditions.
  test_case ("Check various conditions", [] {
    pass ("Passed");
    // fail("Failed");

    // Currently only int and long values can be compared.
    // For everything else use casts.
    expect (eq (compute_one (), 1), "compute_one() == 1");

    // Strings can also be compared (via `strcmp()`).
    expect (eq (std::string_view{ compute_aaa () }, "aaa"sv),
            "compute_aaa() == 'aaa' string_view");

    // More complex conditions are passed as booleans.
    expect (compute_condition (), "condition() is true");

    auto f = [] (int i) { return i + 42; };

    expect (eq (f (1), 43), "lambda == 43");
  });

  // --------------------------------------------------------------------------

  // Check main arguments.
  test_case (
      "Check args",
      [] (int _argc, char* _argv[]) {
        expect (eq (_argc, 3), "argc == 3");

        if (_argc > 1)
          {
            expect (eq (std::string_view{ _argv[1] }, "one"sv),
                    "argv[1] == 'one'");
          }

        if (_argc > 2)
          {
            expect (eq (std::string_view{ _argv[2] }, "two"sv),
                    "argv[2] == 'two'");
          }
      },
      argc, argv);

  // --------------------------------------------------------------------------

#if defined(__EXCEPTIONS)

  test_case ("Check if exceptions are thrown", [] {
    expect (throws ([] { exercise_throw (true); }), "exception thrown");
    expect (
        throws<std::runtime_error> ([] { throw std::runtime_error{ "" }; }),
        "std::runtime_error thrown");
#if 0
    expect (throws<std::runtime_error> ([] { exercise_throw (true); }),
            "std::runtime_error thrown");
#endif
  });

  test_case ("Check if exceptions are not thrown", [] {
    expect (nothrow ([] { exercise_throw (false); }), "exception not thrown");
  });

#endif // defined(__EXCEPTIONS)

  // --------------------------------------------------------------------------

  return micro_test_plus::exit_code ();
}

// ----------------------------------------------------------------------------

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
#include <vector>

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
compute_answer (void)
{
  // The Answer to the Ultimate Question of Life,
  // the Universe and Everything is...
  return 42;
}

static const char*
compute_ultimate_answer (void)
{
  // Construct the result from parts, to be sure that the comparison
  // passes only when the content is checked; comparing pointers is not
  // reliable, plus that the compiler will coalesce strings and test
  // results will not be accurate.
  static char str[10];
  strcpy (str, "forty");
  strcat (str, "two");
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

int
main (int argc, char* argv[])
{
  using namespace micro_test_plus;

  // There is a default test suite automatically defined in main().
  initialize ("Sample", argc, argv);

  // --------------------------------------------------------------------------

  // Test comparison functions.
  test_case ("Check various conditions", [] {
    // There are functions with usual names for all comparisons.

    expect (eq (compute_answer (), 42)); // << "baburiba";
    expect (eq (compute_answer (), 42), "answer eq 42");
    expect (ne (compute_answer (), 43), "answer ne 43");
    expect (lt (compute_answer (), 43), "answer lt 43");
    expect (le (compute_answer (), 43), "answer le 42");
    expect (gt (compute_answer (), 41), "answer gt 43");
    expect (ge (compute_answer (), 42), "answer ge 42");

    // Boolean expressions can be checked directly.
    expect (compute_condition (), "condition is true");
  });

  test_case ("Check various conditions with operators", [] {
    // There are custom operators for all comparisons, but since
    // interferences with other operators are possible, they are
    // located in a separate namespace.
    // Even so, they require their operands to be typed, via literals
    // (like `1_i`) or casts (like `_i(expr)`).

    using namespace micro_test_plus::operators;
    using namespace micro_test_plus::literals;

    expect (compute_answer () == 42_i, "answer == 42 (with literal)");
    expect (_i (compute_answer ()) == 42, "answer == 42 (with cast)");
    expect (compute_answer () != 43_i, "answer != 43");
    expect (compute_answer () < 43_i, "answer < 43");
    expect (compute_answer () <= 43_i, "answer <= 42");
    expect (compute_answer () > 41_i, "answer > 43");
    expect (compute_answer () >= 42_i, "answer >= 42");

    // Note: if the operands are not typed, the test is still performed
    // correctly using the standard operators, as for any logical expression,
    // but in case of failures the actual values cannot be shown.
  });

  test_case ("Check strings", [] {
    // String can also be compared, but only as `string_view` objects,
    // otherwise the comparison is done on
    // the memory addresses, not on the content.

    expect (eq (std::string_view{ compute_ultimate_answer () }, "fortytwo"sv),
            "ultimate answer is 'fortytwo'");
  });

  test_case ("Check strings with operators", [] {
    // There are also custom == and != operators for `string_view` comparisons.

    using namespace micro_test_plus::operators;

    expect (std::string_view{ compute_ultimate_answer () } == "fortytwo"sv,
            "ultimate answer == 'fortytwo'");
  });

  test_case ("Check compound conditions", [] {
    // More complex conditions can be constructed with _and(), _or(), _not()
    // (the underscore is required to differentiate the functions from the
    // language and/or/not operators).

    expect (_and (eq (compute_answer (), 42),
                  eq (std::string_view{ compute_ultimate_answer () },
                      "fortytwo"sv)),
            "logical 'and' expression");
  });

  test_case ("Check compound conditions with operators", [] {
    // There are also operators for logical expressions.

    using namespace micro_test_plus::operators;
    using namespace micro_test_plus::literals;

    expect ((compute_answer () == 42_i)
                and (std::string_view{ compute_ultimate_answer () }
                     == "fortytwo"sv),
            "logical 'and' expression with operators");
  });

  // --------------------------------------------------------------------------

  test_case ("Check multiple function invocations", [] {
    // The function does not need to be embedded in the test case,
    // it can be defined separately and called multiple times.

    auto add = [] (int i) { return i + 40; };

    expect (eq (add (2), 42), "lambda returns 42");
    expect (eq (add (3), 43), "lambda returns 43");
  });

  // --------------------------------------------------------------------------

  // Test case with arguments.
  // The lambdas are special functions, which may be passed arguments
  // or may automatically capture variables from their local scope.
  test_case (
      "Check args",
      [] (int _argc, char* _argv[]) {
        expect (ge (_argc, 2), "argc >= 2");

        if (_argc > 1)
          {
            expect (eq (std::string_view{ _argv[1] }, "one"sv),
                    "argv[1] is 'one'");
          }

        if (_argc > 2)
          {
            expect (eq (std::string_view{ _argv[2] }, "two"sv),
                    "argv[2] is 'two'");
          }
      },
      // After the body there are the actual values to be passed
      // to the lambda.
      // An alternate solution is to capture them by value
      // since the lambda is also a closure.
      argc, argv);

  // --------------------------------------------------------------------------

  test_case ("Check complex logic", [] {
    // Complex conditions can be tested with explicit tests, and
    // the results passed to the test framework.

    bool xyz = true;
    if (xyz)
      {
        expect (true, "xyz passed");
      }
    else
      {
        expect (false, "xyz...");
      }
  });

  // --------------------------------------------------------------------------

#if defined(__EXCEPTIONS)

  test_case ("Check if exceptions are thrown", [] {
    expect (throws ([] { exercise_throw (true); }), "exception thrown");
    expect (
        throws<std::runtime_error> ([] { throw std::runtime_error{ "" }; }),
        "std::runtime_error thrown");
  });

  test_case ("Check if exceptions are not thrown", [] {
    expect (nothrow ([] { exercise_throw (false); }), "exception not thrown");
  });

#endif // defined(__EXCEPTIONS)

  test_case ("Check containers", [] {
    // Containers are iterated and each value compared with `eq()` or `ne()`.

    expect (eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }),
            "vector{ 1, 2 } eq vector{ 1, 2 }");

    expect (ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }),
            "vector{ 1, 2, 3 } ne vector{ 1, 2, 4 }");
  });

  test_case ("Check containers with operators", [] {
    // Containers are iterated and each value compared with `==` or `!=`.

    using namespace micro_test_plus::operators;

    expect (std::vector<int>{ 1, 2 } == std::vector<int>{ 1, 2 },
            "vector{ 1, 2 } == vector{ 1, 2 }");

    expect (std::vector<int>{ 1, 2, 3 } != std::vector<int>{ 1, 2, 4 },
            "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }");
  });

  // --------------------------------------------------------------------------

  // Trigger the execution of the separate test suites and
  // return the overall test result to the system.
  return exit_code ();
}

// ----------------------------------------------------------------------------
// Aditional test suites. They may be located in separate source files.

static micro_test_plus::test_suite ts_1
    = { "Separate", [] {
         using namespace micro_test_plus;

         test_case ("Check one", [] { expect (true, "Passed"); });
         test_case ("Check two", [] { expect (true, "Passed"); });
       } };

static micro_test_plus::test_suite ts_2
    = { "Explicit namespace", [] {
         // In case the application has functions that conflict with
         // the test framework names, use explicit names, possibly
         // shortned to a single letter.
         namespace t = micro_test_plus;

         t::test_case ("Check one", [] { t::expect (true, "Passed"); });
         t::test_case ("Check two", [] { t::expect (true, "Passed"); });
       } };

// ----------------------------------------------------------------------------

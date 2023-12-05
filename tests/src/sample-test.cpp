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

// ----------------------------------------------------------------------------

namespace mt = micro_os_plus::micro_test_plus;
using namespace std::literals;

// ----------------------------------------------------------------------------

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wshadow-uncaptured-local"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wctad-maybe-unsupported"
#pragma clang diagnostic ignored "-Wunknown-warning-option"
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
  // There is a default test suite automatically defined in main().
  mt::initialize (argc, argv, "Sample");

  // --------------------------------------------------------------------------

  // Test comparison functions.
  mt::test_case ("Check various conditions", [] {
    // There are functions with usual names for all comparisons.

    mt::expect (mt::eq (compute_answer (), 42)) << "answer eq 42";
    mt::expect (mt::ne (compute_answer (), 43)) << "answer ne 43";
    mt::expect (mt::lt (compute_answer (), 43)) << "answer lt 43";
    mt::expect (mt::le (compute_answer (), 43)) << "answer le 42";
    mt::expect (mt::gt (compute_answer (), 41)) << "answer gt 43";
    mt::expect (mt::ge (compute_answer (), 42)) << "answer ge 42";

    // Boolean expressions can be checked directly.
    mt::expect (compute_condition ()) << "condition is true";
  });

  mt::test_case ("Check various conditions with operators", [] {
    // There are custom operators for all comparisons, but since
    // interferences with other operators are possible, they are
    // located in a separate namespace.
    // Even so, they require their operands to be typed, via literals
    // (like `1_i`) or casts (like `mt::_i(expr)`).

    using namespace mt::operators;
    using namespace mt::literals;

    mt::expect (compute_answer () == 42_i) << "answer == 42 (with literal)";
    mt::expect (mt::_i (compute_answer ()) == 42)
        << "answer == 42 (with cast)";
    mt::expect (compute_answer () != 43_i) << "answer != 43";
    mt::expect (compute_answer () < 43_i) << "answer < 43";
    mt::expect (compute_answer () <= 43_i) << "answer <= 42";
    mt::expect (compute_answer () > 41_i) << "answer > 43";
    mt::expect (compute_answer () >= 42_i) << "answer >= 42";

    // Note: if the operands are not typed, the test is still performed
    // correctly using the standard operators, as for any logical expression,
    // but in case of failures the actual values cannot be shown.
  });

  mt::test_case ("Check strings", [] {
    // String can also be compared, but only as `string_view` objects,
    // otherwise the comparison is done on
    // the memory addresses, not on the content.

    mt::expect (
        mt::eq (std::string_view{ compute_ultimate_answer () }, "fortytwo"sv))
        << "ultimate answer is 'fortytwo'";
  });

  mt::test_case ("Check strings with operators", [] {
    // There are also custom == and != operators for `string_view` comparisons.

    using namespace mt::operators;

    mt::expect (std::string_view{ compute_ultimate_answer () } == "fortytwo"sv)
        << "ultimate answer == 'fortytwo'";
  });

  mt::test_case ("Check compound conditions", [] {
    // More complex conditions can be constructed with _and(), _or(), _not()
    // (the underscore is required to differentiate the functions from the
    // language and/or/not operators).

    mt::expect (mt::_and (
        mt::eq (compute_answer (), 42),
        mt::eq (std::string_view{ compute_ultimate_answer () }, "fortytwo"sv)))
        << "logical 'and' expression";
  });

  mt::test_case ("Check compound conditions with operators", [] {
    // There are also operators for logical expressions.

    using namespace mt::operators;
    using namespace mt::literals;

    mt::expect (
        (compute_answer () == 42_i)
        and (std::string_view{ compute_ultimate_answer () } == "fortytwo"sv))
        << "logical 'and' expression with operators";
  });

  // --------------------------------------------------------------------------

  mt::test_case ("Check multiple function invocations", [] {
    // The function does not need to be embedded in the test case,
    // it can be defined separately and called multiple times.

    auto add = [] (int i) { return i + 40; };

    mt::expect (mt::eq (add (2), 42)) << "lambda returns 42";
    mt::expect (mt::eq (add (3), 43)) << "lambda returns 43";
  });

  // --------------------------------------------------------------------------

  // Test case with arguments.
  // The lambdas are special functions, which may be passed arguments
  // or may automatically capture variables from their local scope.
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
  mt::test_case (
      "Check args",
      [] (int _argc, char* _argv[]) {
        mt::expect (mt::ge (_argc, 2)) << "argc >= 2";

        if (_argc > 1)
          {
            mt::expect (mt::eq (std::string_view{ _argv[1] }, "one"sv))
                << "argv[1] is 'one'";
          }

        if (_argc > 2)
          {
            mt::expect (mt::eq (std::string_view{ _argv[2] }, "two"sv))
                << "argv[2] is 'two'";
          }
      },
      // After the body there are the actual values to be passed
      // to the lambda.
      // An alternate solution is to capture them by value
      // since the lambda is also a closure.
      argc, argv);
#pragma GCC diagnostic pop

  // --------------------------------------------------------------------------

  mt::test_case ("Check complex logic", [] {
    // Complex conditions can be tested with explicit tests, and
    // the results passed to the test framework.

    bool xyz = true;
    if (xyz)
      {
        mt::expect (true) << "xyz passed";
      }
    else
      {
        mt::expect (false) << "xyz...";
      }
  });

  // --------------------------------------------------------------------------

#if defined(__EXCEPTIONS)

  mt::test_case ("Check if exceptions are thrown", [] {
    mt::expect (mt::throws ([] { exercise_throw (true); }))
        << "exception thrown";
    mt::expect (mt::throws<std::runtime_error> ([] {
      throw std::runtime_error{ "" };
    })) << "std::runtime_error thrown";
  });

  mt::test_case ("Check if exceptions are not thrown", [] {
    mt::expect (mt::nothrow ([] { exercise_throw (false); }))
        << "exception not thrown";
  });

#endif // defined(__EXCEPTIONS)

  mt::test_case ("Check containers", [] {
    // Containers are iterated and each value compared with `eq()` or `ne()`.

    mt::expect (mt::eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
        << "vector{ 1, 2 } eq vector{ 1, 2 }";

    mt::expect (
        mt::ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
        << "vector{ 1, 2, 3 } ne vector{ 1, 2, 4 }";
  });

  mt::test_case ("Check containers with operators", [] {
    // Containers are iterated and each value compared with `==` or `!=`.

    using namespace mt::operators;

    mt::expect (std::vector<int>{ 1, 2 } == std::vector<int>{ 1, 2 })
        << "vector{ 1, 2 } == vector{ 1, 2 }";

    mt::expect (std::vector<int>{ 1, 2, 3 } != std::vector<int>{ 1, 2, 4 })
        << "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }";
  });

  // --------------------------------------------------------------------------

  // Trigger the execution of the separate test suites and
  // return the overall test result to the system.
  return mt::exit_code ();
}

// ----------------------------------------------------------------------------
// Additional test suites. They may be located in separate source files.

static mt::test_suite ts_explicit
    = { "Explicit namespace", [] {
         mt::test_case ("Check one", [] { mt::expect (true) << "Passed"; });
         mt::test_case ("Check two", [] { mt::expect (true) << "Passed"; });
       } };

static micro_os_plus::micro_test_plus::test_suite ts_separate
    = { "Implicit namespace", [] {
         // For applications known to not conflict with the test
         // framework names, it is possible to access the definitions
         // directly, by including all namespace definitions.
         using namespace micro_os_plus::micro_test_plus;

         test_case ("Check one", [] { expect (true) << "Passed"; });
         test_case ("Check two", [] { expect (true) << "Passed"; });
       } };

// ----------------------------------------------------------------------------

// Parametrized test suite, with constants, values, references and pointers.
static void
test_suite_args (int ic, int iv, int& ir, int* ip1, int* ip2)
{
  mt::test_case ("args", [&] {
    mt::expect (mt::eq (ic, 42)) << "ic is 42";
    mt::expect (mt::eq (iv, 43)) << "iv is 43";
    mt::expect (mt::eq (ir, 44)) << "ir is 44";
    mt::expect (mt::eq (*ip1, 45)) << "*ip1 is 45";
    mt::expect (mt::eq (*ip2, 46)) << "*ip2 is 46";
  });
}

static int in = 43;
static int in44 = 44;
static int& ir = in44;
static int in45 = 45;
static int in46 = 46;
static int* ip2 = &in46;

static mt::test_suite ts_args
    = { "Args", test_suite_args, 42, in, ir, &in45, ip2 };

// ----------------------------------------------------------------------------

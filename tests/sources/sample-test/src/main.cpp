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

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

#include <string_view>
#include <stdexcept>
#include <vector>

// ----------------------------------------------------------------------------

namespace mt2 = micro_os_plus::micro_test_plus2;
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
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
  strcpy (str, "forty");
  strcat (str, "two");
#pragma GCC diagnostic pop
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

static mt2::static_test_runner tr ("Sample");

int
main (int argc, char* argv[])
{
  // There is a default test suite automatically defined in main().
  auto& ts = tr.initialise (argc, argv);

  // --------------------------------------------------------------------------

  // Test comparison functions.
  ts.test_case ("Check various conditions", [] (auto& tc)
    {
      // There are functions with usual names for all comparisons.

      tc.expect (mt2::eq (compute_answer (), 42)) << "answer eq 42";
      tc.expect (mt2::ne (compute_answer (), 43)) << "answer ne 43";
      tc.expect (mt2::lt (compute_answer (), 43)) << "answer lt 43";
      tc.expect (mt2::le (compute_answer (), 43)) << "answer le 42";
      tc.expect (mt2::gt (compute_answer (), 41)) << "answer gt 43";
      tc.expect (mt2::ge (compute_answer (), 42)) << "answer ge 42";

      // Boolean expressions can be checked directly.
      tc.expect (compute_condition ()) << "condition is true";
    });

  ts.test_case ("Check various conditions with operators", [] (auto& tc)
    {
      // There are custom operators for all comparisons, but
      // since interferences with other operators are possible,
      // they are located in a separate namespace. Even so, they
      // require their operands to be typed, via literals (like
      // `1_i`) or casts (like `mt2::to_i(expr)`).

      using namespace mt2::operators;
      using namespace mt2::literals;

      tc.expect (compute_answer () == 42_i) << "answer == 42 (with literal)";
      tc.expect (mt2::to_i (compute_answer ()) == 42)
          << "answer == 42 (with cast)";
      tc.expect (compute_answer () != 43_i) << "answer != 43";
      tc.expect (compute_answer () < 43_i) << "answer < 43";
      tc.expect (compute_answer () <= 43_i) << "answer <= 42";
      tc.expect (compute_answer () > 41_i) << "answer > 43";
      tc.expect (compute_answer () >= 42_i) << "answer >= 42";

      // Note: if the operands are not typed, the test is still
      // performed correctly using the standard operators, as
      // for any logical expression, but in case of failures the
      // actual values cannot be shown.
    });

  ts.test_case ("Check strings", [] (auto& tc)
    {
      // String can also be compared, but only as `string_view` objects,
      // otherwise the comparison is done on
      // the memory addresses, not on the content.

      tc.expect (mt2::eq (std::string_view{ compute_ultimate_answer () },
                          "fortytwo"sv))
          << "ultimate answer is 'fortytwo'";
    });

  ts.test_case ("Check strings with operators", [] (auto& tc)
    {
      // There are also custom == and != operators for
      // `string_view` comparisons.

      using namespace mt2::operators;

      tc.expect (std::string_view{ compute_ultimate_answer () }
                 == "fortytwo"sv)
          << "ultimate answer == 'fortytwo'";
    });

  ts.test_case ("Check compound conditions", [] (auto& tc)
    {
      // More complex conditions can be constructed with _and(), _or(),
      // _not() (the underscore is required to differentiate the functions
      // from the language and/or/not operators).

      tc.expect (
          mt2::_and (mt2::eq (compute_answer (), 42),
                     mt2::eq (std::string_view{ compute_ultimate_answer () },
                              "fortytwo"sv)))
          << "logical 'and' expression";
    });

  ts.test_case ("Check compound conditions with operators", [] (auto& tc)
    {
      // There are also operators for logical expressions.

      using namespace mt2::operators;
      using namespace mt2::literals;

      tc.expect (
          (compute_answer () == 42_i)
          and (std::string_view{ compute_ultimate_answer () } == "fortytwo"sv))
          << "logical 'and' expression with operators";
    });

  // --------------------------------------------------------------------------

  ts.test_case ("Check multiple function invocations", [] (auto& tc)
    {
      // The function does not need to be embedded in the test
      // case, it can be defined separately and called multiple
      // times.

      auto add = [] (int i) { return i + 40; };

      tc.expect (mt2::eq (add (2), 42)) << "lambda returns 42";
      tc.expect (mt2::eq (add (3), 43)) << "lambda returns 43";
    });

  // --------------------------------------------------------------------------

  // Test case with arguments.
  // The lambdas are special functions, which may be passed arguments
  // or may automatically capture variables from their local scope.
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
  ts.test_case ("Check args", [] (auto& tc, int _argc, char* _argv[])
    {
      tc.expect (mt2::ge (_argc, 2)) << "argc >= 2";

      if (_argc > 1)
        {
          tc.expect (mt2::eq (std::string_view{ _argv[1] }, "one"sv))
              << "argv[1] is 'one'";
        }

      if (_argc > 2)
        {
          tc.expect (mt2::eq (std::string_view{ _argv[2] }, "two"sv))
              << "argv[2] is 'two'";
        }
    }, argc, argv);
  // The values passed after the body are the actual values to be passed
  // to the lambda. An alternate solution is to capture them by value
  // since the lambda is also a closure.

#pragma GCC diagnostic pop

  // --------------------------------------------------------------------------

  ts.test_case ("Check complex logic", [] (auto& tc)
    {
      // Complex conditions can be tested with explicit tests,
      // and the results passed to the test framework.

      bool xyz = true;
      if (xyz)
        {
          tc.expect (true) << "xyz passed";
        }
      else
        {
          tc.expect (false) << "xyz...";
        }
    });

  // --------------------------------------------------------------------------

#if defined(__EXCEPTIONS)

  ts.test_case ("Check if exceptions are thrown", [] (auto& tc)
    {
      tc.expect (mt2::throws ([] { exercise_throw (true); }))
          << "exception thrown";

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif
      tc.expect (mt2::throws<std::runtime_error> ([]
        { throw std::runtime_error{ "" }; }))
          << "std::runtime_error thrown";
#pragma GCC diagnostic pop
    });

  ts.test_case ("Check if exceptions are not thrown", [] (auto& tc)
    {
      tc.expect (mt2::nothrow ([] { exercise_throw (false); }))
          << "exception not thrown";
    });

#endif // defined(__EXCEPTIONS)

  ts.test_case ("Check containers", [] (auto& tc)
    {
      // Containers are iterated and each value compared with
      // `eq()` or `ne()`.

      tc.expect (mt2::eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
          << "vector{ 1, 2 } eq vector{ 1, 2 }";

      tc.expect (
          mt2::ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
          << "vector{ 1, 2, 3 } ne vector{ 1, 2, 4 }";
    });

  ts.test_case ("Check containers with operators", [] (auto& tc)
    {
      // Containers are iterated and each value compared with `==` or `!=`.

      using namespace mt2::operators;

      tc.expect (std::vector<int>{ 1, 2 } == std::vector<int>{ 1, 2 })
          << "vector{ 1, 2 } == vector{ 1, 2 }";

      tc.expect (std::vector<int>{ 1, 2, 3 } != std::vector<int>{ 1, 2, 4 })
          << "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }";
    });

  // --------------------------------------------------------------------------

  // Trigger the execution of the static test suites.
  tr.run_static_test_suites ();

  // Return the overall test result to the system.
  return tr.exit_code ();
}

// ----------------------------------------------------------------------------

#if 1
// ----------------------------------------------------------------------------
// Additional test suites. They may be located in separate source files.

static mt2::static_test_suite ts_explicit
    = { "Explicit namespace", tr, [] (auto& ts)
  {
    ts.test_case ("Check one",
                  [] (auto& tc) { tc.expect (true) << "Passed"; });
    ts.test_case ("Check two",
                  [] (auto& tc) { tc.expect (true) << "Passed"; });
  } };

static mt2::static_test_suite ts_separate
    = { "Implicit namespace", tr, [] (auto& ts)
  {
    // For applications known to not conflict with the test
    // framework names, it is possible to access the definitions
    // directly, by including all namespace definitions.
    using namespace micro_os_plus::micro_test_plus2;

    ts.test_case ("Check one",
                  [] (auto& tc) { tc.expect (true) << "Passed"; });
    ts.test_case ("Check two",
                  [] (auto& tc) { tc.expect (true) << "Passed"; });
  } };

// ----------------------------------------------------------------------------

// Parametrized test suite, with constants, values, references and pointers.
static void
test_suite_with_args (mt2::static_test_suite& ts, int ic, int iv, int& ir,
                      int* ip1, int* ip2)
{
  ts.test_case ("args", [&] (auto& tc)
    {
      tc.expect (mt2::eq (ic, 42)) << "ic is 42";
      tc.expect (mt2::eq (iv, 43)) << "iv is 43";
      tc.expect (mt2::eq (ir, 44)) << "ir is 44";
      tc.expect (mt2::eq (*ip1, 45)) << "*ip1 is 45";
      tc.expect (mt2::eq (*ip2, 46)) << "*ip2 is 46";
    });
}

static int in = 43;
static int in44 = 44;
static int& ir = in44;
static int in45 = 45;
static int in46 = 46;
static int* ip2 = &in46;

static mt2::static_test_suite ts_args
    = { "Args", tr, test_suite_with_args, 42, in, ir, &in45, ip2 };

#endif

// ----------------------------------------------------------------------------

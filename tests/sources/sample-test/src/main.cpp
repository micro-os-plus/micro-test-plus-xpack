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
#else // GCC only
#pragma GCC diagnostic ignored "-Wshadow"
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

static mt::static_runner tr{ "Sample" };

int
main (int argc, char* argv[])
{
  // There is a default test suite automatically defined in main().
  auto& ts = tr.initialise (argc, argv);

  // --------------------------------------------------------------------------

  // Test comparison functions.
  ts.test ("Check various conditions", [] (auto& t)
    {
      // There are functions with usual names for all comparisons.

      t.expect (mt::eq (compute_answer (), 42)) << "answer eq 42";
      t.expect (mt::ne (compute_answer (), 43)) << "answer ne 43";
      t.expect (mt::lt (compute_answer (), 43)) << "answer lt 43";
      t.expect (mt::le (compute_answer (), 43)) << "answer le 42";
      t.expect (mt::gt (compute_answer (), 41)) << "answer gt 43";
      t.expect (mt::ge (compute_answer (), 42)) << "answer ge 42";

      // Boolean expressions can be checked directly.
      t.expect (compute_condition ()) << "condition is true";
    });

  ts.test ("Check various conditions with operators", [] (auto& t)
    {
      // There are custom operators for all comparisons, but
      // since interferences with other operators are possible,
      // they are located in a separate namespace. Even so, they
      // require their operands to be typed, via literals (like
      // `1_i`) or casts (like `mt::to_i(expr)`).

      using namespace mt::operators;
      using namespace mt::literals;

      t.expect (compute_answer () == 42_i) << "answer == 42 (with literal)";
      t.expect (mt::to_i (compute_answer ()) == 42)
          << "answer == 42 (with cast)";
      t.expect (compute_answer () != 43_i) << "answer != 43";
      t.expect (compute_answer () < 43_i) << "answer < 43";
      t.expect (compute_answer () <= 43_i) << "answer <= 42";
      t.expect (compute_answer () > 41_i) << "answer > 43";
      t.expect (compute_answer () >= 42_i) << "answer >= 42";

      // Note: if the operands are not typed, the test is still
      // performed correctly using the standard operators, as
      // for any logical expression, but in case of failures the
      // actual values cannot be shown.
    });

  ts.test ("Check strings", [] (auto& tc)
    {
      // String can also be compared, but only as `string_view` objects,
      // otherwise the comparison is done on
      // the memory addresses, not on the content.

      tc.expect (mt::eq (std::string_view{ compute_ultimate_answer () },
                         "fortytwo"sv))
          << "ultimate answer is 'fortytwo'";
    });

  ts.test ("Check strings with operators", [] (auto& t)
    {
      // There are also custom == and != operators for
      // `string_view` comparisons.

      using namespace mt::operators;

      t.expect (std::string_view{ compute_ultimate_answer () } == "fortytwo"sv)
          << "ultimate answer == 'fortytwo'";
    });

  ts.test ("Check compound conditions", [] (auto& t)
    {
      // More complex conditions can be constructed with _and(), _or(),
      // _not() (the underscore is required to differentiate the functions
      // from the language and/or/not operators).

      t.expect (
          mt::_and (mt::eq (compute_answer (), 42),
                    mt::eq (std::string_view{ compute_ultimate_answer () },
                            "fortytwo"sv)))
          << "logical 'and' expression";
    });

  ts.test ("Check compound conditions with operators", [] (auto& t)
    {
      // There are also operators for logical expressions.

      using namespace mt::operators;
      using namespace mt::literals;

      t.expect (
          (compute_answer () == 42_i)
          and (std::string_view{ compute_ultimate_answer () } == "fortytwo"sv))
          << "logical 'and' expression with operators";
    });

  // --------------------------------------------------------------------------

  ts.test ("Check multiple function invocations", [] (auto& t)
    {
      // The function does not need to be embedded in the test
      // case, it can be defined separately and called multiple
      // times.

      auto add = [] (int i) { return i + 40; };

      t.expect (mt::eq (add (2), 42)) << "lambda returns 42";
      t.expect (mt::eq (add (3), 43)) << "lambda returns 43";
    });

  // --------------------------------------------------------------------------

  // Test case with arguments.
  // The lambdas are special functions, which may be passed arguments
  // or may automatically capture variables from their local scope.
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
  ts.test ("Check args", [] (auto& t, int _argc, char* _argv[])
    {
      t.expect (mt::ge (_argc, 2)) << "argc >= 2";

      if (_argc > 1)
        {
          t.expect (mt::eq (std::string_view{ _argv[1] }, "one"sv))
              << "argv[1] is 'one'";
        }

      if (_argc > 2)
        {
          t.expect (mt::eq (std::string_view{ _argv[2] }, "two"sv))
              << "argv[2] is 'two'";
        }
    }, argc, argv);
  // The values passed after the body are the actual values to be passed
  // to the lambda. An alternate solution is to capture them by value
  // since the lambda is also a closure.

#pragma GCC diagnostic pop

  // --------------------------------------------------------------------------

  ts.test ("Check complex logic", [] (auto& t)
    {
      // Complex conditions can be tested with explicit tests,
      // and the results passed to the test framework.

      bool xyz = true;
      if (xyz)
        {
          t.expect (true) << "xyz passed";
        }
      else
        {
          t.expect (false) << "xyz...";
        }
    });

  // --------------------------------------------------------------------------

#if defined(__EXCEPTIONS)

  ts.test ("Check if exceptions are thrown", [] (auto& t)
    {
      t.expect (mt::throws ([] { exercise_throw (true); }))
          << "exception thrown";

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif
      t.expect (mt::throws<std::runtime_error> ([]
        { throw std::runtime_error{ "" }; }))
          << "std::runtime_error thrown";
#pragma GCC diagnostic pop
    });

  ts.test ("Check if exceptions are not thrown", [] (auto& t)
    {
      t.expect (mt::nothrow ([] { exercise_throw (false); }))
          << "exception not thrown";
    });

#endif // defined(__EXCEPTIONS)

  ts.test ("Check containers", [] (auto& t)
    {
      // Containers are iterated and each value compared with
      // `eq()` or `ne()`.

      t.expect (mt::eq (std::vector<int>{ 1, 2 }, std::vector<int>{ 1, 2 }))
          << "vector{ 1, 2 } eq vector{ 1, 2 }";

      t.expect (
          mt::ne (std::vector<int>{ 1, 2, 3 }, std::vector<int>{ 1, 2, 4 }))
          << "vector{ 1, 2, 3 } ne vector{ 1, 2, 4 }";
    });

  ts.test ("Check containers with operators", [] (auto& t)
    {
      // Containers are iterated and each value compared with `==` or `!=`.

      using namespace mt::operators;

      t.expect (std::vector<int>{ 1, 2 } == std::vector<int>{ 1, 2 })
          << "vector{ 1, 2 } == vector{ 1, 2 }";

      t.expect (std::vector<int>{ 1, 2, 3 } != std::vector<int>{ 1, 2, 4 })
          << "vector{ 1, 2, 3 } != vector{ 1, 2, 4 }";
    });

  // --------------------------------------------------------------------------

  // Return the overall test result to the system.
  return tr.exit_code ();
}

// ----------------------------------------------------------------------------

#if 1
// ----------------------------------------------------------------------------
// Additional test suites. They may be located in separate source files.

static mt::static_suite ts_explicit
    = { "Explicit namespace suite", tr, [] (auto& t)
  {
    t.test ("Check one", [] (auto& t) { t.expect (true) << "Passed"; });
    t.test ("Check two", [] (auto& t) { t.expect (true) << "Passed"; });
  } };

static mt::static_suite ts_separate
    = { "Implicit namespace suite", tr, [] (auto& t)
  {
    // For applications known to not conflict with the test
    // framework names, it is possible to access the definitions
    // directly, by including all namespace definitions.
    using namespace micro_os_plus::micro_test_plus;

    t.test ("Check one", [] (auto& t) { t.expect (true) << "Passed"; });
    t.test ("Check two", [] (auto& t) { t.expect (true) << "Passed"; });
  } };

// ----------------------------------------------------------------------------

// Parametrized test suite, with constants, values, references and pointers.
static void
test_suite_with_args (mt::static_suite& t, int ic, int iv, int& ir, int* ip1,
                      int* ip2)
{
  t.test ("args", [&] (auto& t)
    {
      t.expect (mt::eq (ic, 42)) << "ic is 42";
      t.expect (mt::eq (iv, 43)) << "iv is 43";
      t.expect (mt::eq (ir, 44)) << "ir is 44";
      t.expect (mt::eq (*ip1, 45)) << "*ip1 is 45";
      t.expect (mt::eq (*ip2, 46)) << "*ip2 is 46";
    });
}

static int in = 43;
static int in44 = 44;
static int& ir = in44;
static int in45 = 45;
static int in46 = 46;
static int* ip2 = &in46;

static mt::static_suite ts_args
    = { "Args suite", tr, test_suite_with_args, 42, in, ir, &in45, ip2 };

#endif

// ----------------------------------------------------------------------------

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

#include "suite.h"

// ----------------------------------------------------------------------------

namespace mt = micro_os_plus::micro_test_plus;
using namespace std::literals;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wshadow-uncaptured-local"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#else // GCC only
#pragma GCC diagnostic ignored "-Wshadow"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

// Simple examples of functions to be tested.
static int
compute_answer (void)
{
  // The Answer to the Ultimate Question of Life,
  // the Universe and Everything is...
  return 42;
}

static bool
compute_condition (void)
{
  return true;
}

// ----------------------------------------------------------------------------

static void
suite_function (mt::suite& ts)
{
  // Test comparison functions.
  ts.test ("Check various conditions", [] (auto& t)
    {
      t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";

      // Boolean expressions can be checked directly.
      t.expect (compute_condition ()) << "condition is true";
    });
}

static mt::static_suite suite = { "Static suite", sr, suite_function };

// ----------------------------------------------------------------------------

// The suite and test case names are longer than the fixed-size arrays
// previously used by the reporters to format the lines, and the test
// cases are nested deep enough to exceed them with the indentation alone,
// to check that nothing is truncated.

static void
nested_test_case (mt::test_case& t, int depth)
{
  if (depth > 0)
    {
      t.test ("Nested test case", nested_test_case, depth - 1);
    }
  else
    {
      t.expect (compute_condition ()) << "condition is true";
    }
}

static void
long_names_suite_function (mt::suite& ts)
{
  ts.test ("Check a test case with a long name, which is longer than the "
           "fixed-size arrays previously used by the reporters to format "
           "the lines, including the indentation, the index, and the counts, "
           "to check that the name is no longer truncated, neither in the "
           "subtest line, nor in the result line, which must end with the "
           "counts",
           [] (auto& t)
    { t.expect (mt::eq (compute_answer (), 42)) << "answer is 42"; });

  ts.test ("Check deeply nested test cases", nested_test_case, 10);
}

static mt::static_suite long_names_suite
    = { "Static suite with a long name, which is longer than the fixed-size "
        "arrays previously used by the reporters to format the lines, to "
        "check that the name is no longer truncated",
        sr, long_names_suite_function };

// ----------------------------------------------------------------------------

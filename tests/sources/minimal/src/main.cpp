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

#include "micro-os-plus/platform.h"
#include "micro-os-plus/micro-test-plus.h"

#include <string_view>
#include <stdexcept>
#include <vector>

// ----------------------------------------------------------------------------

namespace mt = micro_os_plus::micro_test_plus;
using namespace std::literals;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
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

int
main (int argc, char* argv[])
{
  // Name the default test suite.
  mt::runner tr;
  auto& ts = tr.initialise (argc, argv);

  // --------------------------------------------------------------------------

  // Test comparison functions.
  ts.test ("Check various conditions", [] (auto& t)
    {
      // There are functions with usual names for all comparisons.
      t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";

      // Boolean expressions can be checked directly.
      t.expect (compute_condition ()) << "condition is true";
    });

  // --------------------------------------------------------------------------

  // Return the overall test result to the system.
  return tr.exit_code ();
}

// ----------------------------------------------------------------------------

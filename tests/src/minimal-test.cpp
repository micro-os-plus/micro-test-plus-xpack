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

static bool
compute_condition (void)
{
  return true;
}

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  // There is a default test suite automatically defined in main().
  mt::initialize (argc, argv, "Minimal");

  // --------------------------------------------------------------------------

  // Test comparison functions.
  mt::test_case ("Check various conditions", [] {
    // There are functions with usual names for all comparisons.

    mt::expect (mt::eq (compute_answer (), 42)) << "answer is 42";

    // Boolean expressions can be checked directly.
    mt::expect (compute_condition ()) << "condition is true";
  });

  // --------------------------------------------------------------------------

  // Trigger the execution of the separate test suites and
  // return the overall test result to the system.
  return mt::exit_code ();
}

// ----------------------------------------------------------------------------

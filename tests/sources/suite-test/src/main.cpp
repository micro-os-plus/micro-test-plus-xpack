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

#include "suite.h"

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
// #pragma clang diagnostic ignored "-Wshadow-uncaptured-local"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
// #pragma clang diagnostic ignored "-Wctad-maybe-unsupported"
// #pragma clang diagnostic ignored "-Wunknown-warning-option"
#endif

// ----------------------------------------------------------------------------

extern mt2::static_test_runner tr;

mt2::static_test_runner tr{ "Suite" };

int
main (int argc, char* argv[])
{
  // There is a default test suite automatically defined in main().
  tr.initialise (argc, argv);

  // --------------------------------------------------------------------------

  // Trigger the execution of the static test suites.
  tr.run_static_test_suites ();

  // return the overall test result to the system.
  return tr.exit_code ();
}

// ----------------------------------------------------------------------------

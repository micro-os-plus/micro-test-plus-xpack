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
// #pragma clang diagnostic ignored "-Wctad-maybe-unsupported"
// #pragma clang diagnostic ignored "-Wunknown-warning-option"
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

static bool
compute_condition (void)
{
  return true;
}

// ----------------------------------------------------------------------------

static void
suite_function (mt::static_suite& t)
{
  // Test comparison functions.
  t.test ("Check various conditions", [] (auto& t)
    {
      t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";

      // Boolean expressions can be checked directly.
      t.expect (compute_condition ()) << "condition is true";
    });
}

static mt::static_suite suite = { "Static suite", str, suite_function };

// ----------------------------------------------------------------------------

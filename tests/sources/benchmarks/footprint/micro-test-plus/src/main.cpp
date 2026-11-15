/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

// The footprint program of µTest++: one test case with the two checks used
// by all the footprint programs, in the default configuration.
//
// The checked values are volatile, so that the compiler cannot evaluate the
// checks at build time and remove the code that reports them.

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus.h"

// ----------------------------------------------------------------------------

namespace mt = micro_os_plus::micro_test_plus;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

static volatile int answer_ = 42;
static volatile bool condition_ = true;

static int
compute_answer (void)
{
  return answer_;
}

static bool
compute_condition (void)
{
  return condition_;
}

// ----------------------------------------------------------------------------

static mt::runner tr;

int
main (int argc, char* argv[])
{
  tr.initialise (argc, argv);

  auto& ts = tr.add_top_suite ();

  ts.test ("Check various conditions", [] (auto& t)
    {
      t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";
      t.expect (compute_condition ()) << "condition is true";
    });

  return tr.run_suites ();
}

// ----------------------------------------------------------------------------

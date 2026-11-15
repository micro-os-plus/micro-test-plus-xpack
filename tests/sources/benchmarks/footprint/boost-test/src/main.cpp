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

// The footprint program of Boost.Test
// (https://www.boost.org/doc/libs/release/libs/test/): one test case with
// the two checks used by all the footprint programs, in the default
// configuration of the single-header variant, which also defines `main()`.
// Build it with the POSIX stubs of `benchmarks/footprint/common`.
//
// On bare metal, also define `_POSIX_MONOTONIC_CLOCK=200112L` and
// `_POSIX_TIMERS=1`, required by the Boost.Test timer. The program is
// single-threaded, so `BOOST_SP_DISABLE_THREADS` is also defined; without
// it, the `shared_ptr` counts use atomic operations, which ARMv6-M
// (Cortex-M0) does not have.
//
// The checked values are volatile, so that the compiler cannot evaluate the
// checks at build time and remove the code that reports them.

// ----------------------------------------------------------------------------

#define BOOST_TEST_MODULE footprint_boost_test
#include <boost/test/included/unit_test.hpp>

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

BOOST_AUTO_TEST_CASE (check_various_conditions)
{
  BOOST_CHECK_MESSAGE (compute_answer () == 42, "answer is 42");
  BOOST_CHECK_MESSAGE (compute_condition (), "condition is true");
}

// ----------------------------------------------------------------------------

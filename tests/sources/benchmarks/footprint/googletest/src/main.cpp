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

// The footprint program of GoogleTest (https://github.com/google/googletest):
// one test case with the two checks used by all the footprint programs, in
// the default configuration. Build it with `googletest/src/gtest-all.cc`
// and with the POSIX stubs of `benchmarks/footprint/common`.
//
// On bare metal, also define `GTEST_HAS_PTHREAD=0` for all the GoogleTest
// sources; GoogleTest detects by itself when the exceptions are disabled.
//
// The checked values are volatile, so that the compiler cannot evaluate the
// checks at build time and remove the code that reports them.

// ----------------------------------------------------------------------------

#include "gtest/gtest.h"

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

TEST (Minimal, CheckVariousConditions)
{
  EXPECT_EQ (compute_answer (), 42) << "answer is 42";
  EXPECT_TRUE (compute_condition ()) << "condition is true";
}

int
main (int argc, char* argv[])
{
  testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}

// ----------------------------------------------------------------------------

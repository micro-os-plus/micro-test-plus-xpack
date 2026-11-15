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

// The footprint program of Catch2 (https://github.com/catchorg/Catch2): one
// test case with the two checks used by all the footprint programs, in the
// default configuration. Build it with the amalgamated
// `extras/catch_amalgamated.cpp`, which also defines `main()`, and with the
// POSIX stubs of `benchmarks/footprint/common`.
//
// On bare metal, also define `CATCH_CONFIG_NO_POSIX_SIGNALS` for all the
// Catch2 sources; Catch2 detects by itself when the exceptions are
// disabled.
//
// The checked values are volatile, so that the compiler cannot evaluate the
// checks at build time and remove the code that reports them.

// ----------------------------------------------------------------------------

#include "catch_amalgamated.hpp"

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

TEST_CASE ("Check various conditions")
{
  INFO ("answer is 42");
  CHECK (compute_answer () == 42);

  INFO ("condition is true");
  CHECK (compute_condition ());
}

// ----------------------------------------------------------------------------

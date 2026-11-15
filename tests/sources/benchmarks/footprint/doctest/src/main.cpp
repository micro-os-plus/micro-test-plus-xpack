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

// The footprint program of doctest (https://github.com/doctest/doctest):
// one test case with the two checks used by all the footprint programs, in
// the default configuration; the framework is the single header
// `doctest/doctest.h`.
//
// On bare metal, also define `DOCTEST_CONFIG_NO_MULTITHREADING` and
// `DOCTEST_CONFIG_NO_POSIX_SIGNALS`; doctest detects by itself when the
// exceptions are disabled.
//
// The checked values are volatile, so that the compiler cannot evaluate the
// checks at build time and remove the code that reports them.

// ----------------------------------------------------------------------------

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

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
  CHECK_MESSAGE (compute_answer () == 42, "answer is 42");
  CHECK_MESSAGE (compute_condition (), "condition is true");
}

// ----------------------------------------------------------------------------

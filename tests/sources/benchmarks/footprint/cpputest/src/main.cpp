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

// The footprint program of CppUTest (https://cpputest.github.io/): one test
// case with the two checks used by all the footprint programs, in the
// default configuration. Build it with `src/CppUTest/*.cpp` and
// `src/Platforms/Gcc/UtestPlatform.cpp`.
//
// Define `HAVE_CONFIG_H` for all the CppUTest sources, so that CppUTest
// includes `generated/CppUTestGeneratedConfig.h` from the `include` folder
// of this program; without exceptions, it disables the standard C++ library
// and the leak detection, which do not build without exceptions.
//
// The checked values are volatile, so that the compiler cannot evaluate the
// checks at build time and remove the code that reports them.

// ----------------------------------------------------------------------------

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

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

TEST_GROUP (minimal){};

TEST (minimal, check_various_conditions)
{
  LONGS_EQUAL_TEXT (42, compute_answer (), "answer is 42");
  CHECK_TEXT (compute_condition (), "condition is true");
}

int
main (int argc, char* argv[])
{
  return CommandLineTestRunner::RunAllTests (argc, argv);
}

// ----------------------------------------------------------------------------

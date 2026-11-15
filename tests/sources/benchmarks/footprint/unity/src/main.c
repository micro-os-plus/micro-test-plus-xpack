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

// The footprint program of Unity (https://github.com/ThrowTheSwitch/Unity):
// one test case with the two checks used by all the footprint programs, in
// the default configuration. Build it with `src/unity.c`.
//
// The checked values are volatile, so that the compiler cannot evaluate the
// checks at build time and remove the code that reports them.

// ----------------------------------------------------------------------------

#include "unity.h"

#include <stdbool.h>

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

// Required by Unity, which calls them before and after each test.
void
setUp (void)
{
}

void
tearDown (void)
{
}

// ----------------------------------------------------------------------------

static void
check_various_conditions (void)
{
  TEST_ASSERT_EQUAL_INT_MESSAGE (42, compute_answer (), "answer is 42");
  TEST_ASSERT_TRUE_MESSAGE (compute_condition (), "condition is true");
}

int
main (void)
{
  UNITY_BEGIN ();
  RUN_TEST (check_various_conditions);
  return UNITY_END ();
}

// ----------------------------------------------------------------------------

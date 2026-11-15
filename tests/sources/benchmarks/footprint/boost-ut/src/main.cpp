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

// The footprint program of Boost UT (https://github.com/boost-ext/ut): one
// test case with the two checks used by all the footprint programs, in the
// default configuration; the framework is the single header
// `include/boost/ut.hpp`, which detects when the exceptions are disabled.
//
// The checked values are volatile, so that the compiler cannot evaluate the
// checks at build time and remove the code that reports them.

// ----------------------------------------------------------------------------

#include "boost/ut.hpp"

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

int
main ()
{
  using namespace boost::ut;

  "Check various conditions"_test = []
    {
      expect (eq (compute_answer (), 42)) << "answer is 42";
      expect (compute_condition ()) << "condition is true";
    };

  // The tests run and are reported when the global runner is destroyed.
  return 0;
}

// ----------------------------------------------------------------------------

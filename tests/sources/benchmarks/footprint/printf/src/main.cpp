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

// A program with a single `printf()` call and no test framework. Compared
// with the baseline, it gives the size of the formatted output of the C
// library, which most of the frameworks use.

// ----------------------------------------------------------------------------

#include <cstdio>

// ----------------------------------------------------------------------------

// Volatile, so that the compiler cannot compute the output at build time.
static volatile int answer_ = 42;

int
main (int argc, char* argv[])
{
  (void)argc;
  (void)argv;

  std::printf ("%s %d\n", "answer", answer_);

  return 0;
}

// ----------------------------------------------------------------------------

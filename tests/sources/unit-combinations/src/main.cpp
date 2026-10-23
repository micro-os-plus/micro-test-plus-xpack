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

// The unit tests of the combinations of the numeric types: the integral and
// floating-point comparators, with the passed and the failed checks. The
// suites are in the `*-combinations.cpp` files; each instantiates the
// comparator templates for many types, so they are kept apart from the
// other tests.

#include "unit-combinations-test.h"

#include <stdio.h>

// For this test only, make the namespaces globally visible.
using namespace micro_os_plus::micro_test_plus;

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

runner tr;

local_counts_t local_counts;

int
main (int argc, char* argv[])
{
  tr.initialise (argc, argv, "Top suite");

  if (tr.verbosity_level () > verbosity::quiet && !tr.is_listing ())
    {
      printf ("\nµTest++ combinations unit tests; some checks are expected to "
              "fail.\n");
    }

  // --------------------------------------------------------------------------

  // The inner tests should return failure.
  // run() must be always called, otherwise the test suites
  // are not executed.
  int code = tr.run ();
  test_assert (code != 0);

  if (tr.verbosity_level () > verbosity::quiet && !tr.is_listing ())
    {
      // On failure it aborts before reaching this point.
      printf ("Overall, the µTest++ combinations unit tests were "
              "successful!\n\n");
    }

  return 0;
}

// ----------------------------------------------------------------------------

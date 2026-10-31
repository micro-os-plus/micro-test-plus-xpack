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

// The unit tests of the deprecated features, kept for compatibility with
// the previous releases. The suite is in `deprecated.cpp`; this whole test
// can be removed when the deprecated features are removed.

#include "unit-deprecated-test.h"

#include <stdio.h>

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

mt::runner tr;

local_counts_t local_counts;

int
main (int argc, char* argv[])
{
  tr.initialise (argc, argv);
  auto& ts = tr.add_top_suite ("Top suite");

  if (tr.verbosity_level () > mt::verbosity::quiet && !tr.is_listing ())
    {
      printf ("\nµTest++ deprecated unit tests; some checks are expected to "
              "fail.\n");
    }

  // --------------------------------------------------------------------------

  // run_suites() must be always called, otherwise the test suites
  // are not executed.
  int code = tr.run_suites ();
  // The deprecated tests include checks that fail on purpose, so the
  // session should return failure.
  test_assert (code != 0);

  unit_common_verify_session (argc, argv, ts, code);

  if (tr.verbosity_level () > mt::verbosity::quiet && !tr.is_listing ())
    {
      // On failure it aborts before reaching this point.
      printf ("Overall, the µTest++ deprecated unit tests were "
              "successful!\n\n");
    }

  return 0;
}

// ----------------------------------------------------------------------------

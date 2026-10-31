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

#include "unit-checks-test.h"

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
      printf ("\nµTest++ unit tests; some checks are expected to fail.\n");
    }

  // --------------------------------------------------------------------------

  unit_checks_run_tests (ts);

  // The inner test should return failure.
  // run_suites() must always be called; otherwise the static suites are not
  // run, and the session is not completed.
  int code = tr.run_suites ();
  test_assert (code != 0);

  unit_common_verify_session (argc, argv, ts, code);

  if (tr.verbosity_level () > mt::verbosity::quiet && !tr.is_listing ())
    {
      // On failure it aborts before reaching this point.
      printf ("Overall, the µTest++ unit tests were successful!\n\n");
    }

  return 0;
}

// ----------------------------------------------------------------------------

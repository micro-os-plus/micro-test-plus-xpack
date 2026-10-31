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

#include "unit-common-test.h"

#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

void __attribute__ ((noreturn))
local_test_assert (const char* failedexpr, const char* file, int line)
{
  fprintf (stderr, "\nassertion \"%s\" failed\n", failedexpr);
  fprintf (stderr, "file: \"%s\"\n", file);
  fprintf (stderr, "line: %d\n", line);

  fprintf (stderr, "\nµTest++ unit test failed!\n\n");

  abort ();
  /* NOTREACHED */
}

// ----------------------------------------------------------------------------

// Checks the state of the session after `run_suites()` returned `code`.
void
unit_common_verify_session (int argc, char* argv[],
                            micro_os_plus::micro_test_plus::suite& ts,
                            int code)
{
  // The session runs only once; the later calls of run_suites() return the same
  // code without running the suites again, and a second initialise() or
  // add_top_suite() changes nothing.
  {
    const size_t executed_checks = tr.totals ().executed_checks ();
    const size_t executed_test_cases = tr.totals ().executed_test_cases ();

    test_assert (tr.run_suites () == code);
    tr.initialise (argc, argv);
    test_assert (&tr.add_top_suite () == &ts);
    test_assert (tr.run_suites () == code);

    test_assert (tr.totals ().executed_checks () == executed_checks);
    test_assert (tr.totals ().executed_test_cases () == executed_test_cases);
  }
}

// ----------------------------------------------------------------------------

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

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

#include <string_view>
#include <stdexcept>
#include <vector>
#include <cassert>

// ----------------------------------------------------------------------------

namespace mt = micro_os_plus::micro_test_plus;
using namespace std::literals;

// ----------------------------------------------------------------------------

// #pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
// #pragma clang diagnostic ignored "-Wshadow-uncaptured-local"
// #pragma clang diagnostic ignored "-Wexit-time-destructors"
// #pragma clang diagnostic ignored "-Wglobal-constructors"
// #pragma clang diagnostic ignored "-Wctad-maybe-unsupported"
// #pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif

// ----------------------------------------------------------------------------

// The simple way of testing a testing framework without having to resort to
// another testing framework (which might have clashing primitives),
// is to use traditional asserts. To have some minimal control and do not
// depend on NDEBUG, define a custom assert locally.

#define test_assert(EX) \
  (void)((EX) || (local_test_assert (#EX, __FILE__, __LINE__), 0))

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
static void __attribute__ ((noreturn))
local_test_assert (const char* failedexpr, const char* file, int line)
{
  fprintf (stdout, "\nassertion \"%s\" failed\n", failedexpr);
  fprintf (stdout, "file: \"%s\"\n", file);
  fprintf (stdout, "line: %d\n", line);

  fprintf (stdout, "\nµTest++ test failed!\n\n");

  abort ();
  /* NOTREACHED */
}
#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
#if 1
  {
    mt::runner tr ("Empty");
    tr.initialise (argc, argv);

    int exit_code = tr.exit_code ();

    test_assert (exit_code == 0);
  }

  // ---------------------------------------------------------------------------

  {
    mt::runner tr ("Empty with top suite");
    auto& ts = tr.initialise (argc, argv);
    test_assert (strcmp (ts.name (), "Empty with top suite") == 0);
    // printf ("in test suite '%s'\n", ts.name ());

    int xc = 0;
    ts.test_case ("Empty test case", [&xc] (auto& tc)
      {
        // printf ("in test case '%s'\n", tc.name ());

        // No checks, just an empty test case.
        xc = 1;
        test_assert (strcmp (tc.name (), "Empty test case") == 0);
      });

    int exit_code = tr.exit_code ();

    test_assert (exit_code == 0);
    test_assert (xc == 1);
  }
  // ---------------------------------------------------------------------------

  {
    mt::runner tr ("Empty with top suite and extra suite");
    auto& ts = tr.initialise (argc, argv);
    // printf ("in test suite '%s'\n", ts.name ());

    int xc = 0;
    ts.test_case ("Empty test case", [&xc] (auto& tc)
      {
        // printf ("in test case '%s'\n", tc.name ());

        // No checks, just an empty test case.
        xc = 1;
        test_assert (strcmp (tc.name (), "Empty test case") == 0);
      });

    int xs = 0;
    tr.test_suite ("Empty extra test suite", [&xs] (auto& ts2)
      {
        // printf ("in test suite '%s'\n", ts2.name ());

        xs = 1;
        test_assert (strcmp (ts2.name (), "Empty extra test suite") == 0);

        int y = 0;
        ts2.test_case ("Empty test case2", [&y] (auto& tc)
          {
            // printf ("in test case '%s'\n", tc.name ());

            // No checks, just an empty test case.
            y = 1;
            test_assert (strcmp (tc.name (), "Empty test case2") == 0);
          });
        test_assert (y == 1);
      });

    // The suites are delayed until exit_code().
    int exit_code = tr.exit_code ();
    test_assert (exit_code == 0);

    test_assert (xc == 1);
    test_assert (xs == 1);
  }
#endif
  // ---------------------------------------------------------------------------

  {
    mt::runner tr ("Empty with top nested cases");
    auto& ts = tr.initialise (argc, argv);
    // printf ("in test suite '%s'\n", ts.name ());

    int xc = 0;
    ts.test_case ("Empty test case", [&xc] (auto& tc)
      {
        // printf ("in test case '%s'\n", tc.name ());

        // No checks, just an empty test case.
        xc = 1;
        test_assert (strcmp (tc.name (), "Empty test case") == 0);

        int yc = 0;
        tc.test_case ("Empty nested test case", [&yc] (auto& tc2)
          {
            // printf ("in nested test case '%s'\n", tc2.name ());

            // No checks, just an empty test case.
            test_assert (strcmp (tc2.name (), "Empty nested test case") == 0);
            yc = 1;
          });
        test_assert (yc == 1);
      });

    int exit_code = tr.exit_code ();

    test_assert (exit_code == 0);
    test_assert (xc == 1);
  }

  // ---------------------------------------------------------------------------

  return 0;
}

// ----------------------------------------------------------------------------

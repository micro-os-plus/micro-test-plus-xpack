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

#include <micro-os-plus/platform.h>
#include <micro-os-plus/micro-test-plus.h>

#include <string_view>
#include <stdexcept>
#include <vector>
#include <cassert>

// ----------------------------------------------------------------------------

namespace mt = micro_os_plus::micro_test_plus;
using namespace std::literals;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wshadow-uncaptured-local"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#else // GCC only
#pragma GCC diagnostic ignored "-Wshadow"
#endif
#endif

// ----------------------------------------------------------------------------

// The simple way of testing a testing framework without having to resort to
// another testing framework (which might have clashing primitives),
// is to use traditional asserts. To have some minimal control and do not
// depend on NDEBUG, define a custom assert locally.

#define test_assert(EX) \
  (void)((EX) || (local_test_assert (#EX, __FILE__, __LINE__), 0))

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif

static void __attribute__ ((noreturn))
local_test_assert (const char* failedexpr, const char* file, int line)
{
  fprintf (stderr, "\nassertion \"%s\" failed\n", failedexpr);
  fprintf (stderr, "file: \"%s\"\n", file);
  fprintf (stderr, "line: %d\n", line);

  fprintf (stderr, "\nµTest++ empty test failed!\n\n");

  abort ();
  /* NOTREACHED */
}

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

int
main (int argc, char* argv[])
{
  {
    mt::runner tr{ "Empty suite" };
    tr.initialise (argc, argv);

    int exit_code = tr.exit_code ();

    test_assert (exit_code == 0);
  }

  // ---------------------------------------------------------------------------

  {
    mt::runner tr{ "Suite with subtest" };
    auto& ts = tr.initialise (argc, argv);

    int xc = 0;
    ts.test ("Empty subtest", [&xc] (auto& t)
      {
        // printf ("in test case '%s'\n", tc.name ());

        // No checks, just an empty test case.
        xc = 1;
        test_assert (strcmp (t.name (), "Empty subtest") == 0);
      });

    int exit_code = tr.exit_code ();

    test_assert (exit_code == 0);
    test_assert (xc == 1);
  }

  // ---------------------------------------------------------------------------

  {
    mt::runner tr{ "Suite with second subtest" };
    auto& ts = tr.initialise (argc, argv);

    int xc = 0;
    ts.test ("First subtest", [&xc] (auto& t)
      {
        // printf ("in test '%s'\n", t.name ());

        // No checks, just an empty test case.
        xc = 1;
        test_assert (strcmp (t.name (), "First subtest") == 0);
      });

    int xs = 0;
    ts.test ("Second subtest", [&xs] (auto& t)
      {
        // printf ("in extra test '%s'\n", t.name ());

        xs = 1;
        test_assert (strcmp (t.name (), "Second subtest") == 0);

        int y = 0;
        t.test ("Inner test", [&y] (auto& t)
          {
            // printf ("in inner test '%s'\n", t.name ());

            // No checks, just an empty test case.
            y = 1;
            test_assert (strcmp (t.name (), "Inner test") == 0);
          });
        test_assert (y == 1);
      });

    // The suites are delayed until exit_code().
    int exit_code = tr.exit_code ();
    test_assert (exit_code == 0);

    test_assert (xc == 1);
    test_assert (xs == 1);
  }

  // ---------------------------------------------------------------------------

  {
    mt::runner tr{ "Top suite with nested subtests" };
    auto& ts = tr.initialise (argc, argv);
    // printf ("in test suite '%s'\n", ts.name ());

    int xc = 0;
    ts.test ("Test with nested subtest", [&xc] (auto& t)
      {
        // printf ("in test '%s'\n", t.name ());

        // No checks, just an empty test case.
        xc = 1;
        test_assert (strcmp (t.name (), "Test with nested subtest") == 0);

        int yc = 0;
        t.test ("Empty nested test", [&yc] (auto& t)
          {
            // printf ("in nested test '%s'\n", t.name ());

            // No checks, just an empty test.
            test_assert (strcmp (t.name (), "Empty nested test") == 0);
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

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

#include "suite.h"

// ----------------------------------------------------------------------------

namespace mt = micro_os_plus::micro_test_plus;
using namespace std::literals;

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wshadow-uncaptured-local"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#else // GCC only
#pragma GCC diagnostic ignored "-Wshadow"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

// Simple examples of functions to be tested.
static int
compute_answer (void)
{
  // The Answer to the Ultimate Question of Life,
  // the Universe and Everything is...
  return 42;
}

static bool
compute_condition (void)
{
  return true;
}

static void
suite_function (mt::suite& t)
{
  // Test comparison functions.
  t.test ("Check various conditions in suite", [] (auto& t)
    {
      t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";

      // Boolean expressions can be checked directly.
      t.expect (compute_condition ()) << "condition is true";
    });
}

// ----------------------------------------------------------------------------

// Test if initialise() overrides this.
mt::static_runner sr{ "Overriden" };

int
main (int argc, char* argv[])
{
  int exit_code = 0;

  // --------------------------------------------------------------------------

  {
    mt::runner lr;
    auto& ts = lr.initialise (argc, argv, "Local suite");

    ts.test ("Check various conditions 1.1", [] (auto& t)
      {
        t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";

        // Boolean expressions can be checked directly.
        t.expect (compute_condition ()) << "condition is true";
      });

    // The suite will be executed when the runner terminates, at `exit_code()`.
    lr.suite ("Local suite 1", suite_function);

    ts.test ("Check various conditions 1.2", [] (auto& t)
      {
        t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";

        // Boolean expressions can be checked directly.
        t.expect (compute_condition ()) << "condition is true";
      });

    exit_code = lr.exit_code ();
  }

  // --------------------------------------------------------------------------

  {
    // Should override the name given in the runner constructor.
    auto& ts = sr.initialise (argc, argv, "Static top suite");
    ts.test ("Check various conditions 2.1", [] (auto& t)
      {
        t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";

        // Boolean expressions can be checked directly.
        t.expect (compute_condition ()) << "condition is true";
      });

    // The suite will be executed when the runner terminates, at `exit_code()`,
    // before the static suites.
    sr.suite ("Local suite 2", suite_function);

    ts.test ("Check various conditions 2.2", [] (auto& t)
      {
        t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";

        // Boolean expressions can be checked directly.
        t.expect (compute_condition ()) << "condition is true";
      });

    exit_code += sr.exit_code ();
  }

  // --------------------------------------------------------------------------

  // return the overall test result to the system.
  return exit_code;
}

// ----------------------------------------------------------------------------

/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from <https://opensource.org/licenses/MIT/>.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from <https://www.boost.org/LICENSE_1_0.txt>.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>
#include <cstring>
// <iostream> is too heavy for embedded, use printf().
#include <stdio.h>
#include <unistd.h>

// ----------------------------------------------------------------------------

//#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // Public API.

  void
  initialize (const char* name, int argc, char* argv[])
  {
#if defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif
    runner.initialize (name, argc, argv);
  }

  int
  exit_code (void)
  {
    return runner.exit_code ();
  }

  // --------------------------------------------------------------------------

  // Too small to deserve a separate source file.
  namespace reflection
  {

    const char*
    short_name (const char* name)
    {
      const char* p = strrchr (name, '/');
      if (p != nullptr)
        return p + 1;
      else
        return name;
    }

  } // namespace reflection

  // ==========================================================================

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
#endif

  // Static instances;
  test_runner runner;
  test_reporter reporter;

  test_suite* current_test_suite;

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

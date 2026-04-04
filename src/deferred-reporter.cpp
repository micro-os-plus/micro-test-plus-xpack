/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ source file with implementations for the µTest++ methods.
 *
 * @details
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

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  namespace detail
  {
    /**
     * @details
     * This constructor .... The source location is recorded for reporting
     * purposes, enabling precise identification of the test case within the
     * relevant file or folder.
     */
    deferred_reporter_base::deferred_reporter_base (
        bool value, const reflection::source_location location,
        subtest& subtest)
        : value_{ value }, location_{ location }, subtest_{ subtest }
    {
      // The index starts at 0, must be incremented before the first check is
      // reported, to ensure that the first check is reported as check #1.
      subtest_.increment_subtest_index ();
    }

    /**
     * @details
     * The destructor ensures that if an abort condition is set and the test
     * expression has failed, the test output is flushed and the process is
     * terminated. This mechanism guarantees immediate feedback and halts
     * further execution upon critical test failures, aiding in rapid
     * identification and resolution of issues during test runs.
     */
    deferred_reporter_base::~deferred_reporter_base ()
    {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
      printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

      if (value_)
        {
          subtest_.totals.increment_successful_checks ();
        }
      else
        {
          subtest_.totals.increment_failed_checks ();
        }

      if (abort_ && !value_)
        {
          printf ("\n");
          subtest_.reporter ().output ();
          abort ();
        }
    }

  } // namespace detail

  // ==========================================================================
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

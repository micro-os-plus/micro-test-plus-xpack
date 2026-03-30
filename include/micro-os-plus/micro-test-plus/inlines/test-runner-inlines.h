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
 * @brief C++ header file with inline implementations for the µTest++ test
 * runner.
 *
 * @details
 */

#ifndef MICRO_TEST_PLUS_TEST_RUNNER_INLINES_H_
#define MICRO_TEST_PLUS_TEST_RUNNER_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

// #include <stdio.h>
// #include <cstring>

// #include "test-suite.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

namespace micro_os_plus::micro_test_plus2
{
  // --------------------------------------------------------------------------

  template <typename Callable_T, typename... Args_T>
  void
  test_runner::test_suite (const char* name, Callable_T&& callable,
                           Args_T&&... arguments)
  {
    size_t own_index = test_suites_count () + 1;
    auto* child_test_suite = new test_suite_callable (
        name, *this, own_index, std::forward<Callable_T> (callable),
        std::forward<Args_T> (arguments)...);

    // Remember test suites to delete them at the end.
    test_suites.push_back (child_test_suite);

    // Run the child test suite immediately.
    child_test_suite->run ();

    // Accumulate the totals from the child test suite into the runner totals.
    totals += child_test_suite->totals;

    // Does not need to return the test suite reference, as it is passed to
    // the callable and can be accessed there.
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus2

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_RUNNER_INLINES_H_

// ----------------------------------------------------------------------------

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
 * case.
 *
 * @details
 */

#ifndef MICRO_TEST_PLUS_TEST_CASE_INLINES_H_
#define MICRO_TEST_PLUS_TEST_CASE_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <cstring>
// #include "test-runner.h"

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
  test_case_callable::test_case_callable (
      const char* name, test_suite_base& test_suite, size_t own_index,
      size_t nesting_depth, Callable_T&& callable, Args_T&&... arguments)
      : test_case_base{ name, test_suite, own_index, nesting_depth },
        callable_{ std::bind (std::forward<Callable_T> (callable),
                              std::placeholders::_1,
                              std::forward<Args_T> (arguments)...) }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s' %zu %zu %zu\n", __PRETTY_FUNCTION__, name, own_index,
            nesting_depth, nesting_depth_);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  template <typename Callable_T, typename... Args_T>
  void
  test_case_base::test_case (const char* name, Callable_T&& callable,
                             Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
    printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#pragma GCC diagnostic pop
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    size_t own_index = increment_child_index ();
    auto* child_test_case = new test_case_callable (
        name, test_suite_, own_index, nesting_depth_ + 1,
        std::forward<Callable_T> (callable),
        std::forward<Args_T> (arguments)...);

    test_cases_.push_back (child_test_case);
    //    child_test_case->index = test_cases.size ();

    child_test_case->run ();

    // Accumulate the totals from the child test case into the test case
    // totals.
    totals += child_test_case->totals;
    totals.increment_executed_test_cases ();

    // Does not need to return the test case reference, as it is passed to
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

#endif // MICRO_TEST_PLUS_TEST_CASE_INLINES_H_

// ----------------------------------------------------------------------------

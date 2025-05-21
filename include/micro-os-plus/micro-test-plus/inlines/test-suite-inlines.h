/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from https://www.boost.org/LICENSE_1_0.txt.
 */

// ----------------------------------------------------------------------------

/**
 * @file
 * @brief C++ header file with inline implementations for the µTest++ test
 * suite methods.
 *
 * @details
 * This header provides inline definitions for the `test_suite` class, which
 * ...
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, maintaining a clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * This file is intended for internal use within the framework and should not
 * be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_TEST_SUITE_INLINES_H_
#define MICRO_TEST_PLUS_TEST_SUITE_INLINES_H_

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

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  extern test_runner runner;

  // --------------------------------------------------------------------------

  /**
   * @details
   * This constructor initialises a test suite by binding the provided callable
   * and its arguments, and registers the suite with the test runner.
   *
   * The callable is bound using `std::bind`, allowing for flexible test suite
   * definitions with arbitrary arguments. Upon construction, the test suite is
   * automatically registered with the global runner for execution.
   */
  template <typename Callable_T, typename... Args_T>
  test_suite::test_suite (const char* name, Callable_T&& callable,
                          Args_T&&... arguments)
      : test_suite_base{ name },
        callable_{ std::bind (callable, arguments...) }
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    runner.register_test_suite (this);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_SUITE_INLINES_H_

// ----------------------------------------------------------------------------

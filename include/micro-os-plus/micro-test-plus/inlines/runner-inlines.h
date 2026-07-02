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
 * This header provides the inline template implementation for
 * `runner::suite()`, the method used to create and register a named test
 * suite with a `runner` instance. The method constructs a `suite` object
 * on the heap (wrapped in `std::unique_ptr`), transfers ownership to the
 * runner via `register_suite_()`, and the newly created suite runs
 * immediately as part of the registration process.
 *
 * The implementation is separated into this inline header so that the
 * template definition is visible at every call site without cluttering the
 * main `runner.h` declaration file.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_TEST_RUNNER_INLINES_H_
#define MICRO_TEST_PLUS_TEST_RUNNER_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_TRACE)
#include <micro-os-plus/diag/trace.h>
#endif // MICRO_OS_PLUS_TRACE

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#else // GCC only
#pragma GCC diagnostic ignored "-Wredundant-tags"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // ==========================================================================

  /**
   * @details
   * Returns a reference to the reporter object stored in the unique pointer.
   */
  inline class reporter&
  runner::reporter (void) const noexcept
  {
    return *reporter_;
  }

  /**
   * @details
   * Returns a reference to the `timestamps` member.
   */
  inline detail::timestamps&
  runner::timings () noexcept
  {
    return timings_;
  }

  /**
   * @details
   * Returns a const reference to the `timestamps` member.
   */
  inline const detail::timestamps&
  runner::timings () const noexcept
  {
    return timings_;
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Constructs a `suite` object on the heap, binding the callable and any
   * additional arguments, then transfers ownership to the runner via
   * `register_suite_()`. The suite runs immediately as part of the
   * registration process.
   */
  template <typename Callable_T, typename... Args_T>
  void
  runner::suite (const char* name, Callable_T&& callable,
                 Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_TRACE) \
    && defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif
#endif
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    auto child_suite = std::make_unique<class suite> (
        name, *this, std::forward<Callable_T> (callable),
        std::forward<Args_T> (arguments)...);

    register_suite_ (std::move (child_suite));
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_RUNNER_INLINES_H_

// ----------------------------------------------------------------------------

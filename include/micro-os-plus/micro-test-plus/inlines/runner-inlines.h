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

/**
 * @file
 * @brief C++ header file with inline implementations for the µTest++ test
 * runner.
 *
 * @details
 * This header provides the inline accessors of the `runner` class and the
 * inline template implementation for `runner::add_suite()`, the member
 * function used to create and register a named test suite with a `runner`
 * instance, and for its deprecated alias `runner::suite()`. It constructs
 * a `suite` object on the heap (wrapped in `std::unique_ptr`) and
 * transfers ownership to the runner via `register_suite()`; the suite is
 * run later, by `run_suites()`.
 *
 * The implementation is separated into this inline header so that the
 * template definition is visible at every call site without cluttering the
 * main `runner.h` declaration file.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_RUNNER_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_RUNNER_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#else // GCC only
#pragma GCC diagnostic ignored "-Wredundant-tags"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // ==========================================================================

  /**
   * @details
   * Returns the level kept in `options_`, which does not depend on
   * the reporter, so the call is safe before `initialise()`.
   */
  inline auto
  runner::verbosity_level (void) const noexcept -> micro_test_plus::verbosity
  {
    return options_.verbosity_level;
  }

  /**
   * @details
   * Returns `runner_options::list_tests` of the session options.
   */
  inline bool
  runner::is_listing (void) const noexcept
  {
    return options_.list_tests;
  }

  /**
   * @details
   * Combines the results kept by the options and by the reporter, so
   * that the runner needs no flag of its own.
   */
  inline bool
  runner::has_option_errors (void) const noexcept
  {
    return options_.has_errors () || reporter_->has_output_file_error ();
  }

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
  /**
   * @details
   * Forwards to `verbosity_level()`.
   */
  // Deprecated since 6.0.0; use verbosity_level().
  inline auto
  runner::verbosity (void) const noexcept -> micro_test_plus::verbosity
  {
    return verbosity_level ();
  }
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

  /**
   * @details
   * Returns a const reference to the `counters` member.
   */
  inline const counters&
  runner::totals (void) const noexcept
  {
    return totals_;
  }

  /**
   * @details
   * Returns the application arguments of the options kept by the
   * runner.
   */
  inline std::span<const std::string>
  runner::application_arguments (void) const noexcept
  {
    return options_.application_arguments ();
  }

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
  /**
   * @details
   * Returns a const reference to the `stopwatch` member.
   */
  // Deprecated since 6.0.0; the timings are internal.
  inline const detail::stopwatch&
  runner::timings (void) const noexcept
  {
    return stopwatch_;
  }

  /**
   * @details
   * Returns a reference to the `stopwatch` member.
   */
  // Deprecated since 6.0.0; the timings are internal.
  inline detail::stopwatch&
  runner::timings (void) noexcept
  {
    return stopwatch_;
  }

  /**
   * @details
   * Returns a reference to the reporter owned by the `reporter_` unique
   * pointer, which is empty before `initialise()`.
   */
  // Deprecated since 6.0.0; use verbosity_level().
  inline detail::reporter&
  runner::reporter (void) const noexcept
  {
    return *reporter_;
  }
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

  // --------------------------------------------------------------------------

  /**
   * @details
   * Constructs a `suite` object on the heap, binding the callable and any
   * additional arguments, then transfers ownership to the runner via
   * `register_suite()`. The suite is not run here; all registered suites
   * are run later by `run_suites()`, together with the static suites, sorted by
   * name. A suite added once `run_suites()` has started is rejected by
   * `register_suite()`.
   */
  template <typename Callable_T, typename... Args_T>
  void
  runner::add_suite (std::string_view name, Callable_T&& callable,
                     Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%.*s'\n", __PRETTY_FUNCTION__,
                   static_cast<int> (name.size ()), name.data ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    // Not std::make_unique(), which cannot access the protected constructor.
    std::unique_ptr<class suite> child_suite{ new class suite (
        name, *this, std::forward<Callable_T> (callable),
        std::forward<Args_T> (arguments)...) };

    register_suite (std::move (child_suite));
  }

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
  /**
   * @details
   * Forwards the name, the callable, and the arguments to `add_suite()`.
   */
  // Deprecated since 6.0.0; use add_suite().
  template <typename Callable_T, typename... Args_T>
  void
  runner::suite (std::string_view name, Callable_T&& callable,
                 Args_T&&... arguments)
  {
    add_suite (name, std::forward<Callable_T> (callable),
               std::forward<Args_T> (arguments)...);
  }
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_RUNNER_INLINES_H_

// ----------------------------------------------------------------------------

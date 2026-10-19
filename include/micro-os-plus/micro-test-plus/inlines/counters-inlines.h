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
 * @brief C++ header file with inline implementations for the µTest++
 * counters.
 *
 * @details
 * This header provides the inline method bodies for the `counters`
 * class, separated from the class declaration in `counters.h` to
 * enforce the project convention that declarations reside in headers
 * and implementations reside in inline files.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising
 * the risk of naming conflicts.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_COUNTERS_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_COUNTERS_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // ==========================================================================

  /**
   * @details
   * Adds `count` to the `passed_checks_` counter.
   */
  inline void
  counters::increment_passed_checks (size_t count) noexcept
  {
    passed_checks_ += count;
  }

  /**
   * @details
   * Forwards to `increment_passed_checks()`.
   */
  inline void
  counters::increment_successful_checks (size_t count) noexcept
  {
    increment_passed_checks (count);
  }

  /**
   * @details
   * Adds `count` to the `failed_checks_` counter.
   */
  inline void
  counters::increment_failed_checks (size_t count) noexcept
  {
    failed_checks_ += count;
  }

  /**
   * @details
   * Adds `count` to the `executed_test_cases_` counter.
   */
  inline void
  counters::increment_executed_test_cases (size_t count) noexcept
  {
    executed_test_cases_ += count;
  }

  /**
   * @details
   * Adds `count` to the `failed_test_cases_` counter.
   */
  inline void
  counters::increment_failed_test_cases (size_t count) noexcept
  {
    failed_test_cases_ += count;
  }

  /**
   * @details
   * Adds `count` to the `skipped_test_cases_` counter.
   */
  inline void
  counters::increment_skipped_test_cases (size_t count) noexcept
  {
    skipped_test_cases_ += count;
  }

  /**
   * @details
   * Returns the value of the `passed_checks_` counter.
   */
  inline size_t
  counters::passed_checks (void) const noexcept
  {
    return passed_checks_;
  }

  /**
   * @details
   * Forwards to `passed_checks()`.
   */
  inline size_t
  counters::successful_checks (void) const noexcept
  {
    return passed_checks ();
  }

  /**
   * @details
   * Returns the value of the `failed_checks_` counter.
   */
  inline size_t
  counters::failed_checks (void) const noexcept
  {
    return failed_checks_;
  }

  /**
   * @details
   * Returns the sum of `passed_checks_` and `failed_checks_`.
   */
  inline size_t
  counters::executed_checks (void) const noexcept
  {
    return passed_checks_ + failed_checks_;
  }

  /**
   * @details
   * Returns the value of the `executed_test_cases_` counter.
   */
  inline size_t
  counters::executed_test_cases (void) const noexcept
  {
    return executed_test_cases_;
  }

  /**
   * @details
   * Returns the value of the `failed_test_cases_` counter.
   */
  inline size_t
  counters::failed_test_cases (void) const noexcept
  {
    return failed_test_cases_;
  }

  /**
   * @details
   * Returns the value of the `skipped_test_cases_` counter.
   */
  inline size_t
  counters::skipped_test_cases (void) const noexcept
  {
    return skipped_test_cases_;
  }

  /**
   * @details
   * A node with no checks at all is considered successful, as it
   * did not fail any check. A test case whose own checks all passed is
   * still unsuccessful if one of its nested test cases failed, so that a
   * failure is reported at every level above it, as in node-tap.
   */
  inline bool
  counters::passed (void) const noexcept
  {
    return failed_checks_ == 0 && failed_test_cases_ == 0;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_COUNTERS_INLINES_H_

// ----------------------------------------------------------------------------

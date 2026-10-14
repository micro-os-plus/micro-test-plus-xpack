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
 * runner totals.
 *
 * @details
 * This header provides the inline method bodies for the `runner_totals`
 * class, separated from the class declaration in `runner-totals.h` to
 * enforce the project convention that declarations reside in headers
 * and implementations reside in inline files.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising
 * the risk of naming conflicts.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_RUNNER_TOTALS_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_RUNNER_TOTALS_INLINES_H_

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
   * Adds `count` to the `successful_checks_` counter.
   */
  inline void
  runner_totals::increment_successful_checks (size_t count) noexcept
  {
    successful_checks_ += count;
  }

  /**
   * @details
   * Adds `count` to the `failed_checks_` counter.
   */
  inline void
  runner_totals::increment_failed_checks (size_t count) noexcept
  {
    failed_checks_ += count;
  }

  /**
   * @details
   * Adds `count` to the `executed_subtests_` counter.
   */
  inline void
  runner_totals::increment_executed_subtests (size_t count) noexcept
  {
    executed_subtests_ += count;
  }

  /**
   * @details
   * Adds `count` to the `failed_subtests_` counter.
   */
  inline void
  runner_totals::increment_failed_subtests (size_t count) noexcept
  {
    failed_subtests_ += count;
  }

  /**
   * @details
   * Adds `count` to the `skipped_subtests_` counter.
   */
  inline void
  runner_totals::increment_skipped_subtests (size_t count) noexcept
  {
    skipped_subtests_ += count;
  }

  /**
   * @details
   * Returns the value of the `successful_checks_` counter.
   */
  inline size_t
  runner_totals::successful_checks () const noexcept
  {
    return successful_checks_;
  }

  /**
   * @details
   * Returns the value of the `failed_checks_` counter.
   */
  inline size_t
  runner_totals::failed_checks () const noexcept
  {
    return failed_checks_;
  }

  /**
   * @details
   * Returns the sum of `successful_checks_` and `failed_checks_`.
   */
  inline size_t
  runner_totals::executed_checks () const noexcept
  {
    return successful_checks_ + failed_checks_;
  }

  /**
   * @details
   * Returns the value of the `executed_subtests_` counter.
   */
  inline size_t
  runner_totals::executed_subtests () const noexcept
  {
    return executed_subtests_;
  }

  /**
   * @details
   * Returns the value of the `failed_subtests_` counter.
   */
  inline size_t
  runner_totals::failed_subtests () const noexcept
  {
    return failed_subtests_;
  }

  /**
   * @details
   * Returns the value of the `skipped_subtests_` counter.
   */
  inline size_t
  runner_totals::skipped_subtests () const noexcept
  {
    return skipped_subtests_;
  }

  /**
   * @details
   * A node with no checks at all is considered successful, as it
   * did not fail any check. A subtest whose own checks all passed is
   * still unsuccessful if one of its nested subtests failed, so that a
   * failure is reported at every level above it, as in node-tap.
   */
  inline bool
  runner_totals::was_successful (void) const noexcept
  {
    return failed_checks_ == 0 && failed_subtests_ == 0;
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

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_RUNNER_TOTALS_INLINES_H_

// ----------------------------------------------------------------------------

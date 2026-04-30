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

#if !defined(MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_)
// clang-format off
#error "Do not include this file directly; use <micro-os-plus/micro-test-plus.h>."
// clang-format on
#endif // MICRO_TEST_PLUS_MICRO_TEST_PLUS_H_

/**
 * @file
 * @brief C++ header file with declarations for the µTest++ runner totals.
 *
 * @details
 * This header provides the `runner_totals` class, which aggregates the
 * counts of successful checks, failed checks, and executed subtests for a
 * test runner, test suite, or subtest. Instances of this class are embedded
 * inside every `test_node`-derived object and updated in place as the
 * test session progresses.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_TEST_PLUS_TEST_RUNNER_TOTALS_H_
#define MICRO_TEST_PLUS_TEST_RUNNER_TOTALS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <cstddef>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @brief Aggregated pass/fail/subtest counters for a node in the test tree.
   *
   * @details
   * `runner_totals` records three counters that are maintained throughout a
   * test session:
   * - the number of checks that passed (`successful_checks_`),
   * - the number of checks that failed (`failed_checks_`), and
   * - the number of subtests that were executed (`executed_subtests_`).
   *
   * Every `test_node`-derived object (`runner`, `suite`, `subtest`) owns a
   * `runner_totals` member and accumulates its counts in place. At the end
   * of each suite or session the operator `+=` propagates the child totals
   * up to the parent node.
   *
   * The class is non-copyable and non-movable to prevent accidental
   * duplication of live counters.
   *
   * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
   */
  class runner_totals
  {
  public:
    /**
     * @brief Default constructor. All counters are zero-initialised.
     */
    runner_totals () = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    runner_totals (const runner_totals&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    runner_totals (runner_totals&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    runner_totals&
    operator= (const runner_totals&) = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    runner_totals&
    operator= (runner_totals&&) = delete;

    /**
     * @brief Accumulates the totals from another instance into this one.
     *
     * @param other The instance whose totals are to be added.
     * @return Reference to this instance.
     */
    runner_totals&
    operator+= (const runner_totals& other) noexcept;

    /**
     * @brief Increments the successful-checks counter.
     *
     * @param count The number of successful checks to add (default 1).
     * @par Returns
     *   Nothing.
     */
    void
    increment_successful_checks (size_t count = 1) noexcept
    {
      successful_checks_ += count;
    }

    /**
     * @brief Increments the failed-checks counter.
     *
     * @param count The number of failed checks to add (default 1).
     * @par Returns
     *   Nothing.
     */
    void
    increment_failed_checks (size_t count = 1) noexcept
    {
      failed_checks_ += count;
    }

    /**
     * @brief Increments the executed-subtests counter.
     *
     * @param count The number of subtests to add (default 1).
     * @par Returns
     *   Nothing.
     */
    void
    increment_executed_subtests (size_t count = 1) noexcept
    {
      executed_subtests_ += count;
    }

    /**
     * @brief Returns the number of checks that passed.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of successful checks.
     */
    [[nodiscard]] size_t
    successful_checks () const noexcept
    {
      return successful_checks_;
    }

    /**
     * @brief Returns the number of checks that failed.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of failed checks.
     */
    [[nodiscard]] size_t
    failed_checks () const noexcept
    {
      return failed_checks_;
    }

    /**
     * @brief Returns the total number of checks executed.
     *
     * @par Parameters
     *   None.
     * @return The sum of successful and failed checks.
     */
    [[nodiscard]] size_t
    executed_checks () const noexcept
    {
      return successful_checks_ + failed_checks_;
    }

    /**
     * @brief Returns the number of subtests that were executed.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of executed subtests.
     */
    [[nodiscard]] size_t
    executed_subtests () const noexcept
    {
      return executed_subtests_;
    }

    /**
     * @brief Checks whether all executed checks were successful.
     *
     * @par Parameters
     *	None.
     * @retval true  No checks failed.
     * @retval false At least one check failed.
     *
     * @details
     * A runner with no checks at all is considered successful, as it
     * did not fail any check.
     */
    [[nodiscard]] bool
    was_successful (void) const noexcept
    {
      return failed_checks_ == 0;
    }

  protected:
    /**
     * @brief Total number of successful checks.
     */
    size_t successful_checks_ = 0;

    /**
     * @brief Total number of failed checks.
     */
    size_t failed_checks_ = 0;

    /**
     * @brief Total number of tests executed.
     */
    size_t executed_subtests_ = 0;
  };

  // --------------------------------------------------------------------------

} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TEST_RUNNER_TOTALS_H_

// ----------------------------------------------------------------------------

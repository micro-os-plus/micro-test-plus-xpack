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
 * The class is public, since `totals()` returns it, and the tests may
 * read their own counters through it; the header itself is included
 * through `micro-test-plus.h` and should not be included directly by
 * user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_TOTALS_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_TOTALS_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include <cstddef>

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
   * @brief Aggregated pass/fail/subtest counters for a node in the test
   * tree.
   *
   * @details
   * `runner_totals` records four counters that are maintained throughout a
   * test session:
   * - the number of checks that passed (`successful_checks_`),
   * - the number of checks that failed (`failed_checks_`),
   * - the number of subtests that were executed (`executed_subtests_`), and
   * - the number of those subtests that failed (`failed_subtests_`).
   *
   * For a subtest, the subtest counters refer only to its direct nested
   * subtests; for a suite or the runner, they refer to the subtests at
   * all nesting levels.
   *
   * Every `test_node`-derived object (`runner`, `suite`, `subtest`) owns a
   * `runner_totals` member and accumulates its counts in place. At the end
   * of each suite or session the operator `+=` propagates the child totals
   * up to the parent node.
   *
   * The tests can read the counters of the runner, of a suite, or of a
   * test case through the read-only `totals()` accessor.
   *
   * The class is non-copyable and non-movable to prevent accidental
   * duplication of live counters.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class runner_totals
  {
  public:
    /**
     * @brief Default constructor.
     *
     * @details
     * All counters start at zero, via their default member initialisers.
     */
    runner_totals () = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     *
     * @details
     * The counters belong to a single node of the test tree; a copy would
     * be updated independently and the results would diverge.
     */
    runner_totals (const runner_totals&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     *
     * @details
     * The instance is a member of a node that is itself non-movable.
     */
    runner_totals (runner_totals&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     *
     * @details
     * Totals are combined explicitly with `operator+=`, never replaced.
     */
    runner_totals&
    operator= (const runner_totals&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     *
     * @details
     * Totals are combined explicitly with `operator+=`, never replaced.
     */
    runner_totals&
    operator= (runner_totals&&)
        = delete;

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
    increment_successful_checks (size_t count = 1) noexcept;

    /**
     * @brief Increments the failed-checks counter.
     *
     * @param count The number of failed checks to add (default 1).
     * @par Returns
     *   Nothing.
     */
    void
    increment_failed_checks (size_t count = 1) noexcept;

    /**
     * @brief Increments the executed-subtests counter.
     *
     * @param count The number of subtests to add (default 1).
     * @par Returns
     *   Nothing.
     */
    void
    increment_executed_subtests (size_t count = 1) noexcept;

    /**
     * @brief Increments the failed-subtests counter.
     *
     * @param count The number of failed subtests to add (default 1).
     * @par Returns
     *   Nothing.
     */
    void
    increment_failed_subtests (size_t count = 1) noexcept;

    /**
     * @brief Returns the number of checks that passed.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of successful checks.
     */
    [[nodiscard]] size_t
    successful_checks () const noexcept;

    /**
     * @brief Returns the number of checks that failed.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of failed checks.
     */
    [[nodiscard]] size_t
    failed_checks () const noexcept;

    /**
     * @brief Returns the total number of checks executed.
     *
     * @par Parameters
     *   None.
     * @return The sum of successful and failed checks.
     */
    [[nodiscard]] size_t
    executed_checks () const noexcept;

    /**
     * @brief Returns the number of subtests that were executed.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of executed subtests.
     */
    [[nodiscard]] size_t
    executed_subtests () const noexcept;

    /**
     * @brief Returns the number of executed subtests that failed.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of failed subtests.
     */
    [[nodiscard]] size_t
    failed_subtests () const noexcept;

    /**
     * @brief Checks whether all executed checks and subtests were
     * successful.
     *
     * @par Parameters
     *   None.
     * @retval true  No checks and no subtests failed.
     * @retval false At least one check or one subtest failed.
     */
    [[nodiscard]] bool
    was_successful (void) const noexcept;

  protected:
    /**
     * @brief Total number of successful checks.
     *
     * @details
     * Incremented by `increment_successful_checks()` and by
     * `operator+=`.
     */
    size_t successful_checks_ = 0;

    /**
     * @brief Total number of failed checks.
     *
     * @details
     * Incremented by `increment_failed_checks()` and by `operator+=`.
     */
    size_t failed_checks_ = 0;

    /**
     * @brief Total number of subtests executed.
     *
     * @details
     * Incremented by `increment_executed_subtests()` and by
     * `operator+=`.
     */
    size_t executed_subtests_ = 0;

    /**
     * @brief Total number of executed subtests that failed.
     *
     * @details
     * Incremented by `increment_failed_subtests()`, when a subtest ends
     * with a failed check or a failed nested subtest, and by
     * `operator+=`. A subtest fails when any of its nested subtests
     * fails, as in node-tap, although the checks of the nested subtests
     * are not counted in its check counters.
     */
    size_t failed_subtests_ = 0;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/runner-totals-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_TOTALS_H_

// ----------------------------------------------------------------------------

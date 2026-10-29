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
 * @brief C++ header file with declarations for the µTest++ counters.
 *
 * @details
 * This header provides the `counters` class, which aggregates the
 * counts of passed checks, failed checks, and executed test cases for a
 * test runner, test suite, or test case. Instances of this class are embedded
 * inside the runner and every node of the test tree, and updated in place
 * as the test session progresses.
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_COUNTERS_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_COUNTERS_H_

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
   * @brief Aggregated check and test case counters for a node in the test
   * tree.
   *
   * @details
   * `counters` records five counters that are maintained throughout a
   * test session:
   * - the number of checks that passed (`passed_checks_`),
   * - the number of checks that failed (`failed_checks_`),
   * - the number of test cases that were executed (`executed_test_cases_`),
   * - the number of those test cases that failed (`failed_test_cases_`),
   *   and
   * - the number of test cases skipped by the filter
   *   (`skipped_test_cases_`).
   *
   * For a test case, the test case counters refer only to its direct nested
   * test cases; for a suite or the runner, they refer to the test cases at
   * all nesting levels.
   *
   * The runner and every node of the test tree (`suite`, `test_case`) own a
   * `counters` member and accumulate their counts in place. At the
   * end of each suite or session the operator `+=` propagates the child
   * totals up to the parent node, or to the runner.
   *
   * The tests can read the counters of the runner, of a suite, or of a
   * test case through the `totals()` accessor.
   *
   * The class is a copyable value type, so that a test can take a
   * snapshot of the counters (`counters before = ts.totals ();`) and
   * compare it later with the current values. The copy is independent:
   * it is not updated when the original counters change. The nodes that
   * own the live counters are themselves neither copyable nor movable.
   * The runner returns only a `const` reference; the suites and the test
   * cases also have a non-`const` overload, kept for v5.0.1, but the
   * counters of the nodes are meant to be read only.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class counters
  {
  public:
    /**
     * @brief Default constructor.
     *
     * @details
     * All counters start at zero, via their default member initialisers.
     */
    counters (void) = default;

    /**
     * @brief Copy constructor.
     *
     * @details
     * Copies the values of all the counters. The new instance is
     * independent of the original, which may continue to be updated.
     *
     * @param other The instance to copy.
     *
     * @since 6.0.0
     */
    counters (const counters& other) = default;

    /**
     * @brief Move constructor.
     *
     * @details
     * Equivalent to the copy constructor, since the counters are plain
     * integral values.
     *
     * @param other The instance to move from.
     *
     * @since 6.0.0
     */
    counters (counters&& other) = default;

    /**
     * @brief Copy assignment operator.
     *
     * @details
     * Replaces the values of all the counters with those of `other`.
     *
     * @param other The instance to copy.
     * @return Reference to this instance.
     *
     * @since 6.0.0
     */
    counters&
    operator= (const counters& other)
        = default;

    /**
     * @brief Move assignment operator.
     *
     * @details
     * Equivalent to the copy assignment operator, since the counters are
     * plain integral values.
     *
     * @param other The instance to move from.
     * @return Reference to this instance.
     *
     * @since 6.0.0
     */
    counters&
    operator= (counters&& other)
        = default;

    /**
     * @brief Destructor.
     *
     * @details
     * Trivial; the counters own no resources.
     */
    ~counters () = default;

    /**
     * @brief Accumulates the totals from another instance into this one.
     *
     * @param other The instance whose totals are to be added.
     * @return Reference to this instance.
     */
    counters&
    operator+= (const counters& other) noexcept;

    /**
     * @brief Increments the passed-checks counter.
     *
     * @details
     * Called for each check that passed; the opposite count is
     * incremented by `increment_failed_checks()`.
     *
     * @param count The number of passed checks to add (default 1).
     * @par Returns
     *   Nothing.
     *
     * @since 6.0.0
     */
    void
    increment_passed_checks (size_t count = 1) noexcept;

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated name of `increment_passed_checks()`.
     *
     * @details
     * Calls `increment_passed_checks()`. The old name called the checks
     * "successful", while the reporters print them as "passed".
     *
     * @param count The number of passed checks to add (default 1).
     * @par Returns
     *   Nothing.
     */
    [[deprecated ("use increment_passed_checks() (since 6.0.0)")]] void
    increment_successful_checks (size_t count = 1) noexcept;

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

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
     * @brief Increments the executed test cases counter.
     *
     * @param count The number of test cases to add (default 1).
     * @par Returns
     *   Nothing.
     */
    void
    increment_executed_test_cases (size_t count = 1) noexcept;

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated name of `increment_executed_test_cases()`.
     *
     * @details
     * Calls `increment_executed_test_cases()`. The old name referred to
     * the `subtest` class, which is now `test_case`.
     *
     * @param count The number of test cases to add (default 1).
     * @par Returns
     *   Nothing.
     */
    [[deprecated ("use increment_executed_test_cases() (since 6.0.0)")]] void
    increment_executed_subtests (size_t count = 1) noexcept;

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    /**
     * @brief Increments the failed test cases counter.
     *
     * @param count The number of failed test cases to add (default 1).
     * @par Returns
     *   Nothing.
     */
    void
    increment_failed_test_cases (size_t count = 1) noexcept;

    /**
     * @brief Increments the skipped test cases counter.
     *
     * @param count The number of skipped test cases to add (default 1).
     * @par Returns
     *   Nothing.
     *
     * @since 6.0.0
     */
    void
    increment_skipped_test_cases (size_t count = 1) noexcept;

    /**
     * @brief Returns the number of checks that passed.
     *
     * @details
     * The opposite count is returned by `failed_checks()`, and their
     * sum by `executed_checks()`.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of passed checks.
     *
     * @since 6.0.0
     */
    [[nodiscard]] size_t
    passed_checks (void) const noexcept;

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated name of `passed_checks()`.
     *
     * @details
     * Calls `passed_checks()`. The old name called the checks
     * "successful", while the reporters print them as "passed".
     *
     * @par Parameters
     *   None.
     * @return The value returned by `passed_checks()`.
     */
    [[deprecated ("use passed_checks() (since 6.0.0)"), nodiscard]] size_t
    successful_checks (void) const noexcept;

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    /**
     * @brief Returns the number of checks that failed.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of failed checks.
     */
    [[nodiscard]] size_t
    failed_checks (void) const noexcept;

    /**
     * @brief Returns the total number of checks executed.
     *
     * @par Parameters
     *   None.
     * @return The sum of passed and failed checks.
     */
    [[nodiscard]] size_t
    executed_checks (void) const noexcept;

    /**
     * @brief Returns the number of test cases that were executed.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of executed test cases.
     */
    [[nodiscard]] size_t
    executed_test_cases (void) const noexcept;

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated name of `executed_test_cases()`.
     *
     * @details
     * Calls `executed_test_cases()`. The old name referred to the
     * `subtest` class, which is now `test_case`.
     *
     * @par Parameters
     *   None.
     * @return The value returned by `executed_test_cases()`.
     */
    [[deprecated ("use executed_test_cases() (since 6.0.0)"),
      nodiscard]] size_t
    executed_subtests (void) const noexcept;

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    /**
     * @brief Returns the number of executed test cases that failed.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of failed test cases.
     */
    [[nodiscard]] size_t
    failed_test_cases (void) const noexcept;

    /**
     * @brief Returns the number of test cases skipped by the filter.
     *
     * @details
     * The skipped test cases are not included in `executed_test_cases()`.
     *
     * @par Parameters
     *   None.
     * @return The cumulative count of skipped test cases.
     *
     * @since 6.0.0
     */
    [[nodiscard]] size_t
    skipped_test_cases (void) const noexcept;

    /**
     * @brief Checks whether all executed checks and test cases were
     * successful.
     *
     * @par Parameters
     *   None.
     * @retval true  No checks and no test cases failed.
     * @retval false At least one check or one test case failed.
     */
    [[nodiscard]] bool
    passed (void) const noexcept;

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated name of `passed()`.
     *
     * @details
     * Calls `passed()`. The new name matches the word used by the
     * reports, and by `passed_checks()`.
     *
     * @par Parameters
     *   None.
     * @return The value returned by `passed()`.
     */
    [[deprecated ("use passed() (since 6.0.0)"), nodiscard]] bool
    was_successful (void) const noexcept;

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

  private:
    /**
     * @brief Total number of passed checks.
     *
     * @details
     * Incremented by `increment_passed_checks()` and by `operator+=`.
     */
    size_t passed_checks_ = 0;

    /**
     * @brief Total number of failed checks.
     *
     * @details
     * Incremented by `increment_failed_checks()` and by `operator+=`.
     */
    size_t failed_checks_ = 0;

    /**
     * @brief Total number of test cases executed.
     *
     * @details
     * Incremented by `increment_executed_test_cases()` and by
     * `operator+=`.
     */
    size_t executed_test_cases_ = 0;

    /**
     * @brief Total number of executed test cases that failed.
     *
     * @details
     * Incremented by `increment_failed_test_cases()`, when a test case ends
     * with a failed check or a failed nested test case, and by
     * `operator+=`. A test case fails when any of its nested test cases
     * fails, as in node-tap, although the checks of the nested test cases
     * are not counted in its check counters.
     */
    size_t failed_test_cases_ = 0;

    /**
     * @brief Total number of test cases skipped by the filter.
     *
     * @details
     * Incremented by `increment_skipped_test_cases()`, when the name of a
     * test case, or of its suite, does not match the filter pattern of its
     * level, and by `operator+=`.
     */
    size_t skipped_test_cases_ = 0;
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

#include "inlines/counters-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_COUNTERS_H_

// ----------------------------------------------------------------------------

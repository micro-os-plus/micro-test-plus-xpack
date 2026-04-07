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
 * @brief C++ header file with declarations for the µTest++ test runner totals.
 *
 * @details
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
// #pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @brief Structure to hold the totals for the test runner, test suites and
   * test cases.
   */
  class runner_totals
  {
  public:
    runner_totals () = default;
    runner_totals (const runner_totals&) = delete;
    runner_totals (runner_totals&&) = delete;
    runner_totals&
    operator= (const runner_totals&) = delete;
    runner_totals&
    operator= (runner_totals&&) = delete;

    /**
     * @brief Accumulates the totals from another instance into this one.
     *
     * @param other The instance whose totals are to be added.
     * @return Reference to this instance.
     */
    runner_totals&
    operator+= (const runner_totals& other);

    constexpr void
    increment_successful_checks (size_t count = 1)
    {
      successful_checks_ += count;
    }

    constexpr void
    increment_failed_checks (size_t count = 1)
    {
      failed_checks_ += count;
    }

    constexpr void
    increment_executed_subtests (size_t count = 1)
    {
      executed_subtests_ += count;
    }

    [[nodiscard]] constexpr size_t
    successful_checks () const
    {
      return successful_checks_;
    }

    [[nodiscard]] constexpr size_t
    failed_checks () const
    {
      return failed_checks_;
    }

    [[nodiscard]] constexpr size_t
    executed_checks () const
    {
      return successful_checks_ + failed_checks_;
    }

    [[nodiscard]] constexpr size_t
    executed_subtests () const
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
    [[nodiscard]] constexpr bool
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

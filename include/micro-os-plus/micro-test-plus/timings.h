
// ----------------------------------------------------------------------------
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
 * @brief C++ header file with declarations for the µTest++ test suite.
 */

#ifndef MICRO_TEST_PLUS_TIMINGS_H_
#define MICRO_TEST_PLUS_TIMINGS_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <cstdint>
#include <optional>
#include <ctime>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif
#endif

// ===========================================================================

namespace micro_os_plus::micro_test_plus
{

  // ==========================================================================

  class timestamp
  {
  public:
    timestamp () noexcept;

    // `timespec` is trivially copyable, so copy and move are safe to default.
    // Defaulting these operations allows `timestamp` to be used in contexts
    // that require copyability or movability (e.g. containers, algorithms).
    timestamp (const timestamp&) = default;
    timestamp (timestamp&&) = default;
    timestamp&
    operator= (const timestamp&) = default;
    timestamp&
    operator= (timestamp&&) = default;

    ~timestamp () = default;

    bool
    has_clock (void) const noexcept;

    [[nodiscard]] timespec&
    value () noexcept
    {
      return value_;
    }

    [[nodiscard]] const timespec&
    value () const noexcept
    {
      return value_;
    }

  protected:
    timespec value_{};
  };

  // ==========================================================================

  class timestamps
  {
  public:
    timestamps () = default;

    timestamps (const timestamps&) = delete;
    timestamps (timestamps&&) = delete;
    timestamps&
    operator= (const timestamps&) = delete;
    timestamps&
    operator= (timestamps&&) = delete;

    ~timestamps () = default;

    void
    timestamp_begin (void) noexcept;

    void
    timestamp_end (void) noexcept;

    bool
    has_begin () const noexcept
    {
      return begin_time_.has_value ();
    }

    bool
    has_end () const noexcept
    {
      return end_time_.has_value ();
    }

    bool
    has_timestamps (void) const noexcept;

    void
    compute_elapsed_time (uint32_t& milliseconds,
                          uint32_t& microseconds) const;

  protected:
    /**
     * @brief The timestamp recorded at the beginning of the test suite.
     */
    std::optional<timestamp> begin_time_;

    /**
     * @brief The timestamp recorded at the end of the test suite.
     */
    std::optional<timestamp> end_time_;
  };

  // ==========================================================================

} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_TIMINGS_H_

// ----------------------------------------------------------------------------

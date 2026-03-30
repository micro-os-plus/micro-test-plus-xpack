
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

#include <time.h>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
// #pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#endif
#endif

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus
{

  // ==========================================================================

  class timestamp
  {
  public:
    timestamp ();
    timestamp (const timestamp&) = delete;
    timestamp (timestamp&&) = delete;
    timestamp&
    operator= (const timestamp&) = delete;
    timestamp&
    operator= (timestamp&&) = delete;
    ~timestamp () = default;

    bool
    has_value (void) const;

    [[nodiscard]] constexpr timespec&
    value ()
    {
      return timestamp_;
    }

  protected:
    timespec timestamp_{};
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
    timestamp_begin (void);

    void
    timestamp_end (void);

    bool
    has_timestamps (void) const;

    void
    compute_elapsed_time (long& milliseconds, long& microseconds);

  protected:
    /**
     * @brief The timestamp recorded at the beginning of the test suite.
     */
    timestamp* begin_time_{ nullptr };

    /**
     * @brief The timestamp recorded at the end of the test suite.
     */
    timestamp* end_time_{ nullptr };
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

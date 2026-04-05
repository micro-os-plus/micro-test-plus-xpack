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
 * @brief C++ source file with implementations for the µTest++ test suite
 * methods.
 *
 * @details
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#else // GCC only
#pragma GCC diagnostic ignored "-Waggregate-return"
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  timestamp::timestamp ()
  {
#if defined(_WIN32)
    timespec_get (&timestamp_, TIME_UTC);
#elif defined(CLOCK_MONOTONIC)
    clock_gettime (CLOCK_MONOTONIC, &timestamp_);
#endif
  }

  bool
  timestamp::has_value (void) const
  {
    return timestamp_.tv_sec != 0 || timestamp_.tv_nsec != 0;
  }

  // --------------------------------------------------------------------------

  void
  timestamps::timestamp_begin (void)
  {
    // Ensure it is timestamped only once.
    if (begin_time_ == nullptr)
      {
        begin_time_ = std::make_unique<timestamp> ();
      }
  }

  void
  timestamps::timestamp_end (void)
  {
    // Ensure it is timestamped only once.
    if (end_time_ == nullptr)
      {
        end_time_ = std::make_unique<timestamp> ();
      }
  }

  bool
  timestamps::has_timestamps (void) const
  {
    return begin_time_ != nullptr && begin_time_->has_value ()
           && end_time_ != nullptr && end_time_->has_value ();
  }

  void
  timestamps::compute_elapsed_time (long& milliseconds, long& microseconds)
  {
    long long delta_ns
        = end_time_->value ().tv_nsec - begin_time_->value ().tv_nsec;
    long long delta_s
        = end_time_->value ().tv_sec - begin_time_->value ().tv_sec;
    if (delta_ns < 0)
      {
        delta_ns += 1000000000LL;
        --delta_s;
      }

    // Split into milliseconds and microseconds.
    const long long total_us = delta_s * 1000000LL + delta_ns / 1000LL;
    milliseconds = static_cast<long> (total_us / 1000LL);
    microseconds = static_cast<long> (total_us % 1000LL);
  }

  // --------------------------------------------------------------------------

} // namespace micro_os_plus::micro_test_plus

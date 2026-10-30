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
 * @brief C++ header file with inline implementations for the µTest++
 * runner options.
 *
 * @details
 * This header provides the inline member function bodies for the
 * `runner_options` class, separated from the class declaration in
 * `runner-options.h` to enforce the project convention that declarations
 * reside in headers and implementations reside in inline files.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising
 * the risk of naming conflicts.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_RUNNER_OPTIONS_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_RUNNER_OPTIONS_INLINES_H_

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
   * Copies `other` with the copy constructor, and moves the copy into
   * this instance; self-assignment is safe.
   */
  inline runner_options&
  runner_options::operator= (const runner_options& other)
  {
    runner_options copy{ other };
    *this = std::move (copy);
    return *this;
  }

  /**
   * @details
   * Returns whether the `errors_` member is not empty.
   */
  inline bool
  runner_options::has_errors (void) const noexcept
  {
    return !errors_.empty ();
  }

  /**
   * @details
   * Returns the `errors_` member.
   */
  inline const std::vector<std::string>&
  runner_options::errors (void) const noexcept
  {
    return errors_;
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

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_RUNNER_OPTIONS_INLINES_H_

// ----------------------------------------------------------------------------

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
 * @brief C++ header file with inline implementations for the µTest++ test
 * reporter.
 *
 * @details
 * This header provides the inline implementations for the test reporting
 * facilities used within the µTest++ framework: the `indent()` manipulator
 * factory, the `reporter` accessor, and the template output operators for
 * pointers and arithmetic values.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::detail` namespace, since the reporters
 * are internal to the framework.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_REPORTER_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_REPORTER_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus::detail
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * Returns an `indentation` aggregate initialised with `level`.
   */
  inline indentation
  indent (size_t level)
  {
    return { level };
  }

  // ==========================================================================

  /**
   * @details
   * The address is formatted by the `detail::append_pointer()` helper,
   * shared with the `detail::expression_formatter`, so that the pointers
   * are displayed identically in the expressions and in the messages.
   */
  template <typename T>
    requires (not std::is_same_v<T, char>)
  reporter&
  reporter::operator<< (T* v)
  {
    append_pointer (buffer_, v);
    return *this;
  }

  /**
   * @details
   * This template operator overload allows the `reporter` to output values of
   * any arithmetic type (integral or floating-point) in a consistent and
   * readable format. The value is formatted using the
   * `detail::append_number()` helper, without a type suffix (unlike the
   * `detail::expression_formatter` operators, which add one).
   */
  template <class T>
    requires std::is_arithmetic_v<T>
  reporter&
  reporter::operator<< (T v)
  {
    append_number (buffer_, v);
    return *this;
  }

  /**
   * @details
   * Returns the level stored in `verbosity_`, set by the constructor.
   */
  inline auto
  reporter::verbosity (void) const noexcept -> micro_test_plus::verbosity
  {
    return verbosity_;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus::detail

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_REPORTER_INLINES_H_

// ----------------------------------------------------------------------------

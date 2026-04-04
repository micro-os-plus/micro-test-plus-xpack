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
 * @brief C++ header file with declarations for the µTest++ internals.
 *
 * @details
 */

#ifndef MICRO_TEST_PLUS_DEFERRED_REPORTER_H_
#define MICRO_TEST_PLUS_DEFERRED_REPORTER_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <string>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  class subtest;

  // --------------------------------------------------------------------------

  /**
   * @namespace micro_os_plus::micro_test_plus::detail
   * @brief Internal implementation details for the µTest++ framework.
   *
   * @details
   * The `detail` namespace encapsulates the internal mechanisms, helper
   * structures, and implementation utilities employed by the µTest++ testing
   * framework. These components do not form part of the public API and may be
   * modified without prior notice.
   *
   * Within this namespace, one will find assertion handling, generic getter
   * utilities, comparator structures for logical and relational operations,
   * mechanisms for exception checking, and base classes for deferred reporting
   * of test results.
   *
   * All definitions within `detail` are intended exclusively for internal use,
   * ensuring a clear distinction between user-facing and internal components.
   * This approach enhances maintainability, mitigates the risk of naming
   * conflicts, and keeps the public API succinct.
   *
   * The relevant header files are organised within the `include/micro-os-plus`
   * folder to maintain a structured and modular codebase.
   */
  namespace detail
  {

    // ------------------------------------------------------------------------

    /**
     * @brief Base class for a deferred reporter that collects messages into a
     * string.
     *
     * @details
     * The `deferred_reporter_base` class serves as the foundational component
     * for deferred reporting within the framework. It is responsible for
     * collecting expectation messages, typically passed via the
     * `operator<<()`, into a string for later reporting.
     *
     * This class maintains the result value, abort status, and the source
     * location associated with the report. It is intended exclusively for
     * internal use and is implemented in the
     * `include/micro-os-plus/micro-test-plus` folder to ensure a structured
     * and modular codebase.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    class deferred_reporter_base
    {
    public:
      /**
       * @brief Constructs a deferred reporter base.
       *
       * @param value The result value associated with the report.
       * @param location The source location relevant to the report.
       */
      deferred_reporter_base (bool value,
                              const reflection::source_location location,
                              subtest& subtest);

      /**
       * @brief Destructor for the deferred reporter base.
       */
      ~deferred_reporter_base ();

      /**
       * @brief Appends a message to the reporter.
       *
       * @tparam T The type of the message to append.
       *
       * @param msg The message to append.
       * @return Reference to the current reporter instance.
       */
      template <class T>
      auto&
      operator<< (const T& msg);

      /**
       * @brief Retrieves the result value.
       *
       *
       * @par Parameters
       *	None.
       * @retval true  The reported condition was met.
       * @retval false The reported condition was not met.
       *
       * @details
       * Returns the result value associated with the report.
       */
      [[nodiscard]] constexpr bool
      value () const
      {
        return value_;
      }

    protected:
      /**
       * @brief Stores the result value of the report.
       */
      bool value_{};

      /**
       * @brief Indicates whether the reporting should abort further
       * processing.
       */
      bool abort_ = false;

      /**
       * @brief Stores the source location associated with the report.
       */
      const reflection::source_location location_{};

      /**
       * @brief String to collect the expectation message passed via
       * `operator<<()`.
       */
      std::string deferred_output_{};

      /**
       * @brief Reference to the test case invoking this report.
       */
      subtest& subtest_;
    };

    // ------------------------------------------------------------------------

    /**
     * @brief Deferred reporter class template for a specific expression.
     *
     * @tparam Expr_T The type of the expression being reported.
     *
     * @details
     * The `deferred_reporter` class template extends `deferred_reporter_base`
     * to provide deferred reporting functionality for a specific test
     * expression within the framework.
     *
     * This class template is responsible for capturing the expression under
     * evaluation, the abort status, and the source location. It is intended
     * exclusively for internal use and is implemented in the
     * `include/micro-os-plus/micro-test-plus` folder to ensure a structured
     * and modular codebase.
     *
     * @headerfile micro-test-plus.h <micro-os-plus/micro-test-plus.h>
     */
    template <class Expr_T>
    class deferred_reporter : public deferred_reporter_base
    {
    public:
      /**
       * @brief Constructs a deferred reporter for a specific expression.
       *
       * @param expr The expression under evaluation.
       * @param abort Indicates whether reporting should abort further
       * processing.
       * @param location The source location relevant to the report.
       *
       * @details
       * Initialises the reporter with the given expression, abort status, and
       * source location.
       */
      constexpr explicit deferred_reporter (
          const Expr_T& expr, bool abort,
          const reflection::source_location& location, subtest& subtest);

      /**
       * @brief Destructor for the deferred reporter.
       */
      ~deferred_reporter ();

    protected:
      /**
       * @brief Stores the expression under evaluation.
       */
      const Expr_T expr_{};
    };

    // ------------------------------------------------------------------------
  } // namespace detail

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_DEFERRED_REPORTER_H_

// ----------------------------------------------------------------------------

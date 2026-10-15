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
 * @brief C++ header file with inline implementations for the µTest++ test
 * hierarchy.
 *
 * @details
 * This header provides the inline and template implementations for the test
 * hierarchy used within the µTest++ framework: the accessors of the base
 * classes, the constructors that bind the callable objects and their
 * arguments, the `test()` methods that create and run test cases, and the
 * `expect()` and `require()` checks.
 *
 * When additional arguments are given, `std::bind` is used to pre-bind them,
 * allowing versatile test initialisation with arbitrary callable types and
 * arguments. A `static_suite` additionally inserts itself into the list of
 * static suites upon construction.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, maintaining a clear separation from user code and minimising the
 * risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TEST_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TEST_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/check-result.h"
#include "micro-os-plus/micro-test-plus/reporter.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

/**
 * @def MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
 * @brief Portable `printf()` conversion for `size_t` values in trace
 * messages.
 *
 * @details
 * Clang's format checker on Windows (the "ms_printf" archetype) rejects the
 * standard `z` modifier, even though the UCRT `printf()` implementation
 * supports it at run time, so the Microsoft-specific `I` modifier is used
 * there instead (`"Iu"`); elsewhere it is `"zu"`. Defined only when
 * `MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED` is defined.
 */
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
#if defined(_WIN32) && defined(__clang__) && !defined(__MINGW32__)
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "Iu"
#else
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "zu"
#endif // defined(_WIN32) && defined(__clang__) && !defined(__MINGW32__)
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)

#include <cstdio>
#include <cstring>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wformat-extra-args"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#else // GCC only
#pragma GCC diagnostic ignored "-Wredundant-tags"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  namespace detail
  {
    // ========================================================================

    /**
     * @details
     * Stores the name pointer and the location; when called implicitly,
     * the location is the place of the conversion, in the user code.
     */
    inline test_name::test_name (
        const char* name, const reflection::source_location& location) noexcept
        : name_{ name }, location_{ location }
    {
    }

    /**
     * @details
     * Returns the pointer stored in `name_`.
     */
    inline const char*
    test_name::name (void) const noexcept
    {
      return name_;
    }

    /**
     * @details
     * Returns a reference to the location stored in `location_`.
     */
    inline const reflection::source_location&
    test_name::location (void) const noexcept
    {
      return location_;
    }

    // ========================================================================

    /**
     * @details
     * Returns a pointer to the null-terminated name stored in `name_`.
     */
    inline const char*
    runnable_base::name (void) const noexcept
    {
      return name_;
    }

    /**
     * @details
     * Returns a const reference to the `counters` member.
     */
    inline const counters&
    runnable_base::totals () const noexcept
    {
      return totals_;
    }

    /**
     * @details
     * Returns the one-based positional index of this object within its parent.
     */
    inline size_t
    runnable_base::own_index () const noexcept
    {
      return own_index_;
    }

    /**
     * @details
     * Sets the positional index of this object within its parent.
     */
    inline void
    runnable_base::own_index (size_t index) noexcept
    {
      own_index_ = index;
    }

    /**
     * @details
     * Returns the number of the most recent child test point (check or
     * nested test case).
     */
    inline size_t
    runnable_base::test_point_number () const noexcept
    {
      return test_point_number_;
    }

    /**
     * @details
     * Each call to `test()` invokes this method before constructing the new
     * `test_case`, and each check invokes it from the check result
     * destructor, when the check is reported, so the numbers form a
     * strictly increasing, one-based sequence of TAP test points, in output
     * order.
     */
    inline size_t
    runnable_base::next_test_point_number () noexcept
    {
      return ++test_point_number_;
    }

    /**
     * @details
     * Returns the number of child test cases owned by this node.
     */
    inline size_t
    runnable_base::child_test_cases_count (void) const noexcept
    {
      return child_test_cases_.size ();
    }

    /**
     * @details
     * Returns a reference to the owning test runner.
     */
    inline runner&
    runnable_base::test_runner (void) const noexcept
    {
      return runner_;
    }

    // ========================================================================

    /**
     * @details
     * Without additional arguments, the callable already has the signature
     * `void (Self_T&)`, and is stored directly. `std::bind` is used only
     * when additional arguments must be bound, to avoid triggering a GCC
     * ARM bug in `__is_nothrow_invocable<_Bind<...>, Self_T&>` (GCC
     * 15.2.1).
     */
    template <typename Self_T, typename Callable_T, typename... Args_T>
    std::function<void (Self_T&)>
    bind_callable (Callable_T&& callable, Args_T&&... arguments)
    {
      if constexpr (sizeof...(arguments) == 0)
        {
          return std::forward<Callable_T> (callable);
        }
      else
        {
          return std::bind (std::forward<Callable_T> (callable),
                            std::placeholders::_1,
                            std::forward<Args_T> (arguments)...);
        }
    }

    // ------------------------------------------------------------------------
  } // namespace detail

  // ==========================================================================

  /**
   * @details
   * Stores the callable, binding its arguments, if any, and the location
   * of the call to `test()`, the parent suite, and the nesting depth.
   */
  template <typename Callable_T, typename... Args_T>
  test_case::test_case (const detail::test_name& name, runner& test_runner,
                        suite& parent_suite, size_t own_index,
                        size_t nesting_depth, Callable_T&& callable,
                        Args_T&&... arguments)
      : runnable_base{ name.name (), test_runner, own_index },
        callable_{ detail::bind_callable<test_case> (
            std::forward<Callable_T> (callable),
            std::forward<Args_T> (arguments)...) },
        location_{ name.location () }, parent_suite_{ parent_suite },
        nesting_depth_{ nesting_depth }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s' %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                   " %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
                   __PRETTY_FUNCTION__, name_, own_index_, nesting_depth_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * Allocates a child `test_case` on the heap, incrementing the test point
   * index and deepening the nesting level by one relative to this test case's
   * depth, then transfers ownership to this test case via
   * `after_test_case_create_()`, which also runs it.
   */
  template <typename Callable_T, typename... Args_T>
  void
  test_case::test (const detail::test_name& name, Callable_T&& callable,
                   Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    size_t own_index = next_test_point_number ();
    // Not std::make_unique(), which cannot access the private constructor.
    std::unique_ptr<test_case> child_test_case{ new test_case (
        name, test_runner (), parent_suite_, own_index, nesting_depth_ + 1,
        std::forward<Callable_T> (callable),
        std::forward<Args_T> (arguments)...) };

    after_test_case_create_ (std::move (child_test_case), parent_suite_);
  }

  /**
   * @details
   * Constructs and returns a `detail::check_result` with
   * `abort = false`. The check result evaluates the condition when
   * constructed, and records a pass or fail when it is destroyed, at the end
   * of the expression statement.
   */
  template <class Expr_T>
    requires type_traits::checkable<Expr_T>
  auto
  test_case::expect (const Expr_T& expr, const reflection::source_location& sl)
  {
    return detail::check_result{ expr, false, sl, *this,
                                 reporter ().expression () };
  }

  /**
   * @details
   * Constructs and returns a `detail::check_result` with
   * `abort = true`. The check result evaluates the condition when
   * constructed, records a pass or fail when it is destroyed, and, if the
   * condition is false, stops the test case by throwing
   * `detail::failed_requirement` (caught by `test_case::run()`), or,
   * without exceptions, aborts the test execution.
   */
  template <class Expr_T>
    requires type_traits::checkable<Expr_T>
  auto
  test_case::require (const Expr_T& expr,
                      const reflection::source_location& sl)
  {
    return detail::check_result{ expr, true, sl, *this,
                                 reporter ().expression () };
  }

  /**
   * @details
   * Forwards to `require()`; the returned reporter is neither copied nor
   * moved, since a prvalue is returned (guaranteed copy elision).
   */
  template <class Expr_T>
    requires type_traits::checkable<Expr_T>
  auto
  test_case::assume (const Expr_T& expr, const reflection::source_location& sl)
  {
    return require (expr, sl);
  }

  /**
   * @details
   * Top-level test cases (direct children of a `suite`) have depth 1.
   * Each additional level of nesting increments the depth by 1.
   */
  inline size_t
  test_case::nesting_depth () const noexcept
  {
    return nesting_depth_;
  }

  // ==========================================================================

  /**
   * @details
   * Stores the callable, binding its arguments, if any. The own index is
   * initially 0; the runner assigns the final index before running the
   * suite.
   *
   * The name is copied into `owned_name_`, and the node name points to the
   * copy, since the suite may run after the string passed by the caller
   * was destroyed.
   */
  template <typename Callable_T, typename... Args_T>
  suite::suite (const char* name, runner& test_runner, Callable_T&& callable,
                Args_T&&... arguments)
      : runnable_base{ name, test_runner, 0 },
        callable_{ detail::bind_callable<suite> (
            std::forward<Callable_T> (callable),
            std::forward<Args_T> (arguments)...) },
        owned_name_{ name }
  {
    name_ = owned_name_.c_str ();

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s' %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
                   __PRETTY_FUNCTION__, name, own_index_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wdocumentation"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

  /**
   * @details
   * The `test` function template creates a test case (a `test_case` with
   * nesting depth 1) and runs it immediately. It accepts a descriptive
   * name, a callable object (such as a lambda or function pointer), and an
   * optional list of arguments to be passed to the callable, after the
   * leading `test_case&` reference. The test case is reported using the
   * provided name.
   *
   * Each test case typically involves evaluating logical expressions, such
   * as comparing a computed result to an expected value, with `expect()` or
   * `require()`. When exceptions are enabled, it is also possible to verify
   * whether evaluating an expression throws exceptions. Each check either
   * succeeds or fails, and the suite totals count the successful and failed
   * checks.
   *
   * It is typically invoked within the body of a suite.
   *
   * @par Example
   *
   * @code{.cpp}
   *   namespace mt = micro_os_plus::micro_test_plus;
   *
   *   ts.test ("Check answer with comparator", [] (auto& t) {
   *     t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";
   *   });
   * @endcode
   */

  template <typename Callable_T, typename... Args_T>
  void
  suite::test (const detail::test_name& name, Callable_T&& callable,
               Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    size_t own_index = next_test_point_number ();
    // Not std::make_unique(), which cannot access the private constructor.
    std::unique_ptr<test_case> child_test_case{ new test_case (
        name, test_runner (), *this, own_index, 1,
        std::forward<Callable_T> (callable),
        std::forward<Args_T> (arguments)...) };

    after_test_case_create_ (std::move (child_test_case), *this);
  }

  /**
   * @details
   * Returns a reference to the `stopwatch_` member.
   */
  inline detail::stopwatch&
  suite::stopwatch () noexcept
  {
    return stopwatch_;
  }

  /**
   * @details
   * Returns a const reference to the `stopwatch_` member.
   */
  inline const detail::stopwatch&
  suite::stopwatch () const noexcept
  {
    return stopwatch_;
  }

  // ==========================================================================

  /**
   * @details
   * Stores the pointer; the string is not copied.
   *
   * Used internally by the runner to set the name of the top suite after
   * initialisation.
   */
  inline void
  top_suite::name (const char* new_name) noexcept
  {
    name_ = new_name;
  }

  // ==========================================================================

  /**
   * @details
   * Delegates to `suite`, which stores the callable and binds its
   * arguments, if any; the callable receives a `suite&` reference, as
   * for the suites registered with `runner::suite()`. After
   * construction, the suite is inserted into the list of static suites,
   * to be run by its runner; the runner itself is not accessed.
   */
  template <typename Callable_T, typename... Args_T>
  static_suite::static_suite (const char* name, runner& test_runner,
                              Callable_T&& callable, Args_T&&... arguments)
      : suite{ name, test_runner, std::forward<Callable_T> (callable),
               std::forward<Args_T> (arguments)... }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s' %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
                   __PRETTY_FUNCTION__, name, own_index_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

    link_ ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TEST_INLINES_H_

// ----------------------------------------------------------------------------

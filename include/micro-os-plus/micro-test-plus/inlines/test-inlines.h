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
 * arguments, the `test()` methods that create and run subtests, and the
 * `expect()` and `assume()` checks.
 *
 * When additional arguments are given, `std::bind` is used to pre-bind them,
 * allowing versatile test initialisation with arbitrary callable types and
 * arguments. A `static_suite` additionally registers itself with its
 * `static_runner` upon construction.
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

#include "micro-os-plus/micro-test-plus/deferred-reporter.h"
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
    test_node::name (void) const noexcept
    {
      return name_;
    }

    /**
     * @details
     * Returns a const reference to the `runner_totals` member.
     */
    inline const runner_totals&
    test_node::totals () const noexcept
    {
      return totals_;
    }

    // ========================================================================

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
     * Returns the sequential index of the most recent child test point
     * (check or nested subtest).
     */
    inline size_t
    runnable_base::current_subtest_index () const noexcept
    {
      return current_subtest_index_;
    }

    /**
     * @details
     * Each call to `test()` invokes this method before constructing the new
     * `subtest`, and each check invokes it from the deferred reporter
     * destructor, when the check is reported, so the index values form a
     * strictly increasing, one-based sequence of TAP test points, in output
     * order.
     */
    inline size_t
    runnable_base::increment_subtest_index () noexcept
    {
      return ++current_subtest_index_;
    }

    /**
     * @details
     * Returns the number of child subtests owned by this node.
     */
    inline size_t
    runnable_base::children_subtests_count (void) const noexcept
    {
      return children_subtests_.size ();
    }

    /**
     * @details
     * Returns a reference to the owning test runner.
     */
    inline class runner&
    runnable_base::runner (void) const noexcept
    {
      return runner_;
    }

    // ========================================================================

    /**
     * @details
     * Binds the callable and its arguments into the stored `callable_`
     * function object. When `run()` is called, the stored function is invoked
     * with a reference to the derived `Self_T` instance as its first argument,
     * followed by the bound arguments.
     */
    template <typename Self_T>
    template <typename Callable_T, typename... Args_T>
    runnable<Self_T>::runnable (const char* name, class runner& runner,
                                size_t own_index, Callable_T&& callable,
                                Args_T&&... arguments)
        : runnable_base{ name, runner, own_index }
    {
      // When there are no extra arguments the callable already has the
      // signature void(Self_T&), so store it directly. Only use std::bind when
      // additional arguments must be pre-bound, to avoid triggering a GCC ARM
      // bug in
      // __is_nothrow_invocable<_Bind<...>, Self_T&> (GCC 15.2.1).
      if constexpr (sizeof...(arguments) == 0)
        {
          callable_ = std::forward<Callable_T> (callable);
        }
      else
        {
          callable_ = std::bind (std::forward<Callable_T> (callable),
                                 std::placeholders::_1,
                                 std::forward<Args_T> (arguments)...);
        }

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s '%s' %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
                     __PRETTY_FUNCTION__, name, own_index_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
    }

    /**
     * @details
     * Destroys the stored callable. When tracing is enabled, emits a trace
     * message identifying the instance being destroyed.
     */
    template <typename Self_T>
    runnable<Self_T>::~runnable ()
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
    }

    // ------------------------------------------------------------------------
  } // namespace detail

  // ==========================================================================

  /**
   * @details
   * Delegates to `runnable`, which binds the callable with its arguments,
   * and stores the location of the call to `test()`, the parent suite,
   * and the nesting depth.
   */
  template <typename Callable_T, typename... Args_T>
  subtest::subtest (const detail::test_name& name, class runner& runner,
                    suite& parent_suite, size_t own_index,
                    size_t nesting_depth, Callable_T&& callable,
                    Args_T&&... arguments)
      : runnable<subtest>{ name.name (), runner, own_index,
                           std::forward<Callable_T> (callable),
                           std::forward<Args_T> (arguments)... },
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
   * Allocates a child `subtest` on the heap, incrementing the test point
   * index and deepening the nesting level by one relative to this subtest's
   * depth, then transfers ownership to this subtest via
   * `after_subtest_create_()`, which also runs it.
   */
  template <typename Callable_T, typename... Args_T>
  void
  subtest::test (const detail::test_name& name, Callable_T&& callable,
                 Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    size_t own_index = increment_subtest_index ();
    auto child_subtest = std::make_unique<subtest> (
        name, runner (), parent_suite_, own_index, nesting_depth_ + 1,
        std::forward<Callable_T> (callable),
        std::forward<Args_T> (arguments)...);

    after_subtest_create_ (std::move (child_subtest), parent_suite_);
  }

  /**
   * @details
   * Constructs and returns a `detail::deferred_reporter` with
   * `abort = false`. The reporter evaluates the condition when constructed,
   * and records a pass or fail when it is destroyed, at the end of the
   * expression statement.
   */
  template <class Expr_T>
    requires type_traits::checkable<Expr_T>
  auto
  subtest::expect (const Expr_T& expr, const reflection::source_location& sl)
  {
    return detail::deferred_reporter{ expr, false, sl, *this,
                                      reporter ().expression () };
  }

  /**
   * @details
   * Constructs and returns a `detail::deferred_reporter` with
   * `abort = true`. The reporter evaluates the condition when constructed,
   * records a pass or fail when it is destroyed, and aborts execution if
   * the condition is false.
   */
  template <class Expr_T>
    requires type_traits::checkable<Expr_T>
  auto
  subtest::assume (const Expr_T& expr, const reflection::source_location& sl)
  {
    return detail::deferred_reporter{ expr, true, sl, *this,
                                      reporter ().expression () };
  }

  /**
   * @details
   * Top-level subtests (direct children of a `suite`) have depth 1.
   * Each additional level of nesting increments the depth by 1.
   */
  inline size_t
  subtest::nesting_depth () const noexcept
  {
    return nesting_depth_;
  }

  // ==========================================================================

  /**
   * @details
   * Delegates to `runnable`, which binds the callable with its arguments.
   * The own index is initially 0; the runner assigns the final index
   * before running the suite.
   *
   * The name is copied into `owned_name_`, and the node name points to the
   * copy, since the suite may run after the string passed by the caller
   * was destroyed.
   */
  template <typename Callable_T, typename... Args_T>
  suite::suite (const char* name, class runner& runner, Callable_T&& callable,
                Args_T&&... arguments)
      : runnable<suite>{ name, runner, 0, std::forward<Callable_T> (callable),
                         std::forward<Args_T> (arguments)... },
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
   * The `test` function template creates a test case (a `subtest` with
   * nesting depth 1) and runs it immediately. It accepts a descriptive
   * name, a callable object (such as a lambda or function pointer), and an
   * optional list of arguments to be passed to the callable, after the
   * leading `subtest&` reference. The test case is reported using the
   * provided name.
   *
   * Each test case typically involves evaluating logical expressions, such
   * as comparing a computed result to an expected value, with `expect()` or
   * `assume()`. When exceptions are enabled, it is also possible to verify
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

    size_t own_index = increment_subtest_index ();
    auto child_subtest
        = std::make_unique<subtest> (name, runner (), *this, own_index, 1,
                                     std::forward<Callable_T> (callable),
                                     std::forward<Args_T> (arguments)...);

    after_subtest_create_ (std::move (child_subtest), *this);
  }

  /**
   * @details
   * Returns a reference to the `timestamps` member.
   */
  inline detail::timestamps&
  suite::timings () noexcept
  {
    return timings_;
  }

  /**
   * @details
   * Returns a const reference to the `timestamps` member.
   */
  inline const detail::timestamps&
  suite::timings () const noexcept
  {
    return timings_;
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
   * Delegates to `suite` with an empty callable, and stores the callable
   * (binding its arguments, if any) in `static_callable_`. After
   * construction, the suite is registered with the static test runner.
   */
  template <typename Callable_T, typename... Args_T>
  static_suite::static_suite (const char* name, static_runner& runner,
                              Callable_T&& callable, Args_T&&... arguments)
      // The nullptr passed to the base constructor is an optimisation to save
      // some space, since this callable is not used by the static runner.
      : suite{ name, detail::to_runner (runner), nullptr }
  {
    if constexpr (sizeof...(arguments) == 0)
      {
        static_callable_ = std::forward<Callable_T> (callable);
      }
    else
      {
        static_callable_ = std::bind (std::forward<Callable_T> (callable),
                                      std::placeholders::_1,
                                      std::forward<Args_T> (arguments)...);
      }

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s' %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
                   __PRETTY_FUNCTION__, name, own_index_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

    detail::register_static_suite (runner, *this);
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

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
 * arguments, the `test()` member functions that create and run test cases,
 * and the `expect()` and `require()` checks.
 *
 * When additional arguments are given, a lambda captures copies of them,
 * allowing versatile test initialisation with arbitrary callable types and
 * arguments. The suites store this lambda in a `std::function`, while
 * the test cases only refer to it, as a local object of the `test()`
 * call that runs them. A `static_suite` additionally inserts itself into
 * the list of suites upon construction.
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
 *
 * The string literals are concatenated when the templates are parsed,
 * not when they are instantiated, so the macro is undefined at the end
 * of this header, to keep it out of the user code.
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
#pragma GCC diagnostic ignored "-Wpadded"
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
  // ==========================================================================

  /**
   * @details
   * Stores the name pointer and the location; when called implicitly,
   * the location is the place of the conversion, in the user code.
   */
  inline test_case_name::test_case_name (
      const char* name, const reflection::source_location& location) noexcept
      : name_{ name }, location_{ location }
  {
  }

  /**
   * @details
   * Stores the pointer returned by `name.c_str()`, which remains valid
   * while the string is neither destroyed nor modified, and the location;
   * when called implicitly, the location is the place of the conversion,
   * in the user code.
   */
  inline test_case_name::test_case_name (
      const std::string& name,
      const reflection::source_location& location) noexcept
      : name_{ name.c_str () }, location_{ location }
  {
  }

  /**
   * @details
   * Returns the pointer stored in `name_`.
   */
  inline const char*
  test_case_name::name (void) const noexcept
  {
    return name_;
  }

  /**
   * @details
   * Returns a reference to the location stored in `location_`.
   */
  inline const reflection::source_location&
  test_case_name::location (void) const noexcept
  {
    return location_;
  }

  // --------------------------------------------------------------------------

  namespace detail
  {
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
    runnable_base::totals (void) const noexcept
    {
      return totals_;
    }

    /**
     * @details
     * Each call to `test()` invokes this member function before constructing
     * the new `test_case`, and each check invokes it from the check result
     * destructor, when the check is reported, so the numbers form a strictly
     * increasing, one-based sequence of TAP test points, in output order.
     */
    inline size_t
    runnable_base::next_test_point_number (void) noexcept
    {
      return ++test_point_number_;
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

    /**
     * @details
     * Binds the callable and its arguments into a local body, constructs
     * the child `test_case` as a local object that refers to the body,
     * with the next test point number of this node as its index, then
     * passes it to `after_test_case_create()`, which counts and runs it.
     *
     * The child test case and its body, with the copies of the
     * arguments, are destroyed when this function returns, so the memory
     * used by a test session does not grow with the number of test cases;
     * the stack holds one test case and one body for each level of
     * nesting being run. Since the body is not stored in a
     * `std::function`, it is never allocated, whatever the size of the
     * lambda captures and of the arguments.
     */
    template <typename Callable_T, typename... Args_T>
    void
    runnable_base::create_test_case (const test_case_name& name,
                                     suite& parent_suite, size_t nesting_depth,
                                     Callable_T&& callable,
                                     Args_T&&... arguments)
    {
      size_t own_index = next_test_point_number ();
      auto body = bind_callable<class test_case> (
          std::forward<Callable_T> (callable),
          std::forward<Args_T> (arguments)...);
      class test_case child_test_case{
        name,      runner_,       parent_suite,
        own_index, nesting_depth, callable_ref<class test_case>{ body }
      };

      after_test_case_create (child_test_case, parent_suite);
    }

    // ========================================================================

    /**
     * @details
     * Without additional arguments, the callable already has the signature
     * `void (Self_T&)`, and a copy of it is returned, without a wrapper.
     *
     * Otherwise, a lambda captures the callable and copies of the
     * arguments (decayed, as by `auto`), since a suite may run after the
     * caller's temporaries are gone; it is `mutable`, so the callable
     * receives the copies as non-`const` lvalues. A reference parameter
     * thus refers to the copy; to refer to the caller's object, pass a
     * pointer, or `std::ref()`, which converts to a `T&` parameter (an
     * `auto&` parameter receives the `std::reference_wrapper` itself).
     */
    template <typename Self_T, typename Callable_T, typename... Args_T>
    auto
    bind_callable (Callable_T&& callable, Args_T&&... arguments)
    {
      if constexpr (sizeof...(arguments) == 0)
        {
          return std::forward<Callable_T> (callable);
        }
      else
        {
          return [stored_callable = std::forward<Callable_T> (callable),
                  ... stored_arguments
                  = std::forward<Args_T> (arguments)] (Self_T& self) mutable
            { std::invoke (stored_callable, self, stored_arguments...); };
        }
    }

    // ========================================================================

    /**
     * @details
     * Stores the address of the callable, and the address of the
     * `invoke_callable()` instantiation for its type.
     */
    template <typename Self_T>
    template <typename Callable_T>
      requires (!std::is_same_v<std::remove_cv_t<Callable_T>,
                                callable_ref<Self_T>>)
    callable_ref<Self_T>::callable_ref (Callable_T& callable) noexcept
        : callable_{ std::addressof (callable) },
          invoke_{ &invoke_callable<Callable_T> }
    {
    }

    /**
     * @details
     * Passes the stored address and @p self to the stored function.
     */
    template <typename Self_T>
    void
    callable_ref<Self_T>::operator() (Self_T& self) const
    {
      invoke_ (callable_, self);
    }

    /**
     * @details
     * Casts @p callable back to `Callable_T*`, the type it had when the
     * reference was constructed, and invokes the callable through it, as
     * an lvalue, with @p self.
     */
    template <typename Self_T>
    template <typename Callable_T>
    void
    callable_ref<Self_T>::invoke_callable (void* callable, Self_T& self)
    {
      std::invoke (*static_cast<Callable_T*> (callable), self);
    }

    // ------------------------------------------------------------------------
  } // namespace detail

  // ==========================================================================

  /**
   * @details
   * Stores the reference to the body, the location of the call to
   * `test()`, the parent suite, and the nesting depth.
   */
  inline test_case::test_case (const test_case_name& name, runner& test_runner,
                               suite& parent_suite, size_t own_index,
                               size_t nesting_depth,
                               detail::callable_ref<test_case> body)
      : runnable_base{ name.name (), test_runner, own_index },
        callable_{ body }, location_{ name.location () },
        parent_suite_{ parent_suite }, nesting_depth_{ nesting_depth }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s' %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE
                   " %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
                   __PRETTY_FUNCTION__, name_, own_index_, nesting_depth_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * Creates and runs the child test case with `create_test_case()`, in
   * the parent suite of this test case, one level of nesting deeper than
   * this test case.
   */
  template <typename Callable_T, typename... Args_T>
  void
  test_case::test (const test_case_name& name, Callable_T&& callable,
                   Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    create_test_case (name, parent_suite_, nesting_depth_ + 1,
                      std::forward<Callable_T> (callable),
                      std::forward<Args_T> (arguments)...);
  }

  /**
   * @details
   * Constructs and returns a `detail::check_result` of the kind
   * `detail::check_kind::expectation`. The check result evaluates the
   * condition when constructed, and records a pass or fail when it is
   * destroyed, at the end of the expression statement.
   */
  template <class Expr_T>
    requires extension::checkable<Expr_T>
  auto
  test_case::expect (const Expr_T& expr, const reflection::source_location& sl)
  {
    return detail::check_result{ expr,
                                 detail::check_kind::expectation,
                                 sl,
                                 *this,
                                 test_reporter ().expression_,
                                 test_reporter ().writes_passed_checks () };
  }

  /**
   * @details
   * Constructs and returns a `detail::check_result` of the kind
   * `detail::check_kind::requirement`. The check result evaluates the
   * condition when constructed, records a pass or fail when it is
   * destroyed, and, if the condition is false, stops the test case by
   * throwing `detail::failed_requirement` (caught by `test_case::run()`),
   * or, without exceptions, aborts the test execution.
   */
  template <class Expr_T>
    requires extension::checkable<Expr_T>
  auto
  test_case::require (const Expr_T& expr,
                      const reflection::source_location& sl)
  {
    return detail::check_result{ expr,
                                 detail::check_kind::requirement,
                                 sl,
                                 *this,
                                 test_reporter ().expression_,
                                 test_reporter ().writes_passed_checks () };
  }

  /**
   * @details
   * Forwards to `require()`; the returned reporter is neither copied nor
   * moved, since a prvalue is returned (guaranteed copy elision).
   */
  template <class Expr_T>
    requires extension::checkable<Expr_T>
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
  test_case::nesting_depth (void) const noexcept
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
   * was destroyed; the base is constructed with an empty name, since the
   * copy does not exist yet. The copy is null-terminated, also when the
   * view passed by the caller is not.
   */
  template <typename Callable_T, typename... Args_T>
  suite::suite (std::string_view name, runner& test_runner,
                Callable_T&& callable, Args_T&&... arguments)
      : runnable_base{ "", test_runner, 0 },
        callable_{ detail::bind_callable<suite> (
            std::forward<Callable_T> (callable),
            std::forward<Args_T> (arguments)...) },
        owned_name_{ name }
  {
    name_ = owned_name_.c_str ();

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s' %" MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE "\n",
                   __PRETTY_FUNCTION__, name_, own_index_);
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
   * The test case is created and run by `create_test_case()`, as a
   * local object destroyed when it returns, together with its stored
   * body and bound arguments; only the number of test cases is kept, for
   * the TAP plan.
   *
   * Each test case typically involves evaluating logical expressions, such
   * as comparing a computed result to an expected value, with `expect()` or
   * `require()`. When exceptions are enabled, it is also possible to verify
   * whether evaluating an expression throws exceptions. Each check either
   * succeeds or fails, and the suite totals count the successful and failed
   * checks.
   *
   * It is typically invoked within the body of a suite. When invoked
   * from the body of a running test case (for example via a captured
   * suite reference), the new test case could not be reported as a
   * sibling of the running one, which has not ended; it is therefore
   * created by the innermost running test case, with `test_case::test()`,
   * and runs nested in it, as if `test()` had been called on that test
   * case.
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
  suite::test (const test_case_name& name, Callable_T&& callable,
               Args_T&&... arguments)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    // Called from inside a running test case; run nested in it.
    if (class test_case* running = running_test_case (); running != nullptr)
      {
        running->test (name, std::forward<Callable_T> (callable),
                       std::forward<Args_T> (arguments)...);
        return;
      }

    create_test_case (name, *this, 1, std::forward<Callable_T> (callable),
                      std::forward<Args_T> (arguments)...);
  }

  // ==========================================================================

  /**
   * @details
   * Delegates to `suite`, which stores the callable and binds its
   * arguments, if any; the callable receives a `suite&` reference, as
   * for the suites registered with `runner::add_suite()`. After
   * construction, the suite is inserted into the list of suites, to be
   * run by its runner; the runner itself is not accessed.
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

    link ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// Used only by the trace messages above; keep it out of the user code.
#undef MICRO_OS_PLUS_MICRO_TEST_PLUS_PRI_SIZE

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TEST_INLINES_H_

// ----------------------------------------------------------------------------

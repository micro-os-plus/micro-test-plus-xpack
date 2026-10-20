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
 * @brief C++ header file with declarations for the µTest++ test hierarchy.
 *
 * @details
 * This header provides the declarations for the test hierarchy used within
 * the µTest++ framework: the internal `detail::runnable_base` base class,
 * and the `test_case`, `suite`, `top_suite`, and `static_suite` classes. They
 * offer mechanisms for running test cases, managing counters for successful
 * and failed checks, and registering test suites with the runner.
 *
 * The design ensures that test suites are non-copyable and non-movable,
 * maintaining unique ownership and consistent state. Flexible support for
 * callable objects enables a wide range of test suite definitions,
 * facilitating expressive and maintainable test organisation across embedded
 * and general C++ projects.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "counters.h"
#include "extension.h"
#include "stopwatch.h"
#include "reflection.h"

#include <cstddef>
#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wpadded"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#else // GCC only
#pragma GCC diagnostic ignored "-Wsuggest-final-types"
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#pragma GCC diagnostic ignored "-Wredundant-tags"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  class counters;
  class runner;
  class test_case;
  class suite;

  // --------------------------------------------------------------------------

  /**
   * @brief The name of a test case, with the location of its definition.
   *
   * @details
   * The first parameter of `suite::test()` and `test_case::test()`. The
   * constructors are not explicit, so a string literal, a `const char*`,
   * or a `std::string` passed as the test case name converts implicitly;
   * the default argument of the constructors is evaluated at the place of
   * the conversion, which is the call to `test()` in the user code, so the
   * location of the test case is captured without an additional argument
   * (which could not follow the variadic arguments of `test()`).
   *
   * The location is used to report a failure that is not associated with
   * a check, such as an exception escaping the test case body.
   *
   * The name is not copied. Since the test cases run immediately, within
   * the call to `test()`, a temporary string passed as the argument, which
   * lives until the end of the full expression, remains valid while the
   * test case runs; a named `test_case_name` object must not outlive the
   * string it was constructed from.
   *
   * A `std::string_view` is not accepted, since it is not guaranteed to be
   * null-terminated; pass `std::string (sv)` instead.
   *
   * Since a conversion sequence may include only one user-defined
   * conversion, an argument that converts to `const char*` or to
   * `std::string` via a user-defined conversion operator must be
   * converted explicitly.
   *
   * A helper function that adds test cases on behalf of its caller can
   * take a `const test_case_name&` parameter and pass it to `test()`, so
   * that the reported location is that of the call to the helper, not
   * that of the call to `test()` inside the helper.
   *
   * @par Example
   *
   * @code{.cpp}
   *   namespace mt = micro_os_plus::micro_test_plus;
   *
   *   void
   *   check_answer (mt::suite& ts, const mt::test_case_name& name, int v)
   *   {
   *     ts.test (name, [v] (auto& t) { t.expect (mt::eq (v, 42)); });
   *   }
   * @endcode
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class test_case_name
  {
  public:
    /**
     * @brief Constructs the name from a C string, capturing the location
     * of the caller.
     *
     * @param name The test case name or description, used in reports;
     * it must remain valid while the test case runs.
     * @param location The location of the conversion, defaulting to the
     * call to `test()` in the user code.
     */
    test_case_name (const char* name,
                    const reflection::source_location& location
                    = reflection::source_location::current ()) noexcept;

    /**
     * @brief Constructs the name from a standard string, capturing the
     * location of the caller.
     *
     * @param name The test case name or description, used in reports;
     * it must remain valid, and not be modified, while the test case runs.
     * @param location The location of the conversion, defaulting to the
     * call to `test()` in the user code.
     */
    test_case_name (const std::string& name,
                    const reflection::source_location& location
                    = reflection::source_location::current ()) noexcept;

    /**
     * @brief Gets the test case name.
     *
     * @par Parameters
     *   None.
     * @return A pointer to the null-terminated test case name.
     */
    [[nodiscard]] const char*
    name (void) const noexcept;

    /**
     * @brief Gets the location of the call to `test()`.
     *
     * @par Parameters
     *   None.
     * @return A reference to the stored source location.
     */
    [[nodiscard]] const reflection::source_location&
    location (void) const noexcept;

  private:
    /**
     * @brief The test case name.
     *
     * @details
     * Not owned; test cases run immediately, while the name is valid.
     */
    const char* name_;

    /**
     * @brief The location of the call to `test()`.
     */
    reflection::source_location location_;
  };

  // --------------------------------------------------------------------------

  namespace detail
  {
    class check_result;
    class reporter;
    class reporter_human;
    class reporter_tap;

    // ========================================================================

    /**
     * @brief Non-template base for all runnable objects (suites and test
     * cases).
     *
     * @details
     * `runnable_base` is the single base of the nodes of the test tree,
     * and holds the state that is shared by every runnable object:
     * - the node name,
     * - the counters of the successful and failed checks and of the
     *   executed test cases,
     * - a reference to the owning `runner`,
     * - the object's own index within its parent container,
     * - the number of the most recent test point (check or nested test
     *   case), used in the TAP output, and
     * - an owning vector of child `test_case` instances.
     *
     * The concrete runnable classes (`suite`, `test_case`) derive from
     * `runnable_base`; each refers to its body, which receives a
     * reference to its own class, and implements `run()`, which invokes
     * the body between the reporter notifications. A suite, which runs
     * later, stores its body in a `std::function`; a test case, which
     * runs immediately, refers to a body kept by its creator.
     *
     * The user code can read only the name and the totals; the rest of
     * the state, and the functions that run and abort the nodes, are the
     * protocol between the nodes, the runner, the check result, and the
     * reporters, which are friends. The runner numbers and runs the
     * suites, the check result numbers and counts the checks, and the
     * reporters read the indices and the test point numbers.
     *
     * The class is non-copyable and non-movable to preserve unique ownership
     * and consistent state throughout the test session.
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    class runnable_base
    {
      // Set the indices of the suites, before running them, and select
      // the static suites by their runner.
      friend class micro_test_plus::runner;

      // Number and count the checks of the test cases, and report them.
      friend class check_result;

      // Display the indices and the test point numbers, and abort on
      // an inconsistent report.
      friend class reporter_human;
      friend class reporter_tap;

    public:
      /**
       * @brief Constructs a `runnable_base` with a name, runner, and index.
       *
       * @param name The name used in reports.
       * @param test_runner The test runner managing this object.
       * @param own_index The positional index of this object within its
       * parent.
       */
      runnable_base (const char* name, runner& test_runner, size_t own_index);

      /**
       * @brief Deleted copy constructor to prevent copying.
       *
       * @details
       * A copy would duplicate the counters.
       */
      runnable_base (const runnable_base&) = delete;

      /**
       * @brief Deleted move constructor to prevent moving.
       *
       * @details
       * Nodes are referred to by address (e.g. by their children and by
       * the runner), so they must not be relocated.
       */
      runnable_base (runnable_base&&) = delete;

      /**
       * @brief Deleted copy assignment operator to prevent copying.
       *
       * @details
       * A copy would duplicate the counters.
       */
      runnable_base&
      operator= (const runnable_base&)
          = delete;

      /**
       * @brief Deleted move assignment operator to prevent moving.
       *
       * @details
       * Nodes are referred to by address (e.g. by their children and by
       * the runner), so they must not be relocated.
       */
      runnable_base&
      operator= (runnable_base&&)
          = delete;

      /**
       * @brief Virtual destructor.
       *
       * @details
       * Virtual, so that the derived nodes are destroyed correctly.
       */
      virtual ~runnable_base ();

      // ----------------------------------------------------------------------

      /**
       * @brief Gets the node name.
       *
       * @par Parameters
       *   None.
       * @return A pointer to the null-terminated node name.
       */
      [[nodiscard]] const char*
      name (void) const noexcept;

      /**
       * @brief Gets the totals of the node.
       *
       * @details
       * The totals are read-only; there is no non-const overload, so that
       * the counters cannot be modified from the test code.
       *
       * @par Parameters
       *   None.
       * @return A const reference to the `counters` instance.
       */
      [[nodiscard]] const counters&
      totals (void) const noexcept;

    private:
      /**
       * @brief Runs the body of the test case or suite.
       *
       * @details
       * Implemented by `test_case` and `suite`, which invoke the stored
       * callable surrounded by the reporter notifications.
       *
       * Private, since the nodes are run only by the framework: the
       * test cases by `after_test_case_create()`, when they are created,
       * and the suites by the runner, which is a friend; a second run
       * would report the node twice.
       *
       * @par Parameters
       *   None.
       * @par Returns
       *   Nothing.
       */
      virtual void
      run (void)
          = 0;

      /**
       * @brief Aborts test execution via the owning runner, for a failed
       * requirement.
       *
       * @details
       * Private, since it is used only by the check result, a friend, for
       * a failed requirement without exceptions; the user code calls
       * `runner::abort()`.
       *
       * @param sl The source location from which the abort is triggered.
       * @par Returns
       *   Does not return.
       */
      [[noreturn]] void
      abort (const reflection::source_location& sl
             = reflection::source_location::current ()) const;

    protected:
      /**
       * @brief Gets the test runner that owns this test runnable.
       *
       * @details
       * Protected, since the runner is internal to the framework; it is
       * used by the suites and the test cases, which derive from this
       * class and pass it to their nested test cases, and by the runner,
       * which is a friend and selects the static suites it runs.
       *
       * Not named `runner()`, which would hide the class `runner` in the
       * derived classes.
       *
       * @par Parameters
       *   None.
       * @return A reference to the test runner.
       */
      [[nodiscard]] runner&
      test_runner (void) const noexcept;

      /**
       * @brief Gets the test reporter associated with this test runnable.
       *
       * @details
       * Protected, since the reporter is internal to the framework; it is
       * used by the suites and the test cases, which derive from this
       * class, and by the check result, which is a friend.
       *
       * Not named `reporter()`, which would hide the class
       * `detail::reporter` in the derived classes.
       *
       * @par Parameters
       *   None.
       * @return A reference to the test reporter.
       */
      [[nodiscard]] class reporter&
      test_reporter (void) const noexcept;

      /**
       * @brief Gets the innermost test case being run by the owning
       * runner, if any.
       *
       * @details
       * Protected, since it is used only by `suite::test()`, to run a
       * test case started on the suite from inside a running test case
       * as a nested test case of it.
       *
       * @par Parameters
       *   None.
       * @return A pointer to the running test case, or `nullptr` when no
       * test case is running.
       */
      [[nodiscard]] class test_case*
      running_test_case (void) const noexcept;

      /**
       * @brief Checks whether the test execution was aborted by the
       * owning runner.
       *
       * @details
       * Protected, since it is used only by `test_case::run()` and
       * `suite::run()`, to pass on an exception thrown by the abort
       * handler, instead of reporting it as unexpected.
       *
       * @par Parameters
       *   None.
       * @return `true` once `runner::abort()` was called.
       */
      [[nodiscard]] bool
      is_aborted (void) const noexcept;

      /**
       * @brief Advances to the next child test point, and returns its
       * number.
       *
       * @details
       * Called for each check (by the check result, when the check is
       * reported) and for each nested test case created.
       *
       * @par Parameters
       *   None.
       * @return The one-based number of the new test point.
       */
      size_t
      next_test_point_number (void) noexcept;

      /**
       * @brief Counts a newly constructed child test case and executes it
       * immediately.
       *
       * @details
       * The child test case is a local object of `create_test_case()`,
       * and is destroyed when that function returns.
       *
       * @param test_case The newly created `test_case`.
       * @param suite The parent `suite` to which execution results are
       * reported.
       * @par Returns
       *   Nothing.
       */
      void
      after_test_case_create (class test_case& test_case, suite& suite);

      /**
       * @brief Creates a child test case, and runs it.
       *
       * @details
       * The common body of `suite::test()` and `test_case::test()`, which
       * differ only in the parent suite and the nesting depth of the
       * test cases they create.
       *
       * Always inlined into them, even without optimisations, since each
       * nested test case adds one call chain to the stack, and a separate
       * frame for this function would make it longer.
       *
       * @tparam Callable_T The type of a callable object.
       * @tparam Args_T The types of the callable arguments.
       *
       * @param name The test case name or description, used in reports,
       * and the location of the call to `test()`.
       * @param parent_suite The suite to which the test case belongs.
       * @param nesting_depth The depth of nesting of the test case; 1 for
       * the direct children of a suite.
       * @param callable A generic callable object, usually a lambda,
       * invoked to perform the test.
       * @param arguments A possibly empty list of arguments to be passed to
       * the callable.
       * @par Returns
       *   Nothing.
       */
      template <typename Callable_T, typename... Args_T>
      [[gnu::always_inline]] void
      create_test_case (const test_case_name& name, suite& parent_suite,
                        size_t nesting_depth, Callable_T&& callable,
                        Args_T&&... arguments);

    protected:
      /**
       * @brief The node name.
       *
       * @details
       * Not owned; it points to a string whose lifetime exceeds that of
       * the node. Derived classes may access this member directly, in
       * addition to the public `name()` getter.
       */
      const char* name_;

      /**
       * @brief Totals for the node.
       *
       * @details
       * For the suites, the totals include the checks of all their
       * test cases; for a test case, they include only its own checks,
       * plus the number of nested test cases executed.
       *
       * Updated by the node itself, by its parent, and by the deferred
       * reporter, which is a friend.
       */
      counters totals_;

      /**
       * @brief Reference to the test runner that owns this object.
       *
       * @details
       * Provides access to the reporter, and is used when aborting.
       */
      runner& runner_;

      /**
       * @brief The test index, counting from 1.
       *
       * @details
       * The position of this object within its parent, displayed by the
       * TAP reporter in the `ok`/`not ok` lines. Set directly by the
       * runner, which numbers the suites when it runs them, and by the
       * top suite, which is always the first one.
       */
      size_t own_index_;

      /**
       * @brief The number of the most recent child test point.
       *
       * @details
       * Test points are numbered from 1; the value is 0 before the first
       * one. This number counts the checks and the nested test cases of this
       * object, in execution order, as required by the TAP `ok`/`not ok`
       * lines. It is incremented for each check (by the check result)
       * and for each nested test case created.
       */
      size_t test_point_number_ = 0;

      /**
       * @brief The number of direct child test cases.
       *
       * @details
       * Incremented for each call to `test()`, which creates a child
       * `test_case` and runs it immediately. The child test cases are not
       * kept after they run, so that the memory does not grow with the
       * number of test cases; only their number is needed later, for the
       * TAP plan.
       */
      size_t child_test_cases_count_ = 0;
    };

    // ========================================================================

    /**
     * @brief Creates the function object that holds the body of a test
     * case or suite.
     *
     * @details
     * The returned object holds a copy of the callable (decayed, as by
     * `auto`) when there are no additional arguments; otherwise it is a
     * `bound_callable` that holds copies of the callable and of the
     * arguments, and passes the arguments after the leading reference,
     * which is passed when the body is invoked. No memory is allocated,
     * other than by the copies themselves.
     *
     * A suite stores the object in a `std::function`, since it runs
     * later; a test case, which runs immediately, refers to it with a
     * `callable_ref`.
     *
     * @tparam Self_T The type referred to by the first parameter of the
     * callable (`test_case` or `suite`).
     * @tparam Callable_T The type of the callable object.
     * @tparam Args_T The types of the additional callable arguments.
     *
     * @param callable A generic callable object, usually a lambda.
     * @param arguments A possibly empty list of arguments forwarded to the
     * callable after the leading `Self_T&` reference.
     * @return The function object, invocable with a `Self_T&` argument.
     */
    template <typename Self_T, typename Callable_T, typename... Args_T>
    [[nodiscard]] auto
    bind_callable (Callable_T&& callable, Args_T&&... arguments);

    // ========================================================================

    /**
     * @brief Function object that holds a callable and the additional
     * arguments it is invoked with.
     *
     * @details
     * Returned by `bind_callable()` when there are additional arguments.
     * When invoked with a `Self_T&` reference, it invokes the stored
     * callable with that reference, followed by the stored arguments,
     * as non-`const` lvalues.
     *
     * It replaces a lambda, since the function call operator of a lambda
     * cannot be marked as always inlined in a way accepted by all the
     * supported compilers; without optimisations, a separate frame for
     * it would make the call chain of each nested test case longer.
     *
     * @tparam Self_T The type referred to by the first parameter of the
     * callable (`test_case` or `suite`).
     * @tparam Callable_T The type of the stored callable (decayed).
     * @tparam Args_T The types of the stored arguments (decayed).
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <typename Self_T, typename Callable_T, typename... Args_T>
    class bound_callable
    {
    public:
      /**
       * @brief Constructs the function object from a callable and the
       * arguments.
       *
       * @details
       * Copies (or moves) the callable and the arguments into the object.
       *
       * @tparam C The type of the callable, as passed.
       * @tparam A The types of the arguments, as passed.
       *
       * @par Constraints
       *   One argument for each stored argument, so that the copy and
       *   move constructors are used for copies (there is always at
       *   least one stored argument).
       *
       * @param callable The callable object.
       * @param arguments The arguments passed to the callable after the
       * leading reference.
       */
      template <typename C, typename... A>
        requires (sizeof...(A) == sizeof...(Args_T))
      constexpr explicit bound_callable (C&& callable, A&&... arguments);

      /**
       * @brief Invokes the stored callable.
       *
       * @details
       * Always inlined, so that, without optimisations, it adds no frame
       * between `callable_ref::invoke_callable()` and the callable.
       *
       * @param self The reference passed as the first argument.
       * @par Returns
       *   Nothing.
       */
      [[gnu::always_inline]] void
      operator() (Self_T& self);

    private:
      /**
       * @brief Invokes the stored callable with the stored arguments,
       * unpacked by their indices.
       *
       * @details
       * Always inlined, as the function call operator.
       *
       * @tparam Is The indices of the stored arguments.
       *
       * @param self The reference passed as the first argument.
       * @par Returns
       *   Nothing.
       */
      template <std::size_t... Is>
      [[gnu::always_inline]] void
      invoke (Self_T& self, std::index_sequence<Is...>);

      /**
       * @brief The stored callable.
       *
       * @details
       * A copy of the callable passed to `bind_callable()`, decayed, so a
       * function is stored as a pointer.
       */
      Callable_T callable_;

      /**
       * @brief The stored arguments.
       *
       * @details
       * Copies of the arguments passed to `bind_callable()`, decayed; a
       * reference parameter of the callable refers to the copy.
       */
      std::tuple<Args_T...> arguments_;
    };

    // ========================================================================

    /**
     * @brief Non-owning reference to a callable invoked with a `Self_T&`
     * argument.
     *
     * @details
     * Holds the address of the callable and a pointer to a function,
     * instantiated for its type, which converts the address back and
     * invokes the callable. Unlike a `std::function`, it neither copies
     * the callable nor allocates memory, so the callable must outlive
     * the reference.
     *
     * A test case refers to its body this way, since the body is a local
     * object of `runnable_base::create_test_case()`, which runs the test
     * case and destroys it before returning.
     *
     * @tparam Self_T The type referred to by the argument of the
     * callable (`test_case`).
     *
     * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
     */
    template <typename Self_T>
    class callable_ref
    {
    public:
      /**
       * @brief Constructs a reference to a callable.
       *
       * @details
       * The callable must be invocable with a `Self_T&` argument, and
       * must outlive the reference.
       *
       * @tparam Callable_T The type of the callable object.
       *
       * @par Constraints
       *   `Callable_T` is not a `callable_ref`, so that the copy
       *   constructor is used for copies.
       *
       * @param callable The callable object; a non-`const` lvalue.
       */
      template <typename Callable_T>
        requires (!std::is_same_v<std::remove_cv_t<Callable_T>, callable_ref>)
      explicit callable_ref (Callable_T& callable) noexcept;

      /**
       * @brief Invokes the referred callable.
       *
       * @details
       * Not `noexcept`, since a failed `require()` stops the body of a
       * test case by throwing an exception.
       *
       * Always inlined, so that, without optimisations, it adds no frame
       * between `test_case::run()` and `invoke_callable()`.
       *
       * @param self The reference passed to the callable.
       * @par Returns
       *   Nothing.
       */
      [[gnu::always_inline]] void
      operator() (Self_T& self) const;

    private:
      /**
       * @brief Invokes a callable of a given type, from its address.
       *
       * @details
       * Instantiated by the constructor for the type of the callable;
       * its address is stored in `invoke_`.
       *
       * @tparam Callable_T The type of the callable object.
       *
       * @param callable The address of the callable, with its type erased.
       * @param self The reference passed to the callable.
       * @par Returns
       *   Nothing.
       */
      template <typename Callable_T>
      static void
      invoke_callable (void* callable, Self_T& self);

      /**
       * @brief The address of the referred callable.
       *
       * @details
       * Its type is erased; only `invoke_` converts it back.
       */
      void* callable_;

      /**
       * @brief The function that invokes the referred callable.
       *
       * @details
       * The `invoke_callable()` instantiation for the type of the
       * callable; it receives `callable_` and the `Self_T&` argument.
       */
      void (*invoke_) (void* callable, Self_T& self);
    };

    // ------------------------------------------------------------------------
  } // namespace detail

  // ==========================================================================

  /**
   * @ingroup micro-os-plus-micro-test-plus-test-case
   * @brief A named, runnable test case that lives inside a `suite`.
   *
   * @details
   * `test_case` represents a single, named test case or a nested group of
   * checks within a parent `suite` or `test_case`. It is constructed by
   * calling `suite::test()` or `test_case::test()`, both of which create
   * the object, immediately execute its callable body via `run()`, and
   * register the result with the parent node. The object is local to the
   * `test()` call, and is destroyed when it returns, together with the
   * body and the copies of its arguments, which are also local to that
   * call; the test case only refers to them, so no memory is allocated
   * for them.
   *
   * The body of the test case is supplied as a callable (typically a lambda)
   * that receives a `test_case&` reference as its first argument. Inside the
   * body, `expect()` and `require()` are used to evaluate conditions and
   * record the results. Test cases may be nested to an arbitrary depth.
   *
   * The constructor is private, since its parameters are set by the
   * framework; the test cases are created only by `suite::test()` and
   * `test_case::test()`.
   *
   * The class is non-copyable and non-movable to preserve unique ownership
   * and consistent state throughout the test session.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class test_case : public detail::runnable_base
  {
    // Create the test cases, and run them after their creation.
    friend class detail::runnable_base;

  private:
    /**
     * @brief Constructs a test case with a name, runner, parent suite, index,
     * nesting depth, and body.
     *
     * @details
     * Private, since the index, the nesting depth, and the parent suite
     * are internal; a test case constructed elsewhere would not be
     * registered with its parent, and would never run.
     *
     * @param name The test case name or description, used in reports, and
     * the location of the call to `test()` that created the test case.
     * @param test_runner The test runner managing this test case.
     * @param parent_suite The suite that owns this test case.
     * @param own_index The one-based positional index within the parent.
     * @param nesting_depth The depth of nesting; 1 for top-level
     * test cases.
     * @param body A reference to the body, with its arguments already
     * bound, invoked when the test case executes; it must outlive the
     * test case.
     */
    test_case (const test_case_name& name, runner& test_runner,
               suite& parent_suite, size_t own_index, size_t nesting_depth,
               detail::callable_ref<test_case> body);

  public:
    /**
     * @brief Deleted copy constructor to prevent copying.
     *
     * @details
     * A copy would duplicate the counters.
     */
    test_case (const test_case&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     *
     * @details
     * Nodes are referred to by address (e.g. by their children and by
     * the runner), so they must not be relocated.
     */
    test_case (test_case&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     *
     * @details
     * A copy would duplicate the counters.
     */
    test_case&
    operator= (const test_case&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     *
     * @details
     * Nodes are referred to by address (e.g. by their children and by
     * the runner), so they must not be relocated.
     */
    test_case&
    operator= (test_case&&)
        = delete;

    /**
     * @brief Virtual destructor.
     *
     * @details
     * Called when the `test()` function that created the test case
     * returns; the nested test cases were already destroyed by then.
     */
    ~test_case () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Adds a nested test case to this test case, and runs it.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param name The test case name or description, used in reports; a
     * string literal, a `const char*`, or a `std::string`, converted
     * implicitly to `test_case_name`, which also captures the location of
     * the call; it must remain valid while the test case runs.
     * @param callable A generic callable object, usually a lambda,
     * invoked to perform the test.
     * @param arguments A possibly empty list of arguments to be passed to
     * the callable.
     * @par Returns
     *   Nothing.
     */
    template <typename Callable_T, typename... Args_T>
    void
    test (const test_case_name& name, Callable_T&& callable,
          Args_T&&... arguments);

    // ------------------------------------------------------------------------

    /**
     * @ingroup micro-os-plus-micro-test-plus-expectations
     * @brief Evaluate a generic condition and report the results.
     *
     * @tparam Expr_T The type of the custom expression.
     *
     * @par Constraints
     *   Enabled only if `Expr_T` is a framework expression type or
     *   is convertible to `bool` (enforced via a C++20 `requires` clause).
     *
     * @param expr Logical expression to evaluate.
     * @param sl Optional source location, defaulting to the current line.
     * @return An output stream to write optional messages.
     */
    template <class Expr_T>
      requires extension::checkable<Expr_T>
    auto
    expect (const Expr_T& expr, const reflection::source_location& sl
                                = reflection::source_location::current ());

    /**
     * @ingroup micro-os-plus-micro-test-plus-requirements
     * @brief Check a condition and, if false, stop the test case.
     *
     * @details
     * The failure is reported and counted as for `expect()`; then, when
     * exceptions are enabled, the rest of the test case body is skipped,
     * and the run continues with the next test case, as `ASSERT_*` in
     * GoogleTest, `REQUIRE()` in Catch2 and doctest, and `BOOST_REQUIRE()`
     * in Boost.Test do. Without exceptions, the test execution is aborted
     * with `runner::abort()`.
     *
     * The test case is stopped by throwing a private exception, at the end
     * of the statement, after the optional message was appended. It is
     * not derived from `std::exception`; a `catch (...)` in the test case
     * body must rethrow it, and the body must not be `noexcept`.
     *
     * @tparam Expr_T The type of the custom expression.
     *
     * @par Constraints
     *   Enabled only if `Expr_T` is a framework expression type or
     *   is convertible to `bool` (enforced via a C++20 `requires` clause).
     *
     * @param expr Logical expression to evaluate.
     * @param sl Optional source location, defaulting to the current line.
     * @return An output stream to write optional messages.
     */
    template <class Expr_T>
      requires extension::checkable<Expr_T>
    auto
    require (const Expr_T& expr, const reflection::source_location& sl
                                 = reflection::source_location::current ());

    /**
     * @ingroup micro-os-plus-micro-test-plus-requirements
     * @brief Check a condition and, if false, stop the test case.
     *
     * @details
     * The same as `require()`. The name was misleading: in other
     * frameworks (JUnit, Hypothesis), an unmet assumption skips the test,
     * while here it fails it.
     *
     * @deprecated Use `require()` (since 5.1.0).
     *
     * @tparam Expr_T The type of the custom expression.
     *
     * @param expr Logical expression to evaluate.
     * @param sl Optional source location, defaulting to the current line.
     * @return An output stream to write optional messages.
     */
    template <class Expr_T>
      requires extension::checkable<Expr_T>
    [[deprecated ("use require()")]] auto
    assume (const Expr_T& expr, const reflection::source_location& sl
                                = reflection::source_location::current ());

    // ------------------------------------------------------------------------

    /**
     * @brief Returns the nesting depth of this test case.
     *
     * @par Parameters
     *   None.
     * @return The nesting depth (1 = top-level).
     */
    [[nodiscard]] size_t
    nesting_depth (void) const noexcept;

  private:
    /**
     * @brief Executes the test case body by invoking the referred
     * callable.
     *
     * @details
     * Private, since the test case is run only once, by
     * `after_test_case_create()`, right after its creation.
     *
     * Always inlined there, with a non-virtual call, so that, without
     * optimisations, it adds no frame to the call chain of each nested
     * test case; the out-of-line copy is used only through the virtual
     * table.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    [[gnu::always_inline]] void
    run (void) override;

  protected:
#if defined(__cpp_exceptions)
    /**
     * @brief Reports an exception that escaped the test case body as a
     * failed check.
     *
     * @details
     * The failure is reported at the location of the call to `test()`
     * that created the test case, since the location of the `throw` is not
     * known.
     *
     * @param what The explanatory string of a `std::exception`, or
     * `nullptr` for an exception of another type.
     * @par Returns
     *   Nothing.
     */
    void
    fail_unexpected_exception (const char* what);
#endif // defined(__cpp_exceptions)

  protected:
    /**
     * @brief Reference to the test case body, with any bound arguments.
     *
     * @details
     * Invoked by `run()` with a reference to this test case. The body is
     * a local object of `runnable_base::create_test_case()`, which
     * outlives the test case.
     */
    detail::callable_ref<test_case> callable_;

    /**
     * @brief The location of the call to `test()` that created this
     * test case.
     *
     * @details
     * Used to report the failures that are not associated with a check.
     */
    reflection::source_location location_;

    /**
     * @brief Reference to the parent suite that owns this test case.
     *
     * @details
     * The suite into which the totals of the nested test cases are
     * accumulated.
     */
    suite& parent_suite_;

    /**
     * @brief The nesting depth of this test case within the suite.
     *
     * @details
     * 1 for the direct children of a suite; used for indentation.
     */
    size_t nesting_depth_;
  };

  // ==========================================================================

  /**
   * @ingroup micro-os-plus-micro-test-plus-test-suites
   * @brief A named, runnable test suite registered with the test runner.
   *
   * @details
   * `suite` represents a top-level named group of related test cases within
   * the µTest++ framework. It is created by calling `runner::add_suite()`,
   * which constructs the object and stores it in the runner's collection; the
   * stored suites are run later by `runner::run()`, together with the
   * static suites, sorted by name.
   * Each suite records its own timing information and propagates its
   * results to the owning `runner`.
   *
   * The suites to be run, registered or static, are kept in a single
   * list, sorted by name, which does not depend on the runner object:
   * its head is a `constinit` pointer, initialised before any
   * constructor runs, and the links are members of the suites. The list
   * includes the suites of all runners; each runner runs those that
   * refer to it, in the order of the list.
   *
   * The body of a suite is supplied as a callable (typically a lambda) that
   * receives a `suite&` reference as its first argument. Inside the body,
   * `suite::test()` is called to create and run individual test cases.
   *
   * The constructor is protected, since a suite constructed elsewhere
   * would not be registered with the runner; the suites are created only
   * by `runner::add_suite()`, by the derived `static_suite`, which registers
   * itself, and by the runner, for its `top_suite`.
   *
   * The class is non-copyable and non-movable to preserve unique ownership
   * and consistent state throughout the test session.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class suite : public detail::runnable_base
  {
    // Create and register the suites, and time the top suite.
    friend class micro_test_plus::runner;

    // Display the suite duration.
    friend class detail::reporter_human;
    friend class detail::reporter_tap;

  protected:
    /**
     * @brief Constructs a suite with a name, runner, and callable body.
     *
     * @details
     * Protected, since the suite must be registered with the runner,
     * which only `runner::add_suite()` and the `static_suite` constructor
     * do.
     *
     * @tparam Callable_T The type of the callable object.
     * @tparam Args_T The types of any additional callable arguments.
     *
     * @param name The suite name or description, used in reports; it is
     * copied, so the string need not outlive the call.
     * @param test_runner The test runner managing this suite.
     * @param callable A generic callable object, usually a lambda,
     * invoked when the suite executes. Its first parameter must be
     * `suite&`.
     * @param arguments A possibly empty list of arguments forwarded to
     * the callable after the leading `suite&` reference.
     */
    template <typename Callable_T, typename... Args_T>
    suite (std::string_view name, runner& test_runner, Callable_T&& callable,
           Args_T&&... arguments);

  public:
    /**
     * @brief Deleted copy constructor to prevent copying.
     *
     * @details
     * A copy would duplicate the counters and the stored body.
     */
    suite (const suite&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     *
     * @details
     * Nodes are referred to by address (e.g. by their children and by
     * the runner), so they must not be relocated.
     */
    suite (suite&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     *
     * @details
     * A copy would duplicate the counters and the stored body.
     */
    suite&
    operator= (const suite&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     *
     * @details
     * Nodes are referred to by address (e.g. by their children and by
     * the runner), so they must not be relocated.
     */
    suite&
    operator= (suite&&)
        = delete;

    /**
     * @brief Virtual destructor.
     *
     * @details
     * Removes the suite from the list of suites, if it is there, and
     * destroys the owned test cases.
     */
    ~suite () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Adds a test case to the suite, and runs it.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param name The test case name or description, used in reports; a
     * string literal, a `const char*`, or a `std::string`, converted
     * implicitly to `test_case_name`, which also captures the location of
     * the call; it must remain valid while the test case runs.
     * @param callable A generic callable object, usually a lambda,
     * invoked to perform the test.
     * @param arguments A possibly empty list of arguments to be passed to
     * the callable.
     * @par Returns
     *   Nothing.
     */
    template <typename Callable_T, typename... Args_T>
    void
    test (const test_case_name& name, Callable_T&& callable,
          Args_T&&... arguments);

  private:
    /**
     * @brief Executes the suite body by invoking the stored callable.
     *
     * @details
     * Private, since the suites are run only once, by the runner, which
     * is a friend.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    run (void) override;

  protected:
#if defined(__cpp_exceptions)
    /**
     * @brief Reports an exception that escaped the suite body as a failed
     * check of the suite.
     *
     * @details
     * The suite body may throw outside its test cases, for example in a
     * set-up step; the test cases catch their own exceptions. The failure
     * is reported without a source location, since the suites do not
     * record one, and the location of the `throw` is not known.
     *
     * @param what The explanatory string of a `std::exception`, or
     * `nullptr` for an exception of another type.
     * @par Returns
     *   Nothing.
     */
    void
    fail_unexpected_exception (const char* what);
#endif // defined(__cpp_exceptions)

    /**
     * @brief Inserts this suite into the list of suites.
     *
     * @details
     * Called by `runner::register_suite()` and by the `static_suite`
     * constructor, after the name was copied. The suite is inserted
     * after the suites with names less than or equal to its own, so the
     * list remains sorted by name, and the suites with the same name
     * remain in the order of their insertion. The top suite is not
     * inserted, since the runner runs it separately.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    link (void) noexcept;

    /**
     * @brief Removes this suite from the list of suites.
     *
     * @details
     * Called by the destructor; a suite that is not in the list, such as
     * the top suite or a suite rejected by the runner, is left
     * unchanged.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    unlink (void) noexcept;

  protected:
    /**
     * @brief Callable storing the suite body and any bound arguments.
     *
     * @details
     * Invoked by `run()` with a reference to this suite; a
     * `static_suite` also stores its body here, so all suite callables
     * receive a `suite&` reference.
     */
    std::function<void (suite&)> callable_;

    /**
     * @brief Stopwatch of this suite.
     *
     * @details
     * Measures the duration of the suite; started and stopped by
     * `run()` (by the runner, for the top suite), and read by the
     * reporters, which are friends.
     */
    detail::stopwatch stopwatch_;

    /**
     * @brief A copy of the suite name.
     *
     * @details
     * The suites registered with `runner::add_suite()`, and the static suites,
     * run later, when the string passed to the constructor may no longer
     * exist; the name is therefore copied here, and the name of the node
     * points to this copy. The test cases, which run immediately, do not
     * copy their names.
     */
    std::string owned_name_{};

    /**
     * @brief The next suite in the list of suites.
     *
     * @details
     * Null for the last suite, and for the suites not in the list. Set
     * by `link()` and `unlink()`, and read by the runner, which is a
     * friend.
     */
    suite* next_ = nullptr;

    /**
     * @brief The first suite in the list of suites.
     *
     * @details
     * The list includes the registered and the static suites of all
     * runners, sorted by name; each runner selects its own. The pointer
     * is constant-initialised (`constinit`, in `src/test.cpp`), so it is
     * null before any constructor runs, whatever the order of the static
     * initialisation across translation units.
     */
    static suite* first_;
  };

  // ==========================================================================

  /**
   * @brief The implicit top-level suite owned by every `runner` instance.
   *
   * @details
   * `top_suite` is a thin specialisation of `suite` used as the implicit
   * root context for the `runner`. It is created by the `runner` constructor
   * and is available to user code via `runner::initialise()`, which returns
   * a reference to it. Unlike regular `suite` objects, `top_suite` is not
   * stored in the runner's child-suite vector; instead it is a direct member
   * of `runner`.
   *
   * The constructor is private; only the runner constructs its top
   * suite.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class top_suite : public suite
  {
    // Construct the top suite, a member of the runner.
    friend class micro_test_plus::runner;

  private:
    /**
     * @brief Constructs the top-level suite with a name and runner reference.
     *
     * @details
     * Private, since each runner has exactly one top suite, which it
     * constructs as a member.
     *
     * @param name The suite name used in reports.
     * @param test_runner The test runner that owns this suite.
     */
    top_suite (const char* name, runner& test_runner);

  public:
    /**
     * @brief Deleted copy constructor to prevent copying.
     *
     * @details
     * A copy would duplicate the counters and the stored body.
     */
    top_suite (const top_suite&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     *
     * @details
     * Nodes are referred to by address (e.g. by their children and by
     * the runner), so they must not be relocated.
     */
    top_suite (top_suite&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     *
     * @details
     * A copy would duplicate the counters and the stored body.
     */
    top_suite&
    operator= (const top_suite&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     *
     * @details
     * Nodes are referred to by address (e.g. by their children and by
     * the runner), so they must not be relocated.
     */
    top_suite&
    operator= (top_suite&&)
        = delete;

    /**
     * @brief Virtual destructor.
     *
     * @details
     * Destroys the owned test cases.
     */
    ~top_suite () override;
  };

  // ==========================================================================

  /**
   * @ingroup micro-os-plus-micro-test-plus-test-suites
   * @brief A test suite designed for static (namespace-scope) registration
   * with a `runner`.
   *
   * @details
   * `static_suite` extends `suite` to support the pattern where test suites
   * are declared as namespace-scope objects and therefore constructed before
   * or after the `runner` instance, in unspecified static-initialisation
   * order.
   *
   * Upon construction, the suite inserts itself into the list of suites,
   * kept sorted by name, which does not depend on the runner object (see
   * `suite`). The runner is only referred to, not accessed, so it may be
   * constructed later. When `runner::run()` is called, the runner runs
   * the suites that refer to it, static or registered with
   * `runner::add_suite()`, in the order of the list; for equal names, in
   * the order of their insertion, so the static suites constructed
   * before `main()` run first. Upon destruction, the suite removes
   * itself from the list.
   *
   * The body is stored in the callable inherited from `suite`, and is run
   * by `suite::run()`; the user callable receives a `suite&` reference,
   * as for the suites registered with `runner::add_suite()`, so the same
   * function can serve both kinds of suites.
   *
   * The class is non-copyable and non-movable to preserve unique ownership
   * and consistent state throughout the test session.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class static_suite : public suite
  {
  public:
    /**
     * @brief Class template constructor for static_suite.
     *
     * @details
     * The runner is only referred to, not accessed, so it may be a
     * namespace-scope object constructed after this suite.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param name The test suite name or description, used in reports; it
     * is copied, so the string need not outlive the call.
     * @param test_runner The test runner that runs this suite.
     * @param callable A generic callable object, usually a lambda or
     * function, invoked to perform the test suite. Its first parameter
     * must be `suite&`.
     * @param arguments A possibly empty list of arguments forwarded to
     * the callable after the leading `suite&` reference.
     */
    template <typename Callable_T, typename... Args_T>
    static_suite (const char* name, runner& test_runner, Callable_T&& callable,
                  Args_T&&... arguments);

    /**
     * @brief Deleted copy constructor to prevent copying.
     *
     * @details
     * A copy would duplicate the counters and the stored body.
     */
    static_suite (const static_suite&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     *
     * @details
     * Nodes are referred to by address (e.g. by their children and by
     * the runner), so they must not be relocated.
     */
    static_suite (static_suite&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     *
     * @details
     * A copy would duplicate the counters and the stored body.
     */
    static_suite&
    operator= (const static_suite&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     *
     * @details
     * Nodes are referred to by address (e.g. by their children and by
     * the runner), so they must not be relocated.
     */
    static_suite&
    operator= (static_suite&&)
        = delete;

    /**
     * @brief Virtual destructor.
     *
     * @details
     * The suite is removed from the list of suites by the `suite`
     * destructor, which also destroys the owned test cases and the
     * stored callable.
     */
    ~static_suite () override;
  };

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/test-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_H_

// ----------------------------------------------------------------------------

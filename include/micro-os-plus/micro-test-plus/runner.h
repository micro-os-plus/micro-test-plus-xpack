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
 * @brief C++ header file with declarations for the µTest++ test runner.
 *
 * @details
 * This header provides the declarations for the test runner facilities used
 * within the µTest++ framework. It defines the interface for managing the
 * registration and execution of test suites, supporting automated discovery
 * and orchestration of tests across a project.
 *
 * The test runner is responsible for initialising the test environment,
 * registering test suites, managing command-line arguments, and determining
 * the overall test result via an exit code. It also provides mechanisms for
 * aborting test execution and retrieving the default suite name.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_RUNNER_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_RUNNER_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#if __has_include("micro-os-plus/project-config.h")
#include "micro-os-plus/project-config.h"
#endif // __has_include("micro-os-plus/project-config.h")

#if __has_include("micro-os-plus/micro-test-plus-defines.h")
#include "micro-os-plus/micro-test-plus-defines.h"
#endif // __has_include("micro-os-plus/micro-test-plus-defines.h")

#include "timings.h"
#include "test.h"
#include "reflection.h"

#include <functional>
#include <memory>
#include <string>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
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

/**
 * @namespace micro_os_plus::micro_test_plus
 * @brief Primary namespace for the µTest++ testing framework.
 *
 * @details
 * The `micro_os_plus::micro_test_plus` namespace encapsulates all core
 * components, types, and utilities of the µTest++ testing framework, providing
 * a dedicated scope for its public API.
 *
 * This namespace is structured into several nested namespaces, each
 * responsible for a specific aspect of the framework, such as mathematical
 * utilities, type traits, literals, test suite and test case management, test
 * runners, test reporters, internal details, operators, and utility functions.
 *
 * By grouping all definitions within this namespace and its sub-namespaces,
 * the framework achieves clear code organisation, minimises naming conflicts,
 * and enhances maintainability. This modular structure supports robust,
 * scalable, and professional test development for both embedded and general
 * C++ projects.
 *
 * All public API definitions are implemented in the `include/micro-os-plus`
 * folder, ensuring a clear separation from user code and facilitating
 * straightforward integration with the wider µOS++ ecosystem.
 */
namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  class suite;
  class top_suite;
  class reporter;

  // ==========================================================================

  /**
   * @ingroup micro-os-plus-micro-test-plus-runners
   * @brief The test runner for the µTest++ framework.
   *
   * @details
   * The `runner` class is responsible for managing the registration and
   * execution of test suites within the µTest++ framework. It maintains a
   * collection of test suites, each of which registers itself automatically
   * upon construction, enabling seamless integration and execution of tests
   * across different components and folders of a project.
   *
   * The test runner provides methods for initialising the test environment,
   * registering test suites, retrieving the runner's name, and determining the
   * overall test result via an exit code. It also offers an abort mechanism
   * for terminating test execution in exceptional circumstances.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class runner : public detail::test_node
  {
  public:
    /**
     * @brief Constructor for the runner class.
     *
     * @par Parameters
     *   None.
     */
    runner (void);

    /**
     * @brief Deprecated constructor for the runner class.
     *
     * @param top_suite_name The name given to the implicit top suite.
     * Defaults to an empty string.
     *
     * @deprecated Use the anonymous constructor.
     */
    runner (const char* top_suite_name);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    runner (const runner&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    runner (runner&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    runner&
    operator= (const runner&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    runner&
    operator= (runner&&)
        = delete;

    /**
     * @brief Destructor for the runner class.
     */
    virtual ~runner () override;

    /**
     * @brief Initialises the test runner with command-line arguments.
     *
     * @param argc The argument count from main().
     * @param argv The argument vector from main().
     * @param top_suite_name The name given to the implicit top suite. Defaults
     * to an empty string.
     * @return Reference to the top-level test suite.
     */
    class suite&
    initialise (int argc, char* argv[], const char* top_suite_name = "");

    /**
     * @brief Returns 0 if all tests were successful, 1 otherwise.
     *
     * @par Parameters
     *	 None.
     * @return Integer exit code representing the overall test result.
     */
    int
    exit_code (void);

    /**
     * @brief Adds a test suite to the runner.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param name The test suite name or description, used in reports.
     * @param callable A generic callable object, usually a lambda,
     * invoked to perform the test suite.
     * @param arguments A possibly empty list of arguments to be passed to
     * the callable.
     * @par Returns
     *   Nothing.
     */
    template <typename Callable_T, typename... Args_T>
    void
    suite (const char* name, Callable_T&& callable, Args_T&&... arguments);

    // ------------------------------------------------------------------------

    /**
     * @brief Aborts test execution immediately.
     *
     * @param sl The source location from which the abort is triggered.
     * @par Returns
     *   Nothing.
     */
    [[noreturn]] void
    abort (const reflection::source_location& sl
           = reflection::source_location::current ());

    // ------------------------------------------------------------------------
    // Getters.

    /**
     * @brief Returns the total count of registered test suites.
     *
     * @par Parameters
     *	 None.
     * @return The total number of test suites managed by this runner.
     */
    [[nodiscard]] virtual size_t
    total_suites_count (void) const noexcept;

    /**
     * @brief Returns a reference to the test reporter.
     *
     * @par Parameters
     *	 None.
     * @return Reference to the test reporter.
     */
    [[nodiscard]] class reporter&
    reporter (void) const noexcept;

    /**
     * @brief Gets the timings for this runner.
     *
     * @par Parameters
     *	 None.
     * @return A reference to the timestamps instance.
     */
    [[nodiscard]] detail::timestamps&
    timings () noexcept;

    /**
     * @brief Gets the timings for this runner (const overload).
     *
     * @par Parameters
     *	 None.
     * @return A const reference to the timestamps instance.
     */
    [[nodiscard]] const detail::timestamps&
    timings () const noexcept;

    /**
     * @brief Returns the count of test suites.
     *
     * @par Parameters
     *	 None.
     * @return The number of test suites, including the top one.
     */
    [[nodiscard]] size_t
    suites_count (void) const noexcept;

  protected:
    /**
     * @brief Runs all registered test suites.
     *
     * @par Parameters
     *	 None.
     */
    virtual void
    run_suites_ (void);

    /**
     * @brief Registers a test suite with the runner.
     *
     * @param suite Owning pointer to the test suite to register.
     * @par Returns
     *   Nothing.
     */
    void
    register_suite_ (std::unique_ptr<class suite> suite);

    // ------------------------------------------------------------------------
  protected:
    /**
     * @brief The implicit top-level suite; always present and executed first.
     */
    class top_suite top_suite_;

    /**
     * @brief Owning collection of dynamically registered child suites.
     *
     * @details
     * Each call to `runner::suite()` appends a new `suite` to this vector
     * and runs it immediately. The vector retains ownership of all suites
     * for the lifetime of the runner.
     */
    std::vector<std::unique_ptr<class suite>> children_suites_;

    /**
     * @brief Pointer to the test reporter used for outputting test results.
     */
    std::unique_ptr<class reporter> reporter_;

    /**
     * @brief Timings for this runner.
     */
    detail::timestamps timings_;

    /**
     * @brief Owned storage for the implicit top-suite name.
     */
    std::string top_suite_name_;
  };

  // ==========================================================================

  /**
   * @ingroup micro-os-plus-micro-test-plus-runners
   * @brief A `runner` variant that also manages statically-registered test
   * suites.
   *
   * @details
   * `static_runner` extends `runner` to handle `static_suite` objects that
   * are declared at namespace scope and therefore constructed before or after
   * the runner itself, in unspecified static-initialisation order.
   *
   * The key design constraint is that `static_runner` instances must
   * themselves be declared at namespace scope (in the BSS segment), so the
   * pointer `static_children_suites_` is zero-initialised by the C runtime
   * before any constructor runs. This ensures that `static_suite` objects
   * constructed before `static_runner` can safely append themselves to the
   * vector without losing registrations.
   *
   * During `exit_code()`, `run_suites_()` is called, which first runs all
   * dynamically registered suites (base class behaviour) and then iterates
   * over the statically registered suites.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class static_runner final : public runner
  {
  public:
    /**
     * @brief Constructor for the runner class.
     *
     * @par Parameters
     *   None.
     */
    static_runner (void);

    /**
     * @brief Constructs the static runner with a top-suite name.
     *
     * @param top_suite_name The name of the implicit top-level suite.
     * Defaults to an empty string.
     *
     * @deprecated Use the anonymous constructor.
     */
    static_runner (const char* top_suite_name);

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    static_runner (const static_runner&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     */
    static_runner (static_runner&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    static_runner&
    operator= (const static_runner&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     */
    static_runner&
    operator= (static_runner&&)
        = delete;

    /**
     * @brief Destructor for the static_runner class.
     */
    virtual ~static_runner () override;

    // ------------------------------------------------------------------------

    /**
     * @brief Registers a static test suite with the runner.
     *
     * @param runner The static runner instance.
     * @param suite The static test suite to register.
     */
    static void
    register_static_suite (static_runner& runner, static_suite& suite);

    /**
     * @brief Returns the total count of registered static test suites.
     *
     * @par Parameters
     *	 None.
     * @return The total number of registered static test suites.
     */
    [[nodiscard]] size_t
    static_suites_count (void) const noexcept;

    /**
     * @brief Returns the total count of all test suites, including static and
     * dynamic.
     *
     * @par Parameters
     *	 None.
     * @return The total number of test suites.
     */
    [[nodiscard]] virtual size_t
    total_suites_count (void) const noexcept final override;

  protected:
    /**
     * @brief Runs all child suites, including statically registered ones.
     *
     * @par Parameters
     *	 None.
     */
    void
    run_suites_ (void) override;

  protected:
    /**
     * @brief Pointer to the vector of registered static test suites.
     *
     * `static_runner` instances are always declared at namespace scope,
     * so this pointer lives in the BSS segment and is zero-initialised
     * before any constructor runs. This guarantees that static test suites
     * registered before this runner's constructor executes (due to
     * unspecified static initialisation order across translation units)
     * are not lost. The pointer MUST NOT carry an explicit
     * default member initialiser, as that would run during construction
     * and could overwrite a value already set by an earlier-constructed
     * `static_suite`.
     */
    std::vector<static_suite*>* static_children_suites_;
  };

} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ============================================================================
// Templates, inlines & constexpr implementations.

#include "inlines/runner-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TEST_RUNNER_H_

// ----------------------------------------------------------------------------

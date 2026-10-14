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
 * within the µTest++ framework. It defines the `runner` class, which manages
 * the registration and execution of test suites, including the static
 * suites declared at namespace scope, and the deprecated `static_runner`
 * alias.
 *
 * The test runner is responsible for initialising the test environment,
 * creating the reporter, registering test suites, processing command-line
 * arguments, and determining the overall test result via an exit code. It
 * also provides a mechanism for aborting test execution.
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

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_H_

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
#include "reporter.h"
#include "runner-options.h"
#include "runner-totals.h"

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
 * The main classes (the runners, and the suites and subtests) are defined
 * directly in this namespace. Several nested namespaces group specific
 * aspects of the framework: `math` (mathematical utilities), `type_traits`
 * (type traits and value wrappers), `reflection` (source locations and type
 * names), `literals` (user-defined literals), `operators` (comparison and
 * logical operators), `utility` (utility functions), and `detail` (internal
 * implementation details, including the reporters).
 *
 * By grouping all definitions within this namespace and its sub-namespaces,
 * the framework achieves clear code organisation, minimises naming conflicts,
 * and enhances maintainability.
 *
 * All public API definitions are implemented in the
 * `include/micro-os-plus/micro-test-plus` folder, ensuring a clear
 * separation from user code and facilitating straightforward integration
 * with the wider µOS++ ecosystem.
 */
namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  class suite;
  class top_suite;

  // ==========================================================================

  /**
   * @ingroup micro-os-plus-micro-test-plus-runners
   * @brief The test runner for the µTest++ framework.
   *
   * @details
   * The `runner` class is responsible for managing the registration and
   * execution of test suites within the µTest++ framework. It owns the
   * implicit top suite, whose test cases are added after `initialise()`,
   * and a collection of test suites added with `suite()`, which are run
   * later, sorted by name, by `run()`. The `static_suite` objects that
   * refer to the runner are run after them, also sorted by name; they are
   * kept in a list independent of the runner object, so they may be
   * constructed before it.
   *
   * The test runner provides methods for initialising the test environment
   * (including the creation of the reporter selected on the command line,
   * or by the `runner_options` passed to `initialise()`),
   * registering test suites, and determining the overall test result via an
   * exit code. It also offers an abort mechanism for terminating test
   * execution in exceptional circumstances.
   *
   * The runner is not a node of the test tree: it has no name of its own
   * (the name shown in the reports belongs to the top suite), and it owns
   * the session totals, which accumulate the totals of all the suites.
   *
   * All members and methods are defined within the
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class runner
  {
    // Display the session duration.
    friend class detail::reporter_human;
    friend class detail::reporter_tap;

    // Pass the reporter to the suites and the test cases.
    friend class detail::runnable_base;

  public:
    /**
     * @brief Constructor for the runner class.
     *
     * @details
     * The top suite name is set later, by `initialise()`.
     *
     * @par Parameters
     *   None.
     */
    runner (void);

    /**
     * @brief Deprecated constructor for the runner class.
     *
     * @details
     * The name can still be overridden by `initialise()`.
     *
     * @param top_suite_name The name given to the implicit top suite.
     *
     * @deprecated Use the anonymous constructor.
     */
    runner (const char* top_suite_name);

    /**
     * @brief Deleted copy constructor to prevent copying.
     *
     * @details
     * The runner owns the suites, the reporter, and the session totals,
     * which must not be duplicated.
     */
    runner (const runner&) = delete;

    /**
     * @brief Deleted move constructor to prevent moving.
     *
     * @details
     * The suites keep a reference to the runner, so it must not be
     * relocated.
     */
    runner (runner&&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     *
     * @details
     * The runner owns the suites, the reporter, and the session totals,
     * which must not be duplicated.
     */
    runner&
    operator= (const runner&)
        = delete;

    /**
     * @brief Deleted move assignment operator to prevent moving.
     *
     * @details
     * The suites keep a reference to the runner, so it must not be
     * relocated.
     */
    runner&
    operator= (runner&&)
        = delete;

    /**
     * @brief Destructor for the runner class.
     *
     * @details
     * Destroys the registered suites and the reporter, which closes the
     * output file, if any. The static suites are not owned by the runner.
     */
    ~runner ();

    /**
     * @brief Initialises the test runner with command-line arguments.
     *
     * @details
     * Parses the µTest++ options from the command line (`--reporter`,
     * `--silent`, `--quiet`, `--verbose`, and `--output-file`) into a
     * `runner_options` structure, and continues as the overload taking
     * the options. The other arguments are ignored, since the
     * applications may define their own.
     *
     * A missing option argument, or an unknown reporter name, is reported
     * on `stderr` and the option is ignored; the tests are still run, but
     * `run()` returns 2.
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
     * @brief Initialises the test runner with the given options.
     *
     * @details
     * Creates the selected reporter, starts the session, and returns the
     * top suite, without parsing a command line; intended for the
     * applications that do not have one, such as the embedded ones
     * without semihosting arguments.
     *
     * If no name is given, here or by the deprecated constructor, the top
     * suite is named after `options.arguments[0]`, when available, or
     * "default suite".
     *
     * If the output file cannot be opened, the error is reported on
     * `stderr` and the report is written only to the console; the tests
     * are still run, but `run()` returns 2.
     *
     * @param options The session options; the strings they refer to must
     * remain valid until the call returns.
     * @param top_suite_name The name given to the implicit top suite. Defaults
     * to an empty string.
     * @return Reference to the top-level test suite.
     *
     * @since 5.1.0
     */
    class suite&
    initialise (const runner_options& options,
                const char* top_suite_name = "");

    /**
     * @brief Runs the registered suites, ends the session, and returns the
     * exit code.
     *
     * @details
     * Completes the top suite, runs the suites registered with `suite()`
     * and the static suites that refer to this runner, and ends the
     * session.
     *
     * The session runs only once; later calls return the same exit code
     * without running anything again.
     *
     * @par Parameters
     *   None.
     * @return 0 if all checks were successful, 1 otherwise, or if the runner
     * was not initialised, and 2 if `initialise()` reported an option
     * error, regardless of the checks.
     *
     * @since 5.1.0
     */
    int
    run (void);

    /**
     * @brief Deprecated name of `run()`.
     *
     * @details
     * Calls `run()`; once the session has ended, it only returns the exit
     * code.
     *
     * @par Parameters
     *   None.
     * @return The value returned by `run()`.
     *
     * @deprecated Use `run()` (since 5.1.0).
     */
    int
    exit_code (void);

    /**
     * @brief Adds a test suite to the runner, to be run by `run()`.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param name The test suite name or description, used in reports; it
     * is copied, so the string need not outlive the call.
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
     * @brief The type of the function called when test execution is
     * aborted.
     *
     * @details
     * The handler receives the source location from which the abort was
     * triggered. It is not expected to return; it may, for example, reset
     * an embedded target, signal the test result to a debugger, or throw
     * an exception (except when called from a check, which reports from a
     * destructor). If it returns, the process is terminated with
     * `::abort()`.
     *
     * @since 5.1.0
     */
    using abort_handler_t = void (*) (const reflection::source_location& sl);

    /**
     * @brief Sets the function called when test execution is aborted.
     *
     * @details
     * Test execution is aborted by a failed `require()`, when exceptions
     * are not enabled (otherwise only the test case is stopped), or when
     * the reporter detects an internal inconsistency. The diagnostic message
     * is written to `stderr` before the handler is called.
     *
     * The handler can be set at any time, before or after `initialise()`.
     *
     * @param handler The new handler, or `nullptr` to restore the default
     * behaviour, which terminates the process with `::abort()`.
     * @return The previous handler, or `nullptr` if none was set.
     *
     * @since 5.1.0
     */
    abort_handler_t
    set_abort_handler (abort_handler_t handler) noexcept;

    /**
     * @brief Aborts test execution immediately.
     *
     * @details
     * Writes the source location to `stderr`, and calls the handler set by
     * `set_abort_handler()`, if any. If there is no handler, or if it
     * returns, the process is terminated with `::abort()`.
     *
     * @param sl The source location from which the abort is triggered.
     * @par Returns
     *   Does not return.
     */
    [[noreturn]] void
    abort (const reflection::source_location& sl
           = reflection::source_location::current ());

    // ------------------------------------------------------------------------
    // Getters.

    /**
     * @brief Returns the total count of registered test suites.
     *
     * @details
     * The sum of `suites_count()` and `static_suites_count()`.
     *
     * @par Parameters
     *   None.
     * @return The total number of test suites managed by this runner,
     * including the top suite and the static suites.
     */
    [[nodiscard]] size_t
    total_suites_count (void) const noexcept;

    /**
     * @brief Returns the verbosity level of the console output.
     *
     * @details
     * The level is selected with the `--silent`, `--quiet`, and
     * `--verbose` command-line options, or with
     * `runner_options::verbosity_level`; the tests can use it to decide
     * whether to display their own messages. Valid only after
     * `initialise()` has been called.
     *
     * @par Parameters
     *   None.
     * @return The active `verbosity` value.
     *
     * @since 5.1.0
     */
    [[nodiscard]] auto
    verbosity (void) const noexcept -> micro_test_plus::verbosity;

    /**
     * @brief Returns the count of test suites.
     *
     * @par Parameters
     *   None.
     * @return The number of test suites, including the top one.
     */
    [[nodiscard]] size_t
    suites_count (void) const noexcept;

    /**
     * @brief Returns the count of static test suites.
     *
     * @details
     * Counts the `static_suite` objects that refer to this runner; it is
     * complete only after the static initialisation.
     *
     * @par Parameters
     *   None.
     * @return The number of static test suites run by this runner.
     */
    [[nodiscard]] size_t
    static_suites_count (void) const noexcept;

    /**
     * @brief Gets the totals of the test session.
     *
     * @details
     * The counters include the checks and the test cases of all the
     * suites that were run, including the top suite; they are complete
     * only after `run()` has returned. The totals are read-only; there is
     * no non-const overload, so that the counters cannot be modified from
     * the test code.
     *
     * @par Parameters
     *   None.
     * @return A const reference to the session totals.
     */
    [[nodiscard]] const runner_totals&
    totals () const noexcept;

  protected:
    /**
     * @brief Returns a reference to the test reporter.
     *
     * @details
     * Protected, since the reporter is internal to the framework; it is
     * used by the suites and the test cases, through
     * `detail::runnable_base`, which is a friend.
     *
     * @par Parameters
     *   None.
     * @return Reference to the test reporter.
     */
    [[nodiscard]] detail::reporter&
    reporter (void) const noexcept;

    /**
     * @brief Gets the timings for this runner.
     *
     * @details
     * Protected, since the timings are an implementation detail; they
     * are set by `run()`, and are read only by the reporters, which are
     * friends.
     *
     * @par Parameters
     *   None.
     * @return A reference to the timestamps instance.
     */
    [[nodiscard]] detail::timestamps&
    timings () noexcept;

    /**
     * @brief Gets the timings for this runner (const overload).
     *
     * @details
     * Protected, for the same reasons as the non-const overload.
     *
     * @par Parameters
     *   None.
     * @return A const reference to the timestamps instance.
     */
    [[nodiscard]] const detail::timestamps&
    timings () const noexcept;

    /**
     * @brief Runs all registered test suites.
     *
     * @details
     * Runs the suites registered with `suite()`, then the static suites
     * that refer to this runner.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
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

    /**
     * @brief Parses the command-line options of the test session.
     *
     * @details
     * All the options are parsed here, once, and passed to the reporter;
     * the arguments not recognised as options are ignored, since the
     * applications may define their own. A missing option argument, or
     * an unknown reporter name, is reported on `stderr`, the option is
     * ignored, and `has_option_errors_` is set.
     *
     * @param argc The argument count from main().
     * @param argv The argument vector from main().
     * @return The parsed options.
     */
    [[nodiscard]] runner_options
    parse_options_ (int argc, char* argv[]);

    // ------------------------------------------------------------------------
  protected:
    /**
     * @brief The implicit top-level suite; always present and executed first.
     *
     * @details
     * Its test cases are added directly, between `initialise()` and
     * `run()`.
     */
    class top_suite top_suite_;

    /**
     * @brief Owning collection of dynamically registered child suites.
     *
     * @details
     * Each call to `runner::suite()` appends a new `suite` to this vector;
     * the suites are run later, by `run()`. The vector retains
     * ownership of all suites for the lifetime of the runner.
     */
    std::vector<std::unique_ptr<class suite>> children_suites_;

    /**
     * @brief Owning pointer to the test reporter used for outputting test
     * results.
     *
     * @details
     * Created by `initialise()`, as selected by the session options,
     * either given by the caller or parsed from the command line by
     * `parse_options_()`.
     */
    std::unique_ptr<detail::reporter> reporter_;

    /**
     * @brief Timings for this runner.
     *
     * @details
     * Measure the duration of the entire test session.
     */
    detail::timestamps timings_;

    /**
     * @brief Totals of the test session.
     *
     * @details
     * The totals of each suite are added by `run()` and `run_suites_()`,
     * after the suite was run.
     */
    runner_totals totals_;

    /**
     * @brief Owned storage for the implicit top-suite name.
     *
     * @details
     * Set by `initialise()`, either from its argument or derived from
     * `argv[0]`, as kept in the session options.
     */
    std::string top_suite_name_;

    /**
     * @brief The states of a test session.
     *
     * @details
     * The session moves only forwards, from `created` to `initialised`
     * (by `initialise()`) and to `finished` (by `run()`); the calls made in
     * another state are reported or ignored.
     */
    enum class session_state_t
    {
      created, /**< Constructed; `initialise()` not yet called. */
      initialised, /**< Initialised; test cases may be added and run. */
      finished /**< All suites run and the session ended. */
    };

    /**
     * @brief The current state of the test session.
     *
     * @details
     * Set by `initialise()` and `run()`.
     */
    session_state_t session_state_ = session_state_t::created;

    /**
     * @brief The exit code computed by `run()`.
     *
     * @details
     * Returned again by the calls of `run()` made after the session
     * ended.
     */
    int exit_code_ = 1;

    /**
     * @brief Whether `initialise()` reported an option error.
     *
     * @details
     * Set for a missing option argument, an unknown reporter name, or an
     * output file that cannot be opened; `run()` then returns 2.
     */
    bool has_option_errors_ = false;

    /**
     * @brief The function called by `abort()`, if not null.
     *
     * @details
     * Set by `set_abort_handler()`.
     */
    abort_handler_t abort_handler_ = nullptr;
  };

  // ==========================================================================

  /**
   * @ingroup micro-os-plus-micro-test-plus-runners
   * @brief Deprecated name of `runner`.
   *
   * @details
   * The `runner` also runs the `static_suite` objects that refer to it,
   * so a separate runner class is no longer needed.
   *
   * @deprecated Use `runner` (since 5.1.0).
   */
  using static_runner = runner;

  // --------------------------------------------------------------------------
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

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_H_

// ----------------------------------------------------------------------------

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
 * @brief C++ header file with declarations for the µTest++ test runner.
 *
 * @details
 * This header provides the declarations for the test runner facilities used
 * within the µTest++ framework. It defines the `runner` class, which manages
 * the registration and execution of test suites, including the static
 * suites declared at namespace scope. The deprecated `static_runner`
 * alias is declared in `deprecated.h`.
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

#include "stopwatch.h"
#include "test.h"
#include "reflection.h"
#include "reporter.h"
#include "runner-options.h"
#include "counters.h"

#include <functional>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

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
 * The main classes (the runners, and the suites and test cases) are defined
 * directly in this namespace. Several nested namespaces group specific
 * aspects of the framework: `math` (mathematical utilities), `extension`
 * (the concepts for custom comparators, operators, and helpers),
 * `reflection` (source locations and type names), `literals` (user-defined
 * literals), `operators` (comparison and logical operators), `utility`
 * (utility functions), and `detail` (internal implementation details,
 * including the reporters and the value wrappers).
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
  class test_case;
  class top_suite;

  // ==========================================================================

  /**
   * @ingroup micro-os-plus-micro-test-plus-cpp-api-runners
   * @brief The test runner for the µTest++ framework.
   *
   * @details
   * The `runner` class is responsible for managing the registration and
   * execution of test suites within the µTest++ framework. It owns the
   * optional top suite, returned by `add_top_suite()`, whose test cases
   * run immediately, in `main()`, and a collection of test suites added
   * with `add_suite()`, which are run later, by `run_suites()`. These
   * suites and the `static_suite` objects that refer to the runner are kept
   * in a single list, sorted by name, independent of the runner object,
   * so the static suites may be constructed before it. `run_suites()` runs
   * the suites added with `add_suite()` and the static suites together, in a
   * single order, sorted by name; for equal names, in the order of their
   * creation, so the static suites constructed before `main()` run first.
   * The names are compared byte by byte, as by `std::strcmp()`, not in
   * the order of addition: the comparison is case-sensitive (`"Zeta"`
   * before `"alpha"`) and does not compare numbers by value (`"Suite 10"`
   * before `"Suite 2"`); zero-padded numeric prefixes (`"01 - Init"`) give
   * an explicit order.
   *
   * Several runners may coexist, global or local, each with its own
   * static suites and suites added with `add_suite()`. The list of suites
   * is shared by all the runners; each suite refers to its runner, and
   * `run_suites()` runs only the suites that refer to this runner, skipping
   * those of the other runners, so the runners do not interfere. The list
   * is not protected by a lock: the runners must not run, and the suites
   * must not be created or destroyed, concurrently from different threads.
   *
   * The test runner provides member functions for initialising the test
   * environment (including the creation of the reporter selected by the
   * `runner_options` passed to `initialise()`), registering test suites,
   * and determining the overall test result via an exit code. It also
   * offers an abort mechanism for terminating test execution in
   * exceptional circumstances.
   *
   * Both `initialise()` and `add_top_suite()` are optional:
   *
   * @code{.cpp}
   * mt::runner tr;
   * 
   * int
   * main (int argc, char* argv[])
   * {
   *   tr.initialise (argc, argv);
   *
   *   auto& ts = tr.add_top_suite ("Main");
   *   ts.test ("Check something", [] (auto& t) { t.expect (true); });
   *
   *   return tr.run_suites ();
   * }
   * @endcode
   *
   * Without `initialise()`, the default options are used; without
   * `add_top_suite()`, there is no top suite, and `run_suites()` runs only the
   * suites added with `add_suite()` and the static suites.
   *
   * The runner is not a node of the test tree: it has no name of its own
   * (the names shown in the reports belong to the suites), and it owns
   * the session totals, which accumulate the totals of all the suites.
   *
   * All members are defined within the
   * `micro_os_plus::micro_test_plus` namespace, ensuring clear separation from
   * user code and minimising the risk of naming conflicts.
   *
   * @headerfile micro-test-plus.h "micro-os-plus/micro-test-plus.h"
   */
  class runner
  {
    /**
     * @brief The human reporter, which displays the session.
     *
     * @details
     * It reads the stopwatch, to display the duration of the session.
     */
    friend class detail::reporter_human;

    /**
     * @brief The TAP reporter, which displays the session.
     *
     * @details
     * It reads the stopwatch, to display the duration of the session.
     */
    friend class detail::reporter_tap;

    /**
     * @brief The base of the nodes, which shares the state of the
     * session.
     *
     * @details
     * It passes the reporter to the suites and the test cases, applies
     * the filter, lists the test cases, keeps the running test case,
     * and aborts for a failed requirement.
     */
    friend class detail::runnable_base;

    /**
     * @brief The static suites link themselves through the runner.
     *
     * @details
     * The `static_suite` constructors call `link_static_suite()`, which
     * rejects the suites constructed after `run_suites()` has started.
     */
    friend class static_suite;

  public:
    /**
     * @brief Constructor for the runner class.
     *
     * @details
     * The session is configured later, by `initialise()`, and the top
     * suite, if any, is added by `add_top_suite()`.
     *
     * @par Parameters
     *   None.
     */
    runner (void);

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated constructor for the runner class.
     *
     * @details
     * Use the anonymous constructor, and pass the name to
     * `add_top_suite()`, which can also override the name given here.
     *
     * @param top_suite_name The name given to the top suite.
     */
    [[deprecated ("use runner() and add_top_suite() (since 4.1.0)")]]
    runner (const char* top_suite_name);

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

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

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated initialisation with the command-line arguments,
     * which also adds the top suite.
     *
     * @details
     * Equivalent to `initialise (argc, argv)` followed by
     * `add_top_suite (top_suite_name)`. Use the two calls; the top
     * suite is now optional, and `initialise()` no longer returns it.
     *
     * The name no longer has a default value, so that the call with two
     * arguments selects the current `initialise (argc, argv)`, which
     * returns nothing and does not add the top suite.
     *
     * If the runner is already initialised, or the test execution was
     * aborted, the error is reported on `stderr`, as by `initialise()`,
     * and the top suite is returned without other effects.
     *
     * @param argc The argument count from main().
     * @param argv The argument vector from main().
     * @param top_suite_name The name given to the top suite; if empty, the
     * name is chosen as by `add_top_suite()`.
     * @return Reference to the top suite.
     */
    [[deprecated ("use initialise (argc, argv) and add_top_suite() "
                  "(since 6.0.0)")]] class suite&
    initialise (int argc, char* argv[], const char* top_suite_name);

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    /**
     * @brief Initialises the test runner with the command-line arguments.
     *
     * @details
     * Parses the command-line options and initialises the runner with
     * them; equivalent to `initialise (runner_options{ argc, argv })`.
     *
     * The call is optional; without it, the runner is initialised with the
     * default options by the first call of `add_top_suite()` or `run_suites()`.
     * If used, it must therefore precede them; a later call, or a call
     * after the test execution was aborted, reports an error on `stderr`,
     * without other effects; the options are then not parsed, so their
     * errors do not change the exit code.
     *
     * @param argc The argument count from main().
     * @param argv The argument vector from main().
     * @par Returns
     *   Nothing.
     *
     * @since 6.0.0
     */
    void
    initialise (int argc, char* argv[]);

    /**
     * @brief Initialises the test runner with the given options.
     *
     * @details
     * Creates the reporter selected by the options and starts the
     * session. The options may be parsed from the command line, adjusted,
     * and passed here:
     *
     * @code{.cpp}
     * mt::runner_options options{ argc, argv };
     * options.selected_reporter = mt::reporter_kind::tap;
     * tr.initialise (std::move (options));
     * @endcode
     *
     * The call is optional; without it, the runner is initialised with the
     * default options by the first call of `add_top_suite()` or `run_suites()`.
     * If used, it must therefore precede them; a later call, or a call
     * after the test execution was aborted, reports an error on `stderr`,
     * without other effects.
     *
     * If the output file cannot be opened, the error is reported on
     * `stderr` and the report is written only to the console; the tests
     * are still run, but `run_suites()` returns 2. With an unknown reporter
     * name, nothing is reported, no test is run, and `run_suites()` returns 2.
     *
     * The options are taken by value and moved into the runner, which
     * keeps them for the whole session; pass a temporary, or use
     * `std::move()`, to avoid a copy.
     *
     * @param options The session options.
     * @par Returns
     *   Nothing.
     *
     * @since 6.0.0
     */
    void
    initialise (runner_options options);

    /**
     * @brief Adds the top suite and returns it.
     *
     * @details
     * The top suite is the suite whose body is the code of `main()`: its
     * test cases run immediately, when `test()` is called, before the
     * suites added with `add_suite()` and the static suites, which run
     * later, by `run_suites()`. It is always the first suite in the report.
     *
     * The call is optional; without it, there is no top suite, and only
     * the other suites are run and reported. If the runner is not yet
     * initialised, it is initialised with the default options.
     *
     * If no name is given, here or by the deprecated constructor, the top
     * suite is named after the file name of `runner_options::arguments[0]`,
     * without the extension, when available, or "default suite".
     *
     * The top suite can be added only once, and before `run_suites()`; a second
     * call, or a call made once `run_suites()` has started, is reported on
     * `stderr`, and the existing top suite is returned. With an unknown
     * reporter name, the top suite is returned, but nothing is reported.
     *
     * @param top_suite_name The name of the top suite, used in reports; a
     * string literal, a `const char*`, a `std::string`, or a
     * `std::string_view`. It is copied, so the string need not outlive the
     * call, nor be null-terminated. Defaults to an empty string.
     * @return Reference to the top suite.
     *
     * @since 6.0.0
     */
    class suite&
    add_top_suite (std::string_view top_suite_name = {});

    /**
     * @brief Runs the registered suites, ends the session, and returns the
     * exit code.
     *
     * @details
     * Completes the top suite, if any, runs the suites registered with
     * `add_suite()` and the static suites that refer to this runner,
     * together, sorted by name, and ends the session. If the runner is not
     * yet initialised, it is initialised with the default options. When
     * filter patterns are given, the suites whose names do not match the
     * first pattern are reported as skipped, without being run.
     *
     * While the test cases are listed (see `is_listing()`), the suites
     * run only to create their test cases, which are listed, and the
     * number of listed test cases is written; the result of the checks
     * does not affect the exit code, since no check is evaluated.
     *
     * A session without any suite (no top suite, no suite added with
     * `add_suite()`, and no static suite) is reported as an error, since
     * a test program that runs nothing must not pass unnoticed.
     *
     * The session runs only once; later calls return the same exit code
     * without running anything again. A call made while the session runs,
     * for example from a suite body, or after the test execution was
     * aborted (see `abort()`), is reported on `stderr` and returns 1,
     * without other effects.
     *
     * @par Parameters
     *   None.
     * @return 0 if all checks passed, or if the test cases were listed;
     * 1 if a check failed, if a suite was rejected by `add_suite()` or
     * `add_top_suite()`, if there was no suite, if the runner is running,
     * or if the test execution was aborted; 2 if `initialise()` reported
     * an option error, or if the filters selected no test case,
     * regardless of the checks.
     *
     * @since 6.0.0
     */
    int
    run_suites (void);

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated name of `run_suites()`.
     *
     * @details
     * Calls `run_suites()`; once the session has ended, it only returns the
     * exit code.
     *
     * @par Parameters
     *   None.
     * @return The value returned by `run_suites()`.
     */
    [[deprecated ("use run_suites() (since 6.0.0)")]] int
    exit_code (void);

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    /**
     * @brief Adds a test suite to the runner, to be run by `run_suites()`.
     *
     * @details
     * Unlike the test cases added to the top suite (see
     * `add_top_suite()`), which run immediately, the suite is only
     * stored; `run_suites()` runs it later,
     * together with the static suites that refer to this runner, sorted
     * by name.
     *
     * The suites must be added before `run_suites()` is called. A suite added
     * while `run_suites()` runs (for example from the body of another
     * suite), or after it returned, would never run; it is rejected, the
     * error is reported on `stderr`, and the exit code is not 0, so that
     * the omission cannot pass unnoticed.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param name The test suite name or description, used in reports; a
     * string literal, a `const char*`, a `std::string`, or a
     * `std::string_view`. It is copied, so the string need not outlive the
     * call, nor be null-terminated.
     * @param callable A generic callable object, usually a lambda,
     * invoked to perform the test suite.
     * @param arguments A possibly empty list of arguments to be passed to
     * the callable.
     * @par Returns
     *   Nothing.
     *
     * @since 6.0.0
     */
    template <typename Callable_T, typename... Args_T>
    void
    add_suite (std::string_view name, Callable_T&& callable,
               Args_T&&... arguments);

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated name of `add_suite()`.
     *
     * @details
     * Calls `add_suite()`. The old name did not show that the suite is
     * only stored, to be run later by `run_suites()`, unlike the test cases,
     * which run immediately; it also hid the `suite` class inside the
     * runner.
     *
     * @tparam Callable_T The type of a callable object.
     * @tparam Args_T The types of the callable arguments.
     *
     * @param name The test suite name or description, as for
     * `add_suite()`.
     * @param callable A generic callable object, usually a lambda,
     * invoked to perform the test suite.
     * @param arguments A possibly empty list of arguments to be passed to
     * the callable.
     * @par Returns
     *   Nothing.
     */
    template <typename Callable_T, typename... Args_T>
    [[deprecated ("use add_suite() (since 6.0.0)")]] void
    suite (std::string_view name, Callable_T&& callable,
           Args_T&&... arguments);

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    // ------------------------------------------------------------------------

    /**
     * @brief The type of the function called when test execution is
     * aborted.
     *
     * @details
     * The handler receives the source location from which the abort was
     * triggered. It is not expected to return; it may, for example, reset
     * an embedded target, or signal the test result to a debugger. If it
     * returns, the process is terminated with `::abort()`.
     *
     * When exceptions are enabled, it may also throw an exception, to
     * return control to the application without terminating the process.
     * The test cases and the suites do not catch it, so it leaves the
     * `test()` call that started a test case of the top suite, or
     * `run_suites()`, and reaches the application; their remaining code is not
     * run. The report is complete, but the runner cannot be used
     * afterwards (see `abort()`).
     *
     * @since 6.0.0
     */
    using abort_handler_t = void (*) (const reflection::source_location& sl);

    /**
     * @brief Sets the function called when test execution is aborted.
     *
     * @details
     * Test execution is aborted by a failed `require()`, when exceptions
     * are not enabled (otherwise only the test case is stopped), or by an
     * explicit call of `abort()`. The abort is reported before the handler
     * is called (see `abort()`).
     *
     * The handler can be set at any time, before or after `initialise()`.
     *
     * @param handler The new handler, or `nullptr` to restore the default
     * behaviour, which terminates the process with `::abort()`.
     * @return The previous handler, or `nullptr` if none was set.
     *
     * @since 6.0.0
     */
    abort_handler_t
    set_abort_handler (abort_handler_t handler) noexcept;

    /**
     * @brief Aborts test execution immediately.
     *
     * @details
     * Between `initialise()` and the end of `run_suites()`, the reporter
     * completes the report, on the console and in the output file: it
     * writes the results of the running test case, if any, followed by a
     * line with the source location (a `Bail out!` line with the TAP
     * reporter), in place of the totals. Before `initialise()` or after
     * `run_suites()`, when there is no report to complete, the source location
     * is written to `stderr`.
     *
     * The handler set by `set_abort_handler()` is then called, if any. If
     * there is no handler, or if it returns, the process is terminated
     * with `::abort()`.
     *
     * The abort is final, also when the handler throws an exception: no
     * test case runs afterwards, `initialise()` and `run_suites()` report an
     * error on `stderr` (`run_suites()` returns 1), and a later abort is not
     * reported again.
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
     * @brief Returns the count of all the test suites.
     *
     * @details
     * One, if the top suite was added by `add_top_suite()`, plus
     * `added_suites_count()` plus `static_suites_count()`; this is the
     * number of suites printed by the reporters.
     *
     * @par Parameters
     *   None.
     * @return The total number of test suites managed by this runner,
     * including the top suite, if any, and the static suites.
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
     * whether to display their own messages. Before `initialise()` is
     * called, it is `verbosity::normal`.
     *
     * @par Parameters
     *   None.
     * @return The active `verbosity` value.
     *
     * @since 6.0.0
     */
    [[nodiscard]] auto
    verbosity_level (void) const noexcept -> micro_test_plus::verbosity;

    /**
     * @brief Checks whether the test cases are listed instead of run.
     *
     * @details
     * Set by the `--list-tests` (or `--list`) command-line option, or by
     * `runner_options::list_tests`. While the test cases are listed, their
     * bodies do not run, so the code in `main()` or in the suite bodies
     * that depends on their results (their totals, or the exit code of
     * `run_suites()`) can use it to skip those parts, and the tests can use
     * it to keep their own messages out of the list. Before `initialise()` is
     * called, it is `false`.
     *
     * @par Parameters
     *   None.
     * @retval true The test cases are listed.
     * @retval false The test cases are run.
     *
     * @since 6.0.0
     */
    [[nodiscard]] bool
    is_listing (void) const noexcept;

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated name of `verbosity_level()`.
     *
     * @details
     * Calls `verbosity_level()`. The old name hid the `verbosity`
     * enumeration inside the runner.
     *
     * @par Parameters
     *   None.
     * @return The value returned by `verbosity_level()`.
     */
    [[deprecated ("use verbosity_level() (since 6.0.0)"), nodiscard]] auto
    verbosity (void) const noexcept -> micro_test_plus::verbosity;

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

    /**
     * @brief Returns the count of the test suites added with
     * `add_suite()`.
     *
     * @details
     * The count includes neither the top suite nor the static suites,
     * which are counted by `static_suites_count()`; add one for the top
     * suite, if added, or use `total_suites_count()`, which counts all of
     * them. The suites that `add_suite()` rejects, once `run_suites()` has
     * started, are not counted.
     *
     * @par Parameters
     *   None.
     * @return The number of test suites added with `add_suite()`.
     *
     * @since 6.0.0
     */
    [[nodiscard]] size_t
    added_suites_count (void) const noexcept;

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated name of the runner.
     *
     * @details
     * In v5.0.1, the runner was a test node, and always returned
     * `"runner"`. The runner is no longer a node; the name shown at the
     * beginning of the reports is that of the top suite, returned by
     * `add_top_suite()`.
     *
     * @par Parameters
     *   None.
     * @return The constant string `"runner"`.
     */
    [[deprecated ("the runner has no name; see add_top_suite() "
                  "(since 6.0.0)"),
      nodiscard]] const char*
    name (void) const noexcept;

    /**
     * @brief Deprecated count of the test suites added with
     * `add_suite()`, plus the top suite.
     *
     * @details
     * Returns `added_suites_count()` plus one, for the top suite. The
     * name suggested that all the suites are counted, while the static
     * suites are not. Use `added_suites_count()`, plus one for the top
     * suite, or `total_suites_count()`.
     *
     * @par Parameters
     *   None.
     * @return The number of test suites added with `add_suite()`, plus
     * one.
     */
    [[deprecated (
          "use added_suites_count() or total_suites_count() (since 6.0.0)"),
      nodiscard]] size_t
    suites_count (void) const noexcept;

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

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
     * @brief Returns the count of the test suites skipped by the filter.
     *
     * @details
     * Counts the suites, registered or static, whose names do not match
     * the first filter pattern (`--filter` or
     * `runner_options::filter_patterns`); it is complete only after
     * `run_suites()` has returned, and is zero when there are no patterns. The
     * skipped suites are included in `added_suites_count()` and
     * `static_suites_count()`; the skipped test cases are counted by
     * `counters::skipped_test_cases()`.
     *
     * @par Parameters
     *   None.
     * @return The number of test suites that were not run.
     *
     * @since 6.0.0
     */
    [[nodiscard]] size_t
    skipped_suites_count (void) const noexcept;

    /**
     * @brief Gets the totals of the test session.
     *
     * @details
     * The counters include the checks and the test cases of all the
     * suites that were run, including the top suite, if any; they are
     * complete only after `run_suites()` has returned. The totals are
     * read-only; there is no non-const overload, so that the counters cannot be
     * modified from the test code.
     *
     * @par Parameters
     *   None.
     * @return A const reference to the session totals.
     */
    [[nodiscard]] const counters&
    totals (void) const noexcept;

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)
    /**
     * @name Deprecated Functions
     * @{
     */

    /**
     * @brief Deprecated access to the timings of the test session.
     *
     * @details
     * Returns the internal stopwatch of the session, started by
     * `initialise()` and stopped at the end of `run_suites()`; the elapsed time
     * is complete only after `run_suites()` has returned. In v5.0.1, the
     * returned class was `detail::timestamps`, now a deprecated alias;
     * only its read-only members are kept. The timings are internal; the
     * elapsed times are shown by the reporters.
     *
     * @par Parameters
     *   None.
     * @return A const reference to the stopwatch of the session.
     */
    [[deprecated ("the timings are internal (since 6.0.0)"),
      nodiscard]] const detail::stopwatch&
    timings (void) const noexcept;

    /**
     * @brief Deprecated access to the timings of the test session, as a
     * non-`const` reference.
     *
     * @details
     * Kept for the v5.0.1 code that binds a non-`const` reference
     * (`detail::timestamps& t = tr.timings ();`). The test code must not
     * start or stop the stopwatch through it, since the reporters show
     * its elapsed time.
     *
     * @par Parameters
     *   None.
     * @return A reference to the stopwatch of the session.
     */
    [[deprecated ("the timings are internal (since 6.0.0)"),
      nodiscard]] detail::stopwatch&
    timings (void) noexcept;

    /**
     * @brief Deprecated access to the reporter of the test session.
     *
     * @details
     * Returns the internal reporter, created by `initialise()`, as
     * selected by the session options; the call is valid only after
     * `initialise()`. In v5.0.1, the returned class was the top
     * namespace `reporter`, now `detail::reporter`; of its members, the
     * applications used only `verbosity()`, kept, deprecated, on
     * `detail::reporter`.
     *
     * @par Parameters
     *   None.
     * @return A reference to the reporter of the session.
     */
    [[deprecated ("use verbosity_level() (since 6.0.0)"),
      nodiscard]] detail::reporter&
    reporter (void) const noexcept;

    /**
     * @}
     */
#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED)

  private:
    /**
     * @brief Runs all registered test suites.
     *
     * @details
     * Runs the suites registered with `add_suite()` and the static suites
     * that refer to this runner in a single order, sorted by name; for
     * equal names, in the order of their insertion into the list, so the
     * static suites constructed before `main()` run first. The suites not
     * selected by the first filter pattern are reported as skipped.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    run_child_suites (void);

    /**
     * @brief Registers a test suite with the runner.
     *
     * @details
     * Called by `add_suite()`. Once `run_suites()` has started, the suite is
     * rejected: it is destroyed, the error is reported on `stderr`, and
     * `has_rejected_suites_` is set.
     *
     * @param suite Owning pointer to the test suite to register.
     * @par Returns
     *   Nothing.
     */
    void
    register_suite (std::unique_ptr<class suite> suite);

    /**
     * @brief Reject a suite constructed after `run_suites()` has started.
     *
     * @details
     * Reports the error on `stderr`, sets `has_rejected_suites_`, and,
     * if the session has already ended, updates the stored exit code,
     * for the later calls of `run_suites()`. Used by `register_suite()` and by
     * `link_static_suite()`.
     *
     * @param [in] name The name of the rejected suite.
     *
     * @par Returns
     *   Nothing.
     */
    void
    reject_suite (const char* name);

    /**
     * @brief Insert a static suite into the list of suites, or reject it.
     *
     * @details
     * Called by the `static_suite` constructors. A static suite may be
     * constructed before its runner, which must not be accessed then;
     * therefore the runners that have started are kept in a
     * constant-initialised list, which is searched by address. If the
     * runner is in the list, `run_suites()` has started and the suite would
     * never run, so it is rejected, as by `add_suite()`; otherwise, it
     * is linked.
     *
     * @param [in] test_runner The runner of the suite.
     * @param [in] suite The suite being constructed.
     *
     * @par Returns
     *   Nothing.
     */
    static void
    link_static_suite (runner& test_runner, class suite& suite) noexcept;

    /**
     * @brief The head of the list of the runners that have started.
     *
     * @details
     * Constant-initialised, so it is valid before any constructor runs.
     * A runner is inserted by `run_suites()` and removed by the destructor.
     */
    static runner* started_first_;

    /**
     * @brief The next runner in the list of the started runners.
     *
     * @details
     * Null if this runner has not started, or is the last one.
     */
    runner* started_next_ = nullptr;

    /**
     * @brief Checks whether a suite or a test case is selected by the
     * filter pattern of its nesting level.
     *
     * @details
     * Level 0 refers to the suites, level 1 to their test cases, and each
     * further level to the test cases nested one level deeper. A name is
     * selected when there is no pattern for its level, or when it matches
     * one of the alternatives of the pattern, separated by `|`, as
     * defined by `utility::is_match()`.
     *
     * Also called by `detail::runnable_base`, a friend, before running a
     * test case.
     *
     * @param name The name of the suite or of the test case.
     * @param level The nesting level; 0 for suites.
     * @return `true` if it must run, `false` if it must be skipped.
     */
    [[nodiscard]] bool
    is_selected (const char* name, size_t level) const;

    /**
     * @brief Checks whether an option error was found by `initialise()`.
     *
     * @details
     * Called by `run_suites()`, which then returns 2. The errors are those
     * found while parsing the options (see `runner_options::has_errors()`),
     * and the output file that cannot be opened. The filters that select
     * no test case are checked by `run_suites()` itself.
     *
     * Valid only after `initialise()` created the reporter.
     *
     * @return `true` if an option error was found.
     */
    [[nodiscard]] bool
    has_option_errors (void) const noexcept;

    /**
     * @brief Lists a test case, instead of running it.
     *
     * @details
     * Called by `detail::runnable_base`, a friend, for each selected test
     * case created while the test cases are listed (see
     * `runner_options::list_tests`). The name of the suite is written
     * before its first listed test case, indented by two spaces, and the
     * name of the test case after it, indented by four spaces, through the
     * reporter, to the console, unless the verbosity is `silent`, and to
     * the output file, if any.
     *
     * @param suite The suite of the test case.
     * @param test_case The test case to list.
     * @par Returns
     *   Nothing.
     */
    void
    list_test_case (const class suite& suite,
                    const class test_case& test_case);

    /**
     * @brief Aborts test execution, telling the reporter why.
     *
     * @details
     * Implements `abort()`, which calls it for an explicit abort; also
     * called by `detail::runnable_base`, a friend, for a failed
     * requirement without exceptions, so that the reporter names the
     * cause.
     *
     * @param sl The source location from which the abort is triggered.
     * @param is_requirement `true` if the abort is caused by a failed
     * requirement.
     * @par Returns
     *   Does not return.
     */
    [[noreturn]] void
    abort (const reflection::source_location& sl, bool is_requirement);

    // ------------------------------------------------------------------------
  private:
    /**
     * @brief The top suite, whose body is the code of `main()`.
     *
     * @details
     * Always constructed with the runner, but part of the session only
     * after `add_top_suite()` (see `has_top_suite_`); its test cases are
     * added directly, between `add_top_suite()` and `run_suites()`.
     */
    class top_suite top_suite_;

    /**
     * @brief Whether the top suite was added to the session.
     *
     * @details
     * Set by `add_top_suite()`. When not set, the top suite is neither
     * run, nor reported, nor counted.
     */
    bool has_top_suite_ = false;

    /**
     * @brief Owning collection of dynamically registered child suites.
     *
     * @details
     * Each call to `add_suite()` appends a new `suite` to this vector,
     * and inserts it into the list of suites, sorted by name; the suites
     * are run later, by `run_suites()`, in the order of the list. The vector
     * retains ownership of all suites for the lifetime of the runner.
     */
    std::vector<std::unique_ptr<class suite>> children_suites_;

    /**
     * @brief Owning pointer to the test reporter used for outputting test
     * results.
     *
     * @details
     * Created by `initialise()`, as selected by the session options,
     * either given by the caller or parsed from the command line by the
     * `runner_options` constructor. Used by the suites and the test cases,
     * through `detail::runnable_base`, which is a friend.
     */
    std::unique_ptr<detail::reporter> reporter_;

    /**
     * @brief Stopwatch of this runner.
     *
     * @details
     * Measures the duration of the entire test session; started by
     * `initialise()`, stopped by `run_suites()`, and read by the reporters,
     * which are friends.
     */
    detail::stopwatch stopwatch_;

    /**
     * @brief Totals of the test session.
     *
     * @details
     * The totals of each suite are added by `run_suites()` and
     * `run_child_suites()`, after the suite was run.
     */
    counters totals_;

    /**
     * @brief Owned storage for the top suite name.
     *
     * @details
     * Set by `add_top_suite()`, either from its argument or derived from
     * `arguments[0]` of the session options.
     */
    std::string top_suite_name_;

    /**
     * @brief The options of the test session.
     *
     * @details
     * Moved in by `initialise()`, and kept for the whole session: the
     * verbosity is returned by `verbosity_level()`, the filter patterns
     * are read by `is_selected()`, the listing of the test cases by
     * `run_suites()` and `is_listing()`, and the command line by the reporters,
     * which are friends. The defaults until then.
     */
    runner_options options_{};

    /**
     * @brief The number of suites skipped by the filter.
     *
     * @details
     * Incremented by `run_child_suites()`; returned by
     * `skipped_suites_count()`.
     */
    size_t skipped_suites_count_ = 0;

    /**
     * @brief The states of a test session.
     *
     * @details
     * The session moves only forwards, from `created` to `initialised`
     * (by `initialise()`), to `running`, and to `finished` (both by
     * `run_suites()`); the calls made in another state are reported or ignored.
     */
    enum class session_state
    {
      created, /**< Constructed; `initialise()` not yet called. */
      initialised, /**< Initialised; test cases may be added and run. */
      running, /**< `run_suites()` runs the suites; no suite may be added. */
      finished /**< All suites run and the session ended. */
    };

    /**
     * @brief The current state of the test session.
     *
     * @details
     * Set by `initialise()` and `run_suites()`; read by `register_suite()`, to
     * reject the suites added too late.
     */
    session_state session_state_ = session_state::created;

    /**
     * @brief The exit code computed by `run_suites()`.
     *
     * @details
     * Returned again by the calls of `run_suites()` made after the session
     * ended.
     */
    int exit_code_ = 1;

    /**
     * @brief Whether a suite was added after `run_suites()` had started.
     *
     * @details
     * Set by `register_suite()`, which rejects such a suite; `run_suites()`
     * then returns 1, unless an option error requires 2.
     */
    bool has_rejected_suites_ = false;

    /**
     * @brief The function called by `abort()`, if not null.
     *
     * @details
     * Set by `set_abort_handler()`.
     */
    abort_handler_t abort_handler_ = nullptr;

    /**
     * @brief Whether the test execution was aborted.
     *
     * @details
     * Set by `abort()`, before the abort is reported, and never cleared.
     * Read by `detail::runnable_base`, a friend, so that, when the abort
     * handler throws an exception, the test cases and the suites pass it
     * on instead of reporting it, and no test case runs afterwards; read
     * by `initialise()` and `run_suites()`, which then refuse to start, and by
     * `abort()`, so that a later abort is not reported again.
     */
    bool aborted_ = false;

    /**
     * @brief The innermost test case being run, if any.
     *
     * @details
     * Set by `detail::runnable_base`, a friend, while a test case runs,
     * and restored when it ends, so that `suite::test()`, when called
     * from the body of a test case (for example via a captured suite
     * reference), runs the new test case nested in it.
     */
    test_case* running_test_case_ = nullptr;

    /**
     * @brief The suite whose name was listed last, if any.
     *
     * @details
     * Used by `list_test_case()` to write the name of a suite only once,
     * before its first listed test case.
     */
    const class suite* listed_suite_ = nullptr;

    /**
     * @brief The number of listed test cases.
     *
     * @details
     * Incremented by `list_test_case()`; written by `run_suites()` at the end
     * of the list.
     */
    size_t listed_test_cases_count_ = 0;

    /**
     * @brief The number of suites with listed test cases.
     *
     * @details
     * Incremented by `list_test_case()` when it writes the name of a
     * suite; written by `run_suites()` at the end of the list.
     */
    size_t listed_suites_count_ = 0;
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

#include "inlines/runner-inlines.h"

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_RUNNER_H_

// ----------------------------------------------------------------------------

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
   * @ingroup micro-os-plus-micro-test-plus-runners
   * @brief The test runner for the µTest++ framework.
   *
   * @details
   * The `runner` class is responsible for managing the registration and
   * execution of test suites within the µTest++ framework. It owns the
   * implicit top suite, whose test cases are added after `initialise()`,
   * and a collection of test suites added with `add_suite()`, which are
   * run later, by `run()`. These suites and the `static_suite` objects
   * that refer to the runner are kept in a single list, sorted by name,
   * independent of the runner object, so the static suites may be
   * constructed before it. `run()` runs the suites added with
   * `add_suite()` and the static suites together, in a single order,
   * sorted by name; for equal names, in the order of their creation, so
   * the static suites constructed before `main()` run first. The names
   * are compared byte by byte, as by `std::strcmp()`, not in the order of
   * addition: the comparison is case-sensitive (`"Zeta"` before
   * `"alpha"`) and does not compare numbers by value (`"Suite 10"` before
   * `"Suite 2"`); zero-padded numeric prefixes (`"01 - Init"`) give an
   * explicit order.
   *
   * The test runner provides member functions for initialising the test
   * environment (including the creation of the reporter selected on the
   * command line, or by the `runner_options` passed to `initialise()`),
   * registering test suites, and determining the overall test result via an
   * exit code. It also offers an abort mechanism for terminating test
   * execution in exceptional circumstances.
   *
   * The runner is not a node of the test tree: it has no name of its own
   * (the name shown in the reports belongs to the top suite), and it owns
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
     * @deprecated Use the anonymous constructor, and pass the name to
     * `initialise()` (since 4.1.0).
     */
    [[deprecated ("use runner() and pass the name to initialise()")]]
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
     * `--silent`, `--quiet`, `--verbose`, `--output-file`,
     * `--color`, `--use-colour`, and `--filter`) into a
     * `runner_options` structure, and continues as the overload taking
     * the options. The other arguments are ignored, since the
     * applications may define their own.
     *
     * A missing option argument, an unknown reporter name, or an unknown
     * colour mode, is reported on `stderr` and the option is ignored; the
     * tests are still run, but `run()` returns 2.
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
     * Completes the top suite, runs the suites registered with `add_suite()`
     * and the static suites that refer to this runner, together, sorted
     * by name, and ends the session. When filter patterns are given, the
     * suites whose names do not match the first pattern are reported as
     * skipped, without being run.
     *
     * The session runs only once; later calls return the same exit code
     * without running anything again. A call made while the session runs,
     * for example from a suite body, or after the test execution was
     * aborted (see `abort()`), is reported on `stderr` and returns 1,
     * without other effects.
     *
     * @par Parameters
     *   None.
     * @return 0 if all checks were successful, 1 otherwise, if a suite was
     * rejected by `add_suite()`, if the runner was not initialised, or if the
     * test execution was aborted, and 2 if `initialise()` reported an
     * option error, regardless of the checks.
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
    [[deprecated ("use run()")]] int
    exit_code (void);

    /**
     * @brief Adds a test suite to the runner, to be run by `run()`.
     *
     * @details
     * Unlike the test cases added to the top suite, which run
     * immediately, the suite is only stored; `run()` runs it later,
     * together with the static suites that refer to this runner, sorted
     * by name.
     *
     * The suites must be added before `run()` is called. A suite added
     * while `run()` runs (for example from the body of another suite), or
     * after it returned, would never run; it is rejected, the error is
     * reported on `stderr`, and the exit code is not 0, so that the
     * omission cannot pass unnoticed.
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
     * @since 5.1.0
     */
    template <typename Callable_T, typename... Args_T>
    void
    add_suite (std::string_view name, Callable_T&& callable,
               Args_T&&... arguments);

    /**
     * @brief Deprecated name of `add_suite()`.
     *
     * @details
     * Calls `add_suite()`. The old name did not show that the suite is
     * only stored, to be run later by `run()`, unlike the test cases,
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
     *
     * @deprecated Use `add_suite()` (since 5.1.0).
     */
    template <typename Callable_T, typename... Args_T>
    [[deprecated ("use add_suite()")]] void
    suite (std::string_view name, Callable_T&& callable,
           Args_T&&... arguments);

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
     * `run()`, and reaches the application; their remaining code is not
     * run. The report is complete, but the runner cannot be used
     * afterwards (see `abort()`).
     *
     * @since 5.1.0
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
     * @since 5.1.0
     */
    abort_handler_t
    set_abort_handler (abort_handler_t handler) noexcept;

    /**
     * @brief Aborts test execution immediately.
     *
     * @details
     * Between `initialise()` and the end of `run()`, the reporter
     * completes the report, on the console and in the output file: it
     * writes the results of the running test case, if any, followed by a
     * line with the source location (a `Bail out!` line with the TAP
     * reporter), in place of the totals. Before `initialise()` or after
     * `run()`, when there is no report to complete, the source location
     * is written to `stderr`.
     *
     * The handler set by `set_abort_handler()` is then called, if any. If
     * there is no handler, or if it returns, the process is terminated
     * with `::abort()`.
     *
     * The abort is final, also when the handler throws an exception: no
     * test case runs afterwards, `initialise()` and `run()` report an
     * error on `stderr` (`run()` returns 1), and a later abort is not
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
     * One, for the top suite, plus `added_suites_count()` plus
     * `static_suites_count()`; this is the number of suites printed by
     * the reporters.
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
     * whether to display their own messages. Before `initialise()` is
     * called, it is `verbosity::normal`.
     *
     * @par Parameters
     *   None.
     * @return The active `verbosity` value.
     *
     * @since 5.1.0
     */
    [[nodiscard]] auto
    verbosity_level (void) const noexcept -> micro_test_plus::verbosity;

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
     *
     * @deprecated Use `verbosity_level()` (since 5.1.0).
     */
    [[deprecated ("use verbosity_level()"), nodiscard]] auto
    verbosity (void) const noexcept -> micro_test_plus::verbosity;

    /**
     * @brief Returns the count of the test suites added with
     * `add_suite()`.
     *
     * @details
     * The count includes neither the top suite nor the static suites,
     * which are counted by `static_suites_count()`; add one for the top
     * suite when needed, or use `total_suites_count()`, which counts all
     * of them. The suites that `add_suite()` rejects, once `run()` has
     * started, are not counted.
     *
     * @par Parameters
     *   None.
     * @return The number of test suites added with `add_suite()`.
     *
     * @since 5.1.0
     */
    [[nodiscard]] size_t
    added_suites_count (void) const noexcept;

    /**
     * @brief Deprecated count of the test suites added with
     * `add_suite()`, plus the top suite.
     *
     * @details
     * Returns `added_suites_count()` plus one, for the top suite. The
     * name suggested that all the suites are counted, while the static
     * suites are not.
     *
     * @par Parameters
     *   None.
     * @return The number of test suites added with `add_suite()`, plus
     * one.
     *
     * @deprecated Use `added_suites_count()`, plus one for the top suite,
     * or `total_suites_count()` (since 5.1.0).
     */
    [[deprecated ("use added_suites_count() or total_suites_count()"),
      nodiscard]] size_t
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
     * @brief Returns the count of the test suites skipped by the filter.
     *
     * @details
     * Counts the suites, registered or static, whose names do not match
     * the first filter pattern (`--filter` or
     * `runner_options::filter_patterns`); it is complete only after
     * `run()` has returned, and is zero when there are no patterns. The
     * skipped suites are included in `added_suites_count()` and
     * `static_suites_count()`; the skipped test cases are counted by
     * `counters::skipped_test_cases()`.
     *
     * @par Parameters
     *   None.
     * @return The number of test suites that were not run.
     *
     * @since 5.1.0
     */
    [[nodiscard]] size_t
    skipped_suites_count (void) const noexcept;

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
    [[nodiscard]] const counters&
    totals (void) const noexcept;

    /**
     * @brief Deprecated access to the timings of the test session.
     *
     * @details
     * Returns the internal stopwatch of the session, started by
     * `initialise()` and stopped at the end of `run()`; the elapsed time
     * is complete only after `run()` has returned. In v5.0.1, the
     * returned class was `detail::timestamps`, now a deprecated alias;
     * only its read-only members are kept.
     *
     * @par Parameters
     *   None.
     * @return A const reference to the stopwatch of the session.
     *
     * @deprecated The timings are internal; the elapsed times are shown
     * by the reporters (since 5.1.0).
     */
    [[deprecated ("the timings are internal"),
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
     *
     * @deprecated The timings are internal; the elapsed times are shown
     * by the reporters (since 5.1.0).
     */
    [[deprecated ("the timings are internal"), nodiscard]] detail::stopwatch&
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
     *
     * @deprecated The reporter is internal; use `verbosity_level()`
     * (since 5.1.0).
     */
    [[deprecated ("the reporter is internal; use verbosity_level()"),
      nodiscard]] detail::reporter&
    reporter (void) const noexcept;

  private:
    /**
     * @brief Runs all registered test suites.
     *
     * @details
     * Runs the suites registered with `add_suite()` and the static suites
     * that refer to this runner in a single order, sorted by name; for
     * equal names, the registered suites run first. The suites not
     * selected by the first filter pattern are reported as skipped.
     *
     * @par Parameters
     *   None.
     * @par Returns
     *   Nothing.
     */
    void
    run_suites (void);

    /**
     * @brief Registers a test suite with the runner.
     *
     * @details
     * Called by `add_suite()`. Once `run()` has started, the suite is
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
     * @brief Parses the command-line options of the test session.
     *
     * @details
     * All the options are parsed here, once, and passed to the reporter;
     * the arguments not recognised as options are ignored, since the
     * applications may define their own. A missing option argument, an
     * unknown reporter name, or an unknown colour mode, is reported on
     * `stderr`, the option is ignored, and `has_option_errors_` is set.
     *
     * @param argc The argument count from main().
     * @param argv The argument vector from main().
     * @return The parsed options.
     */
    [[nodiscard]] runner_options
    parse_options (int argc, char* argv[]);

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
     * Each call to `add_suite()` appends a new `suite` to this vector,
     * and inserts it into the list of suites, sorted by name; the suites
     * are run later, by `run()`, in the order of the list. The vector
     * retains ownership of all suites for the lifetime of the runner.
     */
    std::vector<std::unique_ptr<class suite>> children_suites_;

    /**
     * @brief Owning pointer to the test reporter used for outputting test
     * results.
     *
     * @details
     * Created by `initialise()`, as selected by the session options,
     * either given by the caller or parsed from the command line by
     * `parse_options()`. Used by the suites and the test cases,
     * through `detail::runnable_base`, which is a friend.
     */
    std::unique_ptr<detail::reporter> reporter_;

    /**
     * @brief Stopwatch of this runner.
     *
     * @details
     * Measures the duration of the entire test session; started by
     * `initialise()`, stopped by `run()`, and read by the reporters,
     * which are friends.
     */
    detail::stopwatch stopwatch_;

    /**
     * @brief Totals of the test session.
     *
     * @details
     * The totals of each suite are added by `run()` and `run_suites()`,
     * after the suite was run.
     */
    counters totals_;

    /**
     * @brief Owned storage for the implicit top-suite name.
     *
     * @details
     * Set by `initialise()`, either from its argument or derived from
     * `argv[0]`, as kept in the session options.
     */
    std::string top_suite_name_;

    /**
     * @brief The verbosity level of the console output.
     *
     * @details
     * Copied by `initialise()` from `runner_options::verbosity_level`,
     * before the reporter is created, which keeps its own constant copy;
     * returned by `verbosity_level()`. `verbosity::normal` until then.
     */
    micro_test_plus::verbosity verbosity_ = verbosity::normal;

    /**
     * @brief The patterns that select the suites and the test cases to
     * run, one per nesting level.
     *
     * @details
     * Copied by `initialise()` from `runner_options::filter_patterns`,
     * including the characters, so the caller's strings need not outlive
     * the call, and read by `is_selected()`. Empty when everything must
     * run.
     */
    std::vector<std::string> filter_patterns_;

    /**
     * @brief The number of suites skipped by the filter.
     *
     * @details
     * Incremented by `run_suites()`; returned by
     * `skipped_suites_count()`.
     */
    size_t skipped_suites_count_ = 0;

    /**
     * @brief The states of a test session.
     *
     * @details
     * The session moves only forwards, from `created` to `initialised`
     * (by `initialise()`), to `running`, and to `finished` (both by
     * `run()`); the calls made in another state are reported or ignored.
     */
    enum class session_state
    {
      created, /**< Constructed; `initialise()` not yet called. */
      initialised, /**< Initialised; test cases may be added and run. */
      running, /**< `run()` is running the suites; no suite may be added. */
      finished /**< All suites run and the session ended. */
    };

    /**
     * @brief The current state of the test session.
     *
     * @details
     * Set by `initialise()` and `run()`; read by `register_suite()`, to
     * reject the suites added too late.
     */
    session_state session_state_ = session_state::created;

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
     * Set for a missing option argument, an unknown reporter name, an
     * unknown colour mode, or an output file that cannot be opened;
     * `run()` then returns 2.
     */
    bool has_option_errors_ = false;

    /**
     * @brief Whether a suite was added after `run()` had started.
     *
     * @details
     * Set by `register_suite()`, which rejects such a suite; `run()`
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
     * by `initialise()` and `run()`, which then refuse to start, and by
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
  using static_runner [[deprecated ("use runner")]] = runner;

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

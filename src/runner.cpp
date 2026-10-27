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
 * @brief C++ source file with implementations for the µTest++ test runner
 * member functions.
 *
 * @details
 * This source file contains the core implementations for the test runner
 * facilities of the µTest++ framework. It provides the logic for initialising
 * the test environment, registering and managing test suites, handling
 * command-line arguments, orchestrating test execution, and determining the
 * overall test result. The registered suites and the suites declared at
 * namespace scope are executed together, in a single order, sorted by
 * name. A mechanism for aborting test execution in critical scenarios is also
 * provided.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/runner.h"
#include "micro-os-plus/micro-test-plus/utility.h"
#include "micro-os-plus/micro-test-plus/reporter-tap.h"
#include "micro-os-plus/micro-test-plus/reporter-human.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

#include <cstdio>
#include <cstring>
#include <string>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-c++11-c++14-compat"
#pragma clang diagnostic ignored "-Wpre-c++17-compat"
#pragma clang diagnostic ignored "-Wc++20-compat"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  /**
   * @details
   * The constructor initialises a new `runner` instance together with
   * its top suite (`top_suite_`). If tracing is enabled, it outputs the
   * function signature for diagnostic purposes.
   */
  runner::runner (void) : top_suite_{ "", *this }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, top_suite_.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * The constructor initialises a new `runner` instance together with
   * its top suite (`top_suite_`). If tracing is enabled, it outputs the
   * function signature for diagnostic purposes.
   */
  // Deprecated since 4.1.0; use runner() and initialise().
  runner::runner (const char* top_suite_name)
      : top_suite_{ top_suite_name, *this }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, top_suite_.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * The `reporter_` unique pointer is released automatically. If tracing
   * is enabled, the function signature is output for diagnostic purposes.
   */
  runner::~runner ()
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

    for (runner** slot = &started_first_; *slot != nullptr;
         slot = &(*slot)->started_next_)
      {
        if (*slot == this)
          {
            *slot = started_next_;
            break;
          }
      }

    // reporter_ is a unique_ptr; destroyed automatically.
  }

#if defined(__GNUC__)
#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

  /**
   * @details
   * Parses the command-line options with the `runner_options`
   * constructor, and passes them to the overload taking the options,
   * which creates the selected reporter (`--reporter=human` or
   * `--reporter=tap`, the default) and starts the session. An option error is reported on `stderr`, the
   * option is ignored, and `run()` will return 2.
   *
   * The options are not parsed if the runner is already initialised; the
   * error is then reported by the other overload.
   *
   * If tracing is enabled, the command-line arguments are
   * also logged for diagnostic purposes.
   */
  suite&
  runner::initialise (int argc, char* argv[], const char* top_suite_name)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);

#if !(defined(MICRO_OS_PLUS_STARTUP_ENABLED) \
      && defined(MICRO_OS_PLUS_DIAG_TRACE_ENABLED))
#if defined(MICRO_OS_PLUS_DEBUG_ENABLED)
    trace::printf ("argv[");
    for (int i = 0; i < argc; ++i)
      {
        if (i > 0)
          {
            trace::printf (", ");
          }
        trace::printf ("'%s'", argv[i]);
      }
    trace::puts ("]");
#endif // defined(MICRO_OS_PLUS_DEBUG_ENABLED)
#endif // !defined(MICRO_OS_PLUS_STARTUP_ENABLED)
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (session_state_ != session_state::created)
      {
        // Do not parse the options, since an option error would change
        // the exit code of the running session; the other overload
        // reports the error.
        return initialise (runner_options{}, top_suite_name);
      }

    return initialise (runner_options{ argc, argv }, top_suite_name);
  }

  /**
   * @details
   * Moves the options into the runner, which keeps them for the whole
   * session, records whether errors were found while parsing them,
   * creates the reporter selected by them, starts the session timing,
   * and emits the initial reporter notifications for the session and the
   * top suite. While the test cases are listed, only the header of the
   * list is written; the session and the top suite are not reported.
   *
   * If the top suite name is not provided, here or by the deprecated
   * constructor, it is derived from the file name of
   * `options.arguments[0]` (usually `argv[0]`), without the extension,
   * or defaults to "default suite".
   *
   * If the output file cannot be opened, the reporter writes only to the
   * console, and `run()` will return 2.
   *
   * If the reporter name is not recognised, nothing else is done: no
   * output file is created, nothing is reported, the session is marked as
   * finished, so that no test is run, and `run()` returns 2.
   *
   * The runner is initialised only once; a later call, or a call after
   * the test execution was aborted, reports an error on `stderr` and
   * returns the top suite, without other effects.
   */
  suite&
  runner::initialise (runner_options options, const char* top_suite_name)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (aborted_)
      {
        fprintf (stderr, "error: test execution aborted\n");
        return top_suite_;
      }

    if (session_state_ != session_state::created)
      {
        fprintf (stderr, "error: test runner already initialised\n");
        return top_suite_;
      }

    // Move the vectors, since their copy assignment uses std::copy, which
    // triggers -Waggregate-return in the standard library headers on some
    // targets.
    options_ = std::move (options);

    if (top_suite_name != nullptr && strlen (top_suite_name) > 0)
      {
        // If provided by this call, use it, possibly override the
        // deprecated constructor.
        top_suite_name_ = top_suite_name;
        top_suite_.name_ = top_suite_name_.c_str ();
      }
    else if (strlen (top_suite_.name ()) == 0)
      {
        // If not provided by the constructor or by this call, try to extract a
        // name from argv[0], which is commonly the executable name. If that
        // fails, use a default name.
        if (!options_.arguments.empty ())
          {
            std::string_view top_suite_name_view{ utility::extract_file_name (
                options_.arguments[0].c_str ()) };

            const auto dot_pos = top_suite_name_view.rfind ('.');
            if (dot_pos != std::string_view::npos)
              {
                top_suite_name_view = top_suite_name_view.substr (0, dot_pos);
              }

            top_suite_name_ = top_suite_name_view;
          }
        else
          {
            top_suite_name_ = "default suite";
          }
        top_suite_.name_ = top_suite_name_.c_str ();
      }

    // With an unknown reporter, do not proceed: no output file is created,
    // nothing is reported, no test is run, and `run()` returns 2. A silent
    // reporter without output file is still created, since the suites and
    // the test cases refer to it.
    if (options_.has_invalid_reporter ())
      {
        runner_options silent_options{};
        silent_options.verbosity_level = verbosity::silent;
        options_.verbosity_level = verbosity::silent;
        reporter_ = std::make_unique<detail::reporter_tap> (silent_options);
        exit_code_ = 2;
        session_state_ = session_state::finished;
        return top_suite_;
      }

    // Initialise and configure the reporter; it keeps its own copy of the
    // verbosity, taken from the same options.
    if (options_.selected_reporter == reporter_kind::human)
      {
        reporter_ = std::make_unique<detail::reporter_human> (options_);
      }
    else
      {
        reporter_ = std::make_unique<detail::reporter_tap> (options_);
      }

    // ------------------------------------------------------------------------

    // When listing, the session is not reported; only the header of the
    // list is written, and the test cases are listed as they are created.
    if (options_.list_tests)
      {
        reporter_->write_line (
            options_.verbosity_level != verbosity::silent, "%s\n",
            options_.filter_patterns.empty () ? "All available test cases:"
                                              : "Matching test cases:");
        session_state_ = session_state::initialised;
        return top_suite_;
      }

    stopwatch_.start ();
    reporter_->begin_session (*this);

    top_suite_.stopwatch_.start ();
    reporter_->begin_suite (top_suite_);

    session_state_ = session_state::initialised;

    return top_suite_;
  }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

  /**
   * @details
   * The levels beyond the last pattern are not filtered. Otherwise, the
   * alternatives of the pattern, separated by `|`, are tried in order,
   * until one matches the whole name.
   */
  bool
  runner::is_selected (const char* name, size_t level) const
  {
    if (level >= options_.filter_patterns.size ())
      {
        return true;
      }

    std::string_view alternatives{ options_.filter_patterns[level] };
    while (true)
      {
        const size_t separator = alternatives.find ('|');
        if (utility::is_match (name, alternatives.substr (0, separator)))
          {
            return true;
          }
        if (separator == std::string_view::npos)
          {
            return false;
          }
        alternatives.remove_prefix (separator + 1);
      }
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * The suites are listed in the order in which their first test cases
   * are created: the top suite first, during `main()`, then the other
   * suites, in the order of `run_suites()`; so the name of a suite is
   * written when it differs from the previous one.
   */
  void
  runner::list_test_case (const class suite& suite, const test_case& test_case)
  {
    if (&suite != listed_suite_)
      {
        listed_suite_ = &suite;
        ++listed_suites_count_;
        reporter_->write_line (options_.verbosity_level != verbosity::silent,
                               "  %s\n", suite.name ());
      }

    ++listed_test_cases_count_;
    reporter_->write_line (options_.verbosity_level != verbosity::silent,
                           "    %s\n", test_case.name ());
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * Takes ownership of the supplied `suite` unique pointer and appends
   * it to the internal `children_suites_` vector, then inserts the suite
   * into the list of suites, sorted by name, deferring execution until
   * `run_suites()` is called. The suite is inserted after it is stored,
   * so that a failed allocation of the vector leaves it out of the list.
   * If tracing is enabled, the suite name is logged for diagnostic
   * purposes.
   *
   * Once `run()` has started, the suite is rejected, since it would
   * never run: `run_suites()` takes the number of suites only once,
   * before running them, and after the session has ended nothing runs.
   * The error is reported on `stderr`, the suite is destroyed when the
   * pointer goes out of scope, and `has_rejected_suites_` is set, so that
   * the exit code is not 0; if the session has already ended, the stored
   * exit code is updated, for the later calls of `run()`.
   */
  void
  runner::register_suite (std::unique_ptr<class suite> suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite->name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (session_state_ == session_state::running
        || session_state_ == session_state::finished)
      {
        reject_suite (suite->name ());
        return;
      }

    children_suites_.push_back (std::move (suite));
    children_suites_.back ()->link ();
  }

  /**
   * @details
   * The message is written on `stderr`, since the reporter may have
   * ended. The suite itself is destroyed by the caller.
   */
  void
  runner::reject_suite (const char* name)
  {
    fprintf (stderr, "error: suite '%s' added after run() started, rejected\n",
             name);
    has_rejected_suites_ = true;
    if (session_state_ == session_state::finished && exit_code_ == 0)
      {
        exit_code_ = 1;
      }
  }

  /**
   * @details
   * Searches the list of the started runners for @p test_runner, without
   * accessing it, since it may not be constructed yet. If found, the
   * runner reports the rejection; otherwise, the suite is linked. No
   * memory is allocated.
   */
  void
  runner::link_static_suite (runner& test_runner, class suite& suite) noexcept
  {
    for (const runner* started = started_first_; started != nullptr;
         started = started->started_next_)
      {
        if (started == &test_runner)
          {
            test_runner.reject_suite (suite.name ());
            return;
          }
      }

    suite.link ();
  }

  /**
   * @details
   * Constant-initialised, so it is null before any static constructor
   * runs.
   */
  constinit runner* runner::started_first_ = nullptr;

  /**
   * @details
   * Runs the suites registered with `add_suite()` and the static suites that
   * refer to this runner in a single order, sorted by name.
   *
   * Both kinds of suites are in the list of suites, which `suite::link()`
   * keeps sorted by name, so no sorting is needed here; the suites of
   * other runners are skipped. The names are compared with
   * `std::strcmp()`, so in byte order, case-sensitively, and without
   * comparing the numbers by value; the suites with the same name run in
   * the order of their insertion into the list.
   *
   * Each suite is assigned a 1-based index, following the top suite, in
   * the order of execution. If the first filter pattern selects it, it is
   * executed via `suite::run()`, and its totals are accumulated into the
   * runner totals; otherwise, it is reported as skipped and counted in
   * `skipped_suites_count_`, keeping its index, so that the TAP plan
   * remains complete; while the test cases are listed, the skipped suites
   * are not reported. The executed test cases counter is not incremented;
   * suites are not counted as test cases.
   *
   * The next suite is read after the current one has run, since the
   * suites of the local runners created by the current suite are
   * inserted into the list, and removed again, while it runs.
   */
  void
  runner::run_suites (void)
  {
    // The top suite has index 1.
    size_t own_index = 1;
    for (class suite* suite_ptr = suite::first_; suite_ptr != nullptr;
         suite_ptr = suite_ptr->next_)
      {
        // Skip the suites run by other runners.
        if (&suite_ptr->test_runner () != this)
          {
            continue;
          }

        suite_ptr->own_index_ = ++own_index;

        if (!is_selected (suite_ptr->name (), 0))
          {
            ++skipped_suites_count_;
            if (!options_.list_tests)
              {
                reporter_->skip_suite (*suite_ptr);
              }
            continue;
          }

        suite_ptr->run ();

        // Accumulate the totals from the child suite into the runner
        // totals.
        // DO NOT increment executed_test_cases here.
        totals_ += suite_ptr->totals ();
      }
  }

  /**
   * @details
   * Finalises the top suite by stopping its stopwatch and notifying
   * the reporter, then accumulates its totals into the runner totals.
   * Subsequently invokes `run_suites()` to execute, sorted by name, and
   * accumulate the registered and the static child suites. Finally,
   * stops the session stopwatch, notifies the reporter, and returns `0`
   * if all checks passed or `1` otherwise, or if a suite was rejected by
   * `register_suite()`; if `initialise()` reported an option error, `2`
   * is returned, regardless of the checks.
   *
   * While the suites run, the session is in the `running` state, so that
   * the suites added by them are rejected.
   *
   * While the test cases are listed, the top suite is not reported, the
   * suites run only to create their test cases, the numbers of listed
   * test cases and suites end the list, and the exit code is `0`, or
   * `2` after an option error.
   *
   * The result is stored, and the later calls return it without running
   * anything again. If the runner was not initialised, if it is
   * already running (a call from a suite or a test case), or if the test
   * execution was aborted, an error is reported on `stderr` and `1` is
   * returned.
   */
  int
  runner::run (void)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (aborted_)
      {
        fprintf (stderr, "error: test execution aborted\n");
        return 1;
      }

    if (session_state_ == session_state::finished)
      {
        // The session has ended; do not run the suites again.
        return exit_code_;
      }

    if (session_state_ == session_state::running)
      {
        fprintf (stderr, "error: test runner already running\n");
        return 1;
      }

    if (session_state_ != session_state::initialised)
      {
        fprintf (stderr, "error: test runner not initialised\n");
        return 1;
      }

    session_state_ = session_state::running;
    started_next_ = started_first_;
    started_first_ = this;

    // When listing, the suites run only to create their test cases, which
    // are listed, and the number of listed test cases ends the list.
    if (options_.list_tests)
      {
        run_suites ();

        const unsigned long test_cases = listed_test_cases_count_;
        const unsigned long suites = listed_suites_count_;
        reporter_->write_line (options_.verbosity_level != verbosity::silent,
                               "%lu test case%s in %lu test suite%s\n",
                               test_cases, (test_cases == 1) ? "" : "s",
                               suites, (suites == 1) ? "" : "s");
        reporter_->flush_streams ();

        exit_code_ = has_option_errors () ? 2 : 0;
        session_state_ = session_state::finished;
        return exit_code_;
      }

    top_suite_.stopwatch_.stop ();
    reporter_->end_suite (top_suite_);
    totals_ += top_suite_.totals ();

    run_suites ();

    // A filter that selects no test case disables the tests; report it.
    const bool selected_nothing = !options_.filter_patterns.empty ()
                                  && totals_.executed_test_cases () == 0;
    if (selected_nothing)
      {
        fprintf (stderr, "error: the filters selected no test case\n");
        reporter_->write_line (options_.verbosity_level != verbosity::silent,
                               "%serror: the filters selected no test case\n",
                               reporter_->comment_prefix ());
      }

    stopwatch_.stop ();
    reporter_->end_session (*this);

    if (selected_nothing || has_option_errors ())
      {
        exit_code_ = 2;
      }
    else
      {
        exit_code_ = (totals_.passed () && !has_rejected_suites_) ? 0 : 1;
      }
    session_state_ = session_state::finished;

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s -> %d\n", __PRETTY_FUNCTION__, exit_code_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    return exit_code_;
  }

  /**
   * @details
   * Kept for compatibility; it calls `run()`, so the first call runs the
   * session and the later ones return the stored exit code.
   */
  // Deprecated since 5.1.0; use run().
  int
  runner::exit_code (void)
  {
    return run ();
  }

  /**
   * @details
   * Stores the new handler and returns the previous one; a null handler
   * restores the default behaviour.
   */
  runner::abort_handler_t
  runner::set_abort_handler (abort_handler_t handler) noexcept
  {
    abort_handler_t previous = abort_handler_;
    abort_handler_ = handler;
    return previous;
  }

  /**
   * @details
   * Delegates to `abort()`, as an explicit abort, not caused by a failed
   * requirement.
   */
  void
  runner::abort (const reflection::source_location& sl)
  {
    abort (sl, false);
  }

  /**
   * @details
   * While the report is open, from `initialise()`, which begins it (the
   * test cases of the top suite run from then on), to the end of `run()`,
   * the reporter writes the buffered results and the location of the
   * abort, with `abort_session()`, to the console and to the output
   * file, since the totals are never reached. Otherwise, there is no
   * report to complete, and the location is written to `stderr`. The
   * standard streams are then flushed, and the handler set by
   * `set_abort_handler()` is called, if any. If there is no handler, or
   * if it returns, the process is terminated via `::abort()`.
   *
   * The `aborted_` flag is set first, and never cleared, so that, if the
   * handler throws an exception, the test cases and the suites pass it
   * on (see `test_case::run()`), and the runner refuses to run again.
   * An abort after another one, for example from the code that caught
   * the exception, is not reported again, since the report is already
   * complete; the handler is still called.
   */
  void
  runner::abort (const reflection::source_location& sl, bool is_requirement)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (!aborted_)
      {
        aborted_ = true;

        if (session_state_ == session_state::initialised
            || session_state_ == session_state::running)
          {
            reporter_->abort_session (sl, is_requirement);
          }
        else
          {
            // The type of `line()` depends on the toolchain
            // (`uint_least32_t` for `std::source_location`); widen it
            // implicitly, without a cast that would be useless on some
            // platforms.
            const unsigned long line = sl.line ();
            fprintf (stderr, "error: test execution aborted at %s:%lu\n",
                     utility::extract_file_name (sl.file_name ()), line);
          }
      }

    fflush (stdout);
    fflush (stderr);

    if (abort_handler_ != nullptr)
      {
        abort_handler_ (sl);
      }

    ::abort ();
  }

  /**
   * @details
   * Returns the number of suites stored by `register_suite()`; the top
   * suite and the static suites are not in `children_suites_`.
   */
  size_t
  runner::added_suites_count (void) const noexcept
  {
    return children_suites_.size ();
  }

  /**
   * @details
   * Returns `added_suites_count()` plus one, for the top suite, as
   * before the rename.
   */
  // Deprecated since 5.1.0; use added_suites_count() or total_suites_count().
  size_t
  runner::suites_count (void) const noexcept
  {
    return added_suites_count () + 1;
  }

  /**
   * @details
   * Walks the list of suites, counts those that refer to this runner,
   * and subtracts the suites registered with `add_suite()`, which are
   * all in the list.
   */
  size_t
  runner::static_suites_count (void) const noexcept
  {
    size_t count = 0;
    for (const class suite* suite_ptr = suite::first_; suite_ptr != nullptr;
         suite_ptr = suite_ptr->next_)
      {
        if (&suite_ptr->test_runner () == this)
          {
            ++count;
          }
      }
    return count - children_suites_.size ();
  }

  /**
   * @details
   * Returns one, for the top suite, plus the count of the suites added
   * with `add_suite()`, plus the count of the static suites.
   */
  size_t
  runner::total_suites_count (void) const noexcept
  {
    return 1 + added_suites_count () + static_suites_count ();
  }

  /**
   * @details
   * Returns the counter incremented by `run_suites()`.
   */
  size_t
  runner::skipped_suites_count (void) const noexcept
  {
    return skipped_suites_count_;
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

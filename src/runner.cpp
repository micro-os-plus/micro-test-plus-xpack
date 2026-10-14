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
 * @brief C++ source file with implementations for the µTest++ test runner
 * methods.
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

#include <algorithm>
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
   * Parses the command-line options with `parse_options_()`, and passes
   * them to the overload taking the options, which creates the selected
   * reporter (`--reporter=human` or `--reporter=tap`, the default) and
   * starts the session. An option error is reported on `stderr`, the
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

    if (session_state_ != session_state_t::created)
      {
        return initialise (runner_options{}, top_suite_name);
      }

    return initialise (parse_options_ (argc, argv), top_suite_name);
  }

  /**
   * @details
   * Creates the reporter selected by the options, keeps a copy of the
   * filter patterns, starts session timing, and emits the initial
   * reporter notifications for the session and top suite.
   *
   * If the top suite name is not provided, here or by the deprecated
   * constructor, it is derived from the file name of
   * `options.arguments[0]` (usually `argv[0]`), without the extension,
   * or defaults to "default suite".
   *
   * If the output file cannot be opened, the reporter writes only to the
   * console, and `run()` will return 2.
   *
   * The runner is initialised only once; a later call reports an error on
   * `stderr` and returns the top suite, without other effects.
   */
  suite&
  runner::initialise (const runner_options& options,
                      const char* top_suite_name)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (session_state_ != session_state_t::created)
      {
        fprintf (stderr, "error: test runner already initialised\n");
        return top_suite_;
      }

    if (top_suite_name != nullptr && strlen (top_suite_name) > 0)
      {
        // If provided by this call, use it, possibly override the
        // deprecated constructor.
        top_suite_name_ = top_suite_name;
        top_suite_.name (top_suite_name_.c_str ());
      }
    else if (strlen (top_suite_.name ()) == 0)
      {
        // If not provided by the constructor or by this call, try to extract a
        // name from argv[0], which is commonly the executable name. If that
        // fails, use a default name.
        if (!options.arguments.empty () && options.arguments[0] != nullptr)
          {
            std::string_view top_suite_name_view{ utility::extract_file_name (
                options.arguments[0]) };

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
        top_suite_.name (top_suite_name_.c_str ());
      }

    // Initialise and configure the reporter.
    if (options.selected_reporter == reporter_kind::human)
      {
        reporter_ = std::make_unique<detail::reporter_human> (options);
      }
    else
      {
        reporter_ = std::make_unique<detail::reporter_tap> (options);
      }

    if (reporter_->has_output_file_error ())
      {
        has_option_errors_ = true;
      }

    // The views are copied, not the strings; they must remain valid until
    // run() returns. Copy them one by one, since the vector assignment
    // uses std::copy, which triggers -Waggregate-return in the standard
    // library headers on some targets.
    filter_patterns_.reserve (options.filter_patterns.size ());
    for (const std::string_view pattern : options.filter_patterns)
      {
        filter_patterns_.push_back (pattern);
      }

    // ------------------------------------------------------------------------

    timings_.timestamp_begin ();
    reporter_->begin_session (*this);

    top_suite_.timings ().timestamp_begin ();
    reporter_->begin_suite (top_suite_);

    session_state_ = session_state_t::initialised;

    return top_suite_;
  }

  /**
   * @details
   * Scans the arguments after `argv[0]`, in order, for:
   *
   * - `--reporter=<name>` or `--reporter <name>`, with `tap` (the default)
   *   or `human`;
   * - `--verbose`, `--quiet`, and `--silent`;
   * - `--output-file=<path>` or `--output-file <path>`;
   * - `--filter=<pattern>` or `--filter <pattern>`.
   *
   * When an option is repeated, the last one takes effect, except
   * `--filter`, whose patterns are all kept, in order, one per nesting
   * level. An option
   * argument given separately is the next argument, whatever its content.
   * The other arguments are ignored. The whole command line is kept in the
   * options, to be listed by the reporter.
   *
   * A missing option argument, or an unknown reporter name, is reported on
   * `stderr`, the option is ignored, and `has_option_errors_` is set, so
   * that `run()` returns 2; the parsing continues with the next argument.
   */
  runner_options
  runner::parse_options_ (int argc, char* argv[])
  {
    runner_options opts{};

    if (argc <= 0 || argv == nullptr)
      {
        return opts;
      }

    opts.arguments = { argv, static_cast<size_t> (argc) };

    static constexpr std::string_view reporter_option{ "--reporter" };
    static constexpr std::string_view output_file_option{ "--output-file" };
    static constexpr std::string_view filter_option{ "--filter" };

    // Get the value of an option given as `--option=<value>` or as
    // `--option <value>`; the latter advances the index past the value.
    // Return false if the argument is not this option, or if its value is
    // missing, which is reported as an error.
    auto get_value = [&] (std::string_view option, size_t& i,
                          std::string_view& value) -> bool
      {
        const std::string_view argument{ opts.arguments[i] };
        if (argument == option)
          {
            if (i + 1 >= opts.arguments.size ())
              {
                fprintf (stderr, "error: %.*s option requires an argument\n",
                         static_cast<int> (option.size ()), option.data ());
                has_option_errors_ = true;
                return false;
              }
            value = opts.arguments[++i];
            return true;
          }
        if (argument.starts_with (option)
            && argument.substr (option.size ()).starts_with ('='))
          {
            value = argument.substr (option.size () + 1);
            return true;
          }
        return false;
      };

    for (size_t i = 1; i < opts.arguments.size (); ++i)
      {
        const std::string_view argument{ opts.arguments[i] };
        std::string_view value{};

        if (argument == "--verbose")
          {
            opts.verbosity_level = verbosity::verbose;
          }
        else if (argument == "--quiet")
          {
            opts.verbosity_level = verbosity::quiet;
          }
        else if (argument == "--silent")
          {
            opts.verbosity_level = verbosity::silent;
          }
        else if (get_value (reporter_option, i, value))
          {
            if (value == "human")
              {
                opts.selected_reporter = reporter_kind::human;
              }
            else if (value == "tap")
              {
                opts.selected_reporter = reporter_kind::tap;
              }
            else
              {
                fprintf (stderr, "error: unknown reporter '%.*s'\n",
                         static_cast<int> (value.size ()), value.data ());
                has_option_errors_ = true;
              }
          }
        else if (get_value (output_file_option, i, value))
          {
            // The value is a suffix of a null-terminated argv[] string,
            // so it is null-terminated too. An empty path disables the
            // output file.
            opts.output_file_path = value.empty () ? nullptr : value.data ();
          }
        else if (get_value (filter_option, i, value))
          {
            // The view refers to the argv[] string, which remains valid
            // until the program ends.
            opts.filter_patterns.push_back (value);
          }
      }

    return opts;
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
  runner::is_selected_ (const char* name, size_t level) const
  {
    if (level >= filter_patterns_.size ())
      {
        return true;
      }

    std::string_view alternatives{ filter_patterns_[level] };
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
   * Takes ownership of the supplied `suite` unique pointer and appends
   * it to the internal `children_suites_` vector, deferring execution
   * until `run_suites_()` is called. If tracing is enabled, the suite
   * name is logged for diagnostic purposes.
   */
  void
  runner::register_suite_ (std::unique_ptr<class suite> suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite->name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    children_suites_.push_back (std::move (suite));
  }

  /**
   * @details
   * Runs the suites registered with `suite()` and the static suites that
   * refer to this runner in a single order, sorted by name.
   *
   * First, `children_suites_` is sorted by name with an insertion sort
   * on `unique_ptr::swap`, avoiding the `-Waggregate-return` diagnostic
   * that `std::stable_sort` would trigger on unique-pointer iterators;
   * the sort is stable, so the registered suites with the same name
   * remain in the order of their registration.
   *
   * The sorted registered suites are then merged with the list of static
   * suites, which is already sorted by name; the static suites of other
   * runners are skipped. For equal names, the registered suite runs
   * first. The names are compared with `std::strcmp()`, as when the list
   * of static suites is built.
   *
   * Each suite is assigned a 1-based index, following the top suite, in
   * the order of execution. If the first filter pattern selects it, it is
   * executed via `suite::run()`, and its totals are accumulated into the
   * runner totals; otherwise, it is reported as skipped and counted in
   * `skipped_suites_count_`, keeping its index, so that the TAP plan
   * remains complete. The executed-subtest counter is not incremented;
   * suites are not counted as subtests.
   */
  void
  runner::run_suites_ (void)
  {
    // Use insertion sort with unique_ptr::swap (returns void) to avoid
    // std::stable_sort triggering -Waggregate-return via
    // std::move_backward, which returns a class-type iterator when
    // operating on unique_ptr elements.
    const size_t n = children_suites_.size ();
    for (size_t i = 1; i < n; ++i)
      {
        for (size_t j = i;
             j > 0
             && std::strcmp (children_suites_[j - 1]->name (),
                             children_suites_[j]->name ())
                    > 0;
             --j)
          {
            children_suites_[j - 1].swap (children_suites_[j]);
          }
      }

    // The top suite has index 1.
    size_t own_index = 1;
    size_t i = 0;
    static_suite* static_ptr = static_suite::first_;
    while (true)
      {
        // Skip the static suites run by other runners.
        while (static_ptr != nullptr && &static_ptr->test_runner () != this)
          {
            static_ptr = static_ptr->next_;
          }

        class suite* suite_ptr;
        if (i < n
            && (static_ptr == nullptr
                || std::strcmp (children_suites_[i]->name (),
                                static_ptr->name ())
                       <= 0))
          {
            suite_ptr = children_suites_[i].get ();
            ++i;
          }
        else if (static_ptr != nullptr)
          {
            suite_ptr = static_ptr;
            static_ptr = static_ptr->next_;
          }
        else
          {
            break;
          }

        suite_ptr->own_index (++own_index);

        if (!is_selected_ (suite_ptr->name (), 0))
          {
            ++skipped_suites_count_;
            reporter_->skip_suite (*suite_ptr);
            continue;
          }

        suite_ptr->run ();

        // Accumulate the totals from the child suite into the runner
        // totals.
        // DO NOT increment executed_subtests here.
        totals_ += suite_ptr->totals ();
      }
  }

  /**
   * @details
   * Finalises the top suite by recording its end timestamp and notifying
   * the reporter, then accumulates its totals into the runner totals.
   * Subsequently invokes `run_suites_()` to execute, sorted by name, and
   * accumulate the registered and the static child suites. Finally, records the session
   * end timestamp, notifies the reporter, and returns `0` if all checks
   * passed or `1` otherwise; if `initialise()` reported an option error,
   * `2` is returned, regardless of the checks.
   *
   * The result is stored, and the later calls return it without running
   * anything again. If the runner was not initialised, an error is
   * reported on `stderr` and `1` is returned.
   */
  int
  runner::run (void)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (session_state_ == session_state_t::finished)
      {
        // The session has ended; do not run the suites again.
        return exit_code_;
      }

    if (session_state_ != session_state_t::initialised)
      {
        fprintf (stderr, "error: test runner not initialised\n");
        return 1;
      }

    top_suite_.timings ().timestamp_end ();
    reporter_->end_suite (top_suite_);
    totals_ += top_suite_.totals ();

    run_suites_ ();

    timings_.timestamp_end ();
    reporter_->end_session (*this);

    if (has_option_errors_)
      {
        exit_code_ = 2;
      }
    else
      {
        exit_code_ = totals_.was_successful () ? 0 : 1;
      }
    session_state_ = session_state_t::finished;

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
   * Prints the source location of the fatal error to `stderr`, flushes
   * the standard streams, and calls the handler set by
   * `set_abort_handler()`, if any. If there is no handler, or if it
   * returns, the process is terminated via `::abort()`.
   */
  void
  runner::abort (const reflection::source_location& sl)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    fprintf (stderr, "\nerror: test execution aborted at %s:%u\n",
             reflection::short_name (sl.file_name ()), sl.line ());

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
   * Returns the number of registered child suites plus one, accounting
   * for the top suite.
   */
  size_t
  runner::suites_count (void) const noexcept
  {
    return children_suites_.size () + 1;
  }

  /**
   * @details
   * Walks the list of static suites, and counts those that refer to this
   * runner.
   */
  size_t
  runner::static_suites_count (void) const noexcept
  {
    size_t count = 0;
    for (const static_suite* suite_ptr = static_suite::first_;
         suite_ptr != nullptr; suite_ptr = suite_ptr->next_)
      {
        if (&suite_ptr->test_runner () == this)
          {
            ++count;
          }
      }
    return count;
  }

  /**
   * @details
   * Returns the combined count of the registered suites, including the
   * top suite, and of the static suites.
   */
  size_t
  runner::total_suites_count (void) const noexcept
  {
    return suites_count () + static_suites_count ();
  }

  /**
   * @details
   * Returns the counter incremented by `run_suites_()`.
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

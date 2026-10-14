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
 * overall test result. The registered suites are executed sorted by name;
 * the `static_runner` additionally executes the suites declared at
 * namespace scope. A mechanism for aborting test execution in critical
 * scenarios is also provided.
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
   * Performs the `static_runner` to `runner` upcast where both types are
   * complete, allowing headers with only forward declarations to request this
   * conversion safely.
   */
  runner&
  detail::to_runner (static_runner& static_runner_ref) noexcept
  {
    return static_cast<runner&> (static_runner_ref);
  }

  /**
   * @details
   * Performs static-suite registration where `static_runner` is complete,
   * allowing header-only template code to avoid direct dependence on
   * `runner.h` include order.
   */
  void
  detail::register_static_suite (static_runner& static_runner_ref,
                                 static_suite& static_suite_ref)
  {
    static_runner::register_static_suite (static_runner_ref, static_suite_ref);
  }

  // --------------------------------------------------------------------------

  /**
   * @details
   * The constructor initialises a new `runner` instance together with
   * its top suite (`top_suite_`). If tracing is enabled, it outputs the
   * function signature for diagnostic purposes.
   */
  runner::runner (void) : test_node{ "runner" }, top_suite_{ "", *this }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * The constructor initialises a new `runner` instance together with
   * its top suite (`top_suite_`). If tracing is enabled, it outputs the
   * function signature for diagnostic purposes.
   */
  runner::runner (const char* top_suite_name)
      : test_node{ "runner" }, top_suite_{ top_suite_name, *this }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name ());
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
   * Parses the command-line options with `parse_options_()`, creates
   * the selected reporter (`--reporter=human` or `--reporter=tap`, the
   * default) with these options, starts session timing, and emits the
   * initial reporter notifications for the session and top suite. An
   * option error terminates the process with an error message.
   *
   * If the top suite name is not provided, here or by the deprecated
   * constructor, it is derived from the file name of `argv[0]`, without
   * the extension, or defaults to "default suite".
   *
   * The runner is initialised only once; a later call reports an error on
   * `stderr` and returns the top suite, without other effects.
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
        fprintf (stderr, "error: test runner already initialised\n");
        return top_suite_;
      }

    if (strlen (top_suite_name) > 0)
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
        if (argc > 0 && argv != nullptr && argv[0] != nullptr)
          {
            std::string_view top_suite_name_view{ utility::extract_file_name (
                argv[0]) };

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

    const detail::options opts{ parse_options_ (argc, argv) };

    // Initialise and configure the reporter.
    if (opts.selected_reporter == detail::reporter_kind::human)
      {
        reporter_ = std::make_unique<detail::reporter_human> (opts);
      }
    else
      {
        reporter_ = std::make_unique<detail::reporter_tap> (opts);
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
   * - `--output-file=<path>` or `--output-file <path>`.
   *
   * When an option is repeated, the last one takes effect. An option
   * argument given separately is the next argument, whatever its content.
   * The other arguments are ignored. The whole command line is kept in the
   * options, to be listed by the reporter.
   */
  detail::options
  runner::parse_options_ (int argc, char* argv[])
  {
    detail::options opts{};

    if (argc <= 0 || argv == nullptr)
      {
        return opts;
      }

    opts.arguments = { argv, static_cast<size_t> (argc) };

    static constexpr std::string_view reporter_option{ "--reporter" };
    static constexpr std::string_view output_file_option{ "--output-file" };

    // Get the value of an option given as `--option=<value>` or as
    // `--option <value>`; the latter advances the index past the value.
    // Return false if the argument is not this option.
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
              exit (1);
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
                opts.selected_reporter = detail::reporter_kind::human;
              }
            else if (value == "tap")
              {
                opts.selected_reporter = detail::reporter_kind::tap;
              }
            else
              {
                fprintf (stderr, "error: unknown reporter '%.*s'\n",
                         static_cast<int> (value.size ()), value.data ());
                exit (1);
              }
          }
        else if (get_value (output_file_option, i, value))
          {
            // The value is a suffix of a null-terminated argv[] string,
            // so it is null-terminated too. An empty path disables the
            // output file.
            opts.output_file_path = value.empty () ? nullptr : value.data ();
          }
      }

    return opts;
  }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

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
   * Sorts `children_suites_` alphabetically by suite name using a
   * selection sort on `unique_ptr::swap`, avoiding the
   * `-Waggregate-return` diagnostic that `std::sort` would trigger on
   * unique-pointer iterators. Each suite is assigned a 1-based index
   * offset by the top-suite index, executed via `suite::run()`, and its
   * totals are accumulated into the runner totals. The executed-subtest
   * counter is not incremented; suites are not counted as subtests.
   */
  void
  runner::run_suites_ (void)
  {
    // Use selection sort with unique_ptr::swap (returns void) to avoid
    // std::sort triggering -Waggregate-return via std::move_backward,
    // which returns a class-type iterator when operating on unique_ptr
    // elements.
    const size_t n = children_suites_.size ();
    for (size_t i = 0; i < n; ++i)
      {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j)
          {
            if (std::string_view{ children_suites_[j]->name () }
                < std::string_view{ children_suites_[min_idx]->name () })
              min_idx = j;
          }
        if (min_idx != i)
          children_suites_[i].swap (children_suites_[min_idx]);
      }

    for (size_t i = 0; i < n; ++i)
      {
        auto* suite_ptr = children_suites_[i].get ();

        // +1 for 1-based index, +1 for top suite
        suite_ptr->own_index (i + 1 + 1);

        // Run the child suite immediately.
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
   * Subsequently invokes `run_suites_()` to sort, execute, and
   * accumulate all registered child suites. Finally, records the session
   * end timestamp, notifies the reporter, and returns `0` if all checks
   * passed or `1` otherwise.
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

    exit_code_ = totals_.was_successful () ? 0 : 1;
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
   * Prints the source location of the fatal error to `stderr` and then
   * terminates the process via `::abort()`.
   */
  void
  runner::abort (const reflection::source_location& sl)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    fprintf (stderr, "\nerror: test execution aborted at %s:%u\n",
             reflection::short_name (sl.file_name ()), sl.line ());

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
   * For the base `runner`, the total suite count equals `suites_count()`,
   * as there are no additional static suites.
   */
  size_t
  runner::total_suites_count (void) const noexcept
  {
    return suites_count ();
  }

  // ==========================================================================

  /**
   * @details
   * Delegates construction to the `runner` base class.
   * If tracing is enabled, the function signature
   * and suite name are output for diagnostic purposes.
   */
  static_runner::static_runner (void) : runner{}
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * Delegates construction to the `runner` base class with the given
   * @p top_suite_name. If tracing is enabled, the function signature
   * and suite name are output for diagnostic purposes.
   */
  static_runner::static_runner (const char* top_suite_name)
      : runner{ top_suite_name }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * If `static_children_suites_` is non-null, the dynamically allocated
   * vector of raw pointers is deleted and the pointer is reset to
   * `nullptr`. The pointed-to `static_suite` objects are not deleted,
   * as they are static storage-duration objects. If tracing is enabled,
   * the function signature is output for diagnostic purposes.
   */
  static_runner::~static_runner ()
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

    if (static_children_suites_ != nullptr)
      {
        // The tests are static, so we do not delete them, but we need to
        // delete the array of pointers.
        delete static_children_suites_;
        static_children_suites_ = nullptr;
      }
  }

  /**
   * @details
   * Returns the number of elements in `static_children_suites_`, or
   * zero if the vector has not been allocated yet.
   */
  size_t
  static_runner::static_suites_count (void) const noexcept
  {
    return static_children_suites_ != nullptr
               ? static_children_suites_->size ()
               : 0;
  }

  /**
   * @details
   * Returns the combined count of dynamically registered suites (from
   * the base `runner`) and statically registered suites.
   */
  size_t
  static_runner::total_suites_count (void) const noexcept
  {
    return suites_count () + static_suites_count ();
  }

  /**
   * @details
   * First invokes `runner::run_suites_()` to execute all dynamically
   * registered child suites. If `static_children_suites_` is non-null,
   * its contents are sorted alphabetically by suite name using selection
   * sort on raw pointers, each suite is assigned a 1-based index offset
   * by the dynamic suite count, executed via `suite::run()`, and its
   * totals are accumulated into the runner totals.
   */
  void
  static_runner::run_suites_ (void)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    runner::run_suites_ ();

    if (static_children_suites_ != nullptr)
      {
        // Use selection sort with std::swap on raw pointers (returns void)
        // to avoid std::sort triggering -Waggregate-return via
        // std::move_backward returning a class-type iterator.
        const size_t n = static_children_suites_->size ();
        auto& suites = *static_children_suites_;
        for (size_t i = 0; i < n; ++i)
          {
            size_t min_idx = i;
            for (size_t j = i + 1; j < n; ++j)
              {
                if (std::string_view{ suites[j]->name () }
                    < std::string_view{ suites[min_idx]->name () })
                  min_idx = j;
              }
            if (min_idx != i)
              std::swap (suites[i], suites[min_idx]);
          }

        for (size_t i = 0; i < n; ++i)
          {
            auto* suite_ptr = suites[i];

            suite_ptr->own_index (i + 1 + suites_count ());

            // Run the child suite immediately.
            suite_ptr->run ();

            // Accumulate the totals from the static suite into the runner
            // totals.
            // DO NOT increment executed_subtests here.
            totals_ += suite_ptr->totals ();
          }
      }
  }

  /**
   * @details
   * If `runner.static_children_suites_` is null, a new
   * `std::vector<static_suite*>` is heap-allocated and assigned to it.
   * The address of @p suite is then appended to the vector. This method
   * is intended to be called from the constructor of `static_suite`,
   * before test execution begins.
   */
  void
  static_runner::register_static_suite (static_runner& runner,
                                        static_suite& suite)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    if (runner.static_children_suites_ == nullptr)
      {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
        trace::printf ("%s new static_children_suites_ array\n",
                       __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED
        runner.static_children_suites_ = new std::vector<static_suite*>;
      }
    runner.static_children_suites_->push_back (&suite);
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

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
 * @brief C++ source file with implementations for the µTest++ test
 * hierarchy methods.
 *
 * @details
 * This source file contains the non-template implementations for the test
 * hierarchy of the µTest++ framework: the constructors and destructors, the
 * `run()` methods of the test cases and suites, which call the reporter
 * before and after invoking the stored callable, and the registration of
 * the child test cases, including the accumulation of their totals.
 *
 * All definitions reside within the `micro_os_plus::micro_test_plus`
 * namespace, ensuring clear separation from user code and minimising the risk
 * of naming conflicts.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#include "micro-os-plus/micro-test-plus/test.h"
#include "micro-os-plus/micro-test-plus/runner.h"

#if __has_include("micro-os-plus/diag/trace.h")
#include "micro-os-plus/diag/trace.h"
#endif // __has_include("micro-os-plus/diag/trace.h")

#include <cstring>
#include <exception>
#include <string>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wc++20-compat"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage-in-libc-call"
#else // GCC only
#pragma GCC diagnostic ignored "-Wredundant-tags"
#pragma GCC diagnostic ignored "-Wsuggest-final-types"
#pragma GCC diagnostic ignored "-Wsuggest-final-methods"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

namespace micro_os_plus::micro_test_plus
{
  namespace detail
  {
    // ========================================================================

    /**
     * @details
     * The constructor initialises a new instance of the `runnable_base` class
     * with the specified name, runner reference, and own index; the name
     * pointer is stored, and is expected to point to a string with a
     * lifetime exceeding that of this instance. The totals and the child
     * test point index start at zero and the children collection is empty.
     * If tracing is enabled, the function signature is output for
     * diagnostic purposes.
     */
    runnable_base::runnable_base (const char* name, runner& test_runner,
                                  size_t own_index)
        : name_{ name }, runner_{ test_runner }, own_index_{ own_index }
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s '%s' %zu\n", __PRETTY_FUNCTION__, name, own_index_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
    }

    /**
     * @details
     * The destructor destroys the owned child test cases, held by
     * `std::unique_ptr` in `child_test_cases_`. If tracing is enabled, the
     * name is output for diagnostic purposes.
     */
    runnable_base::~runnable_base ()
    {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

      // child_test_cases_ holds unique_ptrs; destroyed automatically.
    }

    /**
     * @details
     * Delegates immediately to `runner_.reporter()`, returning the
     * reporter associated with the owning runner instance.
     */
    [[nodiscard]] reporter&
    runnable_base::reporter_ (void) const noexcept
    {
      return *runner_.reporter_;
    }

    /**
     * @details
     * Delegates immediately to `runner_.abort()`, passing the supplied
     * source location so that the error message identifies the call site
     * before the process is terminated via `::abort()`.
     */
    [[noreturn]] void
    runnable_base::abort (const reflection::source_location& sl)
    {
      runner_.abort (sl);
    }

    /**
     * @details
     * Transfers ownership of @p child_test into `child_test_cases_` and
     * immediately invokes `test_case::run()` on the newly stored test case.
     *
     * If the filter patterns do not select the test case (its own name at
     * its nesting level, or the name of @p suite at level 0, which
     * matters only for the top suite, since the other suites run only
     * when selected), its body is not called: the reporter is notified
     * with `skip_test_case()` and the parent's skipped test cases counter is
     * incremented. The test case keeps its index and its place among the
     * children, so the TAP plan of the parent remains complete.
     *
     * Otherwise, the parent's executed test cases counter is incremented
     * after the run, and, if the child failed (a failed check, or a failed
     * nested test case), its failed test cases counter too, so that the
     * parent fails as well, as in node-tap. The child's check counters are
     * intentionally not merged into the parent totals; each test case
     * reports only its own counters.
     * The child's totals are, however, accumulated into @p suite so that
     * the suite summary reflects all checks performed by its test cases.
     */
    void
    runnable_base::after_test_case_create_ (
        std::unique_ptr<class test_case> child_test, suite& suite)
    {
      // Transfer ownership into the vector.
      child_test_cases_.push_back (std::move (child_test));

      class test_case& test_case = *child_test_cases_.back ();

      // Skip the test cases not selected by the filter; the outer test
      // cases, if any, were selected, otherwise this one was not created.
      if (!runner_.is_selected_ (suite.name (), 0)
          || !runner_.is_selected_ (test_case.name (),
                                    test_case.nesting_depth ()))
        {
          reporter_ ().skip_test_case (test_case);
          totals_.increment_skipped_test_cases ();
          return;
        }

      // Run the child test case immediately.
      test_case.run ();

      // This test executed one more test case.
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s test case '%s' executed one more test case\n",
                     __PRETTY_FUNCTION__, name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
      totals_.increment_executed_test_cases ();

      // Do not accumulate the totals from the child test into the current test
      // totals, each test case shows only its counters. But a failed child
      // fails this test too, as in node-tap; the failure reaches all outer
      // tests, one level at a time, when they end.
      if (!test_case.totals ().passed ())
        {
          totals_.increment_failed_test_cases ();
        }

#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
      trace::printf ("%s suite '%s' totals\n", __PRETTY_FUNCTION__,
                     suite.name ());
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

      // Accumulate the totals from the child test into the suite totals.
      suite.totals_ += test_case.totals ();
    }
  } // namespace detail

  // ==========================================================================

  /**
   * @details
   * No resources are owned directly by `test_case`; the nested test cases are
   * destroyed by the base class. If tracing is enabled, the name is output
   * for diagnostic purposes.
   */
  test_case::~test_case ()
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * Invokes the stored callable with this test case, surrounded by
   * reporter calls to begin and end the test case.
   *
   * When exceptions are enabled, an exception that escapes the callable
   * is caught and reported as a failed check of this test case, and the
   * test case ends normally, so that the run continues with the next test
   * case; the checks performed before the exception remain reported.
   * Since the nested test cases catch their own exceptions, an exception
   * is reported by the innermost test case whose body it escapes.
   *
   * The `detail::failed_requirement` exception, thrown after a failed
   * `require()`, only stops the body; the failure was already reported
   * and counted.
   */
  void
  test_case::run (void)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    detail::reporter& reporter = this->reporter_ ();

    // For now, test cases do not record the time.
    // this->stopwatch_.start ();
    reporter.begin_test_case (*this);

#if defined(__cpp_exceptions)
    try
      {
        // Invoke the callable, passing the self reference followed by the
        // variadic arguments.
        callable_ (*this);
      }
    catch (const detail::failed_requirement&)
      {
        // A failed require() stopped the test case; already reported.
      }
    catch (const std::exception& e)
      {
        fail_unexpected_exception_ (e.what ());
      }
    catch (...)
      {
        fail_unexpected_exception_ (nullptr);
      }
#else
    // Invoke the callable, passing the self reference followed by the variadic
    // arguments.
    callable_ (*this);
#endif // defined(__cpp_exceptions)

    // this->stopwatch_.stop ();
    reporter.end_test_case (*this);
  }

#if defined(__cpp_exceptions)
  /**
   * @details
   * The failure is reported as a check: the check index is incremented
   * first, as `check_result` does, so that the TAP output
   * numbers it after the checks already reported, and the failed checks
   * counter is incremented, so that the test case, and through it its
   * parents, fail.
   *
   * The message is `unexpected exception: ` followed by @p what, or
   * `unexpected exception of unknown type` when @p what is `nullptr`;
   * the type of a `std::exception` is not shown, since its name is
   * available only via RTTI, and only in an implementation-defined
   * (usually mangled) form. There is no expression to display.
   */
  void
  test_case::fail_unexpected_exception_ (const char* what)
  {
    next_test_point_number_ ();

    detail::failure_info failure{ .kind = detail::check_kind::expectation,
                                  .message = "unexpected exception",
                                  .has_expression = false,
                                  .location = location_ };
    if (what != nullptr)
      {
        failure.message.append (": ");
        failure.message.append (what);
      }
    else
      {
        failure.message.append (" of unknown type");
      }

    const std::string expression{};
    reporter_ ().fail (failure, expression, *this);
    totals_.increment_failed_checks ();
  }
#endif // defined(__cpp_exceptions)

  // ==========================================================================

  /**
   * @details
   * No resources are owned directly by `suite`; the destructor performs
   * no explicit clean-up. If tracing is enabled, the suite name is
   * output for diagnostic purposes.
   */
  suite::~suite ()
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  /**
   * @details
   * Invokes the stored callable with this suite, surrounded by
   * reporter calls to begin and end the suite.
   */
  void
  suite::run (void)
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    detail::reporter& reporter = this->reporter_ ();

    this->stopwatch_.start ();
    reporter.begin_suite (*this);

    // Invoke the callable, passing the self reference followed by the variadic
    // arguments.
    callable_ (*this);

    this->stopwatch_.stop ();
    reporter.end_suite (*this);
  }

  // ==========================================================================

  /**
   * @details
   * Initialises the base `suite` with @p name, the given @p test_runner, and
   * a no-op callable. Sets `own_index` to 1, reserving index 0 for the
   * runner itself. If tracing is enabled, the name is output for
   * diagnostic purposes.
   */
  top_suite::top_suite (const char* name, runner& test_runner)
      : suite{ name, test_runner, [] (suite&) noexcept {} }
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

    own_index_ = 1;
  }

  /**
   * @details
   * No resources are owned directly by `top_suite`; the destructor
   * performs no explicit clean-up. If tracing is enabled, the suite
   * name is output for diagnostic purposes.
   */
  top_suite::~top_suite ()
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
  }

  // ==========================================================================

  /**
   * @details
   * Constant-initialised, so it is null before any static constructor
   * runs; the static suites constructed before the runner are therefore
   * not lost.
   */
  constinit static_suite* static_suite::first_ = nullptr;

  /**
   * @details
   * Removes the suite from the list of static suites. If tracing is
   * enabled, the suite name is output for diagnostic purposes.
   */
  static_suite::~static_suite ()
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED

    unlink_ ();
  }

  /**
   * @details
   * Inserts the suite after the suites with names less than or equal to
   * its own, so the list remains sorted by name, and the suites with the
   * same name remain in the order of their construction. No memory is
   * allocated.
   */
  void
  static_suite::link_ (void) noexcept
  {
#if defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED)
    trace::printf ("%s '%s'\n", __PRETTY_FUNCTION__, name_);
#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED

    // std::strcmp() compares as unsigned char, like std::string_view,
    // without a temporary object (which triggers -Waggregate-return).
    static_suite** link = &first_;
    while (*link != nullptr && std::strcmp ((*link)->name_, name_) <= 0)
      {
        link = &(*link)->next_;
      }
    next_ = *link;
    *link = this;
  }

  /**
   * @details
   * Searches the list for the suite and, if found, bypasses it.
   */
  void
  static_suite::unlink_ (void) noexcept
  {
    for (static_suite** link = &first_; *link != nullptr;
         link = &(*link)->next_)
      {
        if (*link == this)
          {
            *link = next_;
            next_ = nullptr;
            return;
          }
      }
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

#endif // defined(MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED)

// ----------------------------------------------------------------------------

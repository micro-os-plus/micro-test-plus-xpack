/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * Major parts of the code are inspired from v1.1.8 of the Boost UT project,
 * released under the terms of the Boost Version 1.0 Software License,
 * which can be obtained from <https://www.boost.org/LICENSE_1_0.txt>.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>
#include <cstring>
// <iostream> is too heavy for embedded, use printf().
#include <stdio.h>
#include <unistd.h>

// ----------------------------------------------------------------------------

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // Public API.

  void
  initialize (const char* name, int argc, char* argv[])
  {
#if defined(MICRO_TEST_PLUS_DEBUG)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif
    runner.initialize (name, argc, argv);
  }

  int
  exit_code (void)
  {
    return runner.exit_code ();
  }

  // --------------------------------------------------------------------------

  namespace reflection
  {
    const char*
    short_name (const char* name)
    {
      const char* p = strrchr (name, '/');
      if (p != nullptr)
        return p + 1;
      else
        return name;
    }

  } // namespace reflection

  // --------------------------------------------------------------------------

  test_runner::test_runner ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    micro_os_plus::trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  void
  test_runner::initialize (const char* name, int argc, char* argv[])
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    micro_os_plus::trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    default_suite_name_ = name;

    this->argc_ = argc;
    this->argv_ = argv;

#if defined(__clang__)
    printf ("Built with clang " __VERSION__);
#elif defined(__GNUC__)
    printf ("Built with GCC " __VERSION__);
#elif defined(_MSC_VER)
    // https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170
    printf ("Built with MSVC %d", _MSC_VER);
#else
    printf ("Built with an unknown compiler");
#endif
#if defined(__ARM_PCS_VFP)
    printf (", with FP");
#else
    printf (", no FP");
#endif
#if defined(__EXCEPTIONS)
    printf (", with exceptions");
#else
    printf (", no exceptions");
#endif
#if defined(MICRO_OS_PLUS_DEBUG)
    printf (", with MICRO_OS_PLUS_DEBUG");
#endif
    puts (".");

#if defined(MICRO_OS_PLUS_DEBUG)
    printf ("argv[] = ");
    for (int i = 0; i < argc; ++i)
      {
        printf ("'%s' ", argv[i]);
      }
    puts ("");
#endif

    default_test_suite_ = new test_suite (default_suite_name_);

    default_test_suite_->begin ();
  }

  int
  test_runner::exit_code (void)
  {
    default_test_suite_->end ();

    bool success = default_test_suite_->success ();

    if (suites_ != nullptr)
      {
        for (auto suite : *suites_)
          {
            default_test_suite_ = suite;
            suite->run ();

            success &= suite->success ();
          }
      }
    return success ? 0 : 1;
  }

  void
  test_runner::register_test_suite (test_suite* suite)
  {
#if 0 // defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    micro_os_plus::trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    if (suites_ == nullptr)
      {
        suites_ = new std::vector<test_suite*> ();
      }
    suites_->push_back (suite);
  }

  // --------------------------------------------------------------------------

  test_reporter&
  endl (test_reporter& stream)
  {
    printf ("\n");
    fflush (stdout);
    return stream;
  }

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#endif

  void
  test_reporter::print_where (const char* format, const char* file, int line)
  {
    if (file != nullptr)
      {
        printf (format, file, line);
      }
  }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  void
  test_reporter::flush (void)
  {
    //#if !defined(__MINGW32__)
    fflush (stdout); // Sync STDOUT.
    //#endif
  }

  // --------------------------------------------------------------------------

  test_suite::test_suite (const char* name)
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    micro_os_plus::trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS

    name_ = name;
    // callable_ = [] {};

    // The default test suite needs no registration.
  }

  void
  test_suite::run ()
  {
    if (callable_ != nullptr)
      {
        begin ();
        callable_ ();
        end ();
      }
  }

  void
  test_suite::begin (void)
  {
    current_test_suite = this;

    printf ("\n%s\n", name_);
  }

  void
  test_suite::end (void)
  {
    // Also fail if none passed.
    if (failed_ == 0 && passed_ != 0)
      {
        printf ("\n%s passed (%d checks in %d test cases)\n", name_, passed_,
                test_cases_);
      }
    else
      {
        printf (
            "\n%s failed (%d checks passed, %d failed, in %d test cases)\n",
            name_, passed_, failed_, test_cases_);
      }
  }

  void
  test_suite::begin_test_case (const char* name)
  {
    printf ("\n  %s\n", name);
    test_case_name_ = name;
    ++test_cases_;
  }

  void
  test_suite::end_test_case ()
  {
  }

  // --------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
#endif

  // Static instances;
  test_runner runner;
  test_reporter reporter;

  test_suite* current_test_suite;

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

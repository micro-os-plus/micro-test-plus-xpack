/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>
#include <cstring>
// <iostream> is too heavy for embedded, use printf().
#include <stdio.h>

// ----------------------------------------------------------------------------

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  test_runner::test_runner ()
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    micro_os_plus::trace::printf ("%s()\n", __PRETTY_FUNCTION__);
#endif // MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  }

  void
  test_runner::init (const char* name, int argc, char* argv[])
  {
#if defined(MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS)
    micro_os_plus::trace::printf ("%s()\n", __PRETTY_FUNCTION__);
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

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#endif

  void
  test_runner::print_where_ (const char* format, const char* file, int line)
  {
    if (file != nullptr)
      {
        printf (format, file, line);
      }
  }

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  int
  test_runner::result (void)
  {
    default_test_suite_->end ();

    int result = default_test_suite_->result ();

    if (suites_ != nullptr)
      {
        for (auto suite : *suites_)
          {
            default_test_suite_ = suite;
            suite->run ();

            result |= suite->result ();
          }
      }
    return result;
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
    ++test_cases_;
  }

  void
  test_suite::end_test_case ([[maybe_unused]] const char* name)
  {
  }

  int
  test_suite::result (void)
  {
    // Also fail if none passed.
    if (failed_ == 0 && passed_ != 0)
      {
        return 0;
      }
    else
      {
        return 1;
      }
  }

  // --------------------------------------------------------------------------

  void
  init (const char* name, int argc, char* argv[])
  {
#if defined(MICRO_TEST_PLUS_DEBUG)
    trace::printf ("%s\n", __PRETTY_FUNCTION__);
#endif
    runner.init (name, argc, argv);
  }

  void
  pass (const char* message, [[maybe_unused]] const char* file,
        [[maybe_unused]] int line)
  {
    // The file name and line number are unused in this version;
    // they are present only in case future versions will keep a
    // log off all tests.
    printf ("    ✓ %s\n", message);

    current_test_suite->pass ();
  }

  void
  fail (const char* message, const char* file, int line)
  {
    printf ("    ✗ %s", message);
    runner.print_where_ (" (in '%s:%d')", file, line);
    printf ("\n");

    current_test_suite->fail ();
  }

  void
  expect_true (bool condition, const char* message, const char* file, int line)
  {
    if (condition)
      {
        printf ("    ✓ %s\n", message);
        current_test_suite->pass ();
      }
    else
      {
        printf ("    ✗ %s", message);
        runner.print_where_ (" (in '%s:%d')", file, line);
        printf ("\n");
        current_test_suite->fail ();
      }
  }

  int
  result (void)
  {
    return runner.result ();
  }

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wglobal-constructors"
#endif

  // Static instance;
  test_runner runner;
  test_suite* current_test_suite;

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

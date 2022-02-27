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
    this->argc_ = 0;
    this->argv_ = nullptr;

    passed_ = 0;
    failed_ = 0;
    test_cases_ = 0;
  }

  test_runner::test_runner (int argc, char* argv[])
  {
    init (argc, argv);
  }

  void
  test_runner::init (int argc, char* argv[])
  {
    this->argc_ = argc;
    this->argv_ = argv;

    passed_ = 0;
    failed_ = 0;
    test_cases_ = 0;

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
  }

  void
  test_runner::start_suite (const char* name)
  {
    name_ = name;
    printf ("\n%s started\n", name);
  }

  void
  test_runner::start_test_case (const char* name)
  {
    printf ("\n  %s\n", name);
  }

  void
  test_runner::run_test_case (void (*function) (test_runner&), const char* name)
  {
    start_test_case (name);

    (*function) (*this);

    test_cases_++;
  }

  void
  test_runner::run_test_case (const char* name, void (*function) (test_runner&))
  {
    start_test_case (name);

    (*function) (*this);

    test_cases_++;
  }

  void
  test_runner::pass (const char* message, [[maybe_unused]] const char* file,
                 [[maybe_unused]] int line)
  {
    // The file name and line number are unused in this version;
    // they are present only in case future versions will keep a
    // log off all tests.
    printf ("    ✓ %s\n", message);

    passed_++;
  }

  void
  test_runner::fail (const char* message, const char* file, int line)
  {
    printf ("    ✗ %s", message);
    print_where_ (" (in '%s:%d')", file, line);
    printf ("\n");

    failed_++;
  }

  void
  test_runner::expect_true (bool condition, const char* message, const char* file,
                        int line)
  {
    if (condition)
      {
        printf ("    ✓ %s\n", message);
        passed_++;
      }
    else
      {
        printf ("    ✗ %s", message);
        print_where_ (" (in '%s:%d')", file, line);
        printf ("\n");
        failed_++;
      }
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
    // Also fail if none passed.
    if (failed_ == 0 && passed_ != 0)
      {
        printf ("\n%s passed (%d tests in %d test cases)\n", name_, passed_,
                test_cases_);
        return 0;
      }
    else
      {
        printf ("\n%s failed (%d tests passed, %d failed, in %d test cases)\n",
                name_, passed_, failed_, test_cases_);
        return 1;
      }
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

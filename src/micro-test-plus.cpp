/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 */

#include <micro-os-plus/micro-test-plus.h>
#include <stdio.h>
#include <cstring>

// ----------------------------------------------------------------------------

#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

namespace micro_os_plus
{
  namespace micro_test_plus
  {

    // ------------------------------------------------------------------------

    session::session ()
    {
      this->argc_ = 0;
      this->argv_ = nullptr;

      passed_ = 0;
      failed_ = 0;
      test_cases_ = 0;
    }

    session::session (int argc, char* argv[])
    {
      init (argc, argv);
    }

    void
    session::init (int argc, char* argv[])
    {
      this->argc_ = argc;
      this->argv_ = argv;

      passed_ = 0;
      failed_ = 0;
      test_cases_ = 0;

#if defined(__clang__)
      printf ("Built with clang " __VERSION__);
#else
      printf ("Built with GCC " __VERSION__);
#endif
#if defined(__EXCEPTIONS)
      printf (", with exceptions");
#else
      printf (", no exceptions");
#endif
#if defined(DEBUG)
      printf (", with DEBUG");
#endif
      puts (".");

#if defined(DEBUG)
      printf ("argv[] = ");
      for (int i = 0; i < argc; ++i)
        {
          printf ("'%s' ", argv[i]);
        }
      puts ("");
#endif
    }

    void
    session::start_suite (const char* name)
    {
      name_ = name;
      printf ("\n%s started\n", name);
    }

    void
    session::run_test_case (void (*function) (session&), const char* name)
    {
      printf ("\n  %s\n", name);

      (*function) (*this);
      test_cases_++;
    }

    void
    session::pass (const char* message,
                   const char* file __attribute__ ((unused)),
                   int line __attribute__ ((unused)))
    {
      // The file name and line number are unused in this version;
      // they are present only in case future versions will keep a
      // log off all tests.
      printf ("    ✓ %s\n", message);
      passed_++;
    }

    void
    session::fail (const char* message, const char* file, int line)
    {
      printf ("    ✗ %s", message);
      print_where_ (" (in '%s:%d')", file, line);
      printf ("\n");

      failed_++;
    }

    void
    session::expect_true (bool condition, const char* message,
                          const char* file, int line)
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

    void
    session::expect_eq (int actual, int expected, const char* message,
                        const char* file, int line)
    {
      if (actual == expected)
        {
          printf ("    ✓ %s\n", message);
          passed_++;
        }
      else
        {
          printf ("    ✗ %s (expected %d, got %d", message, expected, actual);
          print_where_ (", in '%s:%d'", file, line);
          printf (")\n");
          failed_++;
        }
    }

    void
    session::expect_eq (long actual, long expected, const char* message,
                        const char* file, int line)
    {
      if (actual == expected)
        {
          printf ("    ✓ %s\n", message);
          passed_++;
        }
      else
        {
          printf ("    ✗ %s (expected %ld, got %ld", message, expected,
                  actual);
          print_where_ (", in '%s:%d'", file, line);
          printf (")\n");
          failed_++;
        }
    }

    void
    session::expect_eq (const char* actual, const char* expected,
                        const char* message, const char* file, int line)
    {
      if (std::strcmp (actual, expected) == 0)
        {
          printf ("    ✓ %s\n", message);
          passed_++;
        }
      else
        {
          printf ("    ✗ %s (expected '%s', got '%s'", message, expected,
                  actual);
          print_where_ (", in '%s:%d'", file, line);
          printf (")\n");
          failed_++;
        }
    }

#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wformat-nonliteral"

    void
    session::print_where_ (const char* format, const char* file, int line)
    {
      if (file != nullptr)
        {
          printf (format, file, line);
        }
    }

#pragma GCC diagnostic pop

    int
    session::result (void)
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
          printf (
              "\n%s failed (%d tests passed, %d failed, in %d test cases)\n",
              name_, passed_, failed_, test_cases_);
          return 1;
        }
    }

    // ------------------------------------------------------------------------
  } // namespace micro_test_plus
} // namespace micro_os_plus

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------

/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2021 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from <https://opensource.org/licenses/MIT/>.
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
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
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

  // ==========================================================================

  test_reporter&
  endl (test_reporter& stream)
  {
    printf ("\n");
    fflush (stdout);
    return stream;
  }

  void
  test_reporter::flush (void)
  {
    //#if !defined(__MINGW32__)
    fflush (stdout); // Sync STDOUT.
    //#endif
  }

  test_reporter&
  test_reporter::operator<< (std::string_view sv)
  {
    printf ("%s", sv.data ());
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (char c)
  {
    printf ("%c", c);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (const char* s)
  {
    printf ("%s", s);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (char* s)
  {
    printf ("%s", s);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (bool v)
  {
    printf ("%s", v ? "true_b" : "false_b");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (std::nullptr_t)
  {
    printf ("nullptr");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed char c)
  {
    printf ("%d_sc", c);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned char c)
  {
    printf ("%d_uc", c);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed short c)
  {
    printf ("%d_s", c);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned short c)
  {
    printf ("%u_us", c);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed int v)
  {
    printf ("%d_i", v);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned int v)
  {
    printf ("%u_u", v);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed long v)
  {
    printf ("%ld_l", v);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned long v)
  {
    printf ("%lu_ul", v);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed long long v)
  {
    printf ("%lld_ll", v);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned long long v)
  {
    printf ("%llu_ull", v);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (float v)
  {
    printf ("%f_f", static_cast<double> (v));
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (double v)
  {
    printf ("%f_d", v);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (long double v)
  {
    printf ("%Lf_ld", v);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (test_reporter& (*func) (test_reporter&))
  {
    // Call the endl function.
    (*func) (*this);
    return *this;
  }

  // ==========================================================================

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
    fflush (stdout);
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
    fflush (stdout);
  }

  void
  test_suite::begin_test_case (const char* name)
  {
    printf ("\n  %s\n", name);
    fflush (stdout);
    test_case_name_ = name;
    ++test_cases_;
  }

  void
  test_suite::end_test_case ()
  {
    fflush (stdout);
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

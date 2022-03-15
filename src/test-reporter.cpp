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

// ----------------------------------------------------------------------------

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  test_reporter&
  endl (test_reporter& stream)
  {
    printf ("\n");
    reporter.flush ();
    return stream;
  }

  // --------------------------------------------------------------------------

  void
  test_reporter::flush (void)
  {
    fflush (stdout); // Sync STDOUT.
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
    printf ("%s", v ? "true" : "false");
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
    printf ("%d%s", c, "c");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned char c)
  {
    printf ("%d%s", c, "uc");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed short c)
  {
    printf ("%d%s", c, "s");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned short c)
  {
    printf ("%u%s", c, "us");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed int v)
  {
    printf ("%d", v);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned int v)
  {
    printf ("%u%s", v, "u");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed long v)
  {
    printf ("%ld%s", v, "l");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned long v)
  {
    printf ("%lu%s", v, "ul");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed long long v)
  {
    printf ("%lld%s", v, "ll");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned long long v)
  {
    printf ("%llu%s", v, "ull");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (float v)
  {
    printf ("%f%s", static_cast<double> (v), "f");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (double v)
  {
    printf ("%f", v);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (long double v)
  {
    printf ("%Lf%s", v, "l");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (test_reporter& (*func) (test_reporter&))
  {
    // Call the endl function.
    (*func) (*this);
    return *this;
  }

  void
  test_reporter::begin_test_case (const char* name)
  {
    printf ("\n  %s\n", name);
    flush ();
  }

  void
  test_reporter::end_test_case ([[maybe_unused]] const char* name)
  {
    flush ();
  }

  void
  test_reporter::begin_test_suite (const char* name)
  {
    flush ();
    printf ("\n%s\n", name);
  }

  void
  test_reporter::end_test_suite (test_suite& suite)
  {
    // Also fail if none passed.
    if (suite.failed () == 0 && suite.passed () != 0)
      {
        printf ("\n%s passed (%d checks in %d test cases)\n", suite.name (),
                suite.passed (), suite.test_cases ());
      }
    else
      {
        printf (
            "\n%s failed (%d checks passed, %d failed, in %d test cases)\n",
            suite.name (), suite.passed (), suite.failed (),
            suite.test_cases ());
      }
    flush ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

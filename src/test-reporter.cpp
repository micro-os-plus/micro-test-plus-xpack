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

#pragma GCC diagnostic ignored "-Waggregate-return"
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
    reporter.endline ();
    return stream;
  }

  // --------------------------------------------------------------------------

  void
  test_reporter::output_pass_prefix_ (std::string& message)
  {
    *this << colors_.pass;
    if (is_in_test_case_)
      {
        *this << "  ";
      }
    *this << "  ✓ ";
    *this << colors_.none;
    if (!message.empty ())
      {
        *this << message.c_str ();
      }
  }

  void
  test_reporter::output_pass_suffix_ (void)
  {
    *this << endl;

    flush ();
  }

  void
  test_reporter::output_fail_prefix_ (
      std::string& message, const reflection::source_location& location)
  {
    *this << colors_.fail;
    if (is_in_test_case_)
      {
        *this << "  ";
      }
    *this << "  ✗ ";
    *this << colors_.none;
    if (!message.empty ())
      {
        *this << message.c_str ();
        *this << " ";
      }
    *this << colors_.fail << "FAILED" << colors_.none;
    *this << " (" << reflection::short_name (location.file_name ()) << ":"
          << type_traits::genuine_integral_value<int>{ location.line () };
  }

  void
  test_reporter::output_fail_suffix_ (bool abort)
  {
    *this << ")";
    if (abort)
      {
        *this << " aborted...";
      }
    *this << endl;

    flush ();
  }

  test_reporter&
  test_reporter::operator<< (test_reporter& (*func) (test_reporter&))
  {
    // Call the endl function.
    (*func) (*this);
    return *this;
  }

  void
  test_reporter::endline (void)
  {
    out_.append ("\n");
    flush ();
  }

  void
  test_reporter::flush (void)
  {
    fflush (stdout); // Sync STDOUT.
  }

  test_reporter&
  test_reporter::operator<< (std::string_view sv)
  {
    out_.append (sv);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (char c)
  {
    out_.append (1, c);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (const char* s)
  {
    out_.append (s);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (char* s)
  {
    out_.append (s);
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (bool v)
  {
    out_.append (v ? "true" : "false");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (std::nullptr_t)
  {
    out_.append ("nullptr");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed char c)
  {
    out_.append (std::to_string (c));
    out_.append ("c");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned char c)
  {
    out_.append (std::to_string (static_cast<int> (c)));
    out_.append ("uc");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed short v)
  {
    out_.append (std::to_string (v));
    out_.append ("s");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned short v)
  {
    out_.append (std::to_string (static_cast<long> (v)));
    out_.append ("us");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed int v)
  {
    out_.append (std::to_string (v));
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned int v)
  {
    out_.append (std::to_string (v));
    out_.append ("u");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed long v)
  {
    out_.append (std::to_string (v));
    out_.append ("l");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned long v)
  {
    out_.append (std::to_string (v));
    out_.append ("ul");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (signed long long v)
  {
    out_.append (std::to_string (v));
    out_.append ("ll");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (unsigned long long v)
  {
    out_.append (std::to_string (v));
    out_.append ("ull");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (float v)
  {
    out_.append (std::to_string (v));
    out_.append ("f");
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (double v)
  {
    out_.append (std::to_string (v));
    return *this;
  }

  test_reporter&
  test_reporter::operator<< (long double v)
  {
    out_.append (std::to_string (v));
    out_.append ("l");
    return *this;
  }

  void
  test_reporter::begin_test_case ([[maybe_unused]] const char* name)
  {
    is_in_test_case_ = true;

    if (!out_.empty () && (verbosity == verbosity::verbose))
      {
        if (add_empty_line)
          {
            printf ("\n");
          }
        output ();
        add_empty_line = true;
      }

    out_.clear ();

    flush ();
  }

  void
  test_reporter::end_test_case ([[maybe_unused]] const char* name)
  {
    if (verbosity == verbosity::normal || verbosity == verbosity::verbose)
      {
        if (current_test_suite->current_test_case.failed_checks > 0)
          {
            if (true /* add_empty_line */)
              {
                printf ("\n");
              }
            printf ("  • %s - test case started\n", name);
            output ();
            printf (
                "  %s✗%s %s - test case %sFAILED%s (%d %s passed, %d "
                "failed)\n",
                colors_.fail, colors_.none, name, colors_.fail, colors_.none,
                current_test_suite->current_test_case.successful_checks,
                current_test_suite->current_test_case.successful_checks == 1
                    ? "check"
                    : "checks",
                current_test_suite->current_test_case.failed_checks);
            add_empty_line = true;
          }
        else
          {
            if (add_empty_line)
              {
                printf ("\n");
              }
            if (verbosity == verbosity::verbose)
              {
                printf ("  • %s - test case started\n", name);
                output ();
                printf (
                    "  %s✓%s %s - test case passed (%d %s)\n", colors_.pass,
                    colors_.none, name,
                    current_test_suite->current_test_case.successful_checks,
                    current_test_suite->current_test_case.successful_checks
                            == 1
                        ? "check"
                        : "checks");

                add_empty_line = true;
              }
            else
              {
                printf (
                    "  %s✓%s %s - test case passed (%d %s)\n", colors_.pass,
                    colors_.none, name,
                    current_test_suite->current_test_case.successful_checks,
                    current_test_suite->current_test_case.successful_checks
                            == 1
                        ? "check"
                        : "checks");

                add_empty_line = false;
              }
          }
      }

    out_.clear ();
    flush ();

    is_in_test_case_ = false;
  }

  void
  test_reporter::begin_test_suite (const char* name)
  {
    if (add_empty_line)
      {
        flush ();
        printf ("\n");
      }

    if (verbosity == verbosity::silent || verbosity == verbosity::quiet)
      {
        add_empty_line = false;
        return;
      }

    printf ("• %s - test suite started\n", name);

    add_empty_line = true;
  }

  void
  test_reporter::end_test_suite (test_suite_base& suite)
  {
    if (verbosity == verbosity::silent)
      {
        return;
      }

    if (suite.test_cases () > 0 && verbosity != verbosity::quiet)
      {
        printf ("\n");
        add_empty_line = true;
      }

    // Also fail if none passed.
    if (suite.failed_checks () == 0 && suite.successful_checks () != 0)
      {
        printf ("%s✓%s %s - test suite passed (%d %s in %d test %s)\n",
                colors_.pass, colors_.none, suite.name (),
                suite.successful_checks (),
                suite.successful_checks () == 1 ? "check" : "checks",
                suite.test_cases (),
                suite.test_cases () == 1 ? "case" : "cases");
      }
    else
      {
        printf ("%s✗%s %s - test suite %sFAILED%s (%d %s passed, %d failed, "
                "in %d test %s)\n",
                colors_.fail, colors_.none, suite.name (), colors_.fail,
                colors_.none, suite.successful_checks (),
                suite.successful_checks () == 1 ? "check" : "checks",
                suite.failed_checks (), suite.test_cases (),
                suite.test_cases () == 1 ? "case" : "cases");
      }
    flush ();
  }

  void
  test_reporter::output (void)
  {
    printf ("%s", out_.c_str ()); // No `\n` here.
    out_.clear ();
  }

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

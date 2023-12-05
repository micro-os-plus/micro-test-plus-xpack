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
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // Public API.

  /**
   * @details
   * All tests include a default test suite, which runs the test cases
   * defined in the main function.
   *
   * This function forwards the process arguments to the test framework
   * and initialises the runner.
   *
   * The name is used to identify the default test suite.
   *
   * The arguments can be used to control the verbosity level.
   */
  void
  initialize (int argc, char* argv[], const char* name)
  {
#if defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif
    runner.initialize (argc, argv, name);
  }

  /**
   * @details
   * In addition to the test cases defined in `main()`, there can be
   * more separate **test suites**, defined as static objects in the same
   * file or in other files,
   * and self-registered via the static constructors mechanism.
   *
   * This function triggers the execution of the globally
   * registered test suites
   * (if any) and returns the test result as the process exit code
   * (0 = success).
   */
  int
  exit_code (void)
  {
    return runner.exit_code ();
  }

  // --------------------------------------------------------------------------
  // Too small to deserve a separate source file.
  namespace reflection
  {

    const char*
    short_name (const char* name)
    {
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
      const char* p = strrchr (name, '/');
      if (p != nullptr)
        return p + 1;
      else
        return name;
#pragma GCC diagnostic pop
    }

  } // namespace reflection

  namespace utility
  {
    /**
     * @details
     * For tests comparing strings, in addition to exact matches,
     * it is also possible to check matches with patterns like `*`
     * (for any characters) and `?` (for a single character)
     *
     * @par Examples
     *
     * ```cpp
     * namespace mt = micro_os_plus::micro_test_plus;
     *
     * mt::expect (mt::utility::is_match ("abc", "a?c")) << "abc matches a?c";
     * mt::expect (mt::utility::is_match ("abc", "a*c")) << "abc matches a*c";
     * ```
     */
    [[nodiscard]] bool
    is_match (std::string_view input, std::string_view pattern)
    {
      if (std::empty (pattern))
        {
          return std::empty (input);
        }

      if (std::empty (input))
        {
          return pattern[0] == '*' ? is_match (input, pattern.substr (1))
                                   : false;
        }

      if (pattern[0] != '?' and pattern[0] != '*' and pattern[0] != input[0])
        {
          return false;
        }

      if (pattern[0] == '*')
        {
          for (decltype (std::size (input)) i = 0u; i <= std::size (input);
               ++i)
            {
              if (is_match (input.substr (i), pattern.substr (1)))
                {
                  return true;
                }
            }
          return false;
        }

      return is_match (input.substr (1), pattern.substr (1));
    }

  } // namespace utility

  namespace detail
  {
    deferred_reporter_base::deferred_reporter_base (
        bool value, const reflection::source_location location)
        : value_{ value }, location_{ location }
    {
      if (value_)
        {
          current_test_suite->increment_successful ();
        }
      else
        {
          current_test_suite->increment_failed ();
        }
    }

    deferred_reporter_base::~deferred_reporter_base ()
    {
#if 0 // defined(MICRO_TEST_PLUS_TRACE)
      printf ("%s\n", __PRETTY_FUNCTION__);
#endif // MICRO_TEST_PLUS_TRACE

      if (abort_ && !value_)
        {
          printf ("\n");
          reporter.output ();
          abort ();
        }
    }

  } // namespace detail

  // ==========================================================================

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
#endif

  // Static instances;
  test_runner runner;
  test_reporter reporter;

  test_suite_base* current_test_suite;

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

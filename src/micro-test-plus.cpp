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
#endif

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // Public API.

  void
  initialize (const char* name, int argc, char* argv[])
  {
#if defined(MICRO_TEST_PLUS_TRACE)
    printf ("%s\n", __PRETTY_FUNCTION__);
#endif
    runner.initialize (name, argc, argv);
  }

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
      const char* p = strrchr (name, '/');
      if (p != nullptr)
        return p + 1;
      else
        return name;
    }

  } // namespace reflection

  namespace utility
  {
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

  test_suite* current_test_suite;

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

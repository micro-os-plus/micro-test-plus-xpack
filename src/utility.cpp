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
 * @brief C++ source file with implementations for the µTest++ methods.
 *
 * @details
 * This source file contains the implementations of the utility functions
 * for the µTest++ framework. It provides `extract_file_name()`, which
 * strips the folder path from a file path returning only the base name,
 * and `is_match()`, which performs wildcard pattern matching with `*`
 * (any sequence of characters) and `?` (any single character) support.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::utility` namespace.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  namespace utility
  {
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wdocumentation"
#endif
#endif
    /**
     * @details
     * The `extract_file_name` function extracts the file name from a given
     * file path, handling both Unix-style (`/`) and Windows-style (`\`) path
     * separators. It returns a pointer to the start of the file name within
     * the input string, or the original string if no separators are found.
     *
     * This utility is particularly useful for test reporting, allowing for
     * concise display of file names without full paths.
     *
     * @par Example
     *
     * @code{.cpp}
     * const char* path = "/home/user/project/test.cpp";
     * const char* filename = utility::extract_file_name (path);
     * // filename now points to "test.cpp"
     * @endcode
     */
    [[nodiscard]] const char*
    extract_file_name (const char* path) noexcept
    {
      const std::string_view sv{ path };
      const auto pos = sv.find_last_of ("/\\");
      if (pos == std::string_view::npos)
        {
          return path; // No separators found, return original string.
        }
      return sv.substr (pos + 1).data ();
    }

/**
 * @details
 * This function enables pattern-based string comparison for tests, supporting
 * both exact matches and wildcard patterns. The pattern may include `*` to
 * match any sequence of characters and `?` to match any single character. This
 * allows for flexible validation of string content in test assertions,
 * accommodating variable or partially known values.
 *
 * @warning The `*` wildcard is handled via recursion with a linear loop,
 *   giving $O(2^n)$ worst-case complexity in the number of `*` wildcards
 *   (e.g. a pattern such as `"a*a*a*b"` against a long string of `'a'`
 *   characters). For the typical short suite-name patterns used in a test
 *   framework this is not a concern, but callers should avoid patterns with
 *   many consecutive wildcards against long input strings.
 *
 * @par Examples
 *
 * @code{.cpp}
 * namespace mt = micro_os_plus::micro_test_plus;
 *
 * mt::expect (mt::utility::is_match ("abc", "a?c")) << "abc matches a?c";
 * mt::expect (mt::utility::is_match ("abc", "a*c")) << "abc matches a*c";
 * @endcode
 */
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
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
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

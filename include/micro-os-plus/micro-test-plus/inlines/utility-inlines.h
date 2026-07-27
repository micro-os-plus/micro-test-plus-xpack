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
 * @brief C++ header file with inline implementations for the µTest++ utility
 * functions.
 *
 * @details
 * This header provides the inline implementations for the utility function
 * templates used within the µTest++ framework. It defines the logic for
 * splitting strings into substrings using a specified delimiter, enabling
 * convenient and type-safe string parsing in test expressions.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::utility` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_UTILITY_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_UTILITY_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
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
    /**
     * @details
     * This function template facilitates string handling in tests by splitting
     * a string into a vector of substrings, using the specified delimiter.
     *
     * The function iterates through the input string, identifying delimiter
     * positions and extracting substrings between them. Each resulting
     * substring is added to the output vector. This approach supports flexible
     * parsing of delimited data, which is particularly useful for validating
     * string processing logic in test cases.
     *
     * **Example**
     *
     * @code{.cpp}
     * namespace mt = micro_os_plus::micro_test_plus;
     *
     * t.expect (std::vector<std::string_view>{ "a", "b" }
     *             == mt::utility::split<std::string_view> ("a.b", "."))
     *         << "a.b splits into [a,b]";
     * @endcode
     */
    template <class T = std::string_view, class Delim_T>
    [[nodiscard]] auto
    split (T input, Delim_T delim) -> std::vector<T>
    {
      std::vector<T> output{};
      std::size_t first{};
      while (first < std::size (input))
        {
          const auto second = input.find_first_of (delim, first);
          if (first != second)
            {
              output.emplace_back (input.substr (first, second - first));
            }
          if (second == T::npos)
            {
              break;
            }
          first = second + 1;
        }
      return output;
    }

    // ------------------------------------------------------------------------
  } // namespace utility

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_UTILITY_INLINES_H_

// ----------------------------------------------------------------------------

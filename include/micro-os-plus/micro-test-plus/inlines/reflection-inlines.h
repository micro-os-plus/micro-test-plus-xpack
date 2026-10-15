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
 * @brief C++ header file with inline implementations for the µTest++
 * reflection utilities.
 *
 * @details
 * This header provides the inline implementations for the reflection utilities
 * used within the µTest++ framework. It includes the logic for capturing and
 * reporting source location information, such as file names and line numbers,
 * as well as utilities for extracting type names at compile time using
 * compiler-specific macros.
 *
 * The `source_location` implementation offers a lightweight,
 * constexpr-compatible alternative to `std::source_location`, used when the
 * standard library does not provide it. The `type_name` utility parses the
 * compiler-specific `__PRETTY_FUNCTION__` string to obtain human-readable
 * type names for improved test output and debugging.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::reflection` namespace, ensuring clear
 * separation from user code and minimising the risk of naming conflicts.
 *
 * The header files are organised within the
 * `include/micro-os-plus/micro-test-plus` folder to maintain a structured and
 * modular codebase.
 *
 * This file is intended solely for internal use within the framework and
 * should not be included directly by user code.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_REFLECTION_INLINES_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_REFLECTION_INLINES_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include <cstdint>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif // defined(__clang__)
#endif // defined(__GNUC__)

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------

  namespace reflection
  {
    // ------------------------------------------------------------------------

#if !defined(__cpp_lib_source_location)

    /**
     * @details
     * Returns a `source_location` instance representing the file name and
     * line number at the point of invocation.
     *
     * If supported by the compiler, uses built-in macros to capture this
     * information; otherwise, defaults to `"unknown"` and zero.
     */
    constexpr source_location
    source_location::current (const char* file, unsigned int line) noexcept
    {
      source_location sl{};
      sl.file_ = file;
      sl.line_ = line;
      return sl;
    }

    /**
     * @details
     * Returns the file name captured at the time this `source_location`
     * instance was created.
     */
    constexpr auto
    source_location::file_name (void) const noexcept
    {
      return file_;
    }

    /**
     * @details
     * Returns the line number captured at the time this `source_location`
     * instance was created.
     */
    constexpr auto
    source_location::line (void) const noexcept
    {
      return line_;
    }

#endif // !defined(__cpp_lib_source_location)

    /**
     * @details
     * This function template parses the compiler-specific
     * `__PRETTY_FUNCTION__` macro to extract a concise type name for the
     * template parameter \c T.
     *
     * Rather than relying on fixed character offsets (which are fragile across
     * compiler versions and namespace changes), the implementation searches
     * for the marker that introduces the template argument in the function
     * signature string:
     *
     * - Clang formats the signature as `"... [T = <typename>]"`, so the type
     *   name lies between the first `"[T = "` and the last `']'`. The
     *   marker is searched for as a whole, since the type name may itself
     *   contain brackets (e.g. `int[3]`).
     * - GCC formats the signature as `"... [with T = <typename>]"` or, on
     *   some versions, `"... [with T = <typename>; ...]"`, so the type name
     *   starts after the first `"[with T = "` and ends at the following
     *   `';'` or, if there is none, at the last `']'`.
     *
     * If the marker is not found, or the compiler is not supported (e.g.
     * MSVC, which uses `__FUNCSIG__` instead of `__PRETTY_FUNCTION__`), the
     * function returns `"unknown"` rather than failing to compile, since
     * the name is used only to improve the test output.
     *
     * The expected layouts are verified at compile time by the
     * `static_assert` checks that follow the definition.
     */
    template <class T>
    constexpr auto
    type_name (void) -> std::string_view
    {
#if defined(__clang__)
      // Clang: "... [T = <typename>]"
      const std::string_view sv = __PRETTY_FUNCTION__;
      constexpr std::string_view marker{ "[T = " };
      const auto pos = sv.find (marker);
      const auto end = sv.rfind (']');
#elif defined(__GNUC__)
      // GCC: "... [with T = <typename>]" or, on some versions,
      //      "... [with T = <typename>; std::string_view = ...]"
      const std::string_view sv = __PRETTY_FUNCTION__;
      constexpr std::string_view marker{ "[with T = " };
      const auto pos = sv.find (marker);
      const auto semi = sv.find (';', pos);
      const auto end
          = (semi != std::string_view::npos) ? semi : sv.rfind (']');
#else
      // Unsupported compiler; no portable signature string is available.
      const std::string_view sv{};
      constexpr std::string_view marker{};
      const auto pos = std::string_view::npos;
      const auto end = std::string_view::npos;
#endif // defined(__clang__) || defined(__GNUC__)
      if (pos == std::string_view::npos || end == std::string_view::npos
          || end < pos + marker.size ())
        {
          return "unknown";
        }
      const auto start = pos + marker.size ();
      return sv.substr (start, end - start);
    }

#if defined(__GNUC__)
    // Compile-time self-test of the signature layout parsed above; a
    // failure means that the compiler changed its __PRETTY_FUNCTION__
    // format and `type_name()` must be updated.
    static_assert (type_name<int> () == "int");
    static_assert (type_name<unsigned int> () == "unsigned int");
    static_assert (type_name<int[3]> () == "int [3]"
                   || type_name<int[3]> () == "int[3]");
#endif // defined(__GNUC__)

    // ------------------------------------------------------------------------
  } // namespace reflection

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__)

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_REFLECTION_INLINES_H_

// ----------------------------------------------------------------------------

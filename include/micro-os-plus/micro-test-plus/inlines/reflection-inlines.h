/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/mit.
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
 * constexpr-compatible alternative to `std::source_location`, enabling
 * enhanced diagnostics and reporting even in environments lacking C++20
 * support. The `type_name` utility leverages compiler intrinsics to obtain
 * human-readable type names for improved test output and debugging.
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

#ifndef MICRO_TEST_PLUS_REFLECTION_INLINES_H_
#define MICRO_TEST_PLUS_REFLECTION_INLINES_H_

// ----------------------------------------------------------------------------

#ifdef __cplusplus

// ----------------------------------------------------------------------------

#include <cstdint>

// #include "type-traits.h"

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#endif
#endif

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
    [[nodiscard]] constexpr source_location
    source_location::current (const char* file, unsigned int line) noexcept
    {
      source_location sl{};
      sl.file_ = file;
      sl.line_ = line;
      return sl;
    }

    /**
     * @details
     * ... TBD
     */
    [[nodiscard]] constexpr auto
    source_location::file_name (void) const noexcept
    {
      return file_;
    }

    /**
     * @details
     * ... TBD
     */
    [[nodiscard]] constexpr auto
    source_location::line (void) const noexcept
    {
      return line_;
    }

#endif

    /**
     * @details
     * This function template parses the compiler-specific
     * `__PRETTY_FUNCTION__` macro to extract a concise type name for the
     * template parameter \c T.
     *
     * The implementation is compiler-dependent and may require adjustment for
     * different toolchains. It is primarily intended for internal use within
     * the µTest++ framework to support improved diagnostics and reporting.
     */
    template <class T>
    [[nodiscard]] constexpr auto
    type_name (void) -> std::string_view
    {
#if defined(__clang__)
#pragma GCC diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
      // printf("|%s|%zu|\n", __PRETTY_FUNCTION__, sizeof
      // (__PRETTY_FUNCTION__)); printf("|%s|\n", &__PRETTY_FUNCTION__[78]);
      return { &__PRETTY_FUNCTION__[78], sizeof (__PRETTY_FUNCTION__) - 80 };
#pragma GCC diagnostic pop
#elif defined(__GNUC__)
      // printf("|%s|%zu|\n", __PRETTY_FUNCTION__, sizeof
      // (__PRETTY_FUNCTION__)); printf("|%s|\n", &__PRETTY_FUNCTION__[93]);
      return { &__PRETTY_FUNCTION__[93], sizeof (__PRETTY_FUNCTION__) - 144 };
#else
#error "Unsupported compiler"
      return "Unsupported compiler";
#endif
    }

    // ------------------------------------------------------------------------
  } // namespace reflection

  // --------------------------------------------------------------------------
} // namespace micro_os_plus::micro_test_plus

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

// ----------------------------------------------------------------------------

#endif // __cplusplus

// ----------------------------------------------------------------------------

#endif // MICRO_TEST_PLUS_REFLECTION_INLINES_H_

// ----------------------------------------------------------------------------

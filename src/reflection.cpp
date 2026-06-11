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
 * This source file contains the implementation of
 * `reflection::short_name()`, which extracts the base file name from a
 * fully qualified path by returning the portion after the last `/`
 * separator, or the original string if no separator is present.
 *
 * All definitions reside within the
 * `micro_os_plus::micro_test_plus::reflection` namespace.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#if __has_include(<micro-os-plus/project-config.h>)
#include <micro-os-plus/project-config.h>
#elif __has_include(<micro-os-plus/config.h>)
#pragma message \
    "micro-os-plus/config.h is deprecated, rename to micro-os-plus/project-config.h and include it instead of micro-os-plus/config.h"
#include <micro-os-plus/config.h>
#endif // __has_include(<micro-os-plus/project-config.h>)

#if __has_include(<micro-os-plus/micro-test-plus-defines.h>)
#include <micro-os-plus/micro-test-plus-defines.h>
#endif // __has_include(<micro-os-plus/micro-test-plus-defines.h>)

#include "micro-os-plus/micro-test-plus/reflection.h"

#include <cstring>

// ----------------------------------------------------------------------------

#if defined(__GNUC__)
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif
#endif

// ============================================================================

namespace micro_os_plus::micro_test_plus
{
  // --------------------------------------------------------------------------
  // Public API.

  // --------------------------------------------------------------------------
  // Too small to deserve a separate source file.
  namespace reflection
  {

    /**
     * @details
     * This function extracts the short name from a given file path by locating
     * the final folder separator ('/'). If a separator is found, it returns a
     * pointer to the character immediately following it, effectively providing
     * the file or folder name. If no separator is present, the original input
     * string is returned. This utility is useful for reporting concise file or
     * folder names in test output.
     */
    const char*
    short_name (const char* name) noexcept
    {
#if defined(__GNUC__)
#pragma GCC diagnostic push
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#endif
#endif
      const char* p = strrchr (name, '/');
      if (p != nullptr)
        return p + 1;
      else
        return name;
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
    }

  } // namespace reflection

  // ==========================================================================
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

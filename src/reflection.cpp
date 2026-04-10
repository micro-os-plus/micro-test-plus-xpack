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
 * This source file contains the core implementations for the µTest++ testing
 * framework, including initialisation and shutdown routines, utility
 * functions, and the management of global framework state. It provides the
 * logic for setting up the test environment, registering and executing test
 * suites, reporting results, and supporting utility operations such as file
 * name extraction and pattern-based string matching.
 *
 * All definitions are contained within the `micro_os_plus::micro_test_plus`
 * namespace and its nested namespaces, ensuring clear separation from user
 * code and minimising the risk of naming conflicts.
 *
 * The implementation is optimised for embedded environments, avoiding heavy
 * dependencies and providing lightweight, efficient mechanisms for test
 * execution and reporting.
 *
 * This file must be included when building the µTest++ library.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <micro-os-plus/micro-test-plus.h>

// #include <cstring>
// <iostream> is too heavy for embedded, use printf().
// #include <stdio.h>
// #include <unistd.h>

// ----------------------------------------------------------------------------

// #pragma GCC diagnostic ignored "-Waggregate-return"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
// #pragma clang diagnostic ignored "-Wexit-time-destructors"
// #pragma clang diagnostic ignored "-Wglobal-constructors"
// #pragma clang diagnostic ignored "-Wunknown-warning-option"
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

  // ==========================================================================
} // namespace micro_os_plus::micro_test_plus

// ----------------------------------------------------------------------------

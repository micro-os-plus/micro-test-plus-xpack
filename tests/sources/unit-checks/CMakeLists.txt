# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# sources/unit-checks/xcdl-test.jsonc
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# This file is intended to be used by applications via:
#
# `add_subdirectory("sources/unit-checks")`
#
# This creates an interface library that can be linked to a target with:
#
# `target_link_libraries(your-target PUBLIC tests-unit-checks)`

# -----------------------------------------------------------------------------

# The source code for a unit test to exercise the framework checks.
message (VERBOSE "Processing 'tests/sources/unit-checks/'...")

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (tests-unit-checks-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (tests-unit-checks-interface INTERFACE "include")

target_sources (
  tests-unit-checks-interface
  INTERFACE "src/main.cpp"
            "src/comparisons.cpp"
            "src/float-failed-combinations.cpp"
            "src/float-passed-combinations.cpp"
            "src/integral-failed-combinations.cpp"
            "src/integral-passed-combinations.cpp"
            "src/miscellaneous.cpp"
            "src/operators.cpp"
            "src/stopwatch.cpp"
            "src/support.cpp"
            "src/utility.cpp"
)

target_link_libraries (
  tests-unit-checks-interface
  INTERFACE "micro-os-plus::micro-test-plus-static-library"
)

xpack_display_target_lists (tests-unit-checks-interface)

# -----------------------------------------------------------------------------
# Alias.

# Export an alias target using namespaced syntax (Project::Target). This is the
# canonical pattern for consumption via target_link_libraries(), whether the
# dependency is added via add_subdirectory(), FetchContent, or an installed
# package via find_package(). Using "::" lets CMake detect an invalid or
# misspelled target name at configure time, rather than silently passing it
# through to the linker as a plain string or flag. Note: alias targets are
# read-only; properties must be set on the underlying target, not on the alias
# itself.
# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (tests::unit-checks ALIAS tests-unit-checks-interface)
message (VERBOSE "> tests::unit-checks -> tests-unit-checks-interface")

# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# sources/unit-miscellaneous/xcdl-test.jsonc
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
# `add_subdirectory("sources/unit-miscellaneous")`
#
# This creates interface libraries that can be linked to a target with:
#
# ~~~
# target_link_libraries(your-target PUBLIC test::unit-miscellaneous-body)
# target_link_libraries(your-target PUBLIC test::unit-miscellaneous)
# ~~~

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/sources/unit-miscellaneous/'...")

# -----------------------------------------------------------------------------

# The test code of the miscellaneous unit test, without main().

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (test-unit-miscellaneous-body-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (
  test-unit-miscellaneous-body-interface INTERFACE "include"
)

target_sources (
  test-unit-miscellaneous-body-interface
  INTERFACE "src/miscellaneous.cpp" "src/runner-options.cpp"
            "src/stopwatch.cpp" "src/utility.cpp" "src/allocations.cpp"
)

target_link_libraries (
  test-unit-miscellaneous-body-interface
  INTERFACE "micro-os-plus::micro-test-plus-static-library" "test::unit-common"
)

xpack_display_target_lists (test-unit-miscellaneous-body-interface)

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
add_library (
  test::unit-miscellaneous-body ALIAS test-unit-miscellaneous-body-interface
)
message (
  VERBOSE
  "> test::unit-miscellaneous-body -> test-unit-miscellaneous-body-interface"
)

# -----------------------------------------------------------------------------

# The source code for a unit test to exercise the miscellaneous features of the
# test framework.

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (test-unit-miscellaneous-interface INTERFACE EXCLUDE_FROM_ALL)

target_sources (test-unit-miscellaneous-interface INTERFACE "src/main.cpp")

target_link_libraries (
  test-unit-miscellaneous-interface INTERFACE "test::unit-miscellaneous-body"
)

xpack_display_target_lists (test-unit-miscellaneous-interface)

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
add_library (test::unit-miscellaneous ALIAS test-unit-miscellaneous-interface)
message (VERBOSE
         "> test::unit-miscellaneous -> test-unit-miscellaneous-interface"
)

# -----------------------------------------------------------------------------

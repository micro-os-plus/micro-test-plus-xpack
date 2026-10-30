# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# sources/unit-exceptions/xcdl-test.jsonc
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
# `add_subdirectory("sources/unit-exceptions")`
#
# This creates interface libraries that can be linked to a target with:
#
# ~~~
# target_link_libraries(your-target PUBLIC test::unit-exceptions-body)
# target_link_libraries(your-target PUBLIC test::unit-exceptions)
# ~~~

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/sources/unit-exceptions/'...")

# -----------------------------------------------------------------------------

# The test code of the exceptions unit test, without main().

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (test-unit-exceptions-body-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (
  test-unit-exceptions-body-interface INTERFACE "include"
)

target_sources (
  test-unit-exceptions-body-interface INTERFACE "src/exceptions.cpp"
)

target_link_libraries (
  test-unit-exceptions-body-interface
  INTERFACE "micro-os-plus::micro-test-plus-static-library" "test::unit-common"
)

xpack_display_target_lists (test-unit-exceptions-body-interface)

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
  test::unit-exceptions-body ALIAS test-unit-exceptions-body-interface
)
message (VERBOSE
         "> test::unit-exceptions-body -> test-unit-exceptions-body-interface"
)

# -----------------------------------------------------------------------------

# The source code for a unit test to exercise the exceptions features of the
# test framework.

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (test-unit-exceptions-interface INTERFACE EXCLUDE_FROM_ALL)

target_sources (test-unit-exceptions-interface INTERFACE "src/main.cpp")

target_link_libraries (
  test-unit-exceptions-interface INTERFACE "test::unit-exceptions-body"
)

xpack_display_target_lists (test-unit-exceptions-interface)

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
add_library (test::unit-exceptions ALIAS test-unit-exceptions-interface)
message (VERBOSE "> test::unit-exceptions -> test-unit-exceptions-interface")

# -----------------------------------------------------------------------------

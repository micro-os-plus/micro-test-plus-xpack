# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# sources/empty/xcdl-test.jsonc
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
# `add_subdirectory("sources/empty")`
#
# This creates an interface library that can be linked to a target with:
#
# `target_link_libraries(your-target PUBLIC test-empty)`

# -----------------------------------------------------------------------------

# The source code for a test to exercise empty suites.
message (VERBOSE "Processing 'tests/sources/empty/'...")

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (test-empty-interface INTERFACE EXCLUDE_FROM_ALL)

target_sources (test-empty-interface INTERFACE "src/main.cpp")

target_link_libraries (
  test-empty-interface
  INTERFACE "micro-os-plus::micro-test-plus-static-library"
)

xpack_display_target_lists (test-empty-interface)

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
add_library (test::empty ALIAS test-empty-interface)
message (VERBOSE "> test::empty -> test-empty-interface")

# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# sources/benchmarks/footprint/doctest/xcdl-test.jsonc
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
# `add_subdirectory("sources/benchmarks/footprint/doctest")`
#
# This creates interface libraries that can be linked to a target with:
#
# ~~~
# target_link_libraries(your-target PUBLIC benchmark::footprint-doctest)
# ~~~

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/sources/benchmarks/footprint/doctest/'...")

# -----------------------------------------------------------------------------

# The footprint benchmark program of doctest.

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (benchmark-footprint-doctest-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (
  benchmark-footprint-doctest-interface
  INTERFACE "../../../../benchmarks-frameworks/doctest"
)

target_sources (benchmark-footprint-doctest-interface INTERFACE "src/main.cpp")

target_compile_definitions (
  benchmark-footprint-doctest-interface
  INTERFACE "_DARWIN_C_SOURCE" "DOCTEST_CONFIG_NO_MULTITHREADING"
            "DOCTEST_CONFIG_NO_POSIX_SIGNALS"
)

target_compile_options (benchmark-footprint-doctest-interface INTERFACE "-w")

xpack_display_target_lists (benchmark-footprint-doctest-interface)

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
  benchmark::footprint-doctest ALIAS benchmark-footprint-doctest-interface
)
message (
  VERBOSE
  "> benchmark::footprint-doctest -> benchmark-footprint-doctest-interface"
)

# -----------------------------------------------------------------------------

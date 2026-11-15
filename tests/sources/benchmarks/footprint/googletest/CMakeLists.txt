# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# sources/benchmarks/footprint/googletest/xcdl-test.jsonc
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
# `add_subdirectory("sources/benchmarks/footprint/googletest")`
#
# This creates interface libraries that can be linked to a target with:
#
# ~~~
# target_link_libraries(your-target PUBLIC benchmark::footprint-googletest)
# ~~~

# -----------------------------------------------------------------------------

message (VERBOSE
         "Processing 'tests/sources/benchmarks/footprint/googletest/'..."
)

# -----------------------------------------------------------------------------

# The footprint benchmark program of GoogleTest.

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (
  benchmark-footprint-googletest-interface INTERFACE EXCLUDE_FROM_ALL
)

target_include_directories (
  benchmark-footprint-googletest-interface
  INTERFACE "../../../../benchmarks-frameworks/googletest/googletest/include"
            "../../../../benchmarks-frameworks/googletest/googletest"
)

target_sources (
  benchmark-footprint-googletest-interface
  INTERFACE
    "src/main.cpp"
    "../../../../benchmarks-frameworks/googletest/googletest/src/gtest-all.cc"
)

target_compile_definitions (
  benchmark-footprint-googletest-interface INTERFACE "GTEST_HAS_PTHREAD=0"
)

target_compile_options (benchmark-footprint-googletest-interface INTERFACE "-w")

target_link_libraries (
  benchmark-footprint-googletest-interface
  INTERFACE "benchmark::footprint-common"
)

xpack_display_target_lists (benchmark-footprint-googletest-interface)

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
  benchmark::footprint-googletest ALIAS
  benchmark-footprint-googletest-interface
)
message (
  VERBOSE
  "> benchmark::footprint-googletest -> benchmark-footprint-googletest-interface"
)

# -----------------------------------------------------------------------------

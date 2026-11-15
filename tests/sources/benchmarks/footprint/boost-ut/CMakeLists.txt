# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# sources/benchmarks/footprint/boost-ut/xcdl-test.jsonc
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
# `add_subdirectory("sources/benchmarks/footprint/boost-ut")`
#
# This creates interface libraries that can be linked to a target with:
#
# ~~~
# target_link_libraries(your-target PUBLIC benchmark::footprint-boost-ut)
# ~~~

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/sources/benchmarks/footprint/boost-ut/'...")

# -----------------------------------------------------------------------------

# The footprint benchmark program of Boost UT.

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: INTERFACE passes properties up to targets that link
# against it.
add_library (benchmark-footprint-boost-ut-interface INTERFACE EXCLUDE_FROM_ALL)

target_include_directories (
  benchmark-footprint-boost-ut-interface
  INTERFACE "../../../../benchmarks-frameworks/boost-ut/include"
)

target_sources (benchmark-footprint-boost-ut-interface INTERFACE "src/main.cpp")

target_compile_options (benchmark-footprint-boost-ut-interface INTERFACE "-w")

xpack_display_target_lists (benchmark-footprint-boost-ut-interface)

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
  benchmark::footprint-boost-ut ALIAS benchmark-footprint-boost-ut-interface
)
message (
  VERBOSE
  "> benchmark::footprint-boost-ut -> benchmark-footprint-boost-ut-interface"
)

# -----------------------------------------------------------------------------

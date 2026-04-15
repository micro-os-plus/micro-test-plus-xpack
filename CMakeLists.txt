# -----------------------------------------------------------------------------
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

# This file is intended to be consumed by applications with:
#
# `add_subdirectory("xpacks/@micro-os-plus/micro-test-plus")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC micro-os-plus::micro-test-plus)`

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required (VERSION 3.20)

project (micro-os-plus-micro-test-plus DESCRIPTION "µTest++")

# To access the optional functions, include the
# `cmake/micro-os-plus-build-helper.cmake` file from the
# `@micro-os-plus/build-helper` package.

if (COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version (
    "${CMAKE_CURRENT_SOURCE_DIR}/package.json"
  )
  message (VERBOSE
           "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}..."
  )
endif ()

# -----------------------------------------------------------------------------

# The project library definitions.

# The include directories shared between the INTERFACE and OBJECT library
# targets.
set (micro-os-plus-micro-test-plus-includes "include")
# The source files shared between the INTERFACE and OBJECT library targets.
set (
  micro-os-plus-micro-test-plus-sources
  "src/runner.cpp"
  "src/runner-totals.cpp"
  "src/deferred-reporter.cpp"
  "src/reporter.cpp"
  "src/reporter-human.cpp"
  "src/reporter-tap.cpp"
  "src/test.cpp"
  "src/timings.cpp"
  "src/reflection.cpp"
  "src/utility.cpp"
)

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#normal-libraries
# PRIVATE: build definitions, used internally INTERFACE: usage definitions,
# passed up to targets linking to it PUBLIC: both
add_library (micro-os-plus-micro-test-plus-interface INTERFACE)

target_include_directories (
  micro-os-plus-micro-test-plus-interface
  INTERFACE ${micro-os-plus-micro-test-plus-includes}
)

target_sources (
  micro-os-plus-micro-test-plus-interface
  INTERFACE ${micro-os-plus-micro-test-plus-sources}
)

target_compile_definitions (
  micro-os-plus-micro-test-plus-interface INTERFACE # None.
)

target_compile_options (
  micro-os-plus-micro-test-plus-interface INTERFACE # None.
)

target_link_libraries (
  micro-os-plus-micro-test-plus-interface INTERFACE micro-os-plus::diag-trace
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-micro-test-plus-interface)
endif ()

# -----------------------------------------------------------------------------

# Optional OBJECT library: sources are compiled once rather than per consumer.
# Inherits include directories, compile definitions, and compiler options from
# the interface library via PRIVATE linkage, which avoids propagating the
# interface library's INTERFACE sources to consumers of the object library. The
# include directories are re-exported explicitly so that consumers can find the
# headers.
add_library (
  micro-os-plus-micro-test-plus-objects OBJECT
  ${micro-os-plus-micro-test-plus-sources}
)

target_link_libraries (
  micro-os-plus-micro-test-plus-objects
  PRIVATE micro-os-plus-micro-test-plus-interface
)

target_include_directories (
  micro-os-plus-micro-test-plus-objects
  INTERFACE ${micro-os-plus-micro-test-plus-includes}
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-micro-test-plus-objects)
endif ()

# -----------------------------------------------------------------------------

# Aliases.
# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::micro-test-plus ALIAS micro-os-plus-micro-test-plus-interface
)
message (
  VERBOSE
  "> micro-os-plus::micro-test-plus -> micro-os-plus-micro-test-plus-interface"
)

add_library (
  micro-os-plus::micro-test-plus-objects ALIAS
  micro-os-plus-micro-test-plus-objects
)
message (
  VERBOSE
  "> micro-os-plus::micro-test-plus-objects -> micro-os-plus-micro-test-plus-objects"
)

# -----------------------------------------------------------------------------

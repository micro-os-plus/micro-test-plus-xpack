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

project (
  micro-os-plus-micro-test-plus
  DESCRIPTION "µTest++"
  LANGUAGES CXX
)

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

# The interface library is the main target of this package, which consumers
# (like embedded applications) link against. It defines the public API and
# properties of the library, and compiles the sources that are part of the
# public API.

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#normal-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (micro-os-plus-micro-test-plus-interface INTERFACE)

target_include_directories (
  micro-os-plus-micro-test-plus-interface INTERFACE "include"
)

target_sources (
  micro-os-plus-micro-test-plus-interface
  INTERFACE "src/runner.cpp"
            "src/runner-totals.cpp"
            "src/deferred-reporter.cpp"
            "src/expression-formatter.cpp"
            "src/reporter.cpp"
            "src/reporter-human.cpp"
            "src/reporter-tap.cpp"
            "src/test.cpp"
            "src/timings.cpp"
            "src/reflection.cpp"
            "src/utility.cpp"
)

target_compile_definitions (micro-os-plus-micro-test-plus-interface INTERFACE)

target_compile_options (micro-os-plus-micro-test-plus-interface INTERFACE)

target_link_libraries (
  micro-os-plus-micro-test-plus-interface INTERFACE micro-os-plus::diag-trace
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-micro-test-plus-interface)
endif ()

# -----------------------------------------------------------------------------

# Optional OBJECT library: compiles the library sources once and shares the
# resulting object files across all test executables, rather than recompiling
# them per consumer.
#
# Include directories are managed explicitly instead of using PRIVATE linkage to
# the interface library. PRIVATE linkage would cause diag-trace's
# INTERFACE_SOURCES (trace.cpp) to be compiled into this OBJECT library via
# transitive propagation, which conflicts with the separate diag-trace
# compilation in each test executable. Consumers of this OBJECT library are
# expected to link separately to micro-os-plus::diag-trace and to the
# platform-specific trace backend.
add_library (micro-os-plus-micro-test-plus-objects OBJECT)

get_property (
  micro-os-plus-micro-test-plus-includes
  TARGET micro-os-plus-micro-test-plus-interface
  PROPERTY INTERFACE_INCLUDE_DIRECTORIES
)
# Use PUBLIC so that the include directories are available both for the OBJECT
# library's own sources and for consumers of the library.
target_include_directories (
  micro-os-plus-micro-test-plus-objects
  PUBLIC ${micro-os-plus-micro-test-plus-includes}
)

get_property (
  micro-os-plus-micro-test-plus-sources
  TARGET micro-os-plus-micro-test-plus-interface
  PROPERTY INTERFACE_SOURCES
)
# Use PRIVATE to avoid propagating the sources to consumers of the OBJECT
# library, which would cause duplicate symbol errors at link time.
target_sources (
  micro-os-plus-micro-test-plus-objects
  PRIVATE ${micro-os-plus-micro-test-plus-sources}
)

get_property (
  micro-os-plus-micro-test-plus-compile-definitions
  TARGET micro-os-plus-micro-test-plus-interface
  PROPERTY INTERFACE_COMPILE_DEFINITIONS
)
# Use PRIVATE to avoid propagating compile definitions to consumers of the
# OBJECT library.
target_compile_definitions (
  micro-os-plus-micro-test-plus-objects
  PRIVATE ${micro-os-plus-micro-test-plus-compile-definitions}
)

get_property (
  micro-os-plus-micro-test-plus-compile-options
  TARGET micro-os-plus-micro-test-plus-interface
  PROPERTY INTERFACE_COMPILE_OPTIONS
)
# Use PRIVATE to avoid propagating the compile options to consumers of the
# OBJECT library, which may cause conflicts with consumer-specific compile
# options.
target_compile_options (
  micro-os-plus-micro-test-plus-objects
  PRIVATE ${micro-os-plus-micro-test-plus-compile-options}
)

# Add the diag-trace include path in Debug without linking the diag-trace
# target: linking it would add trace.cpp as an INTERFACE_SOURCE and compile it
# into the OBJECT library, causing duplicate symbols at link time.
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  get_property (
    micro-os-plus-diag-trace-includes
    TARGET micro-os-plus::diag-trace
    PROPERTY INTERFACE_INCLUDE_DIRECTORIES
  )
  target_include_directories (
    micro-os-plus-micro-test-plus-objects
    PRIVATE ${micro-os-plus-diag-trace-includes}
  )
endif ()

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-micro-test-plus-objects)
endif ()

# -----------------------------------------------------------------------------

add_library (micro-os-plus-micro-test-plus-static STATIC)

target_link_libraries (
  micro-os-plus-micro-test-plus-static
  PUBLIC micro-os-plus-micro-test-plus-objects
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-micro-test-plus-static)
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

add_library (
  micro-os-plus::micro-test-plus-static ALIAS
  micro-os-plus-micro-test-plus-static
)
message (
  VERBOSE
  "> micro-os-plus::micro-test-plus-static -> micro-os-plus-micro-test-plus-static"
)

# -----------------------------------------------------------------------------

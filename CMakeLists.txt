# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from xcdl-library.json.
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

# µTest++, a lightweight testing framework for embedded platforms.
project (
  micro-os-plus-micro-test-plus
  DESCRIPTION "µTest++ Testing Framework"
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
# properties of the library; sources are propagated to and compiled by each
# consumer.

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#interface-libraries
# Visibility keywords: PRIVATE applies to the target itself; INTERFACE passes
# properties up to targets that link against it; PUBLIC does both.
add_library (micro-os-plus-micro-test-plus-interface INTERFACE)

target_include_directories (
  micro-os-plus-micro-test-plus-interface 
  INTERFACE "include"
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

target_compile_definitions (
  micro-os-plus-micro-test-plus-interface 
  INTERFACE
)

target_compile_options (
  micro-os-plus-micro-test-plus-interface 
  INTERFACE
)

target_link_libraries (
  micro-os-plus-micro-test-plus-interface 
  INTERFACE "micro-os-plus::diag-trace"
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-micro-test-plus-interface)
endif ()

# Alias.
# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::micro-test-plus ALIAS micro-os-plus-micro-test-plus-interface
)
message (
  VERBOSE
  "> micro-os-plus::micro-test-plus -> micro-os-plus-micro-test-plus-interface"
)

# -----------------------------------------------------------------------------

# Extract the properties of the interface library to reuse them in the OBJECT
# and STATIC libraries, which are compiled before the platform library and need
# to get the same compile options.
get_property (
  micro-os-plus-micro-test-plus-includes
  TARGET micro-os-plus-micro-test-plus-interface
  PROPERTY INTERFACE_INCLUDE_DIRECTORIES
)

get_property (
  micro-os-plus-micro-test-plus-sources
  TARGET micro-os-plus-micro-test-plus-interface
  PROPERTY INTERFACE_SOURCES
)

get_property (
  micro-os-plus-micro-test-plus-compile-definitions
  TARGET micro-os-plus-micro-test-plus-interface
  PROPERTY INTERFACE_COMPILE_DEFINITIONS
)

get_property (
  micro-os-plus-micro-test-plus-compile-options
  TARGET micro-os-plus-micro-test-plus-interface
  PROPERTY INTERFACE_COMPILE_OPTIONS
)

get_property (
  micro-os-plus-diag-trace-includes
  TARGET micro-os-plus::diag-trace
  PROPERTY INTERFACE_INCLUDE_DIRECTORIES
)

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#object-libraries
# Optional OBJECT library: compiles the library sources once and shares the
# resulting object files across all test executables, rather than recompiling
# them per consumer.
#
# Include directories are managed explicitly instead of using PRIVATE linkage
# to the interface library. PRIVATE linkage would cause dependency sources to
# be compiled into this OBJECT library via transitive propagation, which
# conflicts with the separate dependency compilation in each executable.
# Consumers of this OBJECT library are expected to link separately to all
# dependencies and to the platform-specific library.
add_library (micro-os-plus-micro-test-plus-objects OBJECT)

# Use PUBLIC so that the include directories are available both for the OBJECT
# library's own sources and for consumers of the library.
target_include_directories (
  micro-os-plus-micro-test-plus-objects
  PUBLIC ${micro-os-plus-micro-test-plus-includes}
)

# Use PRIVATE to avoid propagating the sources to consumers of the OBJECT
# library, which would cause duplicate symbol errors at link time.
target_sources (
  micro-os-plus-micro-test-plus-objects
  PRIVATE ${micro-os-plus-micro-test-plus-sources}
)

# Use PRIVATE to avoid propagating compile definitions to consumers of the
# OBJECT library.
target_compile_definitions (
  micro-os-plus-micro-test-plus-objects
  PRIVATE ${micro-os-plus-micro-test-plus-compile-definitions}
)

# Use PRIVATE to avoid propagating the compile options to consumers of the
# OBJECT library, which may cause conflicts with consumer-specific compile
# options.
target_compile_options (
  micro-os-plus-micro-test-plus-objects
  PRIVATE ${micro-os-plus-micro-test-plus-compile-options}
)

# Add the dependency include paths without linking the code; linking it would
# add dependency sources as INTERFACE_SOURCES and compile them into the OBJECT
# library, causing duplicate symbols at link time.

target_include_directories (
  micro-os-plus-micro-test-plus-objects
  PRIVATE ${micro-os-plus-diag-trace-includes}
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-micro-test-plus-objects)
endif ()

# Alias.
# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::micro-test-plus-objects ALIAS
  micro-os-plus-micro-test-plus-objects
)
message (
  VERBOSE
  "> micro-os-plus::micro-test-plus-objects -> micro-os-plus-micro-test-plus-objects"
)

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#normal-libraries
# Optional STATIC library: compiles the library sources into an archive that
# is linked into each consumer executable, rather than sharing object files.
#
# Include directories are managed explicitly instead of using PRIVATE linkage
# to the interface library. PRIVATE linkage would cause dependency sources to
# be compiled into this STATIC library via transitive propagation, which
# conflicts with the separate dependency compilation in each executable.
# Consumers of this STATIC library are expected to link separately to all
# dependencies and to the platform-specific library.
add_library (micro-os-plus-micro-test-plus-static STATIC)

# Use PUBLIC so that the include directories are available both for the STATIC
# library's own sources and for consumers of the library.
target_include_directories (
  micro-os-plus-micro-test-plus-static
  PUBLIC ${micro-os-plus-micro-test-plus-includes}
)

# Use PRIVATE to avoid propagating the sources to consumers of the STATIC
# library, which would cause duplicate symbol errors at link time.
target_sources (
  micro-os-plus-micro-test-plus-static
  PRIVATE ${micro-os-plus-micro-test-plus-sources}
)

# Use PRIVATE to avoid propagating compile definitions to consumers of the
# STATIC library.
target_compile_definitions (
  micro-os-plus-micro-test-plus-static
  PRIVATE ${micro-os-plus-micro-test-plus-compile-definitions}
)

# Use PRIVATE to avoid propagating the compile options to consumers of the
# STATIC library, which may cause conflicts with consumer-specific compile
# options.
target_compile_options (
  micro-os-plus-micro-test-plus-static
  PRIVATE ${micro-os-plus-micro-test-plus-compile-options}
)

# Add the dependency include paths without linking the dependency target:
# linking it would add dependency sources as INTERFACE_SOURCES and compile
# them into the STATIC library, causing duplicate symbols at link time.

target_include_directories (
  micro-os-plus-micro-test-plus-static
  PRIVATE ${micro-os-plus-diag-trace-includes}
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists (micro-os-plus-micro-test-plus-static)
endif ()

# Alias.
# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library (
  micro-os-plus::micro-test-plus-static ALIAS
  micro-os-plus-micro-test-plus-static
)
message (
  VERBOSE
  "> micro-os-plus::micro-test-plus-static -> micro-os-plus-micro-test-plus-static"
)

# -----------------------------------------------------------------------------

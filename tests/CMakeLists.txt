#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
## Preamble ##

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required(VERSION 3.20)

project(
  micro-os-plus-micro-test-plus
  DESCRIPTION "µTest++"
)

# Must be called from the project root folder.
enable_testing()

# -----------------------------------------------------------------------------
## Project wide setup ##

enable_language(C)
enable_language(CXX)
enable_language(ASM)

# Specify the C/C++ standards.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate the compile_commands.json file to feed the indexer.
# Highly recommended, to help IDEs construct the index.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable this to see the dependency graph.
# set_property(GLOBAL PROPERTY GLOBAL_DEPENDS_DEBUG_MODE 1)

# -----------------------------------------------------------------------------

if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
  message(FATAL_ERROR "In-source builds are not supported. Please use separate folder for build.")
endif()


# The build-helper is a devDependency, available only after `xpm install`.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/top/xpacks/micro-os-plus-build-helper/cmake")
include("micro-os-plus-build-helper")

xpack_display_greetings()

# -----------------------------------------------------------------------------

# Common to all platforms.
add_compile_definitions(
  # NDEBUG provided by the toolchain definitions on release.

  # DO NOT use CMAKE_BUILD_TYPE
  $<$<CONFIG:Debug>:DEBUG>
  $<$<CONFIG:Debug>:TRACE>
)

# -----------------------------------------------------------------------------

# Bare-metal executables have the .elf extension.
if(CMAKE_SYSTEM_NAME STREQUAL "Generic")
  set(CMAKE_EXECUTABLE_SUFFIX ".elf")
endif()

# -----------------------------------------------------------------------------

# The globals must be included in this scope, before any targets.
include("platform-${PLATFORM_NAME}/cmake/globals.cmake")

# Build configuration dependencies.
xpack_glob_add_subdirectories("${CMAKE_BINARY_DIR}/xpacks" "xpacks-bin")

# Project dependencies.
xpack_glob_add_subdirectories("top/xpacks" "top-xpacks-bin")

# The main library from the root folder.
add_subdirectory("top")

# The platform specific configuration.
add_subdirectory("platform-${PLATFORM_NAME}" "platform")

# -----------------------------------------------------------------------------

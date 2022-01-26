#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
  message(FATAL_ERROR "In-source builds are not supported. Please use separate folder for build.")
endif()

# -----------------------------------------------------------------------------
## Project wide setup ##

# Generate the compile_commands.json file to feed the indexer.
# Highly recommended, to help IDEs construct the index.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable this to see the dependency graph.
# set_property(GLOBAL PROPERTY GLOBAL_DEPENDS_DEBUG_MODE 1)

if (WIN32)
  set(CMAKE_OBJECT_PATH_MAX 260)
endif ()

# -----------------------------------------------------------------------------

# The build-helper is a devDependency, available only after `xpm install`.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/xpacks/micro-os-plus-build-helper/cmake")
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
xpack_glob_add_subdirectories("${CMAKE_BINARY_DIR}/xpacks" "xpacks")

# Project dependencies.
xpack_glob_add_subdirectories("${CMAKE_SOURCE_DIR}/xpacks" "xpacks")

# The main library from the root folder.
add_subdirectory("${CMAKE_SOURCE_DIR}/sources" "sources")

# The platform specific configuration.
add_subdirectory("platform-${PLATFORM_NAME}")

# -----------------------------------------------------------------------------

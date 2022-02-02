#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `add_subdirectory("xpacks/micro-os-plus-micro-test-plus")`
#
# The result is a library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC micro-os-plus::micro-test-plus)`

# -----------------------------------------------------------------------------
## Preamble ##

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required(VERSION 3.20)

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------
## The project library definitions ##

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#normal-libraries
# PRIVATE: build definitions, used internally
# INTERFACE: usage definitions, passed up to targets linking to it
# PUBLIC: both

# The STATIC library is built once and linked to multiple tests.
# Using INTERFACE would compile the source code separately for each test.
add_library(micro-os-plus-micro-test-plus-static STATIC)

# -----------------------------------------------------------------------------
# Target settings.

target_sources(
  micro-os-plus-micro-test-plus-static

  PRIVATE
    "src/micro-test-plus.cpp"
)

message(VERBOSE "+ src/micro-test-plus.cpp")

target_include_directories(
  micro-os-plus-micro-test-plus-static

  PUBLIC
    "include"
)

message(VERBOSE "+ include")

target_compile_definitions(
  micro-os-plus-micro-test-plus-static

  PRIVATE
    # ...

  PUBLIC
    # ...
)

target_compile_options(
  micro-os-plus-micro-test-plus-static

  PRIVATE
    # ...
)

target_link_options(
  micro-os-plus-micro-test-plus-static

  PRIVATE
    # ...
)

target_link_libraries(
  micro-os-plus-micro-test-plus-static

  PUBLIC
    # ...
)

# -----------------------------------------------------------------------------
# Aliases.

add_library(micro-os-plus::micro-test-plus ALIAS micro-os-plus-micro-test-plus-static)
message(VERBOSE "> micro-os-plus::micro-test-plus -> micro-os-plus-micro-test-plus-static")

# -----------------------------------------------------------------------------


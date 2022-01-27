#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/

# PRIVATE: build definitions, used internally
# INTERFACE: usage definitions, passed up to targets linking to it
# PUBLIC: both

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/../package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------

# The STATIC library is built once and linked to multiple tests.
# Using INTERFACE would compile the source code separately for each test.
add_library(micro-os-plus-micro-test-plus-static STATIC)

# -----------------------------------------------------------------------------

target_sources(
  micro-os-plus-micro-test-plus-static

  PRIVATE
    "src/micro-test-plus.cpp"
)

message(VERBOSE "+ sources/src/micro-test-plus.cpp")

target_include_directories(
  micro-os-plus-micro-test-plus-static

  PUBLIC
    "include"
)

message(VERBOSE "+ sources/include")

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

  PUBLIC
    # ...
)

target_link_libraries(
  micro-os-plus-micro-test-plus-static

  PRIVATE
    # ...

  PUBLIC
    # ...
)

# -----------------------------------------------------------------------------
# Aliases.

add_library(micro-os-plus::micro-test-plus ALIAS micro-os-plus-micro-test-plus-static)
message(VERBOSE "micro-os-plus::micro-test-plus -> micro-os-plus-micro-test-plus-static")

# -----------------------------------------------------------------------------


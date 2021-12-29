#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# This Source Code Form is subject to the terms of the MIT License.
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `find_package(micro-os-plus-micro-test-plus REQUIRED)`
#
# or, if CMake packages are not used, manually with:
#
# `add_subdirectory("xpacks/micro-os-plus-micro-test-plus")`
#
# The result is a static library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC micro-os-plus::micro-test-plus)`
#
# To avoid poluting this file with test related details, there is a separate
# CMake configuration in the `tests` folder.

# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.19/
cmake_minimum_required(VERSION 3.19)

project(
  micro-os-plus-micro-test-plus
  DESCRIPTION "µTest++"
)

if ("${CMAKE_CURRENT_LIST_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  # Building tests for the current project.
  enable_testing() # Must be called from the project root folder.
  add_subdirectory(tests)
else()
  # If not a standalone project, then a library included in a top project.
  # Reuse the package configuration.
  include("${CMAKE_CURRENT_LIST_DIR}/meta/micro-os-plus-micro-test-plus-config.cmake")
endif()

# -----------------------------------------------------------------------------

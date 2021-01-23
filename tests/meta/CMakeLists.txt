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

# https://cmake.org/cmake/help/v3.18/
cmake_minimum_required(VERSION 3.18)

project(
	xpack-test
	DESCRIPTION "A blinky using the µOS++ RTOS"
)

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

message(STATUS "Build configuration: ${BUILD_CONFIG}")
message(STATUS "Project path: ${PROJECT_SOURCE_DIR}")

get_filename_component(xpack_tests_root_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)
get_filename_component(xpack_root_folder ${xpack_tests_root_folder} DIRECTORY)

# Generate the compile_commands.json file to feed the indexer.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if(BUILD_CONFIG STREQUAL "unit-test-native-release-cmake")
  set(CMAKE_BUILD_TYPE Release)
  # ...
elseif(BUILD_CONFIG STREQUAL "sample-native-release-cmake")
  set(CMAKE_BUILD_TYPE Release)
  # ...
else()
  message(FATAL_ERROR, "Unsupported BUILD_CONFIG")
endif()

# -----------------------------------------------------------------------------

add_executable(unit-test-app)

set_target_properties(
  unit-test-app

  PROPERTIES
    OUTPUT_NAME "unit-test"
    CXX_EXTENSIONS OFF
)

# Application sources.
target_sources(
  unit-test-app

  PRIVATE
    ${xpack_tests_root_folder}/unit-test.cpp
    ${xpack_root_folder}/src/micro-test-plus.cpp
)

# Application includes.
target_include_directories(
  unit-test-app

  PRIVATE
    ${xpack_root_folder}/include
)

# -----------------------------------------------------------------------------

add_executable(sample-app)

set_target_properties(
  sample-app

  PROPERTIES
    OUTPUT_NAME "sample-test"
    CXX_EXTENSIONS OFF
)

# Application sources.
target_sources(
  sample-app

  PRIVATE
    ${xpack_tests_root_folder}/sample-test.cpp
    ${xpack_root_folder}/src/micro-test-plus.cpp
)

# Application includes.
target_include_directories(
  sample-app

  PRIVATE
    ${xpack_root_folder}/include
)

# -----------------------------------------------------------------------------

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "")

# -----------------------------------------------------------------------------

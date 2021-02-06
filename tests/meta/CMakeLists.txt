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
message(STATUS "CMake version: ${CMAKE_VERSION}")

# -----------------------------------------------------------------------------

get_filename_component(xpack_tests_root_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)
get_filename_component(xpack_root_folder ${xpack_tests_root_folder} DIRECTORY)

include("${xpack_root_folder}/xpacks/micro-os-plus-build-helper/cmake/xpack-helper.cmake")

# append_cmake_prefix_path("${xpack_tests_root_folder}")
append_cmake_prefix_path("${xpack_root_folder}")

# Leave the result in PACKAGE_JSON_VERSION[*]
parse_package_json_semver("${xpack_root_folder}/package.json")

# -----------------------------------------------------------------------------

project(
	xpack-test
	DESCRIPTION "µTest++ tests"
  VERSION "${PACKAGE_JSON_VERSION}"
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

message(STATUS "Platform name: ${PLATFORM_NAME}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Project path: ${xpack_root_folder}")
message(STATUS "Prefix path: ${CMAKE_PREFIX_PATH}")

# Generate the compile_commands.json file to feed the indexer.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(PLATFORM_NAME STREQUAL "native")
  # ...
elseif(PLATFORM_NAME STREQUAL "stm32f4discovery")
  # ...
else()
  message(FATAL_ERROR, "Unsupported PLATFORM_NAME")
endif()


# -----------------------------------------------------------------------------

# set(micro-os-plus-micro-test-plus_DIR "${xpack_root_folder}/meta")
# list(APPEND CMAKE_PREFIX_PATH "${xpack_root_folder}/meta")

find_package(micro-os-plus-micro-test-plus REQUIRED)

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

add_executable(sample-test-app)

set_target_properties(
  sample-test-app

  PROPERTIES
    OUTPUT_NAME "sample-test"
    CXX_EXTENSIONS OFF
)

# Application sources.
target_sources(
  sample-test-app

  PRIVATE
    ${xpack_tests_root_folder}/sample-test.cpp
    ${xpack_root_folder}/src/micro-test-plus.cpp
)

# Application includes.
target_include_directories(
  sample-test-app

  PRIVATE
    ${xpack_root_folder}/include
)

# -----------------------------------------------------------------------------

enable_testing()

add_test(
  NAME "unit-test"
  COMMAND "unit-test"
)

add_test(
  NAME "sample-test"
  COMMAND "sample-test"
)

# -----------------------------------------------------------------------------

# Display an empty line, to better see the configuration output.
message(STATUS "")

# -----------------------------------------------------------------------------

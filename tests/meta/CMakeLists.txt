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

if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
  message(FATAL_ERROR "In-source builds are not supported. Please use separate folder for build.")
endif()

# Generate the compile_commands.json file to feed the indexer.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -----------------------------------------------------------------------------

get_filename_component(xpack_tests_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)
get_filename_component(xpack_project_folder ${xpack_tests_folder} DIRECTORY)
set(xpack_current_folder ${xpack_tests_folder})

include("${xpack_project_folder}/xpacks/micro-os-plus-build-helper/cmake/xpack-helper.cmake")

append_cmake_prefix_path("${xpack_project_folder}")

# Leave the result in PACKAGE_JSON_VERSION[*]
parse_package_json_semver("${xpack_project_folder}/package.json")

# -----------------------------------------------------------------------------

project(
  tests
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
# CMAKE_BUILD_TYPE: Debug, Release, RelWithDebInfo, MinSizeRel
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Project path: ${xpack_project_folder}")
message(STATUS "Prefix path: ${CMAKE_PREFIX_PATH}")

# Generate the compile_commands.json file to feed the indexer.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -----------------------------------------------------------------------------


find_package(micro-os-plus-micro-test-plus REQUIRED)

# ---

add_library(micro-os-plus STATIC)

set(USE_STATIC_LIBS 1)

if(NOT USE_STATIC_LIBS)

target_link_libraries(
  micro-os-plus

  PUBLIC 
    micro-os-plus::micro-test-plus
)

else()

# No SOURCES given to target: micro-os-plus (weird!)
target_sources(micro-os-plus PRIVATE dummy.c)

target_link_libraries(
  micro-os-plus

  PUBLIC 
    micro-os-plus::micro-test-plus-static
)

endif()

# ---

if(PLATFORM_NAME STREQUAL "native")

  # bin is mandatory, but not used.
  add_subdirectory("${xpack_tests_folder}/platform-native/meta" bin)

elseif(PLATFORM_NAME STREQUAL "stm32f4discovery")

  # Brace libraries with --whole-archive and --start-group to avoid linker
  # missing the non-weak symbols, like the interrupt handlers.
  set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_CXX_COMPILER>  <FLAGS> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> -Wl,--start-group -Wl,--whole-archive <LINK_LIBRARIES> -Wl,--no-whole-archive -Wl,--end-group")

  add_subdirectory("${xpack_tests_folder}/platform-stm32f4discovery/meta" bin)
  
  # list(APPEND CMAKE_PREFIX_PATH "${xpack_tests_folder}/platform-stm32f4discovery/meta")
  # find_package(platform-stm32f4discovery REQUIRED)

  find_package(micro-os-plus-libs-c REQUIRED)
  find_package(micro-os-plus-libs-cpp REQUIRED)
  find_package(micro-os-plus-semihosting REQUIRED)
  find_package(micro-os-plus-startup REQUIRED)

if(NOT USE_STATIC_LIBS)

  # Collect all objects into a single library, and later link it
  # to all tests.
  target_link_libraries(
    micro-os-plus

    PUBLIC 
      micro-os-plus::platform # Should bring device & architecture too.

      micro-os-plus::libs-c
      micro-os-plus::libs-cpp
      micro-os-plus::semihosting
      micro-os-plus::startup
  )

else()

  target_link_libraries(
    micro-os-plus

    PUBLIC 
      micro-os-plus::platform-static # Should bring device & architecture too.

      micro-os-plus::libs-c-static
      micro-os-plus::libs-cpp-static
      micro-os-plus::semihosting-static
      micro-os-plus::startup-static
  )

endif()

else()
  message(FATAL_ERROR, "Unsupported PLATFORM_NAME")
endif()

# -----------------------------------------------------------------------------

add_executable(unit-test-app)

set_target_properties(
  unit-test-app

  PROPERTIES
    OUTPUT_NAME "unit-test"
    CXX_EXTENSIONS OFF
)

# Bare-metal executables have the .elf extension.
if(CMAKE_SYSTEM_NAME STREQUAL "Generic")
  set_target_properties(
    unit-test-app

    PROPERTIES
      SUFFIX ".elf"
  )
endif()

# Source folders.
target_sources(
  unit-test-app

  PRIVATE
    ${xpack_current_folder}/src/unit-test.cpp
)

# Include folders.
target_include_directories(
  unit-test-app

  PRIVATE
    ${xpack_current_folder}/include
)

target_compile_definitions(
  unit-test-app

  PRIVATE
    # ...
)

target_link_libraries(
  unit-test-app 
  
  PUBLIC 
    micro-os-plus
)

if(PLATFORM_NAME STREQUAL "stm32f4discovery")

  target_link_options(
    unit-test-app

    PRIVATE
      -Wl,-Map,unit-test.map
      # -Wl,--whole-archive $<TARGET_PROPERTY:LINK_INTERFACE_LIBRARIES> -Wl,--no-whole-archive
  )

  add_custom_command(
    TARGET unit-test-app POST_BUILD
    COMMAND arm-none-eabi-size --format=berkeley "unit-test.elf"
  )

endif()

# -----------------------------------------------------------------------------

add_executable(sample-test-app)

set_target_properties(
  sample-test-app

  PROPERTIES
    OUTPUT_NAME "sample-test"
    CXX_EXTENSIONS OFF
)

# Bare-metal executables have the .elf extension.
if(CMAKE_SYSTEM_NAME STREQUAL "Generic")
  set_target_properties(
    sample-test-app

    PROPERTIES
      SUFFIX ".elf"
  )
endif()

# Application sources.
target_sources(
  sample-test-app

  PRIVATE
    ${xpack_current_folder}/src/sample-test.cpp
)

# Include folders.
target_include_directories(
  sample-test-app

  PRIVATE
    ${xpack_current_folder}/include
)

target_compile_definitions(
  sample-test-app

  PRIVATE
    # ...
)

target_link_libraries(
  sample-test-app
  
  PUBLIC 
    micro-os-plus
)

if(PLATFORM_NAME STREQUAL "stm32f4discovery")

  target_link_options(
    sample-test-app

    PRIVATE
      -Wl,-Map,sample-test.map
  )

  add_custom_command(
    TARGET sample-test-app POST_BUILD
    COMMAND arm-none-eabi-size --format=berkeley "sample-test.elf"
  )

endif()

# -----------------------------------------------------------------------------

enable_testing()

if(PLATFORM_NAME STREQUAL "native")

  add_test(
    NAME "unit-test"
    COMMAND unit-test
  )

  add_test(
    NAME "sample-test"
    COMMAND sample-test 1 2 3
  )

elseif(PLATFORM_NAME STREQUAL "stm32f4discovery")

  add_test(
    NAME "unit-test"
    COMMAND qemu-system-gnuarmeclipse --verbose --board STM32F4-Discovery -d unimp,guest_errors --nographic --image unit-test.elf --semihosting-config enable=on,target=native --semihosting-cmdline unit-test
  )

  add_test(
    NAME "sample-test"
    COMMAND qemu-system-gnuarmeclipse --verbose --board STM32F4-Discovery -d unimp,guest_errors --nographic --image sample-test.elf --semihosting-config enable=on,target=native --semihosting-cmdline sample-test 1 2 3
  )

endif()

# -----------------------------------------------------------------------------

# Display an empty line, to better see the configuration output.
message(STATUS "")

# -----------------------------------------------------------------------------

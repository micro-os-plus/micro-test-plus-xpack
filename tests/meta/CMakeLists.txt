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
# CMAKE_BUILD_TYPE: Debug, Release, RelWithDebInfo, MinSizeRel
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Project path: ${xpack_project_folder}")
message(STATUS "Prefix path: ${CMAKE_PREFIX_PATH}")

# Generate the compile_commands.json file to feed the indexer.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(PLATFORM_NAME STREQUAL "native")
  # No platform specific definitions so far.
elseif(PLATFORM_NAME STREQUAL "stm32f4discovery")
  include("${xpack_current_folder}/platform-stm32f4discovery/meta/xpack-helper.cmake")
  include("${xpack_project_folder}/xpacks/micro-os-plus-platform-stm32f4discovery/meta/xpack-helper.cmake")
  include("${xpack_project_folder}/xpacks/micro-os-plus-devices-stm32f4/meta/xpack-helper.cmake")
  include("${xpack_project_folder}/xpacks/micro-os-plus-architecture-cortexm/meta/xpack-helper.cmake")

  include("${xpack_project_folder}/xpacks/micro-os-plus-diag-trace/meta/xpack-helper.cmake")
  include("${xpack_project_folder}/xpacks/micro-os-plus-libs-c/meta/xpack-helper.cmake")
  include("${xpack_project_folder}/xpacks/micro-os-plus-libs-cpp/meta/xpack-helper.cmake")
  include("${xpack_project_folder}/xpacks/micro-os-plus-semihosting/meta/xpack-helper.cmake")
  include("${xpack_project_folder}/xpacks/micro-os-plus-startup/meta/xpack-helper.cmake")
  include("${xpack_project_folder}/xpacks/micro-os-plus-version/meta/xpack-helper.cmake")
else()
  message(FATAL_ERROR, "Unsupported PLATFORM_NAME")
endif()


# -----------------------------------------------------------------------------

# Not yet used.
find_package(micro-os-plus-micro-test-plus REQUIRED)

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
    ${xpack_current_folder}/unit-test.cpp
    ${xpack_project_folder}/src/micro-test-plus.cpp
)

# Include folders.
target_include_directories(
  unit-test-app

  PRIVATE
    ${xpack_project_folder}/include
)

target_compile_definitions(
  unit-test-app

  PRIVATE
    # HAVE_MICRO_OS_PLUS_CONFIG_H

    # NDEBUG provided by the toolchain definitions on release.
    $<$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">:DEBUG>
    $<$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">:TRACE>
)

if(PLATFORM_NAME STREQUAL "stm32f4discovery")

  # Platform specific settings.
  target_sources_micro_os_plus_platform(unit-test-app)
  target_include_directories_micro_os_plus_platform(unit-test-app)
  target_compile_definitions_micro_os_plus_platform(unit-test-app)
  # Many interesting things come from the platfrom specific definitions.
  target_options_micro_os_plus_platform(unit-test-app)

  # Device specific settings.
  target_sources_micro_os_plus_device(unit-test-app)
  target_include_directories_micro_os_plus_device(unit-test-app)

  # Architecture specific settings.
  target_sources_micro_os_plus_architecture(unit-test-app)
  target_include_directories_micro_os_plus_architecture(unit-test-app)

  # Portable settings.
  target_sources_micro_os_plus_diag_trace(unit-test-app)
  target_include_directories_micro_os_plus_diag_trace(unit-test-app)

  target_sources_micro_os_plus_libs_c(unit-test-app)
  target_include_directories_micro_os_plus_libs_c(unit-test-app)

  target_sources_micro_os_plus_libs_cpp(unit-test-app)
  target_include_directories_micro_os_plus_libs_cpp(unit-test-app)

  target_sources_micro_os_plus_semihosting(unit-test-app)
  target_include_directories_micro_os_plus_semihosting(unit-test-app)

  target_sources_micro_os_plus_startup(unit-test-app)
  target_include_directories_micro_os_plus_startup(unit-test-app)

  # Header only, no sources.
  target_include_directories_micro_os_plus_version(unit-test-app)

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
    ${xpack_current_folder}/sample-test.cpp
    ${xpack_project_folder}/src/micro-test-plus.cpp
)

# Include folders.
target_include_directories(
  sample-test-app

  PRIVATE
    ${xpack_project_folder}/include
)

target_compile_definitions(
  sample-test-app

  PRIVATE
    # HAVE_MICRO_OS_PLUS_CONFIG_H

    # NDEBUG provided by the toolchain definitions on release.
    $<$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">:DEBUG>
    $<$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">:TRACE>
)

if(PLATFORM_NAME STREQUAL "stm32f4discovery")

  # Platform specific settings.
  target_sources_micro_os_plus_platform(sample-test-app)
  target_include_directories_micro_os_plus_platform(sample-test-app)
  target_compile_definitions_micro_os_plus_platform(sample-test-app)
  # Many interesting things come from the platfrom specific definitions.
  target_options_micro_os_plus_platform(sample-test-app)

  # Device specific settings.
  target_sources_micro_os_plus_device(sample-test-app)
  target_include_directories_micro_os_plus_device(sample-test-app)

  # Architecture specific settings.
  target_sources_micro_os_plus_architecture(sample-test-app)
  target_include_directories_micro_os_plus_architecture(sample-test-app)

  # Portable settings.
  target_sources_micro_os_plus_diag_trace(sample-test-app)
  target_include_directories_micro_os_plus_diag_trace(sample-test-app)

  target_sources_micro_os_plus_libs_c(sample-test-app)
  target_include_directories_micro_os_plus_libs_c(sample-test-app)

  target_sources_micro_os_plus_libs_cpp(sample-test-app)
  target_include_directories_micro_os_plus_libs_cpp(sample-test-app)

  target_sources_micro_os_plus_semihosting(sample-test-app)
  target_include_directories_micro_os_plus_semihosting(sample-test-app)

  target_sources_micro_os_plus_startup(sample-test-app)
  target_include_directories_micro_os_plus_startup(sample-test-app)

  # Header only, no sources.
  target_include_directories_micro_os_plus_version(sample-test-app)

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

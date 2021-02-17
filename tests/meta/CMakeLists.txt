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

# Common to all platforms.
add_compile_definitions(
  # NDEBUG provided by the toolchain definitions on release.
  $<$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">:DEBUG>
  $<$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">:TRACE>
)

# -----------------------------------------------------------------------------

# Bare-metal executables have the .elf extension.
if(CMAKE_SYSTEM_NAME STREQUAL "Generic")
  set(CMAKE_EXECUTABLE_SUFFIX ".elf")
endif()

# -----------------------------------------------------------------------------

if(PLATFORM_NAME STREQUAL "native")

  include("${xpack_tests_folder}/platform-native/meta/xpack-helper.cmake")

  # This must be the very first, before creating any library.
  add_common_options_platform_native()
  add_libraries_platform_native()

  # No SOURCES given to target: micro-os-plus (weird!)
  add_library(micro-os-plus STATIC dummy.c)

elseif(PLATFORM_NAME STREQUAL "stm32f4discovery")

  # Brace libraries with --whole-archive and --start-group to avoid linker
  # missing the non-weak symbols, like the interrupt handlers.
  set(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_CXX_COMPILER>  <FLAGS> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> -Wl,--start-group -Wl,--whole-archive <LINK_LIBRARIES> -Wl,--no-whole-archive -Wl,--end-group")

  include("${xpack_tests_folder}/platform-stm32f4discovery/meta/xpack-helper.cmake")

  # These must be the very first, before creating any library.
  include_directories_platform_stm32f4discovery()
  add_compile_definitions_platform_stm32f4discovery()
  add_common_options_platform_stm32f4discovery()
  
  add_libraries_platform_stm32f4discovery()

  find_package(micro-os-plus-libs-c REQUIRED)
  find_package(micro-os-plus-libs-cpp REQUIRED)
  find_package(micro-os-plus-semihosting REQUIRED)
  find_package(micro-os-plus-startup REQUIRED)

  # No SOURCES given to target: micro-os-plus (weird!)
  add_library(micro-os-plus STATIC dummy.c)

  target_link_libraries(
    micro-os-plus

    PUBLIC 
      micro-os-plus::platform-static # Should bring device & architecture too.

      micro-os-plus::libs-c-static
      micro-os-plus::libs-cpp-static
      micro-os-plus::semihosting-static
      micro-os-plus::startup-static
  )

else()
  message(FATAL_ERROR, "Unsupported PLATFORM_NAME")
endif()

# -----------------------------------------------------------------------------

find_package(micro-os-plus-micro-test-plus REQUIRED)

target_link_libraries(
  micro-os-plus

  PUBLIC 
    micro-os-plus::micro-test-plus-static
)

# -----------------------------------------------------------------------------

function(add_test_executable name)

  add_executable(${name})

  set_target_properties(
    ${name}

    PROPERTIES
      OUTPUT_NAME "${name}"
  )

  # Application sources.
  target_sources(
    ${name}

    PRIVATE
      ${xpack_current_folder}/src/${name}.cpp
  )

  # Include folders.
  target_include_directories(
    ${name}

    PRIVATE
      ${xpack_current_folder}/include
  )

  target_compile_definitions(
    ${name}

    PRIVATE
      # ...
  )

  target_link_libraries(
    ${name}
    
    PUBLIC 
      micro-os-plus
  )

  if(PLATFORM_NAME STREQUAL "stm32f4discovery")

    target_link_options(
      ${name}

      PRIVATE
        -Wl,-Map,${name}.map
    )

    add_custom_command(
      TARGET ${name} POST_BUILD
      COMMAND arm-none-eabi-size --format=berkeley "$<TARGET_FILE:${name}>"
    )

  endif()

endfunction()

# -----------------------------------------------------------------------------

add_test_executable(unit-test)

add_test_executable(sample-test)

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

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

if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
  message(FATAL_ERROR "In-source builds are not supported. Please use separate folder for build.")
endif()

# -----------------------------------------------------------------------------

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

message(STATUS "Compiler: ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION}")

# Generate the compile_commands.json file to feed the indexer.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable this to see the dependency graph.
# set_property(GLOBAL PROPERTY GLOBAL_DEPENDS_DEBUG_MODE 1)

# -----------------------------------------------------------------------------

get_filename_component(xpack_tests_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)
get_filename_component(xpack_project_folder ${xpack_tests_folder} DIRECTORY)

include("${xpack_project_folder}/xpacks/micro-os-plus-build-helper/cmake/xpack-helper.cmake")

# Add the current project.
list(APPEND CMAKE_PREFIX_PATH "${xpack_project_folder}/meta")
# Add folders that have a *-config.cmake file.
xpack_append_cmake_prefix_path("${xpack_project_folder}/xpacks")

# -----------------------------------------------------------------------------

# Informative. Leave the result in PACKAGE_JSON_VERSION[*]
xpack_parse_package_json_semver("${xpack_project_folder}/package.json")

project(
  tests
  DESCRIPTION "µTest++ tests"
  VERSION "${PACKAGE_JSON_VERSION}"
)

# -----------------------------------------------------------------------------

message(STATUS "Platform name: ${PLATFORM_NAME}")
# CMAKE_BUILD_TYPE: Debug, Release, RelWithDebInfo, MinSizeRel
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Project path: ${xpack_project_folder}")
message(STATUS "Prefix path: ${CMAKE_PREFIX_PATH}")

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
  include("${xpack_tests_folder}/platform-native/meta/config.cmake")
elseif(PLATFORM_NAME STREQUAL "stm32f4discovery")
  include("${xpack_tests_folder}/platform-stm32f4discovery/meta/config.cmake")
else()
  message(FATAL_ERROR, "Unsupported PLATFORM_NAME")
endif()

# -----------------------------------------------------------------------------

find_package(micro-os-plus-micro-test-plus REQUIRED)

# Bare-metal platforms have more dependencies.
if(CMAKE_SYSTEM_NAME STREQUAL "Generic")
  find_package(micro-os-plus-libs-c REQUIRED)
  find_package(micro-os-plus-libs-cpp REQUIRED)
  find_package(micro-os-plus-semihosting REQUIRED)
  find_package(micro-os-plus-startup REQUIRED)
endif()

# -----------------------------------------------------------------------------

function(add_test_executable name)

  add_executable(${name})

  set_target_properties(
    ${name}

    PROPERTIES
      OUTPUT_NAME "${name}"
  )

  message(STATUS "+ src/${name}.cpp")
  # Application sources.
  target_sources(
    ${name}

    PRIVATE
      ${xpack_tests_folder}/src/${name}.cpp
  )

  # Include folders.
  target_include_directories(
    ${name}

    PRIVATE
      ${xpack_tests_folder}/include
  )

  target_compile_definitions(
    ${name}

    PRIVATE
      # ...
  )

  # Bare-metal platforms should be warnings free.
  if(CMAKE_SYSTEM_NAME STREQUAL "Generic")
    target_compile_options(
      ${name}

      PRIVATE
        -Werror
    )
  endif()

  target_link_libraries(
    ${name}
    
      micro-os-plus::micro-test-plus
  )

  if(CMAKE_SYSTEM_NAME STREQUAL "Generic")

    target_link_libraries(
      ${name}
      
        micro-os-plus::platform # Should bring device & architecture too.

        micro-os-plus::libs-c
        micro-os-plus::libs-cpp
        micro-os-plus::semihosting
        micro-os-plus::startup
    )

    target_link_options(
      ${name}

      PRIVATE
        -Wl,-Map,${name}-map.txt
    )

    add_custom_command(
      TARGET ${name} POST_BUILD
      COMMAND ${CMAKE_SIZE} --format=berkeley "$<TARGET_FILE:${name}>"
    )

  endif()

  message(STATUS "=> ${name}")
  
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

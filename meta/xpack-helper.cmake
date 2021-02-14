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

message(STATUS "Including micro-os-plus-micro-test-plus...")

# -----------------------------------------------------------------------------

function(target_sources_micro_os_plus_micro_test_plus target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_sources(
    ${target}

    PUBLIC
      ${xpack_current_folder}/src/micro-test-plus.cpp
  )

endfunction()

# -----------------------------------------------------------------------------

function(target_include_directories_micro_os_plus_micro_test_plus target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_include_directories(
    ${target}

    PUBLIC
      ${xpack_current_folder}/include
  )

endfunction()

# -----------------------------------------------------------------------------

function(target_compile_definitions_micro_os_plus_micro_test_plus target)

  # None

endfunction()

# -----------------------------------------------------------------------------

function(add_libraries_micro_os_plus_micro_test_plus)

  # ---------------------------------------------------------------------------

  add_library(micro-os-plus-micro-test-plus-object OBJECT EXCLUDE_FROM_ALL)

  target_sources_micro_os_plus_micro_test_plus(micro-os-plus-micro-test-plus-object)
  target_include_directories_micro_os_plus_micro_test_plus(micro-os-plus-micro-test-plus-object)
  target_compile_definitions_micro_os_plus_micro_test_plus(micro-os-plus-micro-test-plus-object)

  add_library(micro-os-plus::micro-test-plus ALIAS micro-os-plus-micro-test-plus-object)
  message(STATUS "micro-os-plus::micro-test-plus")

  target_link_libraries(
    micro-os-plus-micro-test-plus-object
    
    INTERFACE
      micro-os-plus::common
  )

  # ---------------------------------------------------------------------------

if(true)
  add_library(micro-os-plus-micro-test-plus-static STATIC EXCLUDE_FROM_ALL)

  target_sources_micro_os_plus_micro_test_plus(micro-os-plus-micro-test-plus-static)
  target_include_directories_micro_os_plus_micro_test_plus(micro-os-plus-micro-test-plus-static)
  target_compile_definitions_micro_os_plus_micro_test_plus(micro-os-plus-micro-test-plus-static)

  add_library(micro-os-plus::micro-test-plus-static ALIAS micro-os-plus-micro-test-plus-static)

  target_link_libraries(
    micro-os-plus-micro-test-plus-static
    
    PUBLIC
      micro-os-plus::common
  )
endif()

  # ---------------------------------------------------------------------------

endfunction()

# -----------------------------------------------------------------------------

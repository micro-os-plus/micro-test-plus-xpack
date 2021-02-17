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

if(platform-stm32f4discovery-included)
  return()
endif()

set(platform-stm32f4discovery-included TRUE)

message(STATUS "Including platform-stm32f4discovery...")

# -----------------------------------------------------------------------------

function(target_sources_platform_stm32f4discovery target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_sources(
    ${target}

    PRIVATE
      ${xpack_current_folder}/src/initialize-hardware.cpp
      ${xpack_current_folder}/src/interrupts-handlers.cpp
  )

endfunction()


function(target_include_directories_platform_stm32f4discovery target)

  # None

endfunction()


function(target_compile_definitions_platform_stm32f4discovery target)

  # None

endfunction()

# =============================================================================

function(target_include_directories_micro_os_plus_common target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_include_directories(
    ${target}

    INTERFACE
      ${xpack_current_folder}/include
  )

endfunction()


function(target_compile_definitions_micro_os_plus_common target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_compile_definitions(
    ${target}

    INTERFACE      
      OS_USE_SEMIHOSTING_SYSCALLS
      # HAVE_MICRO_OS_PLUS_CONFIG_H

      $<$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">:OS_USE_TRACE_SEMIHOSTING_DEBUG>
  )

endfunction()


function(target_options_micro_os_plus_common target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  set(common_cpu_options 

    -mcpu=cortex-m4
    -mthumb
    -mfloat-abi=soft
  )

  set(common_optimization_options

    -fmessage-length=0
    -fsigned-char
    -ffunction-sections
    -fdata-sections
    -fno-move-loop-invariants

    $<$<COMPILE_LANGUAGE:CXX>:-fabi-version=0>
    # $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>

    # -Wunused
    # -Wuninitialized
    # -Wall
    # -Wextra
    # -Wconversion
    # -Wpointer-arith
    # -Wshadow
    # -Wlogical-op
    # -Wfloat-equal

    # $<$<COMPILE_LANGUAGE:CXX>:-Wctor-dtor-privacy>
    # $<$<COMPILE_LANGUAGE:CXX>:-Wnoexcept>
    # $<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>
    # $<$<COMPILE_LANGUAGE:CXX>:-Wstrict-null-sentinel>
    # $<$<COMPILE_LANGUAGE:CXX>:-Wsign-promo>
  )

  target_compile_options(
    ${target}

    INTERFACE
      ${common_cpu_options}
      ${common_optimization_options}
  )

  target_link_options(
    ${target}

    INTERFACE
      ${common_cpu_options}
      ${common_optimization_options}

      -nostartfiles
      # nano has no exceptions.
      # -specs=nano.specs
      -Xlinker --gc-sections

      # -Wl,-u,Reset_Handler
      # -Wl,-u,initialise_monitor_handles
      # -Wl,--whole-archive 
      # libmicro-os-plus.a  libmicro-os-plus-micro-test-plus-static.a  bin/libplatform-stm32f4discovery-static.a  bin/libmicro-os-plus-platform-stm32f4discovery-static.a  bin/libmicro-os-plus-device-static.a  bin/libmicro-os-plus-devices-stm32f4-extras-static.a  libmicro-os-plus-libs-c-static.a  libmicro-os-plus-libs-cpp-static.a  bin/libmicro-os-plus-semihosting-static.a  bin/libmicro-os-plus-startup-static.a  bin/libmicro-os-plus-diag-trace-static.a 
      # -Wl,--no-whole-archive

      # Including files from other packages is not very nice, but functional.
      # Use absolute paths, otherwise set -L.
      -T${xpack_project_folder}/xpacks/micro-os-plus-platform-stm32f4discovery/linker-scripts/mem.ld
      -T${xpack_project_folder}/xpacks/micro-os-plus-architecture-cortexm/linker-scripts/sections.ld
  )

endfunction()

# -----------------------------------------------------------------------------

function(add_libraries_platform_stm32f4discovery)

  # ---------------------------------------------------------------------------

  # This will also define the device.
  find_package(micro-os-plus-platform-stm32f4discovery)
  find_package(micro-os-plus-startup)

  # ===========================================================================

  if(NOT TARGET micro-os-plus-common-interface)

    # Common definitions used across all dependencies.
    add_library(micro-os-plus-common-interface INTERFACE EXCLUDE_FROM_ALL)

    target_include_directories_micro_os_plus_common(micro-os-plus-common-interface)
    target_compile_definitions_micro_os_plus_common(micro-os-plus-common-interface)
    target_options_micro_os_plus_common(micro-os-plus-common-interface)

    add_library(micro-os-plus::common ALIAS micro-os-plus-common-interface)
    message(STATUS "micro-os-plus::common")

  endif()

  # ===========================================================================

  if(NOT TARGET platform-stm32f4discovery-objects)

    # Local platform definitions. Depend on device.
    add_library(platform-stm32f4discovery-objects OBJECT EXCLUDE_FROM_ALL)

    target_sources_platform_stm32f4discovery(platform-stm32f4discovery-objects)
    target_include_directories_platform_stm32f4discovery(platform-stm32f4discovery-objects)
    target_compile_definitions_platform_stm32f4discovery(platform-stm32f4discovery-objects)

    add_library(micro-os-plus::platform ALIAS platform-stm32f4discovery-objects)
    message(STATUS "micro-os-plus::platform")

    target_link_libraries(
      platform-stm32f4discovery-objects

      PUBLIC
        micro-os-plus::platform-stm32f4discovery
    )

  endif()

  # ---------------------------------------------------------------------------

if(true)
  if(NOT TARGET platform-stm32f4discovery-static)

    add_library(platform-stm32f4discovery-static STATIC EXCLUDE_FROM_ALL)

    target_sources_platform_stm32f4discovery(platform-stm32f4discovery-static)
    target_include_directories_platform_stm32f4discovery(platform-stm32f4discovery-static)
    target_compile_definitions_platform_stm32f4discovery(platform-stm32f4discovery-static)

    add_library(micro-os-plus::platform-static ALIAS platform-stm32f4discovery-static)

    target_link_libraries(
      platform-stm32f4discovery-static
      
      PUBLIC
        micro-os-plus::platform-stm32f4discovery-static
        micro-os-plus::startup-static
    )

  endif()
endif()

  # ---------------------------------------------------------------------------

endfunction()

# -----------------------------------------------------------------------------

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
# The current folder.

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# ---------------------------------------------------------------------------
# Global definitions. Before any libraries.

include_directories(

  ${xpack_current_folder}/include
)

add_compile_definitions(

  OS_USE_SEMIHOSTING_SYSCALLS
  # HAVE_MICRO_OS_PLUS_CONFIG_H

  $<$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">:OS_USE_TRACE_SEMIHOSTING_DEBUG>
)

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

add_compile_options(

    ${common_cpu_options}
    ${common_optimization_options}
)

add_link_options(

    ${common_cpu_options}
    ${common_optimization_options}
)

add_link_options(
  
    -nostartfiles
    # nano has no exceptions.
    # -specs=nano.specs
    -Wl,--gc-sections

    # Including files from other packages is not very nice, but functional.
    # Use absolute paths, otherwise set -L.
    -T${xpack_project_folder}/xpacks/micro-os-plus-platform-stm32f4discovery/linker-scripts/mem.ld
    -T${xpack_project_folder}/xpacks/micro-os-plus-architecture-cortexm/linker-scripts/sections.ld
)

# -----------------------------------------------------------------------------
# Dependencies.

# This will also define the device.
find_package(micro-os-plus-platform-stm32f4discovery REQUIRED)

# ---------------------------------------------------------------------------
# Recompute current path after find_package().

get_filename_component(xpack_current_folder ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)

# ---------------------------------------------------------------------------

if(NOT TARGET platform-stm32f4discovery-interface)

  add_library(platform-stm32f4discovery-interface INTERFACE EXCLUDE_FROM_ALL)

  # -------------------------------------------------------------------------

  target_sources(
    platform-stm32f4discovery-interface

    INTERFACE
      ${xpack_current_folder}/src/initialize-hardware.cpp
      ${xpack_current_folder}/src/interrupts-handlers.cpp
  )

  target_include_directories(
    platform-stm32f4discovery-interface

    INTERFACE
      # The include folder was passed globally, to catch the global config.h.
  )

  # The preprocessor definitions were passed globally.

  target_link_libraries(
    platform-stm32f4discovery-interface
    
    INTERFACE
      micro-os-plus::platform-stm32f4discovery
  )

  # -------------------------------------------------------------------------
  # Aliases.

  add_library(micro-os-plus::platform ALIAS platform-stm32f4discovery-interface)
  message(STATUS "micro-os-plus::platform")

endif()

# -----------------------------------------------------------------------------

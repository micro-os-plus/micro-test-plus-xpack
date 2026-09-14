# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2023-2026 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# Create the platform specific library.

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/platforms/${PLATFORM_NAME}/'...")

# -----------------------------------------------------------------------------

# TODO: possibly update to separate device-stm32f4-extras, when ready.
add_subdirectory ("device")

# -----------------------------------------------------------------------------
# Define the platform library.
add_library (
  platform-raspberry-pi-pico-sdk-interface INTERFACE EXCLUDE_FROM_ALL
)

# -----------------------------------------------------------------------------

target_include_directories (
  platform-raspberry-pi-pico-sdk-interface INTERFACE "include"
)

target_compile_definitions (
  platform-raspberry-pi-pico-sdk-interface
  INTERFACE
    "${xpack_platform_compile_definition}"
    # Full POSIX conformance:
    # https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap02.html#tag_02_01_03
    _POSIX_C_SOURCE=200809L
    # For S_IREAD
    _GNU_SOURCE
)

set (
  xpack_platform_common_args
  -mcpu=cortex-m0plus
  -mthumb
  -mfloat-abi=soft
  # -fno-move-loop-invariants Embedded builds generally must be warning free,
  # but PICO SDK does not allow this. -Werror -flto fails to run on QEMU.
  # $<$<CONFIG:Release>:-flto> $<$<CONFIG:MinSizeRel>:-flto>
  $<$<CONFIG:Debug>:-fno-omit-frame-pointer>
  # ... libs-c/src/stdlib/exit.c:132:46
  # $<$<CXX_COMPILER_ID:GNU>:-Wno-missing-attributes> parameter passing for
  # argument of type
  # 'os::rtos::memory::allocator_stateless_default_resource<os::rtos::thread>'
  # changed in GCC 7.1 $<$<CXX_COMPILER_ID:GNU>:-Wno-psabi>
  # $<$<COMPILE_LANGUAGE:C>:-fxxx>
  # https://cmake.org/cmake/help/v3.20/manual/cmake-generator-expressions.7.html?highlight=compile_language#genex:COMPILE_LANGUAGE
  # $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
  # $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
  # $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
)

target_compile_options (
  platform-raspberry-pi-pico-sdk-interface
  INTERFACE ${xpack_platform_common_args}
)

# When `-flto` is used, the compile options must be passed to the linker too.
target_link_options (
  platform-raspberry-pi-pico-sdk-interface
  INTERFACE
  # -v
  ${xpack_platform_common_args}
  -nostartfiles
  # --specs=rdimon.specs -Wl,--start-group -lgcc -lc -lc -lm -lrdimon
  # -Wl,--end-group Force the linker to keep the interrupt vectors which
  # otherwise are not referred from anywhere. -u_interrupt_vectors nano has no
  # exceptions. -specs=nano.specs
  -Wl,--gc-sections
  -Wl,-z,max-page-size=4096
)

if ("${CMAKE_C_COMPILER_VERSION}" VERSION_GREATER_EQUAL "12.0.0")
  target_link_options (
    platform-raspberry-pi-pico-sdk-interface INTERFACE
    # .elf has a LOAD segment with RWX permissions (GCC 12)
    -Wl,--no-warn-rwx-segment
  )
endif ()

target_link_libraries (
  platform-raspberry-pi-pico-sdk-interface INTERFACE micro-os-plus::device
                                                     micro-os-plus::startup
)

xpack_display_target_lists (platform-raspberry-pi-pico-sdk-interface)

# -----------------------------------------------------------------------------

# Aliases.
add_library (
  micro-os-plus::platform ALIAS platform-raspberry-pi-pico-sdk-interface
)
message (VERBOSE
         "> micro-os-plus::platform -> platform-raspberry-pi-pico-sdk-interface"
)

# -----------------------------------------------------------------------------

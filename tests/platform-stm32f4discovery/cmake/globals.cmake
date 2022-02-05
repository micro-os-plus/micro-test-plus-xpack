#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file defines the global settings that apply to all targets.
# Must be included with include() in the `tests` scope.

message(VERBOSE "Including platform-stm32f4discovery globals...")

# -----------------------------------------------------------------------------
# Global definitions. Before any libraries.

# A list of all imaginable warnings.
xpack_set_all_compiler_warnings(all_warnings)

# The global configuration file and possibly other platform defines.
include_directories(

  # Folders are relative to `tests`.
  "platform-stm32f4discovery/include-config"
)

message(VERBOSE "G+ -I tests/platform-stm32f4discovery/include-config")

add_compile_definitions(

  MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS
  # HAVE_MICRO_OS_PLUS_CONFIG_H

  # Do not use CMAKE_BUILD_TYPE
  $<$<CONFIG:Debug>:MICRO_OS_PLUS_USE_TRACE_SEMIHOSTING_DEBUG>
)

message(VERBOSE "G+ -D MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS")
message(VERBOSE "G+ -D $<$<CONFIG:Debug>:MICRO_OS_PLUS_USE_TRACE_SEMIHOSTING_DEBUG>")

set(common_options

  -mcpu=cortex-m4
  -mthumb
  -mfloat-abi=soft

  -fmessage-length=0
  -fsigned-char

  -ffunction-sections
  -fdata-sections

  -fno-move-loop-invariants

  # $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-use-cxa-atexit>
  $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>

  # -flto fails with undefined reference to `__assert_func'...
  # $<$<CONFIG:Release>:-flto>
  # $<$<CONFIG:MinSizeRel>:-flto>

  # ... libs-c/src/stdlib/exit.c:132:46
  # $<$<CXX_COMPILER_ID:GNU>:-Wno-missing-attributes>

  ${all_warnings}

  -Werror
)

add_compile_options(

    ${common_options}
)

add_link_options(

    ${common_options}
)

add_link_options(

    -nostartfiles
    # nano has no exceptions.
    # -specs=nano.specs
    -Wl,--gc-sections

    # Ensure the linker will keep the interrupt vectors which otherwise
    # are not refered from anywhere.
    -u_interrupt_vectors

    # Including files from other packages is not very nice, but functional.
    # Use absolute paths, otherwise set -L.
    -T${CMAKE_BINARY_DIR}/xpacks/micro-os-plus-platform-stm32f4discovery/linker-scripts/mem.ld
    -T${CMAKE_BINARY_DIR}/xpacks/micro-os-plus-architecture-cortexm/linker-scripts/sections.ld
)

# -----------------------------------------------------------------------------

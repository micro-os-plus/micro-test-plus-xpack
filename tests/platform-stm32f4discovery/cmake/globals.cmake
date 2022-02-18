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

# Global compiler definitions.
add_compile_definitions(

  # Moved to config.h
)

set(platform_common_options

  -mcpu=cortex-m4
  -mthumb
  -mfloat-abi=soft
  # -mfloat-abi=hard

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

  # Embedded builds must be warning free.
  -Werror
)

add_compile_options(
    ${platform_common_options}
)

add_link_options(
    ${platform_common_options}
)

add_link_options(
    -nostartfiles
    # nano has no exceptions.
    # -specs=nano.specs
    -Wl,--gc-sections

    # Force the linker to keep the interrupt vectors which otherwise
    # are not refered from anywhere.
    -u_interrupt_vectors

    # Including files from other packages is not very nice, but functional.
    # Use absolute paths, otherwise set -L.
    -T${CMAKE_BINARY_DIR}/xpacks/micro-os-plus-platform-stm32f4discovery/linker-scripts/mem.ld
    -T${CMAKE_BINARY_DIR}/xpacks/micro-os-plus-architecture-cortexm/linker-scripts/sections.ld
)

# -----------------------------------------------------------------------------

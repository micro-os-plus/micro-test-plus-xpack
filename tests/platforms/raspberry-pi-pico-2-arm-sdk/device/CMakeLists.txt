# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2022-2026 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/platforms/${PLATFORM_NAME}/device'...")

# -----------------------------------------------------------------------------

# Define the device library.
add_library (micro-os-plus-device-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------

target_include_directories (micro-os-plus-device-interface INTERFACE "include")

target_sources (
  micro-os-plus-device-interface INTERFACE "src/_sbrk.c" "src/wraps.c"
)

target_compile_definitions (
  micro-os-plus-device-interface
  INTERFACE # Default is 0x800 (2 KB); full (non-nano) Newlib's
            # vfprintf/_svfprintf can overflow that. 0x1000 (4 KB) is the
            # maximum obtainable this way, since the stack is reserved out of
            # the 4 KB SCRATCH_Y bank; going further requires relocating the
            # stack into main RAM via a linker script override.
            PICO_STACK_SIZE=0x1000
)

target_compile_options (
  micro-os-plus-device-interface
  INTERFACE # Turn off many warnings, the Pico SDK throws a lot of them.
            $<$<COMPILE_LANGUAGE:C>:-Wno-c++-compat>
            $<$<COMPILE_LANGUAGE:C>:-Wno-missing-prototypes>
            $<$<COMPILE_LANGUAGE:C>:-Wno-nested-externs>
            $<$<COMPILE_LANGUAGE:C>:-Wno-bad-function-cast>
            -Wno-undef
            -Wno-arith-conversion
            -Wno-padded
            -Wno-missing-declarations
)

target_link_options (
  micro-os-plus-device-interface INTERFACE
  #
  -Wl,--wrap=main -Wl,--wrap=__libc_init_array
)

target_link_libraries (
  micro-os-plus-device-interface
  INTERFACE cmsis_core
            pico_standard_link
            pico_crt0
            pico_runtime_init
            hardware_gpio
            hardware_clocks
            micro-os-plus::architecture
)

xpack_display_target_lists (cmsis_core)
xpack_display_target_lists (pico_standard_link)
xpack_display_target_lists (pico_crt0)
xpack_display_target_lists (pico_runtime_init)
xpack_display_target_lists (hardware_gpio)
xpack_display_target_lists (hardware_clocks)

xpack_display_target_lists (micro-os-plus-device-interface)

# -----------------------------------------------------------------------------

# Aliases.
add_library (micro-os-plus::device ALIAS micro-os-plus-device-interface)
message (VERBOSE "> micro-os-plus::device -> micro-os-plus-device-interface")

# -----------------------------------------------------------------------------

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
add_library (device-raspberry-pi-rp2040-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------

target_include_directories (
  device-raspberry-pi-rp2040-interface
  INTERFACE
    "include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Core/Include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Device/RP2040/Include"
)

target_sources (
  device-raspberry-pi-rp2040-interface
  INTERFACE "src/bs2_default_padded_checksummed.S" "src/vectors-rp2040.c"
            "src/system-rp2040.c"
)

target_compile_definitions (device-raspberry-pi-rp2040-interface INTERFACE)

target_compile_options (
  device-raspberry-pi-rp2040-interface
  INTERFACE # Turn off many warnings, the Pico SDK throws a lot of them.
            $<$<COMPILE_LANGUAGE:C>:-Wno-c++-compat>
            $<$<COMPILE_LANGUAGE:C>:-Wno-old-style-definition>
            $<$<COMPILE_LANGUAGE:C>:-Wno-missing-prototypes>
            $<$<COMPILE_LANGUAGE:C>:-Wno-nested-externs>
            $<$<COMPILE_LANGUAGE:C>:-Wno-bad-function-cast>
            -Wno-undef
            -Wno-arith-conversion
            -Wno-attributes
            -Wno-padded
            -Wno-format
            -Wno-format-y2k
            -Wno-format-nonliteral
            -Wno-format-security
            -Wno-aggregate-return
            -Wno-packed
            -Wno-missing-declarations
)

target_link_options (device-raspberry-pi-rp2040-interface INTERFACE)

target_link_libraries (
  device-raspberry-pi-rp2040-interface INTERFACE micro-os-plus::architecture
)

xpack_display_target_lists (device-raspberry-pi-rp2040-interface)

# -----------------------------------------------------------------------------

# Aliases.
add_library (micro-os-plus::device ALIAS device-raspberry-pi-rp2040-interface)
message (VERBOSE
         "> micro-os-plus::device -> device-raspberry-pi-rp2040-interface"
)

# -----------------------------------------------------------------------------

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

add_subdirectory ("rp2350")

# -----------------------------------------------------------------------------

# Define the device library.
add_library (micro-os-plus-device-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------

target_include_directories (
  micro-os-plus-device-interface
  INTERFACE
    "include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Core/Include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/cmsis/stub/CMSIS/Device/RP2350/Include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/common/boot_picobin_headers/include"
)

target_sources (
  micro-os-plus-device-interface
  INTERFACE "src/vectors-rp2350.c" "src/system-rp2350.cpp"
            "src/embedded-block-rp2350.c"
)

target_compile_definitions (micro-os-plus-device-interface INTERFACE)

target_compile_options (micro-os-plus-device-interface INTERFACE)

target_link_options (micro-os-plus-device-interface INTERFACE)

target_link_libraries (
  micro-os-plus-device-interface INTERFACE micro-os-plus::architecture
                                           micro-os-plus::device-rp2350
)

xpack_display_target_lists (micro-os-plus-device-interface)

# -----------------------------------------------------------------------------

# Aliases.
add_library (micro-os-plus::device ALIAS micro-os-plus-device-interface)
message (VERBOSE "> micro-os-plus::device -> micro-os-plus-device-interface")

# -----------------------------------------------------------------------------

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

message (VERBOSE
         "Processing 'tests/platforms/${PLATFORM_NAME}/device/rp2040'..."
)

# -----------------------------------------------------------------------------
# Define the RP2040 device library.
add_library (device-raspberry-pi-rp2040-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------

target_include_directories (
  device-raspberry-pi-rp2040-interface
  INTERFACE
    "include"
    # Header-only register bit-field definitions used by src/system-clock.cpp
    # to bring up the clocks; no Pico SDK library/CMake target is linked.
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2040/hardware_regs/include"
)

target_sources (
  device-raspberry-pi-rp2040-interface INTERFACE "src/system-clock.cpp"
)

xpack_display_target_lists (device-raspberry-pi-rp2040-interface)

# -----------------------------------------------------------------------------

# Aliases.
add_library (
  micro-os-plus::device-rp2040 ALIAS device-raspberry-pi-rp2040-interface
)
message (
  VERBOSE
  "> micro-os-plus::device-rp2040 -> device-raspberry-pi-rp2040-interface"
)

# -----------------------------------------------------------------------------

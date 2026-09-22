# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2026 Liviu Ionescu. All rights reserved.
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
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/common/boot_picobin_headers/include"
    # For "pico/bootrom_constants.h".
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/pico_bootrom/include"
    "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk/src/rp2_common/boot_bootrom_headers/include"
)

target_sources (
  micro-os-plus-device-interface
  INTERFACE "src/debugger-entry-point.S" "src/trap-handler.cpp"
            "src/embedded-block-rp2350-riscv.c"
)

target_compile_definitions (
  micro-os-plus-device-interface
  INTERFACE # boot/bootrom_constants.h otherwise includes pico/platform.h, which
            # (like hardware/hazard3.h -- see micro-os-plus/device.h) pulls in
            # pico/config_autogen.h, a header this platform's build does not
            # generate. BOOTROM_ENTRY_OFFSET itself does not depend on it.
            NO_PICO_PLATFORM
)

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

# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2023-2025 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/platforms/${PLATFORM_NAME}/device/'...")

# -----------------------------------------------------------------------------

add_subdirectory ("stm32cubemx")

# -----------------------------------------------------------------------------

# Define the device library.
add_library (device-stm32h5xx-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------
target_include_directories (device-stm32h5xx-interface INTERFACE "include")

target_sources (
  device-stm32h5xx-interface
  INTERFACE "src/vectors-stm32h533xx.c" "src/exception-handlers.cpp"
            "src/reset-handler.c" "src/debugger-entry-point.S"
)

# target_compile_definitions ( device-stm32h5xx-interface INTERFACE
# "${xpack_device_compile_definition}" )

target_compile_options (device-stm32h5xx-interface INTERFACE)

target_link_options (
  device-stm32h5xx-interface
  INTERFACE
  # Prefer absolute paths over paths relative to the build folder.
  -T${CMAKE_CURRENT_SOURCE_DIR}/linker-scripts/mem.ld
  -T${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/startup/linker-scripts/sections.ld
)

target_link_libraries (
  device-stm32h5xx-interface INTERFACE micro-os-plus::stm32cubemx
)

xpack_display_target_lists (device-stm32h5xx-interface)

# -----------------------------------------------------------------------------
# Aliases.
add_library (micro-os-plus::device ALIAS device-stm32h5xx-interface)
message (VERBOSE "> micro-os-plus::device -> device-stm32h5xx-interface")

# -----------------------------------------------------------------------------

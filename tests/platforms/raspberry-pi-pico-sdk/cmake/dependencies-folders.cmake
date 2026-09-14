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

# Define a list of folders where the platform dependencies are located.

# -----------------------------------------------------------------------------

message (
  VERBOSE
  "Including tests/platforms/${PLATFORM_NAME}/cmake/dependencies-folders.cmake..."
)

# -----------------------------------------------------------------------------
set (
  xpack_dependencies_folders
  #
  # Portable dependencies.
  "${CMAKE_SOURCE_DIR}/xpacks/@micro-os-plus/diag-trace"
  #
  # Platform specific dependencies.
  "${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/architecture-cortexm"
  # Pico SDK.
  "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/raspberrypi-pico-sdk"
  #
  "${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/semihosting"
  "${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/startup"
)

# -----------------------------------------------------------------------------

set (PICO_BOARD pico)
set (PICO_CXX_ENABLE_EXCEPTIONS 1)

# -----------------------------------------------------------------------------

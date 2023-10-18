# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
# (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# Add the platform dependencies.

# -----------------------------------------------------------------------------

# Required in devices-qemu-cortexm.
set(xpack_device_compile_definition "MICRO_OS_PLUS_DEVICE_QEMU_CORTEX_M7")

set(xpack_platform_compile_definition "MICRO_OS_PLUS_PLATFORM_QEMU_CORTEX_M7F")

# -----------------------------------------------------------------------------
set(xpack_dependencies_folders

  # Project dependencies.

  # The BINARY_DIR is the `build/<config>` folder.
  "${CMAKE_BINARY_DIR}/xpacks/@xpack-3rd-party/arm-cmsis-core"
  "${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/architecture-cortexm"
  "${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/devices-qemu-cortexm"
  "${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/semihosting"
  "${CMAKE_BINARY_DIR}/xpacks/@micro-os-plus/startup"

  # The SOURCE_DIR is the `tests` folder.
  "${CMAKE_SOURCE_DIR}/xpacks/@micro-os-plus/diag-trace"
)

xpack_add_dependencies_subdirectories("${xpack_dependencies_folders}" "xpacks-bin")

# -----------------------------------------------------------------------------

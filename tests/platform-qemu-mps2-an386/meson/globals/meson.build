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

# Definitions required for compiling all files, thus the use of
# add_global_*() functions.
# Must be called before creating any library or executable.

# Note: -flto fails with undefined __assert_func, _write, etc.

platform_common_flags = [
  '-mcpu=cortex-m4',
  '-mthumb',
  '-mfloat-abi=hard',

  '-fno-move-loop-invariants',
]

platform_common_cpp_extra_flags = [
  '-fno-rtti',
  '-fno-use-cxa-atexit',
  '-fno-threadsafe-statics',
]

if get_option('buildtype').contains('debug')
  platform_common_flags += [
    '-fno-omit-frame-pointer'
  ]
endif

add_global_arguments(
  platform_common_flags,

  language: [ 'c', 'cpp' ]
)

add_global_arguments(
  platform_common_cpp_extra_flags,

  language: [ 'cpp' ]
)

add_global_link_arguments(
  platform_common_flags,

  language: [ 'c', 'cpp' ]
)

add_global_link_arguments(
  platform_common_cpp_extra_flags,

  language: [ 'cpp' ]
)

add_global_arguments(
  '-DMICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS',

  language: [ 'c', 'cpp' ]
)

message('+ -D MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS')
if get_option('buildtype').contains('debug')
  add_global_arguments(
    '-DMICRO_OS_PLUS_USE_TRACE_SEMIHOSTING_STDOUT',

    language: [ 'c', 'cpp' ]
  )
  message('+ -D MICRO_OS_PLUS_USE_TRACE_SEMIHOSTING_STDOUT')
endif

# The current folder is tests, we must include folders from the build folder.
xpack_dependencies = [
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-version', # -
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-diag-trace', # -
  xpack_build_folder_relative_path + '/xpacks/xpack-3rd-party-arm-cmsis-core-m', # -
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-architecture-cortexm', # (architecture) -
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-semihosting', # diag-trace, architecture
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-device-cortexm', # semihosting
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-startup', # version, diag-trace, architecture
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-libs-c', # diag-trace, startup, architecture
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-libs-cpp', # diag-trace
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-device-qemu-cortexm', # device, diag-trace | (device) arm-cmsis-core-m, architecture-cortexm-device
]

xpack_device_compile_definition='DEVICE_QEMU_CORTEX_M4'

# -----------------------------------------------------------------------------

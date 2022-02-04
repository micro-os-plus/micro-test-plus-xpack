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

platform_common_flags = [
  '-mcpu=cortex-m4',
  '-mthumb',
  '-mfloat-abi=soft',

  '-fno-move-loop-invariants',
]

platform_common_c_extra_flags = [
  # Normally should be in the HAL library.
  '-Wno-bad-function-cast',
]

platform_common_cpp_extra_flags = [
  '-fno-rtti',
  '-fno-use-cxa-atexit',
  '-fno-threadsafe-statics'
]

if get_option('buildtype').contains('debug')
  platform_common_flags += [
    '-fno-omit-frame-pointer'
  ]
endif

# Inclded in common part.
# '-fmessage-length=0', '-fsigned-char',
# '-ffunction-sections', '-fdata-sections',
# '-flto', '-fno-omit-frame-pointer'

add_global_arguments(
  platform_common_flags,

  language: [ 'c', 'cpp' ]
)

add_global_arguments(
  platform_common_c_extra_flags,

  language: [ 'c' ]
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

message('G+ -D MICRO_OS_PLUS_USE_SEMIHOSTING_SYSCALLS')

if get_option('buildtype').contains('debug')
  add_global_arguments(
    '-DMICRO_OS_PLUS_USE_TRACE_SEMIHOSTING_STDOUT',

    language: [ 'c', 'cpp' ]
  )
  message('G+ -D MICRO_OS_PLUS_USE_TRACE_SEMIHOSTING_STDOUT')
endif

# -----------------------------------------------------------------------------

# The current folder is tests, we must include folders from the build folder.
# The order is relevant, each package must be included only after
# all its dependencies were included.
xpack_dependencies = [
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-version', # -
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-diag-trace', # -
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-architecture-cortexm', # - >architecture
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-startup', # +(version, diag_trace, architecture) >startup
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-libs-c', # +(diag_trace, startup, architecture) >libs_c
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-libs-cpp', # +(diag_trace) >libs_cpp

  # +(diag_trace, architecture) >semihosting
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-semihosting',
  # +(semihosting) >devices_cortexm
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-devices-cortexm',

  # +(architecture) >devices_stm32f4*_extra
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-devices-stm32f4-extras',

  # +(devices_cortexm, devices_stm32f4*_extra, startup) >device
  # +(device, diag_trace) >platform_stm32f4discovery
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-platform-stm32f4discovery',
]

# -----------------------------------------------------------------------------

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
# Must be added with subdir() before creating any library or executable.

message('Including platform-stm32f4discovery globals...')

# -----------------------------------------------------------------------------

xpack_platform_common_args = []
xpack_platform_common_c_args = []
xpack_platform_common_cpp_args = []
xpack_platform_compile_definitions = []

# Compiler definitions must passed as options.
xpack_platform_compile_definitions += [
  '-D_POSIX_C_SOURCE=200809L',
]

xpack_platform_common_args += [
  '-mcpu=cortex-m4',
  '-mthumb',
  '-mfloat-abi=soft',

  # '-flto' # fails with undefined __assert_func, _write, etc.

  '-fno-move-loop-invariants',

  # Embedded builds must be warning free.
  '-Werror',
]

if get_option('buildtype').contains('debug')
  xpack_platform_common_args += [
    '-fno-omit-frame-pointer'
  ]
endif

xpack_platform_common_c_args += [
  # Normally should be in the HAL library.
  '-Wno-bad-function-cast',
]

xpack_platform_common_cpp_args += [
  # '-fno-exceptions',
  # '-fno-rtti',
  '-fno-use-cxa-atexit',
  '-fno-threadsafe-statics',
]

add_global_arguments(
  xpack_platform_common_args + xpack_platform_common_c_args + xpack_platform_compile_definitions,

  language: [ 'c' ]
)

add_global_arguments(
  xpack_platform_common_args + xpack_platform_common_cpp_args + xpack_platform_compile_definitions,

  language: [ 'cpp' ]
)

foreach xn : xpack_platform_common_args + xpack_platform_common_c_args + xpack_platform_common_cpp_args + xpack_platform_compile_definitions
  message('G+ ' + xn)
endforeach

add_global_link_arguments(
  xpack_platform_common_args + xpack_platform_common_c_args,

  language: [ 'c' ]
)

add_global_link_arguments(
  xpack_platform_common_args + xpack_platform_common_cpp_args,

  language: [ 'cpp' ]
)

# -----------------------------------------------------------------------------

# The current folder is tests, we must include folders from the build folder.
# The order is relevant, each package must be included only after
# all its dependencies were included.
xpack_dependencies = [
  'xpacks/micro-os-plus-diag-trace', # -

  # -
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-version',
  # - >architecture
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-architecture-cortexm',

  # +(version, diag_trace, architecture) >startup
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-startup',
  # +(diag_trace, startup, architecture) >libs_c
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-libs-c',
  # +(diag_trace) >libs_cpp
  xpack_build_folder_relative_path + '/xpacks/micro-os-plus-libs-cpp',

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

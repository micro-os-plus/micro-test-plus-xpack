#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# Inclded in `tests/meson/globals`.
# '-fmessage-length=0', '-fsigned-char',
# '-ffunction-sections', '-fdata-sections',
# '-flto'.

platform_common_flags = [
]

if get_option('buildtype') == 'release' or get_option('buildtype') == 'minsize' or get_option('buildtype') == 'debugoptimized'
  platform_common_flags += [
    '-flto'
  ]
endif

platform_common_cpp_extra_flags = [
]

add_global_arguments(
  platform_common_flags,

  language: [ 'c', 'cpp' ]
)

add_global_arguments(
  platform_common_cpp_extra_flags,

  language: [ 'cpp' ]
)

# -----------------------------------------------------------------------------

# Native builds do not have dependencies.
xpack_dependencies = []

# -----------------------------------------------------------------------------

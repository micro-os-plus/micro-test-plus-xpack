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
# '-ffunction-sections', '-fdata-sections'.

platform_common_options = [
]

if get_option('buildtype') == 'release' or get_option('buildtype') == 'minsize' or get_option('buildtype') == 'debugoptimized'
  # https://mesonbuild.com/Reference-tables.html#operating-system-names
  if build_machine.system() == 'linux' and c_compiler.get_id().contains('clang')
    if build_machine.cpu() == 'armv7l'
      # clang-12: error: unable to execute command: Segmentation fault
      # clang-12: error: linker command failed due to signal (use -v to see invocation)
    else
      # meson-out/sample-test.p/.._src_sample-test.cpp.o: file not recognized: file format not recognized
      platform_common_options += [
        '-flto',
      ]
    endif
  else
    message('boo')
    platform_common_options += [
      '-flto'
    ]
  endif
endif

add_global_arguments(
  platform_common_options,

  language: [ 'c', 'cpp' ]
)

add_global_link_arguments(
  platform_common_options,

  language: [ 'c', 'cpp' ]
)


# -----------------------------------------------------------------------------

# Native builds do not have dependencies.
xpack_dependencies = []

# -----------------------------------------------------------------------------

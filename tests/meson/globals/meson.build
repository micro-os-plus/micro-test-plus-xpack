#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------
## Common definitions for all platforms ##

## Assume GCC or clang, for MSVC things are different
if c_compiler.get_id() == 'gcc' or c_compiler.get_id().contains('clang')

  # Always add the `include-config` folder.
  includes = [ '-I../../tests/platform-' + xpack_platform_name + '/include-config' ]
  message('+ -I tests/platform-' + xpack_platform_name + '/include-config')

  # Global compiler preprocessor definitions.
  # Native builds may not use them.
  compiler_definitions = []
  if get_option('buildtype').contains('debug')
    compiler_definitions += ['-DDEBUG']
    compiler_definitions += ['-DTRACE']
  endif
  if get_option('buildtype') == 'release'
    compiler_definitions += ['-DNDEBUG']
  endif

  # Options for both compilers and linkers. When using `-flto`, all options
  # must also be passed to the linker.
  # https://mesonbuild.com/Reference-tables.html#c_compiler-ids

  common_options = []
  if get_option('buildtype') == 'debug'
    # common_options += ['-O0']
  elif get_option('buildtype') == 'debugoptimized'
    common_options += ['-Og'] # Override -O2
  elif get_option('buildtype') == 'minsize'
    # common_options += ['-Os']
  elif get_option('buildtype') == 'release'
    # common_options += ['-O3']
  else
    common_options += ['-O']
  endif

  common_options += [
    '-fmessage-length=0',
    '-fsigned-char'
  ]

  # This is used in conjunction with linker `--gc-sections`.
  common_options += [
    '-ffunction-sections',
    '-fdata-sections'
  ]

  add_global_arguments(
    includes + compiler_definitions + common_options,

    language: [ 'c', 'cpp' ]
  )

  # When using -flto, the options must be passed to the linker too.
  add_global_link_arguments(
    common_options,

    language: [ 'c', 'cpp' ]
  )

else
  message('Unsupported compiler')
endif

# -----------------------------------------------------------------------------


#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `subdir('xpacks/micro-os-plus-micro-test-plus')`
#
# The result is a static library that can be added to the linker with:
#
# `dependencies: [lib_micro_os_plus_micro_test_plus_dependency],`
# `link_with: [lib_micro_os_plus_micro_test_plus],`

# Note: the meson configuration is provided only as a proof of concept,
# for production it might need some refinements.

# -----------------------------------------------------------------------------

# https://mesonbuild.com/Reference-manual.html#project
project('µTest++',
  ['c', 'cpp'],
  default_options: ['c_std=c11', 'cpp_std=c++17'],
  meson_version: '>= 0.59'
)

# languages: {c, cpp}

# https://mesonbuild.com/Builtin-options.html#compiler-options
# c_std: none, c89, c99, c11, c17, c18, c2x, gnu89, gnu99, gnu11, gnu17, gnu18, gnu2x
#
# cpp_std: none, c++98, c++03, c++11, c++14, c++17, c++20
# c++2a, c++1z, gnu++03, gnu++11, gnu++14, gnu++17, gnu++1z,
# gnu++2a, gnu++20, vc++14, vc++17, vc++latest

# -----------------------------------------------------------------------------

fs = import('fs')
compiler = meson.get_compiler('c')

# -----------------------------------------------------------------------------

xpack_project_folder = meson.current_source_dir()

# -----------------------------------------------------------------------------

# buildtype: {plain, debug, debugoptimized, release, minsize, custom}
message('Build type: ' + get_option('buildtype'))
message('Project path: ' + xpack_project_folder)

# -----------------------------------------------------------------------------

# Compiler preprocessor definitions.
compiler_definitions = []
if get_option('buildtype').contains('debug')
  compiler_definitions += ['-DDEBUG']
endif
if get_option('buildtype') == 'release'
  compiler_definitions += ['-DNDEBUG']
endif

# Options for both compilers and linkers. When using -flto all options
# must also be passed to the linker.
# https://mesonbuild.com/Reference-tables.html#compiler-ids

common_options = []

if compiler.get_id() == 'gcc' or compiler.get_id().contains('clang')
  common_options += [
    '-fmessage-length=0',
    '-fsigned-char'
  ]
  # This is used in conjunction with linker `--gc-sections`.
  common_options += [
    '-ffunction-sections',
    '-fdata-sections'
  ]

  if get_option('buildtype') == 'release' or get_option('buildtype') == 'debugoptimized'
  # Optional, comment it out to disable link time optimizations.
    common_options += [
      '-flto'
    ]
  endif
  if get_option('buildtype').contains('debug')
    common_options += [
      '-fno-omit-frame-pointer'
    ]
  endif
elif compiler.get_id() == 'msvc'
  common_options += [
    '/utf-8'
    # Add MSVC options here.
  ]
endif

c_compiler_options = compiler_definitions + common_options

cpp_compiler_options=compiler_definitions + common_options

# -----------------------------------------------------------------------------

lib_micro_os_plus_micro_test_plus = static_library(
  'micro-os-plus-micro-test-plus',
  include_directories: include_directories(
    'include',
  ),
  sources: files(
    'src/micro-test-plus.cpp',
  ),
  c_args: c_compiler_options,
  cpp_args: cpp_compiler_options,
)

# https://mesonbuild.com/Reference-manual.html#declare_dependency
lib_micro_os_plus_micro_test_plus_dependency = declare_dependency(
  include_directories: include_directories(
    'include',
  ),
)

# -----------------------------------------------------------------------------

if get_option('is-micro-os-plus-micro-test-plus-test')
  # https://mesonbuild.com/Reference-manual.html#subdir
  subdir('tests')
endif

# -----------------------------------------------------------------------------

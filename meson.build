# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `subdir('xpacks/micro-os-plus-micro-test-plus')`
#
# The result is a library and a dependency that can be referred as:
#
# `dependencies: [micro_os_plus_micro_test_plus_dependency],`

# Note: the meson configuration is provided only as a proof of concept,
# for production it might need some refinements.

# -----------------------------------------------------------------------------

message('Processing xPack @micro-os-plus/micro-test-plus...')

# -----------------------------------------------------------------------------

xpack_common_args = []
xpack_c_args = []
xpack_cpp_args = []
xpack_include_directories = []
xpack_sources = []
xpack_compile_definitions = []

xpack_include_directories += [
  'include',
]

xpack_sources += [
  'src/micro-test-plus.cpp',
  'src/test-runner.cpp',
  'src/test-reporter.cpp',
  'src/test-suite.cpp',
]

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_micro_test_plus_dependency = declare_dependency(
  include_directories: include_directories(xpack_include_directories),
  compile_args: xpack_common_args,
  sources: files(xpack_sources),
)

# micro_os_plus_micro_test_plus_dependency_c_args = xpack_c_args
# micro_os_plus_micro_test_plus_dependency_cpp_args = xpack_cpp_args

foreach name : xpack_include_directories
  message('+ -I ' + name)
endforeach
foreach name : xpack_sources + xpack_common_args
  message('+ ' + name)
endforeach
message('> micro_os_plus_micro_test_plus_dependency')

# -----------------------------------------------------------------------------

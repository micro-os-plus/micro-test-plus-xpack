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
# The result is a dependency that can be refered as:
#
# `dependencies: [micro_os_plus_micro_test_plus_dependency],`

# Note: the meson configuration is provided only as a proof of concept,
# for production it might need some refinements.

# -----------------------------------------------------------------------------

message('Processing xPack @micro-os-plus/micro-test-plus...')

# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_micro_test_plus_dependency = declare_dependency(
  include_directories: include_directories(
    'include',
  ),
  sources: files(
    'src/micro-test-plus.cpp',
    'src/test-runner.cpp',
  ),
)

message('+ -I include')
message('+ src/micro-test-plus.cpp')
message('+ src/test-runner.cpp')
message('> micro_os_plus_micro_test_plus_dependency')

# -----------------------------------------------------------------------------

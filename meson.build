
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2022 Liviu Ionescu
#
# This Source Code Form is subject to the terms of the MIT License.
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `subdir('xpacks/micro-os-plus-micro-test-plus')`
#
# The result is a static library that can be added to the linker with:
#
# `dependencies: [micro_os_plus_micro_test_plus_dependency],`
# `link_with: [micro_os_plus_micro_test_plus_static],`

# Note: the meson configuration is provided only as a proof of concept,
# for production it might need some refinements.

# -----------------------------------------------------------------------------

message('Processing xPack @micro-os-plus/micro-test-plus...')

# Public definitions, also passed up to targets linking to them.
# https://mesonbuild.com/Reference-manual_functions.html#declare_dependency
micro_os_plus_micro_test_plus_dependency = declare_dependency(
  include_directories: include_directories(
    'include',
  )
)

message('+ -I include')
message('> micro_os_plus_micro_test_plus_dependency')

# https://mesonbuild.com/Reference-manual_functions.html#static_library
micro_os_plus_micro_test_plus_static = static_library(
  'micro-os-plus-micro-test-plus', # Archive name.
  sources: files(
    'src/micro-test-plus.cpp',
  ),
  dependencies: [
    micro_os_plus_micro_test_plus_dependency
  ]
)

message('+ src/micro-test-plus.cpp')
message('> micro_os_plus_micro_test_plus_static')

# -----------------------------------------------------------------------------

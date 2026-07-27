# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# build-helper/templates/common/_micro-os-plus/tests/meson/project-definitions/meson-liquid.build
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2022-2026 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Project specific definitions.

xpack_enable_empty_test = true
xpack_enable_minimal_test = true
xpack_enable_suite_test = true
xpack_enable_sample_test = true
xpack_enable_unit_test = true

xpack_dependencies_tests_folders = []
 
# Each test has its own library. Add only those enabled.
if xpack_enable_empty_test
  xpack_dependencies_tests_folders += [ 'sources/empty' ]
endif

if xpack_enable_minimal_test
  xpack_dependencies_tests_folders += [ 'sources/minimal' ]
endif

if xpack_enable_suite_test
  xpack_dependencies_tests_folders += [ 'sources/suite' ]
endif

if xpack_enable_sample_test
  xpack_dependencies_tests_folders += [ 'sources/sample' ]
endif

if xpack_enable_unit_test
  xpack_dependencies_tests_folders += [ 'sources/unit' ]
endif

# -----------------------------------------------------------------------------

# Enable them only when needed.
xpack_enable_report_size = true
xpack_enable_create_listing = false
xpack_enable_create_hex = false

# -----------------------------------------------------------------------------

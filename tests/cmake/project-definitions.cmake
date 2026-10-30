# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# build-helper/templates/common/_micro-os-plus/tests/cmake/project-definitions-liquid.cmake
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

set (XPACK_ENABLE_EMPTY_TEST true)
set (XPACK_ENABLE_MINIMAL_TEST true)
set (XPACK_ENABLE_SUITE_TEST true)
set (XPACK_ENABLE_SAMPLE_TEST true)
set (XPACK_ENABLE_UNIT_STATIC_ASSERTS_TEST true)
set (XPACK_ENABLE_UNIT_COMMON true)
set (XPACK_ENABLE_UNIT_CHECKS_TEST true)
set (XPACK_ENABLE_UNIT_COMBINATIONS_TEST true)
set (XPACK_ENABLE_UNIT_EXCEPTIONS_TEST true)
set (XPACK_ENABLE_UNIT_MISCELLANEOUS_TEST true)
set (XPACK_ENABLE_UNIT_DEPRECATED_TEST true)
set (XPACK_ENABLE_UNIT_TEST true)

set (xpack_dependencies_tests_folders)

# Each test has its own library. Add only those enabled.
if (XPACK_ENABLE_EMPTY_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/empty"
  )
endif ()

if (XPACK_ENABLE_MINIMAL_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/minimal"
  )
endif ()

if (XPACK_ENABLE_SUITE_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/suite"
  )
endif ()

if (XPACK_ENABLE_SAMPLE_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/sample"
  )
endif ()

if (XPACK_ENABLE_UNIT_STATIC_ASSERTS_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/unit-static-asserts"
  )
endif ()

if (XPACK_ENABLE_UNIT_COMMON)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/unit-common"
  )
endif ()

if (XPACK_ENABLE_UNIT_CHECKS_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/unit-checks"
  )
endif ()

if (XPACK_ENABLE_UNIT_COMBINATIONS_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/unit-combinations"
  )
endif ()

if (XPACK_ENABLE_UNIT_EXCEPTIONS_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/unit-exceptions"
  )
endif ()

if (XPACK_ENABLE_UNIT_MISCELLANEOUS_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/unit-miscellaneous"
  )
endif ()

if (XPACK_ENABLE_UNIT_DEPRECATED_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/unit-deprecated"
  )
endif ()

# The combined unit test must follow the tests it combines.
if (XPACK_ENABLE_UNIT_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/unit"
  )
endif ()

# -----------------------------------------------------------------------------

set (XPACK_ENABLE_REPORT_SIZE true)
set (XPACK_ENABLE_CREATE_HEX false)
set (XPACK_ENABLE_CREATE_LISTING true)

# -----------------------------------------------------------------------------

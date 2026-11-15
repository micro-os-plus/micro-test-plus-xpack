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

set (xpack_dependencies_tests_folders)

set (XPACK_ENABLE_FOOTPRINT_BENCHMARKS_TEST false)

if (XPACK_ENABLE_FOOTPRINT_BENCHMARKS_TEST)

set (XPACK_ENABLE_EMPTY_TEST false)
set (XPACK_ENABLE_MINIMAL_TEST false)
set (XPACK_ENABLE_SUITE_TEST false)
set (XPACK_ENABLE_SAMPLE_TEST false)
set (XPACK_ENABLE_UNIT_STATIC_ASSERTS_TEST false)
set (XPACK_ENABLE_UNIT_CHECKS_TEST false)
set (XPACK_ENABLE_UNIT_COMBINATIONS_TEST false)
set (XPACK_ENABLE_UNIT_EXCEPTIONS_TEST false)
set (XPACK_ENABLE_UNIT_MISCELLANEOUS_TEST false)
set (XPACK_ENABLE_UNIT_DEPRECATED_TEST false)
set (XPACK_ENABLE_UNIT_TEST false)

# The footprint benchmark programs (`sources/benchmarks/footprint`).
#
# The programs without a third-party framework are always built; those of the
# other frameworks only if `xpm run fetch-benchmarks-frameworks` fetched the
# framework into the `benchmarks-frameworks` folder. The executables are
# defined in the platform `cmake/artefacts.cmake`, which skips those listed
# in `xpack_footprint_benchmarks_not_built`, and does not run those listed in
# `xpack_footprint_benchmarks_not_run`; both lists are set in the platform
# `cmake/definitions.cmake`.

set (xpack_footprint_benchmarks baseline printf micro-test-plus)

# Pairs of benchmark names and the `benchmarks-frameworks` sub-folders they
# require (for snitch, the generated configuration header).
set (
  xpack_footprint_frameworks
  "unity:unity"
  "cpputest:cpputest"
  "doctest:doctest"
  "catch2:catch2"
  "boost-ut:boost-ut"
  "boost-test:boost"
  "googletest:googletest"
  "snitch:snitch-config"
)

foreach (pair ${xpack_footprint_frameworks})
  string (REPLACE ":" ";" pair_list "${pair}")
  list (GET pair_list 0 benchmark_name)
  list (GET pair_list 1 framework_folder)
  if (EXISTS "${CMAKE_SOURCE_DIR}/benchmarks-frameworks/${framework_folder}")
    list (APPEND xpack_footprint_benchmarks "${benchmark_name}")
  else ()
    message (VERBOSE "Footprint benchmark '${benchmark_name}' skipped, "
             "'benchmarks-frameworks/${framework_folder}' not found"
    )
  endif ()
endforeach ()

# The stubs come first, since some of the framework programs depend on them.
list (APPEND xpack_dependencies_tests_folders
      "${CMAKE_SOURCE_DIR}/sources/benchmarks/footprint/common"
)
foreach (benchmark_name ${xpack_footprint_benchmarks})
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/benchmarks/footprint/${benchmark_name}"
  )
endforeach ()

else()

set (XPACK_ENABLE_EMPTY_TEST true)
set (XPACK_ENABLE_MINIMAL_TEST true)
set (XPACK_ENABLE_SUITE_TEST true)
set (XPACK_ENABLE_SAMPLE_TEST true)
set (XPACK_ENABLE_UNIT_STATIC_ASSERTS_TEST true)
set (XPACK_ENABLE_UNIT_CHECKS_TEST true)
set (XPACK_ENABLE_UNIT_COMBINATIONS_TEST true)
set (XPACK_ENABLE_UNIT_EXCEPTIONS_TEST true)
set (XPACK_ENABLE_UNIT_MISCELLANEOUS_TEST true)
set (XPACK_ENABLE_UNIT_DEPRECATED_TEST true)
set (XPACK_ENABLE_UNIT_TEST true)

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

if (XPACK_ENABLE_UNIT_TEST)
  list (APPEND xpack_dependencies_tests_folders
        "${CMAKE_SOURCE_DIR}/sources/unit"
  )
endif ()

endif ()

# -----------------------------------------------------------------------------

set (XPACK_ENABLE_REPORT_SIZE true)
set (XPACK_ENABLE_CREATE_HEX false)
set (XPACK_ENABLE_CREATE_LISTING false)

# -----------------------------------------------------------------------------

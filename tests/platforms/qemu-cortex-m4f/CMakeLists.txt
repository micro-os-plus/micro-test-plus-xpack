# -----------------------------------------------------------------------------
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

# Create the platform specific test executables.

# -----------------------------------------------------------------------------

message (VERBOSE "Processing 'tests/platforms/qemu-cortex-m4f'...")

include ("cmake/platform-library.cmake")

# The libraries are compiled before the platform library, so they need to get
# the same compile options.
add_compile_common_private_options (micro-os-plus-micro-test-plus-static)

# -----------------------------------------------------------------------------

set (XPACK_QEMU_BINARY "qemu-system-arm")
set (XPACK_QEMU_MACHINE_ARGS --machine mps2-an386 --cpu cortex-m4)
set (XPACK_QEMU_EXTRA_ARGS --nographic -d unimp,guest_errors)

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_cross_test_executable (empty-test)
  target_link_cross_test_libraries (empty-test tests::empty)

  message (VERBOSE "A> empty-test")

  add_qemu_test (
    NAME "empty-test" COMMAND empty-test one two --output-file empty-test.tap
  )
  add_compare_files_test (
    NAME "empty-test-compare"
    DEPENDS "empty-test"
    FILES "empty-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_MINIMAL_TEST)
  add_cross_test_executable (minimal-test)
  target_link_cross_test_libraries (minimal-test tests::minimal)

  message (VERBOSE "A> minimal-test")

  add_qemu_test (
    NAME "minimal-test" COMMAND minimal-test one two --output-file
                                minimal-test.tap
  )
  add_compare_files_test (
    NAME "minimal-test-compare"
    DEPENDS "minimal-test"
    FILES "minimal-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_cross_test_executable (suite-test)
  target_link_cross_test_libraries (suite-test tests::suite)

  message (VERBOSE "A> suite-test")

  add_qemu_test (
    NAME "suite-test" COMMAND suite-test one two --output-file suite-test.tap
  )
  add_compare_files_test (
    NAME "suite-test-compare"
    DEPENDS "suite-test"
    FILES "suite-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_cross_test_executable (sample-test)
  target_link_cross_test_libraries (sample-test tests::sample)

  message (VERBOSE "A> sample-test")

  add_qemu_test (
    NAME "sample-test" COMMAND sample-test one two --output-file
                               sample-test.tap
  )
  add_compare_files_test (
    NAME "sample-test-compare"
    DEPENDS "sample-test"
    FILES "sample-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_cross_test_executable (unit-test)
  target_link_cross_test_libraries (unit-test tests::unit)

  message (VERBOSE "A> unit-test")

  add_qemu_test (
    NAME "unit-test-quiet" COMMAND unit-test --quiet one two --output-file
                                   unit-test.tap
  )
  add_compare_files_test (
    NAME "unit-test-quiet-compare"
    DEPENDS "unit-test-quiet"
    FILES "unit-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )

  add_qemu_test (
    NAME "unit-test-reporter-human" COMMAND unit-test --reporter human one two
                                            --output-file unit-test.txt
  )
  add_compare_files_test (
    NAME "unit-test-reporter-human-compare"
    DEPENDS "unit-test-reporter-human"
    FILES "unit-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/unit-test.txt"
  )
endif ()

# -----------------------------------------------------------------------------

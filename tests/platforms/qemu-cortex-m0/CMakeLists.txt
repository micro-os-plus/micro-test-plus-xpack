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

message (VERBOSE "Processing 'tests/platforms/qemu-cortex-m3'...")

include ("cmake/platform-library.cmake")

# The OBJECTS are compiled before the platform library, so they need to get the
# same compile options.
add_common_options_to_objects_library (micro-os-plus-micro-test-plus-objects)

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_cross_test_executable (empty-test)
  target_link_cross_test_libraries (empty-test test::empty)

  message (VERBOSE "A> empty-test")

  # Currently QEMU does not support any M0 board.
  # The mps2-an385 board has a Cortex-M3 CPU, but it is the closest to M0, 
  # and it is used for testing the M0 code.
  add_test (
    NAME "empty-test"
    COMMAND
      qemu-system-arm${extension} --machine mps2-an385 --cpu cortex-m3 --kernel
      empty-test.elf --nographic -d unimp,guest_errors --semihosting-config
      enable=on,target=native,arg=empty-test,arg=one,arg=two,arg=--output-file,arg=empty-test.tap
  )

  add_test (
    NAME "empty-test-compare"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-files.sh"
      "empty-test.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )
  set_tests_properties ("empty-test-compare" PROPERTIES DEPENDS "empty-test")
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_MINIMAL_TEST)
  add_cross_test_executable (minimal-test)
  target_link_cross_test_libraries (minimal-test test::minimal)

  message (VERBOSE "A> minimal-test")

  add_test (
    NAME "minimal-test"
    COMMAND
      qemu-system-arm${extension} --machine mps2-an385 --cpu cortex-m3 --kernel
      minimal-test.elf --nographic -d unimp,guest_errors --semihosting-config
      enable=on,target=native,arg=minimal-test,arg=one,arg=two,arg=--output-file,arg=minimal-test.tap
  )

  add_test (
    NAME "minimal-test-compare"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-files.sh"
      "minimal-test.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )
  set_tests_properties (
    "minimal-test-compare" PROPERTIES DEPENDS "minimal-test"
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_cross_test_executable (suite-test)
  target_link_cross_test_libraries (suite-test test::suite)

  message (VERBOSE "A> suite-test")

  add_test (
    NAME "suite-test"
    COMMAND
      qemu-system-arm${extension} --machine mps2-an385 --cpu cortex-m3 --kernel
      suite-test.elf --nographic -d unimp,guest_errors --semihosting-config
      enable=on,target=native,arg=suite-test,arg=one,arg=two,arg=--output-file,arg=suite-test.tap
  )

  add_test (
    NAME "suite-test-compare"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-files.sh"
      "suite-test.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )
  set_tests_properties ("suite-test-compare" PROPERTIES DEPENDS "suite-test")
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_cross_test_executable (sample-test)
  target_link_cross_test_libraries (sample-test test::sample)

  message (VERBOSE "A> sample-test")

  add_test (
    NAME "sample-test"
    COMMAND
      qemu-system-arm${extension} --machine mps2-an385 --cpu cortex-m3 --kernel
      sample-test.elf --nographic -d unimp,guest_errors --semihosting-config
      enable=on,target=native,arg=sample-test,arg=one,arg=two,arg=--output-file,arg=sample-test.tap
  )

  add_test (
    NAME "sample-test-compare"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-files.sh"
      "sample-test.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )
  set_tests_properties ("sample-test-compare" PROPERTIES DEPENDS "sample-test")
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_cross_test_executable (unit-test)
  target_link_cross_test_libraries (unit-test test::unit)

  message (VERBOSE "A> unit-test")

  add_test (
    NAME "unit-test-quiet"
    COMMAND
      qemu-system-arm${extension} --machine mps2-an385 --cpu cortex-m3 --kernel
      unit-test.elf --nographic -d unimp,guest_errors --semihosting-config
      enable=on,target=native,arg=unit-test,arg=--quiet,arg=one,arg=two,arg=--output-file,arg=unit-test.tap
  )

  add_test (
    NAME "unit-test-quiet-compare"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-files.sh"
      "unit-test.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )
  set_tests_properties (
    "unit-test-quiet-compare" PROPERTIES DEPENDS "unit-test-quiet"
  )

  add_test (
    NAME "unit-test-reporter-human"
    COMMAND
      qemu-system-arm${extension} --machine mps2-an385 --cpu cortex-m3 --kernel
      unit-test.elf --nographic -d unimp,guest_errors --semihosting-config
      enable=on,target=native,arg=unit-test,arg=--reporter,arg=human,arg=one,arg=two,arg=--output-file,arg=unit-test.txt
  )

  add_test (
    NAME "unit-test-reporter-human-compare"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-files.sh"
      "unit-test.txt"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/unit-test.txt"
  )
  set_tests_properties (
    "unit-test-reporter-human-compare" PROPERTIES DEPENDS
                                                  "unit-test-reporter-human"
  )
endif ()

# -----------------------------------------------------------------------------

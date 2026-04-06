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

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_cross_test_executable (empty-test)
  target_link_cross_test_libraries (empty-test test::empty)

  message (VERBOSE "A> empty-test")

  add_test (
    NAME "empty-test"
    COMMAND
      qemu-system-arm${extension} --machine mps2-an385 --cpu cortex-m3 --kernel
      empty-test.elf --nographic -d unimp,guest_errors --semihosting-config
      enable=on,target=native,arg=empty-test,arg=one,arg=two,arg=--output-file,arg=empty-test.tap
  )
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
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_cross_test_executable (unit-test)
  target_link_cross_test_libraries (unit-test test::unit)

  message (VERBOSE "A> unit-test")

  add_test (
    NAME "unit-test"
    COMMAND
      qemu-system-arm${extension} --machine mps2-an385 --cpu cortex-m3 --kernel
      unit-test.elf --nographic -d unimp,guest_errors --semihosting-config
      enable=on,target=native,arg=unit-test
    # --semihosting-config arg=--verbose
  )
endif ()

# -----------------------------------------------------------------------------

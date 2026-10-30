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

message (VERBOSE
         "Including 'tests/platforms/${PLATFORM_NAME}/cmake/artefacts.cmake'..."
)

# -----------------------------------------------------------------------------

# The libraries are compiled before the platform library, so they need to get
# the same compile options.
prepend_compile_common_private_options (
  micro-os-plus-micro-test-plus-static-library
)

# -----------------------------------------------------------------------------

set (XPACK_OPENOCD_INTERFACE "stlink.cfg")
set (XPACK_OPENOCD_TARGET "stm32f7x.cfg")

# Running successive OpenOCD/CMSIS-DAP sessions back-to-back has been observed
# to intermittently fail the "verify" step of the next session with USB
# communication errors (e.g. "error reading USB data", "Pipe error", "CMSIS-DAP
# command SWD_Sequence failed"), most likely because the probe/host USB stack
# has not yet settled after the previous OpenOCD process released the device.
# Insert a short settle delay between consecutive OpenOCD tests as a workaround.
set (XPACK_OPENOCD_USB_SETTLE_DELAY_SECONDS "2")

function (add_openocd_test)

  cmake_parse_arguments (PARSE_ARGV 0 arg "" "NAME" "COMMAND")

  # First element is the ELF base name (argv[0] in the semihosting config).
  list (GET arg_COMMAND 0 name)

  set (semihosting_cmdline "arm semihosting_cmdline")
  foreach (a IN LISTS arg_COMMAND)
    string (APPEND semihosting_cmdline " ${a}")
  endforeach ()

  # If a previous OpenOCD test was already registered, insert a settle delay
  # test between it and this one, and chain the dependencies so ctest runs them
  # strictly in order: previous test -> delay -> this test, regardless of how
  # ctest would otherwise schedule them.
  set (openocd_depends "")
  if (DEFINED XPACK_LAST_OPENOCD_TEST_NAME)
    set (settle_test_name "${arg_NAME}-usb-settle-delay")
    add_test (NAME "${settle_test_name}"
              COMMAND "${CMAKE_COMMAND}" -E sleep
                      "${XPACK_OPENOCD_USB_SETTLE_DELAY_SECONDS}"
    )
    set_tests_properties (
      "${settle_test_name}" PROPERTIES DEPENDS
                                       "${XPACK_LAST_OPENOCD_TEST_NAME}"
    )
    set (openocd_depends "${settle_test_name}")
  endif ()

  # Use `reset halt` + `resume`, not `reset`: an early semihosting call may halt
  # the core while OpenOCD is still in the reset procedure, and remain
  # unserviced.
  add_test (
    NAME "${arg_NAME}"
    COMMAND
      openocd${extension}
      # -d3
      -c "gdb port disabled" -c "tcl port disabled" -c "telnet port disabled"
      -f "interface/${XPACK_OPENOCD_INTERFACE}" -c "transport select swd" -f
      "target/${XPACK_OPENOCD_TARGET}" -c "program ${name}.elf verify" -c
      "arm semihosting enable" -c "${semihosting_cmdline}" -c "reset halt" -c
      "resume"
  )

  if (openocd_depends)
    set_tests_properties ("${arg_NAME}" PROPERTIES DEPENDS "${openocd_depends}")
  endif ()

  set (
    XPACK_LAST_OPENOCD_TEST_NAME
    "${arg_NAME}"
    PARENT_SCOPE
  )

  message (VERBOSE "T> ${arg_NAME}")

endfunction ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_cross_test_executable (empty-test)
  target_link_cross_tests_libraries (empty-test test::empty)

  xpack_display_target_lists (empty-test)
  message (VERBOSE "A> empty-test")

  add_openocd_test (
    NAME
    "empty-test"
    COMMAND
    empty-test
    --output-file=empty-test.tap
    one
    two
  )

  add_compare_files_test (
    NAME "empty-test-compare"
    DEPENDS "empty-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/empty-test.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_MINIMAL_TEST)
  add_cross_test_executable (minimal-test)
  target_link_cross_tests_libraries (minimal-test test::minimal)

  xpack_display_target_lists (minimal-test)
  message (VERBOSE "A> minimal-test")

  add_openocd_test (
    NAME
    "minimal-test"
    COMMAND
    minimal-test
    --output-file=minimal-test.tap
    one
    two
  )

  add_compare_files_test (
    NAME "minimal-test-compare"
    DEPENDS "minimal-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/minimal-test.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_cross_test_executable (suite-test)
  target_link_cross_tests_libraries (suite-test test::suite)

  xpack_display_target_lists (suite-test)
  message (VERBOSE "A> suite-test")

  add_openocd_test (
    NAME
    "suite-test"
    COMMAND
    suite-test
    --output-file=suite-test.tap
    one
    two
  )

  add_compare_files_test (
    NAME "suite-test-compare"
    DEPENDS "suite-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/suite-test.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_cross_test_executable (sample-test)
  target_link_cross_tests_libraries (sample-test test::sample)

  xpack_display_target_lists (sample-test)
  message (VERBOSE "A> sample-test")

  add_openocd_test (
    NAME
    "sample-test"
    COMMAND
    sample-test
    --output-file=sample-test.tap
    one
    two
  )

  add_compare_files_test (
    NAME "sample-test-compare"
    DEPENDS "sample-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/sample-test.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_STATIC_ASSERTS_TEST)
  add_cross_test_executable (unit-static-asserts-test)
  target_link_native_test_libraries (
    unit-static-asserts-test test::unit-static-asserts
  )

  xpack_display_target_lists (unit-static-asserts-test)
  message (VERBOSE "A> unit-static-asserts-test")

  # There is nothing to test at runtime for static asserts, as they are checked
  # at compile time.
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_CHECKS_TEST)
  add_cross_test_executable (unit-checks-test)
  target_link_cross_tests_libraries (unit-checks-test test::unit-checks)

  xpack_display_target_lists (unit-checks-test)
  message (VERBOSE "A> unit-checks-test")

  # The TAP output is too verbose and takes to long to be displayed by the
  # OpenOCD semihosting.
  if (false)
    add_openocd_test (
      NAME
      "unit-checks-test"
      COMMAND
      unit-checks-test
      --output-file=unit-checks-test.tap
      one
      two
    )
    add_compare_files_test (
      NAME "unit-checks-test-compare"
      DEPENDS "unit-checks-test"
      FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test.tap"
            "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-checks-test.tap"
    )
  endif ()

  add_openocd_test (
    NAME
    "unit-checks-test-reporter-human"
    COMMAND
    unit-checks-test
    --reporter
    human
    --output-file=unit-checks-test.txt
    one
    two
  )
  add_compare_files_test (
    NAME "unit-checks-test-reporter-human-compare"
    DEPENDS "unit-checks-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-checks-test.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_COMBINATIONS_TEST)
  add_cross_test_executable (unit-combinations-test)
  target_link_cross_tests_libraries (
    unit-combinations-test test::unit-combinations
  )

  xpack_display_target_lists (unit-combinations-test)
  message (VERBOSE "A> unit-combinations-test")

  add_openocd_test (
    NAME
    "unit-combinations-test-reporter-human"
    COMMAND
    unit-combinations-test
    --reporter
    human
    --output-file=unit-combinations-test.txt
    one
    two
  )
  add_compare_files_test (
    NAME "unit-combinations-test-reporter-human-compare"
    DEPENDS "unit-combinations-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-combinations-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-combinations-test.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_EXCEPTIONS_TEST)
  add_cross_test_executable (unit-exceptions-test)
  target_link_cross_tests_libraries (unit-exceptions-test test::unit-exceptions)

  xpack_display_target_lists (unit-exceptions-test)
  message (VERBOSE "A> unit-exceptions-test")

  add_openocd_test (
    NAME
    "unit-exceptions-test-reporter-human"
    COMMAND
    unit-exceptions-test
    --reporter
    human
    --output-file=unit-exceptions-test.txt
    one
    two
  )
  add_compare_files_test (
    NAME "unit-exceptions-test-reporter-human-compare"
    DEPENDS "unit-exceptions-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-exceptions-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-exceptions-test.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_MISCELLANEOUS_TEST)
  add_cross_test_executable (unit-miscellaneous-test)
  target_link_cross_tests_libraries (
    unit-miscellaneous-test test::unit-miscellaneous
  )

  xpack_display_target_lists (unit-miscellaneous-test)
  message (VERBOSE "A> unit-miscellaneous-test")

  add_openocd_test (
    NAME
    "unit-miscellaneous-test-reporter-human"
    COMMAND
    unit-miscellaneous-test
    --reporter
    human
    --output-file=unit-miscellaneous-test.txt
    one
    two
  )
  add_compare_files_test (
    NAME "unit-miscellaneous-test-reporter-human-compare"
    DEPENDS "unit-miscellaneous-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-miscellaneous-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-miscellaneous-test.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_DEPRECATED_TEST)
  add_cross_test_executable (unit-deprecated-test)
  target_link_cross_tests_libraries (unit-deprecated-test test::unit-deprecated)

  xpack_display_target_lists (unit-deprecated-test)
  message (VERBOSE "A> unit-deprecated-test")

  add_openocd_test (
    NAME
    "unit-deprecated-test-reporter-human"
    COMMAND
    unit-deprecated-test
    --reporter
    human
    --output-file=unit-deprecated-test.txt
    one
    two
  )
  add_compare_files_test (
    NAME "unit-deprecated-test-reporter-human-compare"
    DEPENDS "unit-deprecated-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-deprecated-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-deprecated-test.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

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

message (VERBOSE "Processing 'tests/platforms/native'...")

include ("cmake/platform-library.cmake")

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_native_test_executable (empty-test)
  target_link_native_test_libraries (empty-test test::empty)

  message (VERBOSE "A> empty-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  add_test (NAME "empty-test --verbose"
            COMMAND empty-test one two --verbose --output-file
                    empty-test-verbose.tap
  )

  # --verbose
  add_test (
    NAME "empty-test compare-tap --verbose"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "empty-test-verbose.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )
  set_tests_properties (
    "empty-test compare-tap --verbose" PROPERTIES DEPENDS
                                                  "empty-test --verbose"
  )

  # default
  add_test (NAME "empty-test" COMMAND empty-test one two --output-file
                                      empty-test.tap
  )

  add_test (
    NAME "empty-test compare-tap"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "empty-test.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )
  set_tests_properties (
    "empty-test compare-tap" PROPERTIES DEPENDS "empty-test"
  )

  # --quiet
  add_test (NAME "empty-test --quiet"
            COMMAND empty-test one two --quiet --output-file
                    empty-test-quiet.tap
  )

  add_test (
    NAME "empty-test compare-tap --quiet"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "empty-test-quiet.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )
  set_tests_properties (
    "empty-test compare-tap --quiet" PROPERTIES DEPENDS "empty-test --quiet"
  )

  # --silent
  add_test (NAME "empty-test --silent"
            COMMAND empty-test one two --silent --output-file
                    empty-test-silent.tap
  )

  add_test (
    NAME "empty-test compare-tap --silent"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "empty-test-silent.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )
  set_tests_properties (
    "empty-test compare-tap --silent" PROPERTIES DEPENDS "empty-test --silent"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "empty-test --verbose --reporter human"
            COMMAND empty-test one two --verbose --reporter human
  )

  # default
  add_test (NAME "empty-test --reporter human"
            COMMAND empty-test one two --reporter human --output-file
                    empty-test.txt
  )

  add_test (
    NAME "empty-test compare-tap --reporter human"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "empty-test.txt"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/empty-test.txt"
  )
  set_tests_properties (
    "empty-test compare-tap --reporter human"
    PROPERTIES DEPENDS "empty-test --reporter human"
  )

  # --quiet
  add_test (NAME "empty-test --quiet --reporter human"
            COMMAND empty-test one two --quiet --reporter human
  )

  # --silent
  add_test (NAME "empty-test --silent --reporter human"
            COMMAND empty-test one two --silent --reporter human
  )

endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_MINIMAL_TEST)
  add_native_test_executable (minimal-test)
  target_link_native_test_libraries (minimal-test test::minimal)

  # Only for this test, always define the trace macros, to check if the tracing
  # support compiles  correctly.
  target_compile_definitions (
    minimal-test PRIVATE MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS_CONSTRUCTORS
                         MICRO_OS_PLUS_TRACE_MICRO_TEST_PLUS
  )

  message (VERBOSE "A> minimal-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "minimal-test --verbose --reporter tap"
            COMMAND minimal-test one two --verbose --reporter tap --output-file
                    minimal-test-verbose.tap
  )

  add_test (
    NAME "minimal-test compare-tap --verbose"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "minimal-test-verbose.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )
  set_tests_properties (
    "minimal-test compare-tap --verbose"
    PROPERTIES DEPENDS "minimal-test --verbose --reporter tap"
  )

  # default
  add_test (NAME "minimal-test --reporter tap"
            COMMAND minimal-test one two --reporter tap --output-file
                    minimal-test.tap
  )

  add_test (
    NAME "minimal-test compare-tap"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "minimal-test.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )
  set_tests_properties (
    "minimal-test compare-tap" PROPERTIES DEPENDS "minimal-test --reporter tap"
  )

  # --quiet
  add_test (NAME "minimal-test --quiet --reporter tap"
            COMMAND minimal-test one two --quiet --reporter tap --output-file
                    minimal-test-quiet.tap
  )

  add_test (
    NAME "minimal-test compare-tap --quiet"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "minimal-test-quiet.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )
  set_tests_properties (
    "minimal-test compare-tap --quiet"
    PROPERTIES DEPENDS "minimal-test --quiet --reporter tap"
  )

  # --silent
  add_test (NAME "minimal-test --silent --reporter tap"
            COMMAND minimal-test one two --silent --reporter tap --output-file
                    minimal-test-silent.tap
  )

  add_test (
    NAME "minimal-test compare-tap --silent"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "minimal-test-silent.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )
  set_tests_properties (
    "minimal-test compare-tap --silent"
    PROPERTIES DEPENDS "minimal-test --silent --reporter tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "minimal-test --verbose --reporter human"
            COMMAND minimal-test one two --verbose --reporter human
  )

  # default
  add_test (NAME "minimal-test --reporter human"
            COMMAND minimal-test one two --reporter human --output-file
                    minimal-test.txt
  )

  add_test (
    NAME "minimal-test compare-tap --reporter human"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "minimal-test.txt"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/minimal-test.txt"
  )
  set_tests_properties (
    "minimal-test compare-tap --reporter human"
    PROPERTIES DEPENDS "minimal-test --reporter human"
  )

  # --quiet
  add_test (NAME "minimal-test --quiet --reporter human"
            COMMAND minimal-test one two --quiet --reporter human
  )

  # --silent
  add_test (NAME "minimal-test --silent --reporter human"
            COMMAND minimal-test one two --silent --reporter human
  )

endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_native_test_executable (suite-test)
  target_link_native_test_libraries (suite-test test::suite)

  message (VERBOSE "A> suite-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "suite-test --verbose --reporter tap"
            COMMAND suite-test one two --verbose --reporter tap --output-file
                    suite-test-verbose.tap
  )

  add_test (
    NAME "suite-test compare-tap --verbose"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "suite-test-verbose.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )
  set_tests_properties (
    "suite-test compare-tap --verbose"
    PROPERTIES DEPENDS "suite-test --verbose --reporter tap"
  )

  # default
  add_test (NAME "suite-test --reporter tap"
            COMMAND suite-test one two --reporter tap --output-file
                    suite-test.tap
  )

  add_test (
    NAME "suite-test compare-tap"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "suite-test.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )
  set_tests_properties (
    "suite-test compare-tap" PROPERTIES DEPENDS "suite-test --reporter tap"
  )

  # --quiet
  add_test (NAME "suite-test --quiet --reporter tap"
            COMMAND suite-test one two --quiet --reporter tap --output-file
                    suite-test-quiet.tap
  )

  add_test (
    NAME "suite-test compare-tap --quiet"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "suite-test-quiet.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )
  set_tests_properties (
    "suite-test compare-tap --quiet"
    PROPERTIES DEPENDS "suite-test --quiet --reporter tap"
  )

  # --silent
  add_test (NAME "suite-test --silent --reporter tap"
            COMMAND suite-test one two --silent --reporter tap --output-file
                    suite-test-silent.tap
  )

  add_test (
    NAME "suite-test compare-tap --silent"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "suite-test-silent.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )
  set_tests_properties (
    "suite-test compare-tap --silent"
    PROPERTIES DEPENDS "suite-test --silent --reporter tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "suite-test --verbose --reporter human"
            COMMAND suite-test one two --verbose --reporter human
  )

  # default
  add_test (NAME "suite-test --reporter human"
            COMMAND suite-test one two --reporter human --output-file
                    suite-test.txt
  )

  add_test (
    NAME "suite-test compare-tap --reporter human"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "suite-test.txt"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/suite-test.txt"
  )
  set_tests_properties (
    "suite-test compare-tap --reporter human"
    PROPERTIES DEPENDS "suite-test --reporter human"
  )

  # --quiet
  add_test (NAME "suite-test --quiet --reporter human"
            COMMAND suite-test one two --quiet --reporter human
  )

  # --silent
  add_test (NAME "suite-test --silent --reporter human"
            COMMAND suite-test one two --silent --reporter human
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_native_test_executable (sample-test)
  target_link_native_test_libraries (sample-test test::sample)

  message (VERBOSE "A> sample-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "sample-test --verbose --reporter tap"
            COMMAND sample-test one two --verbose --reporter tap --output-file
                    sample-test-verbose.tap
  )

  add_test (
    NAME "sample-test compare-tap --verbose"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "sample-test-verbose.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )
  set_tests_properties (
    "sample-test compare-tap --verbose"
    PROPERTIES DEPENDS "sample-test --verbose --reporter tap"
  )

  # default
  add_test (NAME "sample-test --reporter tap"
            COMMAND sample-test one two --reporter tap --output-file
                    sample-test.tap
  )

  add_test (
    NAME "sample-test compare-tap"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "sample-test.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )
  set_tests_properties (
    "sample-test compare-tap" PROPERTIES DEPENDS "sample-test --reporter tap"
  )

  # --quiet
  add_test (NAME "sample-test --quiet --reporter tap"
            COMMAND sample-test one two --quiet --reporter tap --output-file
                    sample-test-quiet.tap
  )

  add_test (
    NAME "sample-test compare-tap --quiet"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "sample-test-quiet.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )
  set_tests_properties (
    "sample-test compare-tap --quiet"
    PROPERTIES DEPENDS "sample-test --quiet --reporter tap"
  )

  # --silent
  add_test (NAME "sample-test --silent --reporter tap"
            COMMAND sample-test one two --silent --reporter tap --output-file
                    sample-test-silent.tap
  )

  add_test (
    NAME "sample-test compare-tap --silent"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "sample-test-silent.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )
  set_tests_properties (
    "sample-test compare-tap --silent"
    PROPERTIES DEPENDS "sample-test --silent --reporter tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "sample-test --verbose --reporter human"
            COMMAND sample-test one two --verbose --reporter human
  )

  # default
  add_test (NAME "sample-test --reporter human"
            COMMAND sample-test one two --reporter human --output-file
                    sample-test.txt
  )

  add_test (
    NAME "sample-test compare-tap --reporter human"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "sample-test.txt"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/sample-test.txt"
  )
  set_tests_properties (
    "sample-test compare-tap --reporter human"
    PROPERTIES DEPENDS "sample-test --reporter human"
  )

  # --quiet
  add_test (NAME "sample-test --quiet --reporter human"
            COMMAND sample-test one two --quiet --reporter human
  )

  # --silent
  add_test (NAME "sample-test --silent --reporter human"
            COMMAND sample-test one two --silent --reporter human
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_native_test_executable (unit-test)
  target_link_native_test_libraries (unit-test test::unit)

  message (VERBOSE "A> unit-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose

  # add_test (NAME "unit-test --verbose --reporter tap" COMMAND unit-test
  # --verbose --reporter tap --output-file unit-test-verbose.tap)

  # add_test ( NAME "unit-test compare-tap --verbose" COMMAND bash
  # "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
  # "unit-test-verbose.tap"
  # "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap" )
  # set_tests_properties ( "unit-test compare-tap --verbose" PROPERTIES DEPENDS
  # "unit-test --verbose --reporter tap" )

  # add_test (NAME "unit-test --reporter tap" COMMAND unit-test --reporter tap)

  # --quiet
  add_test (NAME "unit-test --quiet --reporter tap"
            COMMAND unit-test --quiet --reporter tap --output-file
                    unit-test-quiet.tap
  )

  add_test (
    NAME "unit-test compare-tap --quiet"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "unit-test-quiet.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )
  set_tests_properties (
    "unit-test compare-tap --quiet"
    PROPERTIES DEPENDS "unit-test --quiet --reporter tap"
  )

  # --silent
  add_test (NAME "unit-test --silent --reporter tap"
            COMMAND unit-test --silent --reporter tap --output-file
                    unit-test-silent.tap
  )

  add_test (
    NAME "unit-test compare-tap --silent"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "unit-test-silent.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )
  set_tests_properties (
    "unit-test compare-tap --silent"
    PROPERTIES DEPENDS "unit-test --silent --reporter tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "unit-test --verbose --reporter human"
            COMMAND unit-test --verbose --reporter human
  )

  # default
  add_test (NAME "unit-test --reporter human"
            COMMAND unit-test --reporter human --output-file unit-test.txt
  )

  add_test (
    NAME "unit-test compare-tap --reporter human"
    COMMAND
      bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/compare-tap-files.sh"
      "unit-test.txt"
      "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/unit-test.txt"
  )
  set_tests_properties (
    "unit-test compare-tap --reporter human"
    PROPERTIES DEPENDS "unit-test --reporter human"
  )

  # --quiet
  add_test (NAME "unit-test --quiet --reporter human" COMMAND unit-test --quiet
                                                              --reporter human
  )

  # --silent
  add_test (NAME "unit-test --silent --reporter human"
            COMMAND unit-test --silent --reporter human
  )
endif ()

# -----------------------------------------------------------------------------

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

if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND CMAKE_HOST_SYSTEM_NAME STREQUAL
                                          "Darwin"
)
  # Enable it temporarily to check the coverage on macOS.
  set (XPACK_ENABLE_COVERAGE false)
endif ()

# The libraries are compiled before the platform library, so they need to get
# the same compile options.
add_compile_common_private_options (micro-os-plus-micro-test-plus-static)

if (XPACK_ENABLE_COVERAGE)
  add_compile_coverage_private_options (micro-os-plus-micro-test-plus-static)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_native_test_executable (empty-test)
  target_link_native_test_libraries (empty-test tests::empty)

  message (VERBOSE "A> empty-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "empty-test-verbose"
            COMMAND empty-test one two --verbose --output-file
                    empty-test-verbose.tap
  )

  add_compare_files_test (
    NAME "empty-test-verbose-compare"
    DEPENDS "empty-test-verbose"
    FILES "empty-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )

  # default
  add_test (NAME "empty-test" COMMAND empty-test one two --output-file
                                      empty-test.tap
  )

  # --quiet
  add_test (NAME "empty-test-quiet" COMMAND empty-test one two --quiet
                                            --output-file empty-test-quiet.tap
  )

  add_compare_files_test (
    NAME "empty-test-quiet-compare"
    DEPENDS "empty-test-quiet"
    FILES "empty-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )

  # --silent
  add_test (NAME "empty-test-silent"
            COMMAND empty-test one two --silent --output-file
                    empty-test-silent.tap
  )

  add_compare_files_test (
    NAME "empty-test-silent-compare"
    DEPENDS "empty-test-silent"
    FILES "empty-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "empty-test-reporter-human-verbose"
            COMMAND empty-test one two --verbose --reporter human
  )

  # default
  add_test (NAME "empty-test-reporter-human"
            COMMAND empty-test one two --reporter human --output-file
                    empty-test.txt
  )

  add_compare_files_test (
    NAME "empty-test-reporter-human-compare"
    DEPENDS "empty-test-reporter-human"
    FILES "empty-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/empty-test.txt"
  )

  # --quiet
  add_test (NAME "empty-test-reporter-human-quiet"
            COMMAND empty-test one two --quiet --reporter human
  )

  # --silent
  add_test (NAME "empty-test-reporter-human-silent"
            COMMAND empty-test one two --silent --reporter human
  )

endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_MINIMAL_TEST)
  add_native_test_executable (minimal-test)
  target_link_native_test_libraries (minimal-test tests::minimal)

  # Only for this test, always define the trace macros, to check if the tracing
  # support compiles  correctly.
  target_compile_definitions (
    minimal-test
    PRIVATE MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
            MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED
  )

  message (VERBOSE "A> minimal-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "minimal-test-reporter-tap-verbose"
            COMMAND minimal-test one two --verbose --reporter tap --output-file
                    minimal-test-verbose.tap
  )

  add_compare_files_test (
    NAME "minimal-test-reporter-tap-verbose-compare"
    DEPENDS "minimal-test-reporter-tap-verbose"
    FILES "minimal-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )

  # default
  add_test (NAME "minimal-test-reporter-tap"
            COMMAND minimal-test one two --reporter tap --output-file
                    minimal-test.tap
  )

  add_compare_files_test (
    NAME "minimal-test-reporter-tap-compare"
    DEPENDS "minimal-test-reporter-tap"
    FILES "minimal-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )

  # --quiet
  add_test (NAME "minimal-test-reporter-tap-quiet"
            COMMAND minimal-test one two --quiet --reporter tap --output-file
                    minimal-test-quiet.tap
  )

  add_compare_files_test (
    NAME "minimal-test-reporter-tap-quiet-compare"
    DEPENDS "minimal-test-reporter-tap-quiet"
    FILES "minimal-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )

  # --silent
  add_test (NAME "minimal-test-reporter-tap-silent"
            COMMAND minimal-test one two --silent --reporter tap --output-file
                    minimal-test-silent.tap
  )

  add_compare_files_test (
    NAME "minimal-test-reporter-tap-silent-compare"
    DEPENDS "minimal-test-reporter-tap-silent"
    FILES "minimal-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "minimal-test-reporter-human-verbose"
            COMMAND minimal-test one two --verbose --reporter human
  )

  # default
  add_test (NAME "minimal-test-reporter-human"
            COMMAND minimal-test one two --reporter human --output-file
                    minimal-test.txt
  )

  add_compare_files_test (
    NAME "minimal-test-reporter-human-compare"
    DEPENDS "minimal-test-reporter-human"
    FILES "minimal-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/minimal-test.txt"
  )

  # --quiet
  add_test (NAME "minimal-test-reporter-human-quiet"
            COMMAND minimal-test one two --quiet --reporter human
  )

  # --silent
  add_test (NAME "minimal-test-reporter-human-silent"
            COMMAND minimal-test one two --silent --reporter human
  )

endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_native_test_executable (suite-test)
  target_link_native_test_libraries (suite-test tests::suite)

  message (VERBOSE "A> suite-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "suite-test-reporter-tap-verbose"
            COMMAND suite-test one two --verbose --reporter tap --output-file
                    suite-test-verbose.tap
  )

  add_compare_files_test (
    NAME "suite-test-reporter-tap-verbose-compare"
    DEPENDS "suite-test-reporter-tap-verbose"
    FILES "suite-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )

  # default
  add_test (NAME "suite-test-reporter-tap"
            COMMAND suite-test one two --reporter tap --output-file
                    suite-test.tap
  )

  add_compare_files_test (
    NAME "suite-test-reporter-tap-compare"
    DEPENDS "suite-test-reporter-tap"
    FILES "suite-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )

  # --quiet
  add_test (NAME "suite-test-reporter-tap-quiet"
            COMMAND suite-test one two --quiet --reporter tap --output-file
                    suite-test-quiet.tap
  )

  add_compare_files_test (
    NAME "suite-test-reporter-tap-quiet-compare"
    DEPENDS "suite-test-reporter-tap-quiet"
    FILES "suite-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )

  # --silent
  add_test (NAME "suite-test-reporter-tap-silent"
            COMMAND suite-test one two --silent --reporter tap --output-file
                    suite-test-silent.tap
  )

  add_compare_files_test (
    NAME "suite-test-reporter-tap-silent-compare"
    DEPENDS "suite-test-reporter-tap-silent"
    FILES "suite-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "suite-test-reporter-human-verbose"
            COMMAND suite-test one two --verbose --reporter human
  )

  # default
  add_test (NAME "suite-test-reporter-human"
            COMMAND suite-test one two --reporter human --output-file
                    suite-test.txt
  )

  add_compare_files_test (
    NAME "suite-test-reporter-human-compare"
    DEPENDS "suite-test-reporter-human"
    FILES "suite-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/suite-test.txt"
  )

  # --quiet
  add_test (NAME "suite-test-reporter-human-quiet"
            COMMAND suite-test one two --quiet --reporter human
  )

  # --silent
  add_test (NAME "suite-test-reporter-human-silent"
            COMMAND suite-test one two --silent --reporter human
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_native_test_executable (sample-test)
  target_link_native_test_libraries (sample-test tests::sample)

  message (VERBOSE "A> sample-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "sample-test-reporter-tap-verbose"
            COMMAND sample-test one two --verbose --reporter tap --output-file
                    sample-test-verbose.tap
  )

  add_compare_files_test (
    NAME "sample-test-reporter-tap-verbose-compare"
    DEPENDS "sample-test-reporter-tap-verbose"
    FILES "sample-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )

  # default
  add_test (NAME "sample-test-reporter-tap"
            COMMAND sample-test one two --reporter tap --output-file
                    sample-test.tap
  )

  add_compare_files_test (
    NAME "sample-test-reporter-tap-compare"
    DEPENDS "sample-test-reporter-tap"
    FILES "sample-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )

  # --quiet
  add_test (NAME "sample-test-reporter-tap-quiet"
            COMMAND sample-test one two --quiet --reporter tap --output-file
                    sample-test-quiet.tap
  )

  add_compare_files_test (
    NAME "sample-test-reporter-tap-quiet-compare"
    DEPENDS "sample-test-reporter-tap-quiet"
    FILES "sample-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )

  # --silent
  add_test (NAME "sample-test-reporter-tap-silent"
            COMMAND sample-test one two --silent --reporter tap --output-file
                    sample-test-silent.tap
  )

  add_compare_files_test (
    NAME "sample-test-reporter-tap-silent-compare"
    DEPENDS "sample-test-reporter-tap-silent"
    FILES "sample-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "sample-test-reporter-human-verbose"
            COMMAND sample-test one two --verbose --reporter human
  )

  # default
  add_test (NAME "sample-test-reporter-human"
            COMMAND sample-test one two --reporter human --output-file
                    sample-test.txt
  )

  add_compare_files_test (
    NAME "sample-test-reporter-human-compare"
    DEPENDS "sample-test-reporter-human"
    FILES "sample-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/sample-test.txt"
  )

  # --quiet
  add_test (NAME "sample-test-reporter-human-quiet"
            COMMAND sample-test one two --quiet --reporter human
  )

  # --silent
  add_test (NAME "sample-test-reporter-human-silent"
            COMMAND sample-test one two --silent --reporter human
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_native_test_executable (unit-test)
  target_link_native_test_libraries (unit-test tests::unit)

  if (XPACK_ENABLE_COVERAGE)
    add_compile_coverage_private_options (unit-test)
    add_link_coverage_private_options (unit-test)
  endif ()

  message (VERBOSE "A> unit-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose

  add_test (NAME "unit-test-reporter-tap-verbose"
            COMMAND unit-test --verbose --reporter tap --output-file
                    unit-test-verbose.tap
  )

  if (XPACK_ENABLE_COVERAGE)
    set_tests_properties (
      "unit-test-reporter-tap-verbose"
      PROPERTIES ENVIRONMENT
                 "LLVM_PROFILE_FILE=unit-test-reporter-tap-verbose.profraw"
    )

    add_test (
      NAME "unit-test-reporter-tap-verbose-coverage"
      COMMAND bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/show-coverage.sh"
              unit-test unit-test-reporter-tap-verbose
    )
    set_tests_properties (
      "unit-test-reporter-tap-verbose-coverage"
      PROPERTIES DEPENDS "unit-test-reporter-tap-verbose"
    )
  endif ()

  add_compare_files_test (
    NAME "unit-test-reporter-tap-verbose-compare"
    DEPENDS "unit-test-reporter-tap-verbose"
    FILES "unit-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )

  # default
  add_test (NAME "unit-test-reporter-tap" COMMAND unit-test --reporter tap)

  # --quiet
  add_test (NAME "unit-test-reporter-tap-quiet"
            COMMAND unit-test --quiet --reporter tap --output-file
                    unit-test-quiet.tap
  )

  add_compare_files_test (
    NAME "unit-test-reporter-tap-quiet-compare"
    DEPENDS "unit-test-reporter-tap-quiet"
    FILES "unit-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )

  # --silent
  add_test (NAME "unit-test-reporter-tap-silent"
            COMMAND unit-test --silent --reporter tap --output-file
                    unit-test-silent.tap
  )

  add_compare_files_test (
    NAME "unit-test-reporter-tap-silent-compare"
    DEPENDS "unit-test-reporter-tap-silent"
    FILES "unit-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "unit-test-reporter-human-verbose" COMMAND unit-test --verbose
                                                            --reporter human
  )

  # default
  add_test (NAME "unit-test-reporter-human" COMMAND unit-test --reporter human
                                                    --output-file unit-test.txt
  )

  add_compare_files_test (
    NAME "unit-test-reporter-human-compare"
    DEPENDS "unit-test-reporter-human"
    FILES "unit-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/unit-test.txt"
  )

  # --quiet
  add_test (NAME "unit-test-reporter-human-quiet" COMMAND unit-test --quiet
                                                          --reporter human
  )

  # --silent
  add_test (NAME "unit-test-reporter-human-silent" COMMAND unit-test --silent
                                                           --reporter human
  )
endif ()

# -----------------------------------------------------------------------------

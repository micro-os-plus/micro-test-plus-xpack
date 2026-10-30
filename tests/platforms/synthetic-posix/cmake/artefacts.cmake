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

if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND CMAKE_CXX_COMPILER_ID STREQUAL
                                          "AppleClang"
)
  # Enable it temporarily to check the coverage on macOS.
  set (XPACK_ENABLE_COVERAGE false)
endif ()

# The libraries are compiled before the platform library, so they need to get
# the same compile options.
prepend_compile_common_private_options (
  micro-os-plus-micro-test-plus-static-library
)

if (XPACK_ENABLE_COVERAGE)
  add_compile_coverage_private_options (
    micro-os-plus-micro-test-plus-static-library
  )
endif ()

# -----------------------------------------------------------------------------

# The TAP validator is a Node.js script, using the `tap-parser` package from the
# tests `node_modules`.
find_program (NODE_EXECUTABLE NAMES node REQUIRED)

# add_validate_tap_test(NAME <validate-name> DEPENDS <depends-name> FILE
# <tap-file>)
#
# Registers a test named <validate-name>, which runs validate-tap.mjs to check
# that <tap-file> is well-formed TAP 14. The test depends on <depends-name>.

function (add_validate_tap_test)

  cmake_parse_arguments (PARSE_ARGV 0 arg "" "NAME;DEPENDS;FILE" "")

  add_test (
    NAME "${arg_NAME}"
    COMMAND "${NODE_EXECUTABLE}" "${CMAKE_SOURCE_DIR}/scripts/validate-tap.mjs"
            "${arg_FILE}"
  )

  set_tests_properties ("${arg_NAME}" PROPERTIES DEPENDS "${arg_DEPENDS}")

  message (VERBOSE "T> ${arg_NAME}")

endfunction ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_native_test_executable (empty-test)
  target_link_native_test_libraries (empty-test test::empty)

  xpack_display_target_lists (empty-test)
  message (VERBOSE "A> empty-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "empty-test-verbose"
            COMMAND empty-test --output-file=empty-test-verbose.tap --verbose
                    one two
  )
  message (VERBOSE "T> empty-test-verbose")

  add_compare_files_test (
    NAME "empty-test-verbose-compare"
    DEPENDS "empty-test-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/empty-test.tap"
  )
  add_validate_tap_test (
    NAME "empty-test-verbose-validate" DEPENDS "empty-test-verbose" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/empty-test-verbose.tap"
  )

  # default
  add_test (NAME "empty-test" COMMAND empty-test --output-file=empty-test.tap
                                      one two
  )
  message (VERBOSE "T> empty-test")
  add_compare_files_test (
    NAME "empty-test-compare"
    DEPENDS "empty-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/empty-test.tap"
  )
  add_validate_tap_test (
    NAME "empty-test-validate" DEPENDS "empty-test" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/empty-test.tap"
  )

  # --quiet
  add_test (NAME "empty-test-quiet"
            COMMAND empty-test --output-file=empty-test-quiet.tap --quiet one
                    two
  )
  message (VERBOSE "T> empty-test-quiet")
  add_compare_files_test (
    NAME "empty-test-quiet-compare"
    DEPENDS "empty-test-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/empty-test.tap"
  )
  add_validate_tap_test (
    NAME "empty-test-quiet-validate" DEPENDS "empty-test-quiet" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/empty-test-quiet.tap"
  )

  # --silent
  add_test (NAME "empty-test-silent"
            COMMAND empty-test --output-file=empty-test-silent.tap --silent one
                    two
  )
  message (VERBOSE "T> empty-test-silent")
  add_compare_files_test (
    NAME "empty-test-silent-compare"
    DEPENDS "empty-test-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/empty-test.tap"
  )
  add_validate_tap_test (
    NAME "empty-test-silent-validate" DEPENDS "empty-test-silent" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/empty-test-silent.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "empty-test-reporter-human-verbose"
            COMMAND empty-test --reporter=human
                    --output-file=empty-test-verbose.txt --verbose one two
  )
  message (VERBOSE "T> empty-test-reporter-human-verbose")
  add_compare_files_test (
    NAME "empty-test-reporter-human-verbose-compare"
    DEPENDS "empty-test-reporter-human-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-verbose.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/empty-test.txt"
  )

  # default
  add_test (NAME "empty-test-reporter-human"
            COMMAND empty-test --reporter=human --output-file=empty-test.txt
                    one two
  )
  message (VERBOSE "T> empty-test-reporter-human")
  add_compare_files_test (
    NAME "empty-test-reporter-human-compare"
    DEPENDS "empty-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/empty-test.txt"
  )

  # --quiet
  add_test (NAME "empty-test-reporter-human-quiet"
            COMMAND empty-test --reporter=human
                    --output-file=empty-test-quiet.txt --quiet one two
  )
  message (VERBOSE "T> empty-test-reporter-human-quiet")
  add_compare_files_test (
    NAME "empty-test-reporter-human-quiet-compare"
    DEPENDS "empty-test-reporter-human-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-quiet.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/empty-test.txt"
  )

  # --silent
  add_test (NAME "empty-test-reporter-human-silent"
            COMMAND empty-test --reporter=human
                    --output-file=empty-test-silent.txt --silent one two
  )
  message (VERBOSE "T> empty-test-reporter-human-silent")
  add_compare_files_test (
    NAME "empty-test-reporter-human-silent-compare"
    DEPENDS "empty-test-reporter-human-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-silent.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/empty-test.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_MINIMAL_TEST)
  add_native_test_executable (minimal-test)
  target_link_native_test_libraries (minimal-test test::minimal)

  # Only for this test, always define the trace macros, to check if the tracing
  # support compiles  correctly.
  target_compile_definitions (
    minimal-test
    PRIVATE MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_CONSTRUCTORS_ENABLED
            MICRO_OS_PLUS_MICRO_TEST_PLUS_TRACE_ENABLED
  )

  xpack_display_target_lists (minimal-test)
  message (VERBOSE "A> minimal-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "minimal-test-verbose"
            COMMAND minimal-test --output-file=minimal-test-verbose.tap
                    --verbose one two
  )
  message (VERBOSE "T> minimal-test-verbose")

  add_compare_files_test (
    NAME "minimal-test-verbose-compare"
    DEPENDS "minimal-test-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/minimal-test.tap"
  )
  add_validate_tap_test (
    NAME "minimal-test-verbose-validate" DEPENDS "minimal-test-verbose" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-verbose.tap"
  )

  # default
  add_test (NAME "minimal-test" COMMAND minimal-test
                                        --output-file=minimal-test.tap one two
  )
  message (VERBOSE "T> minimal-test")
  add_compare_files_test (
    NAME "minimal-test-compare"
    DEPENDS "minimal-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/minimal-test.tap"
  )
  add_validate_tap_test (
    NAME "minimal-test-validate" DEPENDS "minimal-test" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/minimal-test.tap"
  )

  # --quiet
  add_test (NAME "minimal-test-quiet"
            COMMAND minimal-test --output-file=minimal-test-quiet.tap --quiet
                    one two
  )
  message (VERBOSE "T> minimal-test-quiet")
  add_compare_files_test (
    NAME "minimal-test-quiet-compare"
    DEPENDS "minimal-test-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/minimal-test.tap"
  )
  add_validate_tap_test (
    NAME "minimal-test-quiet-validate" DEPENDS "minimal-test-quiet" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-quiet.tap"
  )

  # --silent
  add_test (NAME "minimal-test-silent"
            COMMAND minimal-test --output-file=minimal-test-silent.tap --silent
                    one two
  )
  message (VERBOSE "T> minimal-test-silent")
  add_compare_files_test (
    NAME "minimal-test-silent-compare"
    DEPENDS "minimal-test-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/minimal-test.tap"
  )
  add_validate_tap_test (
    NAME "minimal-test-silent-validate" DEPENDS "minimal-test-silent" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-silent.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "minimal-test-reporter-human-verbose"
            COMMAND minimal-test --reporter=human
                    --output-file=minimal-test-verbose.txt --verbose one two
  )
  message (VERBOSE "T> minimal-test-reporter-human-verbose")
  add_compare_files_test (
    NAME "minimal-test-reporter-human-verbose-compare"
    DEPENDS "minimal-test-reporter-human-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-verbose.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/minimal-test.txt"
  )

  # default
  add_test (NAME "minimal-test-reporter-human"
            COMMAND minimal-test --reporter=human
                    --output-file=minimal-test.txt one two
  )
  message (VERBOSE "T> minimal-test-reporter-human")
  add_compare_files_test (
    NAME "minimal-test-reporter-human-compare"
    DEPENDS "minimal-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/minimal-test.txt"
  )

  # --quiet
  add_test (NAME "minimal-test-reporter-human-quiet"
            COMMAND minimal-test --reporter=human
                    --output-file=minimal-test-quiet.txt --quiet one two
  )
  message (VERBOSE "T> minimal-test-reporter-human-quiet")
  add_compare_files_test (
    NAME "minimal-test-reporter-human-quiet-compare"
    DEPENDS "minimal-test-reporter-human-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-quiet.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/minimal-test.txt"
  )

  # --silent
  add_test (NAME "minimal-test-reporter-human-silent"
            COMMAND minimal-test --reporter=human
                    --output-file=minimal-test-silent.txt --silent one two
  )
  message (VERBOSE "T> minimal-test-reporter-human-silent")
  add_compare_files_test (
    NAME "minimal-test-reporter-human-silent-compare"
    DEPENDS "minimal-test-reporter-human-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-silent.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/minimal-test.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_native_test_executable (suite-test)
  target_link_native_test_libraries (suite-test test::suite)

  xpack_display_target_lists (suite-test)
  message (VERBOSE "A> suite-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "suite-test-verbose"
            COMMAND suite-test --output-file=suite-test-verbose.tap --verbose
                    one two
  )
  message (VERBOSE "T> suite-test-verbose")

  add_compare_files_test (
    NAME "suite-test-verbose-compare"
    DEPENDS "suite-test-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/suite-test.tap"
  )
  add_validate_tap_test (
    NAME "suite-test-verbose-validate" DEPENDS "suite-test-verbose" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/suite-test-verbose.tap"
  )

  # default
  add_test (NAME "suite-test" COMMAND suite-test --output-file=suite-test.tap
                                      one two
  )
  message (VERBOSE "T> suite-test")
  add_compare_files_test (
    NAME "suite-test-compare"
    DEPENDS "suite-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/suite-test.tap"
  )
  add_validate_tap_test (
    NAME "suite-test-validate" DEPENDS "suite-test" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/suite-test.tap"
  )

  # --quiet
  add_test (NAME "suite-test-quiet"
            COMMAND suite-test --output-file=suite-test-quiet.tap --quiet one
                    two
  )
  message (VERBOSE "T> suite-test-quiet")
  add_compare_files_test (
    NAME "suite-test-quiet-compare"
    DEPENDS "suite-test-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/suite-test.tap"
  )
  add_validate_tap_test (
    NAME "suite-test-quiet-validate" DEPENDS "suite-test-quiet" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/suite-test-quiet.tap"
  )

  # --silent
  add_test (NAME "suite-test-silent"
            COMMAND suite-test --output-file=suite-test-silent.tap --silent one
                    two
  )
  message (VERBOSE "T> suite-test-silent")
  add_compare_files_test (
    NAME "suite-test-silent-compare"
    DEPENDS "suite-test-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/suite-test.tap"
  )
  add_validate_tap_test (
    NAME "suite-test-silent-validate" DEPENDS "suite-test-silent" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/suite-test-silent.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "suite-test-reporter-human-verbose"
            COMMAND suite-test --reporter=human
                    --output-file=suite-test-verbose.txt --verbose one two
  )
  message (VERBOSE "T> suite-test-reporter-human-verbose")
  add_compare_files_test (
    NAME "suite-test-reporter-human-verbose-compare"
    DEPENDS "suite-test-reporter-human-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-verbose.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/suite-test.txt"
  )

  # default
  add_test (NAME "suite-test-reporter-human"
            COMMAND suite-test --reporter=human --output-file=suite-test.txt
                    one two
  )
  message (VERBOSE "T> suite-test-reporter-human")
  add_compare_files_test (
    NAME "suite-test-reporter-human-compare"
    DEPENDS "suite-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/suite-test.txt"
  )

  # --quiet
  add_test (NAME "suite-test-reporter-human-quiet"
            COMMAND suite-test --reporter=human
                    --output-file=suite-test-quiet.txt --quiet one two
  )
  message (VERBOSE "T> suite-test-reporter-human-quiet")
  add_compare_files_test (
    NAME "suite-test-reporter-human-quiet-compare"
    DEPENDS "suite-test-reporter-human-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-quiet.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/suite-test.txt"
  )

  # --silent
  add_test (NAME "suite-test-reporter-human-silent"
            COMMAND suite-test --reporter=human
                    --output-file=suite-test-silent.txt --silent one two
  )
  message (VERBOSE "T> suite-test-reporter-human-silent")
  add_compare_files_test (
    NAME "suite-test-reporter-human-silent-compare"
    DEPENDS "suite-test-reporter-human-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-silent.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/suite-test.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_native_test_executable (sample-test)
  target_link_native_test_libraries (sample-test test::sample)

  xpack_display_target_lists (sample-test)
  message (VERBOSE "A> sample-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "sample-test-verbose"
            COMMAND sample-test --output-file=sample-test-verbose.tap --verbose
                    one two
  )
  message (VERBOSE "T> sample-test-verbose")

  add_compare_files_test (
    NAME "sample-test-verbose-compare"
    DEPENDS "sample-test-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/sample-test.tap"
  )
  add_validate_tap_test (
    NAME "sample-test-verbose-validate" DEPENDS "sample-test-verbose" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/sample-test-verbose.tap"
  )

  # default
  add_test (NAME "sample-test" COMMAND sample-test
                                       --output-file=sample-test.tap one two
  )
  message (VERBOSE "T> sample-test")
  add_compare_files_test (
    NAME "sample-test-compare"
    DEPENDS "sample-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/sample-test.tap"
  )
  add_validate_tap_test (
    NAME "sample-test-validate" DEPENDS "sample-test" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/sample-test.tap"
  )

  # --quiet
  add_test (NAME "sample-test-quiet"
            COMMAND sample-test --output-file=sample-test-quiet.tap --quiet one
                    two
  )
  # The console must show one line per suite, counted by the plan, which was
  # previously 1..0 (the exit code is checked by "sample-test").
  set_tests_properties (
    "sample-test-quiet"
    PROPERTIES PASS_REGULAR_EXPRESSION
               "\nok 4 - Implicit namespace suite # [^\n]*\n1\\.\\.4\r?\n"
  )
  message (VERBOSE "T> sample-test-quiet")
  add_compare_files_test (
    NAME "sample-test-quiet-compare"
    DEPENDS "sample-test-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/sample-test.tap"
  )
  add_validate_tap_test (
    NAME "sample-test-quiet-validate" DEPENDS "sample-test-quiet" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/sample-test-quiet.tap"
  )

  # --silent
  add_test (NAME "sample-test-silent"
            COMMAND sample-test --output-file=sample-test-silent.tap --silent
                    one two
  )
  message (VERBOSE "T> sample-test-silent")
  add_compare_files_test (
    NAME "sample-test-silent-compare"
    DEPENDS "sample-test-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/sample-test.tap"
  )
  add_validate_tap_test (
    NAME "sample-test-silent-validate" DEPENDS "sample-test-silent" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/sample-test-silent.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "sample-test-reporter-human-verbose"
            COMMAND sample-test --reporter=human
                    --output-file=sample-test-verbose.txt --verbose one two
  )
  message (VERBOSE "T> sample-test-reporter-human-verbose")
  add_compare_files_test (
    NAME "sample-test-reporter-human-verbose-compare"
    DEPENDS "sample-test-reporter-human-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-verbose.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/sample-test.txt"
  )

  # default
  add_test (NAME "sample-test-reporter-human"
            COMMAND sample-test --reporter=human --output-file=sample-test.txt
                    one two
  )
  message (VERBOSE "T> sample-test-reporter-human")
  add_compare_files_test (
    NAME "sample-test-reporter-human-compare"
    DEPENDS "sample-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/sample-test.txt"
  )

  # --quiet
  add_test (NAME "sample-test-reporter-human-quiet"
            COMMAND sample-test --reporter=human
                    --output-file=sample-test-quiet.txt --quiet one two
  )
  message (VERBOSE "T> sample-test-reporter-human-quiet")
  add_compare_files_test (
    NAME "sample-test-reporter-human-quiet-compare"
    DEPENDS "sample-test-reporter-human-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-quiet.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/sample-test.txt"
  )

  # --silent
  add_test (NAME "sample-test-reporter-human-silent"
            COMMAND sample-test --reporter=human
                    --output-file=sample-test-silent.txt --silent one two
  )
  message (VERBOSE "T> sample-test-reporter-human-silent")
  add_compare_files_test (
    NAME "sample-test-reporter-human-silent-compare"
    DEPENDS "sample-test-reporter-human-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-silent.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/sample-test.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_STATIC_ASSERTS_TEST)
  add_native_test_executable (unit-static-asserts-test)
  target_link_native_test_libraries (
    unit-static-asserts-test test::unit-static-asserts
  )

  xpack_display_target_lists (unit-static-asserts-test)
  message (VERBOSE "A> unit-static-asserts-test")

  add_test (NAME "unit-static-asserts-test" COMMAND unit-static-asserts-test
                                                    one two
  )
  message (VERBOSE "T> unit-static-asserts-test")
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_CHECKS_TEST)
  add_native_test_executable (unit-checks-test)
  target_link_native_test_libraries (unit-checks-test test::unit-checks)

  if (XPACK_ENABLE_COVERAGE)
    add_compile_coverage_private_options (unit-checks-test)
    add_link_coverage_private_options (unit-checks-test)
  endif ()

  xpack_display_target_lists (unit-checks-test)
  message (VERBOSE "A> unit-checks-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "unit-checks-test-verbose"
            COMMAND unit-checks-test --output-file=unit-checks-test-verbose.tap
                    --verbose one two
  )
  message (VERBOSE "T> unit-checks-test-verbose")

  if (XPACK_ENABLE_COVERAGE)
    set_tests_properties (
      "unit-checks-test-verbose"
      PROPERTIES ENVIRONMENT
                 "LLVM_PROFILE_FILE=unit-checks-test-verbose.profraw"
    )

    add_test (
      NAME "unit-checks-test-verbose-coverage"
      COMMAND bash "${CMAKE_CURRENT_SOURCE_DIR}/scripts/show-coverage.sh"
              unit-checks-test unit-checks-test-verbose
    )
    message (VERBOSE "T> unit-checks-test-verbose-coverage")
    set_tests_properties (
      "unit-checks-test-verbose-coverage" PROPERTIES DEPENDS
                                                     "unit-checks-test-verbose"
    )
  endif ()

  add_compare_files_test (
    NAME "unit-checks-test-verbose-compare"
    DEPENDS "unit-checks-test-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-checks-test.tap"
  )
  add_validate_tap_test (
    NAME "unit-checks-test-verbose-validate" DEPENDS "unit-checks-test-verbose"
    FILE "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-verbose.tap"
  )

  # default
  add_test (NAME "unit-checks-test"
            COMMAND unit-checks-test --output-file=unit-checks-test.tap one two
  )
  message (VERBOSE "T> unit-checks-test")
  add_compare_files_test (
    NAME "unit-checks-test-compare"
    DEPENDS "unit-checks-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-checks-test.tap"
  )
  add_validate_tap_test (
    NAME "unit-checks-test-validate" DEPENDS "unit-checks-test" FILE
    "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test.tap"
  )

  # --quiet
  add_test (NAME "unit-checks-test-quiet"
            COMMAND unit-checks-test --output-file=unit-checks-test-quiet.tap
                    --quiet one two
  )
  message (VERBOSE "T> unit-checks-test-quiet")
  add_compare_files_test (
    NAME "unit-checks-test-quiet-compare"
    DEPENDS "unit-checks-test-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-checks-test.tap"
  )
  add_validate_tap_test (
    NAME "unit-checks-test-quiet-validate" DEPENDS "unit-checks-test-quiet"
    FILE "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-quiet.tap"
  )

  # --silent
  add_test (NAME "unit-checks-test-silent"
            COMMAND unit-checks-test --output-file=unit-checks-test-silent.tap
                    --silent one two
  )
  message (VERBOSE "T> unit-checks-test-silent")
  add_compare_files_test (
    NAME "unit-checks-test-silent-compare"
    DEPENDS "unit-checks-test-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-checks-test.tap"
  )
  add_validate_tap_test (
    NAME "unit-checks-test-silent-validate" DEPENDS "unit-checks-test-silent"
    FILE "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-silent.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (
    NAME "unit-checks-test-reporter-human-verbose"
    COMMAND unit-checks-test --reporter=human
            --output-file=unit-checks-test-verbose.txt --verbose one two
  )
  message (VERBOSE "T> unit-checks-test-reporter-human-verbose")
  add_compare_files_test (
    NAME "unit-checks-test-reporter-human-verbose-compare"
    DEPENDS "unit-checks-test-reporter-human-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-verbose.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-checks-test.txt"
  )

  # --verbose --color The output file never receives colours, so the console
  # output is captured instead.
  add_test (
    NAME "unit-checks-test-reporter-human-colour"
    COMMAND
      "${CMAKE_COMMAND}" -D "EXECUTABLE=$<TARGET_FILE:unit-checks-test>" -D
      "OUTPUT=unit-checks-test-colour.txt" -P
      "${CMAKE_CURRENT_LIST_DIR}/capture-stdout.cmake" -- --reporter human
      --color --verbose one two
  )
  message (VERBOSE "T> unit-checks-test-reporter-human-colour")
  add_compare_files_test (
    NAME "unit-checks-test-reporter-human-colour-compare"
    DEPENDS "unit-checks-test-reporter-human-colour"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-colour.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-checks-test-colour.txt"
  )

  # The console output with the normal verbosity differs from the output file:
  # the passed test cases are single lines, and the names of the outer test
  # cases precede the nested ones.
  add_test (
    NAME "unit-checks-test-reporter-human-console"
    COMMAND
      "${CMAKE_COMMAND}" -D "EXECUTABLE=$<TARGET_FILE:unit-checks-test>" -D
      "OUTPUT=unit-checks-test-console.txt" -P
      "${CMAKE_CURRENT_LIST_DIR}/capture-stdout.cmake" -- --reporter human one
      two
  )
  message (VERBOSE "T> unit-checks-test-reporter-human-console")
  add_compare_files_test (
    NAME "unit-checks-test-reporter-human-console-compare"
    DEPENDS "unit-checks-test-reporter-human-console"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-console.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-checks-test-console.txt"
  )

  # --quiet The console output shows only the failed checks, with the names of
  # the enclosing suite and test cases, and the totals.
  add_test (
    NAME "unit-checks-test-reporter-human-console-quiet"
    COMMAND
      "${CMAKE_COMMAND}" -D "EXECUTABLE=$<TARGET_FILE:unit-checks-test>" -D
      "OUTPUT=unit-checks-test-console-quiet.txt" -P
      "${CMAKE_CURRENT_LIST_DIR}/capture-stdout.cmake" -- --reporter human
      --quiet one two
  )
  message (VERBOSE "T> unit-checks-test-reporter-human-console-quiet")
  add_compare_files_test (
    NAME "unit-checks-test-reporter-human-console-quiet-compare"
    DEPENDS "unit-checks-test-reporter-human-console-quiet"
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-console-quiet.txt"
      "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-checks-test-console-quiet.txt"
  )

  # The TAP console output with the normal verbosity; unlike the output file,
  # the passed test cases are single test points, and the failed ones are
  # complete blocks.
  add_test (
    NAME "unit-checks-test-console"
    COMMAND
      "${CMAKE_COMMAND}" -D "EXECUTABLE=$<TARGET_FILE:unit-checks-test>" -D
      "OUTPUT=unit-checks-test-console.tap" -P
      "${CMAKE_CURRENT_LIST_DIR}/capture-stdout.cmake" -- one two
  )
  message (VERBOSE "T> unit-checks-test-console")
  add_compare_files_test (
    NAME "unit-checks-test-console-compare"
    DEPENDS "unit-checks-test-console"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-console.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-checks-test-console.tap"
  )

  # --quiet The TAP console output has the suites as single test points, and the
  # failed checks as comments.
  add_test (
    NAME "unit-checks-test-console-quiet"
    COMMAND
      "${CMAKE_COMMAND}" -D "EXECUTABLE=$<TARGET_FILE:unit-checks-test>" -D
      "OUTPUT=unit-checks-test-console-quiet.tap" -P
      "${CMAKE_CURRENT_LIST_DIR}/capture-stdout.cmake" -- --quiet one two
  )
  message (VERBOSE "T> unit-checks-test-console-quiet")
  add_compare_files_test (
    NAME "unit-checks-test-console-quiet-compare"
    DEPENDS "unit-checks-test-console-quiet"
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-console-quiet.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-checks-test-console-quiet.tap"
  )

  # default
  add_test (NAME "unit-checks-test-reporter-human"
            COMMAND unit-checks-test --reporter=human
                    --output-file=unit-checks-test.txt one two
  )
  message (VERBOSE "T> unit-checks-test-reporter-human")
  add_compare_files_test (
    NAME "unit-checks-test-reporter-human-compare"
    DEPENDS "unit-checks-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-checks-test.txt"
  )

  # --quiet
  add_test (NAME "unit-checks-test-reporter-human-quiet"
            COMMAND unit-checks-test --reporter=human
                    --output-file=unit-checks-test-quiet.txt --quiet one two
  )
  message (VERBOSE "T> unit-checks-test-reporter-human-quiet")
  add_compare_files_test (
    NAME "unit-checks-test-reporter-human-quiet-compare"
    DEPENDS "unit-checks-test-reporter-human-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-quiet.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-checks-test.txt"
  )

  # --silent
  add_test (NAME "unit-checks-test-reporter-human-silent"
            COMMAND unit-checks-test --reporter=human
                    --output-file=unit-checks-test-silent.txt --silent one two
  )
  message (VERBOSE "T> unit-checks-test-reporter-human-silent")
  add_compare_files_test (
    NAME "unit-checks-test-reporter-human-silent-compare"
    DEPENDS "unit-checks-test-reporter-human-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-silent.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-checks-test.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_COMBINATIONS_TEST)
  add_native_test_executable (unit-combinations-test)
  target_link_native_test_libraries (
    unit-combinations-test test::unit-combinations
  )

  xpack_display_target_lists (unit-combinations-test)
  message (VERBOSE "A> unit-combinations-test")

  add_test (NAME "unit-combinations-test"
            COMMAND unit-combinations-test
                    --output-file=unit-combinations-test.tap one two
  )
  message (VERBOSE "T> unit-combinations-test")
  add_compare_files_test (
    NAME "unit-combinations-test-compare"
    DEPENDS "unit-combinations-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-combinations-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-combinations-test.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_EXCEPTIONS_TEST)
  add_native_test_executable (unit-exceptions-test)
  target_link_native_test_libraries (unit-exceptions-test test::unit-exceptions)

  xpack_display_target_lists (unit-exceptions-test)
  message (VERBOSE "A> unit-exceptions-test")

  add_test (NAME "unit-exceptions-test"
            COMMAND unit-exceptions-test --output-file=unit-exceptions-test.tap
                    one two
  )
  message (VERBOSE "T> unit-exceptions-test")
  add_compare_files_test (
    NAME "unit-exceptions-test-compare"
    DEPENDS "unit-exceptions-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-exceptions-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-exceptions-test.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_MISCELLANEOUS_TEST)
  add_native_test_executable (unit-miscellaneous-test)
  target_link_native_test_libraries (
    unit-miscellaneous-test test::unit-miscellaneous
  )

  xpack_display_target_lists (unit-miscellaneous-test)
  message (VERBOSE "A> unit-miscellaneous-test")

  add_test (NAME "unit-miscellaneous-test"
            COMMAND unit-miscellaneous-test
                    --output-file=unit-miscellaneous-test.tap one two
  )
  message (VERBOSE "T> unit-miscellaneous-test")
  add_compare_files_test (
    NAME "unit-miscellaneous-test-compare"
    DEPENDS "unit-miscellaneous-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-miscellaneous-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-miscellaneous-test.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_DEPRECATED_TEST)
  add_native_test_executable (unit-deprecated-test)
  target_link_native_test_libraries (unit-deprecated-test test::unit-deprecated)

  xpack_display_target_lists (unit-deprecated-test)
  message (VERBOSE "A> unit-deprecated-test")

  add_test (NAME "unit-deprecated-test"
            COMMAND unit-deprecated-test --output-file=unit-deprecated-test.tap
                    one two
  )
  message (VERBOSE "T> unit-deprecated-test")
  add_compare_files_test (
    NAME "unit-deprecated-test-compare"
    DEPENDS "unit-deprecated-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-deprecated-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-deprecated-test.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

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

# -----------------------------------------------------------------------------

if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND CMAKE_CXX_COMPILER_ID STREQUAL
                                          "AppleClang"
)
  # Enable it temporarily to check the coverage on macOS.
  set (XPACK_ENABLE_COVERAGE true)
endif ()

# The libraries are compiled before the platform library, so they need to get
# the same compile options.
add_compile_common_private_options (
  micro-os-plus-micro-test-plus-static-library
)

if (XPACK_ENABLE_COVERAGE)
  add_compile_coverage_private_options (
    micro-os-plus-micro-test-plus-static-library
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_native_test_executable (empty-test)
  target_link_native_test_libraries (empty-test tests::empty)

  xpack_display_target_lists (empty-test)
  message (VERBOSE "A> empty-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "empty-test-verbose" COMMAND empty-test one two --output-file
                                              empty-test-verbose.tap --verbose
  )

  add_compare_files_test (
    NAME "empty-test-verbose-compare"
    DEPENDS "empty-test-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )

  # default
  add_test (NAME "empty-test" COMMAND empty-test one two --output-file
                                      empty-test.tap
  )
  add_compare_files_test (
    NAME "empty-test-compare"
    DEPENDS "empty-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )

  # --quiet
  add_test (NAME "empty-test-quiet" COMMAND empty-test one two --output-file
                                            empty-test-quiet.tap --quiet
  )
  add_compare_files_test (
    NAME "empty-test-quiet-compare"
    DEPENDS "empty-test-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )

  # --silent
  add_test (NAME "empty-test-silent" COMMAND empty-test one two --output-file
                                             empty-test-silent.tap --silent
  )
  add_compare_files_test (
    NAME "empty-test-silent-compare"
    DEPENDS "empty-test-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/empty-test.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "empty-test-reporter-human-verbose"
            COMMAND empty-test one two --reporter human --output-file
                    empty-test-verbose.txt --verbose
  )
  add_compare_files_test (
    NAME "empty-test-reporter-human-verbose-compare"
    DEPENDS "empty-test-reporter-human-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-verbose.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/empty-test.txt"
  )

  # default
  add_test (NAME "empty-test-reporter-human"
            COMMAND empty-test one two --reporter human --output-file
                    empty-test.txt
  )
  add_compare_files_test (
    NAME "empty-test-reporter-human-compare"
    DEPENDS "empty-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/empty-test.txt"
  )

  # --quiet
  add_test (NAME "empty-test-reporter-human-quiet"
            COMMAND empty-test one two --reporter human --output-file
                    empty-test-quiet.txt --quiet
  )
  add_compare_files_test (
    NAME "empty-test-reporter-human-quiet-compare"
    DEPENDS "empty-test-reporter-human-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-quiet.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/empty-test-quiet.txt"
  )

  # --silent
  add_test (NAME "empty-test-reporter-human-silent"
            COMMAND empty-test one two --reporter human --output-file
                    empty-test-silent.txt --silent
  )
  add_compare_files_test (
    NAME "empty-test-reporter-human-silent-compare"
    DEPENDS "empty-test-reporter-human-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-silent.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/empty-test-silent.txt"
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

  xpack_display_target_lists (minimal-test)
  message (VERBOSE "A> minimal-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "minimal-test-verbose"
            COMMAND minimal-test one two --output-file minimal-test-verbose.tap
                    --verbose
  )

  add_compare_files_test (
    NAME "minimal-test-verbose-compare"
    DEPENDS "minimal-test-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )

  # default
  add_test (NAME "minimal-test" COMMAND minimal-test one two --output-file
                                        minimal-test.tap
  )
  add_compare_files_test (
    NAME "minimal-test-compare"
    DEPENDS "minimal-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )

  # --quiet
  add_test (NAME "minimal-test-quiet"
            COMMAND minimal-test one two --output-file minimal-test-quiet.tap
                    --quiet
  )
  add_compare_files_test (
    NAME "minimal-test-quiet-compare"
    DEPENDS "minimal-test-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )

  # --silent
  add_test (NAME "minimal-test-silent"
            COMMAND minimal-test one two --output-file minimal-test-silent.tap
                    --silent
  )
  add_compare_files_test (
    NAME "minimal-test-silent-compare"
    DEPENDS "minimal-test-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/minimal-test.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "minimal-test-reporter-human-verbose"
            COMMAND minimal-test one two --reporter human --output-file
                    minimal-test-verbose.txt --verbose
  )
  add_compare_files_test (
    NAME "minimal-test-reporter-human-verbose-compare"
    DEPENDS "minimal-test-reporter-human-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-verbose.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/minimal-test.txt"
  )

  # default
  add_test (NAME "minimal-test-reporter-human"
            COMMAND minimal-test one two --reporter human --output-file
                    minimal-test.txt
  )
  add_compare_files_test (
    NAME "minimal-test-reporter-human-compare"
    DEPENDS "minimal-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/minimal-test.txt"
  )

  # --quiet
  add_test (NAME "minimal-test-reporter-human-quiet"
            COMMAND minimal-test one two --reporter human --output-file
                    minimal-test-quiet.txt --quiet
  )
  add_compare_files_test (
    NAME "minimal-test-reporter-human-quiet-compare"
    DEPENDS "minimal-test-reporter-human-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-quiet.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/minimal-test-quiet.txt"
  )

  # --silent
  add_test (NAME "minimal-test-reporter-human-silent"
            COMMAND minimal-test one two --reporter human --output-file
                    minimal-test-silent.txt --silent
  )
  add_compare_files_test (
    NAME "minimal-test-reporter-human-silent-compare"
    DEPENDS "minimal-test-reporter-human-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-silent.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/minimal-test-silent.txt"
  )

endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_native_test_executable (suite-test)
  target_link_native_test_libraries (suite-test tests::suite)

  xpack_display_target_lists (suite-test)
  message (VERBOSE "A> suite-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "suite-test-verbose" COMMAND suite-test one two --output-file
                                              suite-test-verbose.tap --verbose
  )

  add_compare_files_test (
    NAME "suite-test-verbose-compare"
    DEPENDS "suite-test-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )

  # default
  add_test (NAME "suite-test" COMMAND suite-test one two --output-file
                                      suite-test.tap
  )
  add_compare_files_test (
    NAME "suite-test-compare"
    DEPENDS "suite-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )

  # --quiet
  add_test (NAME "suite-test-quiet" COMMAND suite-test one two --output-file
                                            suite-test-quiet.tap --quiet
  )
  add_compare_files_test (
    NAME "suite-test-quiet-compare"
    DEPENDS "suite-test-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )

  # --silent
  add_test (NAME "suite-test-silent" COMMAND suite-test one two --output-file
                                             suite-test-silent.tap --silent
  )
  add_compare_files_test (
    NAME "suite-test-silent-compare"
    DEPENDS "suite-test-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/suite-test.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "suite-test-reporter-human-verbose"
            COMMAND suite-test one two --reporter human --output-file
                    suite-test-verbose.txt --verbose
  )
  add_compare_files_test (
    NAME "suite-test-reporter-human-verbose-compare"
    DEPENDS "suite-test-reporter-human-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-verbose.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/suite-test.txt"
  )

  # default
  add_test (NAME "suite-test-reporter-human"
            COMMAND suite-test one two --reporter human --output-file
                    suite-test.txt
  )
  add_compare_files_test (
    NAME "suite-test-reporter-human-compare"
    DEPENDS "suite-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/suite-test.txt"
  )

  # --quiet
  add_test (NAME "suite-test-reporter-human-quiet"
            COMMAND suite-test one two --reporter human --output-file
                    suite-test-quiet.txt --quiet
  )
  add_compare_files_test (
    NAME "suite-test-reporter-human-quiet-compare"
    DEPENDS "suite-test-reporter-human-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-quiet.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/suite-test-quiet.txt"
  )

  # --silent
  add_test (NAME "suite-test-reporter-human-silent"
            COMMAND suite-test one two --reporter human --output-file
                    suite-test-silent.txt --silent
  )
  add_compare_files_test (
    NAME "suite-test-reporter-human-silent-compare"
    DEPENDS "suite-test-reporter-human-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-silent.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/suite-test-silent.txt"
  )

endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_native_test_executable (sample-test)
  target_link_native_test_libraries (sample-test tests::sample)

  xpack_display_target_lists (sample-test)
  message (VERBOSE "A> sample-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "sample-test-verbose"
            COMMAND sample-test one two --output-file sample-test-verbose.tap
                    --verbose
  )

  add_compare_files_test (
    NAME "sample-test-verbose-compare"
    DEPENDS "sample-test-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )

  # default
  add_test (NAME "sample-test" COMMAND sample-test one two --output-file
                                       sample-test.tap
  )
  add_compare_files_test (
    NAME "sample-test-compare"
    DEPENDS "sample-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )

  # --quiet
  add_test (NAME "sample-test-quiet" COMMAND sample-test one two --output-file
                                             sample-test-quiet.tap --quiet
  )
  add_compare_files_test (
    NAME "sample-test-quiet-compare"
    DEPENDS "sample-test-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )

  # --silent
  add_test (NAME "sample-test-silent" COMMAND sample-test one two --output-file
                                              sample-test-silent.tap --silent
  )
  add_compare_files_test (
    NAME "sample-test-silent-compare"
    DEPENDS "sample-test-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/sample-test.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "sample-test-reporter-human-verbose"
            COMMAND sample-test one two --reporter human --output-file
                    sample-test-verbose.txt --verbose
  )
  add_compare_files_test (
    NAME "sample-test-reporter-human-verbose-compare"
    DEPENDS "sample-test-reporter-human-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-verbose.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/sample-test.txt"
  )

  # default
  add_test (NAME "sample-test-reporter-human"
            COMMAND sample-test one two --reporter human --output-file
                    sample-test.txt
  )
  add_compare_files_test (
    NAME "sample-test-reporter-human-compare"
    DEPENDS "sample-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/sample-test.txt"
  )

  # --quiet
  add_test (NAME "sample-test-reporter-human-quiet"
            COMMAND sample-test one two --reporter human --output-file
                    sample-test-quiet.txt --quiet
  )
  add_compare_files_test (
    NAME "sample-test-reporter-human-quiet-compare"
    DEPENDS "sample-test-reporter-human-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-quiet.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/sample-test-quiet.txt"
  )

  # --silent
  add_test (NAME "sample-test-reporter-human-silent"
            COMMAND sample-test one two --reporter human --output-file
                    sample-test-silent.txt --silent
  )
  add_compare_files_test (
    NAME "sample-test-reporter-human-silent-compare"
    DEPENDS "sample-test-reporter-human-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-silent.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/sample-test-silent.txt"
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

  xpack_display_target_lists (unit-test)
  message (VERBOSE "A> unit-test")

  # ---------------------------------------------------------------------------
  # TAP reporter

  # --verbose
  add_test (NAME "unit-test-verbose" COMMAND unit-test one two --output-file
                                             unit-test-verbose.tap --verbose
  )

  if (XPACK_ENABLE_COVERAGE)
    set_tests_properties (
      "unit-test-verbose"
      PROPERTIES ENVIRONMENT "LLVM_PROFILE_FILE=unit-test-verbose.profraw"
    )

    add_test (
      NAME "unit-test-verbose-coverage"
      COMMAND bash "${CMAKE_CURRENT_SOURCE_DIR}/../../scripts/show-coverage.sh"
              unit-test unit-test-verbose
    )
    set_tests_properties (
      "unit-test-verbose-coverage" PROPERTIES DEPENDS "unit-test-verbose"
    )
  endif ()

  add_compare_files_test (
    NAME "unit-test-verbose-compare"
    DEPENDS "unit-test-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test-verbose.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )

  # default
  add_test (NAME "unit-test" COMMAND unit-test one two --output-file
                                     unit-test.tap
  )
  add_compare_files_test (
    NAME "unit-test-compare"
    DEPENDS "unit-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )

  # --quiet
  add_test (NAME "unit-test-quiet" COMMAND unit-test one two --output-file
                                           unit-test-quiet.tap --quiet
  )
  add_compare_files_test (
    NAME "unit-test-quiet-compare"
    DEPENDS "unit-test-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test-quiet.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )

  # --silent
  add_test (NAME "unit-test-silent" COMMAND unit-test one two --output-file
                                            unit-test-silent.tap --silent
  )
  add_compare_files_test (
    NAME "unit-test-silent-compare"
    DEPENDS "unit-test-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test-silent.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/tap/unit-test.tap"
  )

  # ---------------------------------------------------------------------------
  # Human reporter

  # --verbose
  add_test (NAME "unit-test-reporter-human-verbose"
            COMMAND unit-test one two --reporter human --output-file
                    unit-test-verbose.txt --verbose
  )
  add_compare_files_test (
    NAME "unit-test-reporter-human-verbose-compare"
    DEPENDS "unit-test-reporter-human-verbose"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test-verbose.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/unit-test.txt"
  )

  # default
  add_test (NAME "unit-test-reporter-human"
            COMMAND unit-test one two --reporter human --output-file
                    unit-test.txt
  )
  add_compare_files_test (
    NAME "unit-test-reporter-human-compare"
    DEPENDS "unit-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/unit-test.txt"
  )

  # --quiet
  add_test (NAME "unit-test-reporter-human-quiet"
            COMMAND unit-test one two --reporter human --output-file
                    unit-test-quiet.txt --quiet
  )
  add_compare_files_test (
    NAME "unit-test-reporter-human-quiet-compare"
    DEPENDS "unit-test-reporter-human-quiet"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test-quiet.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/unit-test-quiet.txt"
  )

  # --silent
  add_test (NAME "unit-test-reporter-human-silent"
            COMMAND unit-test one two --reporter human --output-file
                    unit-test-silent.txt --silent
  )
  add_compare_files_test (
    NAME "unit-test-reporter-human-silent-compare"
    DEPENDS "unit-test-reporter-human-silent"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test-silent.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/../../assets/txt/unit-test-silent.txt"
  )

endif ()

# -----------------------------------------------------------------------------

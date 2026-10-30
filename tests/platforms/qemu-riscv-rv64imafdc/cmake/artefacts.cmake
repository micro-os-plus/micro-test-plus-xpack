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

# NOTE: Exceptions are disabled.

# -----------------------------------------------------------------------------

set (XPACK_QEMU_BINARY "qemu-system-riscv64")
set (XPACK_QEMU_MACHINE_ARGS --machine virt --cpu rv64)
set (
  XPACK_QEMU_EXTRA_ARGS
  -smp
  2
  -bios
  none
  --nographic
  -d
  unimp,guest_errors
)

# The libraries are compiled before the platform library, so they need to get
# the same compile options.
prepend_compile_common_private_options (
  micro-os-plus-micro-test-plus-static-library
)

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_cross_test_executable (empty-test)
  target_link_cross_tests_libraries (empty-test test::empty)

  xpack_display_target_lists (empty-test)
  message (VERBOSE "A> empty-test")

  add_qemu_test (
    NAME "empty-test" COMMAND empty-test --output-file=empty-test-noexcept.tap
                              one two
  )
  add_compare_files_test (
    NAME "empty-test-compare"
    DEPENDS "empty-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test-noexcept.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/empty-test-noexcept.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_MINIMAL_TEST)
  add_cross_test_executable (minimal-test)
  target_link_cross_tests_libraries (minimal-test test::minimal)

  xpack_display_target_lists (minimal-test)
  message (VERBOSE "A> minimal-test")

  add_qemu_test (
    NAME "minimal-test" COMMAND minimal-test
                                --output-file=minimal-test-noexcept.tap one two
  )
  add_compare_files_test (
    NAME "minimal-test-compare"
    DEPENDS "minimal-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test-noexcept.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/minimal-test-noexcept.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_cross_test_executable (suite-test)
  target_link_cross_tests_libraries (suite-test test::suite)

  xpack_display_target_lists (suite-test)
  message (VERBOSE "A> suite-test")

  add_qemu_test (
    NAME "suite-test" COMMAND suite-test --output-file=suite-test-noexcept.tap
                              one two
  )
  add_compare_files_test (
    NAME "suite-test-compare"
    DEPENDS "suite-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test-noexcept.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/suite-test-noexcept.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_cross_test_executable (sample-test)
  target_link_cross_tests_libraries (sample-test test::sample)

  xpack_display_target_lists (sample-test)
  message (VERBOSE "A> sample-test")

  add_qemu_test (
    NAME "sample-test" COMMAND sample-test
                               --output-file=sample-test-noexcept.tap one two
  )
  add_compare_files_test (
    NAME "sample-test-compare"
    DEPENDS "sample-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test-noexcept.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/sample-test-noexcept.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_STATIC_ASSERTS_TEST)
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

  add_qemu_test (
    NAME "unit-checks-test"
    COMMAND unit-checks-test --output-file=unit-checks-test-noexcept.tap one
            two
  )
  add_compare_files_test (
    NAME "unit-checks-test-compare"
    DEPENDS "unit-checks-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-noexcept.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-checks-test-noexcept.tap"
  )

  add_qemu_test (
    NAME "unit-checks-test-reporter-human"
    COMMAND unit-checks-test --reporter=human
            --output-file=unit-checks-test-noexcept.txt one two
  )
  add_compare_files_test (
    NAME "unit-checks-test-reporter-human-compare"
    DEPENDS "unit-checks-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-checks-test-noexcept.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-checks-test-noexcept.txt"
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

  add_qemu_test (
    NAME "unit-combinations-test"
    COMMAND unit-combinations-test
            --output-file=unit-combinations-test-noexcept.tap one two
  )
  add_compare_files_test (
    NAME "unit-combinations-test-compare"
    DEPENDS "unit-combinations-test"
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/unit-combinations-test-noexcept.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-combinations-test-noexcept.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_EXCEPTIONS_TEST)
  add_cross_test_executable (unit-exceptions-test)
  target_link_cross_tests_libraries (unit-exceptions-test test::unit-exceptions)

  xpack_display_target_lists (unit-exceptions-test)
  message (VERBOSE "A> unit-exceptions-test")

  add_qemu_test (
    NAME "unit-exceptions-test"
    COMMAND unit-exceptions-test
            --output-file=unit-exceptions-test-noexcept.tap one two
  )
  add_compare_files_test (
    NAME "unit-exceptions-test-compare"
    DEPENDS "unit-exceptions-test"
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/unit-exceptions-test-noexcept.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-exceptions-test-noexcept.tap"
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

  add_qemu_test (
    NAME "unit-miscellaneous-test"
    COMMAND unit-miscellaneous-test
            --output-file=unit-miscellaneous-test-noexcept.tap one two
  )
  add_compare_files_test (
    NAME "unit-miscellaneous-test-compare"
    DEPENDS "unit-miscellaneous-test"
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/unit-miscellaneous-test-noexcept.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-miscellaneous-test-noexcept.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_DEPRECATED_TEST)
  add_cross_test_executable (unit-deprecated-test)
  target_link_cross_tests_libraries (unit-deprecated-test test::unit-deprecated)

  xpack_display_target_lists (unit-deprecated-test)
  message (VERBOSE "A> unit-deprecated-test")

  add_qemu_test (
    NAME "unit-deprecated-test"
    COMMAND unit-deprecated-test
            --output-file=unit-deprecated-test-noexcept.tap one two
  )
  add_compare_files_test (
    NAME "unit-deprecated-test-compare"
    DEPENDS "unit-deprecated-test"
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/unit-deprecated-test-noexcept.tap"
      "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-deprecated-test-noexcept.tap"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_cross_test_executable (unit-test)
  target_link_cross_tests_libraries (unit-test test::unit)

  xpack_display_target_lists (unit-test)
  message (VERBOSE "A> unit-test")

  add_qemu_test (
    NAME "unit-test" COMMAND unit-test --output-file=unit-test-noexcept.tap one
                             two
  )
  add_compare_files_test (
    NAME "unit-test-compare"
    DEPENDS "unit-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test-noexcept.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-test-noexcept.tap"
  )

  add_qemu_test (
    NAME "unit-test-reporter-human"
    COMMAND unit-test --reporter=human --output-file=unit-test-noexcept.txt one
            two
  )
  add_compare_files_test (
    NAME "unit-test-reporter-human-compare"
    DEPENDS "unit-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test-noexcept.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-test-noexcept.txt"
  )

  message (VERBOSE "") # Separator for readability
endif ()

# -----------------------------------------------------------------------------

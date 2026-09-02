# -----------------------------------------------------------------------------
# DO NOT EDIT! Automatically generated from template file:
# build-helper/templates/common/_micro-os-plus/tests/platforms/qemu-cortex-m4f/CMakeLists-liquid.txt
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

prepend_compile_common_private_options (stm32cubemx-drivers-objects-library)

# -----------------------------------------------------------------------------

set (XPACK_OPENOCD_INTERFACE "stlink-dap.cfg")
set (XPACK_OPENOCD_TARGET "stm32h5x.cfg")

function (add_openocd_test)

  cmake_parse_arguments (PARSE_ARGV 0 arg "" "NAME" "COMMAND")

  # First element is the ELF base name (argv[0] in the semihosting config).
  list (GET arg_COMMAND 0 name)

  set (semihosting_cmdline "arm semihosting_cmdline")
  foreach (a IN LISTS arg_COMMAND)
    string (APPEND semihosting_cmdline " ${a}")
  endforeach ()

  # TODO: update when upstream openocd is updated to support the H5 family.
  add_test (
    NAME "${arg_NAME}"
    COMMAND
      /Users/ilg/.local/st-openocd/bin/openocd${extension} -s
      /Users/ilg/.local/st-openocd/openocd/scripts
      # -d3
      -f "interface/${XPACK_OPENOCD_INTERFACE}" -f
      "target/${XPACK_OPENOCD_TARGET}" -c "program ${name}.elf verify" -c
      "arm semihosting enable" -c "${semihosting_cmdline}" -c "reset"
  )

endfunction ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_cross_test_executable (empty-test)
  target_link_cross_test_libraries (
    empty-test tests::empty micro-os-plus::stm32cubemx-drivers-objects-library
  )

  xpack_display_target_lists (empty-test)
  message (VERBOSE "A> empty-test")

  add_openocd_test (
    NAME
    "empty-test"
    COMMAND
    empty-test
    one
    two
    --output-file
    empty-test.tap
  )

  add_compare_files_test (
    NAME "empty-test-compare"
    DEPENDS "empty-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/empty-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/empty-test.tap"
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_MINIMAL_TEST)
  add_cross_test_executable (minimal-test)
  target_link_cross_test_libraries (
    minimal-test tests::minimal
    micro-os-plus::stm32cubemx-drivers-objects-library
  )

  xpack_display_target_lists (minimal-test)
  message (VERBOSE "A> minimal-test")

  add_openocd_test (
    NAME
    "minimal-test"
    COMMAND
    minimal-test
    one
    two
    --output-file
    minimal-test.tap
  )

  add_compare_files_test (
    NAME "minimal-test-compare"
    DEPENDS "minimal-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/minimal-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/minimal-test.tap"
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_cross_test_executable (suite-test)
  target_link_cross_test_libraries (
    suite-test tests::suite micro-os-plus::stm32cubemx-drivers-objects-library
  )

  xpack_display_target_lists (suite-test)
  message (VERBOSE "A> suite-test")

  add_openocd_test (
    NAME
    "suite-test"
    COMMAND
    suite-test
    one
    two
    --output-file
    suite-test.tap
  )

  add_compare_files_test (
    NAME "suite-test-compare"
    DEPENDS "suite-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/suite-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/suite-test.tap"
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_cross_test_executable (sample-test)
  target_link_cross_test_libraries (
    sample-test tests::sample
    micro-os-plus::stm32cubemx-drivers-objects-library
  )

  xpack_display_target_lists (sample-test)
  message (VERBOSE "A> sample-test")

  add_openocd_test (
    NAME
    "sample-test"
    COMMAND
    sample-test
    one
    two
    --output-file
    sample-test.tap
  )

  add_compare_files_test (
    NAME "sample-test-compare"
    DEPENDS "sample-test"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/sample-test.tap"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/sample-test.tap"
  )
endif ()

# -----------------------------------------------------------------------------

# if (XPACK_ENABLE_UNIT_TEST AND NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
if (XPACK_ENABLE_UNIT_TEST)
  add_cross_test_executable (unit-test)
  target_link_cross_test_libraries (
    unit-test tests::unit micro-os-plus::stm32cubemx-drivers-objects-library
  )

  xpack_display_target_lists (unit-test)
  message (VERBOSE "A> unit-test")

  # The TAP output is too verbose and takes to long to be displayed by the
  # OpenOCD semihosting.
  if (false)
    add_openocd_test (
      NAME
      "unit-test"
      COMMAND
      unit-test
      one
      two
      --output-file
      unit-test.tap
    )
    add_compare_files_test (
      NAME "unit-test-compare"
      DEPENDS "unit-test"
      FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test.tap"
            "${CMAKE_CURRENT_SOURCE_DIR}/assets/tap/unit-test.tap"
    )
  endif ()

  add_openocd_test (
    NAME
    "unit-test-reporter-human"
    COMMAND
    unit-test
    one
    two
    --reporter
    human
    --output-file
    unit-test.txt
  )
  add_compare_files_test (
    NAME "unit-test-reporter-human-compare"
    DEPENDS "unit-test-reporter-human"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/unit-test.txt"
          "${CMAKE_CURRENT_SOURCE_DIR}/assets/txt/unit-test.txt"
  )
endif ()

# -----------------------------------------------------------------------------

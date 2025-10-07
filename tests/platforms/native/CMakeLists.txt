# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2022-2025 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# Create the platform specific test executables.

# -----------------------------------------------------------------------------

message(VERBOSE "Processing 'tests/platforms/native'...")

include("cmake/platform-library.cmake")

# -----------------------------------------------------------------------------

# set(xpack_create_listing true)

# -----------------------------------------------------------------------------
function(add_test_executable name)
  add_executable(${name})

  set_target_properties(${name} PROPERTIES OUTPUT_NAME "${name}")

  # https://cmake.org/cmake/help/v3.20/manual/cmake-generator-expressions.7.html
  # The link options were defined in `platform-native-interface`.
  target_link_options(${name} PRIVATE
    $<$<PLATFORM_ID:Linux,Windows>:-Wl,-Map,platform-bin/${name}-map.txt>

    # -v
  )

  if(xpack_create_listing)
    add_custom_command(TARGET ${name} POST_BUILD

      # --all-headers -> Invalid/Unsupported object file format
      COMMAND ${CMAKE_OBJDUMP} --source --demangle --line-numbers --wide "$<TARGET_FILE:${name}>" > ${name}-list.txt
      VERBATIM
    )
  endif()
endfunction()

# -----------------------------------------------------------------------------
if(ENABLE_MINIMAL_TEST)
  add_test_executable(minimal-test)

  target_link_libraries(minimal-test PRIVATE

    micro-os-plus::common-options

    # Library with the current test.
    test::minimal

    # Tested library.
    micro-os-plus::micro-test-plus

    # Portable dependencies.
    micro-os-plus::diag-trace

    # Platform specific dependencies and common compile/link options.
    micro-os-plus::platform
  )

  message(VERBOSE "A> minimal-test")

  add_test(
    NAME "minimal-test"
    COMMAND minimal-test one two
  )

  add_test(
    NAME "minimal-test --verbose"
    COMMAND minimal-test one two --verbose
  )

  add_test(
    NAME "minimal-test --quiet"
    COMMAND minimal-test one two --quiet
  )

  add_test(
    NAME "minimal-test --silent"
    COMMAND minimal-test one two --silent
  )
endif()

# -----------------------------------------------------------------------------
if(ENABLE_SAMPLE_TEST)
  add_test_executable(sample-test)

  target_link_libraries(sample-test PRIVATE

    micro-os-plus::common-options

    # Library with the current test.
    test::sample

    # Tested library.
    micro-os-plus::micro-test-plus

    # Portable dependencies.
    micro-os-plus::diag-trace

    # Platform specific dependencies and common compile/link options.
    micro-os-plus::platform
  )

  message(VERBOSE "A> sample-test")

  add_test(
    NAME "sample-test"
    COMMAND sample-test one two
  )

  add_test(
    NAME "sample-test --verbose"
    COMMAND sample-test one two --verbose
  )

  add_test(
    NAME "sample-test --quiet"
    COMMAND sample-test one two --quiet
  )

  add_test(
    NAME "sample-test --silent"
    COMMAND sample-test one two --silent
  )
endif()

# -----------------------------------------------------------------------------
if(ENABLE_UNIT_TEST)
  add_test_executable(unit-test)

  target_link_libraries(unit-test PRIVATE

    micro-os-plus::common-options

    # Library with the current test.
    test::unit

    # Tested library.
    micro-os-plus::micro-test-plus

    # Portable dependencies.
    micro-os-plus::diag-trace

    # Platform specific dependencies and common compile/link options.
    micro-os-plus::platform
  )

  message(VERBOSE "A> unit-test")

  add_test(
    NAME "unit-test"
    COMMAND unit-test
  )

  add_test(
    NAME "unit-test --verbose"
    COMMAND unit-test --verbose
  )

  add_test(
    NAME "unit-test --quiet"
    COMMAND unit-test --quiet
  )

  add_test(
    NAME "unit-test --silent"
    COMMAND unit-test --silent
  )
endif()

# -----------------------------------------------------------------------------

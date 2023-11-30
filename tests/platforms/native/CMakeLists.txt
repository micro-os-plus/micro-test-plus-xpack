# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
# (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# Create the platform specific test executables.

# -----------------------------------------------------------------------------

message(VERBOSE "Processing 'tests/platforms/native'...")

# -----------------------------------------------------------------------------

# set(xpack_create_listing true)
set(ENABLE_MINIMAL_TEST true)

# -----------------------------------------------------------------------------
function(add_test_executable name)
  add_executable(${name})

  # Application folders.
  target_include_directories(${name} PRIVATE
    "../../include"
  )

  message(VERBOSE "A+ -I tests/include")

  set_target_properties(${name} PROPERTIES OUTPUT_NAME "${name}")

  # Application sources.
  target_sources(${name} PRIVATE
    "../../src/${name}.cpp"
  )

  message(VERBOSE "A+ tests/src/${name}.cpp")

  target_compile_definitions(${name} PRIVATE
    # None.
  )

  # The compile options were defined in `platform-native-interface`.
  target_compile_options(${name} PRIVATE
    # None.
  )

  # https://cmake.org/cmake/help/v3.20/manual/cmake-generator-expressions.7.html
  # The link options were defined in `platform-native-interface`.
  target_link_options(${name} PRIVATE
    $<$<PLATFORM_ID:Linux,Windows>:-Wl,-Map,platform-bin/${name}-map.txt>

    # -v
  )

  target_link_libraries(${name} PRIVATE

    # Tested library.
    micro-os-plus::micro-test-plus

    # Portable dependencies.
    micro-os-plus::diag-trace

    # Platform specific dependencies and common compile/link options.
    micro-os-plus::platform
  )

  if(xpack_create_listing)
    add_custom_command(TARGET ${name} POST_BUILD
      # --all-headers -> Invalid/Unsupported object file format
      COMMAND ${CMAKE_OBJDUMP} --source --demangle --line-numbers --wide "$<TARGET_FILE:${name}>" > ${name}-list.txt
      VERBATIM
    )
  endif()

  message(VERBOSE "A> ${name}")
endfunction()

# -----------------------------------------------------------------------------

# minimal-test
if(ENABLE_MINIMAL_TEST)
  add_test_executable(minimal-test)

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
    micro-os-plus::micro-test-plus
  )

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

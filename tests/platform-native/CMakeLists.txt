#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# This file defines the global settings that apply to all targets.

message(VERBOSE "Processing platform-native...")

# -----------------------------------------------------------------------------

# A `micro-os-plus::platform` is not really needed and is not created.

# =============================================================================

function(add_test_executable name)

  add_executable(${name})

  set_target_properties(
    ${name}

    PROPERTIES
      OUTPUT_NAME "${name}"
  )

  # Application sources.
  target_sources(
    ${name}

    PRIVATE
      "../src/${name}.cpp"
  )

  message(VERBOSE "+ tests/src/${name}.cpp")

  # Include folders.
  # `platform-native/include` was added globally.
  target_include_directories(
    ${name}

    PRIVATE
      "../include"
  )

  message(VERBOSE "+ tests/include")

  target_compile_definitions(
    ${name}

    PRIVATE
      # ...
  )

  target_link_libraries(
    ${name}

    PRIVATE
      micro-os-plus::micro-test-plus
  )

  message(VERBOSE ">> ${name}")

endfunction()

# -----------------------------------------------------------------------------

add_test_executable(unit-test)

add_test_executable(sample-test)

# -----------------------------------------------------------------------------

add_test(
  NAME "unit-test"
  COMMAND unit-test
)

add_test(
  NAME "sample-test"
  COMMAND sample-test one two
)

# -----------------------------------------------------------------------------

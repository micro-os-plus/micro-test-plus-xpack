#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

message(VERBOSE "Adding 'tests/platform-qemu-mps2-an386'...")

# -----------------------------------------------------------------------------

add_library(platform-qemu-cortexm-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------

target_sources(
  platform-qemu-cortexm-interface

  INTERFACE
    "src/initialize-hardware.cpp"
    "src/interrupts-handlers.cpp"
)

message(VERBOSE "+ tests/platform-qemu-mps2-an386/src/initialize-hardware.cpp")
message(VERBOSE "+ tests/platform-qemu-mps2-an386/src/interrupts-handlers.cpp")

target_include_directories(
  platform-qemu-cortexm-interface

  INTERFACE
    "include-platform"
)

message(VERBOSE "+ tests/platform-qemu-mps2-an386/include-platform")

target_compile_definitions(
  platform-qemu-cortexm-interface

  INTERFACE
    # ...
)

target_compile_options(
  platform-qemu-cortexm-interface

  INTERFACE
    # ...
)

target_link_libraries(
  platform-qemu-cortexm-interface

  INTERFACE
    micro-os-plus::platform-qemu-cortexm
)

# -----------------------------------------------------------------------------
# Aliases.

add_library(micro-os-plus::platform ALIAS platform-qemu-cortexm-interface)
message(VERBOSE "> micro-os-plus::platform -> platform-qemu-cortexm-interface")

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
  # `tests/platform-qemu-mps2-an386/include` was added globally.
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

  # Bare-metal platforms should be warnings free.
  # Native builds may use different toolchain versions, which
  # may trigger unexpected warnings.
  target_compile_options(
    ${name}

    PRIVATE
      -Werror
  )

  target_link_libraries(
    ${name}

    PRIVATE
      micro-os-plus::micro-test-plus
  )

  target_link_libraries(
    ${name}

    PRIVATE
      micro-os-plus::platform # Should bring device & architecture too.

      micro-os-plus::libs-c
      micro-os-plus::libs-cpp
      micro-os-plus::semihosting
      micro-os-plus::startup
  )

  target_link_options(
    ${name}

    PRIVATE
      -Wl,-Map,${name}-map.txt
  )

  # TODO use add_custom_target()
  add_custom_command(
    TARGET ${name} POST_BUILD
    COMMAND ${CMAKE_SIZE} --format=berkeley "$<TARGET_FILE:${name}>"
  )

  message(VERBOSE ">> ${name}")

endfunction()

# -----------------------------------------------------------------------------

add_test_executable(unit-test)

add_test_executable(sample-test)

# -----------------------------------------------------------------------------

if("${CMAKE_HOST_SYSTEM_NAME}" STREQUAL "Windows")
  set(extension ".cmd")
endif()

add_test(
  NAME "unit-test"

  COMMAND qemu-system-arm${extension}
    --machine mps2-an386
    -d unimp,guest_errors
    --nographic
    --kernel unit-test.elf
    --semihosting-config enable=on,target=native,arg=unit-test
)

add_test(
  NAME "sample-test"

  COMMAND qemu-system-arm${extension}
    --machine mps2-an386
    -d unimp,guest_errors
    --nographic
    --kernel sample-test.elf
    --semihosting-config enable=on,target=native,arg=sample-test,arg=one,arg=two
)

# -----------------------------------------------------------------------------


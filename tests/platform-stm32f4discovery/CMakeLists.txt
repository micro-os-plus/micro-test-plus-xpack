#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

message(VERBOSE "Adding 'tests/platform-stm32f4discovery'...")

add_library(platform-stm32f4discovery-interface INTERFACE EXCLUDE_FROM_ALL)

# -------------------------------------------------------------------------

target_sources(
  platform-stm32f4discovery-interface

  INTERFACE
    "src/initialize-hardware.cpp"
    "src/interrupts-handlers.cpp"
)

message(VERBOSE "+ tests/platform-stm32f4discovery/src/initialize-hardware.cpp")
message(VERBOSE "+ tests/platform-stm32f4discovery/src/interrupts-handlers.cpp")

# The include folder was passed globally, to catch the global config.h.
# The preprocessor definitions were passed globally.

target_compile_options(
  platform-stm32f4discovery-interface

  INTERFACE
    # ...
)

target_link_libraries(
  platform-stm32f4discovery-interface

  INTERFACE
    micro-os-plus::platform-stm32f4discovery
)

# -------------------------------------------------------------------------
# Aliases.

add_library(micro-os-plus::platform ALIAS platform-stm32f4discovery-interface)
message(VERBOSE "micro-os-plus::platform -> platform-stm32f4discovery-interface")

# -------------------------------------------------------------------------

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

  message(VERBOSE "=> ${name}")

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

  COMMAND qemu-system-gnuarmeclipse${extension}
      --verbose
      --board STM32F4-Discovery
      -d unimp,guest_errors
      --nographic
      --image unit-test.elf
      --semihosting-config enable=on,target=native
      --semihosting-cmdline unit-test
)

add_test(
  NAME "sample-test"

  COMMAND qemu-system-gnuarmeclipse${extension}
      --verbose
      --board STM32F4-Discovery
      -d unimp,guest_errors
      --nographic
      --image sample-test.elf
      --semihosting-config enable=on,target=native
      --semihosting-cmdline sample-test one two
)

# -----------------------------------------------------------------------------


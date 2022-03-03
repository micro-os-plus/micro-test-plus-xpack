#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

message(VERBOSE "Adding 'tests/platform-stm32f4discovery'...")

# -----------------------------------------------------------------------------

set(xpack_create_listing true)

# -----------------------------------------------------------------------------

add_library(platform-stm32f4discovery-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------

target_include_directories(platform-stm32f4discovery-interface INTERFACE
  "include-platform"
)

target_sources(platform-stm32f4discovery-interface INTERFACE
  "src/initialize-hardware.cpp"
  "src/interrupts-handlers.cpp"
)

target_compile_definitions(platform-stm32f4discovery-interface INTERFACE
  # None.
)

target_compile_options(platform-stm32f4discovery-interface INTERFACE
  # None.
)

target_link_libraries(platform-stm32f4discovery-interface INTERFACE
  micro-os-plus::platform-stm32f4discovery
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists(platform-stm32f4discovery-interface)
endif()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library(micro-os-plus::platform ALIAS platform-stm32f4discovery-interface)
message(VERBOSE "> micro-os-plus::platform -> platform-stm32f4discovery-interface")

# =============================================================================

if("${CMAKE_HOST_SYSTEM_NAME}" STREQUAL "Windows")
  set(extension ".cmd")
endif()

function(add_test_executable name)

  add_executable(${name})

  set_target_properties(${name}
    PROPERTIES
      OUTPUT_NAME "${name}"
  )

  # Include folders.
  target_include_directories(${name} PRIVATE
    "../include"
  )

  message(VERBOSE "A+ -I tests/include")

    # Application sources.
    target_sources(${name} PRIVATE
    "../src/${name}.cpp"
  )

  message(VERBOSE "A+ tests/src/${name}.cpp")

  target_compile_definitions(${name} PRIVATE
    # None.
  )

  target_compile_options(${name} PRIVATE
    # None.
  )

  target_link_options(${name} PRIVATE
    -nostartfiles
    # nano has no exceptions.
    # -specs=nano.specs
    -Wl,--gc-sections

    # Force the linker to keep the interrupt vectors which otherwise
    # are not refered from anywhere.
    -u_interrupt_vectors

    # Including files from other packages is not very nice, but functional.
    # Use absolute paths, otherwise set -L.
    -T${CMAKE_BINARY_DIR}/xpacks/micro-os-plus-platform-stm32f4discovery/linker-scripts/mem.ld
    -T${CMAKE_BINARY_DIR}/xpacks/micro-os-plus-architecture-cortexm/linker-scripts/sections.ld

    -Wl,-Map,platform-bin/${name}-map.txt
    # -v
  )

  target_link_libraries(${name} PRIVATE
    # Tested library.
    micro-os-plus::micro-test-plus

    # Portable dependencies.
    micro-os-plus::diag-trace

    # Platform specific dependencies.
    micro-os-plus::platform # Should bring device & architecture too.

    micro-os-plus::libs-c
    micro-os-plus::libs-cpp
    micro-os-plus::semihosting
    micro-os-plus::startup
  )


  # TODO use add_custom_target()
  # https://cmake.org/cmake/help/v3.20/command/add_custom_command.html
  add_custom_command(
    TARGET ${name} POST_BUILD
    COMMAND ${CMAKE_SIZE} --format=berkeley "$<TARGET_FILE:${name}>"
  )

  if(xpack_create_listing)
    add_custom_command(
      TARGET ${name} POST_BUILD
      COMMAND ${CMAKE_OBJDUMP} --source --all-headers --demangle --line-numbers --wide "$<TARGET_FILE:${name}>" > ${name}-list.txt
      VERBATIM
    )
  endif()

  message(VERBOSE "A> ${name}")

endfunction()

# -----------------------------------------------------------------------------

add_test_executable(sample-test)

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

add_test_executable(unit-test)

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

# -----------------------------------------------------------------------------


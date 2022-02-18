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

# set(xpack_create_listing true)

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

function(add_test_executable name)

  add_executable(${name})

  set_target_properties(${name}
    PROPERTIES
      OUTPUT_NAME "${name}"
  )

  # Application sources.
  target_sources(${name} PRIVATE
    "../src/${name}.cpp"
  )

  message(VERBOSE "A+ tests/src/${name}.cpp")

  # Include folders.
  target_include_directories(${name} PRIVATE
    "../include"
    # 'include-config' # was added globally
  )

  message(VERBOSE "A+ -I tests/include")

  target_compile_definitions(${name} PRIVATE
    # None.
  )

  # Bare-metal platforms should be warnings free.
  # Native builds may use different toolchain versions, which
  # may trigger unexpected warnings.
  target_compile_options(${name} PRIVATE
    -Werror
  )

  target_link_libraries(${name} PRIVATE
    micro-os-plus::micro-test-plus
    micro-os-plus::platform # Should bring device & architecture too.

    micro-os-plus::libs-c
    micro-os-plus::libs-cpp
    micro-os-plus::semihosting
    micro-os-plus::startup
  )

  target_link_options(${name} PRIVATE
    -Wl,-Map,platform-bin/${name}-map.txt
    # -v
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


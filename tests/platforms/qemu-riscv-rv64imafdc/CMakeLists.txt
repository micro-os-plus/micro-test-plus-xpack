# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
# (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu. All rights reserved.
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

message(VERBOSE "Processing 'tests/platforms/qemu-riscv-rv64imafdc'...")

# -----------------------------------------------------------------------------

# set(xpack_create_listing true)
# set(xpack_create_hex true)

# -----------------------------------------------------------------------------

# Define the tests executables.
function(add_test_executable name)
  add_executable(${name})

  set_target_properties(${name}

    PROPERTIES
    OUTPUT_NAME "${name}"
  )

  # Include folders.
  # `tests/platforms/qemu-riscv-rv64imafdc/include` was added globally.
  target_include_directories(${name} PRIVATE
    "../../include"
  )

  message(VERBOSE "A+ -I tests/include")

  # Application sources.
  target_sources(${name} PRIVATE
    "../../src/${name}.cpp"
  )

  message(VERBOSE "A+ tests/src/${name}.cpp")

  target_compile_definitions(${name} PRIVATE

    # None.
  )

  target_compile_options(${name} PRIVATE

    # None.
  )

  target_link_options(${name} PRIVATE
    -Wl,-Map,platform-bin/${name}-map.txt

    # -v
  )

  target_link_libraries(${name} PRIVATE

    # Tested library.
    micro-os-plus::micro-test-plus

    # Portable dependencies.
    micro-os-plus::diag-trace

    # Platform specific dependencies.
    micro-os-plus::platform # bring device & architecture too

    micro-os-plus::semihosting
    micro-os-plus::startup
  )

  # TODO use add_custom_target()
  # https://cmake.org/cmake/help/v3.20/command/add_custom_command.html
  add_custom_command(TARGET ${name} POST_BUILD
    COMMAND ${CMAKE_SIZE} --format=berkeley "$<TARGET_FILE:${name}>"
  )

  if(xpack_create_hex)
    add_custom_command(TARGET ${name} POST_BUILD
      COMMAND ${CMAKE_OBJCOPY} -O ihex "$<TARGET_FILE:${name}>" "$<TARGET_FILE:${name}>.hex"
    )
  endif()

  if(xpack_create_listing)
    add_custom_command(TARGET ${name} POST_BUILD
      COMMAND ${CMAKE_OBJDUMP} --source --all-headers --demangle --line-numbers --wide "$<TARGET_FILE:${name}>" > ${name}-list.txt
      VERBATIM
    )
  endif()

  message(VERBOSE "A> ${name}")
endfunction()

# -----------------------------------------------------------------------------

if(ENABLE_SAMPLE_TEST)
  add_test_executable(sample-test)

  add_test(
    NAME "sample-test"

    COMMAND qemu-system-riscv64${extension}
    --machine virt
    --cpu rv64
    --kernel sample-test.elf
    -smp 1
    -bios none
    --nographic
    -d unimp,guest_errors
    --semihosting-config enable=on,target=native,arg=sample-test,arg=one,arg=two
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

    COMMAND qemu-system-riscv64${extension}
    --machine virt
    --cpu rv64
    --kernel unit-test.elf
    --nographic
    -smp 1
    -bios none
    -d unimp,guest_errors
    --semihosting-config enable=on,target=native,arg=unit-test
  )
endif()

# -----------------------------------------------------------------------------

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

message (VERBOSE "Processing 'tests/platforms/native'...")

include ("cmake/platform-library.cmake")

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_EMPTY_TEST)
  add_native_test_executable (empty-test)
  target_link_native_test_libraries (empty-test test::empty)

  message (VERBOSE "A> empty-test")

  add_test (NAME "empty-test --verbose" COMMAND empty-test one two --verbose
                                                --output-file empty-test.tap
  )

  add_test (NAME "empty-test" COMMAND empty-test one two)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_MINIMAL_TEST)
  add_native_test_executable (minimal-test)
  target_link_native_test_libraries (minimal-test test::minimal)

  message (VERBOSE "A> minimal-test")

  # TAP reporter
  add_test (NAME "minimal-test --verbose --reporter tap"
            COMMAND minimal-test one two --verbose --reporter tap --output-file
                    minimal-test.tap
  )
  add_test (NAME "minimal-test --reporter tap" COMMAND minimal-test one two
                                                       --reporter tap
  )
  add_test (NAME "minimal-test --quiet --reporter tap"
            COMMAND minimal-test one two --quiet --reporter tap
  )
  add_test (NAME "minimal-test --silent --reporter tap"
            COMMAND minimal-test one two --silent --reporter tap
  )

  # Human reporter
  add_test (NAME "minimal-test --verbose --reporter human"
            COMMAND minimal-test one two --verbose --reporter human
  )
  add_test (NAME "minimal-test --reporter human" COMMAND minimal-test one two
                                                         --reporter human
  )
  add_test (NAME "minimal-test --quiet --reporter human"
            COMMAND minimal-test one two --quiet --reporter human
  )
  add_test (NAME "minimal-test --silent --reporter human"
            COMMAND minimal-test one two --silent --reporter human
  )

endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_native_test_executable (suite-test)
  target_link_native_test_libraries (suite-test test::suite)

  message (VERBOSE "A> suite-test")

  # TAP reporter
  add_test (NAME "suite-test --verbose --reporter tap"
            COMMAND suite-test one two --verbose --reporter tap --output-file
                    suite-test.tap
  )
  add_test (NAME "suite-test --reporter tap" COMMAND suite-test one two
                                                     --reporter tap
  )
  add_test (NAME "suite-test --quiet --reporter tap"
            COMMAND suite-test one two --quiet --reporter tap
  )
  add_test (NAME "suite-test --silent --reporter tap"
            COMMAND suite-test one two --silent --reporter tap
  )

  # Human reporter
  add_test (NAME "suite-test --verbose --reporter human"
            COMMAND suite-test one two --verbose --reporter human
  )
  add_test (NAME "suite-test --reporter human" COMMAND suite-test one two
                                                       --reporter human
  )
  add_test (NAME "suite-test --quiet --reporter human"
            COMMAND suite-test one two --quiet --reporter human
  )
  add_test (NAME "suite-test --silent --reporter human"
            COMMAND suite-test one two --silent --reporter human
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_native_test_executable (sample-test)
  target_link_native_test_libraries (sample-test test::sample)

  message (VERBOSE "A> sample-test")

  # TAP reporter
  add_test (NAME "sample-test --verbose --reporter tap"
            COMMAND sample-test one two --verbose --reporter tap --output-file
                    sample-test.tap
  )
  add_test (NAME "sample-test --reporter tap" COMMAND sample-test one two
                                                      --reporter tap
  )
  add_test (NAME "sample-test --quiet --reporter tap"
            COMMAND sample-test one two --quiet --reporter tap
  )
  add_test (NAME "sample-test --silent --reporter tap"
            COMMAND sample-test one two --silent --reporter tap
  )

  # Human reporter
  add_test (NAME "sample-test --verbose --reporter human"
            COMMAND sample-test one two --verbose --reporter human
  )
  add_test (NAME "sample-test --reporter human" COMMAND sample-test one two
                                                        --reporter human
  )
  add_test (NAME "sample-test --quiet --reporter human"
            COMMAND sample-test one two --quiet --reporter human
  )
  add_test (NAME "sample-test --silent --reporter human"
            COMMAND sample-test one two --silent --reporter human
  )
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_native_test_executable (unit-test)
  target_link_native_test_libraries (unit-test test::unit)

  message (VERBOSE "A> unit-test")

  # TAP reporter
  add_test (NAME "unit-test --verbose --reporter tap"
            COMMAND unit-test --verbose --reporter tap
  )
  add_test (NAME "unit-test --reporter tap" COMMAND unit-test --reporter tap)
  add_test (NAME "unit-test --quiet --reporter tap" COMMAND unit-test --quiet
                                                            --reporter tap
  )
  add_test (NAME "unit-test --silent --reporter tap" COMMAND unit-test --silent
                                                             --reporter tap
  )

  # Human reporter
  add_test (NAME "unit-test --verbose --reporter human"
            COMMAND unit-test --verbose --reporter human
  )
  add_test (NAME "unit-test --reporter human" COMMAND unit-test --reporter
                                                      human
  )
  add_test (NAME "unit-test --quiet --reporter human" COMMAND unit-test --quiet
                                                              --reporter human
  )
  add_test (NAME "unit-test --silent --reporter human"
            COMMAND unit-test --silent --reporter human
  )
endif ()

# -----------------------------------------------------------------------------

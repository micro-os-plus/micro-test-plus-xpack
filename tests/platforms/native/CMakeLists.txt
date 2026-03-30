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

  add_test (NAME "empty-test --verbose" COMMAND empty-test one two --verbose)

  add_test (NAME "empty-test" COMMAND empty-test one two)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_MINIMAL_TEST)
  add_native_test_executable (minimal-test)
  target_link_native_test_libraries (minimal-test test::minimal)

  message (VERBOSE "A> minimal-test")

  # tap reporter
  add_test (NAME "minimal-test --verbose --reporter=tap" COMMAND minimal-test one two
                                                  --verbose --reporter=tap
  )
  add_test (NAME "minimal-test --reporter=tap" COMMAND minimal-test one two --reporter=tap)
  add_test (NAME "minimal-test --quiet --reporter=tap" COMMAND minimal-test one two --quiet --reporter=tap)
  add_test (NAME "minimal-test --silent --reporter=tap" COMMAND minimal-test one two --silent --reporter=tap)

  # basic reporter
  add_test (NAME "minimal-test --verbose --reporter=basic" COMMAND minimal-test one two
                                                  --verbose --reporter=basic
  )
  add_test (NAME "minimal-test --reporter=basic" COMMAND minimal-test one two --reporter=basic)
  add_test (NAME "minimal-test --quiet --reporter=basic" COMMAND minimal-test one two --quiet --reporter=basic)
  add_test (NAME "minimal-test --silent --reporter=basic" COMMAND minimal-test one two --silent --reporter=basic)

endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SUITE_TEST)
  add_native_test_executable (suite-test)
  target_link_native_test_libraries (suite-test test::suite)

  message (VERBOSE "A> suite-test")

  # tap reporter
  add_test (NAME "suite-test --verbose --reporter=tap" COMMAND suite-test one two
                                                  --verbose --reporter=tap
  )
  add_test (NAME "suite-test --reporter=tap" COMMAND suite-test one two --reporter=tap)
  add_test (NAME "suite-test --quiet --reporter=tap" COMMAND suite-test one two --quiet --reporter=tap)
  add_test (NAME "suite-test --silent --reporter=tap" COMMAND suite-test one two --silent --reporter=tap)

  # basic reporter
  add_test (NAME "suite-test --verbose --reporter=basic" COMMAND suite-test one two
                                                  --verbose --reporter=basic
  )
  add_test (NAME "suite-test --reporter=basic" COMMAND suite-test one two --reporter=basic)
  add_test (NAME "suite-test --quiet --reporter=basic" COMMAND suite-test one two --quiet --reporter=basic)
  add_test (NAME "suite-test --silent --reporter=basic" COMMAND suite-test one two --silent --reporter=basic)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_SAMPLE_TEST)
  add_native_test_executable (sample-test)
  target_link_native_test_libraries (sample-test test::sample)

  message (VERBOSE "A> sample-test")

  # tap reporter
  add_test (NAME "sample-test --verbose --reporter=tap" COMMAND sample-test one two --verbose --reporter=tap)
  add_test (NAME "sample-test --reporter=tap" COMMAND sample-test one two --reporter=tap)
  add_test (NAME "sample-test --quiet --reporter=tap" COMMAND sample-test one two --quiet --reporter=tap)
  add_test (NAME "sample-test --silent --reporter=tap" COMMAND sample-test one two --silent --reporter=tap)

  # basic reporter
  add_test (NAME "sample-test --verbose --reporter=basic" COMMAND sample-test one two --verbose --reporter=basic)
  add_test (NAME "sample-test --reporter=basic" COMMAND sample-test one two --reporter=basic)
  add_test (NAME "sample-test --quiet --reporter=basic" COMMAND sample-test one two --quiet --reporter=basic)
  add_test (NAME "sample-test --silent --reporter=basic" COMMAND sample-test one two --silent --reporter=basic)
endif ()

# -----------------------------------------------------------------------------

if (XPACK_ENABLE_UNIT_TEST)
  add_native_test_executable (unit-test)
  target_link_native_test_libraries (unit-test test::unit)

  message (VERBOSE "A> unit-test")

  # tap reporter
  add_test (NAME "unit-test --verbose --reporter=tap" COMMAND unit-test --verbose --reporter=tap)
  add_test (NAME "unit-test --reporter=tap" COMMAND unit-test --reporter=tap)
  add_test (NAME "unit-test --quiet --reporter=tap" COMMAND unit-test --quiet --reporter=tap)
  add_test (NAME "unit-test --silent --reporter=tap" COMMAND unit-test --silent --reporter=tap)

  # basic reporter
  add_test (NAME "unit-test --verbose --reporter=basic" COMMAND unit-test --verbose --reporter=basic)
  add_test (NAME "unit-test --reporter=basic" COMMAND unit-test --reporter=basic)
  add_test (NAME "unit-test --quiet --reporter=basic" COMMAND unit-test --quiet --reporter=basic)
  add_test (NAME "unit-test --silent --reporter=basic" COMMAND unit-test --silent --reporter=basic)
endif ()

# -----------------------------------------------------------------------------

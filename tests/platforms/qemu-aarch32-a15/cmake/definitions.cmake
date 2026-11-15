# -----------------------------------------------------------------------------
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2026 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#
# -----------------------------------------------------------------------------

# Override the project definitions with platform specific values.

# -----------------------------------------------------------------------------

# The separate unit tests are replaced by the combined unit test.
set (XPACK_ENABLE_UNIT_CHECKS_TEST false)
set (XPACK_ENABLE_UNIT_COMBINATIONS_TEST false)
set (XPACK_ENABLE_UNIT_EXCEPTIONS_TEST false)
set (XPACK_ENABLE_UNIT_MISCELLANEOUS_TEST false)

# -----------------------------------------------------------------------------
# The benchmarks that are only built, not run, since they fail on this
# platform: Boost.Test does not end, as on the Cortex-M platforms, where it
# overflows the stack.
set (xpack_footprint_benchmarks_not_run boost-test)

# -----------------------------------------------------------------------------

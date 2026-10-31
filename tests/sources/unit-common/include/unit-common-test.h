/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2021-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

#ifndef MICRO_OS_PLUS_MICRO_TEST_PLUS_UNIT_COMMON_TEST_H_
#define MICRO_OS_PLUS_MICRO_TEST_PLUS_UNIT_COMMON_TEST_H_

// ----------------------------------------------------------------------------

#if defined(__cplusplus)

// ----------------------------------------------------------------------------

#include "micro-os-plus/platform.h"
#include "micro-os-plus/micro-test-plus.h"

#include <cstddef>

// ----------------------------------------------------------------------------

// The simple way of testing a testing framework without having to resort to
// another testing framework (which might have clashing primitives),
// is to use traditional asserts. To have some minimal control and do not
// depend on NDEBUG, define a custom assert locally.

// While the test cases are only listed (`--list-tests`), their bodies do
// not run, so the totals checked by the assertions are not reached, and
// the assertions are not evaluated.
#define test_assert(EX) \
  (void)(tr.is_listing () || (EX) \
         || (local_test_assert (#EX, __FILE__, __LINE__), 0))

void __attribute__ ((noreturn))
local_test_assert (const char* failedexpr, const char* file, int line);

// ----------------------------------------------------------------------------

extern micro_os_plus::micro_test_plus::runner tr;

// ----------------------------------------------------------------------------

// Each test case exercises a member function or a family of member
// functions.
// After each test case, the caller checks if the counts of
// passed/failed test conditions matches the local counts.

typedef struct local_counts_s
{
  std::size_t executed_test_cases;
  std::size_t passed_checks;
  std::size_t failed_checks;
} local_counts_t;

extern local_counts_t local_counts;

// ----------------------------------------------------------------------------

// Check the state of the session after `run_suites()` returned `code`;
// `ts` is the top suite and `argc`/`argv` the arguments of `main()`.
void
unit_common_verify_session (int argc, char* argv[],
                            micro_os_plus::micro_test_plus::suite& ts,
                            int code);

// ----------------------------------------------------------------------------

#endif // defined(__cplusplus)

// ----------------------------------------------------------------------------

#endif // MICRO_OS_PLUS_MICRO_TEST_PLUS_UNIT_COMMON_TEST_H_

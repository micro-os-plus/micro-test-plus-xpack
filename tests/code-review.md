# Code Review — `tests/sources/`

**Date:** 8 April 2026  
**Scope:** All test source files under `tests/sources/`; code quality, correctness,
performance, size, and C++20 modernisation opportunities.  
**Doxygen issues excluded** (to be addressed separately).

---

## File Inventory

| File                                 | Lines | Purpose                         |
| ------------------------------------ | ----- | ------------------------------- |
| `sources/minimal-test/src/main.cpp`  | ~80   | Minimal API example             |
| `sources/empty-test/src/main.cpp`    | ~200  | Structural framework validation |
| `sources/suite-test/src/main.cpp`    | ~165  | Runner and suite usage patterns |
| `sources/suite-test/src/suite.cpp`   | ~75   | Static suite definitions        |
| `sources/suite-test/include/suite.h` | ~20   | Shared declarations             |
| `sources/sample-test/src/main.cpp`   | ~370  | Comprehensive API example       |
| `sources/unit-test/src/main.cpp`     | 1984  | Full framework self-test        |

---

## Correctness Issues

### [unit-test] Copy-paste bug: wrong template parameters for `short` types

**Severity: High** | Affects: `ts_passed_integrals` and `ts_failed_integrals`

In both suites, the first two `short` entries instantiate the wrong template
argument (`<signed int>` / `<unsigned int>` instead of `<signed short>` /
`<unsigned short>`). A correct second pair for each follows immediately after,
so the short types are eventually tested — but `signed int` and `unsigned int`
are each tested four times instead of twice.

```cpp
// BUG (appears in both ts_passed_integrals and ts_failed_integrals):
ts.test ("Combinatorial integrals with signed short",
         test_case_expect_passed_integrals_combinatorial<signed int>);   // ← should be <signed short>

ts.test ("Combinatorial integrals with unsigned short",
         test_case_expect_passed_integrals_combinatorial<unsigned int>); // ← should be <unsigned short>
```

**Fix:** Change `<signed int>` → `<signed short>` and `<unsigned int>` →
`<unsigned short>` in the first of the two short-type pairs in each suite.

---

### [suite-test/main.cpp] Redundant `extern` forward declaration for `sr`

**Severity: Low**

```cpp
extern mt::static_runner sr;          // redundant — defined on the very next line
mt::static_runner sr{ "Static top suite" };
```

Forward-declaring and then defining `sr` in the same translation unit is
misleading — it implies the definition lives elsewhere. Remove the `extern`
line.

---

## Code Quality Issues

### [empty-test, unit-test] Duplicated `local_test_assert` / `test_assert`

**Severity: Medium**

The identical ~10-line assert helper (the `local_test_assert` function and the
`test_assert` macro) is copy-pasted verbatim into both `empty-test/main.cpp`
and `unit-test/main.cpp`. Extracting it into a shared internal header (e.g.
`sources/common/test_assert.h`) would eliminate the duplication and ensure any
future changes propagate correctly.

---

### [empty-test/main.cpp] `-Waggregate-return` pragma commented out

**Severity: Low**

All other test files suppress `-Waggregate-return` at file scope. In
`empty-test/main.cpp` the pragma is commented out. The file is currently safe
because it contains no range-for loops over vectors, but the inconsistency is
fragile if the file is ever extended.

```cpp
// #pragma GCC diagnostic ignored "-Waggregate-return"   // ← should be active
```

---

### [empty-test/main.cpp ≈ line 154] `()` constructor instead of `{}`

**Severity: Low**

Every other instantiation in the test suite uses braced initialisation. This one
location uses `()`:

```cpp
mt::runner tr ("Top suite with nested subtests");  // ← inconsistent
```

**Fix:** Change to `mt::runner tr{ "Top suite with nested subtests" };`.

---

### [unit-test/main.cpp] File-scope diagnostic suppressions lack explanation

**Severity: Low**

The following suppressions at lines 37–42 apply to the entire file with no
comment explaining why each is necessary:

```cpp
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wdouble-promotion"
#pragma GCC diagnostic ignored "-Wconversion"
```

These are legitimately required for a test file that deliberately exercises
mixed-type comparisons, but the absence of explanation may confuse future
maintainers. A short comment per pragma stating the reason would help.

---

### [sample-test/main.cpp] Unconditional `#if 1` guard

**Severity: Low**

```cpp
#if 1
// Additional test suites...
#endif
```

The guard is always true and serves only as a toggle placeholder. Either remove
it entirely or replace it with a named macro to make the opt-out intent
explicit.

---

### [sample-test/main.cpp] Obscure names for static parameters feeding `ts_args`

**Severity: Low**

The six static globals (`in`, `in44`, `ir`, `in45`, `in46`, `ip2`) that feed
the `ts_args` parametrised suite communicate their values rather than their
roles. Renaming to something like `arg_iv`, `arg_ir_val`, `arg_ir`,
`arg_ip1_val`, `arg_ip2_val`, `arg_ip2` — placed directly above the suite
definition — would improve readability.

---

## Maintainability Issues

### [unit-test/main.cpp] Fragile `local_counts` ordering dependency

**Severity: Medium**

`local_counts` is a file-scope mutable struct that is reset at the start of
each outer static suite (`local_counts = {};`) and validated immediately after
each `ts.test(...)` call. This ordering dependency is invisible from the call
site. Moving or reordering a `ts.test(...)` call without also moving its
matching `test_assert` triplet would cause silent failures.

A comment block above the combinatorial suites making this contract explicit
would help future readers:

```cpp
// ORDERING CONTRACT: local_counts is reset at suite entry and validated
// after each ts.test() call. Do not reorder calls without also reordering
// the test_assert triplet that follows each one.
```

---

### [unit-test/main.cpp] Repeated 3-line `test_assert` triplet (~30 occurrences)

**Severity: Medium**

The following block appears approximately 30 times across the file:

```cpp
test_assert (current_suite_totals.successful_checks ()
             == local_counts.successful_checks);
test_assert (current_suite_totals.failed_checks ()
             == local_counts.failed_checks);
test_assert (current_suite_totals.executed_subtests ()
             == local_counts.executed_subtest);
```

A helper macro would reduce ~90 repetitive lines to ~30 without changing
behaviour:

```cpp
#define verify_counts() \
  test_assert (current_suite_totals.successful_checks () \
               == local_counts.successful_checks); \
  test_assert (current_suite_totals.failed_checks () \
               == local_counts.failed_checks); \
  test_assert (current_suite_totals.executed_subtests () \
               == local_counts.executed_subtest)
```

---

## C++20 Modernisation Opportunities

### [unit-test/main.cpp] Add `std::integral` / `std::floating_point` concept constraints

The unconstrained mock templates accept any type silently:

```cpp
// Current:
template <typename T = int>
T my_actual_integral (void) { return 42; }

// C++20:
template <std::integral T = int>
T my_actual_integral (void) { return 42; }
```

Applying `std::integral` to `my_actual_integral`, `my_actual_integral_less`,
`my_actual_integral_more`, `my_expected_integral` and these to the
`test_case_expect_*_combinatorial` templates would turn accidental type
mismatches into hard compile-time errors and make intent self-documenting.
The same applies to `my_actual_float` / `my_expected_float` with
`std::floating_point`.

---

### [unit-test/main.cpp ≈ line 172] Replace `std::is_same_v` with `std::same_as`

```cpp
// Current:
static_assert (not std::is_same_v<decltype (_sc (42)), decltype (_c (42))>);

// C++20:
static_assert (!std::same_as<decltype (_sc (42)), decltype (_c (42))>);
```

`std::same_as` reads more naturally in `static_assert` predicates and integrates
better with concept-based tooling.

---

### [empty-test, unit-test] Add `noexcept` to non-throwing lambdas

Several lambdas contain only counter increments or simple assertions and cannot
throw. Marking them `noexcept` conveys intent and allows the compiler to omit
exception-handling boilerplate. `unit-test/main.cpp` already does this on one
lambda; applying it consistently is worthwhile:

```cpp
// Before:
ts.test ("Empty subtest", [&xc] (auto& t) { xc = 1; ... });

// After:
ts.test ("Empty subtest", [&xc] (auto& t) noexcept { xc = 1; ... });
```

---

## Summary

| Severity                     | Count | Location                            |
| ---------------------------- | ----- | ----------------------------------- |
| **High (correctness)**       | 1     | unit-test                           |
| **Low (correctness)**        | 1     | suite-test/main.cpp                 |
| **Medium (quality)**         | 1     | empty-test, unit-test (shared code) |
| **Low (quality)**            | 4     | empty-test (2), sample-test (2)     |
| **Low (quality)**            | 1     | unit-test                           |
| **Medium (maintainability)** | 2     | unit-test                           |
| **C++20 opportunity**        | 3     | unit-test, empty-test               |

**Priority order for remediation:**

1. Fix the copy-paste bug with `<signed short>` / `<unsigned short>` template
   parameters in `unit-test`.
2. Extract `local_test_assert` / `test_assert` into a shared header.
3. Introduce the `verify_counts()` helper macro in `unit-test`.
4. Apply `std::integral` / `std::floating_point` concept constraints.
5. Add `noexcept` to non-throwing lambdas.
6. Address the minor consistency issues (pragma, braces, `#if 1`, `extern`).

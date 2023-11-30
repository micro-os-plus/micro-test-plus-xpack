@page testing Testing

@tableofcontents

[![CI on Push](https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/ci.yml/badge.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/ci.yml)

## Overview

The µOS++ testing strategy is to compile the sources with as many
toolchains as possible, and run them on as many platforms as possible.

## Platforms

The supported test platforms are:

- `platforms/native` - run the test applications as **native processes**
  on the development machine
- `platforms/qemu-cortex-m0` - run the tests as fully semihosted
  **Cortex-M0** applications on a QEMU **mps2-an385** emulated board
  (an Arm Cortex-M3 development board)
- `platforms/qemu-cortex-m3` - run the tests as fully semihosted
  **Cortex-M3** applications on a QEMU **mps2-an385** emulated board
  (an Arm Cortex-M3 development board)
- `platforms/qemu-cortex-m4f` - run the tests as fully semihosted
  **Cortex-M4** applications on a QEMU **mps2-an386** emulated board
  (an Arm Cortex-M4 development board)
- `platforms/qemu-cortex-m7f` - run the tests as fully semihosted
  **Cortex-M7** applications on a QEMU **mps2-an500** emulated board
  (an Arm Cortex-M7 development board)
- `platforms/qemu-cortex-a15` - run the tests as fully semihosted
  **Cortex-A15** applications on a QEMU **virt** emulated board
- `platforms/qemu-cortex-a72` - run the tests as fully semihosted
  **Cortex-A72** (64-bit) applications on a QEMU **virt** emulated board
- `platforms/qemu-riscv-rv32imac` - run the tests as fully semihosted
  **RISC-V RV32IMAC** applications on a QEMU **virt** emulated board
- `platforms/qemu-riscv-rv64imafdc` - run the tests as fully semihosted
  **RISC-V RV64IMAFDC** applications on a QEMU **virt** emulated board

The tests can be executed on:

- GNU/Linux (Intel and Arm)
- macOS (Intel and Apple Silicon)
- Windows

The build configurations use exactly the same source files on all platforms,
without changes. On embedded platforms, the applications interact with the
host via the
[Arm semihosting mechanism](https://github.com/ARM-software/abi-aa/blob/main/semihosting/semihosting.rst).

## Toolchains

To improve source code portability, the builds are repeated with multiple
toolchains, even with multiple versions of the same toolchain.

The following toolchains are used:

- gcc 11, 12, 13 (native)
- clang 13, 14, 15, 16 (native)
- arm-none-eabi-gcc 11, 12, 13 (Cortex-M, AArch32)
- aarch64-none-elf-gcc 11, 12, 13 (AArch64)
- risc-none-elf-gcc 11, 12, 13 (RISC-V 32/64)

## Tests details

### sample-test

The [sample-test.cpp](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/tests/src/sample-test.cpp)
file is a simple application to demonstrate how to call some of the
primitives available in the library to write a simple test.

A typical run looks like:

```console
test 1
    Start 1: sample-test

1: Test command: /Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin/sample-test "one" "two"
1: Working Directory: /Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin
1: Test timeout computed to be: 10000000
1: Built with clang Apple LLVM 15.0.0 (clang-1500.0.40.1), with exceptions.
1:
1: • Sample - test suite started
1:
1:   ✓ Check various conditions - test case passed (7 checks)
1:   ✓ Check various conditions with operators - test case passed (7 checks)
1:   ✓ Check strings - test case passed (1 check)
1:   ✓ Check strings with operators - test case passed (1 check)
1:   ✓ Check compound conditions - test case passed (1 check)
1:   ✓ Check compound conditions with operators - test case passed (1 check)
1:   ✓ Check multiple function invocations - test case passed (2 checks)
1:   ✓ Check args - test case passed (3 checks)
1:   ✓ Check complex logic - test case passed (1 check)
1:   ✓ Check if exceptions are thrown - test case passed (2 checks)
1:   ✓ Check if exceptions are not thrown - test case passed (1 check)
1:   ✓ Check containers - test case passed (2 checks)
1:   ✓ Check containers with operators - test case passed (2 checks)
1:
1: ✓ Sample - test suite passed (31 checks in 13 test cases)
1:
1: • Separate - test suite started
1:
1:   ✓ Check one - test case passed (1 check)
1:   ✓ Check two - test case passed (1 check)
1:
1: ✓ Separate - test suite passed (2 checks in 2 test cases)
1:
1: • Explicit namespace - test suite started
1:
1:   ✓ Check one - test case passed (1 check)
1:   ✓ Check two - test case passed (1 check)
1:
1: ✓ Explicit namespace - test suite passed (2 checks in 2 test cases)
1:
1: • Args - test suite started
1:
1:   ✓ args - test case passed (5 checks)
1:
1: ✓ Args - test suite passed (5 checks in 1 test case)
```

In addition to the default run, there are two more, one more verbose, and one
silent, which only returns the test result.

### unit-test

The [unit-test.cpp](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/tests/src/unit-test.cpp)
file is an exhaustive test trying to validate that all the library
functions work as expected.

A typical run looks like:

```console
test 5
    Start 5: unit-test

5: Test command: /Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin/unit-test
5: Working Directory: /Users/ilg/MyProjects/micro-os-plus.github/xPacks/micro-test-plus-xpack.git/tests/build/native-cmake-sys-release/platform-bin
5: Test timeout computed to be: 10000000
5: Built with clang Apple LLVM 15.0.0 (clang-1500.0.40.1), with exceptions.
5:
5: µTest++ unit tests; some checks are expected to fail.
5:
5: • Main - test suite started
5:
5:   ✓ Initial counters - test case passed (0 checks)
5:   ✓ expect(true) - test case passed (3 checks)
5:
5:   • expect(false) - test case started
5:     ✗ FAILED (micro-test-plus.h:102)
5:     ✗ false FAILED (micro-test-plus.h:102)
5:   ✗ expect(false) - test case FAILED (0 checks passed, 2 failed)
5:
5:   ✓ Integer comparisons - test case passed (8 checks)
5:
5:   • Failed integer comparisons - test case started
5:     ✗ actual != 42 FAILED (micro-test-plus.h:102, 42 != 42)
5:     ✗ actual+1 == 42 FAILED (micro-test-plus.h:102, 43 == 42)
5:     ✗ actual-1 >= 42 FAILED (micro-test-plus.h:102, 41 >= 42)
5:     ✗ actual > 42 FAILED (micro-test-plus.h:102, 42 > 42)
5:     ✗ actual+1 <= 42 FAILED (micro-test-plus.h:102, 43 <= 42)
5:     ✗ actual < 42 FAILED (micro-test-plus.h:102, 42 < 42)
5:     ✗ FAILED (micro-test-plus.h:102, 42 != 42)
5:     ✗ 42 != 42_i FAILED (micro-test-plus.h:102, 42 != 42)
5:   ✗ Failed integer comparisons - test case FAILED (0 checks passed, 8 failed)
5:
5:   ✓ Float comparisons - test case passed (27 checks)
5:
5:   • Failed float comparisons - test case started
5:     ✗ actual != 42.0 FAILED (micro-test-plus.h:102, 42.000000f != 42.000000f)
5:     ✗ actual == 43.0 FAILED (micro-test-plus.h:102, 42.000000f == 43.000000f)
5:     ✗ actual != 42 FAILED (micro-test-plus.h:102, 42.000000f != 42)
5:     ✗ actual == 43 FAILED (micro-test-plus.h:102, 42.000000f == 43)
5:     ✗ 42.101f != 42.101_f FAILED (micro-test-plus.h:102, 42.101002f != 42.101002f)
5:     ✗ 42.101f epsilon 0.01f != 42.10_f FAILED (micro-test-plus.h:102, 42.101002f != 42.099998f)
5:     ✗ 42.101f epsilon 0.1f == 42.10_f FAILED (micro-test-plus.h:102, 42.101002f == 42.099998f)
5:     ✗ 42.1010001f epsilon 0.1f != 42.1_f FAILED (micro-test-plus.h:102, 42.101002f != 42.099998f)
5:     ✗ 42.101f == 42.10_f FAILED (micro-test-plus.h:102, 42.101002f == 42.099998f)
5:     ✗ 42.101f == 42.100_f FAILED (micro-test-plus.h:102, 42.101002f == 42.099998f)
5:     ✗ 42.10f == 42.1_f FAILED (micro-test-plus.h:102, 42.099998f != 42.099998f)
5:     ✗ 42.42f == 42.42_f FAILED (micro-test-plus.h:102, 42.419998f != 42.419998f)
5:     ✗ 42.42 == 42.420_d FAILED (micro-test-plus.h:102, 42.420000 != 42.420000)
5:     ✗ 42.0 == 42.0_d FAILED (micro-test-plus.h:102, 42.000000 != 42.000000)
5:     ✗ 42. == 42._d FAILED (micro-test-plus.h:102, 42.000000 != 42.000000)
5:     ✗ 42.42 == 42.42_ld FAILED (micro-test-plus.h:102, 42.420000l != 42.420000l)
5:     ✗ 1234._f == 1234.f FAILED (micro-test-plus.h:102, 1234.000000f != 1234.000000f)
5:     ✗ 1234.56_f == 1234.56f FAILED (micro-test-plus.h:102, 1234.560059f != 1234.560059f)
5:     ✗ 12345678.9f == 12345678.9_f FAILED (micro-test-plus.h:102, 12345679.000000f != 12345679.000000f)
5:     ✗ 111111.42f == 111111.42_f FAILED (micro-test-plus.h:102, 111111.421875f != 111111.421875f)
5:     ✗ 1111111111.42 == 1111111111.42_d FAILED (micro-test-plus.h:102, 1111111111.420000 != 1111111111.420000)
5:   ✗ Failed float comparisons - test case FAILED (0 checks passed, 21 failed)
5:
5:   ✓ String comparisons - test case passed (6 checks)
5:
5:   • Failed string comparisons - test case started
5:     ✗ actual_sv != abc_sv FAILED (micro-test-plus.h:102, abc != abc)
5:     ✗ actual_sv == abx_sv FAILED (micro-test-plus.h:102, abc == abx)
5:     ✗ actual_sv >= abd_sv FAILED (micro-test-plus.h:102, abc >= abd)
5:     ✗ actual_sv > abc_sv FAILED (micro-test-plus.h:102, abc > abc)
5:     ✗ actual_sv <= abb_sv FAILED (micro-test-plus.h:102, abc <= abb)
5:     ✗ actual_sv < abc_sv FAILED (micro-test-plus.h:102, abc < abc)
5:   ✗ Failed string comparisons - test case FAILED (0 checks passed, 6 failed)
5:
5:   ✓ Pointer comparisons - test case passed (9 checks)
5:
5:   • Failed pointer comparisons - test case started
5:     ✗ ptr1 != &one FAILED (micro-test-plus.h:102, 0x7ff7b286ce2c != 0x7ff7b286ce2c)
5:     ✗ ptr1 != ptr2 FAILED (micro-test-plus.h:102, 0x7ff7b286ce2c != 0x7ff7b286ce2c)
5:     ✗ ptr1 > ptr2 FAILED (micro-test-plus.h:102, 0x7ff7b286ce2c > 0x7ff7b286ce2c)
5:     ✗ ptr1 < ptr2 FAILED (micro-test-plus.h:102, 0x7ff7b286ce2c < 0x7ff7b286ce2c)
5:     ✗ ptr1 == a_non_nullptr FAILED (micro-test-plus.h:102, 0x7ff7b286ce2c == 0x7ff7b286ce90)
5:     ✗ pfunc != afunc FAILED (micro-test-plus.h:102, 0x10d6d2e30 != 0x10d6d2e30)
5:     ✗ pfunc == a_non_nullptr FAILED (micro-test-plus.h:102, 0x10d6d2e30 == 0x7ff7b286ce90)
5:     ✗ pone >= ptwo FAILED (micro-test-plus.h:102, 0x7ff7b286ce38 >= 0x7ff7b286ce3c)
5:     ✗ ptwo <= pone FAILED (micro-test-plus.h:102, 0x7ff7b286ce3c <= 0x7ff7b286ce38)
5:   ✗ Failed pointer comparisons - test case FAILED (0 checks passed, 9 failed)
5:
5:   ✓ Null pointer comparisons - test case passed (3 checks)
5:
5:   • Failed null pointer comparisons - test case started
5:     ✗ a_nullptr != nullptr FAILED (micro-test-plus.h:102, 0x0 != nullptr)
5:     ✗ a_non_nullptr == nullptr FAILED (micro-test-plus.h:102, 0x7ff7b286ce90 == nullptr)
5:     ✗ pfunc != nullptr FAILED (micro-test-plus.h:102, 0x0 != nullptr)
5:   ✗ Failed null pointer comparisons - test case FAILED (0 checks passed, 3 failed)
5:
5:   ✓ reflection::type_name() - test case passed (2 checks)
5:   ✓ thrown exceptions - test case passed (2 checks)
5:
5:   • Failed thrown exceptions - test case started
5:     ✗ exception thrown FAILED (micro-test-plus.h:102, throws)
5:     ✗ std::runtime_error thrown FAILED (micro-test-plus.h:102, throws<std::runtime_error>)
5:   ✗ Failed thrown exceptions - test case FAILED (0 checks passed, 2 failed)
5:
5:   ✓ Not thrown exceptions - test case passed (1 check)
5:
5:   • Failed not thrown exceptions - test case started
5:     ✗ exception not thrown FAILED (micro-test-plus.h:102, nothrow)
5:   ✗ Failed not thrown exceptions - test case FAILED (0 checks passed, 1 failed)
5:
5:   • Logical operations - test case started
5:     ✓ not (actual != 42)
5:     ✗ not (actual == 42) FAILED (micro-test-plus.h:102, not 42 == 42)
5:     ✓ (actual == 42) and (actual == 42.0)
5:     ✗ (actual == 42) and (actual != 42.0) FAILED (micro-test-plus.h:102, (42 == 42 and 42.000000f != 42.000000))
5:     ✗ (actual != 42) and (actual == 42.0) FAILED (micro-test-plus.h:102, (42 != 42 and 42.000000f == 42.000000))
5:     ✗ (actual != 42) and (actual != 42.0) FAILED (micro-test-plus.h:102, (42 != 42 and 42.000000f != 42.000000))
5:     ✓ (42 == 42 and 42.000000f == 42.000000)
5:     ✗ FAILED (micro-test-plus.h:102, (42 == 42 and 42.000000f != 42.000000))
5:     ✓ (actual == 42) or (actual == 42.0)
5:     ✓ (actual == 42) or (actual != 42.0)
5:     ✓ (actual != 42) or (actual == 42.0)
5:     ✗ (actual != 42) or (actual != 42.0) FAILED (micro-test-plus.h:102, (42 != 42 or 42.000000f != 42.000000))
5:   ✗ Logical operations - test case FAILED (6 checks passed, 6 failed)
5:
5:   • Operators - test case started
5:     ✓ actual == 42
5:     ✗ actual+1 == 42 with scalar FAILED (micro-test-plus.h:102)
5:     ✗ actual+1 == 42 with _i literal FAILED (micro-test-plus.h:102, 43 == 42)
5:     ✗ actual+1 == 42 with _i() FAILED (micro-test-plus.h:102, 43 == 42)
5:     ✓ actual+1 != 42
5:     ✓ actual-1 < 42
5:     ✓ actual <= 42
5:     ✓ actual+1 > 42
5:     ✓ actual >= 42
5:     ✓ not (actual != 42)
5:     ✗ not (actual == 42) FAILED (micro-test-plus.h:102, not 42 == 42)
5:     ✓ (actual == 42) and (actual == 42.0)
5:     ✗ (actual == 42) and (actual != 42.0) FAILED (micro-test-plus.h:102, (42 == 42 and 42.000000f != 42.000000))
5:     ✗ (actual != 42) and (actual == 42.0) FAILED (micro-test-plus.h:102, (42 != 42 and 42.000000f == 42.000000))
5:     ✗ (actual != 42) and (actual != 42.0) FAILED (micro-test-plus.h:102, (42 != 42 and 42.000000f != 42.000000))
5:     ✓ (42 == 42 and 42.000000f == 42.000000)
5:     ✗ FAILED (micro-test-plus.h:102, (42 == 42 and 42.000000f != 42.000000))
5:     ✓ (actual == 42) or (actual == 42.0)
5:     ✓ (actual == 42) or (actual != 42.0)
5:     ✓ (actual != 42) or (actual == 42.0)
5:     ✗ (actual != 42) or (actual != 42.0) FAILED (micro-test-plus.h:102, (42 != 42 or 42.000000f != 42.000000f))
5:   ✗ Operators - test case FAILED (12 checks passed, 9 failed)
5:
5:   ✓ Strings matches - test case passed (6 checks)
5:
5:   • Failed strings matches - test case started
5:     ✗ empty matches abc FAILED (micro-test-plus.h:102)
5:     ✗ abc matches b?? FAILED (micro-test-plus.h:102)
5:     ✗ abc matches a*d FAILED (micro-test-plus.h:102)
5:     ✗ abc matches *C FAILED (micro-test-plus.h:102)
5:   ✗ Failed strings matches - test case FAILED (0 checks passed, 4 failed)
5:
5:   ✓ Splits - test case passed (4 checks)
5:
5: ✗ Main - test suite FAILED (92 checks passed, 71 failed, in 23 test cases)
5:
5: • Combinatorial integrals - test suite started
5:
5:   ✓ Combinatorial integrals with signed long long - test case passed (20 checks)
5:   ✓ Combinatorial integrals unsigned long long - test case passed (20 checks)
5:   ✓ Combinatorial integrals with signed int - test case passed (20 checks)
5:   ✓ Combinatorial integrals with unsigned int - test case passed (20 checks)
5:   ✓ Combinatorial integrals with signed short - test case passed (20 checks)
5:   ✓ Combinatorial integrals with unsigned short - test case passed (20 checks)
5:   ✓ Combinatorial integrals with signed short - test case passed (20 checks)
5:   ✓ Combinatorial integrals with unsigned short - test case passed (20 checks)
5:   ✓ Combinatorial integrals with signed char - test case passed (20 checks)
5:   ✓ Combinatorial integrals with unsigned char - test case passed (20 checks)
5:
5: ✓ Combinatorial integrals - test suite passed (200 checks in 10 test cases)
5:
5: • Failed combinatorial integrals - test suite started
5:
5:   • Combinatorial integrals with signed long long - test case started
5:     ✗ ne matches signed long long FAILED (micro-test-plus.h:102, 42ll != 42ll)
5:     ✗ ne matches unsigned long long FAILED (micro-test-plus.h:102, 42ll != 42ull)
5:     ✗ ne matches signed long FAILED (micro-test-plus.h:102, 42ll != 42l)
5:     ✗ ne matches unsigned long FAILED (micro-test-plus.h:102, 42ll != 42ul)
5:     ✗ ne matches signed int FAILED (micro-test-plus.h:102, 42ll != 42)
5:     ✗ ne matches unsigned int FAILED (micro-test-plus.h:102, 42ll != 42u)
5:     ✗ ne matches signed short FAILED (micro-test-plus.h:102, 42ll != 42s)
5:     ✗ ne matches unsigned short FAILED (micro-test-plus.h:102, 42ll != 42us)
5:     ✗ ne matches signed char FAILED (micro-test-plus.h:102, 42ll != 42c)
5:     ✗ ne matches unsigned char FAILED (micro-test-plus.h:102, 42ll != 42uc)
5:     ✗ gt matches signed int FAILED (micro-test-plus.h:102, 42ll > 42)
5:     ✗ lt matches signed int FAILED (micro-test-plus.h:102, 42ll < 42)
5:     ✗ eq matches signed int FAILED (micro-test-plus.h:102, 43ll == 42)
5:     ✗ ge matches signed int FAILED (micro-test-plus.h:102, 41ll >= 42)
5:     ✗ le matches signed int FAILED (micro-test-plus.h:102, 43ll <= 42)
5:     ✗ gt matches unsigned int FAILED (micro-test-plus.h:102, 42ll > 42u)
5:     ✗ lt matches unsigned int FAILED (micro-test-plus.h:102, 42ll < 42u)
5:     ✗ eq matches unsigned int FAILED (micro-test-plus.h:102, 43ll == 42u)
5:     ✗ ge matches unsigned int FAILED (micro-test-plus.h:102, 41ll >= 42u)
5:     ✗ le matches unsigned int FAILED (micro-test-plus.h:102, 43ll <= 42u)
5:   ✗ Combinatorial integrals with signed long long - test case FAILED (0 checks passed, 20 failed)
5:
5:   • Combinatorial integrals unsigned long long - test case started
5:     ✗ ne matches signed long long FAILED (micro-test-plus.h:102, 42ull != 42ll)
5:     ✗ ne matches unsigned long long FAILED (micro-test-plus.h:102, 42ull != 42ull)
5:     ✗ ne matches signed long FAILED (micro-test-plus.h:102, 42ull != 42l)
5:     ✗ ne matches unsigned long FAILED (micro-test-plus.h:102, 42ull != 42ul)
5:     ✗ ne matches signed int FAILED (micro-test-plus.h:102, 42ull != 42)
5:     ✗ ne matches unsigned int FAILED (micro-test-plus.h:102, 42ull != 42u)
5:     ✗ ne matches signed short FAILED (micro-test-plus.h:102, 42ull != 42s)
5:     ✗ ne matches unsigned short FAILED (micro-test-plus.h:102, 42ull != 42us)
5:     ✗ ne matches signed char FAILED (micro-test-plus.h:102, 42ull != 42c)
5:     ✗ ne matches unsigned char FAILED (micro-test-plus.h:102, 42ull != 42uc)
5:     ✗ gt matches signed int FAILED (micro-test-plus.h:102, 42ull > 42)
5:     ✗ lt matches signed int FAILED (micro-test-plus.h:102, 42ull < 42)
5:     ✗ eq matches signed int FAILED (micro-test-plus.h:102, 43ull == 42)
5:     ✗ ge matches signed int FAILED (micro-test-plus.h:102, 41ull >= 42)
5:     ✗ le matches signed int FAILED (micro-test-plus.h:102, 43ull <= 42)
5:     ✗ gt matches unsigned int FAILED (micro-test-plus.h:102, 42ull > 42u)
5:     ✗ lt matches unsigned int FAILED (micro-test-plus.h:102, 42ull < 42u)
5:     ✗ eq matches unsigned int FAILED (micro-test-plus.h:102, 43ull == 42u)
5:     ✗ ge matches unsigned int FAILED (micro-test-plus.h:102, 41ull >= 42u)
5:     ✗ le matches unsigned int FAILED (micro-test-plus.h:102, 43ull <= 42u)
5:   ✗ Combinatorial integrals unsigned long long - test case FAILED (0 checks passed, 20 failed)
5:
5:   • Combinatorial integrals with signed int - test case started
5:     ✗ ne matches signed long long FAILED (micro-test-plus.h:102, 42 != 42ll)
5:     ✗ ne matches unsigned long long FAILED (micro-test-plus.h:102, 42 != 42ull)
5:     ✗ ne matches signed long FAILED (micro-test-plus.h:102, 42 != 42l)
5:     ✗ ne matches unsigned long FAILED (micro-test-plus.h:102, 42 != 42ul)
5:     ✗ ne matches signed int FAILED (micro-test-plus.h:102, 42 != 42)
5:     ✗ ne matches unsigned int FAILED (micro-test-plus.h:102, 42 != 42u)
5:     ✗ ne matches signed short FAILED (micro-test-plus.h:102, 42 != 42s)
5:     ✗ ne matches unsigned short FAILED (micro-test-plus.h:102, 42 != 42us)
5:     ✗ ne matches signed char FAILED (micro-test-plus.h:102, 42 != 42c)
5:     ✗ ne matches unsigned char FAILED (micro-test-plus.h:102, 42 != 42uc)
5:     ✗ gt matches signed int FAILED (micro-test-plus.h:102, 42 > 42)
5:     ✗ lt matches signed int FAILED (micro-test-plus.h:102, 42 < 42)
5:     ✗ eq matches signed int FAILED (micro-test-plus.h:102, 43 == 42)
5:     ✗ ge matches signed int FAILED (micro-test-plus.h:102, 41 >= 42)
5:     ✗ le matches signed int FAILED (micro-test-plus.h:102, 43 <= 42)
5:     ✗ gt matches unsigned int FAILED (micro-test-plus.h:102, 42 > 42u)
5:     ✗ lt matches unsigned int FAILED (micro-test-plus.h:102, 42 < 42u)
5:     ✗ eq matches unsigned int FAILED (micro-test-plus.h:102, 43 == 42u)
5:     ✗ ge matches unsigned int FAILED (micro-test-plus.h:102, 41 >= 42u)
5:     ✗ le matches unsigned int FAILED (micro-test-plus.h:102, 43 <= 42u)
5:   ✗ Combinatorial integrals with signed int - test case FAILED (0 checks passed, 20 failed)
5:
5:   • Combinatorial integrals with unsigned int - test case started
5:     ✗ ne matches signed long long FAILED (micro-test-plus.h:102, 42u != 42ll)
5:     ✗ ne matches unsigned long long FAILED (micro-test-plus.h:102, 42u != 42ull)
5:     ✗ ne matches signed long FAILED (micro-test-plus.h:102, 42u != 42l)
5:     ✗ ne matches unsigned long FAILED (micro-test-plus.h:102, 42u != 42ul)
5:     ✗ ne matches signed int FAILED (micro-test-plus.h:102, 42u != 42)
5:     ✗ ne matches unsigned int FAILED (micro-test-plus.h:102, 42u != 42u)
5:     ✗ ne matches signed short FAILED (micro-test-plus.h:102, 42u != 42s)
5:     ✗ ne matches unsigned short FAILED (micro-test-plus.h:102, 42u != 42us)
5:     ✗ ne matches signed char FAILED (micro-test-plus.h:102, 42u != 42c)
5:     ✗ ne matches unsigned char FAILED (micro-test-plus.h:102, 42u != 42uc)
5:     ✗ gt matches signed int FAILED (micro-test-plus.h:102, 42u > 42)
5:     ✗ lt matches signed int FAILED (micro-test-plus.h:102, 42u < 42)
5:     ✗ eq matches signed int FAILED (micro-test-plus.h:102, 43u == 42)
5:     ✗ ge matches signed int FAILED (micro-test-plus.h:102, 41u >= 42)
5:     ✗ le matches signed int FAILED (micro-test-plus.h:102, 43u <= 42)
5:     ✗ gt matches unsigned int FAILED (micro-test-plus.h:102, 42u > 42u)
5:     ✗ lt matches unsigned int FAILED (micro-test-plus.h:102, 42u < 42u)
5:     ✗ eq matches unsigned int FAILED (micro-test-plus.h:102, 43u == 42u)
5:     ✗ ge matches unsigned int FAILED (micro-test-plus.h:102, 41u >= 42u)
5:     ✗ le matches unsigned int FAILED (micro-test-plus.h:102, 43u <= 42u)
5:   ✗ Combinatorial integrals with unsigned int - test case FAILED (0 checks passed, 20 failed)
5:
5:   • Combinatorial integrals with signed short - test case started
5:     ✗ ne matches signed long long FAILED (micro-test-plus.h:102, 42 != 42ll)
5:     ✗ ne matches unsigned long long FAILED (micro-test-plus.h:102, 42 != 42ull)
5:     ✗ ne matches signed long FAILED (micro-test-plus.h:102, 42 != 42l)
5:     ✗ ne matches unsigned long FAILED (micro-test-plus.h:102, 42 != 42ul)
5:     ✗ ne matches signed int FAILED (micro-test-plus.h:102, 42 != 42)
5:     ✗ ne matches unsigned int FAILED (micro-test-plus.h:102, 42 != 42u)
5:     ✗ ne matches signed short FAILED (micro-test-plus.h:102, 42 != 42s)
5:     ✗ ne matches unsigned short FAILED (micro-test-plus.h:102, 42 != 42us)
5:     ✗ ne matches signed char FAILED (micro-test-plus.h:102, 42 != 42c)
5:     ✗ ne matches unsigned char FAILED (micro-test-plus.h:102, 42 != 42uc)
5:     ✗ gt matches signed int FAILED (micro-test-plus.h:102, 42 > 42)
5:     ✗ lt matches signed int FAILED (micro-test-plus.h:102, 42 < 42)
5:     ✗ eq matches signed int FAILED (micro-test-plus.h:102, 43 == 42)
5:     ✗ ge matches signed int FAILED (micro-test-plus.h:102, 41 >= 42)
5:     ✗ le matches signed int FAILED (micro-test-plus.h:102, 43 <= 42)
5:     ✗ gt matches unsigned int FAILED (micro-test-plus.h:102, 42 > 42u)
5:     ✗ lt matches unsigned int FAILED (micro-test-plus.h:102, 42 < 42u)
5:     ✗ eq matches unsigned int FAILED (micro-test-plus.h:102, 43 == 42u)
5:     ✗ ge matches unsigned int FAILED (micro-test-plus.h:102, 41 >= 42u)
5:     ✗ le matches unsigned int FAILED (micro-test-plus.h:102, 43 <= 42u)
5:   ✗ Combinatorial integrals with signed short - test case FAILED (0 checks passed, 20 failed)
5:
5:   • Combinatorial integrals with unsigned short - test case started
5:     ✗ ne matches signed long long FAILED (micro-test-plus.h:102, 42u != 42ll)
5:     ✗ ne matches unsigned long long FAILED (micro-test-plus.h:102, 42u != 42ull)
5:     ✗ ne matches signed long FAILED (micro-test-plus.h:102, 42u != 42l)
5:     ✗ ne matches unsigned long FAILED (micro-test-plus.h:102, 42u != 42ul)
5:     ✗ ne matches signed int FAILED (micro-test-plus.h:102, 42u != 42)
5:     ✗ ne matches unsigned int FAILED (micro-test-plus.h:102, 42u != 42u)
5:     ✗ ne matches signed short FAILED (micro-test-plus.h:102, 42u != 42s)
5:     ✗ ne matches unsigned short FAILED (micro-test-plus.h:102, 42u != 42us)
5:     ✗ ne matches signed char FAILED (micro-test-plus.h:102, 42u != 42c)
5:     ✗ ne matches unsigned char FAILED (micro-test-plus.h:102, 42u != 42uc)
5:     ✗ gt matches signed int FAILED (micro-test-plus.h:102, 42u > 42)
5:     ✗ lt matches signed int FAILED (micro-test-plus.h:102, 42u < 42)
5:     ✗ eq matches signed int FAILED (micro-test-plus.h:102, 43u == 42)
5:     ✗ ge matches signed int FAILED (micro-test-plus.h:102, 41u >= 42)
5:     ✗ le matches signed int FAILED (micro-test-plus.h:102, 43u <= 42)
5:     ✗ gt matches unsigned int FAILED (micro-test-plus.h:102, 42u > 42u)
5:     ✗ lt matches unsigned int FAILED (micro-test-plus.h:102, 42u < 42u)
5:     ✗ eq matches unsigned int FAILED (micro-test-plus.h:102, 43u == 42u)
5:     ✗ ge matches unsigned int FAILED (micro-test-plus.h:102, 41u >= 42u)
5:     ✗ le matches unsigned int FAILED (micro-test-plus.h:102, 43u <= 42u)
5:   ✗ Combinatorial integrals with unsigned short - test case FAILED (0 checks passed, 20 failed)
5:
5:   • Combinatorial integrals with signed short - test case started
5:     ✗ ne matches signed long long FAILED (micro-test-plus.h:102, 42s != 42ll)
5:     ✗ ne matches unsigned long long FAILED (micro-test-plus.h:102, 42s != 42ull)
5:     ✗ ne matches signed long FAILED (micro-test-plus.h:102, 42s != 42l)
5:     ✗ ne matches unsigned long FAILED (micro-test-plus.h:102, 42s != 42ul)
5:     ✗ ne matches signed int FAILED (micro-test-plus.h:102, 42s != 42)
5:     ✗ ne matches unsigned int FAILED (micro-test-plus.h:102, 42s != 42u)
5:     ✗ ne matches signed short FAILED (micro-test-plus.h:102, 42s != 42s)
5:     ✗ ne matches unsigned short FAILED (micro-test-plus.h:102, 42s != 42us)
5:     ✗ ne matches signed char FAILED (micro-test-plus.h:102, 42s != 42c)
5:     ✗ ne matches unsigned char FAILED (micro-test-plus.h:102, 42s != 42uc)
5:     ✗ gt matches signed int FAILED (micro-test-plus.h:102, 42s > 42)
5:     ✗ lt matches signed int FAILED (micro-test-plus.h:102, 42s < 42)
5:     ✗ eq matches signed int FAILED (micro-test-plus.h:102, 43s == 42)
5:     ✗ ge matches signed int FAILED (micro-test-plus.h:102, 41s >= 42)
5:     ✗ le matches signed int FAILED (micro-test-plus.h:102, 43s <= 42)
5:     ✗ gt matches unsigned int FAILED (micro-test-plus.h:102, 42s > 42u)
5:     ✗ lt matches unsigned int FAILED (micro-test-plus.h:102, 42s < 42u)
5:     ✗ eq matches unsigned int FAILED (micro-test-plus.h:102, 43s == 42u)
5:     ✗ ge matches unsigned int FAILED (micro-test-plus.h:102, 41s >= 42u)
5:     ✗ le matches unsigned int FAILED (micro-test-plus.h:102, 43s <= 42u)
5:   ✗ Combinatorial integrals with signed short - test case FAILED (0 checks passed, 20 failed)
5:
5:   • Combinatorial integrals with unsigned short - test case started
5:     ✗ ne matches signed long long FAILED (micro-test-plus.h:102, 42us != 42ll)
5:     ✗ ne matches unsigned long long FAILED (micro-test-plus.h:102, 42us != 42ull)
5:     ✗ ne matches signed long FAILED (micro-test-plus.h:102, 42us != 42l)
5:     ✗ ne matches unsigned long FAILED (micro-test-plus.h:102, 42us != 42ul)
5:     ✗ ne matches signed int FAILED (micro-test-plus.h:102, 42us != 42)
5:     ✗ ne matches unsigned int FAILED (micro-test-plus.h:102, 42us != 42u)
5:     ✗ ne matches signed short FAILED (micro-test-plus.h:102, 42us != 42s)
5:     ✗ ne matches unsigned short FAILED (micro-test-plus.h:102, 42us != 42us)
5:     ✗ ne matches signed char FAILED (micro-test-plus.h:102, 42us != 42c)
5:     ✗ ne matches unsigned char FAILED (micro-test-plus.h:102, 42us != 42uc)
5:     ✗ gt matches signed int FAILED (micro-test-plus.h:102, 42us > 42)
5:     ✗ lt matches signed int FAILED (micro-test-plus.h:102, 42us < 42)
5:     ✗ eq matches signed int FAILED (micro-test-plus.h:102, 43us == 42)
5:     ✗ ge matches signed int FAILED (micro-test-plus.h:102, 41us >= 42)
5:     ✗ le matches signed int FAILED (micro-test-plus.h:102, 43us <= 42)
5:     ✗ gt matches unsigned int FAILED (micro-test-plus.h:102, 42us > 42u)
5:     ✗ lt matches unsigned int FAILED (micro-test-plus.h:102, 42us < 42u)
5:     ✗ eq matches unsigned int FAILED (micro-test-plus.h:102, 43us == 42u)
5:     ✗ ge matches unsigned int FAILED (micro-test-plus.h:102, 41us >= 42u)
5:     ✗ le matches unsigned int FAILED (micro-test-plus.h:102, 43us <= 42u)
5:   ✗ Combinatorial integrals with unsigned short - test case FAILED (0 checks passed, 20 failed)
5:
5:   • Combinatorial integrals with signed char - test case started
5:     ✗ ne matches signed long long FAILED (micro-test-plus.h:102, 42c != 42ll)
5:     ✗ ne matches unsigned long long FAILED (micro-test-plus.h:102, 42c != 42ull)
5:     ✗ ne matches signed long FAILED (micro-test-plus.h:102, 42c != 42l)
5:     ✗ ne matches unsigned long FAILED (micro-test-plus.h:102, 42c != 42ul)
5:     ✗ ne matches signed int FAILED (micro-test-plus.h:102, 42c != 42)
5:     ✗ ne matches unsigned int FAILED (micro-test-plus.h:102, 42c != 42u)
5:     ✗ ne matches signed short FAILED (micro-test-plus.h:102, 42c != 42s)
5:     ✗ ne matches unsigned short FAILED (micro-test-plus.h:102, 42c != 42us)
5:     ✗ ne matches signed char FAILED (micro-test-plus.h:102, 42c != 42c)
5:     ✗ ne matches unsigned char FAILED (micro-test-plus.h:102, 42c != 42uc)
5:     ✗ gt matches signed int FAILED (micro-test-plus.h:102, 42c > 42)
5:     ✗ lt matches signed int FAILED (micro-test-plus.h:102, 42c < 42)
5:     ✗ eq matches signed int FAILED (micro-test-plus.h:102, 43c == 42)
5:     ✗ ge matches signed int FAILED (micro-test-plus.h:102, 41c >= 42)
5:     ✗ le matches signed int FAILED (micro-test-plus.h:102, 43c <= 42)
5:     ✗ gt matches unsigned int FAILED (micro-test-plus.h:102, 42c > 42u)
5:     ✗ lt matches unsigned int FAILED (micro-test-plus.h:102, 42c < 42u)
5:     ✗ eq matches unsigned int FAILED (micro-test-plus.h:102, 43c == 42u)
5:     ✗ ge matches unsigned int FAILED (micro-test-plus.h:102, 41c >= 42u)
5:     ✗ le matches unsigned int FAILED (micro-test-plus.h:102, 43c <= 42u)
5:   ✗ Combinatorial integrals with signed char - test case FAILED (0 checks passed, 20 failed)
5:
5:   • Combinatorial integrals with unsigned char - test case started
5:     ✗ ne matches signed long long FAILED (micro-test-plus.h:102, 42uc != 42ll)
5:     ✗ ne matches unsigned long long FAILED (micro-test-plus.h:102, 42uc != 42ull)
5:     ✗ ne matches signed long FAILED (micro-test-plus.h:102, 42uc != 42l)
5:     ✗ ne matches unsigned long FAILED (micro-test-plus.h:102, 42uc != 42ul)
5:     ✗ ne matches signed int FAILED (micro-test-plus.h:102, 42uc != 42)
5:     ✗ ne matches unsigned int FAILED (micro-test-plus.h:102, 42uc != 42u)
5:     ✗ ne matches signed short FAILED (micro-test-plus.h:102, 42uc != 42s)
5:     ✗ ne matches unsigned short FAILED (micro-test-plus.h:102, 42uc != 42us)
5:     ✗ ne matches signed char FAILED (micro-test-plus.h:102, 42uc != 42c)
5:     ✗ ne matches unsigned char FAILED (micro-test-plus.h:102, 42uc != 42uc)
5:     ✗ gt matches signed int FAILED (micro-test-plus.h:102, 42uc > 42)
5:     ✗ lt matches signed int FAILED (micro-test-plus.h:102, 42uc < 42)
5:     ✗ eq matches signed int FAILED (micro-test-plus.h:102, 43uc == 42)
5:     ✗ ge matches signed int FAILED (micro-test-plus.h:102, 41uc >= 42)
5:     ✗ le matches signed int FAILED (micro-test-plus.h:102, 43uc <= 42)
5:     ✗ gt matches unsigned int FAILED (micro-test-plus.h:102, 42uc > 42u)
5:     ✗ lt matches unsigned int FAILED (micro-test-plus.h:102, 42uc < 42u)
5:     ✗ eq matches unsigned int FAILED (micro-test-plus.h:102, 43uc == 42u)
5:     ✗ ge matches unsigned int FAILED (micro-test-plus.h:102, 41uc >= 42u)
5:     ✗ le matches unsigned int FAILED (micro-test-plus.h:102, 43uc <= 42u)
5:   ✗ Combinatorial integrals with unsigned char - test case FAILED (0 checks passed, 20 failed)
5:
5: ✗ Failed combinatorial integrals - test suite FAILED (0 checks passed, 200 failed, in 10 test cases)
5:
5: • Combinatorial floats - test suite started
5:
5:   ✓ Combinatorial floats - test case passed (11 checks)
5:   ✓ Combinatorial doubles - test case passed (11 checks)
5:
5: ✓ Combinatorial floats - test suite passed (22 checks in 2 test cases)
5:
5: • Miscellaneous - test suite started
5:
5:   ✓ Arrays - test case passed (4 checks)
5:
5:   • Arrays failed - test case started
5:     ✗ array{ 42 } ne array{ 42 } FAILED (micro-test-plus.h:102, {42} != {42})
5:     ✗ array{ 42 } eq array{ 43 } FAILED (micro-test-plus.h:102, {42} == {43})
5:     ✗ array{ 1, 2 } ne array{ 1, 2 } FAILED (micro-test-plus.h:102, {1, 2} != {1, 2})
5:     ✗ array{ 1, 2, 3 } eq array{ 1, 2, 4 } FAILED (micro-test-plus.h:102, {1, 2, 3} == {1, 2, 4})
5:   ✗ Arrays failed - test case FAILED (0 checks passed, 4 failed)
5:
5:   ✓ Vectors - test case passed (6 checks)
5:
5:   • Vectors failed - test case started
5:     ✗ vector{ } != vector{ } FAILED (micro-test-plus.h:102, {} != {})
5:     ✗ FAILED (micro-test-plus.h:102, {} != {})
5:     ✗ vector{ 42 } != vector{ 42 } FAILED (micro-test-plus.h:102, {42} != {42})
5:     ✗ vector{ 42 } == vector{ 43 } FAILED (micro-test-plus.h:102, {42} == {43})
5:     ✗ vector{ 1, 2 } != vector{ 1, 2 } FAILED (micro-test-plus.h:102, {1, 2} != {1, 2})
5:     ✗ vector{ 1, 2, 3 } == vector{ 1, 2, 4 } FAILED (micro-test-plus.h:102, {1, 2, 3} == {1, 2, 4})
5:   ✗ Vectors failed - test case FAILED (0 checks passed, 6 failed)
5:
5: ✗ Miscellaneous - test suite FAILED (10 checks passed, 10 failed, in 4 test cases)
5: Overall, the µTest++ unit tests were successful!
5:
5/8 Test #5: unit-test ........................   Passed    0.01 sec
```

## Continuous Integration

There is a GitHub Actions CI
[workflow](https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/ci.yml)
that runs a selection of the
tests on every push; for details see
[ci.yml](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/.github/workflows/ci.yml).

## Extensive testing

A second
[workflow](https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/test-all.yml)
can be triggered manually before releases, and runs all available tests
on all supported platforms; for details see
[test-all.yml](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/.github/workflows/test-all.yml).

@note
Running these tests on Apple Silicon macOS and Arm GNU/Linux
require the self-hosted runners for the `micro-os-plus` GitHub
organisation to be up and running.

## Manual runs

The tests can be executed manually on any of the supported
platforms:

- GNU/Linux (Intel and Arm, **GLIBC>=2.27**); to run the native
tests, a C++ development environment is required
(on Ubuntu install `build-essential`)
- macOS (Intel >= **10.13** and Apple Silicon > **11.1**);
as C++ development environment use **Command Line Tools**
- Windows 7 with the Universal C Runtime (UCRT), Windows 8, Windows 10,
Windows 11

### Prerequisites

A recent **Node.js** (>=16) run environment. For instructions on how to
install it, see the [prerequisites](https://xpack.github.io/install/) page.

With **npm** available, install **xpm**:

```sh
npm install --global xpm@latest
```

### Clone the project

To clone the development branch (`xpack-develop`), run the following commands in a
terminal (on Windows use the _Git Bash_ console):

```sh
rm -rf ~/Work/micro-os-plus/micro-test-plus-xpack.git && \
mkdir -p ~/Work/micro-os-plus && \
git clone \
  --branch xpack-develop \
  https://github.com/micro-os-plus/micro-test-plus-xpack.git \
  ~/Work/micro-os-plus/micro-test-plus-xpack.git
```

### Run the tests

There are multiple predefined actions, to run various selections of tests,
from a single run with the system compiler, to all possible tests.

@note
On the first run, the install step might take quite some time,
since it has to download the toolchain archives, which are relatively
large, up to hundreds of MB.

To run the tests with the system compiler:

```sh
xpm run install -C ~/Work/micro-os-plus/micro-test-plus-xpack.git/tests
xpm run test -C ~/Work/micro-os-plus/micro-test-plus-xpack.git/tests
```

To run a selection of tests with the latest versions of the toolchains:

```sh
xpm run install-selected -C ~/Work/micro-os-plus/micro-test-plus-xpack.git/tests
xpm run test-selected -C ~/Work/micro-os-plus/micro-test-plus-xpack.git/tests
```

To run all tests with the latest versions of the toolchains:

```sh
xpm run install-latest -C ~/Work/micro-os-plus/micro-test-plus-xpack.git/tests
xpm run test-latest -C ~/Work/micro-os-plus/micro-test-plus-xpack.git/tests
```

To run all tests with all toolchain versions:

```sh
xpm run install-all -C ~/Work/micro-os-plus/micro-test-plus-xpack.git/tests
xpm run test-all -C ~/Work/micro-os-plus/micro-test-plus-xpack.git/tests
```

### Cleanups

To do a deep cleanup in order to free space or to restart the tests
from scratch:

```sh
npm install -C ~/Work/micro-os-plus/micro-test-plus-xpack.git/tests
xpm run deep-clean -C ~/Work/micro-os-plus/micro-test-plus-xpack.git/tests
```

@note
All dependencies installed by xpm are located in the home folder and
can be uninstalled by simply removing the folders:
- `~/.local/xPacks` and `~/.cache/xpacks` on GNU/Linux,
- `~/Library/xPacks` and `~/Library/Caches/xPacks` on macOS,
- `%%APPDATA%\xPacks` and `%%LOCALAPPDATA%\Caches\xPacks` on Windows.

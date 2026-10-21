# Size comparison results

The sizes of the v5.0.1 test programs, built with two versions of the
library; see `SIZE-COMPARISON.md` for the method and for how to repeat
the runs. The most recent results are first.

## 2026-10-21, `dbe0c110`

- Tests: the v5.0.1 test sources (`491f7297`), patched by
  `v5.0.1-tests.patch`.
- Libraries: `v5.0.1` (`491f7297`); `dbe0c110` (#153: Restore the v5.0.1
  type_traits::has_value); and `dbe0c110` patched by
  `local-source-location.patch`.
- Platform: `qemu-cortex-m33-cmake-gcc`, `debug` (`-O0`) and `release`
  (`-Os`).
- Compiler: xPack GNU Arm Embedded GCC 15.2.1 20251203.
- QEMU: xPack QEMU emulator version 9.2.4.

The control run, with the `dbe0c110` library on both sides, showed no
difference in any size, so the differences below come only from the
libraries.

### v5.0.1 library compared with the current library (bytes)

| Build | Program | `text` v5.0.1 | `text` HEAD | Change | `data` | `bss` |
| --- | --- | ---: | ---: | ---: | --- | --- |
| debug | empty | 161104 | 163208 | +2104 (+1.3%) | 2780 → 2876 | 9328 → 9336 |
| debug | minimal | 155592 | 169724 | +14132 (+9.1%) | 2780 → 2852 | 9328 → 9344 |
| debug | sample | 222572 | 219380 | -3192 (-1.4%) | 2800 → 3768 | 9968 → 10008 |
| debug | suite | 175900 | 182656 | +6756 (+3.8%) | 2788 → 3100 | 9696 → 9736 |
| debug | unit | 747736 | 781360 | +33624 (+4.5%) | 2824 → 13840 | 10880 → 10920 |
| release | empty | 110324 | 115308 | +4984 (+4.5%) | 2772 → 2876 | 9328 → 9328 |
| release | minimal | 108964 | 115464 | +6500 (+6.0%) | 2780 → 2852 | 9328 → 9336 |
| release | sample | 125492 | 133272 | +7780 (+6.2%) | 2792 → 3744 | 9960 → 10000 |
| release | suite | 114956 | 121612 | +6656 (+5.8%) | 2788 → 3100 | 9688 → 9728 |
| release | unit | 373272 | 407220 | +33948 (+9.1%) | 2824 → 13840 | 10872 → 10912 |

### Runs under QEMU

All the programs exit with code 0, with all three libraries, and each
one reports the same totals with all of them:

| Program | Totals (all libraries, both builds) | Source location records, HEAD (debug, release) |
| --- | --- | --- |
| empty | 0 checks passed, 0 failed, in 0 test cases, 1 test suite | 6, 6 |
| minimal | 2 checks passed, 0 failed, in 1 test case, 1 test suite | 3, 3 |
| sample | 40 checks passed, 0 failed, in 18 test cases, 4 test suites | 59, 58 |
| suite | 6 checks passed, 0 failed, in 3 test cases, 2 test suites | 18, 18 |
| unit | 341 checks passed, 326 failed, in 60 test cases, 12 test suites | 687, 687 |

The failed checks of `unit` are expected; the program checks its own
counts, and exits with 0 only when they match. The v5.0.1 library, and
the current library with `local-source-location.patch`, have no source
location records.

### Where the code grows (release `minimal`, code symbols, bytes)

| Component | v5.0.1 | HEAD | Change |
| --- | ---: | ---: | ---: |
| C/C++ libraries and platform | 93840 | 95018 | +1178 |
| `test_case` | 0 | 1156 | +1156 |
| `reporter_tap` | 1936 | 2990 | +1054 |
| `runner` | 1736 | 2658 | +922 |
| other framework symbols | 88 | 756 | +668 |
| `expression_formatter` | 122 | 706 | +584 |
| `reporter` | 1672 | 2184 | +512 |
| `check_result` | 0 | 436 | +436 |
| `suite` | 182 | 448 | +266 |
| `stopwatch` | 0 | 184 | +184 |
| `utility` | 64 | 176 | +112 |
| `counters` | 0 | 42 | +42 |
| `reporter_human` | 2178 | 2166 | -12 |
| `test_node` | 58 | 0 | -58 |
| `runnable` | 132 | 16 | -116 |
| `timestamp` | 224 | 0 | -224 |
| `deferred_reporter` | 368 | 0 | -368 |
| `subtest` | 614 | 0 | -614 |
| **Framework total** | **9374** | **13918** | **+4544** |
| **All code symbols** | **103214** | **108936** | **+5722** |

The components are grouped by the class names in the symbols (the `t`,
`T`, `w`, and `W` symbols of `nm`), so the read-only data, such as the
strings, are not included; the C/C++ library part was not broken down
further.

### The `.data` growth: the source location records

The `.data` growth comes from the source location records. The current
library uses `std::source_location`, and, for each call site of a
function with a defaulted source location parameter (mostly `expect()`,
`require()`, and `test()`), GCC creates a 16-byte record (the file name,
the function name, the line, and the column). These records account for
928 bytes in `sample` (58 records) and 10 992 bytes in `unit` (687
records).

Findings:

- GCC 15.2.1 places each record in a writable section,
  `.data..Lsrc_loc<N>` with the flags `"aw"`, both with `-O0` and with
  `-Os`, and in `.data` without `-fdata-sections`; only the two strings
  it points to are in `.rodata`. The `.data` section is copied from flash
  to RAM by the startup code, so each record takes 16 bytes of flash and
  16 bytes of RAM, although it is never written.
- Clang (the native Apple clang 17, on macOS) places the same record in
  a constant data section (`__DATA,__const`).
- A web search found no GCC bug report or discussion of this placement;
  GCC's Bugzilla was not searched directly.
- The v5.0.1 library did not have these records on these targets: its
  `reflection.h` used `std::source_location` only when
  `__cpp_lib_source_location` was defined, which, depending on the
  headers included before it, was not the case, so it used its own
  class, which holds the file name and the line by value (this
  dependency was the problem fixed by the review item #1). The current
  `reflection.h` includes `<version>`, so it always uses
  `std::source_location`.
- The library uses only the `file_name()` and `line()` members of the
  source locations.

### Experiment: the current library with its own source location class

The current library patched by `local-source-location.patch`, which
makes it always use its own class, compared with the unpatched current
library (bytes):

| Build | Program | `text` HEAD | `text` patched | Change | `data` | `bss` |
| --- | --- | ---: | ---: | ---: | --- | --- |
| debug | empty | 163208 | 162552 | -656 (-0.4%) | 2876 → 2780 | 9336 → 9336 |
| debug | minimal | 169724 | 169180 | -544 (-0.3%) | 2852 → 2804 | 9344 → 9344 |
| debug | sample | 219380 | 217264 | -2116 (-1.0%) | 3768 → 2824 | 10008 → 10008 |
| debug | suite | 182656 | 181520 | -1136 (-0.6%) | 3100 → 2812 | 9736 → 9736 |
| debug | unit | 781360 | 775924 | -5436 (-0.7%) | 13840 → 2848 | 10920 → 10920 |
| release | empty | 115308 | 114756 | -552 (-0.5%) | 2876 → 2780 | 9328 → 9328 |
| release | minimal | 115464 | 115176 | -288 (-0.2%) | 2852 → 2804 | 9336 → 9336 |
| release | sample | 133272 | 131200 | -2072 (-1.6%) | 3744 → 2816 | 10000 → 10000 |
| release | suite | 121612 | 120660 | -952 (-0.8%) | 3100 → 2812 | 9728 → 9728 |
| release | unit | 407220 | 402192 | -5028 (-1.2%) | 13840 → 2848 | 10912 → 10912 |

- The `.data` returns almost to the v5.0.1 values (2848 bytes in
  `unit`, compared with 2824 in v5.0.1), and the code is also smaller,
  by 0.3 KB to 5.4 KB.
- The programs report the same totals; in an earlier run, in a
  temporary folder, the 652 file and line locations written to the TAP
  output by `unit` (release) were identical with both libraries.
- The patch only shows the effect; a fix would have to keep the type the
  same in all the translation units (the review item #1), for example by
  always using the local class, and decide about the applications that
  pass a `std::source_location` explicitly, and about the compilers
  without `__has_builtin`.

### Observations

- In `release`, the code (`text`) grows by 4.5% to 9.1%: about 4.5 KB
  of framework code, plus about 1.2 KB of C/C++ library and platform
  code, for the smallest programs.
- In `debug`, the growth varies from -1.4% (`sample`) to +9.1%
  (`minimal`); the reason was not analysed.
- The `.data` growth comes from the source location records, which use
  both flash and RAM; on targets with little RAM, this is the most
  visible change. Using the library's own source location class removes
  them (see the experiment above).
- The `bss` grows by at most 40 bytes.

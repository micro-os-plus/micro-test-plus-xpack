# Size comparison with v5.0.1

How to compare the sizes of the test programs of v5.0.1, built with two
versions of the library: by default, the v5.0.1 library and the current
one. The same script also measures the effect of an experimental change
to the library, given as a patch. The results are kept in
`SIZE-COMPARISON-RESULTS.md`, next to this file.

The files used are in `maintenance/scripts/size-comparison/`:

- `compare-sizes.py`, the script;
- `v5.0.1-tests.patch`, the patch to the v5.0.1 test sources (see below);
- `local-source-location.patch`, the experimental patch to the current
  library (see below).

## What is compared

The same test sources (by default, `tests/sources/` at the `v5.0.1`
tag: `empty`, `minimal`, `sample`, `suite`, and `unit`) are built twice,
once with the headers and sources of the baseline library (by default,
v5.0.1), and once with those of the current library (by default,
`HEAD`). Each of them may be patched first.

Everything else is the same for both builds: the compile flags, the link
commands, the linker scripts, and the platform objects (startup, vectors,
semihosting, and trace) are taken from the current build folders of the
platform, so the size differences come only from the library.

Each program is then run under QEMU, to check that both builds work and
report the same totals.

By default, the platform is `qemu-cortex-m33-cmake-gcc`, with the
`debug` (`-O0`) and `release` (`-Os`) build folders.

## The patch to the v5.0.1 tests

The v5.0.1 test sources compile with the current library, with
deprecation warnings, except for 4 errors in
`tests/sources/unit/src/timings.cpp`: a helper class derived from the
internal `detail::timestamps` writes its protected data members
(`begin_time_` and `end_time_`), which no longer exist, since the class
is now an alias of the internal stopwatch.

The patch `v5.0.1-tests.patch` disables, with `#if 0` / `#endif`:

- the `set_times()` member of the helper class;
- the last two checks of the "timestamps::has_timestamps() state" test
  case, which call it;
- the three test cases that depend on it ("timestamps::timestamp_begin()
  idempotency", "timestamps::timestamp_end() idempotency", and
  "timestamps::compute_elapsed_time()"), with the checks of their
  counts.

In total, 3 test cases and 16 checks are disabled. The test sources are
the same for both builds, so the comparison remains fair. The patch is
applied by default (`--tests-patch`).

## The experimental patch to the current library

The current library records the source locations with
`std::source_location`. For each call site of a function with a
defaulted source location parameter (mostly `expect()`, `require()`, and
`test()`), GCC creates a 16-byte record (the file name, the function
name, the line, and the column), and places it in a writable section,
`.data..Lsrc_loc<N>`, so it takes both flash and RAM; only the two
strings it points to are placed in `.rodata`. The v5.0.1 library, on the
same targets, used its own class, which holds the file name and the line
by value, and needs no records.

The patch `local-source-location.patch` makes the current library always
use its own class, by replacing the two preprocessor tests of
`__cpp_lib_source_location`, in `reflection.h` and
`inlines/reflection-inlines.h`. It is an experiment, to measure the
effect; it is not a fix ready to be committed. Since it changes two
`#if` lines by their context, it may need to be regenerated if these
files change.

To check the placement of the records with another compiler version,
compile a call to `std::source_location::current()` with `-S`, and look
at the section of the `.Lsrc_loc0` label:

```sh
printf '%s\n' '#include <source_location>' \
  'const char* f (const std::source_location& sl = std::source_location::current ());' \
  'const char* g (void) { return f (); }' > a.cpp
arm-none-eabi-g++ -std=c++20 -Os -mcpu=cortex-m33 -mthumb -fdata-sections -S a.cpp
grep -B6 '^\.Lsrc_loc0:' a.s | grep section
```

## How to run it

Requirements: Python 3, `git`, `patch`, and `tar`, and the `tests`
project installed (`xpm install -C tests`).

1. Build the two build folders of the platform with the current
   revision, so that their compile commands and platform objects exist:

   ```sh
   xpm run build --config qemu-cortex-m33-cmake-gcc-debug -C tests
   xpm run build --config qemu-cortex-m33-cmake-gcc-release -C tests
   ```

2. Run the script, from the repository root. The comparison of the
   v5.0.1 library with the current one:

   ```sh
   python3 -I maintenance/scripts/size-comparison/compare-sizes.py
   ```

   The effect of the experimental patch, as the current library compared
   with itself, patched:

   ```sh
   python3 -I maintenance/scripts/size-comparison/compare-sizes.py \
       --baseline HEAD --current HEAD \
       --current-patch local-source-location.patch
   ```

   A control run, as the current library compared with itself, must
   show no differences at all; if it does, the method is wrong:

   ```sh
   python3 -I maintenance/scripts/size-comparison/compare-sizes.py \
       --baseline HEAD --current HEAD
   ```

   Each run exports the test sources and the two libraries with
   `git archive`, applies the patches, builds the programs, runs them
   under QEMU, and prints the results as Markdown tables. The working
   files are written to `tests/build/size-comparison/`, which is ignored
   by git, and replaced by each run; the repository is not changed. Each
   run takes a few minutes.

3. Copy the tables into `SIZE-COMPARISON-RESULTS.md`, as a new dated
   section, with the commit, the compiler, and the QEMU versions.

The options:

| Option | Default | Meaning |
| --- | --- | --- |
| `--tests` | `v5.0.1` | the revision of the test programs |
| `--tests-patch` | `v5.0.1-tests.patch` | the patch to the test sources (`""` for none) |
| `--baseline` | `v5.0.1` | the revision of the baseline library |
| `--baseline-patch` | none | a patch to the baseline library |
| `--current` | `HEAD` | the revision of the current library |
| `--current-patch` | none | a patch to the current library |
| `--platform` | `qemu-cortex-m33-cmake-gcc` | the prefix of the build folders |
| `--work` | `tests/build/size-comparison` | the working folder |

A patch given without a folder is taken from the script folder. The
revisions may be any git revision (a tag, a branch, or a commit), and are
used without being checked out; they only provide the sources, while the
build folders always come from the working tree.

## Notes on the method

- The `-Werror` option is removed from the commands of both builds,
  since the v5.0.1 sources use deprecated names; it does not change the
  generated code.
- The source file names are compiled into the programs (for example in
  the source locations), so the absolute sizes depend on the length of
  the path of the working folder. The two libraries are exported to
  folders with names of the same length (`library-1` and `library-2`),
  so the differences between the two builds are not affected; compare
  absolute sizes only between runs with the same working folder.
- The script counts the source location records (the
  `.data..Lsrc_loc*` input sections in the linker map) of each program.
- The script needs the build folders to be generated by CMake
  (`compile_commands.json`, `CTestTestfile.cmake`, and `ninja`); the
  meson build folders are not supported.

# C++ API review

Date: 2026-10-30, on branch `xpack-development`, commit `e9e79e78`
(no changes outside `website/`).

Scope: the umbrella header `include/micro-os-plus/micro-test-plus.h`,
the 19 public headers in `include/micro-os-plus/micro-test-plus/`, the
inline headers in `include/micro-os-plus/micro-test-plus/inlines/`, and
the 12 source files in `src/`. The Doxygen comments were ignored. The
deprecated definitions were not reviewed, except where non-deprecated
code exists only to serve them (see the last section).

Method: the comments were stripped with
`.github/skills/api-review/scripts/strip-comments.mjs` (48 files, 8942
lines of code, original line numbers kept) and the stripped files were
read, except `math.h`, `math-inlines.h`, `deprecated.h`,
`deprecated-inlines.h`, and `src/deprecated.cpp`. The headers were
checked for self-containment (`check-headers.mjs`, Apple Clang 17.0.0,
19 headers, none failed) and the formatting with
`clang-format --dry-run --Werror` (no differences). Eleven probe
programs were built against the library sources with Apple Clang
17.0.0 (`-std=c++20 -Wall -Wextra -Wpedantic`, also `-Weverything`,
`-fno-exceptions -fno-rtti`, and `-fsanitize=address,undefined`); the
TAP outputs were validated with `tests/scripts/validate-tap.mjs`. The
library sources were also compiled with the cross compiler
`arm-none-eabi-g++` (Cortex-M4, `-Os -fno-exceptions -fno-rtti -Wall
-Wextra -Wpedantic -Wconversion -Wdouble-promotion
-Wframe-larger-than=512 -fstack-usage`). No native GCC is installed on
the review machine, so GCC was used only through the cross compiler.
The test suites in `tests/` were not run, no program size was
measured, and no claim about size is made.

Independence: the `api-review` skill requires each review to be made
without reading the earlier reports. That rule was broken: before the
skill was loaded, `API-REVIEW-3.md` was read in full. No other earlier
report, commit message, or issue text was consulted. The findings
below come from reading the code and from probes; every item marked
**[confirmed]** was reproduced in this review, and nothing was copied
from the earlier report. Because of the breach, the list of problems
that this review did *not* find should be trusted somewhat less than
it would be after a blind review.

Summary: 20 problems (20 open, 0 fixed, 0 withdrawn).

The most serious are the defects that make a check give the wrong
answer, or make the output wrong for the tools that read it:

- the comparators give the wrong answer for mixed signed and unsigned
  operands, and the compiler warning that would have shown it is
  silenced (#1);
- `approx()` treats a distance equal to the tolerance as a failure, so
  a tolerance of zero can never pass (#2);
- command-line errors never reach the console output or the output file
  (#3), and the TAP console is not valid TAP when an output file is used
  (#4).

Suggested order of work:

1. The defects, which are all local fixes and do not change the API:
   #1 to #7.
2. The additive changes to the command line and the names: #8 and #10.
3. The breaking change, for one major release: #9.
4. The clean-ups: #11 to #19.
5. The deprecated group, together with the removal of the deprecated
   definitions: #20.

Tags:

- **[breaking]**: the suggested change alters the public API or the
  observable behaviour of correct user code;
- **[internal]**: the suggested change does not alter the public API;
- **[confirmed]**: a probe program reproduced the problem; items
  without this tag are derived from reading the code;
- **[deprecated]**: the problem concerns deprecated functionality.

## 1. Defects

- **#1 — Mixed signed and unsigned operands compare wrongly, and the
  warning is silenced.** [internal] **[confirmed]**
  `inlines/detail-inlines.h` lines 216, 253, and 266 to 344: the six
  `apply()` functions compare the operands with the built-in operators
  under `#pragma GCC diagnostic ignored "-Wsign-compare"`, so the usual
  arithmetic conversions turn a negative signed operand into a large
  unsigned one, silently. The probe, with `int neg = -1; unsigned one
  = 1u;`, built with `-Wall -Wextra -Wpedantic` and no warning:
  - `lt (neg, one)` fails (`-1 < 1u`);
  - `gt (one, neg)` fails (`1u > -1`);
  - `ne (neg, std::numeric_limits<unsigned>::max ())` fails, that is,
    `eq (-1, UINT_MAX)` passes;
  - `eq (std::vector<int>{}.size (), -1)` passes.

  The case is realistic: `eq (v.size (), -1)` and `gt (count, -1)` are
  natural checks, and the framework itself does the comparison correctly
  where it matters (`differ_by_less_than()`, lines 426 to 469, uses
  `std::cmp_less()` and `std::cmp_greater_equal()`). Suggested change:
  in the six `apply()` functions, when both operands are integers (not
  `bool`, not character types) and their signedness differs, use
  `std::cmp_equal()`, `std::cmp_less()`, and the other functions of
  `<utility>`; keep the built-in operators for every other pair, and
  drop the pragma. The release notes should say that the results of the
  comparisons of mixed-sign integers have changed, since they are now
  correct.

- **#2 — `approx()` excludes the tolerance itself, so a tolerance of
  zero never passes.** [internal] **[confirmed]**
  `inlines/detail-inlines.h` lines 426 to 469: `differ_by_less_than()`
  returns `distance < epsilon` for integers and `abs (lhs - rhs) <
  epsilon` for floating-point values. The probes, all failing:
  `approx (10, 12, 2)` (reported as `10 ~ (12 +/- 2)`),
  `approx (5, 5, 0)`, and `approx (1.0, 1.0, 0.0)`. The report reads
  "within plus or minus 2", but the check says otherwise, and identical
  values fail when the tolerance is zero, which is the natural way to
  ask for an exact comparison of a value that is usually exact.
  Suggested change: use `<=`. Alternatively, keep the strict
  comparison and print the relation (`10 ~ (12 +/- 2)` becomes
  `|10 - 12| < 2`), but then a tolerance of zero must be documented as
  meaningless. The first option is the one most users expect (it is the
  one of `std::abs (a - b) <= eps` and of the other frameworks).

- **#3 — Command-line errors reach only `stderr` and the exit code.**
  [internal] **[confirmed]**
  `src/runner-options.cpp` lines 284 to 293, `inlines/runner-inlines.h`
  lines 97 to 101, `src/runner.cpp` lines 680 and 719: `add_error()`
  prints the message on `stderr` and sets a flag; the message is not
  kept, so the reporters cannot write it. The probe: `p4 --bogus
  --output-file=b.tap` prints `error: unknown option '--bogus'` on
  `stderr`, exits with 2, and writes a complete TAP console and file,
  neither of which contains the word `error`; the same happens for
  `--filter` without a value. A tool that reads the TAP stream or the
  file sees a document whose only trace of the problem is the line
  `# Running: p4 --bogus ...`. The `api-review` checks require that
  configuration and command-line errors reach the output file. Suggested
  change: keep the messages in `runner_options` (a `std::vector<
  std::string>`), and let `begin_session()` write them as comment lines
  (`# error: ...` in TAP) to the console and to the file, in addition to
  `stderr`.

- **#4 — The TAP console is not valid TAP when an output file is used,
  and the note is printed from a destructor.** [internal] **[confirmed]**
  `src/reporter.cpp` lines 194 to 214: `~reporter()` writes `Test output
  written to 'p4.tap'.` with `write_console()`, without the comment
  prefix. The probe: `p4 --output-file=p4.tap > console`; the validator
  reports `non-TAP line: "Test output written to 'p4.tap'.\n"`, after
  the plan and the totals (the file itself is valid). Two defects in one
  line: the text is not a comment, and it is written when the reporter is
  destroyed, that is, when the runner goes out of scope, which is after
  anything the application prints after `run_suites()` and, for a
  `static` runner, after `main()` returns. Suggested change: write the
  note from `end_session()`, with `comment_prefix()`, after the totals.

- **#5 — `printable` is true for containers of types that cannot be
  printed, so the error is a hard error and `test_each()` cannot fall
  back.** [internal] **[confirmed]**
  `expression-formatter.h` lines 691 to 741, `extension.h` lines 304 to
  306 and 457 to 462, `inlines/test-inlines.h` lines 758 to 767: the
  `operator<<` templates for `std::pair`, `std::tuple`, `std::optional`,
  and `std::chrono::duration` have no constraint on their elements, so
  `extension::printable<T>` is true as soon as the template is declared.
  The probes, with `struct opaque { int x; }` (no `operator<<`):
  `printable<std::pair<int, opaque>>`, `printable<std::optional<opaque>>`,
  `printable<std::tuple<int, opaque>>`, and
  `printable<std::vector<std::pair<int, opaque>>>` are all true (each
  `static_assert (!printable<...>)` fails). The consequences:
  - `eq (std::optional<opaque>{}, ...)` is accepted by the constraint on
    `eq()` and then fails inside the formatter, with an error that starts
    at `expression-formatter-inlines.h:321`; the constraint that was
    meant to reject unprintable operands at the call does not do so;
  - `test_each ("v", std::vector<std::pair<int, opaque>>{...}, f)` does
    not compile, although `test_each_value()` was written to use `#N` in
    the name when the value is not printable (line 758);
  - `duration<my_rep>` would fail inside `append_number()` for a `Rep`
    that is not arithmetic (derived from reading; not probed).

  Suggested change: constrain the four templates on the printability of
  their elements (for `duration`, `std::is_arithmetic_v<Rep>`), as
  `formattable_range` already does for ranges.

- **#6 — Errors in the call order change neither the exit code nor the
  reports.** [internal] **[confirmed]** for `initialise()`, derived from
  reading for `add_top_suite()`
  `src/runner.cpp` lines 241 to 245 and 340 to 344: a second call of
  `initialise()` prints `error: test runner already initialised` on
  `stderr` and returns; a second call of `add_top_suite()` prints
  `error: top suite already added` and returns the existing top suite.
  The probe with two `initialise (argc, argv)` calls and one passing
  check exits with 0 and prints nothing else. Neither error is
  recorded, so a test program with a wiring mistake (two initialisations
  in different layers is a plausible one) reports success. The late
  `add_suite()` is handled correctly (`reject_suite()` sets
  `has_rejected_suites_`, which makes the exit code 1). Suggested change:
  treat both as rejected calls in the same way, with a flag that makes
  the exit code non-zero, and report them with the command-line errors
  of #3.

- **#7 — `--list-tests` prints text that is not TAP on the TAP
  reporter.** [internal] **[confirmed]**
  `src/runner.cpp` lines 282 to 290, 449 to 455, and 672 to 678: the
  listing writes `All available test cases:`, indented suite and test
  case names, and `2 test cases in 1 test suite` as plain lines, whatever
  the reporter. The validator rejects the output (`Non-TAP data
  encountered in strict mode`). TAP is the default reporter, so the
  default listing is not a TAP document. Suggested change: write the
  listing as comment lines (`comment_prefix()`), which keeps it readable
  and makes it valid TAP.

## 2. Structure and layering

- **#8 — The framework owns the whole `--` namespace of the command line,
  and offers no way to pass options to the application.** [internal]
  **[confirmed]**
  `src/runner-options.cpp` lines 204 to 271: every argument that starts
  with `--` and is not one of the library's own is an error that makes
  the exit code 2. The probes: `p4 -- --app-opt` reports
  `unknown option '--'` and `unknown option '--app-opt'`; `p4 --help`
  reports `unknown option '--help'`. So an application cannot have an
  option of its own (a board name, a seed, a data folder) without the
  tests refusing to run, the conventional `--` terminator is rejected,
  and there is no `--help` listing the options that exist. The
  `runner_options` constructor exposes `arguments` to the application,
  but the application is not allowed to use them. Suggested change:
  (a) stop parsing at `--`, and leave the rest to the application;
  (b) add `--help` (and possibly `--version`) as options that print the
  list and make `run_suites()` return 0; (c) optionally, provide a way
  for the application to declare its own options before `initialise()`.
  Not breaking.

- **#9 — `suite` can be derived from by user code, which then reaches
  the protected state of the test tree.** [breaking] **[confirmed]**
  `test.h` lines 647 to 716 (`runnable_base::name_`, `totals_`,
  `runner_`, `own_index_`, `test_point_number_`,
  `child_test_cases_count_`), 1498 to 1869 (`suite`, the protected
  constructor and the protected `link()`, `unlink()`, `callable_`,
  `stopwatch_`, `owned_name_`, `next_`, and `first_`): `test_case`,
  `top_suite`, `static_suite`, and `stopwatch` are `final`, but `suite`
  is not, and its constructor is protected and a template, so any user
  class can derive from it. The probe: `struct my_suite : mt::suite`
  with a member that does `totals_ = mt::counters{}; name_ = "renamed";
  link ();` compiles without warning, and the run reports the renamed
  suite as passed with no checks. That is the access to the counters
  that the read-only `totals()` was meant to remove, available through
  inheritance. Only `top_suite` and `static_suite` are meant to derive
  from `suite`. Suggested change: make the constructor of `suite`
  private, with `runner`, `top_suite`, and `static_suite` as friends (or
  make the three classes share a private implementation base), and make
  the protected members private or accessible only to those friends.
  Migration: none is possible for code that derived from `suite`; the
  release notes and the compatibility notices should say so.

## 3. Naming and consistency

- **#10 — Names are passed as three different types, and a
  `std::string_view` is not accepted for a test case.** [internal]
  **[confirmed]**
  `inlines/test-inlines.h` lines 101 to 118, `runner.h` lines 447 and
  548 to 551, `test.h` lines 2064 to 2067: `test_case_name` accepts
  `const char*` and `const std::string&`; `runner::add_suite()` and
  `runner::add_top_suite()` take `std::string_view`; `static_suite`
  takes `const char*`. The probe: `t.test (std::string_view{"x"}, ...)`
  does not compile (`no matching member function for call to 'test'`),
  although the same view is accepted by `add_suite()`. The suites and the
  test cases are named in the same way in the reports, so the
  difference is accidental. Suggested change: give `test_case_name` a
  `std::string_view` constructor (the name must stay valid for the
  duration of the call, which is the case for the synchronous
  `test()`), and let `static_suite` also take a `std::string_view`;
  keep the `const char*` constructors for the null-pointer handling.

- **#11 — The colour option has two prefixes, no British spelling, and
  three synonyms for each value.** [internal] **[confirmed]**
  `src/runner-options.cpp` lines 129 to 133, 184 to 196, and 246 to 260:
  `--color` and `--use-colour` are accepted, `--colour` is not (the
  probe reports `unknown option '--colour=never'`), although the member
  of `runner_options` is `colour`, the enumeration is `colour_mode`, and
  the project is written in British English. The values have synonyms
  (`always`, `yes`, `force`; `never`, `no`, `none`; `auto`, `tty`,
  `if-tty`), and the listing has two (`--list`, `--list-tests`). Each
  synonym is a name that must be documented, kept, and tested.
  Suggested change: choose one spelling per option (`--colour`, with
  `--color` and `--use-colour` accepted as aliases if the compatibility
  with other frameworks matters), and reduce the synonyms of the values
  to one or two.

- **#12 — `utility::extract_file_name()` is a public helper of the
  framework, and has undefined behaviour for a null pointer.**
  [internal]
  `utility.h` lines 94 to 95, `src/utility.cpp` lines 88 to 98: the
  function is used only by the runner and the reporters, but it sits in
  the public `utility` namespace, next to `is_match()` and `split()`
  that are meant for applications. It is declared `noexcept` and
  constructs a `std::string_view` from its argument, which is undefined
  for `nullptr`. Suggested change: move it to `detail` (or give it a
  null check), so that the public `utility` namespace contains only what
  applications use.

## 4. Simplicity and duplication

- **#13 — The list of open test cases is displayed by two copies of the
  same function.** [internal]
  `src/reporter-human.cpp` lines 864 to 902 (`display_open_names()`) and
  `src/reporter-tap.cpp` lines 1050 to 1075 (`display_open_headers()`):
  both walk `open_test_cases_`, skip the entries already displayed,
  write a heading, and mark the entry; they differ only in the format of
  the heading and in the handling of `add_empty_line_`. The state they
  work on (`open_test_cases_`, `add_empty_line_`, `current_suite_`) is in
  the base class. Suggested change: move the loop to `reporter`, and let
  the derived classes provide only the formatting of one heading.

- **#14 — `runner_options::operator=` repeats what `= default` does.**
  [internal]
  `runner-options.h` lines 299 to 300, `inlines/runner-options-inlines.h`
  lines 58 to 64: the copy assignment is written as copy-and-move, while
  the class has a defaulted copy constructor and a defaulted move
  assignment, and all its members are copyable. The hand-written version
  adds an extra move and is one more function to keep. Suggested change:
  `= default`.

## 5. Modern C++

- **#15 — `runner::run_suites()` is not `[[nodiscard]]`.** [internal]
  **[confirmed]**
  `runner.h` lines 488 to 489: the return value is the exit code of the
  program. The probe: `r.run_suites (); return 0;` builds with no
  warning at `-Wall -Wextra` and exits with 0 even when checks fail. The
  two accessors next to it (`total_suites_count()`, `is_listing()`) are
  already `[[nodiscard]]`. Suggested change: add `[[nodiscard]]`.

## 6. Suitability for embedded targets

- **#16 — Containers are printed in full, and byte values carry a type
  suffix.** [internal] **[confirmed]**
  `inlines/expression-formatter-inlines.h` lines 189 to 203,
  `src/expression-formatter.cpp` lines 395 to 401: `operator<<` for a
  range appends every element, with no limit, and `unsigned char` values
  are written with the suffix `uc`. The probes: a failed `eq` of two
  `std::array<std::uint8_t, 4>` prints `{1uc, 2uc, 3uc, 4uc} == {1uc,
  2uc, 3uc, 5uc}`; a failed `eq` of two `std::vector<int>` of 2000
  elements prints a report of about 12 kilobytes
  in total, held in a `std::string` and, in TAP, copied once more for
  the YAML block. On a target with a few kilobytes of heap, a check on a
  buffer can by itself exhaust the memory, and the one difference is
  lost in the output. Suggested change: limit the number of elements printed
  (for example the first 16, then `...`, with the total count), print
  the index of the first difference when two ranges are compared, and
  omit the type suffix for `unsigned char` and `signed char` elements of
  a range (they are bytes, not numbers with a type).

## 7. Incidental observations

- **#17 — One line exceeds 80 characters.** [internal]
  `src/runner.cpp` line 254 has 81 characters (a comment). All the other
  lines of `include/` and `src/` fit.

- **#18 — Two comments produce `-Wdocumentation` warnings.** [internal]
  **[confirmed]**
  `src/utility.cpp` lines 125 and 191: `@par Examples` and `@par Example`
  are followed by an empty line, which Clang with `-Weverything`
  reports as `empty paragraph passed to '@par' command`. No other
  warning is reported for the library at `-Weverything`.

- **#19 — The metadata of the release is not updated.** [internal]
  `package.json` has the version `6.0.0-pre` at the commit titled
  `6.0.0` (`e9e79e78`); `CHANGELOG.md` ends its list at `v5.0.1`. The
  release contains breaking changes (the removal of mutable
  `totals()`, the `final` classes, the new `checkable` constraint, the
  rename of `run()`), which the log is meant to announce.

## 8. Deprecated functionality

- **#20 — Non-deprecated definitions exist only for the deprecated
  tolerance wrappers.** [deprecated] [internal]
  `extension.h` lines 176 to 177 (`extension::has_epsilon`),
  `detail.h` lines 187 to 190 and `inlines/detail-inlines.h` lines 206
  to 241 (`within_tolerance()`), `inlines/detail-inlines.h` lines 388 to
  398 (the tolerance branch of `compare_op`), and the
  `within_tolerance_result` member of each of the six comparison tags
  (`detail.h` lines 441 to 686): the only types that carry an `epsilon`
  member are the floating-point `detail::value<T>` wrappers of
  `values.h`, which exist for the deprecated `to_f`, `to_d`, and `to_ld`
  and for the deprecated literals. `approx_op` stores its tolerance
  behind a function, so it does not satisfy `has_epsilon`. The concept
  is in the `extension` namespace, which the documentation presents as
  the interface for application code, so applications are invited to
  rely on it. Suggested change: when the deprecated definitions are
  removed, remove with them these definitions and the branch of
  `compare_op`; until then, say in the documentation of `has_epsilon`
  that it is deprecated with the wrappers.

## 9. Reviewed and found sound

- All 19 public headers compile on their own; the formatting of all
  headers and sources matches `maintenance/config/.clang-format`; the
  header guards follow the rule and are unique; there is no `#ifdef` or
  `#ifndef` except for the guards, and every `#endif` is followed by a
  comment; the 12 source files are registered in `CMakeLists.txt`,
  `meson.build`, and `xcdl-package.jsonc`.
- The library builds with `-Wall -Wextra -Wpedantic`, with
  `-fno-exceptions -fno-rtti`, and with the Cortex-M4 cross compiler
  (`-Wconversion -Wdouble-promotion`) without any warning; the largest
  stack frame is 328 bytes (`reporter_tap::end_suite()`), under the
  limit of 512.
- Probes of nested test cases (a failure in an inner test case reaches
  the outer one and the totals), of comparisons of durations, strings
  with embedded quotes and newlines, optionals, maps, enumerations, null
  `const char*` operands, `throws()`, and `any_of()` ran clean under
  AddressSanitizer and UndefinedBehaviorSanitizer.
- Without exceptions, a failed `require()` ends the run with a visible
  "test execution aborted" message (`-fno-exceptions` probe).
- Reading the expression templates, the operands are taken correctly: the
  constructors of `and_op`, `or_op`, `not_op`, `predicate_op`, and
  `approx_op` evaluate the result from the arguments before the operands
  are moved into the members, and `stored_operand_t` keeps temporaries
  by value and lvalues by reference, so a result that outlives the
  expression holds no dangling reference to a temporary.
- The filters (`--filter` per level, with alternatives separated by
  `|`) select suites and test cases as documented; a run in which they
  select nothing exits with 2; `suite::test()` called from a running
  test case nests the new test case under it.
- The TAP output files of the probes at the default verbosity are valid.

## 10. Not examined, or not certain

- `math.h`, `math-inlines.h`, and the deprecated definitions were not
  read.
- MSVC and Windows: the clock (`timespec_get (&ts, TIME_UTC)` is not
  monotonic), the attributes (`[[gnu::always_inline]]`), and the
  `__PRETTY_FUNCTION__` fallback were read but not built.
- The effect of different values of the configuration macros in two
  translation units of one program (the one-definition rule) was not
  probed; only member functions depend on `__cpp_exceptions` and
  `MICRO_OS_PLUS_MICRO_TEST_PLUS_DEPRECATED_ENABLED`, so the layout of
  the classes appears unchanged.
- The program size and the number of allocations were not measured.
- The test programs in `tests/sources/` were not run; the website and
  the Doxygen comments were not reviewed.

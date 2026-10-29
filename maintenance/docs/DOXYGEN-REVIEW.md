# Doxygen Review

Note: the private function `runner::run_suites()` (earlier `run_suites_()`)
was renamed `run_child_suites()`, to free the name for a public function;
this document uses the new name throughout.

Note: the public function `runner::run()` was renamed `run_suites()` (#193).
Where this document mentions `run()` of the runner, the new name is used,
except in the passages that describe the history of the name; `run()` of
the suites and of the test cases is unchanged.

Review of the Doxygen comments in `include/`, `src/`, and
`website/doxygen`, following `.github/skills/doxygen-review/SKILL.md`.
Every actionable item has a permanent number.

## Automatic checks

| Check | Before | After |
| --- | --- | --- |
| Doxygen warnings (strict settings) | 0 | 0 |
| Merged completeness (`check-doxygen-merged.mjs`) | 34 | 0 |
| Style (`check-doxygen-style.mjs`) | 21 | 3 |

The 3 remaining style problems are long `#endif` comments that repeat
long conditions (`micro-test-plus.h:61`, `detail-inlines.h:790`,
`reporter.cpp:448`).

All edited sources are unchanged by `clang-format`.

The tests pass, with no compiler warnings: `xpm run test` (102 of
102), `test-synthetic-posix-cmake-clang` (102 of 102, with
`-Wdocumentation`), and `test-qemu-cortex-m33-cmake-gcc` (12 of 12).

## Inaccurate descriptions corrected

### Stale design descriptions

- #1 Fixed: `test.h`, `runnable_base`: listed "an owning vector of child
  `test_case` instances"; the children are not kept, only
  `child_test_cases_count_`.
- #2 Fixed: `test.h`, `runnable_base::totals_`: "updated by the deferred
  reporter, which is a friend"; the deferred reporter no longer exists.
  Now it names the check result and `after_test_case_create()`.
- #3 Fixed: `test.h`, the destructors of `suite`, `top_suite`, and
  `static_suite`: "destroys the owned test cases"; the suites own no
  test cases.
- #4 Fixed: `test-inlines.h`, file details: "a lambda captures copies" of the
  arguments; it is now `detail::bound_callable`, referred to by
  `detail::callable_ref`.
- #5 Fixed: `detail.h`, file and `detail` namespace: "deferred reporting" and
  "base classes for deferred reporting"; removed.
- #6 Fixed: `reporter.h`, file details: claimed to define the `verbosity`
  levels, which are in `runner-options.h`.
- #7 Fixed: `reporter.cpp`, file details: listed "command-line option parsing",
  which the runner does.
- #8 Fixed: `expression-formatter-inlines.h`, file details: listed the buffer
  accessors `c_str()`, `clear()`, `empty()`, `append()`, and
  `reserve()`, which do not exist; only `str()` does.
- #9 Fixed: `operators.h`, `operators-inlines.h`, and `operators.dox`:
  "operands derived from the local `op` base"; the constraint is the
  `op_type` marker (`extension::is_op`), and the `to_*` wrappers do not
  derive from `op`.
- #10 Fixed: `math.h`, `num()`: referred to `integer()`, now
  `integer_magnitude()`.
- #11 Fixed: `test.cpp`, `runnable_base::test_reporter()`: "delegates to
  `runner_.reporter()`" (the deprecated accessor); it reads
  `runner_.reporter_`.
- #12 Fixed: `test-suites.dox`: the example used the deprecated
  `static_runner` with a name, declared it `static` and used it from
  another source file (which cannot link), and used the deprecated
  `static_suite&` body signature. The text said that the suites run "in
  any order" (they now run sorted by name), and that the top suite is
  created by `initialise()`. The page was rewritten. It now mentions
  `add_suite()` and the `extern` declaration of the runner.
- #13 Fixed: `folders/src.dox`: "`static_runner` constructors"; `static_runner`
  is now an alias.
- #14 Fixed: `test.h`, `assume()`: the brief was the same as the one of
  `require()`; it is now "Deprecated name of `require()`".

### Behaviour claims

- #15 Fixed: `runner-options.h`, `output_file_path`: "if the file cannot be
  opened, the program exits with an error message". In fact the error is
  reported on `stderr`, the report goes only to the console, and `run_suites()`
  returns 2.
- #16 Fixed: `runner.h`, `run_child_suites()`: "for equal names, the registered
  suites run first". Suites with equal names run in insertion order, so
  the static suites constructed before `main()` run first. The old text
  also contradicted the class documentation.
- #17 Fixed: `test.cpp`, `top_suite` constructor: "reserving index 0 for the
  runner". In fact the top suite is suite 1, and the runner numbers the
  others from 2.
- #18 Fixed: `test.cpp`, `runnable_base::abort()`: "before the process is
  terminated via `::abort()`". The abort handler is called first, and it
  may throw.
- #19 Fixed: `reporter.h`, `begin_test_case()`: "the output buffer is expected
  to be empty". The results of an outer test case are first committed by
  `commit_outer_results()`.
- #20 Fixed: `reporter.h`, `output_file_`: "regardless of the verbosity"; true
  only for the TAP reporter.
- #21 Fixed: `reporter.h`, `add_empty_line_`: "between successful test cases".
  It separates groups of console lines in general.
- #22 Fixed: `values.h`, `value_base::value_`: "value-initialised by default";
  it is always set by the constructor.
- #23 Fixed: `detail.h`, `append_number()`: the brief claimed locale-independent
  formatting. The `long double` path on some platforms uses `snprintf()`,
  which uses the C locale's decimal point; this is now documented.
- #24 Fixed: `literals.dox`: "up to … 18 [digits] after [the decimal point]";
  the check allows 19 (`digits10` of `unsigned long long`).
- #25 Fixed: `cli.dox`: `--silent` "suppress all output"; the output file is
  still written.
- #26 Fixed: `test.h`, `expect()`, `require()`, `assume()`: "@return An output
  stream"; they return the check result.
- #27 Fixed: `test-inlines.h`, `assume()`: "the returned reporter"; it is a
  check result.
- #28 Fixed: `reporter-tap.cpp`, `output_pass_prefix()`: "the index of the
  check"; it is the test point number, which also counts the nested test
  cases.
- #29 Fixed: `utility.cpp`, `is_match()`: "used … to select the suites"; it
  also selects the test cases, per alternative.
- #30 Fixed: `extension.h`, `container_like` and `has_npos`: "for specialised
  comparison"; they are used by the formatter and by `test_each()`.
- #31 Fixed: `stopwatch.cpp`: "the monotonic clock"; Windows uses `TIME_UTC`.
- #32 Fixed: `stopwatch.h`, `stopwatch-inlines.h`, `stopwatch.cpp`,
  `expression-formatter.cpp`, `expression-formatter-inlines.h`: the
  definitions are in `detail`, not in the top namespace.
- #33 Fixed: `function-comparators.dox`: the example output showed
  `42.000000`; doubles are now written as `42.0`.
- #34 Fixed: `cli.dox`: the example path `tests/sources/minimal-test/...` is
  `tests/sources/minimal/...`.
- #35 Fixed: `files/topics-h.dox`: "assumptions" is now "requirements".
- #36 Fixed: `folders/include-micro-os-plus-micro-test-plus.dox`: "this folder
  provides the primary public header", which is one level up; "type
  traits" is now "extension concepts".
- #37 Fixed: `macros/*.dox`: the `MICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED`
  details were a `...` placeholder. The two trace macro pages are now
  accurate (the messages also need `MICRO_OS_PLUS_DIAG_TRACE_ENABLED`).
- #38 Fixed: `operators.dox`, `literals.dox`: the examples used
  `micro_test_plus::operators`, which does not compile with only the
  `mt` alias; they now use `mt::operators` and `mt::literals`.

### Missing information

- #39 Fixed: `runner.h`, `run_suites()`: the listing mode was not described, and the
  return value omitted the "already running" case.
- #40 Fixed: `runner.cpp`, `initialise()`, `run_child_suites()`, `run_suites()`: the
  listing mode was not described.
- #41 Fixed: `test.cpp`, `after_test_case_create()`: the listing mode was not
  described.
- #42 Fixed: `reporter.h`, `reporter-human.h`, `reporter-tap.h`: the reporter
  can also be selected with `runner_options::selected_reporter`.
- #43 Fixed: `runner-options.h`, file details: omitted the listing option; "the
  suite filter" also selects the test cases.
- #44 Fixed: `cli.dox`: added the Output File and Listing sections; the brief
  covered only the verbosity.
- #45 Fixed: `test-case.dox`: added `test_case::test()` and `test_each()`, and
  the fact that test cases run immediately.
- #46 Fixed: `function-comparators.h` and its inlines: added `approx()`; "their
  respective logical variants" was meaningless; `ne()` … `le()` now
  mention `as_operand()`.
- #47 Fixed: `detail-inlines.h`, file details: the list of definitions was
  incomplete.

### Padding removed

- #48 Fixed: Filler sentences ("particularly useful …", "integrates seamlessly
  …", "designed to be lightweight …", "facilitates efficient debugging
  …", "across all files and folders") were removed or replaced with
  facts. This covers the 22 literal operators in `literals-inlines.h`,
  `math.h`, `math-inlines.h`, `expression-formatter-inlines.h`,
  `function-comparators-inlines.h`, `values.h`, `literals.h` (`to_t`),
  `reporter.h`, and `cli.dox`.

### Completeness and style

- #49 Fixed: Documented the 17 friend declarations (`runner.h`, `test.h`,
  `reporter.h`, `expression-formatter.h`), previously plain `//`
  comments.
- #50 Fixed: Added missing `@details`: `unwrapped_t`, `approx_op::epsilon_`,
  `range_element` and its `type` members, `identity::type`, the 8
  `function_traits` type aliases, the two `listed_*_count_` members,
  and `test_case_name::location_`.
- #51 Fixed: Reflowed 18 comment lines over 80 characters. The human
  reporter's code comments said "TAP output"; they now say "output".
- #52 Fixed: `inits.dox` had no final newline.

## Code defects noticed, not fixed

- #53 `test.h`: `detail::reporter_human` is a friend of
  `runnable_base`, but uses only public members. The friend
  documentation now says so.
- #54 `test.h` forward-declares `class counters;` after including
  `counters.h`; `reporter.h` forward-declares `check_result` after
  including `check-result.h`. Both are redundant.
- #55 `test.h`, `test_case`: two consecutive `protected:` labels.
- #56 `reporter.cpp`: the message `error: Failed to open output file`
  is capitalised, unlike the other `error:` messages.
- #57 `detail-inlines.h`, `append_number()`: on x86-64 and AArch64
  hosts, `long double` is written with `snprintf ("%.*Lg")`. An
  application that calls `setlocale()` gets a locale-specific decimal
  point (`1,5`) for `long double` only.
- #58 `counters.cpp`: the trace message of `operator+=` omits the
  skipped test cases count.

## Questions (claims that could not be verified)

- #59 Fixed: `values.h`, `floating_point_constant`: the stated reason for
  deriving from `op` rather than `value_base` (a GCC Arm PSABI note "for
  non-trivially-constructible types under C++17") does not match the
  reason given for `value_base` (an empty base in a homogeneous
  floating-point aggregate on AArch64). Which one is correct?
  Answer, from compiling test types with GCC 11.3 and 14.2 for AArch64,
  and GCC 11.3, 13.3, and 14.2 for 32-bit Arm (Cortex-M7, hard-float
  and soft-float), with C++20, C++17, and C++14:
  - the GCC 10.1 note ("parameter passing … when C++17 is enabled
    changed to match C++14 in GCC 10.1") is emitted only for a type
    with an empty base and only floating point members, with C++17 and
    later, on AArch64 and on 32-bit Arm with the hard-float ABI; the
    `value_base` rationale is correct, and now also names 32-bit Arm;
  - the `floating_point_constant` rationale was wrong: a user-provided
    constructor does not cause the note, and the struct, which has no
    non-static members, gets no GCC 10.1 note. The comment now gives
    the real reason for not deriving from `value_base` (the value is a
    compile-time constant, and no run-time storage is needed);
  - on 32-bit Arm, a different note ("changed in GCC 7.1") is emitted
    for the functions that pass a `double` or `long double`
    `floating_point_constant` by value, caused by its static `double`
    members, not by its empty base; it is now documented. The framework
    does not pass the constants by value, and its Cortex-M33 build has
    no such note.
- #60 Fixed: `cli.dox`: "the proprietary format implemented by the initial
  releases will also be retained, but it is not recommended for new
  projects". This contradicts `reporter-human.h` and the main page,
  which present the human reporter as the one for console readers.
  Should the sentence be removed?
  Answer: the sentence was replaced; the human-readable format is
  described as intended for the console readers, and the TAP format for
  the integration with other tools. The option list now uses en dashes,
  as the other lists of the page do.
- #61 Resolved: `cli.dox`, `inits.dox`: the console examples omit the
  `# Running: …` and `# Built with …` lines written with the normal and
  verbose levels. Should they stay simplified?
  Answer: yes, the examples stay simplified; no change.

## Left unchanged

- #62 `website/doxygen/top-common.h` is generated and read-only, so it
  was reviewed separately, after the user fixed "the utilities
  functionality" and "organization" (see #66 to #75).
- #63 Fixed: the 47 briefs in the imperative mood ("Report …",
  "Mark …", "Check if …", "Retrieve …", "Output the …") in
  `reporter.h`, `reporter-human.h`, `reporter-tap.h`, `exceptions.h`,
  `reflection.h`, and `utility.h` are now in the third person, as the
  other briefs are ("Reports", "Marks", "Checks whether", "Gets",
  "Writes"). The `throws()` and `nothrow()` briefs also say that the
  result is for `expect()` or `require()`, and `reporter-human.h` now
  says "test suite", as its siblings do. To prevent regressions,
  `check-doxygen-style.mjs` needs a check for the imperative briefs; the
  script is generated and read-only, so the change is to be made in its
  `npm-packages-helper` template (a tested patch is available).
- #64 Fixed: the long prose lines in the `.dox` pages
  (`pages/mainpage.dox`, `topics/cli.dox`, and the two paragraphs of
  `topics/cpp-api.dox`, of 265 and 285 characters) were re-wrapped. The
  remaining long lines are justified: 10 lines inside `@code` blocks, in
  `cli.dox`, `inits.dox`, and `function-comparators.dox`, are verbatim
  program output, and the `@defgroup` line of
  `function-comparators.dox` must stay on one line. The style script
  does not check the `.dox` files.
- #65 `website/docs/api` and `website/doxygen/xml` are generated and
  are updated when the documentation is rebuilt.

## Review of `top-common.h`

The file is generated from the `docusaurus-template-liquid` templates,
so the fixes belong in the template; it is shared by all the µOS++
projects, so the text must stay generic.

- #66 Fixed: Line 66: "the main interface to the library" is singular, while
  the folder is described as holding the headers of "the µOS++
  libraries"; use "to the libraries".
- #67 Lines 41-43: "All definitions and documentation topics in this
  file are maintained in the `website/doxygen` folder". This contradicts
  the `DO NOT EDIT` header; the file is generated from the template, and
  only the copy is in `website/doxygen`.
- #68 Fixed: Line 33: "the micro-os-plus group on GitHub"; GitHub calls it an
  organisation, as line 80 does. "Group" is the GitLab term.
- #69 Fixed: Lines 47, 56, and 59: the folder briefs say "C/C++ header files",
  but the details of `include/micro-os-plus` say "C++ header files".
  Use one of them consistently.
- #70 Fixed: Line 62: "data structures, data types and inline implementations"
  lacks the Oxford comma.
- #71 Fixed: Line 28: `.doxyfile` is not in backticks, unlike in
  `files/topics-h.dox`.
- #72 Fixed: Padding, as defined by the review rules:
  - lines 38-39, "to promote modularity, reduce redundancy, and enhance
    maintainability";
  - lines 88-90, "ensuring that users have access to clear guidance,
    usage examples, and best practices for professional embedded
    software development";
  - lines 92-93, "By adopting µOS++, developers benefit from a robust,
    scalable, and well-documented foundation …";
  - lines 108-110, "This approach promotes modular development,
    facilitates code reuse, and ensures seamless integration …".
- #73 Fixed: Trailing spaces on lines 52, 59, 62, 65, 75, and 78.
- #74 Fixed: Lines 81-83 are wrapped unevenly ("This modular structure" alone
  on a line).
- #75 The file is now writable (`-rw-r--r--`), while most of the other
  generated files (for example `website/docusaurus.config.ts`) are
  read-only; if this is not intended, check that regenerating the file
  makes it read-only again.

## Deprecation sections

- #76 Fixed: the generated pages showed two Deprecated sections for
  each entity with both a `@deprecated` comment and a
  `[[deprecated (...)]]` attribute, which Doxygen also turns into a
  Deprecated section. The `@deprecated` comments were removed from the
  59 such declarations, and from the `type_traits` namespace. The version
  was added to the attribute messages (`use test_case (since 5.1.0)`),
  which the compilers also print. Where the comment said more than the
  attribute, the text moved to the `@details`. The duplicate on the
  definition of `reflection::short_name()` was also removed. The
  11 entities in the `type_traits` namespace have no attribute, since
  the attribute is on the namespace, and keep their `@deprecated`
  comment.
  Doxygen 1.18 silently drops a deprecation message made of adjacent
  string literals, which `clang-format` creates when a message does not
  fit on a line. This had hidden the deprecation of the `static_suite`
  constructor for a `static_suite&` body; its message is now a single
  literal (`use a suite& first parameter (since 5.1.0)`). All 60
  attribute messages are single literals after `clang-format`, and the
  Doxygen XML has exactly one Deprecated section, with the version, for
  each of the 71 deprecated entities. Keep the attribute messages short
  enough to stay single literals.

---
name: api-review
description: 'Review the C++ API and implementation of the µTest++ Testing Framework from its source code alone (headers, inlines, and src/, ignoring the Doxygen comments): defects, structure and layering, naming and consistency, simplicity, modern C++ usage, and suitability for embedded targets. Confirm suspected defects with probe programs. Each review is fresh (the earlier reports are not read); report the problems found in a new numbered report, each with a permanent number, and suggest improvements in the source files. Use when the user asks for an "API review", an "API and code review", to "review the API", to "analyse the API design", or to review the design or implementation of the library (as a whole, or of a header or folder).'
argument-hint: 'Optional: header, file, or folder to review (e.g. include/micro-os-plus/micro-test-plus/runner.h); defaults to include/ and src/'
---

# API and Code Review — µTest++ Testing Framework

## When to Use

- The user asks for a review of the API, or of the design or the
  implementation of some classes or headers.
- Before a major release, to collect the breaking changes worth making.
- After a large change to the public headers, to check that the API is
  still consistent.

This skill judges the API and its implementation as a user and a
maintainer meet them: through the code. It reports problems and
suggests improvements; it does not change the code, unless the user
asks for that separately (e.g. "fix #4"; see "Acting on an Item").

Related skills, with different scopes:

- `code-review`: the style, documentation, and correctness of a
  change (a diff or a pull request);
- `doxygen-review`: the Doxygen comments;
- `consistency-check`: the consistency between the code, the website,
  and the other project files;
- `website-review`: the website, excluding the API reference pages;
- `website-api-review`: the API reference pages of the website.

## A Fresh Review Each Time

**Each review is independent of the previous ones.** Do not read the
earlier API reviews (`maintenance/docs/API-REVIEW-*.md`), the other
review, comparison, and compatibility reports in `maintenance/docs/`,
or the commit messages and GitHub issues that refer to their items.
Judge the code as it is now, as if for the first time: the earlier
conclusions must not decide what is examined, what is reported, or
how it is classified. A problem that an earlier review already
reported, and that is still present, is reported again.

The only use of the earlier reports is their file names, to choose
the number of the new report (see "Report"). Never modify an earlier
report as part of a new review. `maintenance/docs/SIZE-COMPARISON.md`
is not a report but the description of a method, and may be followed
(see section 6 of the checks); its results file may not be read.

## Scope

If the user specifies a header, a file, or a folder, review only that
(but read whatever it depends on). Otherwise review:

- the umbrella header `include/micro-os-plus/micro-test-plus.h`;
- the public headers in `include/micro-os-plus/micro-test-plus/`;
- the inline and template definitions in
  `include/micro-os-plus/micro-test-plus/inlines/`;
- the definitions in `src/`.

The build integration that lists the source files is `xcdl-package.jsonc`;
the top-level `CMakeLists.txt` and `meson.build` are generated from it.

The test programs in `tests/sources/*/src/` are not reviewed, but read
them to see how the API is used in practice; they also show which
cases the existing tests cover, and which they do not.

State the scope, the branch, and the commit (`git rev-parse --short
HEAD`) at the top of the report.

## Reading the Code

**Ignore the Doxygen comments.** The review judges what the code
says, not what the comments promise; a problem that the comments
explain away is still a problem of the API (the comments are reviewed
by `doxygen-review`). Strip them first, keeping the original line
numbers, so that every finding can cite the real file and line:

```sh
node .github/skills/api-review/scripts/strip-comments.mjs <scratch>/stripped
```

Run it from the repository root; `<scratch>` is the session scratchpad
folder (never write into the repository). Optional arguments select
other files or folders. Each output line starts with its original line
number.

Then read **every** stripped file in full; do not skim and do not rely
on searches alone. A useful order, from the user's entry points
inwards:

1. `micro-test-plus.h` (what is included, and in which order);
2. `runner.h`, `runner-options.h`, `test.h`, and their inlines and
   `src/` files (the session, its configuration, the suites, and the
   test cases);
3. `check-result.h` and `src/check-result.cpp` (what `expect()` and
   `require()` return and do);
4. `function-comparators.h`, `operators.h`, `exceptions.h`,
   `detail.h` (the checks and the comparison structures);
5. `values.h`, `literals.h`, `extension.h`, `math.h` (the wrappers,
   the literals, and the extension interface);
6. `expression-formatter.h`, `reflection.h` (the failure messages);
7. `reporter.h`, `reporter-human.h`, `reporter-tap.h`, and their
   `src/` files (the output protocol);
8. `counters.h`, `stopwatch.h`, `utility.h` (the support classes);
9. `deprecated.h` (the deprecated definitions that are not class
   members, kept for compatibility).

While reading, note for each class and function: who calls it (the
user, the framework, or only the tests), what it costs (allocations,
copies, formatting), and what it does that its name does not say.
Use `grep` over `include/`, `src/`, and `tests/sources/` to find out
whether an entity is used at all.

The stripped files serve the design review only. The checks of the
layout of the files (formatting, line length, header guards) are made
on the original files.

Check that each public header compiles on its own:

```sh
node .github/skills/api-review/scripts/check-headers.mjs <scratch>/headers
```

The compiler is taken from `CXX` (default `c++`).

Check the formatting without modifying the files:

```sh
xpacks/.bin/clang-format --dry-run --Werror \
  --style=file:maintenance/config/.clang-format <files>
```

## Confirming Findings with Probes

A suspected defect is reported as a defect only after it has been
reproduced; otherwise say that it is derived from reading the code.
Write small probe programs in `<scratch>/probe/` and build them
against the library sources, with no other dependency (the
`micro-os-plus/diag/trace.h` header is optional):

```sh
P=<scratch>/probe
W="-Wall -Wextra -Wpedantic"
for f in src/*.cpp
do
  c++ -std=c++20 $W -DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED -Iinclude \
    -c "$f" -o "$P/$(basename "$f" .cpp).o"
done
c++ -std=c++20 $W -DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED -Iinclude \
  "$P/p1.cpp" "$P"/*.o -o "$P/p1"
"$P/p1" --reporter=human --verbose
```

- Build with both GCC and Clang when the question involves warnings,
  overload resolution, or name lookup. With Clang, `-Weverything`
  reports much more; report only the warnings that the library's own
  pragmas do not already silence deliberately.
- Use one probe per question, or one probe with `#if defined(P_...)`
  sections compiled one at a time, when the question is whether
  something compiles or links.
- Build once with `-fno-exceptions -fno-rtti` when the question
  concerns the code guarded by `__cpp_exceptions` or anything that
  may depend on RTTI.
- When the output matters, run the combinations listed under "Output"
  in the checks, and validate every TAP output (console and file) with
  the validator of the tests, which follows TAP 14 and checks the
  plan, the test points, and the YAML blocks:

  ```sh
  "$P/p1" > "$P/p1.tap"
  node tests/scripts/validate-tap.mjs "$P/p1.tap"
  ```

- For the questions that depend on the target (the widths of the
  types, the floating-point unit, the stack frames, warnings such as
  `-Wpsabi` that only appear there), compile the library and the probe
  with a 32-bit cross compiler as well; the test build folders have
  one in `tests/build/qemu-cortex-m4f-cmake-gcc-debug/xpacks/.bin/`
  (`arm-none-eabi-g++`). Compiling with `-c` needs no platform files:

  ```sh
  arm-none-eabi-g++ -std=c++20 -mcpu=cortex-m4 -mthumb \
    -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fno-exceptions -fno-rtti \
    -Wall -Wextra -Wpedantic -Wdouble-promotion \
    -Wframe-larger-than=512 -fstack-usage \
    -DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED -Iinclude \
    -c <file> -o <scratch>/cross/<name>.o
  ```

- For lifetime questions, compile the probe with
  `-g -fsanitize=address` (and `-fsanitize=undefined` for arithmetic,
  pointer arithmetic, and type punning); use strings long enough to be
  allocated on the heap, otherwise the small string optimisation hides
  the error.
- Probes stay in the scratchpad; they are evidence for the report,
  not tests. When a defect is later fixed, the probe becomes the
  regression test in `tests/sources/unit/`.

## Checks

### 1. Defects

Behaviour a user would see as wrong. These come first in the report.
The questions that found real defects in this code base:

- **Undefined behaviour**: code that compiles but may crash or produce
  incorrect results (null or dangling pointers, out-of-bounds access,
  signed overflow, invalid casts, pointer arithmetic outside an
  object).
- **Lifetimes**: which pointers and references does an object keep
  (names as `const char*`, `string_view` members, references to
  arguments)? Is the stored object used after the call returns
  (deferred suites, stored check results)?
- **Call order and repetition**: what happens when a session function
  is called twice, out of order, or not at all (`initialise()`,
  `exit_code()`)? Are side effects hidden in functions that look like
  queries?
- **Nesting**: test cases inside test cases, checks before and after a
  nested test case, failures in a nested test case (do they reach the
  parent, the suite, and the totals?).
- **Shared state**: objects shared by all checks (the formatter, the
  reporter's buffer); what happens when the result of `expect()` is
  kept in a variable, or two results are alive at once?
- **Name lookup**: unqualified calls to generic names (`get`, `abs`,
  `pow`) inside templates, which argument-dependent lookup can
  redirect to a user's function.
- **Concepts that match too much**: concepts and traits that
  recognise a type by the presence of a member (`value`, `epsilon`,
  `npos`, `begin()` and `end()`) also match user types that happen to
  have a member with that name. Probe each one with such a user type
  and check that the result of the comparison does not change.
- **Every fundamental type through every output path**: `bool`,
  `char`, `signed char`, `unsigned char`, `wchar_t`, `char8_t`,
  `char16_t`, `char32_t`, `char*`, `const char*`, `std::nullptr_t`,
  the floating-point types (including `long double`), enumerations,
  `std::byte`, and pointers, streamed into a check message, into the
  reporter, and into the expression formatter. Declared but undefined
  functions show up only at link time.
- **Special values**: `'\0'` (which may truncate the rest of the
  output), empty strings, null C strings, NaN, the infinities, `-0.0`,
  and the minimum and maximum of each type; the precision with which
  each floating-point type is printed.
- **Literals**: octal, hexadecimal, and binary prefixes, digit
  separators, decimal points in integer literals, values out of range
  for the target type, and the widths of the intermediate types on
  32-bit targets (`unsigned long` is 32 bits on Cortex-M, RISC-V 32,
  and AArch32). Unary `-` and `~` on the narrow typed literals and
  wrappers, which the integral promotions may turn into `int`.
- **Comparisons**: the six relations applied consistently (in
  particular any tolerance for floating-point values), mixed types
  (string literals against `std::string`, arrays, pointers to
  characters, containers of different types), the common standard
  types (`std::string_view`, `std::optional`, `std::span`, the
  `std::chrono` durations, scoped enumerations), and the operator
  overloads that the standard ones may outrank.
- **Exceptions**: what happens when a test body or a suite body
  throws; what the `throws`/`nothrow` checks do with unexpected
  exception types. With exceptions disabled, the same failures must
  have the same effect (a failed `require()` stops the same scope, not
  the whole run), unless the difference is unavoidable and visible.
- **Registration**: `static_suite` objects constructed before the
  runner, in other translation units (the static initialisation
  order), during `run()`, or after it; none of them may be silently
  ignored.
- **Copy and move**: objects that are registered in a list or referred
  to by pointer must not be copyable or movable; value types (e.g. the
  counters) must be copyable. A constructor with side effects (a
  registration) combined with an implicit copy registers twice.
- **Include order and configuration**: a type, a default, or an
  inline body that changes with the order of the includes, or with
  the macros of `micro-os-plus/project-config.h` and
  `micro-os-plus/micro-test-plus-defines.h`, violates the one
  definition rule when two translation units differ. Probe with two
  translation units that include the headers in different orders, or
  with different macros, linked together.
- **Stack usage**: recursion (also in templates and literal parsing),
  large local buffers, and large objects passed by value; embedded
  stacks are a few kilobytes. Use the `-fstack-usage` output of the
  cross build.
- **Output**: what the user reads, in every combination of the
  reporter (TAP, human), the verbosity (`--silent`, `--quiet`, normal,
  `--verbose`), the output file (with and without `--output-file`),
  the colours, `--list-tests`, and the filters:
  - the TAP output, on the console and in the file, is valid TAP 14
    (the validator above); the plan `1..N` matches the test points at
    every verbosity; the YAML blocks are valid YAML;
  - names and messages that contain `#`, `\`, a newline, or a colon
    are escaped, so that they cannot become a directive, a comment, or
    a YAML key (the validator does not detect a misplaced `#`);
  - silent mode prints nothing; quiet mode still shows which checks
    failed; the console and the output file agree, and neither
    depends on the verbosity of the other;
  - configuration and command-line errors reach the output file, not
    only the console;
  - the wording of the markers matches what happened (e.g. "aborted"
    only when the run was aborted).
- **Header self-containment** (the script above).

### 2. Structure and layering

- **Public and internal**: which members of the public classes exist
  only for the framework (setters, counters, mutable accessors)? Can a
  user break the state of a test? Are internal constructors public?
- **Leaks of `detail`**: `detail` types in public signatures, in base
  classes of public classes, or returned through `auto`, which force
  the users to name them.
- **Extensibility**: are the classes that look extensible (the
  reporters, the formatter) actually extensible, and are the parts
  meant for users (the `extension` namespace) separated from the
  internal protocol?
- **Configuration**: can everything be configured without a command
  line (embedded targets have no `argv`)? Is the command line parsed
  in one place, with one error policy?
- **Termination**: every `exit()`, `abort()`, and `assert()` in the
  library; a framework should report and let the application decide.
- **Inheritance**: inheritance used only to reuse members (prefer
  composition), templates whose parameter has no effect, and derived
  classes that bypass their base. `protected` members and `virtual`
  functions only in classes designed for derivation; the others are
  `final`.
- **Symmetry**: the same concept offered in several forms with
  different signatures or capabilities (`suite` and `static_suite`,
  `expect()` and `require()`, the function comparators and the
  operators, the `to_i` wrappers and the `_i` literals); each form
  should offer the same features, unless the omission is deliberate
  and visible from the code. Every type accepted as an operand of a
  check is also accepted after `<<` in its message.
- **Hidden policies**: execution order, deferred versus immediate
  execution, sorting, and anything else that the names do not reveal.
- **Dead or misplaced code**: public helpers used only by the tests or
  not at all, value types in a traits namespace, implementation
  helpers in public namespaces.
- **File layout**: declarations in `include/`, inline and template
  definitions in `include/.../inlines/<name>-inlines.h`, out-of-line
  definitions in `src/<name>.cpp`, one file per header of the same
  name; every source file registered in `xcdl-package.jsonc`, and the
  top-level `CMakeLists.txt` and `meson.build` matching the output of
  `xpm run xcdl-export` (they are never edited by hand).

### 3. Naming and consistency

- **Case**: identifiers use `snake_case` (types, functions, variables,
  members); file names are lower-case words separated by dashes (e.g.
  `runner-inlines.h`).
- **Accessors**: getters and setters are nouns and share the name
  (`name()` and `name (const char* s)`), not `get_name()` and
  `set_name()`. Getters have no side effects; setters return `void`
  (no chaining) and change only the value they set.
- **Other member functions** start with a verb that states their
  effect. Flag names that do not describe the effect (a query that
  runs the tests, a `flush()` that does not flush the buffer, a
  `reporter` that is a check result).
- Member functions named after types, which force elaborated type
  specifiers (`class suite&`, `enum verbosity`).
- Several names for one concept (test case, subtest, test); several
  spellings for one entity (`_i`, `to_i`, the `_i` literal). When
  there are many, add a consistency table to the report.
- Naming conventions with several meanings (the trailing underscore
  for non-public members).
- Deprecated entities without `[[deprecated]]`.
- `(void)` versus `()`, `virtual` repeated on overrides, `final` on
  members of `final` classes.
- Boolean and adjacent same-type parameters that are unreadable at
  the call site.
- Deviations from the patterns used elsewhere in the code base, without
  a visible reason.
- **Macros**: compiler-specific macros where a standard feature-test
  macro exists (`__EXCEPTIONS` instead of `__cpp_exceptions`,
  `__GXX_RTTI` instead of `__cpp_rtti`).
- **Header guards**: the path relative to `include/`, in upper case,
  with each non-alphanumeric character replaced by an underscore, and
  a trailing underscore (e.g.
  `MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TEST_INLINES_H_`); unique
  across the project.
- **Layout** (checked on the original files): the formatting matches
  `maintenance/config/.clang-format` (the command above); no line
  exceeds 80 characters, except link URLs and the file path in a
  `DO NOT EDIT` comment of a generated file.

### 4. Simplicity and duplication

- Favour readability over cleverness and compactness.
- The same logic implemented twice or more (sorting, formatting of
  times, file names of paths, `run()` bodies, stream operators);
  hand-written algorithms where the standard library has one.
- Families of near-identical templates that one parameterised
  template would replace.
- Unneeded indirection (pointers to vectors, `std::bind`, two-level
  hierarchies with nothing in one level).
- Unnecessary copies (operands stored by value and returned by value
  several times).

### 5. Modern C++

The code base targets C++20; flag code written in an older style where
a modern equivalent is clearly preferable:

- `concepts` and `requires` clauses instead of SFINAE and
  `std::enable_if`;
- `constexpr` and `consteval` instead of macros and run-time checks,
  where the value is known at compile time;
- range-based `for`, structured bindings, `auto`, and `<=>`, where
  they simplify the code without harming readability;
- `[[nodiscard]]`, `[[maybe_unused]]`, and the other standard
  attributes instead of compiler-specific equivalents;
- missing `const` on parameters, members, and member functions;
- missing or incorrect `noexcept` (move operations, destructors, and
  functions that cannot throw);
- raw pointers, casts, and macros where a standard facility would be
  clearer and safer, within the constraints of section 6.

### 6. Suitability for embedded targets

Program size matters more than speed. The library may use the heap
and the standard containers, but it must build without exceptions and
without RTTI.

- Heap allocations per test case and per check; objects kept alive
  after use; `std::function` and `std::bind` overheads.
- Work done for output that is never printed (formatting every
  passing check).
- Fixed-size buffers and silent truncation.
- Dependencies on the hosted environment (`argv`, files, `exit()`,
  clocks), and whether the build works with `-fno-exceptions` and
  `-fno-rtti`.
- The stack frames reported by the cross build (`-fstack-usage`,
  `-Wframe-larger-than=512`).

Claims about the program size are measured, not estimated, with the
method described in `maintenance/docs/SIZE-COMPARISON.md` (the build
folders of the platform must exist first). Write the suggested change
as a patch in the scratchpad, keep the working folder there too, and
quote the difference in the finding:

```sh
python3 -I maintenance/scripts/size-comparison/compare-sizes.py \
  --baseline HEAD --current HEAD \
  --current-patch <scratch>/change.patch --work <scratch>/size
```

### 7. Incidental observations

Problems noticed along the way that are not API design: stale forward
declarations, macros leaking into user code, casts, fragile
compiler-specific code.

### 8. Reviewed and found sound

List the parts that were checked and are good, so that the maintainer
knows what was covered, and so that the report is not read as a list
of complaints only.

## Judging Findings

- Report a problem only when it can mislead a user, cause a wrong
  result, cost resources, or make the code harder to understand or
  maintain. Do not report a preference.
- Each finding cites the file and the line (from the stripped output,
  which keeps the original numbers), states the problem directly,
  gives the evidence (the probe and its output, or the code path), and
  proposes a concrete change. When several solutions are reasonable,
  offer them and leave the decision to the maintainer.
- Verify every line number cited in a file outside the stripped set
  (for example in `tests/`) before writing it.
- Tag each finding **[breaking]** when the suggested change alters the
  public API, or **[internal]** when it does not, and
  **[confirmed]** when a probe reproduced it.
- For each **[breaking]** finding, propose the migration path: an
  alias or overload with `[[deprecated]]` for one major release, or,
  when that is not possible, the reason, and the text that the release
  notes should give to the users.

## Numbering

Every actionable item in the report gets a permanent number, `#1`,
`#2`, and so on, counting through the whole report (not restarting in
each section), so that the user can refer to any of them (e.g. "fix
#12", "apply #40 to #43"). Only the descriptive parts (the header, the
summary) and the "Reviewed and found sound" list are not numbered.
Each new report starts again from `#1`, so an item is identified by
the report and the number (e.g. `API-REVIEW-3.md #12`).

- Each problem is a separate numbered item; several occurrences of the
  same problem (e.g. the same duplication in five places) are one item.
- Do not group independent problems under one number; a sub-list is
  acceptable only for the details of a single problem.
- The summary and the suggested order of work refer to the items by
  number.
- The numbers never change once assigned, and are never reused. When
  an item is fixed later, mark it `(fixed)` with a one-line note (with
  the commit), in the report that lists it.
- If a problem turns out to be wrong, mark it `(withdrawn)` with the
  reason; do not delete it.

## Report

Write the report to a new file, `maintenance/docs/API-REVIEW-<n>.md`,
where `<n>` is one more than the highest number of the existing
`API-REVIEW-*.md` files (list the file names only, do not open them;
`1` if there are none). Never overwrite an existing report.

Write it in British English and in a formal tone (no contractions, the
Oxford comma, "folder" rather than "directory"), with lines shorter
than 80 characters, except inside code blocks when unavoidable:

```markdown
# C++ API review

Date: <date>, on branch `<branch>`, commit `<hash>`.

Scope: <files reviewed; that the Doxygen comments were ignored>.

Method: <how the code was read, the number of files and lines of code,
the compiler and flags used for the probes, the sanitizers>.

Independence: the earlier reports in `maintenance/docs/`, and the
commits and issues that refer to them, were deliberately not
consulted.

Summary: <n> problems (<open> open, <fixed> fixed, <withdrawn>
withdrawn). <The most serious problems, by number, and the suggested
order of work: defects first, then non-breaking clean-ups, then the
breaking changes, grouped for one major release.>

<the meaning of the tags [breaking], [internal], and [confirmed]>

## 1. Defects

- **#1 — <short title>.** [breaking|internal] **[confirmed]**
  `<file>` lines <n> to <m>: <what is wrong, the evidence, and the
  suggested change>

## 2. Structure and layering

## 3. Naming and consistency

## 4. Simplicity and duplication

## 5. Modern C++

## 6. Suitability for embedded targets

## 7. Incidental observations

## 8. Reviewed and found sound

- <parts checked without problems>
```

Paths in the report are relative to the repository root, or to
`include/micro-os-plus/micro-test-plus/` when unambiguous (e.g.
`runner.h`, `inlines/test-inlines.h`); `src/` paths are always written
in full.

## Procedure

1. Determine the scope, and the number of the new report (from the
   file names only; do not read the earlier reports).
2. Strip the comments, check the headers, and check the formatting
   (commands above).
3. Read every stripped file in the order given, noting suspected
   problems with their file and line.
4. Read the sample programs in `tests/sources/` to see the intended
   use and the existing coverage.
5. Write probes for every suspected defect and every "does this
   compile/link" question; record the outcome.
6. Classify, tag, and number the findings.
7. Write the report to the new file.
8. Give the user a short summary: the counts, the most serious
   problems by number, and the decisions needed. Do not change the code
   unless asked.

## Acting on an Item

When the user later refers to a number (e.g. "fix #7"), it refers to
the most recent report, unless the user names another one:

1. Make sure that the previous fix is committed; do not start a new
   fix on top of uncommitted changes.
2. Change the code, keeping the split between the headers, the
   inlines, and `src/`.
3. Where the item is a defect, turn its probe into a regression test
   in `tests/sources/unit/`; where it adds functionality, add tests
   that cover it.
4. Update the hand-written pages of the website that describe the
   changed API, in particular the user manual in `website/docs/user/`.
   Ignore the pages generated by Doxygen (`website/doxygen/` and
   `website/docs/api/`); they are regenerated separately.
5. Run the tests required by the Testing section of
   `.github/copilot-instructions.md` (`test-selected` after major
   changes, `test` after minor ones), and report the outcome.
6. Update the status of the item in the report that lists it.
7. Commit only when the user asks, following
   `.github/skills/github-commit/SKILL.md`, which also covers the
   reference to the GitHub issue and the update of the report.

---
name: api-review
description: 'Review the C++ API of the µTest++ Testing Framework from its source code alone (headers, inlines, and src/, ignoring the Doxygen comments): structure and layering, consistency, naming, elegance, readability, ease of understanding, and suitability for embedded targets. Confirm suspected defects with probe programs. Report the problems found, each with a permanent number, and suggest improvements in the source files. Use when the user asks for an "API review", to "review the API", to "analyse the API design", or to check the public interface for consistency or usability problems.'
argument-hint: 'Optional: header, file, or folder to review (e.g. include/micro-os-plus/micro-test-plus/runner.h); defaults to include/ and src/'
---

# API Review — µTest++ Testing Framework

## When to Use

- The user asks for a review of the API, or of the design of some
  classes or headers.
- Before a major release, to collect the breaking changes worth making.
- After a large change to the public headers, to check that the API is
  still consistent.

This skill judges the API as a user and a maintainer meet it: through
the code. It reports problems and suggests improvements; it does not
change the code, unless the user asks for that separately (e.g. "fix
#4").

Related skills, with different scopes:

- `code-review`: style, documentation, and correctness of a change;
- `doxygen-review`: the Doxygen comments;
- `website-review`: the website, excluding the API reference pages;
- `website-api-review`: the API reference pages of the website.

## Scope

If the user specifies a header, a file, or a folder, review only that
(but read whatever it depends on). Otherwise review:

- the umbrella header `include/micro-os-plus/micro-test-plus.h`;
- the public headers in `include/micro-os-plus/micro-test-plus/`;
- the inline and template definitions in
  `include/micro-os-plus/micro-test-plus/inlines/`;
- the definitions in `src/`.

The sample programs in `tests/sources/*/src/` are not reviewed, but
read them to see how the API is used in practice; they are also the
place where the existing tests show which cases are (and are not)
covered.

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
   `assume()` return and do);
4. `function-comparators.h`, `operators.h`, `exceptions.h`,
   `detail.h` (the checks and the comparison structures);
5. `values.h`, `literals.h`, `extension.h`, `math.h` (the wrappers
   and the literals);
6. `expression-formatter.h`, `reflection.h` (the failure messages);
7. `reporter.h`, `reporter-human.h`, `reporter-tap.h`, and their
   `src/` files (the output protocol);
8. `counters.h`, `stopwatch.h`, `utility.h` (the support classes).

While reading, note for each class and function: who calls it (the
user, the framework, or only the tests), what it costs (allocations,
copies, formatting), and what it does that its name does not say.
Use `grep` over `include/`, `src/`, and `tests/sources/` to find out
whether an entity is used at all.

Check that each public header compiles on its own:

```sh
node .github/skills/api-review/scripts/check-headers.mjs <scratch>/headers
```

The compiler is taken from `CXX` (default `c++`).

## Confirming Findings with Probes

A suspected defect is reported as a defect only after it has been
reproduced; otherwise say that it is derived from reading the code.
Write small probe programs in `<scratch>/probe/` and build them
against the library sources, with no other dependency (the
`micro-os-plus/diag/trace.h` header is optional):

```sh
P=<scratch>/probe
for f in src/*.cpp
do
  c++ -std=c++20 -DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED -Iinclude \
    -c "$f" -o "$P/$(basename "$f" .cpp).o"
done
c++ -std=c++20 -DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED -Iinclude \
  "$P/p1.cpp" "$P"/*.o -o "$P/p1"
"$P/p1" --reporter=human --verbose
```

- Use one probe per question, or one probe with `#if defined(P_...)`
  sections compiled one at a time, when the question is whether
  something compiles or links.
- Run with both reporters (`--reporter=human`, the default TAP) and
  with `--verbose` and `--quiet` when the output matters.
- For lifetime questions, compile the probe with
  `-g -fsanitize=address` (and `-fsanitize=undefined` for arithmetic);
  use strings long enough to be allocated on the heap, otherwise the
  small string optimisation hides the error.
- Probes stay in the scratchpad; they are evidence for the report,
  not tests. When a defect is later fixed, the probe becomes the
  regression test in `tests/sources/unit/`.

## Checks

### 1. Defects

Behaviour a user would see as wrong. These come first in the report.
The questions that found real defects in this code base:

- **Undefined behaviour**: code that compiles but may crash, produce
  incorrect results, or have other unexpected effects due to violations
  of the language rules (e.g., dereferencing null pointers, out-of-bounds
  array access, use-after-free).
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
- **Every fundamental type through every output path**: `bool`,
  `char`, `signed char`, `unsigned char`, `char*`, `const char*`,
  `std::nullptr_t`, the floating-point types, and pointers, streamed
  into a check message, into the reporter, and into the expression
  formatter. Declared but undefined functions show up only at link
  time.
- **Literals**: octal, hexadecimal, and binary prefixes, digit
  separators, decimal points in integer literals, values out of range
  for the target type, and the widths of the intermediate types on
  32-bit targets (`unsigned long` is 32 bits on Cortex-M, RISC-V 32,
  and AArch32).
- **Comparisons**: the six relations applied consistently (in
  particular any tolerance for floating-point values), mixed types
  (string literals against `std::string`, arrays, pointers to
  characters, containers of different types), and the operator
  overloads that the standard ones may outrank.
- **Exceptions**: what happens when a test body throws; what the
  `throws`/`nothrow` checks do with unexpected exception types.
- **Header self-containment** (the script above).

### 2. Structure and layering

- **Public and internal**: which members of the public classes exist
  only for the framework (setters, counters, mutable accessors)? Can a
  user break the state of a test? Are internal constructors public?
- **detail namespace**: types and functions in the `detail` namespace
  should remain internal and not leak into public interfaces.
- **Leaks of `detail`**: `detail` types in public signatures, in base
  classes of public classes, or returned through `auto`.
- **Extensibility**: are the classes that look extensible (the
  reporters, the formatter) actually extensible, and are the parts
  meant for users separated from the internal protocol?
- **Configuration**: can everything be configured without a command
  line (embedded targets have no `argv`)? Is the command line parsed
  in one place, with one error policy?
- **Termination**: every `exit()`, `abort()`, and `assert()` in the
  library; a framework should report and let the application decide.
- **Inheritance**: inheritance used only to reuse members (prefer
  composition), templates whose parameter has no effect, and derived
  classes that bypass their base.
- **Symmetry**: the same concept offered in two forms with different
  signatures (static and dynamic suites, and their callables).
- **Hidden policies**: execution order, deferred versus immediate
  execution, sorting, and anything else that the names do not reveal.
- **Dead or misplaced code**: public helpers used only by the tests or
  not at all, value types in a traits namespace, implementation
  helpers in public namespaces.

### 3. Naming and consistency

- Getters and setters should be nouns (e.g., `name()` for a getter, 
  `name(char* s)` for a setter).
- Setters should return `void` and not the object itself (avoid chaining).
- Getters should not have side effects.
- Setters should not have side effects beyond modifying the value they set.
- Consistency between getter and setter names (e.g., `name()` and
  `name(char* s)`).
- Getter and setter names should clearly indicate their purpose.
- Member functions names should start with a verb that clearly indicate
  their effect and purpose.
- Names that do not describe the effect (a query that runs the tests,
  a `flush()` that does not flush the buffer, a `reporter` that is a
  check result).
- Member functions named after types, which force elaborated type
  specifiers (`class suite&`, `enum verbosity`).
- Several names for one concept (test case, subtest, test); several
  spellings for one entity (`_i`, `to_i`, the `_i` literal). When
  there are many, add a consistency table to the report.
- Naming conventions with several meanings (the trailing underscore
  for non-public members).
- Deprecated entities without `[[deprecated]]`.
- Accessor style (`name()` versus `get_name()`), `(void)` versus `()`,
  `virtual` repeated on overrides, `final` on members of `final`
  classes.
- Boolean and adjacent same-type parameters that are unreadable at
  the call site.
- Missing `const` on parameters, members, and virtual functions.
- Missing `noexcept` on functions that are not expected to throw exceptions.
- Missing `constexpr` on functions and variables that can be evaluated at
  compile time.

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

### 5. Suitability for embedded targets

- Program size is more important than performance for embedded targets.

- Heap allocations per test case and per check; objects kept alive
  after use; `std::function` and `std::bind` overheads.
- Work done for output that is never printed (formatting every
  passing check).
- Fixed-size buffers and silent truncation.
- Dependencies on the hosted environment (`argv`, files, `exit()`,
  clocks), and whether the build works without exceptions and RTTI.

### 6. Incidental observations

Problems noticed along the way that are not API design: stale forward
declarations, macros leaking into user code, casts, fragile
compiler-specific code.

### 7. Reviewed and found sound

List the parts that were checked and are good, so that the next review
knows what was covered, and so that the report is not read as a list
of complaints only.

## Running test

If the changes add new functionality, add new tests to cover it.

After performing any changes, run the tests, first with the
native compiler:

```sh
xpm run test
```

and then via the QEMU emulator:

```sh
xpm run test-latest-cmake
```

## Documentation

Update the documentation to reflect any changes made to the API. 
Ensure that all public interfaces are properly documented in the 
`website/docs` pages, especially the user manual in `website/docs/user`
and that any changes to the API are reflected in the documentation.

Ignore the pages automatically generated by Doxygen (in `website/doxygen` 
and `website/docs/api`), they are reviewed separately.

## Committing the changes

When committing the changes, make sure to reference the GitHub issue numbers
and provide a clear, concise commit message that describes the changes made.

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
- Read the other reports in `maintenance/docs/` first (in particular
  `WEBSITE-API-REVIEW.md`, whose API design section overlaps this
  review). Do not repeat their findings silently: when an item
  overlaps, say "Same as" or "Overlaps" with their number.

## Numbering

Every actionable item in the report gets a permanent number, `#1`,
`#2`, and so on, counting through the whole report (not restarting in
each section), so that the user can refer to any of them (e.g. "fix
#12", "apply #40 to #43"). Only the descriptive parts (the header, the
summary) and the "Reviewed and found sound" list are not numbered.

- Each problem is a separate numbered item; several occurrences of the
  same problem (e.g. the same duplication in five places) are one item.
- Do not group independent problems under one number; a sub-list is
  acceptable only for the details of a single problem.
- The summary and the suggested order of work refer to the items by
  number.
- The numbers never change once assigned. When the report already
  exists, read it first: keep the numbers of the problems already
  listed, mark those fixed meanwhile with `(fixed)` and a one-line note
  (with the commit), keep those still open, and number the new problems
  after the highest existing number. Never reuse a number.
- If a problem turns out to be wrong, mark it `(withdrawn)` with the
  reason; do not delete it.
- When the user later refers to a number (e.g. "fix #7"), act on that
  item, add a regression test where the item is a defect, run the tests
  required by `.github/copilot-instructions.md`, and update the item's
  status in the report.

## Report

Write the report to `maintenance/docs/API-REVIEW.md`, in British English
and in a formal tone (no contractions, the Oxford comma, "folder"
rather than "directory"), with lines shorter than 80 characters, except
inside code blocks when unavoidable:

```markdown
# C++ API review

Date: <date>, on branch `<branch>`, commit `<hash>`.

Scope: <files reviewed; that the Doxygen comments were ignored>.

Method: <how the code was read, the number of files and lines of code,
the compiler and flags used for the probes, the sanitizers>.

<the overlap with the other reports in maintenance/docs/>

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

## 5. Suitability for embedded targets

## 6. Incidental observations

## 7. Reviewed and found sound

- <parts checked without problems>
```

Paths in the report are relative to the repository root, or to
`include/micro-os-plus/micro-test-plus/` when unambiguous (e.g.
`runner.h`, `inlines/test-inlines.h`); `src/` paths are always written
in full.

## Procedure

1. Determine the scope; read the existing `API-REVIEW.md`, if any, and
   the other reports in `maintenance/docs/`.
2. Strip the comments and check the headers (scripts above).
3. Read every stripped file in the order given, noting suspected
   problems with their file and line.
4. Read the sample programs in `tests/sources/` to see the intended
   use and the existing coverage.
5. Write probes for every suspected defect and every "does this
   compile/link" question; record the outcome.
6. Classify, tag, and number the findings; cross-reference the other
   reports.
7. Write the report.
8. Give the user a short summary: the counts, the most serious
   problems by number, and the decisions needed. Do not change the code
   unless asked.

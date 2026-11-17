# website-api-review — µTest++ Testing Framework

The rules of the `website-api-review` skill that are specific to this
project. This file is owned by the project, and it is never
regenerated; it extends the generated `SKILL.md` in this folder, and
takes precedence over it where they differ.

## The Published Pages

The local file names differ from the URLs, for example
`website/docs/api/classes/micro-os-plus-micro-test-plus-runner.md` is
published as `classes/micro-os-plus/micro-test-plus/runner/`, and
downloaded as `classes--micro-os-plus--micro-test-plus--runner.html`.

The hand-written Doxygen sources include `files/*.dox`,
`folders/*.dox`, `macros/*.dox`, `topics/*.dox`, and
`topics/cpp-api/*.dox`, in `website/doxygen/`.

## Decisions of the Maintainer

The following were decided in the review `WEBSITE-API-REVIEW-3.md`. Do
not report them again, and do not ask about them; if one of them seems
wrong, say so in one line, without a numbered finding.

Kept as they are (accepted):

- the Doxygen options in "The Doxygen Configuration" above, and the page
  sizes that result;
- the root of the topic tree ("µOS++ Topics", "µTest++", "C++ API") and
  its collapsed levels;
- "Expectations" and "Requirements" as two topics;
- the "C API" topic, in the reference;
- the terms "test session", "test run", and "test execution", and the
  name "subtest" (the deprecated alias, and real unit test cases);
- the documentation-only files `top-common.h` and `topics.h` in the
  Files index;
- the duplicate entries of `compare_op`, `predicate_op`, and
  `comparison_integer<T>` in the Classes index;
- `detail::check_result&&` in the signatures of `expect()` and
  `require()`, the alias `expression_formatter` of the `detail` class,
  `class suite&` in the signatures (until the deprecated
  `runner::suite()` is removed), and the inherited `name()` and
  `totals()`, documented through `detail::runnable_base`;
- the deprecated code, which is not changed: a defect in it is a finding
  about the page, which states the actual behaviour;
- the sentences "for diagnostic purposes" of the trace descriptions.

Conventions (applied; report a deviation):

- titles of topics and sections in sentence case ("Test runners",
  "Command-line options"), except for the acronyms and the names;
- "run-time" as an adjective and "run time" as a noun, "floating-point"
  and "command-line" as adjectives, and "check" for a verification
  ("assertion" only for the static assertions and the other frameworks);
- `@ref` for the first mention, on a page, of a class or a function
  that has a page, since a plain code span is not linked by Doxygen;
- in a Markdown table, a bar inside a code span is written as separate
  code spans joined by `\|`, since `\|` inside one code span is shown with
  its backslash;
- the stale `SITEMAP_URL` was a defect, fixed in the template
  `common-config-liquid.doxyfile` of `docusaurus-template-liquid`, and
  locally, as `{{packageHomepage}}doxygen/`; a project that still has
  `reference/` has not regenerated its commons;
- the rejecting overloads, and the out-of-line definitions of the
  deprecated `expect()` and `require()`, are hidden from Doxygen (see
  `doxygen-review`).

Fixes of the converter (`@xpack/doxygen2docusaurus`) found by the
review, to be present in the pages after its release: the descriptions
of the enumerators, the access prefix of the enumerations of a class,
and the sentences "The ... topics, with their brief descriptions, are:"
and "The classes and structs used by this project are:". If the pages
lack them, the converter is older.

## Reading Order

1. In the topic tree, the order of the reader's task is: runner,
   suites, test cases, checks, comparators, operators, literals,
   exceptions, customisation, utilities, configuration, command line.
2. The namespace pages start with `micro_os_plus::micro_test_plus`.
3. The public classes are `runner`, `runner_options`, `suite`,
   `static_suite`, `top_suite`, `test_case`, `located_name`, and
   `counters` (list the `classes--*.html` files to find the current
   ones); deprecated aliases such as `static_runner` have no page of
   their own.

## Sources of Truth

- behaviour: follow the call chain, for example from `expect()` to the
  deferred reporter destructor, to the reporter, to `runner::abort()`;
- sample outputs: `tests/expected/tap/` and `tests/expected/txt/`, and
  the programs in `tests/sources/*/src/` (check the suite names, the
  file names, the line numbers, and the number format); remember that
  the reference files are written with `--output-file`, which may
  differ from the console output at the same verbosity;
- configuration macros: `micro-test-plus.h`, `xcdl-package.jsonc`, and
  the `micro-test-plus-defines.h` files under `tests/platforms/`.

## Past Findings

Examples in this project have failed for these reasons (re-verify each
one; they may be fixed by now):

- literals that the literal operators reject (`42_f`; the
  floating-point literals require a decimal point);
- names that resolve only inside `namespace micro_os_plus`
  (`micro_test_plus::operators` instead of `mt::operators`), or an
  `mt` alias used but not declared;
- undeclared placeholder names (`answer`, `expression`);
- objects declared `static` in one file and used from another;
- deprecated constructors in examples;
- a combination that the types do not allow (a `static_suite` with a
  plain `runner`);
- patterns that silently record nothing (an explicit `try` block with
  no check on the normal path);
- shadowed lambda parameters (`-Wshadow`).

Checks of the claims that need a probe or a code path found (re-verify
before reporting; the code may have changed):

- a failed assumption terminates the process (`::abort()`), at the
  end of the statement, with no summary and no exit code, while the
  text said "the test is terminated immediately";
- the result of `expect()` is a deferred reporter object, not a stream;
- containers are compared with their own `operator==`, and only the
  failure message iterates the elements;
- with `using namespace mt::operators`, the standard `operator==`
  outranks the framework's container operators for same-type standard
  containers, so no operand values are reported;
- comparisons with floating-point literals use a tolerance derived
  from the decimals of the literal (`42.05f == 42.0_f` is true);
- the pointer overloads of `eq()` compare C strings by address;
- the overloaded `&&` and `||` evaluate both operands;
- `"false"_b` is true;
- the human-readable reporter filters the output file by verbosity, the TAP
  reporter does not, while the shared `verbosity` documentation
  describes only one of them.

Defects found in the past: a namespace that moved (`detail::op` for
`type_traits::op`), the description of an "evaluator" that no longer
exists, and two topics giving opposite advice about the human-readable
reporter.

## Completeness

The subjects that a user of this library needs, in addition to the
general ones:

- every literal suffix and wrapper, with their rules;
- the execution order of suites and test cases, and which runner each
  suite kind requires;
- what a check displays on success and on failure, and which message
  types it accepts;
- the exception checks exist only with `__cpp_exceptions`;
- the traps: tolerances, pointer comparisons, evaluation of both
  operands, operator overload resolution;
- the customisation point `expression_formatter`, for the user-defined
  types;
- the Doxygen-only definitions appear on the page as "Definition at
  line ... of micro-test-plus.h".

## Kept on Purpose

In addition to the decisions above, do not report or propose:

- in the structure: a change of the root of the topic tree ("µOS++
  Topics", "µTest++", "C++ API") or of its collapsed levels; a separate
  index for `math` and `reflection`; the documentation-only files
  `top-common.h` and `topics.h` published as library files; the
  duplicate entries of `compare_op`, `predicate_op`, and
  `comparison_integer<T>` (distinct entities with the same brief);
  merging "Expectations" and "Requirements"; moving the "C API" topic;
- in the API design: `detail::check_result&&` in the signatures of
  `expect()` and `require()`, with the parameter that the applications
  never pass; `expression_formatter` as an alias of
  `detail::expression_formatter`; `class suite&` in the signatures,
  until the deprecated `runner::suite()` is removed; and the inherited
  members `name()` and `totals()` of `suite` and `test_case`,
  documented through `detail::runnable_base`;
- in the consistency table: the terms "test session", "test run", and
  "test execution", and "subtest", the name of the deprecated alias and
  of real test cases of the unit tests.

The project terms to check for consistency: test case / subtest /
test; check / expectation / assertion / condition; "local type", "local
`op`", "framework type".

The maintainer leaves the deprecated code as it is, since it will be
removed: a defect in it is a finding about the page, which must state
the actual behaviour (for example, the digits accepted by the
deprecated floating-point literals), not a change of the code.

## Design Review Reports

The latest design review report may be an `API-REVIEW-<n>.md` (see
"Review Documents" in `.github/skills/project.md`); write "Same as
API-REVIEW-<n> #m" or "Overlaps API-REVIEW-<n> #m" for those.

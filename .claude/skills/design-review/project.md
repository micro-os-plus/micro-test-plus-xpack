# design-review — µTest++ Testing Framework

The rules of the `design-review` skill that are specific to this
project. This file is owned by the project, and it is never
regenerated; it extends the generated `SKILL.md` in this folder, and
takes precedence over it where they differ.

## Earlier Reports

The skill was called `api-review`, and its reports are
`maintenance/docs/API-REVIEW-<n>.md` (up to `API-REVIEW-10.md`); they
count as earlier design reviews (see "Review Documents" in
`.github/skills/project.md`). A fresh review does not read them, as it
does not read the `DESIGN-REVIEW-<n>.md` reports.

`maintenance/docs/SIZE-COMPARISON.md` is not a report but the
description of a method, and may be followed (see "Program Size");
its results file (`SIZE-COMPARISON-RESULTS.md`) may not be read.

## Scope

The default scope is:

- the umbrella header `include/micro-os-plus/micro-test-plus.h`;
- the public headers in `include/micro-os-plus/micro-test-plus/`;
- the inline and template definitions in
  `include/micro-os-plus/micro-test-plus/inlines/`;
- the definitions in `src/`.

The test programs to read for the intended use are in
`tests/sources/*/src/`.

## Newcomer Tasks

The newcomer reads the user manual in `website/docs/user/`, the
umbrella header, and the declarations of the public headers in
`include/micro-os-plus/micro-test-plus/`. The tasks, one program each:

1. a suite with a few test cases that check a small application class;
2. comparisons of integers, of floating-point values with a tolerance,
   of strings of different types, and of standard containers;
3. a check that a function throws a given exception, and one that it
   does not throw;
4. a failure message that prints an application type;
5. an application comparator or predicate, written with the
   `extension` namespace, that reports its operands as the built-in
   ones do;
6. a run configured entirely in code, with no command line, as on an
   embedded target, with the TAP reporter;
7. suites defined statically, in a separate translation unit.

For each program, also record whether the output of a failing check
tells, without the source, what was compared and why it failed.

The common mistakes, each built with GCC and Clang:

- `expect()` with a value that is neither a boolean nor a comparison;
- a comparison of unrelated types;
- an operand, and an argument streamed into a check message, of a
  type that has no `operator<<`;
- a test case body with the wrong parameters;
- an `extension` comparator whose tag misses `symbol` or `apply()`.

## Reading Order

Read the stripped files in this order, from the user's entry points
inwards:

1. `micro-test-plus.h` (what is included, and in which order);
2. `runner.h`, `runner-options.h`, `test.h`, and their inlines and
   `src/` files (the session, its configuration, the suites, and the
   test cases);
3. `check-result.h` and `src/check-result.cpp` (what `expect()` and
   `require()` return and do);
4. `function-comparators.h`, `exceptions.h`, `detail.h` (the checks and
   the comparison structures);
5. `extension.h`, `math.h` (the extension interface and the math
   helper);
6. `expression-formatter.h`, `reflection.h` (the failure messages);
7. `reporter.h`, `reporter-human.h`, `reporter-tap.h`, and their
   `src/` files (the output protocol);
8. `counters.h`, `stopwatch.h`, `utility.h` (the support classes);
9. `deprecated.h` (the deprecated definitions that are not class
   members, kept for compatibility, including the operators, the
   literals, and the type wrappers).

Use `grep` over `include/`, `src/`, and `tests/sources/` to find out
whether an entity is used at all.

## Header Check

Check the public headers (the umbrella header compiles on its own as
well, but the check is about the others) with the library enabled:

```sh
node .github/skills/design-review/scripts/check-headers.mjs \
  <scratch>/headers micro-os-plus/micro-test-plus \
  -- -DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED
```

## Probes

The probes are built as described under "Probes" in
`.github/skills/project.md`, which also gives the TAP validator and the
cross compiler.

## Restrictions

### Immediate reporting

The result of each test must be reported right when the test is executed,
not deferred until later. This also means that the result of `expect()` and
`require()` must never be named, stored, or kept in any variable, not even in
a reference (`auto&& r = t.expect (...)` compiles, but dangles after the
statement): a named result would delay the reporting until the variable goes
out of scope. The message operator and `value()` are rvalue-qualified, so a
named result cannot be used, and forcing it with `std::move()` is undefined.
This is a documented restriction of the API, not a defect: do not report the
possibility of a dangling reference (a probe must not force it with
`std::move()`), and do not propose changes to the return type of `expect()`
and `require()` that would allow the result to be kept.

### Suite order

All the suites, those added with `runner::add_suite()` and the static suites,
run in a single order, sorted by name, byte by byte, and not in the order of
the registration calls. The construction order of the static suites of
different translation units is not defined, so they must be sorted to be
deterministic, and one rule for all the suites is simpler than two. The
order is documented in the user manual, with a warning and the idiom of the
numeric name prefixes. This is a deliberate design decision, not a defect:
do not report it, and do not propose the registration order for the added
suites.

### Operands of the comparators

The comparators (`eq()`, `ne()`, `gt()`, `ge()`, `lt()`, `le()`, `approx()`,
and the logical combinators) copy their named operands into the expression,
and move the temporaries. This is a deliberate trade-off, not a defect: an
expression built in a helper function from its parameters, and returned, or
kept in a variable, must stay valid after the operands are destroyed, and a
reference would dangle without any diagnostic. The cost of the copies is
documented in the user manual, with the remedy of comparing a view
(`std::string_view`). Do not report the copies, and do not propose to store
references; an opt-out for the large operands, as a new feature, may be
suggested.

### Containers of different types

The comparators compare containers with the operators of the standard library,
so two containers are comparable only if the standard library defines the
operator for them, which for the standard containers means the same type.
The arrays are the exception, since they have no usable operator: they are
compared element by element, and a C array can be compared with a container.
This is documented in the user manual, and the comparison of operands that the
operators do not support is rejected on purpose, with a message. Do not report
it as a defect; a comparison of different containers, element by element,
would be a new feature, to be suggested as an enhancement.

### Lazy messages

A message that is a callable object (a lazy message) is called only if the
check fails, and never for a passed check, even when the passed checks are
written. It exists for the text that is valid only after a failure, such as
the error of a `std::expected` that holds a value, which is undefined
behaviour to evaluate after a success. This is documented in the user
manual. Do not report that a lazy message is not shown for a passed check.

### Hand-written special members

The copy assignment of `runner_options` is written by hand on purpose: it
copies the object with the copy constructor, and moves the copy into the
instance, because the defaulted copy assignment of the vectors of strings
uses `std::copy`, which triggers `-Waggregate-return` in the standard library
headers of GCC on some targets, and the project is built with that warning.
Do not report it as a special member that could be defaulted. In general, a
special member written by hand where `= default` would do is likely to avoid a
warning of a compiler; read the comment before reporting it, even if the review
otherwise ignores the comments, and confirm by compiling with the strict
warnings of the tests.

### Characters and strings of the wide types

The characters of the types `wchar_t`, `char8_t`, `char16_t`, and `char32_t` are
written with their prefix and quotes (`L'x'`, `u8'x'`, `u'x'`, `U'x'`), in the
reports and in the messages, since they have no plain form in the narrow text,
and without the prefix they would be mistaken for numbers; the `char` is
written as itself in a message, which is text. The strings of these types are
converted to UTF-8 and written as text, quoted in the operands and plain in the
messages, without a prefix, so that a `std::wstring` and a `std::string` with
the same text are reported alike. This is deliberate and documented in the user
manual. Do not report it as an inconsistency.

### Scoped enumerations

A scoped enumeration, including `std::byte`, is written by its underlying
value, as that type is written, for example `1` for an `int`, and
`(unsigned char)1` for a `std::byte`; the framework cannot know the names of
the enumerators. An application that wants the names defines an `operator<<`
for the enumeration. This is documented in the user manual. Do not report
that the enumerations are written as numbers, or that the text does not show
the type of the enumeration.

### The operator for the formatter of the applications

The application writes the values of its types with an `operator<<` whose first
parameter is an `mt::expression_formatter&`, as the user manual prescribes. An
operator with a generic first parameter (`template <class F> F& operator<< (F&,
const T&)`) is outside this contract: it is ambiguous with the member
templates of the formatter, for example for the types with `begin()` and
`end()`. A framework fix would be circular, since `extension::printable` is
defined by the same expression. Do not report it.

### Values of the application types in the reports

The values that the `operator<<` of an application type writes are shown in the
reports as that function writes them, in the plain mode, as in the messages,
without quotes or type suffixes, so that the members are not decorated by the
reports. A formatter constructed by the application, and written to directly,
keeps the decorations of the reports of the built-in types, so its `str()` can
differ from the reports. This is deliberate, and documented in the user manual.
Do not report the difference.

### The type of an exception in the reports

The reports of the exceptions (`throws<E>` and `nothrow` that fail, and the
exception that escapes a test case) show what was thrown as nothing, a
`std::exception` with its `what()`, or an exception of an unknown type, and not
the type of the exception: its name is available only with RTTI, in an
implementation-defined (usually mangled) form, and the library must build with
`-fno-rtti` and give the same reports in every build. Do not report that the
type is not named.

### The report of long ranges and strings

A range is written with at most 16 elements, followed by the number of
elements, and, for an equality whose first difference is beyond the elements
written, the index of the difference; the values at that index are not written,
by design, to keep the report short, and the user finds them with the index. A
string is written in full, quoted, so that an empty string, a trailing space,
and a difference in the white space are visible. Do not report that the
differing values, a position, or a window are not written.

### The command-line errors

An error in the command-line options is written twice: on `stderr`, when the
options are parsed, for a shell or a script that discards the standard output,
and on the console by the reporter (for TAP, as a `Bail out!` line), which
also writes it in the output file. On a terminal, where both streams are
shown, the error therefore appears twice. This is deliberate and documented in
the user manual. Do not report the duplicate.

### The runner object of the application

The runner is an object that the application instantiates, and the static suites
refer to it by a reference (`extern mt::runner tr;`). There is no default or
global runner of the framework: the application owns the object, can have
several runners, each with its own options, report, and totals, and the
construction and the destruction order are the application's. The boilerplate of
`main()` and the `extern` declaration are the price. This is documented in the
user manual. Do not report it; a default runner would be a new feature, to be
suggested as an enhancement.

### The `detail` types in the public signatures

The types of the `detail` namespace appear in some public signatures and
classes: the base class `runnable_base` of the test cases and the suites, the
`check_result` returned by `expect()` and `require()`, the alias
`expression_formatter`, and the concepts that constrain the functions. This is
accepted, as long as an application never has to write their names: what it
needs is documented in the user manual (the `operator<<` for the formatter, the
parameters of the bodies), and the diagnostics state what is accepted, without
naming the concepts. Report a `detail` type only if an application must name it
to write its code.

### The body of a suite

The suites run later, so each suite stores its body, with the copies of its
additional arguments, in a `std::function`; the body and the arguments must
therefore be copyable, and the compiler says so. This is deliberate and
documented in the user manual; the test cases, which run immediately, refer to
their body and do not copy it. Do not report that a move-only body is rejected,
and do not claim a saving of program size from replacing the `std::function`
without the measurement described in `maintenance/docs/SIZE-COMPARISON.md`.

### Utilities

The `utilities` namespace is intended for helper functions and types that
assist in writing and running tests, but are not directly used in the
library. Do not suggest removal or deprecations for them.

## Additional Defect Questions

The questions that found real defects in this code base, in addition
to the general ones of check 1:

- **Lifetimes**: the deferred suites and the stored check results.
- **Call order and repetition**: `initialise()` and `exit_code()`
  called twice, out of order, or not at all.
- **Nesting**: test cases inside test cases, checks before and after a
  nested test case, failures in a nested test case (do they reach the
  parent, the suite, and the totals?).
- **Shared state**: objects shared by all checks (the formatter, the
  reporter's buffer); what happens when the result of `expect()` is
  kept in a variable, or two results are alive at once? (See "Immediate
  reporting" above for what must not be reported.)
- **Concepts that match too much**: also `epsilon`, as a member that
  identifies a type.
- **Every fundamental type through every output path**: `bool`,
  `char`, `signed char`, `unsigned char`, `wchar_t`, `char8_t`,
  `char16_t`, `char32_t`, `char*`, `const char*`, `std::nullptr_t`,
  the floating-point types (including `long double`), enumerations,
  `std::byte`, and pointers, streamed into a check message, into the
  reporter, and into the expression formatter. Declared but undefined
  functions show up only at link time.
- **Special values**: `'\0'` may truncate the rest of the output; check
  the precision with which each floating-point type is printed.
- **Literals**: octal, hexadecimal, and binary prefixes, digit
  separators, decimal points in integer literals, values out of range
  for the target type, and the widths of the intermediate types on
  32-bit targets. Unary `-` and `~` on the narrow typed literals and
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
  exception types. With exceptions disabled, a failed `require()` stops
  the same scope, not the whole run.
- **Registration**: `static_suite` objects constructed before the
  runner, in other translation units (the static initialisation
  order), during `run_suites()`, or after it; none of them may be
  silently ignored.
- **Copy and move**: the counters are value types, and must be
  copyable.
- **Include order and configuration**: the macros of
  `micro-os-plus/project-config.h` and
  `micro-os-plus/micro-test-plus-defines.h`.
- **Stack usage**: also the recursion in the literal parsing.
- **Output**: what the user reads, in every combination of the
  reporter (TAP, human), the verbosity (`--silent`, `--quiet`, normal,
  `--verbose`), the output file (with and without `--output-file`),
  the colours, `--list-tests`, and the filters:
  - the TAP output, on the console and in the file, is valid TAP 14
    (the validator in "Probes" of `.github/skills/project.md`); the
    plan `1..N` matches the test points at every verbosity; the YAML
    blocks are valid YAML;
  - names and messages that contain `#`, `\`, a newline, or a colon
    are escaped, so that they cannot become a directive, a comment, or
    a YAML key (the validator does not detect a misplaced `#`);
  - silent mode prints nothing; quiet mode still shows which checks
    failed; the console and the output file agree, and neither
    depends on the verbosity of the other;
  - configuration and command-line errors reach the output file, not
    only the console;
  - the wording of the markers matches what happened (for example
    "aborted" only when the run was aborted).

## Additional Checks

- **Usability**: failure reports that do not show what was compared.
- **Structure — Symmetry**: the forms of the same concept in this
  library are `suite` and `static_suite`, `expect()` and `require()`,
  the function comparators and the operators, and the `to_i` wrappers
  and the `_i` literals. Every type accepted as an operand of a check
  is also accepted after `<<` in its message.
- **Structure — Extensibility**: the reporters and the formatter look
  extensible; the parts meant for users are in the `extension`
  namespace.
- **Naming**: the names of the flags of check 4 that were found here: a
  query that runs the tests, a `flush()` that does not flush the
  buffer, a `reporter` that is a check result; several names for one
  concept (test case, subtest, test), several spellings for one entity
  (`_i`, `to_i`, the `_i` literal). A header guard, for example:
  `MICRO_OS_PLUS_MICRO_TEST_PLUS_INLINES_TEST_INLINES_H_`.
- **Simplicity**: the duplications found here: sorting, the formatting
  of times, the file names of paths, the `run()` bodies, and the stream
  operators.
- **Embedded targets**: the heap allocations per test case and per
  check; the work done for output that is never printed (formatting
  every passing check).

## Program Size

Claims about the program size are measured with the method described
in `maintenance/docs/SIZE-COMPARISON.md` (the build folders of the
platform must exist first). Write the suggested change as a patch in
the scratchpad, keep the working folder there too, and quote the
difference in the finding:

```sh
python3 -I maintenance/scripts/size-comparison/compare-sizes.py \
  --baseline HEAD --current HEAD \
  --current-patch <scratch>/change.patch --work <scratch>/size
```

## Report

The title of the report was `# C++ API review` in the `API-REVIEW-<n>.md`
reports; the new reports use `# Design review`.

## Acting on an Item

Where the item is a defect, its probe becomes a regression test in the
`unit` program (`tests/sources/unit-*/`); see "Tests" in
`.github/skills/project.md`.

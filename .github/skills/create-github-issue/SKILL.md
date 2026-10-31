---
name: create-github-issue
description: 'Draft and open GitHub issues for bugs and enhancements in the µTest++ Testing Framework repository (micro-os-plus/micro-test-plus-xpack), following the project''s title, body, and label conventions. Use when the user asks to "add an issue", "open an issue", "file a bug", "create an enhancement", or to turn code-review findings into issues.'
argument-hint: 'Short description of the problem or improvement, or a list of findings; optionally the kind (bug or enhancement)'
---

# Create Issue — µTest++ Testing Framework

## When to Use

- The user asks to add, open, create or file a GitHub issue for a bug or an
  enhancement.
- The user asks to turn the findings of a review (code, API, Doxygen,
  website) into issues, one issue per finding.

Issues are opened in `micro-os-plus/micro-test-plus-xpack` with the `gh`
CLI, run from the repository root.

## Procedure

1. **Establish the facts.** Read the code the issue refers to, at the
   current `HEAD`, and record the exact files, line numbers, and
   function or member names. Do not cite line numbers from memory or
   from an earlier version of the file. If the working tree has
   uncommitted changes in the cited files, cite the lines as they are
   in the committed version, or say so in the body.
2. **Reproduce, if it is a bug.** When it is practical, confirm the
   behaviour with a probe, a test run, or the output of the sample
   programs, and keep the evidence (the command, the configuration
   name, and the relevant output). State clearly what was measured and
   what was only estimated or inferred.
3. **Check for duplicates.** Search the open and closed issues:

   ```sh
   gh issue list --state all --limit 30 --search "<keywords>"
   ```

   If an issue already covers the problem, report it to the user
   instead of creating a new one, and offer to add a comment to it.
   If a related issue exists, reference it in the body (see below).
4. **Choose the labels** (see "Labels").
5. **Draft the title and the body** (see "Title" and "Body"), and write
   the body to a file in the scratchpad folder.
6. **Show the draft to the user** — the title, the labels, and the full
   body — and wait for explicit approval. Opening an issue is a public
   action; never create one without approval. For several issues,
   present all drafts together and let the user approve, edit, or drop
   each of them.
7. **Create the issue:**

   ```sh
   gh issue create \
     --title "<title>" \
     --label <label> [--label <label>] \
     --assignee @me \
     --body-file <scratchpad>/issue-body.md
   ```

   Always assign the issue to the current GitHub user (`--assignee
   @me`, the account `gh` is authenticated as). Do not set milestones
   or projects unless the user asks.
8. **Report** the issue number and URL. When several issues are created,
   list them as a table (number, title, labels, assignee).

## Labels

Use only the repository labels below, unless the user asks otherwise:

- `bug` — the code behaves incorrectly: wrong or invalid output (for
  example TAP that is not valid YAML), crashes, faults, undefined
  behaviour, compilation failures with a supported toolchain, or
  behaviour that contradicts the documentation.
- `enhancement` — the code works, but can be improved: refactorings,
  duplicated code, inconsistent naming or macros, performance, memory
  footprint, missing features, API additions, and documentation
  wording.
- Both `bug` and `enhancement` — when a defect can only be fixed by a
  new feature or a new public API (for example a missing extension
  point whose absence leads to a failure).

The `documentation` label is not used; documentation issues are labelled
`enhancement` (or `bug` if the documentation is wrong). If the kind is
uncertain, say so and ask the user.

## Title

- State the **current problem**, not the fix: the title describes what
  is wrong or missing, in the present tense, as a full sentence.
  - Good: `The TAP reporter formats most of its lines twice`
  - Good: `` `initialise (argc, argv)` handles a second call twice ``
  - Bad: `Refactor the TAP reporter output` (describes the fix).
  - Bad: `Fix stack overflow` (imperative, vague).
- Usually start with `The ...`, or with the code identifier in
  backticks.
- Capitalise the first word; do not end with a period.
- Keep it under 70 characters.
- Do not prefix it with the kind (`Bug:`, `[enhancement]`) or an issue
  number; the labels carry the kind.

## Body

Write the body as plain Markdown prose, in British English, formal, with
no contractions, the Oxford comma, and the lines wrapped at 72
characters. Use backticks for file names, identifiers, macros, options,
configuration names, and commit hashes. Do not use headings or
templates (no "Steps to reproduce" / "Expected" / "Actual" sections);
the information is given as connected sentences, in this order:

1. **Location.** Open with the files, line numbers, and functions,
   followed by a colon, for example:
   `` `src/runner.cpp` lines 163 to 166: `` or
   `` `tests/sources/suite/src/suite.cpp`, `nested_test_case()`: ``.
   Paths are relative to the repository root, except for headers
   under `include/micro-os-plus/micro-test-plus/`, which may be given
   by their name (`detail.h`, `inlines/detail-inlines.h`).
2. **Observation.** What the code does, precisely: the configuration
   and the command, the observed output or fault, and the cause, if
   known. For a bug, include the evidence from the reproduction and
   mark estimates as estimates. Mention the related commits by their
   short hash and, where relevant, whether a commit is or is not the
   cause.
3. **Scope.** If relevant, which other platforms, toolchains, or files
   are, or may be, affected, and why a passing case does not prove the
   absence of the problem.
4. **Proposed change.** In the imperative (`Remove it.`, `Add to
   `reporter` a variadic helper ...`, `Measure ..., and then either
   ...`). When several solutions are possible, list them and state the
   trade-offs; do not pretend that one is obviously right. Mention any
   test to add, and any generated file whose template must be changed
   instead (for example the build-helper templates of the platforms,
   followed by `npm run generate-tests-commons` in `tests/`).
5. **References**, if any, as a final short paragraph, for example
   `Found while fixing #134.` or `Decide together with #118.`

Keep the body as short as the facts allow; a simple finding may be a
single paragraph of two lines.

## Approval

The text of the issue must be reviewed and approved before it is added to the repository.

## Example

Title: `The quiet summary omits the count of the skipped test cases`

Labels: `bug`

```markdown
`src/reporter-human.cpp`, `end_session()`: with `--quiet`, the final
summary prints the passed and failed checks, but not the skipped test
cases, which the normal verbosity reports; a session in which all the
test cases are skipped is therefore reported as passed with no checks.
Print the skipped count in the quiet summary as well, when it is not
zero, and update `tests/expected/txt/unit-test-quiet.txt`.

Found while fixing #NNN.
```

(The example is hypothetical; it illustrates the format only.)

## After the Issue Is Fixed

The fix is committed with the `github-commit` skill, which also adds
the closing comment to the issue (see its "Issue Comment" section); the
issue is not closed by hand.

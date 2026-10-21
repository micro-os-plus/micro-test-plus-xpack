---
name: github-commit
description: 'Prepare and create a git commit in the µTest++ Testing Framework repository, following the project''s commit message conventions, and add the closing comment to the GitHub issue it fixes. Use when the user asks to "commit", "make a commit", "commit the fix", or to write a commit message for the current changes.'
argument-hint: 'Optional: the GitHub issue number (#N), and whether the commit completes the issue'
---

# Commit — µTest++ Testing Framework

## When to Use

- The user asks to commit the current changes, or a subset of them.
- The user asks for a commit message for the staged or unstaged
  changes.

This skill is the reference for the commit messages and the issue
updates; `.github/copilot-instructions.md` ("Commits") only points to
it and requires the user approval before each commit.

## Procedure

1. **Inspect the working tree.** Run `git status` and `git diff` (and
   `git diff --cached` if anything is staged). Identify which changes
   belong to this commit; the working tree often contains unrelated
   changes and untracked files (for example notes in
   `maintenance/docs/`), which must not be included.
2. **Identify the issue.** Each commit refers to a GitHub issue. If the
   user did not give the number and it cannot be determined with
   certainty from the conversation, ask for it; do not guess. If no
   issue exists, offer to create one with the `create-github-issue`
   skill. Ask whether this commit completes the issue (and gets
   `Fixes #N`), or is one of several commits for it, unless that is
   already clear.
3. **Check that the tests were run** as required by the "Testing"
   section of `.github/copilot-instructions.md` (`test-selected` after
   major changes, `test` after minor ones, and the platform-specific
   actions for embedded changes). If they were not run after the last
   change, say so and run them, or ask the user, before committing.
   Report failures; do not commit over them without explicit approval.
4. **Check the generated files.** If `xcdl-package.jsonc` or the
   build-helper templates changed, the generated files
   (`CMakeLists.txt`, `meson.build`, the platform files in `tests/`)
   must be regenerated and included, not edited by hand. If the
   reference outputs in `tests/assets/` are affected, they must be
   updated in the same commit.
5. **Draft the message** (see "Message Format") and write it to a file
   in the scratchpad folder.
6. **Show the user** the list of files to be committed and the full
   message, and wait for explicit approval. Never commit without it.
7. **Stage and commit** only the approved files, by name (no
   `git add -A` or `git add .`), and commit with the message file:

   ```sh
   git add <file> ...
   git commit -F <scratchpad>/commit-message.txt
   ```

   Do not amend, rebase, or skip the hooks (`--no-verify`) unless the
   user asks. If a hook fails, fix the cause and create the commit
   again. Do not push unless the user asks.
8. **Report** the commit hash and subject (`git log -1 --oneline`).
9. **Update the issue**, if the commit has `Fixes #N` (see "Issue
   Comment").
10. **Update the review documents** that list the issue or the finding
    it came from (see "Review Documents").

Do not start the next fix while this one is uncommitted; commit first.

## Message Format

### Subject

- `#N: ` followed by a summary in the imperative mood, starting with a
  capital letter: `#152: Write the report lines to both streams once`.
- At most 50 characters, including the `#N: ` prefix.
- No period at the end.
- Describe the change, not the problem (the issue title describes the
  problem): `Restore the deprecated subtest`, not
  `The subtest alias is missing`.

### Body

Separated from the subject by a blank line, wrapped at 72 characters,
in British English, formal, with no contractions and with the Oxford
comma. Identifiers, files, and options are written plainly, without
backticks. Explain what and why, not how; usually three short
paragraphs:

1. **The previous state**, in the past tense: what the code did, and
   why it was a problem.

   > In v5.0.1, the test case bodies received a subtest&, and the
   > applications named it in the functions passed to test(). The
   > class was renamed test_case, without an alias, so this code no
   > longer compiled.

2. **The change**, in the imperative: what was added, removed, or
   changed, and the decisions that are not obvious from the diff
   (what was deliberately left unchanged, and why).

   > Add back subtest, as an alias of test_case, marked
   > [[deprecated]].

3. **Tests and documentation**, in the imperative: the tests added or
   changed, the reference outputs, and the documentation updated.

   > Test it in deprecated.cpp, update the compatibility notices, and
   > update the unit reference outputs.

A trivial change may have a single paragraph.

Mention the related issues and pull requests, if any, by number, where
they are relevant in the text: an earlier decision or change that this
commit builds on or reverts (`as #61 chose`, `removed by #109`), or a
follow-up left to another issue (`see #51`). Refer to an item of a
review document by the document name and the item number, so that it
is not mistaken for an issue: `(API-REVIEW.md #43)`.

### Trailers

After the body, separated by a blank line:

- `Fixes #N` — only on the commit that completes the issue; omit it
  from the intermediate commits of an issue fixed in several commits.
- The attribution trailer required by the agent's environment, if any
  (for example `Co-Authored-By: ...`), as the last line.

### Example

```text
#155: Accept explicit bool conversions in checks

The checks accepted only the framework expressions and the values
implicitly convertible to bool, so std::optional, std::unique_ptr,
and the application types with an explicit operator bool had to be
converted, for example with has_value() or != nullptr.

Define extension::checkable with the contextual conversion to bool,
applied to a const value; the scoped enumerations remain rejected.

Test the concept in static-asserts.cpp and the checks in
miscellaneous.cpp, update the unit reference outputs, the
compatibility notices, and the User's Guide.

Fixes #155
```

## Issue Comment

After a commit with `Fixes #N`, add a comment to the issue:

```sh
gh issue comment <N> --body-file <scratchpad>/issue-comment.md
```

- Start with `Fixed in <short hash>`, followed by a brief explanation
  of the changes, written for the reader of the issue: what was
  changed, what was deliberately not changed and why, and how it was
  verified (measurements, compared outputs).
- Write the commit hashes bare, without backticks (`Fixed in 123f0c76`),
  so that GitHub links them to the commits; in backticks they are not
  linked.
- If the proposal of the issue was not followed, or the finding was
  withdrawn, say so and explain why.
- Write the paragraphs unwrapped (one line each), in Markdown, with
  backticks for identifiers (but not for the commit hashes); short
  lists are acceptable.
- End with a separate line `Fixed on YYYY-MM-DD.`, with the date of the
  commit (`git log -1 --format=%cs`).
- Do not close the issue; it is closed when the commit reaches the
  default branch (`xpack`).

Show the comment to the user before posting it, unless the user has
already approved posting it together with the commit.

## Review Documents

The findings that lead to issues are often recorded in review, change,
or comparison documents, mainly in `maintenance/docs/` (for example
`API-REVIEW.md`, `API-COMPATIBILITY.md`, `BOOST-UT-CHANGES.md`), and
in other files named `*-review*`, `*-changes*`, `*-compatibility*`, or
similar. After the commit, search them for the issue and the finding:

```sh
grep -n -E '\(#N\)|#N[^0-9]|<words from the issue title>' \
  maintenance/docs/*.md
```

In some documents, a `#K` at the start of an item is the number of the
finding within the document, not a GitHub issue number; match the
GitHub number where it is used as such (in parentheses, or after
"issue" or "fixed in"), and confirm the item by its content.

If an item refers to the issue or to the same finding, **ask the user**
whether to update it, and show the proposed text. Then update the item
in the format already used by that document, and always mention both
the GitHub issue number and the short commit hash, for example:

- `` Fixed in `a8733dc2` (#96): <what was done>. `` (the format of
  `API-REVIEW.md`, under the item, with `(fixed)` added after its
  tags, such as `[internal] **[confirmed]**`);
- `` Status: fixed in #155, commit `2933857e`, on 2026-10-21. <what was
  done>. `` (the format of `BOOST-UT-CHANGES.md`, after the verdict).

Summarise what was done, and state where the fix differs from the
recommendation of the document. For an intermediate commit of an issue
fixed in several commits, ask whether to record it as partial (for
example `Partly fixed in ... (#N): ...`). For a withdrawn finding, write
`Withdrawn (#N): <reason>.` instead.

Do not change the header date or commit of the document, which record
when the review was made. These documents are often untracked or have
unrelated changes; do not stage or commit them unless the user asks.

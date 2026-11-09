---
name: rewrite-bash-to-javascript
description: 'Rewrite a bash/shell script (.sh) in this project as an ES module Node.js script (.mjs), following the conventions already used by jsonc-format.mjs and xcdl-export.mjs. Use when the user asks to "rewrite", "convert", "port", or "translate" a bash script into JavaScript/Node.js, or to replace a shell script with a .mjs equivalent.'
argument-hint: 'Path to the .sh script to convert, e.g. maintenance/scripts/cmake-format.sh'
---

# Rewrite Bash Scripts to JavaScript — µTest++ Testing Framework

## When to Use

- The user asks to rewrite, convert, port, or translate a
  `maintenance/scripts/*.sh` file into JavaScript/Node.js.

For a new script that has no `.sh` original, use
[create-javascript-mjs](../create-javascript-mjs/SKILL.md) instead.

## Step 1 — General Conventions

Follow all the conventions of
[create-javascript-mjs](../create-javascript-mjs/SKILL.md) (module
system, header, arguments, style, external tools, file discovery,
dependencies, wiring). The steps below add only what is specific to
converting a bash script.

## Step 2 — Bash-Specific Replacements

- **Header comment**: keep the copyright and MIT permission notice of the
  `.sh` version, adapted to block-comment style.
- **Script location**: replace `$0` / `dirname "$0"` with
  `fileURLToPath(import.meta.url)` and `path.dirname(...)`.
- **File discovery**: replace `find` invocations with `globSync`, keeping
  the ignore patterns of the original.
- **Error handling**: replace `set -o errexit` / `set -o nounset` with
  explicit checks that `console.error(...)` a clear message and
  `process.exit(1)`.
- **Output**: replace `echo` with `console.log` / `console.error`.
- **Running external tools**: replace the bash `run_verbose` helper (which
  echoes the command and runs it) with `execFileSync` or `spawnSync` and
  `stdio: 'inherit'`.
- **Wiring**: update the corresponding `xpack.actions` entry in
  `package.json` to invoke the script with `node`, e.g.
  `"cmake-format": "node maintenance/scripts/cmake-format.mjs"`. Remove
  the now-unused `.sh` file only if the user confirms it is no longer
  needed elsewhere.

## Step 3 — Verify

- Run the new `.mjs` script directly and compare its effect against the
  original `.sh` script on the same input.
- Run the corresponding `xpm run <action>` command to confirm the
  `package.json` wiring end-to-end.

/*
 * This file is part of the µOS++ project (https://micro-os-plus.github.io/).
 * Copyright (c) 2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

// ----------------------------------------------------------------------------

// Validate that TAP files are well-formed TAP 14.
//
// Usage: node validate-tap.mjs [--lenient] <file.tap>...
//
// The files are parsed with the node-tap parser (`tap-parser`) in strict
// mode; each subtest parser is followed. A file is rejected for a parser
// error (wrong plan, duplicate test point, and so on), for a non-TAP line
// (including an invalid YAML diagnostics block), for a missing plan, or
// for a version other than 14. The `not ok` results are not errors, so
// files with intentional failures are accepted.
//
// With `--lenient`, used for the console captures, which also contain the
// lines printed by the test programs and the test case lists of the local
// runners, the files are parsed in the non-strict mode, and the non-TAP
// lines are accepted, except those that look like TAP (a test point, a
// plan, a bail out, or the delimiter of a diagnostics block), since a
// malformed TAP line is also reported as a non-TAP line; the parser
// errors, the missing plans, and the versions are checked as in the
// strict mode. A repeated version line is accepted, since a local runner
// that writes to the console starts its own session there.
//
// The diagnostics fields are not standardised by TAP 14, so their names
// are not checked.
//
// The exit code is 0 if all files are valid, 1 otherwise.

import { readFileSync } from 'node:fs'
import { Parser } from 'tap-parser'

// ----------------------------------------------------------------------------

// The non-TAP lines that look like TAP, rejected also in the lenient mode.
const tap_like_line =
  /^\s*((not )?ok(\b|\d)|1\.\.|Bail out!|---\s*$|\.\.\.\s*$)/

const validate = (file, lenient) => {
  const errors = []

  const watch = (parser, path) => {
    parser.on('extra', (line) => {
      if (!lenient || tap_like_line.test(line)) {
        errors.push(`${path}: non-TAP line: ${JSON.stringify(line)}`)
      }
    })
    parser.on('child', (child) => watch(child, `${path} > ${child.name}`))
    parser.on('complete', (results) => {
      for (const failure of results.failures) {
        if (failure.tapError) {
          errors.push(`${path}: ${failure.tapError}`)
        }
      }
      if (!results.plan || results.plan.start === undefined) {
        errors.push(`${path}: no plan`)
      }
    })
  }

  const parser = new Parser({ strict: !lenient })
  parser.on('version', (version) => {
    if (version !== 14) {
      errors.push(`${file}: TAP version ${version}, expected 14`)
    }
  })
  watch(parser, file)
  parser.end(readFileSync(file, 'utf8'))

  return errors
}

// ----------------------------------------------------------------------------

const args = process.argv.slice(2)
const lenient = args[0] === '--lenient'
const files = lenient ? args.slice(1) : args
if (files.length === 0) {
  console.error('Usage: node validate-tap.mjs [--lenient] <file.tap>...')
  process.exit(1)
}

let failed = false
for (const file of files) {
  const errors = validate(file, lenient)
  if (errors.length) {
    console.error(errors.join('\n'))
    failed = true
  } else {
    console.log(`${file}: valid TAP${lenient ? ' (lenient)' : ''}`)
  }
}
process.exit(failed ? 1 : 0)

// ----------------------------------------------------------------------------

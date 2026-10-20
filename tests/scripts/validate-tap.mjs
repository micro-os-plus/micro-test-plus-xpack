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
// Usage: node validate-tap.mjs <file.tap>...
//
// The files are parsed with the node-tap parser (`tap-parser`) in strict
// mode; each subtest parser is followed. A file is rejected for a parser
// error (wrong plan, duplicate test point, and so on), for a non-TAP line
// (including an invalid YAML diagnostics block), for a missing plan, or
// for a version other than 14. The `not ok` results are not errors, so
// files with intentional failures are accepted.
//
// The diagnostics fields are not standardised by TAP 14, so their names
// are not checked.
//
// The exit code is 0 if all files are valid, 1 otherwise.

import { readFileSync } from 'node:fs'
import { Parser } from 'tap-parser'

// ----------------------------------------------------------------------------

const validate = (file) => {
  const errors = []

  const watch = (parser, path) => {
    parser.on('extra', (line) =>
      errors.push(`${path}: non-TAP line: ${JSON.stringify(line)}`))
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

  const parser = new Parser({ strict: true })
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

const files = process.argv.slice(2)
if (files.length === 0) {
  console.error('Usage: node validate-tap.mjs <file.tap>...')
  process.exit(1)
}

let failed = false
for (const file of files) {
  const errors = validate(file)
  if (errors.length) {
    console.error(errors.join('\n'))
    failed = true
  } else {
    console.log(`${file}: valid TAP`)
  }
}
process.exit(failed ? 1 : 0)

// ----------------------------------------------------------------------------

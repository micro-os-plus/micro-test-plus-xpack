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

// Check that every public header compiles on its own, i.e. that it
// includes everything it uses, instead of relying on the order in which
// the umbrella header includes the others.
//
// Usage:
//   node check-headers.mjs <scratch-folder>
//
// Run it from the repository root. The compiler is taken from the CXX
// environment variable (default `c++`). Each header in
// `include/micro-os-plus/micro-test-plus/` is included alone in a small
// translation unit, compiled with `-fsyntax-only`, with the library
// enabled. The exit code is 1 if any header fails.

import { spawnSync } from 'child_process'
import fs from 'fs'
import path from 'path'

// ----------------------------------------------------------------------------

const scratchFolderPath = process.argv[2]
if (!scratchFolderPath) {
  console.error('Usage: node check-headers.mjs <scratch-folder>')
  process.exit(2)
}

const compiler = process.env.CXX || 'c++'
const includeFolderPath = 'include'
const headersFolderPath = path.join(
  includeFolderPath,
  'micro-os-plus',
  'micro-test-plus'
)

fs.mkdirSync(scratchFolderPath, { recursive: true })
const unitFilePath = path.join(scratchFolderPath, 'check-header.cpp')

// ----------------------------------------------------------------------------

const headers = fs
  .readdirSync(headersFolderPath)
  .filter((name) => name.endsWith('.h'))
  .sort()

let failedCount = 0

for (const header of headers) {
  const includePath = `micro-os-plus/micro-test-plus/${header}`
  fs.writeFileSync(
    unitFilePath,
    `#include "${includePath}"\n\nint\nmain (void)\n{\n  return 0;\n}\n`
  )

  const result = spawnSync(
    compiler,
    [
      '-std=c++20',
      '-fsyntax-only',
      '-DMICRO_OS_PLUS_MICRO_TEST_PLUS_ENABLED',
      `-I${includeFolderPath}`,
      unitFilePath,
    ],
    { encoding: 'utf8' }
  )

  const errorsCount = (result.stderr.match(/error:/g) || []).length
  if (result.status === 0) {
    console.log(`ok      ${includePath}`)
  } else {
    failedCount++
    console.log(`FAILED  ${includePath} (${errorsCount} errors)`)
    const firstError = result.stderr
      .split('\n')
      .find((line) => line.includes('error:'))
    if (firstError) {
      console.log(`        ${firstError.trim()}`)
    }
  }
}

console.log(`${headers.length} headers, ${failedCount} failed`)
process.exit(failedCount > 0 ? 1 : 0)

// ----------------------------------------------------------------------------

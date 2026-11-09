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

// Trigger the `test-all.yml` workflow (manual `workflow_dispatch`) on GitHub,
// using the GitHub CLI (`gh`), which must be installed and authenticated.
//
// Usage: node trigger-workflow-test-all.mjs [<branch>]
//
// Without arguments, the workflow runs on the current Git branch.

import { spawnSync } from 'child_process'

const workflowFile = 'test-all.yml'
const repository = 'micro-os-plus/micro-test-plus-xpack'

if (process.argv.length > 3) {
  console.error('Error: too many arguments.')
  console.error('Usage: node trigger-workflow-test-all.mjs [<branch>]')
  process.exit(1)
}

let branch = process.argv[2]
if (!branch) {
  const result = spawnSync('git', ['rev-parse', '--abbrev-ref', 'HEAD'], {
    encoding: 'utf8'
  })
  if (result.status !== 0) {
    console.error('Error: cannot determine the current branch.')
    process.exit(1)
  }
  branch = result.stdout.trim()
}

console.log(`Triggering ${workflowFile} on branch '${branch}'...`)

const result = spawnSync('gh', [
  'workflow', 'run', workflowFile,
  '--repo', repository,
  '--ref', branch
], { stdio: 'inherit' })

if (result.error) {
  console.error(`Error: cannot run 'gh' (${result.error.message}).`)
  process.exit(1)
}

if (result.status !== 0) {
  process.exit(result.status ?? 1)
}

console.log('Done. See https://github.com/' + repository +
  '/actions/workflows/' + workflowFile)

// ----------------------------------------------------------------------------

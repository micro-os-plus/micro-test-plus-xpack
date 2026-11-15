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

// Extract the sizes of the footprint programs from the QEMU release builds
// and write them, with the conditions of the measurement, to a JSON file.
//
// Usage (from the repository root):
//   node .github/skills/footprint-benchmarks/scripts/extract-footprint-sizes.mjs \
//     tests tests/sources/benchmarks/footprint-sizes.json
//
// For each platform, the programs are read from
// `<tests>/build/<platform>-cmake-gcc-release/footprint-<name>.elf`, with
// the `size` and `nm` tools of the toolchain installed in the build folder.
// A program that was not built is recorded as `null`.
//
// Besides the `text`, `data`, and `bss` sizes, the file records, for each
// platform, the total size of the µTest++ symbols of the µTest++ program
// (`microTestPlusSymbols`), which separates the code of the framework from
// that of the C and C++ libraries.

import { execFileSync } from 'child_process'
import fs from 'fs'
import path from 'path'

// ----------------------------------------------------------------------------

const [testsFolderPath, outputFilePath] = process.argv.slice(2)
if (!testsFolderPath || !outputFilePath) {
  console.error(
    'Usage: node extract-footprint-sizes.mjs <tests-folder> <output-json>'
  )
  process.exit(2)
}

// The platforms, in the order of the columns of the website tables, with
// the prefix of their toolchain.
const platforms = [
  ['qemu-cortex-m0', 'arm-none-eabi'],
  ['qemu-cortex-m3', 'arm-none-eabi'],
  ['qemu-cortex-m4f', 'arm-none-eabi'],
  ['qemu-cortex-m7f', 'arm-none-eabi'],
  ['qemu-cortex-m33', 'arm-none-eabi'],
  ['qemu-aarch32-a15', 'arm-none-eabi'],
  ['qemu-aarch64-a72', 'aarch64-none-elf'],
  ['qemu-riscv-rv32imac', 'riscv-none-elf'],
  ['qemu-riscv-rv64imafdc', 'riscv-none-elf'],
]

// The programs, as named in `tests/sources/benchmarks/footprint`.
const programs = [
  'baseline',
  'printf',
  'micro-test-plus',
  'unity',
  'cpputest',
  'doctest',
  'catch2',
  'boost-ut',
  'boost-test',
  'googletest',
  'snitch',
]

// ----------------------------------------------------------------------------

function run(tool, args) {
  return execFileSync(tool, args, { encoding: 'utf8' })
}

// The sizes of the sections, as reported by `size --format=berkeley`.
function readSizes(sizeTool, elfFilePath) {
  const output = run(sizeTool, ['--format=berkeley', elfFilePath])
  const fields = output.trim().split('\n')[1].trim().split(/\s+/)
  return {
    text: Number(fields[0]),
    data: Number(fields[1]),
    bss: Number(fields[2]),
  }
}

// The total size of the code and read-only symbols of µTest++ (the same
// selection that gave the "about 24 KiB" quoted on the website).
function readMicroTestPlusSymbols(nmTool, elfFilePath) {
  const output = run(nmTool, ['-S', '-C', '--radix=d', elfFilePath])
  let total = 0
  for (const line of output.split('\n')) {
    // <address> <size> <type> <name>
    const match = line.match(/^\S+ (\d+) ([tTrRwW]) (.*)$/)
    if (match && match[3].includes('micro_test_plus')) {
      total += Number(match[1])
    }
  }
  return total
}

// ----------------------------------------------------------------------------

const sizes = {}
const microTestPlusSymbols = {}
const toolchains = {}

for (const [platform, prefix] of platforms) {
  const buildFolderPath = path.join(
    testsFolderPath,
    'build',
    `${platform}-cmake-gcc-release`
  )
  const binFolderPath = path.join(buildFolderPath, 'xpacks', '.bin')
  if (!fs.existsSync(binFolderPath)) {
    console.error(`${buildFolderPath}: not built`)
    process.exit(1)
  }

  const sizeTool = path.join(binFolderPath, `${prefix}-size`)
  const nmTool = path.join(binFolderPath, `${prefix}-nm`)

  if (!toolchains[`${prefix}-gcc`]) {
    toolchains[`${prefix}-gcc`] = run(
      path.join(binFolderPath, `${prefix}-gcc`),
      ['-dumpfullversion']
    ).trim()
  }

  sizes[platform] = {}
  for (const program of programs) {
    const elfFilePath = path.join(buildFolderPath, `footprint-${program}.elf`)
    sizes[platform][program] = fs.existsSync(elfFilePath)
      ? readSizes(sizeTool, elfFilePath)
      : null
  }

  const microTestPlusElfFilePath = path.join(
    buildFolderPath,
    'footprint-micro-test-plus.elf'
  )
  microTestPlusSymbols[platform] = fs.existsSync(microTestPlusElfFilePath)
    ? readMicroTestPlusSymbols(nmTool, microTestPlusElfFilePath)
    : null
}

// The commit and the modified files are those at the time of the
// extraction; run it right after the builds, before committing anything.
const commit = run('git', ['rev-parse', '--short=8', 'HEAD']).trim()
// Untracked files (such as the fetched frameworks) do not matter. The
// lines are not trimmed, since the status columns may start with a space.
const modified = run('git', ['status', '--porcelain', '--untracked-files=no'])
  .split('\n')
  .filter((line) => line.length > 0)

const result = {
  description:
    'The text, data, and bss sizes, in bytes, of the footprint programs in tests/sources/benchmarks/footprint, as reported by size --format=berkeley; null when the program was not built.',
  date: new Date().toISOString().slice(0, 10),
  microTestPlusCommit: commit,
  // The temporary change of the footprint flag is expected here.
  modifiedFiles: modified.map((line) => line.slice(3)),
  frameworks:
    'the release tags listed in tests/sources/benchmarks/frameworks.jsonc',
  build:
    'the <platform>-cmake-gcc-release configurations (-Os), with XPACK_ENABLE_FOOTPRINT_BENCHMARKS_TEST set to true',
  toolchains,
  microTestPlusSymbols,
  sizes,
}

fs.writeFileSync(outputFilePath, JSON.stringify(result, null, 2) + '\n')
console.log(`${outputFilePath} written`)

// ----------------------------------------------------------------------------

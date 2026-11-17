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

// Generate the footprint tables of the comparison page from the JSON file
// written by `extract-footprint-sizes.mjs`, and print the figures that the
// website quotes in the text.
//
// Usage (from the repository root):
//   node .github/skills/footprint-benchmarks/scripts/generate-footprint-tables.mjs \
//     tests/sources/benchmarks/footprint-sizes.json \
//     [--update website/docs/getting-started/comparison/index.mdx]
//
// Without `--update`, the tables are printed. With it, the content between
// the markers `{/* BEGIN generated <name> */}` and
// `{/* END generated <name> */}` of the page is replaced, for the names
// `footprint-flash`, `footprint-ram`, and `footprint-details`.
//
// The sizes are in KiB (1024 bytes), with one decimal below 10 KiB. The
// flash is `text` plus `data`, the RAM is `data` plus `bss`. Each cell is
// the absolute value followed, in parentheses, by the increase over the
// empty program (`baseline`) of the same platform; the absolute values of
// the µTest++ row are bold. The `footprint-details` block is a single
// collapsed `<details>` element with three tables, of the `text`, `data`,
// and `bss` sizes, in bytes, with the platforms as columns.

import fs from 'fs'

// ----------------------------------------------------------------------------

const args = process.argv.slice(2)
const jsonFilePath = args[0]
const updateIndex = args.indexOf('--update')
const pageFilePath = updateIndex >= 0 ? args[updateIndex + 1] : undefined
if (!jsonFilePath || (updateIndex >= 0 && !pageFilePath)) {
  console.error(
    'Usage: node generate-footprint-tables.mjs <sizes-json> [--update <mdx>]'
  )
  process.exit(2)
}

const measurement = JSON.parse(fs.readFileSync(jsonFilePath, 'utf8'))
const sizes = measurement.sizes

// The platforms, in the order of the columns, with their titles.
const columns = [
  ['qemu-cortex-m0', 'Cortex-M0'],
  ['qemu-cortex-m3', 'Cortex-M3'],
  ['qemu-cortex-m4f', 'Cortex-M4F'],
  ['qemu-cortex-m7f', 'Cortex-M7F'],
  ['qemu-cortex-m33', 'Cortex-M33'],
  ['qemu-aarch32-a15', 'Cortex-A15 (AArch32)'],
  ['qemu-aarch64-a72', 'Cortex-A72 (AArch64)'],
  ['qemu-riscv-rv32imac', 'RV32IMAC'],
  ['qemu-riscv-rv64imafdc', 'RV64IMAFDC'],
]

// The rows, in the order of the frameworks on the page.
const rows = [
  ['printf', 'A `printf()` call'],
  ['micro-test-plus', '**µTest++**'],
  ['boost-ut', 'Boost UT'],
  ['snitch', 'snitch'],
  ['googletest', 'GoogleTest'],
  ['catch2', 'Catch2'],
  ['doctest', 'doctest'],
  ['boost-test', 'Boost.Test'],
  ['unity', 'Unity'],
  ['cpputest', 'CppUTest'],
]

const cortexM = columns.slice(0, 5).map(([platform]) => platform)

// ----------------------------------------------------------------------------

const flash = (s) => s.text + s.data
const ram = (s) => s.data + s.bss

function kib(bytes) {
  const value = bytes / 1024
  return Math.abs(value) < 10 ? value.toFixed(1) : Math.round(value).toString()
}

function increase(bytes) {
  const text = kib(bytes)
  return text === '0.0' ? '+0' : `+${text}`
}

function summaryTable(measure) {
  const lines = []
  lines.push('| Program | ' + columns.map((c) => c[1]).join(' | ') + ' |')
  lines.push('| --- |' + columns.map(() => ' ---: |').join(''))
  lines.push(
    '| Empty program | ' +
      columns.map(([p]) => kib(measure(sizes[p].baseline))).join(' | ') +
      ' |'
  )
  for (const [program, label] of rows) {
    const cells = columns.map(([p]) => {
      const s = sizes[p][program]
      if (!s) {
        return '—'
      }
      const absolute = kib(measure(s))
      const shown = program === 'micro-test-plus' ? `**${absolute}**` : absolute
      return `${shown} (${increase(measure(s) - measure(sizes[p].baseline))})`
    })
    lines.push(`| ${label} | ${cells.join(' | ')} |`)
  }
  return lines.join('\n')
}

function detailsBlock() {
  const labels = Object.fromEntries([['baseline', 'Empty program'], ...rows])
  const programs = ['baseline', ...rows.map((r) => r[0])]
  const fields = [
    ['text', 'The code and the constants (`text`):'],
    ['data', 'The initial values of the variables (`data`):'],
    ['bss', 'The variables initialised to zero (`bss`):'],
  ]
  const lines = []
  lines.push('<details>')
  lines.push(
    '<summary>The <code>text</code>, <code>data</code>, and ' +
      '<code>bss</code> sizes, in bytes</summary>'
  )
  for (const [field, caption] of fields) {
    lines.push('')
    lines.push(caption)
    lines.push('')
    lines.push('| Program | ' + columns.map((c) => c[1]).join(' | ') + ' |')
    lines.push('| --- |' + columns.map(() => ' ---: |').join(''))
    for (const program of programs) {
      const cells = columns.map(([platform]) => {
        const s = sizes[platform][program]
        return s ? `${s[field]}` : '—'
      })
      lines.push(`| ${labels[program]} | ${cells.join(' | ')} |`)
    }
  }
  lines.push('')
  lines.push('</details>')
  return lines.join('\n')
}

// ----------------------------------------------------------------------------

const generated = {
  'footprint-flash': summaryTable(flash),
  'footprint-ram': summaryTable(ram),
  'footprint-details': detailsBlock(),
}

if (pageFilePath) {
  let page = fs.readFileSync(pageFilePath, 'utf8')
  for (const [name, content] of Object.entries(generated)) {
    const begin = `{/* BEGIN generated ${name} */}`
    const end = `{/* END generated ${name} */}`
    const beginIndex = page.indexOf(begin)
    const endIndex = page.indexOf(end)
    if (beginIndex < 0 || endIndex < beginIndex) {
      console.error(`${pageFilePath}: markers of '${name}' not found`)
      process.exit(1)
    }
    page =
      page.slice(0, beginIndex + begin.length) +
      `\n\n${content}\n\n` +
      page.slice(endIndex)
  }
  fs.writeFileSync(pageFilePath, page)
  console.log(`${pageFilePath} updated`)
} else {
  for (const [name, content] of Object.entries(generated)) {
    console.log(`\n${name}:\n\n${content}`)
  }
}

// ----------------------------------------------------------------------------
// The figures quoted in the text of the website, to be updated by hand.

const added = (platform, program) => {
  const s = sizes[platform][program]
  return s ? flash(s) - flash(sizes[platform].baseline) : null
}

console.log('\nFigures quoted in the text (flash, KiB):\n')

console.log('Increase over the empty program, Cortex-M3 (matrix row):')
for (const [program, label] of rows) {
  console.log(`  ${label}: ${kib(added('qemu-cortex-m3', program))}`)
}

console.log('\nIncrease over the empty program, Cortex-M0 to M33 (range):')
for (const [program, label] of rows) {
  const values = cortexM.map((p) => added(p, program)).filter((v) => v !== null)
  console.log(
    `  ${label}: ${kib(Math.min(...values))} to ${kib(Math.max(...values))}`
  )
}

const m4f = sizes['qemu-cortex-m4f']
console.log('\nAbsolute flash on Cortex-M4F (landing page example):')
console.log(`  Empty program: ${kib(flash(m4f.baseline))}`)
for (const [program, label] of rows) {
  if (m4f[program]) {
    console.log(`  ${label}: ${kib(flash(m4f[program]))}`)
  }
}

console.log('\nµTest++ symbols (code and read-only data):')
for (const [platform, title] of columns) {
  const bytes = measurement.microTestPlusSymbols?.[platform]
  if (bytes) {
    console.log(`  ${title}: ${kib(bytes)}`)
  }
}

const m7f = sizes['qemu-cortex-m7f']
console.log('\n`size` lines on Cortex-M7F (embedded targets page):')
for (const program of ['baseline', 'micro-test-plus', 'boost-ut']) {
  const s = m7f[program]
  const dec = s.text + s.data + s.bss
  console.log(
    `  ${String(s.text).padStart(7)} ${String(s.data).padStart(7)} ` +
      `${String(s.bss).padStart(7)} ${String(dec).padStart(7)} ` +
      `${dec.toString(16).padStart(7)} footprint-${program}.elf`
  )
}

// ----------------------------------------------------------------------------

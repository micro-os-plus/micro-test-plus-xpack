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

// Compile one or more MDX pages with the MDX compiler of the website, as a
// quick check of the syntax, without a full Docusaurus build.
//
// Usage (from the repository root):
//   node .github/skills/footprint-benchmarks/scripts/check-mdx.mjs \
//     website website/docs/developer/comparison/index.mdx [page...]
//
// The front matter is removed, and so is the `<!-- truncate -->` marker of
// the blog posts, which Docusaurus accepts but plain MDX rejects. The check
// does not resolve the imports, the links, or the anchors; only the full
// build (`npm run build` in `website`) does.

import { createRequire } from 'module'
import fs from 'fs'
import path from 'path'

// ----------------------------------------------------------------------------

const [websiteFolderPath, ...pageFilePaths] = process.argv.slice(2)
if (!websiteFolderPath || pageFilePaths.length === 0) {
  console.error('Usage: node check-mdx.mjs <website-folder> <page.mdx>...')
  process.exit(2)
}

// Load the packages from the `node_modules` of the website.
const require = createRequire(path.resolve(websiteFolderPath, 'package.json'))
const { compile } = await import(require.resolve('@mdx-js/mdx'))
const remarkGfm = (await import(require.resolve('remark-gfm'))).default

let failed = false
for (const pageFilePath of pageFilePaths) {
  const source = fs
    .readFileSync(pageFilePath, 'utf8')
    .replace(/^---[\s\S]*?\n---\n/, '')
    .replace(/^<!-- truncate -->$/m, '')
  try {
    await compile(source, { remarkPlugins: [remarkGfm] })
    console.log(`${pageFilePath}: ok`)
  } catch (error) {
    failed = true
    console.error(`${pageFilePath}: ${error.message}`)
  }
}

process.exit(failed ? 1 : 0)

// ----------------------------------------------------------------------------

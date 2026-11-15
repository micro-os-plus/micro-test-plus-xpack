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

// Fetches the testing frameworks compared by the benchmark programs, as
// listed in `sources/benchmarks/frameworks.jsonc`, into the
// `benchmarks-frameworks` folder, shared by all the platforms.
//
// The git entries are cloned at their release tags, and the clones are
// checked against the expected commits; the archive entries are downloaded,
// checked against their SHA-256 checksums, and only the given folder is
// extracted. The frameworks already at the listed versions are skipped, so
// running the script again fetches only what changed.
//
// For snitch, the `snitch/snitch_config.hpp` header is also generated, by
// the snitch CMake configuration with the default options, into
// `snitch-config`.
//
// Usage: node scripts/fetch-benchmarks-frameworks.mjs [--force] [name ...]

// ----------------------------------------------------------------------------

import { spawnSync } from 'child_process'
import { createHash } from 'crypto'
import {
  copyFileSync,
  existsSync,
  mkdirSync,
  readFileSync,
  renameSync,
  rmSync,
  writeFileSync,
} from 'fs'
import path from 'path'
import { fileURLToPath } from 'url'

import JSON5 from 'json5'

// ----------------------------------------------------------------------------

const scriptFolderPath = path.dirname(fileURLToPath(import.meta.url))
const testsFolderPath = path.dirname(scriptFolderPath)

const configFilePath = path.join(
  testsFolderPath,
  'sources',
  'benchmarks',
  'frameworks.jsonc'
)
const frameworksFolderPath = path.join(testsFolderPath, 'benchmarks-frameworks')

// The file that records the version of an extracted archive.
const versionMarkerFileName = '.version'

// The snitch configuration header, generated after cloning snitch.
const snitchConfigFilePath = path.join(
  frameworksFolderPath,
  'snitch-config',
  'snitch',
  'snitch_config.hpp'
)

// ----------------------------------------------------------------------------

const usage = () => {
  console.error(
    'Usage: node scripts/fetch-benchmarks-frameworks.mjs [--force] [name ...]'
  )
}

// Runs an external program, and returns its result; the output is shown
// only when `quiet` is false. Exits if the program cannot be started.
const run = (command, args, { cwd, quiet = false } = {}) => {
  const result = spawnSync(command, args, {
    cwd,
    stdio: quiet ? 'pipe' : 'inherit',
    encoding: 'utf8',
  })
  if (result.error) {
    console.error(`Error: cannot start '${command}': ${result.error.message}`)
    process.exit(1)
  }
  return result
}

// Returns the path of a tool installed by xpm in the tests folder, or the
// bare name, to be searched in the PATH.
const toolPath = (name) => {
  const xpmToolPath = path.join(testsFolderPath, 'xpacks', '.bin', name)
  return existsSync(xpmToolPath) ? xpmToolPath : name
}

// Returns the commit checked out in a git folder, or undefined.
const currentCommit = (folderPath) => {
  if (!existsSync(path.join(folderPath, '.git'))) {
    return undefined
  }
  const result = run('git', ['-C', folderPath, 'rev-parse', 'HEAD'], {
    quiet: true,
  })
  return result.status === 0 ? result.stdout.trim() : undefined
}

// Returns the SHA-256 checksum of a file, in hexadecimal.
const sha256 = (filePath) =>
  createHash('sha256').update(readFileSync(filePath)).digest('hex')

// ----------------------------------------------------------------------------

// Clones a git entry at its tag, unless it is already at the expected
// commit; returns the status shown in the summary.
const fetchGit = (name, entry, force) => {
  const folderPath = path.join(frameworksFolderPath, name)

  if (!force && currentCommit(folderPath) === entry.commit) {
    return 'current'
  }

  rmSync(folderPath, { recursive: true, force: true })

  console.log(`\nCloning ${entry.git} (${entry.tag})...`)
  const result = run('git', [
    '-c',
    'advice.detachedHead=false',
    'clone',
    '--quiet',
    '--depth',
    '1',
    '--branch',
    entry.tag,
    entry.git,
    folderPath,
  ])
  if (result.status !== 0) {
    throw new Error(`git clone failed with status ${result.status}`)
  }

  const commit = currentCommit(folderPath)
  if (commit !== entry.commit) {
    throw new Error(
      `tag ${entry.tag} resolves to ${commit}, not to the expected ` +
        `${entry.commit}; was the tag moved?`
    )
  }

  return 'fetched'
}

// Downloads an archive entry, checks its checksum, and extracts the given
// folder, unless the version marker shows it is already extracted; returns
// the status shown in the summary.
const fetchArchive = (name, entry, force) => {
  const folderPath = path.join(frameworksFolderPath, name)
  const markerFilePath = path.join(folderPath, versionMarkerFileName)

  if (
    !force &&
    existsSync(markerFilePath) &&
    readFileSync(markerFilePath, 'utf8').trim() === entry.version
  ) {
    return 'current'
  }

  rmSync(folderPath, { recursive: true, force: true })

  const temporaryFolderPath = path.join(frameworksFolderPath, `${name}.tmp`)
  rmSync(temporaryFolderPath, { recursive: true, force: true })
  mkdirSync(temporaryFolderPath, { recursive: true })

  const archiveFilePath = path.join(
    temporaryFolderPath,
    path.basename(new URL(entry.archive).pathname)
  )

  console.log(`\nDownloading ${entry.archive}...`)
  let result = run('curl', [
    '--fail',
    '--location',
    '--silent',
    '--show-error',
    '--output',
    archiveFilePath,
    entry.archive,
  ])
  if (result.status !== 0) {
    throw new Error(`curl failed with status ${result.status}`)
  }

  const checksum = sha256(archiveFilePath)
  if (checksum !== entry.sha256) {
    throw new Error(
      `the checksum of ${path.basename(archiveFilePath)} is ${checksum}, ` +
        `not the expected ${entry.sha256}`
    )
  }

  console.log(`Extracting ${entry.extract}...`)
  result = run('tar', [
    '-xf',
    archiveFilePath,
    '-C',
    temporaryFolderPath,
    entry.extract,
  ])
  if (result.status !== 0) {
    throw new Error(`tar failed with status ${result.status}`)
  }

  // Keep the last component of the extracted folder (for example `boost`),
  // so that the headers are included as `<boost/...>`.
  mkdirSync(folderPath, { recursive: true })
  renameSync(
    path.join(temporaryFolderPath, entry.extract),
    path.join(folderPath, path.basename(entry.extract))
  )
  writeFileSync(markerFilePath, `${entry.version}\n`)
  rmSync(temporaryFolderPath, { recursive: true, force: true })

  return 'fetched'
}

// Generates `snitch/snitch_config.hpp`, with the snitch CMake configuration
// and the default options, into the `snitch-config` folder.
const generateSnitchConfig = () => {
  const sourceFolderPath = path.join(frameworksFolderPath, 'snitch')
  const buildFolderPath = path.join(frameworksFolderPath, 'snitch-build')

  rmSync(buildFolderPath, { recursive: true, force: true })
  rmSync(path.join(frameworksFolderPath, 'snitch-config'), {
    recursive: true,
    force: true,
  })

  console.log('\nGenerating the snitch configuration header...')

  const args = ['-S', sourceFolderPath, '-B', buildFolderPath]
  const ninjaPath = toolPath('ninja')
  if (ninjaPath !== 'ninja') {
    args.push('-G', 'Ninja', `-DCMAKE_MAKE_PROGRAM=${ninjaPath}`)
  }

  const result = run(toolPath('cmake'), args, { quiet: true })
  if (result.status !== 0) {
    console.error(result.stdout)
    console.error(result.stderr)
    throw new Error(`cmake failed with status ${result.status}`)
  }

  const generatedFilePath = path.join(
    buildFolderPath,
    'snitch',
    'snitch_config.hpp'
  )
  if (!existsSync(generatedFilePath)) {
    throw new Error(`${generatedFilePath} was not generated`)
  }

  mkdirSync(path.dirname(snitchConfigFilePath), { recursive: true })
  copyFileSync(generatedFilePath, snitchConfigFilePath)
  rmSync(buildFolderPath, { recursive: true, force: true })
}

// ----------------------------------------------------------------------------

const args = process.argv.slice(2)
const force = args.includes('--force')
const requestedNames = args.filter((arg) => arg !== '--force')

const unknownOptions = requestedNames.filter((arg) => arg.startsWith('-'))
if (unknownOptions.length > 0) {
  console.error(`Error: unknown option '${unknownOptions[0]}'`)
  usage()
  process.exit(1)
}

const frameworks = JSON5.parse(readFileSync(configFilePath, 'utf8'))

const unknownNames = requestedNames.filter((name) => !(name in frameworks))
if (unknownNames.length > 0) {
  console.error(
    `Error: unknown framework '${unknownNames[0]}'; ` +
      `known: ${Object.keys(frameworks).join(', ')}`
  )
  usage()
  process.exit(1)
}

const names =
  requestedNames.length > 0 ? requestedNames : Object.keys(frameworks)

mkdirSync(frameworksFolderPath, { recursive: true })

const summary = []
for (const name of names) {
  const entry = frameworks[name]
  try {
    let status
    if (entry.git) {
      status = fetchGit(name, entry, force)
      // Generate the header after each new clone, or if it is missing.
      if (
        name === 'snitch' &&
        (status === 'fetched' || !existsSync(snitchConfigFilePath))
      ) {
        generateSnitchConfig()
      }
    } else if (entry.archive) {
      status = fetchArchive(name, entry, force)
    } else {
      throw new Error('the entry has neither `git` nor `archive`')
    }
    summary.push({ name, version: entry.tag ?? entry.version, status })
  } catch (error) {
    console.error(`Error: ${name}: ${error.message}`)
    summary.push({
      name,
      version: entry.tag ?? entry.version,
      status: 'FAILED',
    })
  }
}

console.log(`\nFrameworks in ${frameworksFolderPath}:`)
for (const { name, version, status } of summary) {
  console.log(`  ${name.padEnd(12)} ${version.padEnd(10)} ${status}`)
}

process.exit(summary.some(({ status }) => status === 'FAILED') ? 1 : 0)

// ----------------------------------------------------------------------------

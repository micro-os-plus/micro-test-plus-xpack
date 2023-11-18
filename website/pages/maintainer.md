# Maintainer Info

@tableofcontents

[![license](https://img.shields.io/github/license/micro-os-plus/micro-test-plus-xpack)](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/ci.yml/badge.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/ci.yml)
[![GitHub issues](https://img.shields.io/github/issues/micro-os-plus/micro-test-plus-xpack.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/issues)
[![GitHub pulls](https://img.shields.io/github/issues-pr/micro-os-plus/micro-test-plus-xpack.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/pulls)
[![Website](https://img.shields.io/website?url=https%3A%2F%2Fmicro-os-plus.github.io%2Fmicro-test-plus-xpack%2F)](https://micro-os-plus.github.io/micro-test-plus-xpack/)

## Project repository

The project uses Git and is hosted on GitHub as
<https://github.com/micro-os-plus/micro-test-plus-xpack.git>.

To clone the stable branch (`xpack`), run the following commands in a
terminal (on Windows use the _Git Bash_ console):

```sh
rm -rf ~/Work/micro-os-plus/micro-test-plus-xpack.git && \
mkdir -p ~/Work/micro-os-plus && \
git clone \
  https://github.com/micro-os-plus/micro-test-plus-xpack.git \
  ~/Work/micro-os-plus/micro-test-plus-xpack.git
```

For development purposes, clone the `xpack-develop` branch:

```sh
rm -rf ~/Work/micro-os-plus/micro-test-plus-xpack.git && \
mkdir -p ~/Work/micro-os-plus && \
git clone \
  --branch xpack-develop \
  https://github.com/micro-os-plus/micro-test-plus-xpack.git \
  ~/Work/micro-os-plus/micro-test-plus-xpack.git
```

To link it to the central xPack store:

```sh
xpm link -C ~/Work/micro-os-plus/micro-test-plus-xpack.git
```

## Get helper sources

The project has a dependency to a common **helper**; clone the
`xpack-develop` branch and link it to the central xPacks store:

```sh
rm -rf ~/Work/micro-os-plus/build-helper-xpack.git && \
mkdir -p ~/Work/micro-os-plus && \
git clone \
  --branch xpack-develop \
  https://github.com/micro-os-plus/build-helper-xpack.git \
  ~/Work/micro-os-plus/build-helper-xpack.git
```

Or, if the repo was already cloned:

```sh
git -C ~/Work/micro-os-plus/build-helper-xpack.git pull
xpm link -C ~/Work/micro-os-plus/build-helper-xpack.git
```

## Prerequisites

A recent [xpm](https://xpack.github.io/xpm/), which is a portable
[Node.js](https://nodejs.org/) command line application.

To run the native tests, a C++ development environment is required.
On macOS install Command Line Tools, on Ubuntu `build-essential`.

## Code formatting

Code formatting is done using `clang-format --style=file`, either manually
from a script, or automatically from Visual Studio Code, or the Eclipse
CppStyle plug-in.

@note
Always reformat the source files that were changed before committing
them to the repository.

## How to update the website

The project [website](https://micro-os-plus.github.io/micro-test-plus-xpack/)
is automatically generated and published by the
`publish-github-pages.yml` workflow on Git push. The GitHub Action that
runs the workflow is
<https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/publish-github-pages.yml>.

@todo When ready, restrict the workflow to run only on pushes to the
`xpack` branch.

For development, there are two xPack actions that can be used
to automate the workflow:

- `doxygen` - to build the site with Doxygen locally
- `browser` - to start the default browser with the `website/html` folder

## How to make new releases

### Release schedule

There are no fixed releases.

### Check Git

In the `micro-os-plus/micro-test-plus-xpack` Git repo:

- switch to the `xpack-develop` branch
- if needed, merge the `xpack` branch

No need to add a tag here, it'll be added when the release is created.

### Increase the version

Determine the upstream version (like `3.1.1`) and eventually update the
`package.json` file; the format is `3.1.1-pre`.

### Fix possible open issues

Check GitHub issues and pull requests:

- <https://github.com/micro-os-plus/micro-test-plus-xpack/issues>

and fix them; assign them to a milestone (like `3.1.1`, without **v**).

### Update 'website/pages/maintainer.md'

Update the `maintainer.md` file to reflect the changes
related to the new version.

### Update 'website/config.doxyfile'

Update the `PROJECT_NUMBER` variable to the new version.

### Update 'CHANGELOG.md'

- open the `CHANGELOG.md` file
- check if all previous fixed issues are in
- add a new entry like _* v3.1.1_
- commit with a message like _prepare v3.1.1_

### Push changes

- reformat the source files that were changed
- commit and push

### Manual tests

To run the tests manually on the local development machine:

```sh
xpm run deep-clean -C ~/Work/micro-os-plus/micro-test-plus-xpack.git
xpm run install-all -C ~/Work/micro-os-plus/micro-test-plus-xpack.git
xpm run test-all -C ~/Work/micro-os-plus/micro-test-plus-xpack.git
```

### Publish on the 'npmjs.com' server

- select the `xpack-develop` branch
- commit all changes
- `npm pack` and check the content of the archive, which should list
  only `package.json`, `README.md`, `LICENSE`, `CHANGELOG.md`,
  the sources and CMake/meson files;
  possibly adjust `.npmignore`
- `npm version patch`, `npm version minor`, `npm version major`
- push the `xpack-develop` branch to GitHub
- the `postversion` npm script should also update tags via `git push origin --tags`
- wait for the CI job to complete
  (<https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/ci.yml>)

### Test on all platforms

In addition, it is possible to manually trigger a **test-all** job, that
runs all available builds, on all supported platforms, including Linux Arm
and macOS Apple Silicon.

For this:

- start the `~/actions-runners/micro-os-plus/run.sh &` runner on
  `xbbma`, `xbbla64` and `xbbla32`
- ensure that the `xpack-develop` branch is pushed
- run the `trigger-workflow-test-all` action
- wait for the **test-all** job to complete
  (<https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/test-all.yml>)

### Publish

- `npm publish --tag next` (use `npm publish --access public` when
  publishing for the first time)

The version is visible at:

- <https://www.npmjs.com/package/@micro-os-plus/micro-test-plus?activeTab=versions>

### Update the repo

When the package is considered stable:

- with a Git client (VS Code is fine)
- merge `xpack-develop` into `xpack`
- push to GitHub
- select `xpack-develop`

### Tag the npm package as 'latest'

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @micro-os-plus/micro-test-plus`
- `npm dist-tag add @micro-os-plus/micro-test-plus@3.1.1 latest`
- `npm dist-tag ls @micro-os-plus/micro-test-plus`

## Share on Twitter

- in a separate browser windows, open [TweetDeck](https://tweetdeck.twitter.com/)
- using the `@micro_os_plus` account
- paste the release name like **µOS++ µTest++ v3.1.1 released**
- paste the link to the npmjs release
- click the **Tweet** button

## TODO

@todo Possibly split the content into separate classes.

@todo Make a new clang15 release to generate runnable binaries to silence meson.

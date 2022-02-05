[![license](https://img.shields.io/github/license/micro-os-plus/micro-test-plus-xpack)](https://github.com/micro-os-plus/micro-test-plus-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/micro-test-plus-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/actions?query=workflow%3A%22CI+on+Push%22)
[![GitHub issues](https://img.shields.io/github/issues/micro-os-plus/micro-test-plus-xpack.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/issues/)
[![GitHub pulls](https://img.shields.io/github/issues-pr/micro-os-plus/micro-test-plus-xpack.svg)](https://github.com/micro-os-plus/micro-test-plus-xpack/pulls)

# Maintainer info

## Prerequisites

A recent [xpm](https://xpack.github.io/xpm/), which is a portable
[Node.js](https://nodejs.org/) command line application.

It is recommended to update to the latest version with:

```sh
npm install --global xpm@latest
```

## Project repository

The project is hosted on GitHub as:

- <https://github.com/micro-os-plus/micro-test-plus-xpack.git>

To clone the stable branch (`xpack`), run the following commands in a
terminal (on Windows use the _Git Bash_ console):

```sh
rm -rf ~/Work/micro-test-plus-xpack.git && \
mkdir -p ~/Work && \
git clone \
  https://github.com/micro-os-plus/micro-test-plus-xpack.git \
  ~/Work/micro-test-plus-xpack.git
```

For development purposes, clone the `xpack-develop` branch:

```sh
rm -rf ~/Work/micro-test-plus-xpack.git && \
mkdir -p ~/Work && \
git clone \
  --branch xpack-develop \
  https://github.com/micro-os-plus/micro-test-plus-xpack.git \
  ~/Work/micro-test-plus-xpack.git
```

## Development setup

### Remove previous packages

In this early development phase, package versions are not properly set, and
if you have older versions of the xPack installed, sometimes updates may fail
to get the latest version. To fix this remove all global packages by using

```sh
cd ~/Work/micro-test-plus-xpack.git
xpm run rm-global-deps
```

and repeat the steps from `xpm install`.

### Install dependencies

With a clean slate, install dependencies:

```sh
cd ~/Work/micro-test-plus-xpack.git
xpm run install-all
```

## Run tests

The project includes unit tests.

To perform the tests, run the usual xpm sequence:

```sh
cd ~/Work/micro-test-plus-xpack.git
xpm run test-all
```

### Clone writable dependencies

The above procedure will allow to develop the project itself, but the
dependencies will be read-only; to be able to contribute to them,
also clone the `xpack-develop` branches of all µOS++ source xPacks
into a folder of your choice and link them to the central xPacks
folder by running `xpack link` in each folder.

To automate this, there is a helper script to clone these repos into
`${HOME}/Work/micro-os-plus-xpack-repos`:

```sh
curl -L https://raw.githubusercontent.com/micro-os-plus/helper-scripts/main/clone-and-link-all-git-repos.sh | bash -
```

Note: If you prefer a different location, start the script with a first
argument as the destination folder path.

After cloning all Git repos, link this project to the development packages,
by running the `link-deps` actions:

```sh
cd micro-test-plus-xpack.git
xpm run link-deps
```

## Continuous Integration

The CI tests are performed on GitHub Actions, as the
[CI on Push](https://github.com/micro-os-plus/micro-test-plus-xpack/actions?query=workflow%3A%22CI+on+Push%22)
workflow.

## Code formatting

Code formatting is done using `clang-format --style=file`, either manually
from a script, or automatically from Visual Studio Code, or the Eclipse
CppStyle plug-in.

## How to publish

### Prepare a new blog post

In the `micro-os-plus/web-jekyll` GitHub repo:

- select the `develop` branch
- add a new file to `_posts/micro-test-plus/releases`
- name the file like `2020-12-19-micro-test-plus-v1-1-1-released.md`
- name the post like: **µOS++ µTest++ v2.2.1 released**
- update the `date:` field with the current date
- update the GitHub Actions URLs using the actual test pages

If any, refer to closed
[issues](https://github.com/micro-os-plus/micro-test-plus-xpack/issues/)
as:

- **[Issue:\[#1\]\(...\)]**.

### Publish on the npmjs.com server

- select the `xpack-develop` branch
- commit all changes
- update versions in `README.md` and `README-MAINTAINER.md`
- update `CHANGELOG.md`
- commit with a message like _prepare v2.2.1_
- `npm pack` and check the content of the archive, which should list
  only `package.json`, `README.md`, `LICENSE`, `CHANGELOG.md`,
  the sources and CMake/meson files;
  possibly adjust `.npmignore`
- `npm version patch`, `npm version minor`, `npm version major`
- push the `xpack-develop` branch to GitHub
- the `postversion` npm script should also update tags via `git push origin --tags`
- wait for the CI job to complete
  (<https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/CI.yml>)
- `npm publish --tag next` (use `npm publish --access public` when
  publishing for the first time)

The version is visible at:

- <https://www.npmjs.com/package/@micro-os-plus/micro-test-plus?activeTab=versions>

## Update the repo

When the package is considered stable:

- with Sourcetree
- merge `xpack-develop` into `xpack`
- push to GitHub
- select `xpack-develop`

## Tag the npm package as `latest`

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @micro-os-plus/micro-test-plus`
- `npm dist-tag add @micro-os-plus/micro-test-plus@2.2.1 latest`
- `npm dist-tag ls @@micro-os-plus/micro-test-plus`

## Announce to the community

Post an announcement to the forum.

## Share on Twitter

- in a separate browser windows, open [TweetDeck](https://tweetdeck.twitter.com/)
- using the `@micro_os_plus` account
- paste the release name like **µOS++ µTest++ v2.2.1 released**
- paste the link to the Web page release
- click the **Tweet** button

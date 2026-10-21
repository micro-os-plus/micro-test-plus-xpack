#!/usr/bin/env python3
#
# This file is part of the µOS++ project (https://micro-os-plus.github.io/).
# Copyright (c) 2026 Liviu Ionescu. All rights reserved.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can be
# obtained from https://opensource.org/licenses/mit.
#

"""
Compare the sizes of the same test programs (those of v5.0.1 by default),
built with two versions of the library (v5.0.1 and HEAD by default).

The test sources are built twice, against the headers and sources of each
library, with the compile and link commands, and the platform objects, of
the current build folders of the platform, so that the differences come
only from the library. The test sources and each library may be patched
first. The programs are then run under QEMU, and the sizes, the totals
reported by the programs, and the number of source location records in
`.data` are printed as Markdown tables.

See `maintenance/docs/SIZE-COMPARISON.md` for the details.

Usage (from the repository root):

    python3 -I maintenance/scripts/size-comparison/compare-sizes.py

    python3 -I maintenance/scripts/size-comparison/compare-sizes.py \\
        --baseline HEAD --current HEAD \\
        --current-patch local-source-location.patch

The build folders of the platform must exist and be built, for example
with `xpm run build --config qemu-cortex-m33-cmake-gcc-debug -C tests`.
"""

import argparse
import glob
import json
import os
import shlex
import shutil
import subprocess
import sys

SCRIPT_FOLDER = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(SCRIPT_FOLDER, '..', '..', '..'))
TESTS = os.path.join(REPO, 'tests')
PROGRAMS = ['empty', 'minimal', 'sample', 'suite', 'unit']


def run(args, cwd, check=True):
    """Run a command; on failure, show its error output and stop."""
    result = subprocess.run(args, cwd=cwd, capture_output=True, text=True)
    if check and result.returncode != 0:
        sys.stderr.write(' '.join(args)[:400] + '\n')
        sys.stderr.write(result.stdout[-2000:] + result.stderr[-4000:] + '\n')
        raise SystemExit(1)
    return result


def export(revision, paths, destination):
    """Export some paths of a git revision into a folder."""
    if os.path.exists(destination):
        shutil.rmtree(destination)
    os.makedirs(destination)
    archive = subprocess.run(['git', '-C', REPO, 'archive', revision] + paths,
                             capture_output=True, check=True)
    subprocess.run(['tar', '-x', '-C', destination], input=archive.stdout,
                   check=True)


def compile_command(template, library_root, source, output, program, tests):
    """
    Adapt a compile command of the build folder: use the headers of the
    given library and the include folder of the baseline test program, and
    remove the dependency files and `-Werror` (the deprecated names used by
    the baseline sources warn; the generated code is not affected).
    """
    result = []
    skip = 0
    for argument in shlex.split(template):
        if skip:
            skip -= 1
            continue
        if argument in ('-MT', '-MF'):
            skip = 1
            continue
        if argument in ('-MD', '-Werror') or argument.startswith('-Werror='):
            continue
        if argument == '-I' + os.path.join(REPO, 'include'):
            argument = '-I' + os.path.join(library_root, 'include')
        elif program and argument == '-I' + os.path.join(
                TESTS, 'sources', program, 'include'):
            argument = '-I' + os.path.join(tests, program, 'include')
        result.append(argument)
    result[result.index('-o') + 1] = output
    result[result.index('-c') + 1] = source
    return result


def qemu_command(build, program):
    """Return the QEMU command of the default test of a program."""
    with open(os.path.join(build, 'CTestTestfile.cmake')) as file:
        for line in file:
            prefix = 'add_test([=[' + program + '-test]=] '
            if line.startswith(prefix):
                command = shlex.split(line[len(prefix):].rstrip().rstrip(')'))
                local = os.path.join(build, 'xpacks', '.bin', command[0])
                if os.path.exists(local):
                    command[0] = local
                return command
    raise SystemExit('no test ' + program + '-test in ' + build)


def apply_patch(path, folder):
    """Apply a patch with paths relative to the repository root."""
    if not path:
        return
    if not os.path.isabs(path) and not os.path.exists(path):
        path = os.path.join(SCRIPT_FOLDER, path)
    with open(path) as patch:
        subprocess.run(['patch', '-s', '-p1', '-d', folder], stdin=patch,
                       check=True)


def label(revision, patch):
    """The name of a library in the tables: the revision, and the patch."""
    if not patch:
        return revision
    return revision + ' + ' + os.path.splitext(os.path.basename(patch))[0]


def main():
    parser = argparse.ArgumentParser(description=__doc__.split('\n\n')[0])
    parser.add_argument('--tests', default='v5.0.1',
                        help='the revision of the test programs '
                        '(default: v5.0.1)')
    parser.add_argument('--tests-patch', default='v5.0.1-tests.patch',
                        help='the patch applied to the test sources '
                        '(default: v5.0.1-tests.patch; "" for none)')
    parser.add_argument('--baseline', default='v5.0.1',
                        help='the revision of the baseline library '
                        '(default: v5.0.1)')
    parser.add_argument('--baseline-patch', default='',
                        help='a patch applied to the baseline library '
                        '(default: none)')
    parser.add_argument('--current', default='HEAD',
                        help='the revision of the current library '
                        '(default: HEAD)')
    parser.add_argument('--current-patch', default='',
                        help='a patch applied to the current library '
                        '(default: none)')
    parser.add_argument('--platform', default='qemu-cortex-m33-cmake-gcc',
                        help='the build folder prefix '
                        '(default: qemu-cortex-m33-cmake-gcc)')
    parser.add_argument('--work', default=os.path.join(
        TESTS, 'build', 'size-comparison'),
        help='the working folder (default: tests/build/size-comparison)')
    options = parser.parse_args()

    work = os.path.abspath(options.work)

    # The test programs, from their own revision, possibly patched.
    tests_root = os.path.join(work, 'tests')
    export(options.tests, ['tests/sources'], tests_root)
    apply_patch(options.tests_patch, tests_root)
    tests = os.path.join(tests_root, 'tests', 'sources')

    # The two libraries, each possibly patched; the same revision may be
    # used for both, with different patches. The file names are compiled
    # into the programs, so the two folders have names of the same length.
    roles = ('baseline', 'current')
    libraries = {}
    labels = {}
    for index, role in enumerate(roles, start=1):
        revision = getattr(options, role)
        patch = getattr(options, role + '_patch')
        root = os.path.join(work, 'library-' + str(index))
        export(revision, ['include', 'src'], root)
        apply_patch(patch, root)
        libraries[role] = root
        labels[role] = label(revision, patch)

    configs = ('debug', 'release')
    results = {}
    for config in configs:
        build = os.path.join(TESTS, 'build', options.platform + '-' + config)
        bin_folder = os.path.join(build, 'xpacks', '.bin')
        tool_prefix = os.path.join(bin_folder, 'arm-none-eabi-')
        with open(os.path.join(build, 'compile_commands.json')) as file:
            commands = json.load(file)
        library_template = next(
            e for e in commands
            if 'static-library.dir/src/test.cpp' in e['command'])

        for variant, library_root in libraries.items():
            out = os.path.join(work, config, variant)
            if os.path.exists(out):
                shutil.rmtree(out)
            os.makedirs(os.path.join(out, 'library'))

            objects = []
            for source in sorted(glob.glob(os.path.join(library_root, 'src',
                                                        '*.cpp'))):
                obj = os.path.join(out, 'library',
                                   os.path.basename(source) + '.o')
                run(compile_command(library_template['command'], library_root,
                                    source, obj, None, tests),
                    library_template['directory'])
                objects.append(obj)
            archive = os.path.join(out, 'libmicro-test-plus.a')
            run([tool_prefix + 'ar', 'rcs', archive] + objects, build)

            for program in PROGRAMS:
                prefix = ('CMakeFiles/' + program + '-test.dir/sources/' +
                          program + '/src/')
                template = next(e for e in commands if prefix in e['command'])
                test_objects = []
                for source in sorted(glob.glob(os.path.join(tests, program,
                                                            'src', '*.cpp'))):
                    obj = os.path.join(out, program + '-' +
                                       os.path.basename(source) + '.o')
                    run(compile_command(template['command'], library_root,
                                        source, obj, program, tests),
                        template['directory'])
                    test_objects.append(obj)

                # The command is `: && <link> && cd ... && size ... && ...`;
                # only the link is kept.
                line = run([os.path.join(TESTS, 'xpacks', '.bin', 'ninja'),
                            '-C', build, '-t', 'commands',
                            program + '-test.elf'],
                           build).stdout.strip().splitlines()[-1]
                link = []
                inserted = False
                for argument in shlex.split(line.split(' && ')[1]):
                    if argument.startswith(prefix):
                        if not inserted:
                            link += test_objects
                            inserted = True
                        continue
                    if argument == 'top-bin/libmicro-test-plus.a':
                        argument = archive
                    elif argument == program + '-test.elf':
                        argument = os.path.join(out, program + '-test.elf')
                    elif argument.startswith('-Wl,-Map,'):
                        argument = '-Wl,-Map,' + os.path.join(
                            out, program + '-test-map.txt')
                    elif argument == '-Werror':
                        continue
                    link.append(argument)
                run(link, build)

                elf = os.path.join(out, program + '-test.elf')
                size = run([tool_prefix + 'size', elf],
                           out).stdout.splitlines()[1].split()
                with open(os.path.join(out, program + '-test-map.txt')) as m:
                    records = sum(1 for line in m
                                  if line.startswith(' .data..Lsrc_loc'))
                qemu = qemu_command(build, program)
                qemu[qemu.index('--kernel') + 1] = elf
                run_result = run(qemu, out, check=False)
                output = run_result.stdout + run_result.stderr
                totals = next((line.strip() for line in output.splitlines()
                               if line.startswith('# { total')), '(none)')
                results[(config, program, variant)] = (
                    [int(x) for x in size[:3]], records,
                    run_result.returncode, totals)

    print('Tests: ' + label(options.tests, options.tests_patch) +
          '; baseline: ' + labels['baseline'] + '; current: ' +
          labels['current'] + '.')
    print()
    print('| Build | Program | `text` baseline | `text` current | Change | '
          '`data` | `bss` |')
    print('| --- | --- | ---: | ---: | ---: | --- | --- |')
    for config in configs:
        for program in PROGRAMS:
            (b_text, b_data, b_bss), _, _, _ = results[
                (config, program, 'baseline')]
            (c_text, c_data, c_bss), _, _, _ = results[
                (config, program, 'current')]
            change = c_text - b_text
            print(f'| {config} | {program} | {b_text} | {c_text} | '
                  f'{change:+} ({100.0 * change / b_text:+.1f}%) | '
                  f'{b_data} → {c_data} | {b_bss} → {c_bss} |')
    print()
    print('| Build | Program | Library | Exit | Totals | Source location '
          'records |')
    print('| --- | --- | --- | ---: | --- | ---: |')
    for config in configs:
        for program in PROGRAMS:
            for variant in roles:
                _, records, code, totals = results[(config, program, variant)]
                print(f'| {config} | {program} | {labels[variant]} | {code} | '
                      f'`{totals}` | {records} |')


if __name__ == '__main__':
    main()

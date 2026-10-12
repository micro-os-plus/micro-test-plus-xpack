/*
 * This file is part of the xPack project (http://xpack.github.io).
 * Copyright (c) 2024-2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

import Link from '@docusaurus/Link';

import type { FeatureItem } from './FeatureItem';

export const FeatureList: FeatureItem[] = [
  {
    title: 'Macro-free, expressive checks',
    Svg: require('@site/static/img/mosaic.svg').default,
    description: (
      <>
        Checks are plain C++20 expressions, such
        as <code>t.expect (mt::eq (a, 42))</code>. A failed check reports
        the file, the line, and the actual values of both
        operands, <b>without C macros</b>. Test suites are static objects
        that register themselves, so a new suite needs no changes to
        existing code.
      </>
    ),
  },
  {
    title: 'Built for bare-metal',
    Svg: require('@site/static/img/check-badge.svg').default,
    description: (
      <>
        The framework does not use <code>iostream</code>, so
        its <b>small footprint</b> fits microcontrollers with limited
        memory. Results go to <code>stdout</code>, so <b>semihosting</b> or
        a serial port is sufficient. The same tests run on Cortex-M,
        Cortex-A, and RISC-V devices, on QEMU, and on native hosts.
      </>
    ),
  },
  {
    title: 'Standard TAP output',
    Svg: require('@site/static/img/globe.svg').default,
    description: (
      <>
        Results use the <b>TAP 14</b> format by default, so standard TAP
        tools and CI pipelines can process them. Use <code>--reporter=human</code> for
        console-friendly output, and <code>--output-file</code> to also
        save the results to a file. The overall test result is returned as the
        process exit code.
      </>
    ),
  },
];

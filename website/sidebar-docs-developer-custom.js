/*
 * This file is part of the xPack project (http://xpack.github.io).
 * Copyright (c) 2026 Liviu Ionescu. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can be
 * obtained from https://opensource.org/licenses/mit.
 */

export const customDocsDeveloperSidebarCategory =
{
    type: 'category',
    label: 'Contributor\'s Guide',
    link: {
        type: 'doc',
        id: 'developer/index',
    },
    collapsed: true,
    items: [
        {
            type: 'doc',
            id: 'developer/architecture/index',
            label: 'Architecture overview'
        },
        {
            type: 'doc',
            id: 'developer/comparators/index',
            label: 'Expression templates and comparators'
        },
        {
            type: 'doc',
            id: 'developer/checks/index',
            label: 'Checks and the check result'
        },
        {
            type: 'doc',
            id: 'developer/formatter/index',
            label: 'The expression formatter'
        },
        {
            type: 'doc',
            id: 'developer/test-cases-and-suites/index',
            label: 'Test cases and suites'
        },
        {
            type: 'doc',
            id: 'developer/runner/index',
            label: 'The runner'
        },
        {
            type: 'doc',
            id: 'developer/reporters/index',
            label: 'The reporters'
        },
        {
            type: 'doc',
            id: 'developer/comparison/index',
            label: 'Comparison with other frameworks'
        },
        {
            type: 'doc',
            id: 'developer/making-changes/index',
            label: 'Making changes'
        }
    ]
}

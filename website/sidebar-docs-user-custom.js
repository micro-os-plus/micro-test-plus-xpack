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

export const customDocsUserSidebarCategory =
{
    type: 'category',
    label: 'User\'s Guide',
    link: {
        type: 'doc',
        id: 'user/index',
    },
    collapsed: true,
    items: [
        {
            type: 'doc',
            id: 'user/tutorial/index',
            label: 'Tutorial'
        },
        {
            type: 'doc',
            id: 'user/checks/index',
            label: 'Writing checks'
        },
        {
            type: 'doc',
            id: 'user/organising-tests/index',
            label: 'Organising tests'
        },
        {
            type: 'doc',
            id: 'user/running-tests/index',
            label: 'Running tests'
        },
        {
            type: 'doc',
            id: 'user/extending/index',
            label: 'Extending the framework'
        },
        {
            type: 'doc',
            id: 'user/embedded-targets/index',
            label: 'Embedded targets'
        },
        {
            type: 'doc',
            id: 'user/migrating/index',
            label: 'Migrating from earlier versions'
        }
    ]
}

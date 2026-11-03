# Reference pages

The project reference pages are generated with [Doxygen](https://www.doxygen.nl),
and converted to Docusaurus pages by `doxygen2docusaurus`.

## Build

To regenerate the pages, run the following from the `website` folder:

```sh
npm run generate-website-doxygen
```

The Doxygen result is in `website/static/doxygen`, and the converted pages
are in `website/docs/api`.

## Content

The Doxygen input is:

- `include`
- `src`
- `website/doxygen/top-common.h`
- `website/doxygen/topics.h`

The `topics.h` file includes the `.dox` files of the `pages`, `topics`,
`folders`, `files`, and `macros` folders; the order of the includes is also the
order of the entries in the sidebar.

## GitHub Pages

The website is published by the `publish-github-pages.yml` GitHub Actions workflow:

- <https://github.com/micro-os-plus/micro-test-plus-xpack/actions/workflows/publish-github-pages.yml>

The project GitHub Pages address is:

- <https://micro-os-plus.github.io/micro-test-plus-xpack/>

## Doxygen commands

The comments use the commands `@note`, `@warning`, and `@todo`; `@n` is
converted to `<br/>`. The `@example` command is not used.

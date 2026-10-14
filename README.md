# node-api-headers - Node-API C headers for building Node.js native addons

This is a `build2` package repository for
[`node-api-headers`](https://github.com/nodejs/node-api-headers), the header
files for the C-based Node-API provided by Node.js. Node-API is an API for
building native addons that guarantees the ABI (Application Binary Interface)
stability across versions of Node.js.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`node-api-headers` in your `build2`-based project, then instead see the
accompanying [`PACKAGE-README.md`](libnode-api-headers/PACKAGE-README.md)
file.

The development setup for `node-api-headers` uses the standard `bdep`-based
workflow. The upstream source code is a `git` submodule, so clone
recursively. For example:

```
git clone --recurse-submodules .../node-api-headers.git
cd node-api-headers

bdep init -C @gcc cc config.c=gcc
bdep update
bdep test
```

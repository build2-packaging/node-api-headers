# libnode-api-headers - Node-API C headers for building Node.js native addons

This is a `build2` package for the
[`node-api-headers`](https://github.com/nodejs/node-api-headers) C library. It
provides the header files for the C-based Node-API provided by Node.js.
Node-API is an API for building native addons that guarantees the ABI
(Application Binary Interface) stability across versions of Node.js (see:
[Node-API](https://nodejs.org/api/n-api.html)).

The Node-APIs that provide ECMAScript features from native code can be found
in `js_native_api_types.h` and `js_native_api.h`. The APIs defined in these
headers are included in `node_api_types.h` and `node_api.h`.


## Usage

To start using `libnode-api-headers` in your project, add the following
`depends` value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: libnode-api-headers ^1.9.0
```

Then import the library in your `buildfile`:

```
import libs = libnode-api-headers%lib{node-api-headers}
```

The headers are included without a directory prefix, for example,
`<node_api.h>`, and are installed into the `node/` subdirectory of, say,
`/usr/include/`, the same as the Debian and Fedora Node.js development
packages.

The headers target Node-API version 8 unless `NAPI_VERSION` is defined
otherwise, for example:

```
cxx.poptions += -DNAPI_VERSION=10
```

The Node-API functions are provided by the process that loads the addon
(`node`, `electron`, etc) and this package has nothing to link. On Windows the
addon is linked against an import library for the host executable, which
upstream describes with the `.def` files in its `def/` directory.

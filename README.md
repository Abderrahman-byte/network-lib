# Network library

A cpp cross-platform networking library.

[documentation](https://abderrahman-byte.github.io/network-lib/index.html).

## TODO

- [ ] Implement ``Socket`` class on Linux and Windows
- [ ] Test tcp and udp functions in ``Socket``
- [ ] Implement and throw exceptions for ``Socket functions`` something like [this](https://stackoverflow.com/questions/12171377/how-to-convert-errno-to-exception-using-system-error).

## Compilation

This library uses cmake as the build system.

**Note : Make sure cmake is installed.**

- The make the build and compile run the commands :

```bash
cmake -S . -B ./build/
cmake --build ./build/
```

The library is compiled in ``./build/liblibnet.a``.

- To run tests :

```bash
cmake -DBUILT_TESTS=true -S . -B ./build/
cmake --build ./build/
cd build
ctest
```

- To build the documentation files using doxygen :

```bash
cmake -DBUID_DOCS=true -S . -B ./build/
```

the generation documentation is in ``./build/docs/html/``.

**Note : Make sure doxygen is installed.**

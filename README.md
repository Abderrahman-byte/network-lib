# Network library

A cpp cross-platform networking library.

## TODO

- [ ] Implement ``Socket`` class on Linux and Windows
- [ ] Test tcp and udp functions in ``Socket``
- [ ] Implement and throw exceptions for ``Socket functions`` something like [this](https://stackoverflow.com/questions/12171377/how-to-convert-errno-to-exception-using-system-error).

## Compilation

This library uses cmake as the build system.

- The make the build and compile run the commands :

```bash
mkdir ./build # if it doesn't exist
cmake -S . -B ./build/
cmake --build ./build/
```

- To run tests :

```bash
cmake -DBUILT_TESTS=true -S . -B ./build/
cmake --build ./build/
cd build/test
ctest
```

- To build the documentation files using doxygen :

```bash
cmake -DBUID_DOCS=true -S . -B ./build/
```

the generation documentation is in ``./build/docs/html/``.

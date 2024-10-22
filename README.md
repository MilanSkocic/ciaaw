# Introduction

`ciaaw` is a  Fortran library providing the standard and abridged atomic weights, 
the isotopic abundance and the isotopes' standard atomic weights.
The formulas are taken from http://ciaaw.org. 
C API allows usage from C, or can be used as a basis for other wrappers.
Python wrapper allows easy usage from Python.

What have been implemented:

- [x] SAW: Standard Atomic Weights.
- [ ] ICE: Isotopic Composition of the Element (ongoing 45/92)
- [ ] NAW: Nuclides Atomic Weight.

To use `ciaaw` within your [fpm](https://github.com/fortran-lang/fpm) project,
add the following to your `fpm.toml` file:

```
    [dependencies]
    iapws = { git="https://github.com/MilanSkocic/ciaaw.git" }
```


# Dependencies

```
gcc>=10.0
gfortran>=10.0
fpm>=0.7
stdlib>=0.5
```

# Installation

A Makefile is provided, which uses [fpm](https://fpm.fortran-lang.org), for building the library.

* On windows, [msys2](https://www.msys2.org) needs to be installed. 
  Add the msys2 binary (usually C:\\msys64\\usr\\bin) to the path in order to be able to use make.
* On Darwin, the [gcc](https://formulae.brew.sh/formula/gcc) toolchain needs to be installed.

Build: the configuration file will set all the environment variables necessary for the compilation

```
    chmod +x configure.sh
    . ./configure.sh
    make
```

Run tests

```
    make test
```


Install

```
    make install
```

Uninstall

```
    make uninstall
```




# License

MIT

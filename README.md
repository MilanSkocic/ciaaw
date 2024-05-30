# Introduction

`ciaaw` is a  Fortran library providing the standard and abridged atomic weights, 
the isotopic abundance and the isotopes' standard atomic weights.
It also provides a API for the C language. The formulas are taken from http://ciaaw.org. 

To use `ciaaw` within your `fpm <https://github.com/fortran-lang/fpm>`_ project,
add the following to your `fpm.toml` file:

```
    [dependencies]
    iapws = { git="https://github.com/MilanSkocic/ciaaw.git" }
```

Optional thin wrappers allow usage of the library from other languages, e.g.:

* [C wrapper](https://github.com/MilanSkocic/ciaaw-capi)
* [Python wrapper](https://github.com/MilanSkocic/ciaaw-py)


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


# Dependencies

```
gcc>=10.0
gfortran>=10.0
fpm>=0.7
```


# License

MIT
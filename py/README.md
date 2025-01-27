# Introduction

Python wrapper around the
[Fortran ciaaw library](https://milanskocic.github.io/ciaaw/index.html).
The Fortran library does not need to be installed, the python wrapper embeds all needed fortran dependencies
for Windows and MacOS.
On linux, you might have to install `libgfortran` if it is not distributed by default with your linux distribution. 



# Installation

```
pip install pyciaaw
```



# License

MIT
```
MIT License

Copyright (c) Milan Skocic

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```


# Examples
```Python
r"""EXAMPLE IN PYTHON"""
import sys
sys.path.insert(0, "../py/src/")
import pyciaaw

# ASAW = Abridged Standard Atomic Weight
# SAW  = Standard Atomic Weight
# ICE  = Isotopic Composition of the Element
# NAW  = Nuclide Atomic Weight
# U    = Uncertainty

print("########## CIAAW VERSION ##########")
print("version ", pyciaaw.__version__)

print("########## CIAAW SAW  ##########")
print("ASAW H   = ", pyciaaw.get_saw("H"))
print("U ASAW H = ", pyciaaw.get_saw("H", uncertainty=True))
print("SAW H    = ", pyciaaw.get_saw("H", abridged=False, uncertainty=False))
print("U SAW H  = ", pyciaaw.get_saw("H", abridged=False, uncertainty=True))
print("ASAW Tc  = ", pyciaaw.get_saw("Tc"))


print("########## CIAAW ICE  ##########")
print("N ICE H   = ", pyciaaw.get_nice("H"))
print('ICE H 1   = ', pyciaaw.get_ice("H", A=1))
print('U ICE H 1 = ', pyciaaw.get_ice("H", A=1, uncertainty=True))
print('ICE H 2   = ', pyciaaw.get_ice("H", A=2))
print('U ICE H 2 = ', pyciaaw.get_ice("H", A=2, uncertainty=True))
print("N ICE Tc  = ", pyciaaw.get_nice("Tc"))
print("N ICE C   = ", pyciaaw.get_nice("C"))

print("########## CIAAW NAW  ##########")
print('NAW H 2   = ', pyciaaw.get_naw("H", A=2))
print('U NAW H 2 = ', pyciaaw.get_naw("H", A=2, uncertainty=True))
print("N NAW Tc  = ", pyciaaw.get_nnaw("Tc"))
```


# Changelog
## 0.5.1

* Code refactoring.
* Documentation update.

[Full changelog](https://github.com/MilanSkocic/ciaaw/releases)

## 0.5.0

* API break: 
    * Data for standard atomic weights are no directly accessed.
    * SAW, ICE and NAW are stored in derived types for each elements.
    * Each element is stored in a periodic table.
    * Element properties are now accessed through getters.
* Doc update.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)


## 0.4.3 

* Refractoring.
* Documentation update.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)


## 0.4.2 

* Refractoring.
* Documentation update.
* Merge back C API and Python wrapper.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)


## 0.4.1

* Fix bug in max value for saw. 

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)


## 0.4.0

* Fix type error in tests
* Refractoring
* Documentation update.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)


## 0.3.0

* Code refactoring.
* Move C API and Python wrapper to their own repositories.
* Improve documentatinon.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)



## 0.2.0

* Fix error in phosphorus name.
* Possibility to have standard atomic weights for several years.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)



## 0.1.0

* All elements from the periodic table added for the saw module.
* They are implemented as parameter derived type.

Full changelog available at [github](https://github.com/MilanSkocic/ciaaw/releases)

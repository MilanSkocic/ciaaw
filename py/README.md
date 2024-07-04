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



# Usage

```python
import pyciaaw

print("########## CIAAW VERSION ##########")
print("version ", pyciaaw.__version__)

print("########## CIAAW SAW ##########")
elmt = pyciaaw.H
print("Element: ", elmt["element"])
print("Symbol: ", elmt["symbol"])
print("Z: ", elmt["z"])
print("standard atomic weight max: ", elmt["saw_max"])
print("standard atomic weight min: ", elmt["saw_min"])
print("standard atomic weight: ", elmt["saw"])
print("standard atomic weight uncertainty: ", elmt["saw_u"])
print("abredged standard atomic weight: ", elmt["asaw"])
print("abredged standard atomic weight uncertainty: ", elmt["asaw_u"])
print()

elmt = pyciaaw.F
print("Element: ", elmt["element"])
print("Symbol: ", elmt["symbol"])
print("Z: ", elmt["z"])
print("standard atomic weight max: ", elmt["saw_max"])
print("standard atomic weight min: ", elmt["saw_min"])
print("standard atomic weight: ", elmt["saw"])
print("standard atomic weight uncertainty: ", elmt["saw_u"])
print("abredged standard atomic weight: ", elmt["asaw"])
print("abredged standard atomic weight uncertainty: ", elmt["asaw_u"])
```



# License

MIT

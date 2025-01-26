# Introduction

`ciaaw` is a  Fortran library providing the standard and abridged atomic weights, 
the isotopic abundance and the isotopes' standard atomic weights.
The data are taken from http://ciaaw.org. 
C API allows usage from C, or can be used as a basis for other wrappers.
Python wrapper allows easy usage from Python.

What have been implemented:

- [x] SAW: Standard Atomic Weights.
- [x] ICE: Isotopic Composition of the Element
- [x] NAW: Nuclides Atomic Weight.

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
## Fortran
```Fortran
program example_in_f
    use ciaaw
    implicit none

    character(len=8) :: s
    
    ! ASAW = Abridged Standard Atomic Weight
    ! SAW  = Standard Atomic Weight
    ! ICE  = Isotopic Composition of the Element
    ! NAW  = Nuclide Atomic Weight
    ! U    = Uncertainty

    print '(A)', '########### CIAAW VERSION ##########'
    print *, "version ", get_version()  

    print '(A)', '########### CIAAW SAW ##########'
    print '(A10, F10.5)', 'ASAW H   = ', get_saw("H", abridged=.true.)
    print '(A10, F10.5)', 'U ASAW H = ', get_saw("H", uncertainty=.true.)
    print '(A10, F10.5)', 'SAW H    = ', get_saw("H", abridged = .false.)
    print '(A10, F10.5)', 'U SAW H  =  ', get_saw("H", abridged = .false., uncertainty = .true.)
    print '(A10, F10.5)', 'ASAW T   = ', get_saw("Tc", abridged=.true.)
    
    print '(A)', '########### CIAAW ICE ##########'
    print '(A, I3)',        'N ICE H    = ', get_nice("H")
    print '(A, F12.6)',   'ICE H 1    = ', get_ice("H", A=1)
    print '(A, ES23.16)', 'U ICE H 1  = ', get_ice("H", A=1, uncertainty=.true.)
    print '(A, F12.6)',   'ICE H 2    = ', get_ice("H", A=2)
    print '(A, ES23.16)', 'U ICE H 2  = ', get_ice("H", A=2, uncertainty=.true.)
    print '(A, I3)',        'N ICE Tc   = ', get_nice("Tc")
    print '(A, I3)',        'N ICE C    = ', get_nice("C")
    
    print '(A)', '########### CIAAW NAW ##########'
    print '(A, ES23.16)',   'NAW H 2     = ', get_naw("H", A=2)
    print '(A, ES23.16)',   'U NAW H 2   = ', get_naw("H", A=2, uncertainty=.true.)
    print '(A, I3)',          'N NAW Tc    = ', get_nnaw("Tc")

end program
```
## C
```C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ciaaw.h"


    // ASAW = Abridged Standard Atomic Weight
    // SAW  = Standard Atomic Weight
    // ICE  = Isotopic Composition of the Element
    // NAW  = Nuclide Atomic Weight
    // U    = Uncertainty

int main(void){


    printf("%s\n", "########## CIAAW VERSION ##########");
    printf("version %s\n", ciaaw_get_version());
    
    printf("%s\n", "########## CIAAW SAW ##########");
    printf("%s %10.5f\n", "ASAW H   = ", ciaaw_get_saw("H", 1, true, false));
    printf("%s %10.5f\n", "U ASAW H = ", ciaaw_get_saw("H", 1, true, true));
    printf("%s %10.5f\n", "SAW H    = ", ciaaw_get_saw("H", 1, false, false));
    printf("%s %10.5f\n", "U SAW H  = ", ciaaw_get_saw("H", 1, false, true));
    printf("%s %10.5f\n", "ASAW Tc  = ", ciaaw_get_saw("Tc", 2, true, false));

    printf("%s\n", "########## CIAAW ICE ##########");
    printf("%s %d\n",     "N ICE H      = ", ciaaw_get_nice("H", 1));
    printf("%s %12.6f\n", "ICE H 1      = ", ciaaw_get_ice("H", 1, 1, false)); 
    printf("%s %23.16e\n","U ICE H 1    = ", ciaaw_get_ice("H", 1, 1, true)); 
    printf("%s %12.6f\n", "ICE H 2      = ", ciaaw_get_ice("H", 1, 2, false)); 
    printf("%s %23.16e\n","U ICE H 2    = ", ciaaw_get_ice("H", 1, 2, true)); 
    printf("%s %d\n",     "N ICE Tc     = ", ciaaw_get_nice("Tc", 2));
    printf("%s %d\n",     "N ICE C      = ", ciaaw_get_nice("C", 1));

    printf("%s\n", "########## CIAAW NAW ##########");
    printf("%s %23.16f\n", "NAW H 2      = ", ciaaw_get_naw("H", 1, 2, false)); 
    printf("%s %23.16e\n", "U NAW H 2    = ", ciaaw_get_naw("H", 1, 2, true)); 
    printf("%s %d\n",      "N NAW Tc     = ", ciaaw_get_nnaw("Tc", 2));

    return EXIT_SUCCESS;
    }
```
## Python
```Python
r"""Example in python"""
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


# References
Huang, W. J., M. Wang, F. G. Kondev, G. Audi, and S. Naimi. 2021. “The
AME 2020 atomic mass evaluation (i). Evaluation of input data, and
adjustment procedures\*.” *Chinese Physics C*, 45 (3): 030002. Chinese
Physical Society; the Institute of High Energy Physics of the Chinese
Academy of Sciences; the Institute of Modern Physics of the Chinese
Academy of Sciences; IOP Publishing Ltd.
<https://doi.org/10.1088/1674-1137/abddb0>.

Meija, J., T. B. Coplen, M. Berglund, W. A. Brand, P. De Bièvre, M.
Gröning, N. E. Holden, J. Irrgeher, R. D. Loss, T. Walczyk, and T.
Prohaska. 2016. “Isotopic compositions of the elements 2013 (IUPAC
Technical Report).” Pure and Applied Chemistry, 88 (3): 293–306.
<https://doi.org/10.1515/pac-2015-0503>.

Prohaska, T., J. Irrgeher, J. Benefield, J. K. Böhlke, L. A. Chesson, T.
B. Coplen, T. Ding, P. J. H. Dunn, M. Gröning, N. E. Holden, H. A. J.
Meijer, H. Moossen, A. Possolo, Y. Takahashi, J. Vogl, T. Walczyk, J.
Wang, M. E. Wieser, S. Yoneda, X.-K. Zhu, and J. Meija. 2022. “Standard
atomic weights of the elements 2021 (IUPAC Technical Report).” Pure and
Applied Chemistry, 94 (5): 573–600.
<https://doi.org/10.1515/pac-2019-0603>.

van der Veen, M. H., J. Meia, and D. Brynn Hibbert. 2021.
“Interpretation and use of standard atomic weights (IUPAC Technical
Report).” *Pure and Applied Chemistry*, 93 (5): 629–646.


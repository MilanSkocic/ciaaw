---
title: APIs
---

![CIAAW](../media/logo.png)

Standard and abridged atomic weights, isotopic abundances and 
nuclides' standard atomic weights according to [CIAAW](https://www.ciaaw.org).


# Fortran API

The modules [[ciaaw__saw(module)]], [[ciaaw__ice(module)]], [[ciaaw__naw(module)]] and  [[ciaaw__pte(module)]] are
automatically generated with a simple script written in Python.

The API defines convenient getters are available for accessing the desired data for an elements
without having to access to whole periodic table [[ciaaw__pte(module):pt]]

* [[ciaaw__api(module):get_saw(function)]]
* [[ciaaw__api(module):get_ice(function)]]
* [[ciaaw__api(module):get_nice(function)]]
* [[ciaaw__api(module):get_naw(function)]]
* [[ciaaw__api(module):get_nnaw(function)]]

## SAW: Standard Atomic Weights

The latest standard atomic weights were released in 2021 by the [ciaaw](https://www.ciaaw.org).
All the values for the atomic weights are provided as double precision reals in a derived type
[[ciaaw__types(module):saw_type(type)]].

The standard atomic weights (or realtive atomic mass),\(A_r(E)\), 
are extracted from table 1 [Prohaska et al. 2022](../references.html). For the elements
that feature an interval for the standard atomic weight, the mean value and the uncertainty are computed
using formulas defined in [Van der Veen et al. 2021](../references.html).

$$ A_r(E) = \frac{a+b}{2} $$

$$ u(A_r(E)) = \frac{b-a}{2\sqrt{3}} $$

The standard atomic weights are a dimensionless quantity and thus they need to be multiplied by 
the molar mass constant \(M_u=1.00000000105 \pm 0.00000000031 g.mol^{-1}\) 
in order to get the value in \(g.mol^{-1}\). 
See [codata](https://milanskocic.github.io/codata/) for physical constants.


## ICE: Isotopic Compositions of the Element

The latest isotopic compositions were released in 2013 by the [ciaaw](https://www.ciaaw.org).
All the values for the compositions are provided as double precision reals in a derived type
[[ciaaw__types(module):ice_type(type)]].
The isotopic compositions of the element, are extracted from table 1 [Meija et al. 2013](../references.html). 

## NAW: Nuclide Atomic Weights

The latest atomic weights for nuclides were released in 2020 by [ciaaw](https://www.ciaaw.org)
from [Huang et al. 2021](../references.html).
All the values for the nuclide atomic weights are provided as double precision reals in derived type
[[ciaaw__types(module):naw_type(type)]]. 


```fortran
{!example/example.f90!}
```



# C API
The prototypes of the C API are defined as shown below.

```c
{!include/ciaaw.h!}

```

```C
{!example/example.c!}
```



# Python wrapper

The getters defined in [Fortran API](#fortran-api) are available at the top level.

```python
{!example/example.py!}
```

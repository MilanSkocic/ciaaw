---
title: SAW: Standard Atomic Weights
---

# Description

The standard atomic weights (or realtive atomic mass),\(A_r(E)\), 
are extracted from table 1 (Prohaska et al. 2022). For the elements
that feature an interval for the standard atomic weight, the mean value and the uncertainty are computed
using formulas defined in (Van der Veen et al. 2021).

$$ A_r(E) = \frac{a+b}{2} $$

$$ u(A_r(E)) = \frac{b-a}{2\sqrt{3}} $$

The standard atomic weights are a dimensionless quantity and thus they need to be multiplied by 
the molar mass constant \(M_u=1.00000000105 \pm 0.00000000031 g.mol^{-1}\) 
in order to get the value in \(g.mol^{-1}\). 
See [codata](https://milanskocic.github.io/codata-docs/) for physical constants.

# Example

```Fortran
{!./example/example_in_f.f90!}

```

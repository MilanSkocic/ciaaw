#####################
CIAAW - Documentation
#####################

.. image:: ../../../media/logo.png
  :width: 400
  :align: center
  :alt: Alternative text
   
Standard and abridged atomic weights, isotopic abundances and 
nuclides' standard atomic weights according to `CIAAW <https://www.ciaaw.org>`_.

.. only:: html
    
    - man page: :download:`ciaaw.3 <../build/man/ciaaw.3>`.
    
    - info: :download:`ciaaw.info <../build/texinfo/ciaaw.info>`.
    
    - pdf: :download:`ciaaw.pdf <../build/latex/ciaaw.pdf>`.


The latest standard atomic weights were released in 2021 by the [ciaaw](https://www.ciaaw.org).
All the values for the atomic weights are provided as double precision reals.

The standard atomic weights (or realtive atomic mass),:math:`A_r(E)`, 
are extracted from table 1 from :cite:t:`prohaska2022-1`. For the elements
that feature an interval for the standard atomic weight, the mean value and the uncertainty are computed
using formulas defined in :cite:p:`vanderveen2021-1`.

.. math::

   A_r(E) = \frac{a+b}{2}

   u(A_r(E)) = \frac{b-a}{2\sqrt{3}}

The standard atomic weights are a dimensionless quantity and thus they need to be multiplied by 
the molar mass constant :math:`M_u=1.00000000105 \pm 0.00000000031 g.mol^{-1}`
in order to get the value in :math:`g.mol^{-1}`. 
See `codata <https://milanskocic.github.io/codata>`_ for physical constants.


The latest isotopic compositions were released in 2013 by the [ciaaw](https://www.ciaaw.org).
All the values for the compositions are provided as double precision reals.
The isotopic compositions of the element, are extracted from table 1 from :cite:t:`meija2016-1`. 


The latest atomic weights for nuclides were released in 2020 by [ciaaw](https://www.ciaaw.org)
from :cite:t:`huang-2021-1`.
All the values for the nuclide atomic weights are provided as double precision reals. 



.. toctree::
   :maxdepth: 1
   :hidden:
   
   getting_started/index.rst
   examples/index.rst
   api/index.rst
   changelog/index.rst
   references/index.rst

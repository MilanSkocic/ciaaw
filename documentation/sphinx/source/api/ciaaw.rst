ciaaw
===============

Fortran
--------------

.. only:: html
    
    `Fortran code API <../ford/index.html>`_

.. only:: latex
    
    * `iapws.f90`: Main module for the whole library.
    
    .. literalinclude:: ../../../../src/ciaaw_saw.f90
        :language: Fortran

    Standard Atomic Weights
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    * `ciaaw_saw.f90`: Module for Standard atomic weights
    
    .. literalinclude:: ../../../../src/ciaaw_saw.f90
        :language: Fortran
    
    * `ciaaw_saw_capi.f90`: C API for the sat module.
    
    .. literalinclude:: ../../../../src/ciaaw_saw_capi.f90
        :language: Fortran

C
------

* `ciaaw.h`: Main C header for the whole library.

.. literalinclude:: ../../../../include/ciaaw.h
    :language:  C

Standard Atomic Weights
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* `ciaaw_saw.h`: C header.

.. literalinclude:: ../../../../include/ciaaw_saw.h
    :language: C

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "ciaaw_saw.h"

PyDoc_STRVAR(module_docstring, "C extension for saw 2021.");

static PyMethodDef myMethods[] = {{ NULL, NULL, 0, NULL }};

static struct PyModuleDef saw_2021 = {PyModuleDef_HEAD_INIT, "saw_2021", module_docstring, -1, myMethods};

PyMODINIT_FUNC PyInit_saw_2021(void){
    PyObject *m;
    PyObject *d;
    PyObject *v;
    PyObject *element;
    m = PyModule_Create(&saw_2021);
    d = PyModule_GetDict(m);

    v = PyLong_FromLong(YEAR_2021);
    PyDict_SetItemString(d, "YEAR_2021", v);
    Py_INCREF(v);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_H_2021.element,
        "symbol",ciaaw_saw_H_2021.symbol,
        "z",ciaaw_saw_H_2021.z,
        "saw_max",ciaaw_saw_H_2021.saw_max,
        "saw_min",ciaaw_saw_H_2021.saw_min,
        "saw",ciaaw_saw_H_2021.saw,
        "saw_u",ciaaw_saw_H_2021.saw_u,
        "asaw",ciaaw_saw_H_2021.asaw,
        "asaw_u",ciaaw_saw_H_2021.asaw_u
    );
    PyDict_SetItemString(d, "H", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_He_2021.element,
        "symbol",ciaaw_saw_He_2021.symbol,
        "z",ciaaw_saw_He_2021.z,
        "saw_max",ciaaw_saw_He_2021.saw_max,
        "saw_min",ciaaw_saw_He_2021.saw_min,
        "saw",ciaaw_saw_He_2021.saw,
        "saw_u",ciaaw_saw_He_2021.saw_u,
        "asaw",ciaaw_saw_He_2021.asaw,
        "asaw_u",ciaaw_saw_He_2021.asaw_u
    );
    PyDict_SetItemString(d, "He", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Li_2021.element,
        "symbol",ciaaw_saw_Li_2021.symbol,
        "z",ciaaw_saw_Li_2021.z,
        "saw_max",ciaaw_saw_Li_2021.saw_max,
        "saw_min",ciaaw_saw_Li_2021.saw_min,
        "saw",ciaaw_saw_Li_2021.saw,
        "saw_u",ciaaw_saw_Li_2021.saw_u,
        "asaw",ciaaw_saw_Li_2021.asaw,
        "asaw_u",ciaaw_saw_Li_2021.asaw_u
    );
    PyDict_SetItemString(d, "Li", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Be_2021.element,
        "symbol",ciaaw_saw_Be_2021.symbol,
        "z",ciaaw_saw_Be_2021.z,
        "saw_max",ciaaw_saw_Be_2021.saw_max,
        "saw_min",ciaaw_saw_Be_2021.saw_min,
        "saw",ciaaw_saw_Be_2021.saw,
        "saw_u",ciaaw_saw_Be_2021.saw_u,
        "asaw",ciaaw_saw_Be_2021.asaw,
        "asaw_u",ciaaw_saw_Be_2021.asaw_u
    );
    PyDict_SetItemString(d, "Be", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_B_2021.element,
        "symbol",ciaaw_saw_B_2021.symbol,
        "z",ciaaw_saw_B_2021.z,
        "saw_max",ciaaw_saw_B_2021.saw_max,
        "saw_min",ciaaw_saw_B_2021.saw_min,
        "saw",ciaaw_saw_B_2021.saw,
        "saw_u",ciaaw_saw_B_2021.saw_u,
        "asaw",ciaaw_saw_B_2021.asaw,
        "asaw_u",ciaaw_saw_B_2021.asaw_u
    );
    PyDict_SetItemString(d, "B", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_C_2021.element,
        "symbol",ciaaw_saw_C_2021.symbol,
        "z",ciaaw_saw_C_2021.z,
        "saw_max",ciaaw_saw_C_2021.saw_max,
        "saw_min",ciaaw_saw_C_2021.saw_min,
        "saw",ciaaw_saw_C_2021.saw,
        "saw_u",ciaaw_saw_C_2021.saw_u,
        "asaw",ciaaw_saw_C_2021.asaw,
        "asaw_u",ciaaw_saw_C_2021.asaw_u
    );
    PyDict_SetItemString(d, "C", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_N_2021.element,
        "symbol",ciaaw_saw_N_2021.symbol,
        "z",ciaaw_saw_N_2021.z,
        "saw_max",ciaaw_saw_N_2021.saw_max,
        "saw_min",ciaaw_saw_N_2021.saw_min,
        "saw",ciaaw_saw_N_2021.saw,
        "saw_u",ciaaw_saw_N_2021.saw_u,
        "asaw",ciaaw_saw_N_2021.asaw,
        "asaw_u",ciaaw_saw_N_2021.asaw_u
    );
    PyDict_SetItemString(d, "N", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_O_2021.element,
        "symbol",ciaaw_saw_O_2021.symbol,
        "z",ciaaw_saw_O_2021.z,
        "saw_max",ciaaw_saw_O_2021.saw_max,
        "saw_min",ciaaw_saw_O_2021.saw_min,
        "saw",ciaaw_saw_O_2021.saw,
        "saw_u",ciaaw_saw_O_2021.saw_u,
        "asaw",ciaaw_saw_O_2021.asaw,
        "asaw_u",ciaaw_saw_O_2021.asaw_u
    );
    PyDict_SetItemString(d, "O", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_F_2021.element,
        "symbol",ciaaw_saw_F_2021.symbol,
        "z",ciaaw_saw_F_2021.z,
        "saw_max",ciaaw_saw_F_2021.saw_max,
        "saw_min",ciaaw_saw_F_2021.saw_min,
        "saw",ciaaw_saw_F_2021.saw,
        "saw_u",ciaaw_saw_F_2021.saw_u,
        "asaw",ciaaw_saw_F_2021.asaw,
        "asaw_u",ciaaw_saw_F_2021.asaw_u
    );
    PyDict_SetItemString(d, "F", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ne_2021.element,
        "symbol",ciaaw_saw_Ne_2021.symbol,
        "z",ciaaw_saw_Ne_2021.z,
        "saw_max",ciaaw_saw_Ne_2021.saw_max,
        "saw_min",ciaaw_saw_Ne_2021.saw_min,
        "saw",ciaaw_saw_Ne_2021.saw,
        "saw_u",ciaaw_saw_Ne_2021.saw_u,
        "asaw",ciaaw_saw_Ne_2021.asaw,
        "asaw_u",ciaaw_saw_Ne_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ne", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Na_2021.element,
        "symbol",ciaaw_saw_Na_2021.symbol,
        "z",ciaaw_saw_Na_2021.z,
        "saw_max",ciaaw_saw_Na_2021.saw_max,
        "saw_min",ciaaw_saw_Na_2021.saw_min,
        "saw",ciaaw_saw_Na_2021.saw,
        "saw_u",ciaaw_saw_Na_2021.saw_u,
        "asaw",ciaaw_saw_Na_2021.asaw,
        "asaw_u",ciaaw_saw_Na_2021.asaw_u
    );
    PyDict_SetItemString(d, "Na", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Mg_2021.element,
        "symbol",ciaaw_saw_Mg_2021.symbol,
        "z",ciaaw_saw_Mg_2021.z,
        "saw_max",ciaaw_saw_Mg_2021.saw_max,
        "saw_min",ciaaw_saw_Mg_2021.saw_min,
        "saw",ciaaw_saw_Mg_2021.saw,
        "saw_u",ciaaw_saw_Mg_2021.saw_u,
        "asaw",ciaaw_saw_Mg_2021.asaw,
        "asaw_u",ciaaw_saw_Mg_2021.asaw_u
    );
    PyDict_SetItemString(d, "Mg", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Al_2021.element,
        "symbol",ciaaw_saw_Al_2021.symbol,
        "z",ciaaw_saw_Al_2021.z,
        "saw_max",ciaaw_saw_Al_2021.saw_max,
        "saw_min",ciaaw_saw_Al_2021.saw_min,
        "saw",ciaaw_saw_Al_2021.saw,
        "saw_u",ciaaw_saw_Al_2021.saw_u,
        "asaw",ciaaw_saw_Al_2021.asaw,
        "asaw_u",ciaaw_saw_Al_2021.asaw_u
    );
    PyDict_SetItemString(d, "Al", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Si_2021.element,
        "symbol",ciaaw_saw_Si_2021.symbol,
        "z",ciaaw_saw_Si_2021.z,
        "saw_max",ciaaw_saw_Si_2021.saw_max,
        "saw_min",ciaaw_saw_Si_2021.saw_min,
        "saw",ciaaw_saw_Si_2021.saw,
        "saw_u",ciaaw_saw_Si_2021.saw_u,
        "asaw",ciaaw_saw_Si_2021.asaw,
        "asaw_u",ciaaw_saw_Si_2021.asaw_u
    );
    PyDict_SetItemString(d, "Si", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_P_2021.element,
        "symbol",ciaaw_saw_P_2021.symbol,
        "z",ciaaw_saw_P_2021.z,
        "saw_max",ciaaw_saw_P_2021.saw_max,
        "saw_min",ciaaw_saw_P_2021.saw_min,
        "saw",ciaaw_saw_P_2021.saw,
        "saw_u",ciaaw_saw_P_2021.saw_u,
        "asaw",ciaaw_saw_P_2021.asaw,
        "asaw_u",ciaaw_saw_P_2021.asaw_u
    );
    PyDict_SetItemString(d, "P", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_S_2021.element,
        "symbol",ciaaw_saw_S_2021.symbol,
        "z",ciaaw_saw_S_2021.z,
        "saw_max",ciaaw_saw_S_2021.saw_max,
        "saw_min",ciaaw_saw_S_2021.saw_min,
        "saw",ciaaw_saw_S_2021.saw,
        "saw_u",ciaaw_saw_S_2021.saw_u,
        "asaw",ciaaw_saw_S_2021.asaw,
        "asaw_u",ciaaw_saw_S_2021.asaw_u
    );
    PyDict_SetItemString(d, "S", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cl_2021.element,
        "symbol",ciaaw_saw_Cl_2021.symbol,
        "z",ciaaw_saw_Cl_2021.z,
        "saw_max",ciaaw_saw_Cl_2021.saw_max,
        "saw_min",ciaaw_saw_Cl_2021.saw_min,
        "saw",ciaaw_saw_Cl_2021.saw,
        "saw_u",ciaaw_saw_Cl_2021.saw_u,
        "asaw",ciaaw_saw_Cl_2021.asaw,
        "asaw_u",ciaaw_saw_Cl_2021.asaw_u
    );
    PyDict_SetItemString(d, "Cl", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ar_2021.element,
        "symbol",ciaaw_saw_Ar_2021.symbol,
        "z",ciaaw_saw_Ar_2021.z,
        "saw_max",ciaaw_saw_Ar_2021.saw_max,
        "saw_min",ciaaw_saw_Ar_2021.saw_min,
        "saw",ciaaw_saw_Ar_2021.saw,
        "saw_u",ciaaw_saw_Ar_2021.saw_u,
        "asaw",ciaaw_saw_Ar_2021.asaw,
        "asaw_u",ciaaw_saw_Ar_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ar", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_K_2021.element,
        "symbol",ciaaw_saw_K_2021.symbol,
        "z",ciaaw_saw_K_2021.z,
        "saw_max",ciaaw_saw_K_2021.saw_max,
        "saw_min",ciaaw_saw_K_2021.saw_min,
        "saw",ciaaw_saw_K_2021.saw,
        "saw_u",ciaaw_saw_K_2021.saw_u,
        "asaw",ciaaw_saw_K_2021.asaw,
        "asaw_u",ciaaw_saw_K_2021.asaw_u
    );
    PyDict_SetItemString(d, "K", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ca_2021.element,
        "symbol",ciaaw_saw_Ca_2021.symbol,
        "z",ciaaw_saw_Ca_2021.z,
        "saw_max",ciaaw_saw_Ca_2021.saw_max,
        "saw_min",ciaaw_saw_Ca_2021.saw_min,
        "saw",ciaaw_saw_Ca_2021.saw,
        "saw_u",ciaaw_saw_Ca_2021.saw_u,
        "asaw",ciaaw_saw_Ca_2021.asaw,
        "asaw_u",ciaaw_saw_Ca_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ca", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sc_2021.element,
        "symbol",ciaaw_saw_Sc_2021.symbol,
        "z",ciaaw_saw_Sc_2021.z,
        "saw_max",ciaaw_saw_Sc_2021.saw_max,
        "saw_min",ciaaw_saw_Sc_2021.saw_min,
        "saw",ciaaw_saw_Sc_2021.saw,
        "saw_u",ciaaw_saw_Sc_2021.saw_u,
        "asaw",ciaaw_saw_Sc_2021.asaw,
        "asaw_u",ciaaw_saw_Sc_2021.asaw_u
    );
    PyDict_SetItemString(d, "Sc", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ti_2021.element,
        "symbol",ciaaw_saw_Ti_2021.symbol,
        "z",ciaaw_saw_Ti_2021.z,
        "saw_max",ciaaw_saw_Ti_2021.saw_max,
        "saw_min",ciaaw_saw_Ti_2021.saw_min,
        "saw",ciaaw_saw_Ti_2021.saw,
        "saw_u",ciaaw_saw_Ti_2021.saw_u,
        "asaw",ciaaw_saw_Ti_2021.asaw,
        "asaw_u",ciaaw_saw_Ti_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ti", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_V_2021.element,
        "symbol",ciaaw_saw_V_2021.symbol,
        "z",ciaaw_saw_V_2021.z,
        "saw_max",ciaaw_saw_V_2021.saw_max,
        "saw_min",ciaaw_saw_V_2021.saw_min,
        "saw",ciaaw_saw_V_2021.saw,
        "saw_u",ciaaw_saw_V_2021.saw_u,
        "asaw",ciaaw_saw_V_2021.asaw,
        "asaw_u",ciaaw_saw_V_2021.asaw_u
    );
    PyDict_SetItemString(d, "V", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cr_2021.element,
        "symbol",ciaaw_saw_Cr_2021.symbol,
        "z",ciaaw_saw_Cr_2021.z,
        "saw_max",ciaaw_saw_Cr_2021.saw_max,
        "saw_min",ciaaw_saw_Cr_2021.saw_min,
        "saw",ciaaw_saw_Cr_2021.saw,
        "saw_u",ciaaw_saw_Cr_2021.saw_u,
        "asaw",ciaaw_saw_Cr_2021.asaw,
        "asaw_u",ciaaw_saw_Cr_2021.asaw_u
    );
    PyDict_SetItemString(d, "Cr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Mn_2021.element,
        "symbol",ciaaw_saw_Mn_2021.symbol,
        "z",ciaaw_saw_Mn_2021.z,
        "saw_max",ciaaw_saw_Mn_2021.saw_max,
        "saw_min",ciaaw_saw_Mn_2021.saw_min,
        "saw",ciaaw_saw_Mn_2021.saw,
        "saw_u",ciaaw_saw_Mn_2021.saw_u,
        "asaw",ciaaw_saw_Mn_2021.asaw,
        "asaw_u",ciaaw_saw_Mn_2021.asaw_u
    );
    PyDict_SetItemString(d, "Mn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Fe_2021.element,
        "symbol",ciaaw_saw_Fe_2021.symbol,
        "z",ciaaw_saw_Fe_2021.z,
        "saw_max",ciaaw_saw_Fe_2021.saw_max,
        "saw_min",ciaaw_saw_Fe_2021.saw_min,
        "saw",ciaaw_saw_Fe_2021.saw,
        "saw_u",ciaaw_saw_Fe_2021.saw_u,
        "asaw",ciaaw_saw_Fe_2021.asaw,
        "asaw_u",ciaaw_saw_Fe_2021.asaw_u
    );
    PyDict_SetItemString(d, "Fe", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Co_2021.element,
        "symbol",ciaaw_saw_Co_2021.symbol,
        "z",ciaaw_saw_Co_2021.z,
        "saw_max",ciaaw_saw_Co_2021.saw_max,
        "saw_min",ciaaw_saw_Co_2021.saw_min,
        "saw",ciaaw_saw_Co_2021.saw,
        "saw_u",ciaaw_saw_Co_2021.saw_u,
        "asaw",ciaaw_saw_Co_2021.asaw,
        "asaw_u",ciaaw_saw_Co_2021.asaw_u
    );
    PyDict_SetItemString(d, "Co", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ni_2021.element,
        "symbol",ciaaw_saw_Ni_2021.symbol,
        "z",ciaaw_saw_Ni_2021.z,
        "saw_max",ciaaw_saw_Ni_2021.saw_max,
        "saw_min",ciaaw_saw_Ni_2021.saw_min,
        "saw",ciaaw_saw_Ni_2021.saw,
        "saw_u",ciaaw_saw_Ni_2021.saw_u,
        "asaw",ciaaw_saw_Ni_2021.asaw,
        "asaw_u",ciaaw_saw_Ni_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ni", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cu_2021.element,
        "symbol",ciaaw_saw_Cu_2021.symbol,
        "z",ciaaw_saw_Cu_2021.z,
        "saw_max",ciaaw_saw_Cu_2021.saw_max,
        "saw_min",ciaaw_saw_Cu_2021.saw_min,
        "saw",ciaaw_saw_Cu_2021.saw,
        "saw_u",ciaaw_saw_Cu_2021.saw_u,
        "asaw",ciaaw_saw_Cu_2021.asaw,
        "asaw_u",ciaaw_saw_Cu_2021.asaw_u
    );
    PyDict_SetItemString(d, "Cu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Zn_2021.element,
        "symbol",ciaaw_saw_Zn_2021.symbol,
        "z",ciaaw_saw_Zn_2021.z,
        "saw_max",ciaaw_saw_Zn_2021.saw_max,
        "saw_min",ciaaw_saw_Zn_2021.saw_min,
        "saw",ciaaw_saw_Zn_2021.saw,
        "saw_u",ciaaw_saw_Zn_2021.saw_u,
        "asaw",ciaaw_saw_Zn_2021.asaw,
        "asaw_u",ciaaw_saw_Zn_2021.asaw_u
    );
    PyDict_SetItemString(d, "Zn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ga_2021.element,
        "symbol",ciaaw_saw_Ga_2021.symbol,
        "z",ciaaw_saw_Ga_2021.z,
        "saw_max",ciaaw_saw_Ga_2021.saw_max,
        "saw_min",ciaaw_saw_Ga_2021.saw_min,
        "saw",ciaaw_saw_Ga_2021.saw,
        "saw_u",ciaaw_saw_Ga_2021.saw_u,
        "asaw",ciaaw_saw_Ga_2021.asaw,
        "asaw_u",ciaaw_saw_Ga_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ga", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ge_2021.element,
        "symbol",ciaaw_saw_Ge_2021.symbol,
        "z",ciaaw_saw_Ge_2021.z,
        "saw_max",ciaaw_saw_Ge_2021.saw_max,
        "saw_min",ciaaw_saw_Ge_2021.saw_min,
        "saw",ciaaw_saw_Ge_2021.saw,
        "saw_u",ciaaw_saw_Ge_2021.saw_u,
        "asaw",ciaaw_saw_Ge_2021.asaw,
        "asaw_u",ciaaw_saw_Ge_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ge", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_As_2021.element,
        "symbol",ciaaw_saw_As_2021.symbol,
        "z",ciaaw_saw_As_2021.z,
        "saw_max",ciaaw_saw_As_2021.saw_max,
        "saw_min",ciaaw_saw_As_2021.saw_min,
        "saw",ciaaw_saw_As_2021.saw,
        "saw_u",ciaaw_saw_As_2021.saw_u,
        "asaw",ciaaw_saw_As_2021.asaw,
        "asaw_u",ciaaw_saw_As_2021.asaw_u
    );
    PyDict_SetItemString(d, "As", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Se_2021.element,
        "symbol",ciaaw_saw_Se_2021.symbol,
        "z",ciaaw_saw_Se_2021.z,
        "saw_max",ciaaw_saw_Se_2021.saw_max,
        "saw_min",ciaaw_saw_Se_2021.saw_min,
        "saw",ciaaw_saw_Se_2021.saw,
        "saw_u",ciaaw_saw_Se_2021.saw_u,
        "asaw",ciaaw_saw_Se_2021.asaw,
        "asaw_u",ciaaw_saw_Se_2021.asaw_u
    );
    PyDict_SetItemString(d, "Se", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Br_2021.element,
        "symbol",ciaaw_saw_Br_2021.symbol,
        "z",ciaaw_saw_Br_2021.z,
        "saw_max",ciaaw_saw_Br_2021.saw_max,
        "saw_min",ciaaw_saw_Br_2021.saw_min,
        "saw",ciaaw_saw_Br_2021.saw,
        "saw_u",ciaaw_saw_Br_2021.saw_u,
        "asaw",ciaaw_saw_Br_2021.asaw,
        "asaw_u",ciaaw_saw_Br_2021.asaw_u
    );
    PyDict_SetItemString(d, "Br", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Kr_2021.element,
        "symbol",ciaaw_saw_Kr_2021.symbol,
        "z",ciaaw_saw_Kr_2021.z,
        "saw_max",ciaaw_saw_Kr_2021.saw_max,
        "saw_min",ciaaw_saw_Kr_2021.saw_min,
        "saw",ciaaw_saw_Kr_2021.saw,
        "saw_u",ciaaw_saw_Kr_2021.saw_u,
        "asaw",ciaaw_saw_Kr_2021.asaw,
        "asaw_u",ciaaw_saw_Kr_2021.asaw_u
    );
    PyDict_SetItemString(d, "Kr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Rb_2021.element,
        "symbol",ciaaw_saw_Rb_2021.symbol,
        "z",ciaaw_saw_Rb_2021.z,
        "saw_max",ciaaw_saw_Rb_2021.saw_max,
        "saw_min",ciaaw_saw_Rb_2021.saw_min,
        "saw",ciaaw_saw_Rb_2021.saw,
        "saw_u",ciaaw_saw_Rb_2021.saw_u,
        "asaw",ciaaw_saw_Rb_2021.asaw,
        "asaw_u",ciaaw_saw_Rb_2021.asaw_u
    );
    PyDict_SetItemString(d, "Rb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sr_2021.element,
        "symbol",ciaaw_saw_Sr_2021.symbol,
        "z",ciaaw_saw_Sr_2021.z,
        "saw_max",ciaaw_saw_Sr_2021.saw_max,
        "saw_min",ciaaw_saw_Sr_2021.saw_min,
        "saw",ciaaw_saw_Sr_2021.saw,
        "saw_u",ciaaw_saw_Sr_2021.saw_u,
        "asaw",ciaaw_saw_Sr_2021.asaw,
        "asaw_u",ciaaw_saw_Sr_2021.asaw_u
    );
    PyDict_SetItemString(d, "Sr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Y_2021.element,
        "symbol",ciaaw_saw_Y_2021.symbol,
        "z",ciaaw_saw_Y_2021.z,
        "saw_max",ciaaw_saw_Y_2021.saw_max,
        "saw_min",ciaaw_saw_Y_2021.saw_min,
        "saw",ciaaw_saw_Y_2021.saw,
        "saw_u",ciaaw_saw_Y_2021.saw_u,
        "asaw",ciaaw_saw_Y_2021.asaw,
        "asaw_u",ciaaw_saw_Y_2021.asaw_u
    );
    PyDict_SetItemString(d, "Y", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Zr_2021.element,
        "symbol",ciaaw_saw_Zr_2021.symbol,
        "z",ciaaw_saw_Zr_2021.z,
        "saw_max",ciaaw_saw_Zr_2021.saw_max,
        "saw_min",ciaaw_saw_Zr_2021.saw_min,
        "saw",ciaaw_saw_Zr_2021.saw,
        "saw_u",ciaaw_saw_Zr_2021.saw_u,
        "asaw",ciaaw_saw_Zr_2021.asaw,
        "asaw_u",ciaaw_saw_Zr_2021.asaw_u
    );
    PyDict_SetItemString(d, "Zr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Nb_2021.element,
        "symbol",ciaaw_saw_Nb_2021.symbol,
        "z",ciaaw_saw_Nb_2021.z,
        "saw_max",ciaaw_saw_Nb_2021.saw_max,
        "saw_min",ciaaw_saw_Nb_2021.saw_min,
        "saw",ciaaw_saw_Nb_2021.saw,
        "saw_u",ciaaw_saw_Nb_2021.saw_u,
        "asaw",ciaaw_saw_Nb_2021.asaw,
        "asaw_u",ciaaw_saw_Nb_2021.asaw_u
    );
    PyDict_SetItemString(d, "Nb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Mo_2021.element,
        "symbol",ciaaw_saw_Mo_2021.symbol,
        "z",ciaaw_saw_Mo_2021.z,
        "saw_max",ciaaw_saw_Mo_2021.saw_max,
        "saw_min",ciaaw_saw_Mo_2021.saw_min,
        "saw",ciaaw_saw_Mo_2021.saw,
        "saw_u",ciaaw_saw_Mo_2021.saw_u,
        "asaw",ciaaw_saw_Mo_2021.asaw,
        "asaw_u",ciaaw_saw_Mo_2021.asaw_u
    );
    PyDict_SetItemString(d, "Mo", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Tc_2021.element,
        "symbol",ciaaw_saw_Tc_2021.symbol,
        "z",ciaaw_saw_Tc_2021.z,
        "saw_max",ciaaw_saw_Tc_2021.saw_max,
        "saw_min",ciaaw_saw_Tc_2021.saw_min,
        "saw",ciaaw_saw_Tc_2021.saw,
        "saw_u",ciaaw_saw_Tc_2021.saw_u,
        "asaw",ciaaw_saw_Tc_2021.asaw,
        "asaw_u",ciaaw_saw_Tc_2021.asaw_u
    );
    PyDict_SetItemString(d, "Tc", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ru_2021.element,
        "symbol",ciaaw_saw_Ru_2021.symbol,
        "z",ciaaw_saw_Ru_2021.z,
        "saw_max",ciaaw_saw_Ru_2021.saw_max,
        "saw_min",ciaaw_saw_Ru_2021.saw_min,
        "saw",ciaaw_saw_Ru_2021.saw,
        "saw_u",ciaaw_saw_Ru_2021.saw_u,
        "asaw",ciaaw_saw_Ru_2021.asaw,
        "asaw_u",ciaaw_saw_Ru_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ru", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Rh_2021.element,
        "symbol",ciaaw_saw_Rh_2021.symbol,
        "z",ciaaw_saw_Rh_2021.z,
        "saw_max",ciaaw_saw_Rh_2021.saw_max,
        "saw_min",ciaaw_saw_Rh_2021.saw_min,
        "saw",ciaaw_saw_Rh_2021.saw,
        "saw_u",ciaaw_saw_Rh_2021.saw_u,
        "asaw",ciaaw_saw_Rh_2021.asaw,
        "asaw_u",ciaaw_saw_Rh_2021.asaw_u
    );
    PyDict_SetItemString(d, "Rh", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Pd_2021.element,
        "symbol",ciaaw_saw_Pd_2021.symbol,
        "z",ciaaw_saw_Pd_2021.z,
        "saw_max",ciaaw_saw_Pd_2021.saw_max,
        "saw_min",ciaaw_saw_Pd_2021.saw_min,
        "saw",ciaaw_saw_Pd_2021.saw,
        "saw_u",ciaaw_saw_Pd_2021.saw_u,
        "asaw",ciaaw_saw_Pd_2021.asaw,
        "asaw_u",ciaaw_saw_Pd_2021.asaw_u
    );
    PyDict_SetItemString(d, "Pd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ag_2021.element,
        "symbol",ciaaw_saw_Ag_2021.symbol,
        "z",ciaaw_saw_Ag_2021.z,
        "saw_max",ciaaw_saw_Ag_2021.saw_max,
        "saw_min",ciaaw_saw_Ag_2021.saw_min,
        "saw",ciaaw_saw_Ag_2021.saw,
        "saw_u",ciaaw_saw_Ag_2021.saw_u,
        "asaw",ciaaw_saw_Ag_2021.asaw,
        "asaw_u",ciaaw_saw_Ag_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ag", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cd_2021.element,
        "symbol",ciaaw_saw_Cd_2021.symbol,
        "z",ciaaw_saw_Cd_2021.z,
        "saw_max",ciaaw_saw_Cd_2021.saw_max,
        "saw_min",ciaaw_saw_Cd_2021.saw_min,
        "saw",ciaaw_saw_Cd_2021.saw,
        "saw_u",ciaaw_saw_Cd_2021.saw_u,
        "asaw",ciaaw_saw_Cd_2021.asaw,
        "asaw_u",ciaaw_saw_Cd_2021.asaw_u
    );
    PyDict_SetItemString(d, "Cd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_In_2021.element,
        "symbol",ciaaw_saw_In_2021.symbol,
        "z",ciaaw_saw_In_2021.z,
        "saw_max",ciaaw_saw_In_2021.saw_max,
        "saw_min",ciaaw_saw_In_2021.saw_min,
        "saw",ciaaw_saw_In_2021.saw,
        "saw_u",ciaaw_saw_In_2021.saw_u,
        "asaw",ciaaw_saw_In_2021.asaw,
        "asaw_u",ciaaw_saw_In_2021.asaw_u
    );
    PyDict_SetItemString(d, "In", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sn_2021.element,
        "symbol",ciaaw_saw_Sn_2021.symbol,
        "z",ciaaw_saw_Sn_2021.z,
        "saw_max",ciaaw_saw_Sn_2021.saw_max,
        "saw_min",ciaaw_saw_Sn_2021.saw_min,
        "saw",ciaaw_saw_Sn_2021.saw,
        "saw_u",ciaaw_saw_Sn_2021.saw_u,
        "asaw",ciaaw_saw_Sn_2021.asaw,
        "asaw_u",ciaaw_saw_Sn_2021.asaw_u
    );
    PyDict_SetItemString(d, "Sn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sb_2021.element,
        "symbol",ciaaw_saw_Sb_2021.symbol,
        "z",ciaaw_saw_Sb_2021.z,
        "saw_max",ciaaw_saw_Sb_2021.saw_max,
        "saw_min",ciaaw_saw_Sb_2021.saw_min,
        "saw",ciaaw_saw_Sb_2021.saw,
        "saw_u",ciaaw_saw_Sb_2021.saw_u,
        "asaw",ciaaw_saw_Sb_2021.asaw,
        "asaw_u",ciaaw_saw_Sb_2021.asaw_u
    );
    PyDict_SetItemString(d, "Sb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Te_2021.element,
        "symbol",ciaaw_saw_Te_2021.symbol,
        "z",ciaaw_saw_Te_2021.z,
        "saw_max",ciaaw_saw_Te_2021.saw_max,
        "saw_min",ciaaw_saw_Te_2021.saw_min,
        "saw",ciaaw_saw_Te_2021.saw,
        "saw_u",ciaaw_saw_Te_2021.saw_u,
        "asaw",ciaaw_saw_Te_2021.asaw,
        "asaw_u",ciaaw_saw_Te_2021.asaw_u
    );
    PyDict_SetItemString(d, "Te", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_I_2021.element,
        "symbol",ciaaw_saw_I_2021.symbol,
        "z",ciaaw_saw_I_2021.z,
        "saw_max",ciaaw_saw_I_2021.saw_max,
        "saw_min",ciaaw_saw_I_2021.saw_min,
        "saw",ciaaw_saw_I_2021.saw,
        "saw_u",ciaaw_saw_I_2021.saw_u,
        "asaw",ciaaw_saw_I_2021.asaw,
        "asaw_u",ciaaw_saw_I_2021.asaw_u
    );
    PyDict_SetItemString(d, "I", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Xe_2021.element,
        "symbol",ciaaw_saw_Xe_2021.symbol,
        "z",ciaaw_saw_Xe_2021.z,
        "saw_max",ciaaw_saw_Xe_2021.saw_max,
        "saw_min",ciaaw_saw_Xe_2021.saw_min,
        "saw",ciaaw_saw_Xe_2021.saw,
        "saw_u",ciaaw_saw_Xe_2021.saw_u,
        "asaw",ciaaw_saw_Xe_2021.asaw,
        "asaw_u",ciaaw_saw_Xe_2021.asaw_u
    );
    PyDict_SetItemString(d, "Xe", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cs_2021.element,
        "symbol",ciaaw_saw_Cs_2021.symbol,
        "z",ciaaw_saw_Cs_2021.z,
        "saw_max",ciaaw_saw_Cs_2021.saw_max,
        "saw_min",ciaaw_saw_Cs_2021.saw_min,
        "saw",ciaaw_saw_Cs_2021.saw,
        "saw_u",ciaaw_saw_Cs_2021.saw_u,
        "asaw",ciaaw_saw_Cs_2021.asaw,
        "asaw_u",ciaaw_saw_Cs_2021.asaw_u
    );
    PyDict_SetItemString(d, "Cs", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ba_2021.element,
        "symbol",ciaaw_saw_Ba_2021.symbol,
        "z",ciaaw_saw_Ba_2021.z,
        "saw_max",ciaaw_saw_Ba_2021.saw_max,
        "saw_min",ciaaw_saw_Ba_2021.saw_min,
        "saw",ciaaw_saw_Ba_2021.saw,
        "saw_u",ciaaw_saw_Ba_2021.saw_u,
        "asaw",ciaaw_saw_Ba_2021.asaw,
        "asaw_u",ciaaw_saw_Ba_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ba", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_La_2021.element,
        "symbol",ciaaw_saw_La_2021.symbol,
        "z",ciaaw_saw_La_2021.z,
        "saw_max",ciaaw_saw_La_2021.saw_max,
        "saw_min",ciaaw_saw_La_2021.saw_min,
        "saw",ciaaw_saw_La_2021.saw,
        "saw_u",ciaaw_saw_La_2021.saw_u,
        "asaw",ciaaw_saw_La_2021.asaw,
        "asaw_u",ciaaw_saw_La_2021.asaw_u
    );
    PyDict_SetItemString(d, "La", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ce_2021.element,
        "symbol",ciaaw_saw_Ce_2021.symbol,
        "z",ciaaw_saw_Ce_2021.z,
        "saw_max",ciaaw_saw_Ce_2021.saw_max,
        "saw_min",ciaaw_saw_Ce_2021.saw_min,
        "saw",ciaaw_saw_Ce_2021.saw,
        "saw_u",ciaaw_saw_Ce_2021.saw_u,
        "asaw",ciaaw_saw_Ce_2021.asaw,
        "asaw_u",ciaaw_saw_Ce_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ce", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Pr_2021.element,
        "symbol",ciaaw_saw_Pr_2021.symbol,
        "z",ciaaw_saw_Pr_2021.z,
        "saw_max",ciaaw_saw_Pr_2021.saw_max,
        "saw_min",ciaaw_saw_Pr_2021.saw_min,
        "saw",ciaaw_saw_Pr_2021.saw,
        "saw_u",ciaaw_saw_Pr_2021.saw_u,
        "asaw",ciaaw_saw_Pr_2021.asaw,
        "asaw_u",ciaaw_saw_Pr_2021.asaw_u
    );
    PyDict_SetItemString(d, "Pr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Nd_2021.element,
        "symbol",ciaaw_saw_Nd_2021.symbol,
        "z",ciaaw_saw_Nd_2021.z,
        "saw_max",ciaaw_saw_Nd_2021.saw_max,
        "saw_min",ciaaw_saw_Nd_2021.saw_min,
        "saw",ciaaw_saw_Nd_2021.saw,
        "saw_u",ciaaw_saw_Nd_2021.saw_u,
        "asaw",ciaaw_saw_Nd_2021.asaw,
        "asaw_u",ciaaw_saw_Nd_2021.asaw_u
    );
    PyDict_SetItemString(d, "Nd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Pm_2021.element,
        "symbol",ciaaw_saw_Pm_2021.symbol,
        "z",ciaaw_saw_Pm_2021.z,
        "saw_max",ciaaw_saw_Pm_2021.saw_max,
        "saw_min",ciaaw_saw_Pm_2021.saw_min,
        "saw",ciaaw_saw_Pm_2021.saw,
        "saw_u",ciaaw_saw_Pm_2021.saw_u,
        "asaw",ciaaw_saw_Pm_2021.asaw,
        "asaw_u",ciaaw_saw_Pm_2021.asaw_u
    );
    PyDict_SetItemString(d, "Pm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sm_2021.element,
        "symbol",ciaaw_saw_Sm_2021.symbol,
        "z",ciaaw_saw_Sm_2021.z,
        "saw_max",ciaaw_saw_Sm_2021.saw_max,
        "saw_min",ciaaw_saw_Sm_2021.saw_min,
        "saw",ciaaw_saw_Sm_2021.saw,
        "saw_u",ciaaw_saw_Sm_2021.saw_u,
        "asaw",ciaaw_saw_Sm_2021.asaw,
        "asaw_u",ciaaw_saw_Sm_2021.asaw_u
    );
    PyDict_SetItemString(d, "Sm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Eu_2021.element,
        "symbol",ciaaw_saw_Eu_2021.symbol,
        "z",ciaaw_saw_Eu_2021.z,
        "saw_max",ciaaw_saw_Eu_2021.saw_max,
        "saw_min",ciaaw_saw_Eu_2021.saw_min,
        "saw",ciaaw_saw_Eu_2021.saw,
        "saw_u",ciaaw_saw_Eu_2021.saw_u,
        "asaw",ciaaw_saw_Eu_2021.asaw,
        "asaw_u",ciaaw_saw_Eu_2021.asaw_u
    );
    PyDict_SetItemString(d, "Eu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Gd_2021.element,
        "symbol",ciaaw_saw_Gd_2021.symbol,
        "z",ciaaw_saw_Gd_2021.z,
        "saw_max",ciaaw_saw_Gd_2021.saw_max,
        "saw_min",ciaaw_saw_Gd_2021.saw_min,
        "saw",ciaaw_saw_Gd_2021.saw,
        "saw_u",ciaaw_saw_Gd_2021.saw_u,
        "asaw",ciaaw_saw_Gd_2021.asaw,
        "asaw_u",ciaaw_saw_Gd_2021.asaw_u
    );
    PyDict_SetItemString(d, "Gd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Tb_2021.element,
        "symbol",ciaaw_saw_Tb_2021.symbol,
        "z",ciaaw_saw_Tb_2021.z,
        "saw_max",ciaaw_saw_Tb_2021.saw_max,
        "saw_min",ciaaw_saw_Tb_2021.saw_min,
        "saw",ciaaw_saw_Tb_2021.saw,
        "saw_u",ciaaw_saw_Tb_2021.saw_u,
        "asaw",ciaaw_saw_Tb_2021.asaw,
        "asaw_u",ciaaw_saw_Tb_2021.asaw_u
    );
    PyDict_SetItemString(d, "Tb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Dy_2021.element,
        "symbol",ciaaw_saw_Dy_2021.symbol,
        "z",ciaaw_saw_Dy_2021.z,
        "saw_max",ciaaw_saw_Dy_2021.saw_max,
        "saw_min",ciaaw_saw_Dy_2021.saw_min,
        "saw",ciaaw_saw_Dy_2021.saw,
        "saw_u",ciaaw_saw_Dy_2021.saw_u,
        "asaw",ciaaw_saw_Dy_2021.asaw,
        "asaw_u",ciaaw_saw_Dy_2021.asaw_u
    );
    PyDict_SetItemString(d, "Dy", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ho_2021.element,
        "symbol",ciaaw_saw_Ho_2021.symbol,
        "z",ciaaw_saw_Ho_2021.z,
        "saw_max",ciaaw_saw_Ho_2021.saw_max,
        "saw_min",ciaaw_saw_Ho_2021.saw_min,
        "saw",ciaaw_saw_Ho_2021.saw,
        "saw_u",ciaaw_saw_Ho_2021.saw_u,
        "asaw",ciaaw_saw_Ho_2021.asaw,
        "asaw_u",ciaaw_saw_Ho_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ho", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Er_2021.element,
        "symbol",ciaaw_saw_Er_2021.symbol,
        "z",ciaaw_saw_Er_2021.z,
        "saw_max",ciaaw_saw_Er_2021.saw_max,
        "saw_min",ciaaw_saw_Er_2021.saw_min,
        "saw",ciaaw_saw_Er_2021.saw,
        "saw_u",ciaaw_saw_Er_2021.saw_u,
        "asaw",ciaaw_saw_Er_2021.asaw,
        "asaw_u",ciaaw_saw_Er_2021.asaw_u
    );
    PyDict_SetItemString(d, "Er", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Tm_2021.element,
        "symbol",ciaaw_saw_Tm_2021.symbol,
        "z",ciaaw_saw_Tm_2021.z,
        "saw_max",ciaaw_saw_Tm_2021.saw_max,
        "saw_min",ciaaw_saw_Tm_2021.saw_min,
        "saw",ciaaw_saw_Tm_2021.saw,
        "saw_u",ciaaw_saw_Tm_2021.saw_u,
        "asaw",ciaaw_saw_Tm_2021.asaw,
        "asaw_u",ciaaw_saw_Tm_2021.asaw_u
    );
    PyDict_SetItemString(d, "Tm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Yb_2021.element,
        "symbol",ciaaw_saw_Yb_2021.symbol,
        "z",ciaaw_saw_Yb_2021.z,
        "saw_max",ciaaw_saw_Yb_2021.saw_max,
        "saw_min",ciaaw_saw_Yb_2021.saw_min,
        "saw",ciaaw_saw_Yb_2021.saw,
        "saw_u",ciaaw_saw_Yb_2021.saw_u,
        "asaw",ciaaw_saw_Yb_2021.asaw,
        "asaw_u",ciaaw_saw_Yb_2021.asaw_u
    );
    PyDict_SetItemString(d, "Yb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Lu_2021.element,
        "symbol",ciaaw_saw_Lu_2021.symbol,
        "z",ciaaw_saw_Lu_2021.z,
        "saw_max",ciaaw_saw_Lu_2021.saw_max,
        "saw_min",ciaaw_saw_Lu_2021.saw_min,
        "saw",ciaaw_saw_Lu_2021.saw,
        "saw_u",ciaaw_saw_Lu_2021.saw_u,
        "asaw",ciaaw_saw_Lu_2021.asaw,
        "asaw_u",ciaaw_saw_Lu_2021.asaw_u
    );
    PyDict_SetItemString(d, "Lu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Hf_2021.element,
        "symbol",ciaaw_saw_Hf_2021.symbol,
        "z",ciaaw_saw_Hf_2021.z,
        "saw_max",ciaaw_saw_Hf_2021.saw_max,
        "saw_min",ciaaw_saw_Hf_2021.saw_min,
        "saw",ciaaw_saw_Hf_2021.saw,
        "saw_u",ciaaw_saw_Hf_2021.saw_u,
        "asaw",ciaaw_saw_Hf_2021.asaw,
        "asaw_u",ciaaw_saw_Hf_2021.asaw_u
    );
    PyDict_SetItemString(d, "Hf", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ta_2021.element,
        "symbol",ciaaw_saw_Ta_2021.symbol,
        "z",ciaaw_saw_Ta_2021.z,
        "saw_max",ciaaw_saw_Ta_2021.saw_max,
        "saw_min",ciaaw_saw_Ta_2021.saw_min,
        "saw",ciaaw_saw_Ta_2021.saw,
        "saw_u",ciaaw_saw_Ta_2021.saw_u,
        "asaw",ciaaw_saw_Ta_2021.asaw,
        "asaw_u",ciaaw_saw_Ta_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ta", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_W_2021.element,
        "symbol",ciaaw_saw_W_2021.symbol,
        "z",ciaaw_saw_W_2021.z,
        "saw_max",ciaaw_saw_W_2021.saw_max,
        "saw_min",ciaaw_saw_W_2021.saw_min,
        "saw",ciaaw_saw_W_2021.saw,
        "saw_u",ciaaw_saw_W_2021.saw_u,
        "asaw",ciaaw_saw_W_2021.asaw,
        "asaw_u",ciaaw_saw_W_2021.asaw_u
    );
    PyDict_SetItemString(d, "W", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Re_2021.element,
        "symbol",ciaaw_saw_Re_2021.symbol,
        "z",ciaaw_saw_Re_2021.z,
        "saw_max",ciaaw_saw_Re_2021.saw_max,
        "saw_min",ciaaw_saw_Re_2021.saw_min,
        "saw",ciaaw_saw_Re_2021.saw,
        "saw_u",ciaaw_saw_Re_2021.saw_u,
        "asaw",ciaaw_saw_Re_2021.asaw,
        "asaw_u",ciaaw_saw_Re_2021.asaw_u
    );
    PyDict_SetItemString(d, "Re", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Os_2021.element,
        "symbol",ciaaw_saw_Os_2021.symbol,
        "z",ciaaw_saw_Os_2021.z,
        "saw_max",ciaaw_saw_Os_2021.saw_max,
        "saw_min",ciaaw_saw_Os_2021.saw_min,
        "saw",ciaaw_saw_Os_2021.saw,
        "saw_u",ciaaw_saw_Os_2021.saw_u,
        "asaw",ciaaw_saw_Os_2021.asaw,
        "asaw_u",ciaaw_saw_Os_2021.asaw_u
    );
    PyDict_SetItemString(d, "Os", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ir_2021.element,
        "symbol",ciaaw_saw_Ir_2021.symbol,
        "z",ciaaw_saw_Ir_2021.z,
        "saw_max",ciaaw_saw_Ir_2021.saw_max,
        "saw_min",ciaaw_saw_Ir_2021.saw_min,
        "saw",ciaaw_saw_Ir_2021.saw,
        "saw_u",ciaaw_saw_Ir_2021.saw_u,
        "asaw",ciaaw_saw_Ir_2021.asaw,
        "asaw_u",ciaaw_saw_Ir_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ir", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Pt_2021.element,
        "symbol",ciaaw_saw_Pt_2021.symbol,
        "z",ciaaw_saw_Pt_2021.z,
        "saw_max",ciaaw_saw_Pt_2021.saw_max,
        "saw_min",ciaaw_saw_Pt_2021.saw_min,
        "saw",ciaaw_saw_Pt_2021.saw,
        "saw_u",ciaaw_saw_Pt_2021.saw_u,
        "asaw",ciaaw_saw_Pt_2021.asaw,
        "asaw_u",ciaaw_saw_Pt_2021.asaw_u
    );
    PyDict_SetItemString(d, "Pt", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Au_2021.element,
        "symbol",ciaaw_saw_Au_2021.symbol,
        "z",ciaaw_saw_Au_2021.z,
        "saw_max",ciaaw_saw_Au_2021.saw_max,
        "saw_min",ciaaw_saw_Au_2021.saw_min,
        "saw",ciaaw_saw_Au_2021.saw,
        "saw_u",ciaaw_saw_Au_2021.saw_u,
        "asaw",ciaaw_saw_Au_2021.asaw,
        "asaw_u",ciaaw_saw_Au_2021.asaw_u
    );
    PyDict_SetItemString(d, "Au", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Hg_2021.element,
        "symbol",ciaaw_saw_Hg_2021.symbol,
        "z",ciaaw_saw_Hg_2021.z,
        "saw_max",ciaaw_saw_Hg_2021.saw_max,
        "saw_min",ciaaw_saw_Hg_2021.saw_min,
        "saw",ciaaw_saw_Hg_2021.saw,
        "saw_u",ciaaw_saw_Hg_2021.saw_u,
        "asaw",ciaaw_saw_Hg_2021.asaw,
        "asaw_u",ciaaw_saw_Hg_2021.asaw_u
    );
    PyDict_SetItemString(d, "Hg", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Tl_2021.element,
        "symbol",ciaaw_saw_Tl_2021.symbol,
        "z",ciaaw_saw_Tl_2021.z,
        "saw_max",ciaaw_saw_Tl_2021.saw_max,
        "saw_min",ciaaw_saw_Tl_2021.saw_min,
        "saw",ciaaw_saw_Tl_2021.saw,
        "saw_u",ciaaw_saw_Tl_2021.saw_u,
        "asaw",ciaaw_saw_Tl_2021.asaw,
        "asaw_u",ciaaw_saw_Tl_2021.asaw_u
    );
    PyDict_SetItemString(d, "Tl", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Pb_2021.element,
        "symbol",ciaaw_saw_Pb_2021.symbol,
        "z",ciaaw_saw_Pb_2021.z,
        "saw_max",ciaaw_saw_Pb_2021.saw_max,
        "saw_min",ciaaw_saw_Pb_2021.saw_min,
        "saw",ciaaw_saw_Pb_2021.saw,
        "saw_u",ciaaw_saw_Pb_2021.saw_u,
        "asaw",ciaaw_saw_Pb_2021.asaw,
        "asaw_u",ciaaw_saw_Pb_2021.asaw_u
    );
    PyDict_SetItemString(d, "Pb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Bi_2021.element,
        "symbol",ciaaw_saw_Bi_2021.symbol,
        "z",ciaaw_saw_Bi_2021.z,
        "saw_max",ciaaw_saw_Bi_2021.saw_max,
        "saw_min",ciaaw_saw_Bi_2021.saw_min,
        "saw",ciaaw_saw_Bi_2021.saw,
        "saw_u",ciaaw_saw_Bi_2021.saw_u,
        "asaw",ciaaw_saw_Bi_2021.asaw,
        "asaw_u",ciaaw_saw_Bi_2021.asaw_u
    );
    PyDict_SetItemString(d, "Bi", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Po_2021.element,
        "symbol",ciaaw_saw_Po_2021.symbol,
        "z",ciaaw_saw_Po_2021.z,
        "saw_max",ciaaw_saw_Po_2021.saw_max,
        "saw_min",ciaaw_saw_Po_2021.saw_min,
        "saw",ciaaw_saw_Po_2021.saw,
        "saw_u",ciaaw_saw_Po_2021.saw_u,
        "asaw",ciaaw_saw_Po_2021.asaw,
        "asaw_u",ciaaw_saw_Po_2021.asaw_u
    );
    PyDict_SetItemString(d, "Po", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_At_2021.element,
        "symbol",ciaaw_saw_At_2021.symbol,
        "z",ciaaw_saw_At_2021.z,
        "saw_max",ciaaw_saw_At_2021.saw_max,
        "saw_min",ciaaw_saw_At_2021.saw_min,
        "saw",ciaaw_saw_At_2021.saw,
        "saw_u",ciaaw_saw_At_2021.saw_u,
        "asaw",ciaaw_saw_At_2021.asaw,
        "asaw_u",ciaaw_saw_At_2021.asaw_u
    );
    PyDict_SetItemString(d, "At", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Rn_2021.element,
        "symbol",ciaaw_saw_Rn_2021.symbol,
        "z",ciaaw_saw_Rn_2021.z,
        "saw_max",ciaaw_saw_Rn_2021.saw_max,
        "saw_min",ciaaw_saw_Rn_2021.saw_min,
        "saw",ciaaw_saw_Rn_2021.saw,
        "saw_u",ciaaw_saw_Rn_2021.saw_u,
        "asaw",ciaaw_saw_Rn_2021.asaw,
        "asaw_u",ciaaw_saw_Rn_2021.asaw_u
    );
    PyDict_SetItemString(d, "Rn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Fr_2021.element,
        "symbol",ciaaw_saw_Fr_2021.symbol,
        "z",ciaaw_saw_Fr_2021.z,
        "saw_max",ciaaw_saw_Fr_2021.saw_max,
        "saw_min",ciaaw_saw_Fr_2021.saw_min,
        "saw",ciaaw_saw_Fr_2021.saw,
        "saw_u",ciaaw_saw_Fr_2021.saw_u,
        "asaw",ciaaw_saw_Fr_2021.asaw,
        "asaw_u",ciaaw_saw_Fr_2021.asaw_u
    );
    PyDict_SetItemString(d, "Fr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ra_2021.element,
        "symbol",ciaaw_saw_Ra_2021.symbol,
        "z",ciaaw_saw_Ra_2021.z,
        "saw_max",ciaaw_saw_Ra_2021.saw_max,
        "saw_min",ciaaw_saw_Ra_2021.saw_min,
        "saw",ciaaw_saw_Ra_2021.saw,
        "saw_u",ciaaw_saw_Ra_2021.saw_u,
        "asaw",ciaaw_saw_Ra_2021.asaw,
        "asaw_u",ciaaw_saw_Ra_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ra", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ac_2021.element,
        "symbol",ciaaw_saw_Ac_2021.symbol,
        "z",ciaaw_saw_Ac_2021.z,
        "saw_max",ciaaw_saw_Ac_2021.saw_max,
        "saw_min",ciaaw_saw_Ac_2021.saw_min,
        "saw",ciaaw_saw_Ac_2021.saw,
        "saw_u",ciaaw_saw_Ac_2021.saw_u,
        "asaw",ciaaw_saw_Ac_2021.asaw,
        "asaw_u",ciaaw_saw_Ac_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ac", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Th_2021.element,
        "symbol",ciaaw_saw_Th_2021.symbol,
        "z",ciaaw_saw_Th_2021.z,
        "saw_max",ciaaw_saw_Th_2021.saw_max,
        "saw_min",ciaaw_saw_Th_2021.saw_min,
        "saw",ciaaw_saw_Th_2021.saw,
        "saw_u",ciaaw_saw_Th_2021.saw_u,
        "asaw",ciaaw_saw_Th_2021.asaw,
        "asaw_u",ciaaw_saw_Th_2021.asaw_u
    );
    PyDict_SetItemString(d, "Th", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Pa_2021.element,
        "symbol",ciaaw_saw_Pa_2021.symbol,
        "z",ciaaw_saw_Pa_2021.z,
        "saw_max",ciaaw_saw_Pa_2021.saw_max,
        "saw_min",ciaaw_saw_Pa_2021.saw_min,
        "saw",ciaaw_saw_Pa_2021.saw,
        "saw_u",ciaaw_saw_Pa_2021.saw_u,
        "asaw",ciaaw_saw_Pa_2021.asaw,
        "asaw_u",ciaaw_saw_Pa_2021.asaw_u
    );
    PyDict_SetItemString(d, "Pa", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_U_2021.element,
        "symbol",ciaaw_saw_U_2021.symbol,
        "z",ciaaw_saw_U_2021.z,
        "saw_max",ciaaw_saw_U_2021.saw_max,
        "saw_min",ciaaw_saw_U_2021.saw_min,
        "saw",ciaaw_saw_U_2021.saw,
        "saw_u",ciaaw_saw_U_2021.saw_u,
        "asaw",ciaaw_saw_U_2021.asaw,
        "asaw_u",ciaaw_saw_U_2021.asaw_u
    );
    PyDict_SetItemString(d, "U", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Np_2021.element,
        "symbol",ciaaw_saw_Np_2021.symbol,
        "z",ciaaw_saw_Np_2021.z,
        "saw_max",ciaaw_saw_Np_2021.saw_max,
        "saw_min",ciaaw_saw_Np_2021.saw_min,
        "saw",ciaaw_saw_Np_2021.saw,
        "saw_u",ciaaw_saw_Np_2021.saw_u,
        "asaw",ciaaw_saw_Np_2021.asaw,
        "asaw_u",ciaaw_saw_Np_2021.asaw_u
    );
    PyDict_SetItemString(d, "Np", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Pu_2021.element,
        "symbol",ciaaw_saw_Pu_2021.symbol,
        "z",ciaaw_saw_Pu_2021.z,
        "saw_max",ciaaw_saw_Pu_2021.saw_max,
        "saw_min",ciaaw_saw_Pu_2021.saw_min,
        "saw",ciaaw_saw_Pu_2021.saw,
        "saw_u",ciaaw_saw_Pu_2021.saw_u,
        "asaw",ciaaw_saw_Pu_2021.asaw,
        "asaw_u",ciaaw_saw_Pu_2021.asaw_u
    );
    PyDict_SetItemString(d, "Pu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Am_2021.element,
        "symbol",ciaaw_saw_Am_2021.symbol,
        "z",ciaaw_saw_Am_2021.z,
        "saw_max",ciaaw_saw_Am_2021.saw_max,
        "saw_min",ciaaw_saw_Am_2021.saw_min,
        "saw",ciaaw_saw_Am_2021.saw,
        "saw_u",ciaaw_saw_Am_2021.saw_u,
        "asaw",ciaaw_saw_Am_2021.asaw,
        "asaw_u",ciaaw_saw_Am_2021.asaw_u
    );
    PyDict_SetItemString(d, "Am", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cm_2021.element,
        "symbol",ciaaw_saw_Cm_2021.symbol,
        "z",ciaaw_saw_Cm_2021.z,
        "saw_max",ciaaw_saw_Cm_2021.saw_max,
        "saw_min",ciaaw_saw_Cm_2021.saw_min,
        "saw",ciaaw_saw_Cm_2021.saw,
        "saw_u",ciaaw_saw_Cm_2021.saw_u,
        "asaw",ciaaw_saw_Cm_2021.asaw,
        "asaw_u",ciaaw_saw_Cm_2021.asaw_u
    );
    PyDict_SetItemString(d, "Cm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Bk_2021.element,
        "symbol",ciaaw_saw_Bk_2021.symbol,
        "z",ciaaw_saw_Bk_2021.z,
        "saw_max",ciaaw_saw_Bk_2021.saw_max,
        "saw_min",ciaaw_saw_Bk_2021.saw_min,
        "saw",ciaaw_saw_Bk_2021.saw,
        "saw_u",ciaaw_saw_Bk_2021.saw_u,
        "asaw",ciaaw_saw_Bk_2021.asaw,
        "asaw_u",ciaaw_saw_Bk_2021.asaw_u
    );
    PyDict_SetItemString(d, "Bk", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cf_2021.element,
        "symbol",ciaaw_saw_Cf_2021.symbol,
        "z",ciaaw_saw_Cf_2021.z,
        "saw_max",ciaaw_saw_Cf_2021.saw_max,
        "saw_min",ciaaw_saw_Cf_2021.saw_min,
        "saw",ciaaw_saw_Cf_2021.saw,
        "saw_u",ciaaw_saw_Cf_2021.saw_u,
        "asaw",ciaaw_saw_Cf_2021.asaw,
        "asaw_u",ciaaw_saw_Cf_2021.asaw_u
    );
    PyDict_SetItemString(d, "Cf", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Es_2021.element,
        "symbol",ciaaw_saw_Es_2021.symbol,
        "z",ciaaw_saw_Es_2021.z,
        "saw_max",ciaaw_saw_Es_2021.saw_max,
        "saw_min",ciaaw_saw_Es_2021.saw_min,
        "saw",ciaaw_saw_Es_2021.saw,
        "saw_u",ciaaw_saw_Es_2021.saw_u,
        "asaw",ciaaw_saw_Es_2021.asaw,
        "asaw_u",ciaaw_saw_Es_2021.asaw_u
    );
    PyDict_SetItemString(d, "Es", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Fm_2021.element,
        "symbol",ciaaw_saw_Fm_2021.symbol,
        "z",ciaaw_saw_Fm_2021.z,
        "saw_max",ciaaw_saw_Fm_2021.saw_max,
        "saw_min",ciaaw_saw_Fm_2021.saw_min,
        "saw",ciaaw_saw_Fm_2021.saw,
        "saw_u",ciaaw_saw_Fm_2021.saw_u,
        "asaw",ciaaw_saw_Fm_2021.asaw,
        "asaw_u",ciaaw_saw_Fm_2021.asaw_u
    );
    PyDict_SetItemString(d, "Fm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Md_2021.element,
        "symbol",ciaaw_saw_Md_2021.symbol,
        "z",ciaaw_saw_Md_2021.z,
        "saw_max",ciaaw_saw_Md_2021.saw_max,
        "saw_min",ciaaw_saw_Md_2021.saw_min,
        "saw",ciaaw_saw_Md_2021.saw,
        "saw_u",ciaaw_saw_Md_2021.saw_u,
        "asaw",ciaaw_saw_Md_2021.asaw,
        "asaw_u",ciaaw_saw_Md_2021.asaw_u
    );
    PyDict_SetItemString(d, "Md", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_No_2021.element,
        "symbol",ciaaw_saw_No_2021.symbol,
        "z",ciaaw_saw_No_2021.z,
        "saw_max",ciaaw_saw_No_2021.saw_max,
        "saw_min",ciaaw_saw_No_2021.saw_min,
        "saw",ciaaw_saw_No_2021.saw,
        "saw_u",ciaaw_saw_No_2021.saw_u,
        "asaw",ciaaw_saw_No_2021.asaw,
        "asaw_u",ciaaw_saw_No_2021.asaw_u
    );
    PyDict_SetItemString(d, "No", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Lr_2021.element,
        "symbol",ciaaw_saw_Lr_2021.symbol,
        "z",ciaaw_saw_Lr_2021.z,
        "saw_max",ciaaw_saw_Lr_2021.saw_max,
        "saw_min",ciaaw_saw_Lr_2021.saw_min,
        "saw",ciaaw_saw_Lr_2021.saw,
        "saw_u",ciaaw_saw_Lr_2021.saw_u,
        "asaw",ciaaw_saw_Lr_2021.asaw,
        "asaw_u",ciaaw_saw_Lr_2021.asaw_u
    );
    PyDict_SetItemString(d, "Lr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Rf_2021.element,
        "symbol",ciaaw_saw_Rf_2021.symbol,
        "z",ciaaw_saw_Rf_2021.z,
        "saw_max",ciaaw_saw_Rf_2021.saw_max,
        "saw_min",ciaaw_saw_Rf_2021.saw_min,
        "saw",ciaaw_saw_Rf_2021.saw,
        "saw_u",ciaaw_saw_Rf_2021.saw_u,
        "asaw",ciaaw_saw_Rf_2021.asaw,
        "asaw_u",ciaaw_saw_Rf_2021.asaw_u
    );
    PyDict_SetItemString(d, "Rf", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Db_2021.element,
        "symbol",ciaaw_saw_Db_2021.symbol,
        "z",ciaaw_saw_Db_2021.z,
        "saw_max",ciaaw_saw_Db_2021.saw_max,
        "saw_min",ciaaw_saw_Db_2021.saw_min,
        "saw",ciaaw_saw_Db_2021.saw,
        "saw_u",ciaaw_saw_Db_2021.saw_u,
        "asaw",ciaaw_saw_Db_2021.asaw,
        "asaw_u",ciaaw_saw_Db_2021.asaw_u
    );
    PyDict_SetItemString(d, "Db", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sg_2021.element,
        "symbol",ciaaw_saw_Sg_2021.symbol,
        "z",ciaaw_saw_Sg_2021.z,
        "saw_max",ciaaw_saw_Sg_2021.saw_max,
        "saw_min",ciaaw_saw_Sg_2021.saw_min,
        "saw",ciaaw_saw_Sg_2021.saw,
        "saw_u",ciaaw_saw_Sg_2021.saw_u,
        "asaw",ciaaw_saw_Sg_2021.asaw,
        "asaw_u",ciaaw_saw_Sg_2021.asaw_u
    );
    PyDict_SetItemString(d, "Sg", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Bh_2021.element,
        "symbol",ciaaw_saw_Bh_2021.symbol,
        "z",ciaaw_saw_Bh_2021.z,
        "saw_max",ciaaw_saw_Bh_2021.saw_max,
        "saw_min",ciaaw_saw_Bh_2021.saw_min,
        "saw",ciaaw_saw_Bh_2021.saw,
        "saw_u",ciaaw_saw_Bh_2021.saw_u,
        "asaw",ciaaw_saw_Bh_2021.asaw,
        "asaw_u",ciaaw_saw_Bh_2021.asaw_u
    );
    PyDict_SetItemString(d, "Bh", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Hs_2021.element,
        "symbol",ciaaw_saw_Hs_2021.symbol,
        "z",ciaaw_saw_Hs_2021.z,
        "saw_max",ciaaw_saw_Hs_2021.saw_max,
        "saw_min",ciaaw_saw_Hs_2021.saw_min,
        "saw",ciaaw_saw_Hs_2021.saw,
        "saw_u",ciaaw_saw_Hs_2021.saw_u,
        "asaw",ciaaw_saw_Hs_2021.asaw,
        "asaw_u",ciaaw_saw_Hs_2021.asaw_u
    );
    PyDict_SetItemString(d, "Hs", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Mt_2021.element,
        "symbol",ciaaw_saw_Mt_2021.symbol,
        "z",ciaaw_saw_Mt_2021.z,
        "saw_max",ciaaw_saw_Mt_2021.saw_max,
        "saw_min",ciaaw_saw_Mt_2021.saw_min,
        "saw",ciaaw_saw_Mt_2021.saw,
        "saw_u",ciaaw_saw_Mt_2021.saw_u,
        "asaw",ciaaw_saw_Mt_2021.asaw,
        "asaw_u",ciaaw_saw_Mt_2021.asaw_u
    );
    PyDict_SetItemString(d, "Mt", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ds_2021.element,
        "symbol",ciaaw_saw_Ds_2021.symbol,
        "z",ciaaw_saw_Ds_2021.z,
        "saw_max",ciaaw_saw_Ds_2021.saw_max,
        "saw_min",ciaaw_saw_Ds_2021.saw_min,
        "saw",ciaaw_saw_Ds_2021.saw,
        "saw_u",ciaaw_saw_Ds_2021.saw_u,
        "asaw",ciaaw_saw_Ds_2021.asaw,
        "asaw_u",ciaaw_saw_Ds_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ds", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Rg_2021.element,
        "symbol",ciaaw_saw_Rg_2021.symbol,
        "z",ciaaw_saw_Rg_2021.z,
        "saw_max",ciaaw_saw_Rg_2021.saw_max,
        "saw_min",ciaaw_saw_Rg_2021.saw_min,
        "saw",ciaaw_saw_Rg_2021.saw,
        "saw_u",ciaaw_saw_Rg_2021.saw_u,
        "asaw",ciaaw_saw_Rg_2021.asaw,
        "asaw_u",ciaaw_saw_Rg_2021.asaw_u
    );
    PyDict_SetItemString(d, "Rg", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cn_2021.element,
        "symbol",ciaaw_saw_Cn_2021.symbol,
        "z",ciaaw_saw_Cn_2021.z,
        "saw_max",ciaaw_saw_Cn_2021.saw_max,
        "saw_min",ciaaw_saw_Cn_2021.saw_min,
        "saw",ciaaw_saw_Cn_2021.saw,
        "saw_u",ciaaw_saw_Cn_2021.saw_u,
        "asaw",ciaaw_saw_Cn_2021.asaw,
        "asaw_u",ciaaw_saw_Cn_2021.asaw_u
    );
    PyDict_SetItemString(d, "Cn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Nh_2021.element,
        "symbol",ciaaw_saw_Nh_2021.symbol,
        "z",ciaaw_saw_Nh_2021.z,
        "saw_max",ciaaw_saw_Nh_2021.saw_max,
        "saw_min",ciaaw_saw_Nh_2021.saw_min,
        "saw",ciaaw_saw_Nh_2021.saw,
        "saw_u",ciaaw_saw_Nh_2021.saw_u,
        "asaw",ciaaw_saw_Nh_2021.asaw,
        "asaw_u",ciaaw_saw_Nh_2021.asaw_u
    );
    PyDict_SetItemString(d, "Nh", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Fl_2021.element,
        "symbol",ciaaw_saw_Fl_2021.symbol,
        "z",ciaaw_saw_Fl_2021.z,
        "saw_max",ciaaw_saw_Fl_2021.saw_max,
        "saw_min",ciaaw_saw_Fl_2021.saw_min,
        "saw",ciaaw_saw_Fl_2021.saw,
        "saw_u",ciaaw_saw_Fl_2021.saw_u,
        "asaw",ciaaw_saw_Fl_2021.asaw,
        "asaw_u",ciaaw_saw_Fl_2021.asaw_u
    );
    PyDict_SetItemString(d, "Fl", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Mc_2021.element,
        "symbol",ciaaw_saw_Mc_2021.symbol,
        "z",ciaaw_saw_Mc_2021.z,
        "saw_max",ciaaw_saw_Mc_2021.saw_max,
        "saw_min",ciaaw_saw_Mc_2021.saw_min,
        "saw",ciaaw_saw_Mc_2021.saw,
        "saw_u",ciaaw_saw_Mc_2021.saw_u,
        "asaw",ciaaw_saw_Mc_2021.asaw,
        "asaw_u",ciaaw_saw_Mc_2021.asaw_u
    );
    PyDict_SetItemString(d, "Mc", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Lv_2021.element,
        "symbol",ciaaw_saw_Lv_2021.symbol,
        "z",ciaaw_saw_Lv_2021.z,
        "saw_max",ciaaw_saw_Lv_2021.saw_max,
        "saw_min",ciaaw_saw_Lv_2021.saw_min,
        "saw",ciaaw_saw_Lv_2021.saw,
        "saw_u",ciaaw_saw_Lv_2021.saw_u,
        "asaw",ciaaw_saw_Lv_2021.asaw,
        "asaw_u",ciaaw_saw_Lv_2021.asaw_u
    );
    PyDict_SetItemString(d, "Lv", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ts_2021.element,
        "symbol",ciaaw_saw_Ts_2021.symbol,
        "z",ciaaw_saw_Ts_2021.z,
        "saw_max",ciaaw_saw_Ts_2021.saw_max,
        "saw_min",ciaaw_saw_Ts_2021.saw_min,
        "saw",ciaaw_saw_Ts_2021.saw,
        "saw_u",ciaaw_saw_Ts_2021.saw_u,
        "asaw",ciaaw_saw_Ts_2021.asaw,
        "asaw_u",ciaaw_saw_Ts_2021.asaw_u
    );
    PyDict_SetItemString(d, "Ts", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Og_2021.element,
        "symbol",ciaaw_saw_Og_2021.symbol,
        "z",ciaaw_saw_Og_2021.z,
        "saw_max",ciaaw_saw_Og_2021.saw_max,
        "saw_min",ciaaw_saw_Og_2021.saw_min,
        "saw",ciaaw_saw_Og_2021.saw,
        "saw_u",ciaaw_saw_Og_2021.saw_u,
        "asaw",ciaaw_saw_Og_2021.asaw,
        "asaw_u",ciaaw_saw_Og_2021.asaw_u
    );
    PyDict_SetItemString(d, "Og", element);
    Py_INCREF(element);

    return m;
}

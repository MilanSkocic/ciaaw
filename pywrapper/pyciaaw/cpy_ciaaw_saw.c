#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "ciaaw.h"

PyDoc_STRVAR(module_docstring, "C extension for saw.");

static PyMethodDef myMethods[] = {{ NULL, NULL, 0, NULL }};

static struct PyModuleDef saw = {PyModuleDef_HEAD_INIT, "saw", module_docstring, -1, myMethods};

PyMODINIT_FUNC PyInit_saw(void){
    PyObject *m;
    PyObject *d;
    PyObject *v;
    PyObject *element;
    m = PyModule_Create(&saw);
    d = PyModule_GetDict(m);

    v = PyLong_FromLong(ciaaw_saw_YEAR);
    PyDict_SetItemString(d, "YEAR", v);
    Py_INCREF(v);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_H.element,
        "symbol",ciaaw_saw_H.symbol,
        "z",ciaaw_saw_H.z,
        "saw_max",ciaaw_saw_H.saw_max,
        "saw_min",ciaaw_saw_H.saw_min,
        "saw",ciaaw_saw_H.saw,
        "saw_u",ciaaw_saw_H.saw_u,
        "asaw",ciaaw_saw_H.asaw,
        "asaw_u",ciaaw_saw_H.asaw_u
    );
    PyDict_SetItemString(d, "H", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_He.element,
        "symbol",ciaaw_saw_He.symbol,
        "z",ciaaw_saw_He.z,
        "saw_max",ciaaw_saw_He.saw_max,
        "saw_min",ciaaw_saw_He.saw_min,
        "saw",ciaaw_saw_He.saw,
        "saw_u",ciaaw_saw_He.saw_u,
        "asaw",ciaaw_saw_He.asaw,
        "asaw_u",ciaaw_saw_He.asaw_u
    );
    PyDict_SetItemString(d, "He", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Li.element,
        "symbol",ciaaw_saw_Li.symbol,
        "z",ciaaw_saw_Li.z,
        "saw_max",ciaaw_saw_Li.saw_max,
        "saw_min",ciaaw_saw_Li.saw_min,
        "saw",ciaaw_saw_Li.saw,
        "saw_u",ciaaw_saw_Li.saw_u,
        "asaw",ciaaw_saw_Li.asaw,
        "asaw_u",ciaaw_saw_Li.asaw_u
    );
    PyDict_SetItemString(d, "Li", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Be.element,
        "symbol",ciaaw_saw_Be.symbol,
        "z",ciaaw_saw_Be.z,
        "saw_max",ciaaw_saw_Be.saw_max,
        "saw_min",ciaaw_saw_Be.saw_min,
        "saw",ciaaw_saw_Be.saw,
        "saw_u",ciaaw_saw_Be.saw_u,
        "asaw",ciaaw_saw_Be.asaw,
        "asaw_u",ciaaw_saw_Be.asaw_u
    );
    PyDict_SetItemString(d, "Be", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_B.element,
        "symbol",ciaaw_saw_B.symbol,
        "z",ciaaw_saw_B.z,
        "saw_max",ciaaw_saw_B.saw_max,
        "saw_min",ciaaw_saw_B.saw_min,
        "saw",ciaaw_saw_B.saw,
        "saw_u",ciaaw_saw_B.saw_u,
        "asaw",ciaaw_saw_B.asaw,
        "asaw_u",ciaaw_saw_B.asaw_u
    );
    PyDict_SetItemString(d, "B", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_C.element,
        "symbol",ciaaw_saw_C.symbol,
        "z",ciaaw_saw_C.z,
        "saw_max",ciaaw_saw_C.saw_max,
        "saw_min",ciaaw_saw_C.saw_min,
        "saw",ciaaw_saw_C.saw,
        "saw_u",ciaaw_saw_C.saw_u,
        "asaw",ciaaw_saw_C.asaw,
        "asaw_u",ciaaw_saw_C.asaw_u
    );
    PyDict_SetItemString(d, "C", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_N.element,
        "symbol",ciaaw_saw_N.symbol,
        "z",ciaaw_saw_N.z,
        "saw_max",ciaaw_saw_N.saw_max,
        "saw_min",ciaaw_saw_N.saw_min,
        "saw",ciaaw_saw_N.saw,
        "saw_u",ciaaw_saw_N.saw_u,
        "asaw",ciaaw_saw_N.asaw,
        "asaw_u",ciaaw_saw_N.asaw_u
    );
    PyDict_SetItemString(d, "N", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_O.element,
        "symbol",ciaaw_saw_O.symbol,
        "z",ciaaw_saw_O.z,
        "saw_max",ciaaw_saw_O.saw_max,
        "saw_min",ciaaw_saw_O.saw_min,
        "saw",ciaaw_saw_O.saw,
        "saw_u",ciaaw_saw_O.saw_u,
        "asaw",ciaaw_saw_O.asaw,
        "asaw_u",ciaaw_saw_O.asaw_u
    );
    PyDict_SetItemString(d, "O", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_F.element,
        "symbol",ciaaw_saw_F.symbol,
        "z",ciaaw_saw_F.z,
        "saw_max",ciaaw_saw_F.saw_max,
        "saw_min",ciaaw_saw_F.saw_min,
        "saw",ciaaw_saw_F.saw,
        "saw_u",ciaaw_saw_F.saw_u,
        "asaw",ciaaw_saw_F.asaw,
        "asaw_u",ciaaw_saw_F.asaw_u
    );
    PyDict_SetItemString(d, "F", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ne.element,
        "symbol",ciaaw_saw_Ne.symbol,
        "z",ciaaw_saw_Ne.z,
        "saw_max",ciaaw_saw_Ne.saw_max,
        "saw_min",ciaaw_saw_Ne.saw_min,
        "saw",ciaaw_saw_Ne.saw,
        "saw_u",ciaaw_saw_Ne.saw_u,
        "asaw",ciaaw_saw_Ne.asaw,
        "asaw_u",ciaaw_saw_Ne.asaw_u
    );
    PyDict_SetItemString(d, "Ne", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Na.element,
        "symbol",ciaaw_saw_Na.symbol,
        "z",ciaaw_saw_Na.z,
        "saw_max",ciaaw_saw_Na.saw_max,
        "saw_min",ciaaw_saw_Na.saw_min,
        "saw",ciaaw_saw_Na.saw,
        "saw_u",ciaaw_saw_Na.saw_u,
        "asaw",ciaaw_saw_Na.asaw,
        "asaw_u",ciaaw_saw_Na.asaw_u
    );
    PyDict_SetItemString(d, "Na", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Mg.element,
        "symbol",ciaaw_saw_Mg.symbol,
        "z",ciaaw_saw_Mg.z,
        "saw_max",ciaaw_saw_Mg.saw_max,
        "saw_min",ciaaw_saw_Mg.saw_min,
        "saw",ciaaw_saw_Mg.saw,
        "saw_u",ciaaw_saw_Mg.saw_u,
        "asaw",ciaaw_saw_Mg.asaw,
        "asaw_u",ciaaw_saw_Mg.asaw_u
    );
    PyDict_SetItemString(d, "Mg", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Al.element,
        "symbol",ciaaw_saw_Al.symbol,
        "z",ciaaw_saw_Al.z,
        "saw_max",ciaaw_saw_Al.saw_max,
        "saw_min",ciaaw_saw_Al.saw_min,
        "saw",ciaaw_saw_Al.saw,
        "saw_u",ciaaw_saw_Al.saw_u,
        "asaw",ciaaw_saw_Al.asaw,
        "asaw_u",ciaaw_saw_Al.asaw_u
    );
    PyDict_SetItemString(d, "Al", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Si.element,
        "symbol",ciaaw_saw_Si.symbol,
        "z",ciaaw_saw_Si.z,
        "saw_max",ciaaw_saw_Si.saw_max,
        "saw_min",ciaaw_saw_Si.saw_min,
        "saw",ciaaw_saw_Si.saw,
        "saw_u",ciaaw_saw_Si.saw_u,
        "asaw",ciaaw_saw_Si.asaw,
        "asaw_u",ciaaw_saw_Si.asaw_u
    );
    PyDict_SetItemString(d, "Si", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_P.element,
        "symbol",ciaaw_saw_P.symbol,
        "z",ciaaw_saw_P.z,
        "saw_max",ciaaw_saw_P.saw_max,
        "saw_min",ciaaw_saw_P.saw_min,
        "saw",ciaaw_saw_P.saw,
        "saw_u",ciaaw_saw_P.saw_u,
        "asaw",ciaaw_saw_P.asaw,
        "asaw_u",ciaaw_saw_P.asaw_u
    );
    PyDict_SetItemString(d, "P", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_S.element,
        "symbol",ciaaw_saw_S.symbol,
        "z",ciaaw_saw_S.z,
        "saw_max",ciaaw_saw_S.saw_max,
        "saw_min",ciaaw_saw_S.saw_min,
        "saw",ciaaw_saw_S.saw,
        "saw_u",ciaaw_saw_S.saw_u,
        "asaw",ciaaw_saw_S.asaw,
        "asaw_u",ciaaw_saw_S.asaw_u
    );
    PyDict_SetItemString(d, "S", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cl.element,
        "symbol",ciaaw_saw_Cl.symbol,
        "z",ciaaw_saw_Cl.z,
        "saw_max",ciaaw_saw_Cl.saw_max,
        "saw_min",ciaaw_saw_Cl.saw_min,
        "saw",ciaaw_saw_Cl.saw,
        "saw_u",ciaaw_saw_Cl.saw_u,
        "asaw",ciaaw_saw_Cl.asaw,
        "asaw_u",ciaaw_saw_Cl.asaw_u
    );
    PyDict_SetItemString(d, "Cl", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ar.element,
        "symbol",ciaaw_saw_Ar.symbol,
        "z",ciaaw_saw_Ar.z,
        "saw_max",ciaaw_saw_Ar.saw_max,
        "saw_min",ciaaw_saw_Ar.saw_min,
        "saw",ciaaw_saw_Ar.saw,
        "saw_u",ciaaw_saw_Ar.saw_u,
        "asaw",ciaaw_saw_Ar.asaw,
        "asaw_u",ciaaw_saw_Ar.asaw_u
    );
    PyDict_SetItemString(d, "Ar", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_K.element,
        "symbol",ciaaw_saw_K.symbol,
        "z",ciaaw_saw_K.z,
        "saw_max",ciaaw_saw_K.saw_max,
        "saw_min",ciaaw_saw_K.saw_min,
        "saw",ciaaw_saw_K.saw,
        "saw_u",ciaaw_saw_K.saw_u,
        "asaw",ciaaw_saw_K.asaw,
        "asaw_u",ciaaw_saw_K.asaw_u
    );
    PyDict_SetItemString(d, "K", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ca.element,
        "symbol",ciaaw_saw_Ca.symbol,
        "z",ciaaw_saw_Ca.z,
        "saw_max",ciaaw_saw_Ca.saw_max,
        "saw_min",ciaaw_saw_Ca.saw_min,
        "saw",ciaaw_saw_Ca.saw,
        "saw_u",ciaaw_saw_Ca.saw_u,
        "asaw",ciaaw_saw_Ca.asaw,
        "asaw_u",ciaaw_saw_Ca.asaw_u
    );
    PyDict_SetItemString(d, "Ca", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sc.element,
        "symbol",ciaaw_saw_Sc.symbol,
        "z",ciaaw_saw_Sc.z,
        "saw_max",ciaaw_saw_Sc.saw_max,
        "saw_min",ciaaw_saw_Sc.saw_min,
        "saw",ciaaw_saw_Sc.saw,
        "saw_u",ciaaw_saw_Sc.saw_u,
        "asaw",ciaaw_saw_Sc.asaw,
        "asaw_u",ciaaw_saw_Sc.asaw_u
    );
    PyDict_SetItemString(d, "Sc", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ti.element,
        "symbol",ciaaw_saw_Ti.symbol,
        "z",ciaaw_saw_Ti.z,
        "saw_max",ciaaw_saw_Ti.saw_max,
        "saw_min",ciaaw_saw_Ti.saw_min,
        "saw",ciaaw_saw_Ti.saw,
        "saw_u",ciaaw_saw_Ti.saw_u,
        "asaw",ciaaw_saw_Ti.asaw,
        "asaw_u",ciaaw_saw_Ti.asaw_u
    );
    PyDict_SetItemString(d, "Ti", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_V.element,
        "symbol",ciaaw_saw_V.symbol,
        "z",ciaaw_saw_V.z,
        "saw_max",ciaaw_saw_V.saw_max,
        "saw_min",ciaaw_saw_V.saw_min,
        "saw",ciaaw_saw_V.saw,
        "saw_u",ciaaw_saw_V.saw_u,
        "asaw",ciaaw_saw_V.asaw,
        "asaw_u",ciaaw_saw_V.asaw_u
    );
    PyDict_SetItemString(d, "V", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cr.element,
        "symbol",ciaaw_saw_Cr.symbol,
        "z",ciaaw_saw_Cr.z,
        "saw_max",ciaaw_saw_Cr.saw_max,
        "saw_min",ciaaw_saw_Cr.saw_min,
        "saw",ciaaw_saw_Cr.saw,
        "saw_u",ciaaw_saw_Cr.saw_u,
        "asaw",ciaaw_saw_Cr.asaw,
        "asaw_u",ciaaw_saw_Cr.asaw_u
    );
    PyDict_SetItemString(d, "Cr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Mn.element,
        "symbol",ciaaw_saw_Mn.symbol,
        "z",ciaaw_saw_Mn.z,
        "saw_max",ciaaw_saw_Mn.saw_max,
        "saw_min",ciaaw_saw_Mn.saw_min,
        "saw",ciaaw_saw_Mn.saw,
        "saw_u",ciaaw_saw_Mn.saw_u,
        "asaw",ciaaw_saw_Mn.asaw,
        "asaw_u",ciaaw_saw_Mn.asaw_u
    );
    PyDict_SetItemString(d, "Mn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Fe.element,
        "symbol",ciaaw_saw_Fe.symbol,
        "z",ciaaw_saw_Fe.z,
        "saw_max",ciaaw_saw_Fe.saw_max,
        "saw_min",ciaaw_saw_Fe.saw_min,
        "saw",ciaaw_saw_Fe.saw,
        "saw_u",ciaaw_saw_Fe.saw_u,
        "asaw",ciaaw_saw_Fe.asaw,
        "asaw_u",ciaaw_saw_Fe.asaw_u
    );
    PyDict_SetItemString(d, "Fe", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Co.element,
        "symbol",ciaaw_saw_Co.symbol,
        "z",ciaaw_saw_Co.z,
        "saw_max",ciaaw_saw_Co.saw_max,
        "saw_min",ciaaw_saw_Co.saw_min,
        "saw",ciaaw_saw_Co.saw,
        "saw_u",ciaaw_saw_Co.saw_u,
        "asaw",ciaaw_saw_Co.asaw,
        "asaw_u",ciaaw_saw_Co.asaw_u
    );
    PyDict_SetItemString(d, "Co", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ni.element,
        "symbol",ciaaw_saw_Ni.symbol,
        "z",ciaaw_saw_Ni.z,
        "saw_max",ciaaw_saw_Ni.saw_max,
        "saw_min",ciaaw_saw_Ni.saw_min,
        "saw",ciaaw_saw_Ni.saw,
        "saw_u",ciaaw_saw_Ni.saw_u,
        "asaw",ciaaw_saw_Ni.asaw,
        "asaw_u",ciaaw_saw_Ni.asaw_u
    );
    PyDict_SetItemString(d, "Ni", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cu.element,
        "symbol",ciaaw_saw_Cu.symbol,
        "z",ciaaw_saw_Cu.z,
        "saw_max",ciaaw_saw_Cu.saw_max,
        "saw_min",ciaaw_saw_Cu.saw_min,
        "saw",ciaaw_saw_Cu.saw,
        "saw_u",ciaaw_saw_Cu.saw_u,
        "asaw",ciaaw_saw_Cu.asaw,
        "asaw_u",ciaaw_saw_Cu.asaw_u
    );
    PyDict_SetItemString(d, "Cu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Zn.element,
        "symbol",ciaaw_saw_Zn.symbol,
        "z",ciaaw_saw_Zn.z,
        "saw_max",ciaaw_saw_Zn.saw_max,
        "saw_min",ciaaw_saw_Zn.saw_min,
        "saw",ciaaw_saw_Zn.saw,
        "saw_u",ciaaw_saw_Zn.saw_u,
        "asaw",ciaaw_saw_Zn.asaw,
        "asaw_u",ciaaw_saw_Zn.asaw_u
    );
    PyDict_SetItemString(d, "Zn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ga.element,
        "symbol",ciaaw_saw_Ga.symbol,
        "z",ciaaw_saw_Ga.z,
        "saw_max",ciaaw_saw_Ga.saw_max,
        "saw_min",ciaaw_saw_Ga.saw_min,
        "saw",ciaaw_saw_Ga.saw,
        "saw_u",ciaaw_saw_Ga.saw_u,
        "asaw",ciaaw_saw_Ga.asaw,
        "asaw_u",ciaaw_saw_Ga.asaw_u
    );
    PyDict_SetItemString(d, "Ga", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ge.element,
        "symbol",ciaaw_saw_Ge.symbol,
        "z",ciaaw_saw_Ge.z,
        "saw_max",ciaaw_saw_Ge.saw_max,
        "saw_min",ciaaw_saw_Ge.saw_min,
        "saw",ciaaw_saw_Ge.saw,
        "saw_u",ciaaw_saw_Ge.saw_u,
        "asaw",ciaaw_saw_Ge.asaw,
        "asaw_u",ciaaw_saw_Ge.asaw_u
    );
    PyDict_SetItemString(d, "Ge", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_As.element,
        "symbol",ciaaw_saw_As.symbol,
        "z",ciaaw_saw_As.z,
        "saw_max",ciaaw_saw_As.saw_max,
        "saw_min",ciaaw_saw_As.saw_min,
        "saw",ciaaw_saw_As.saw,
        "saw_u",ciaaw_saw_As.saw_u,
        "asaw",ciaaw_saw_As.asaw,
        "asaw_u",ciaaw_saw_As.asaw_u
    );
    PyDict_SetItemString(d, "As", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Se.element,
        "symbol",ciaaw_saw_Se.symbol,
        "z",ciaaw_saw_Se.z,
        "saw_max",ciaaw_saw_Se.saw_max,
        "saw_min",ciaaw_saw_Se.saw_min,
        "saw",ciaaw_saw_Se.saw,
        "saw_u",ciaaw_saw_Se.saw_u,
        "asaw",ciaaw_saw_Se.asaw,
        "asaw_u",ciaaw_saw_Se.asaw_u
    );
    PyDict_SetItemString(d, "Se", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Br.element,
        "symbol",ciaaw_saw_Br.symbol,
        "z",ciaaw_saw_Br.z,
        "saw_max",ciaaw_saw_Br.saw_max,
        "saw_min",ciaaw_saw_Br.saw_min,
        "saw",ciaaw_saw_Br.saw,
        "saw_u",ciaaw_saw_Br.saw_u,
        "asaw",ciaaw_saw_Br.asaw,
        "asaw_u",ciaaw_saw_Br.asaw_u
    );
    PyDict_SetItemString(d, "Br", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Kr.element,
        "symbol",ciaaw_saw_Kr.symbol,
        "z",ciaaw_saw_Kr.z,
        "saw_max",ciaaw_saw_Kr.saw_max,
        "saw_min",ciaaw_saw_Kr.saw_min,
        "saw",ciaaw_saw_Kr.saw,
        "saw_u",ciaaw_saw_Kr.saw_u,
        "asaw",ciaaw_saw_Kr.asaw,
        "asaw_u",ciaaw_saw_Kr.asaw_u
    );
    PyDict_SetItemString(d, "Kr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Rb.element,
        "symbol",ciaaw_saw_Rb.symbol,
        "z",ciaaw_saw_Rb.z,
        "saw_max",ciaaw_saw_Rb.saw_max,
        "saw_min",ciaaw_saw_Rb.saw_min,
        "saw",ciaaw_saw_Rb.saw,
        "saw_u",ciaaw_saw_Rb.saw_u,
        "asaw",ciaaw_saw_Rb.asaw,
        "asaw_u",ciaaw_saw_Rb.asaw_u
    );
    PyDict_SetItemString(d, "Rb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sr.element,
        "symbol",ciaaw_saw_Sr.symbol,
        "z",ciaaw_saw_Sr.z,
        "saw_max",ciaaw_saw_Sr.saw_max,
        "saw_min",ciaaw_saw_Sr.saw_min,
        "saw",ciaaw_saw_Sr.saw,
        "saw_u",ciaaw_saw_Sr.saw_u,
        "asaw",ciaaw_saw_Sr.asaw,
        "asaw_u",ciaaw_saw_Sr.asaw_u
    );
    PyDict_SetItemString(d, "Sr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Y.element,
        "symbol",ciaaw_saw_Y.symbol,
        "z",ciaaw_saw_Y.z,
        "saw_max",ciaaw_saw_Y.saw_max,
        "saw_min",ciaaw_saw_Y.saw_min,
        "saw",ciaaw_saw_Y.saw,
        "saw_u",ciaaw_saw_Y.saw_u,
        "asaw",ciaaw_saw_Y.asaw,
        "asaw_u",ciaaw_saw_Y.asaw_u
    );
    PyDict_SetItemString(d, "Y", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Zr.element,
        "symbol",ciaaw_saw_Zr.symbol,
        "z",ciaaw_saw_Zr.z,
        "saw_max",ciaaw_saw_Zr.saw_max,
        "saw_min",ciaaw_saw_Zr.saw_min,
        "saw",ciaaw_saw_Zr.saw,
        "saw_u",ciaaw_saw_Zr.saw_u,
        "asaw",ciaaw_saw_Zr.asaw,
        "asaw_u",ciaaw_saw_Zr.asaw_u
    );
    PyDict_SetItemString(d, "Zr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Nb.element,
        "symbol",ciaaw_saw_Nb.symbol,
        "z",ciaaw_saw_Nb.z,
        "saw_max",ciaaw_saw_Nb.saw_max,
        "saw_min",ciaaw_saw_Nb.saw_min,
        "saw",ciaaw_saw_Nb.saw,
        "saw_u",ciaaw_saw_Nb.saw_u,
        "asaw",ciaaw_saw_Nb.asaw,
        "asaw_u",ciaaw_saw_Nb.asaw_u
    );
    PyDict_SetItemString(d, "Nb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Mo.element,
        "symbol",ciaaw_saw_Mo.symbol,
        "z",ciaaw_saw_Mo.z,
        "saw_max",ciaaw_saw_Mo.saw_max,
        "saw_min",ciaaw_saw_Mo.saw_min,
        "saw",ciaaw_saw_Mo.saw,
        "saw_u",ciaaw_saw_Mo.saw_u,
        "asaw",ciaaw_saw_Mo.asaw,
        "asaw_u",ciaaw_saw_Mo.asaw_u
    );
    PyDict_SetItemString(d, "Mo", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Tc.element,
        "symbol",ciaaw_saw_Tc.symbol,
        "z",ciaaw_saw_Tc.z,
        "saw_max",ciaaw_saw_Tc.saw_max,
        "saw_min",ciaaw_saw_Tc.saw_min,
        "saw",ciaaw_saw_Tc.saw,
        "saw_u",ciaaw_saw_Tc.saw_u,
        "asaw",ciaaw_saw_Tc.asaw,
        "asaw_u",ciaaw_saw_Tc.asaw_u
    );
    PyDict_SetItemString(d, "Tc", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ru.element,
        "symbol",ciaaw_saw_Ru.symbol,
        "z",ciaaw_saw_Ru.z,
        "saw_max",ciaaw_saw_Ru.saw_max,
        "saw_min",ciaaw_saw_Ru.saw_min,
        "saw",ciaaw_saw_Ru.saw,
        "saw_u",ciaaw_saw_Ru.saw_u,
        "asaw",ciaaw_saw_Ru.asaw,
        "asaw_u",ciaaw_saw_Ru.asaw_u
    );
    PyDict_SetItemString(d, "Ru", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Rh.element,
        "symbol",ciaaw_saw_Rh.symbol,
        "z",ciaaw_saw_Rh.z,
        "saw_max",ciaaw_saw_Rh.saw_max,
        "saw_min",ciaaw_saw_Rh.saw_min,
        "saw",ciaaw_saw_Rh.saw,
        "saw_u",ciaaw_saw_Rh.saw_u,
        "asaw",ciaaw_saw_Rh.asaw,
        "asaw_u",ciaaw_saw_Rh.asaw_u
    );
    PyDict_SetItemString(d, "Rh", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Pd.element,
        "symbol",ciaaw_saw_Pd.symbol,
        "z",ciaaw_saw_Pd.z,
        "saw_max",ciaaw_saw_Pd.saw_max,
        "saw_min",ciaaw_saw_Pd.saw_min,
        "saw",ciaaw_saw_Pd.saw,
        "saw_u",ciaaw_saw_Pd.saw_u,
        "asaw",ciaaw_saw_Pd.asaw,
        "asaw_u",ciaaw_saw_Pd.asaw_u
    );
    PyDict_SetItemString(d, "Pd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ag.element,
        "symbol",ciaaw_saw_Ag.symbol,
        "z",ciaaw_saw_Ag.z,
        "saw_max",ciaaw_saw_Ag.saw_max,
        "saw_min",ciaaw_saw_Ag.saw_min,
        "saw",ciaaw_saw_Ag.saw,
        "saw_u",ciaaw_saw_Ag.saw_u,
        "asaw",ciaaw_saw_Ag.asaw,
        "asaw_u",ciaaw_saw_Ag.asaw_u
    );
    PyDict_SetItemString(d, "Ag", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cd.element,
        "symbol",ciaaw_saw_Cd.symbol,
        "z",ciaaw_saw_Cd.z,
        "saw_max",ciaaw_saw_Cd.saw_max,
        "saw_min",ciaaw_saw_Cd.saw_min,
        "saw",ciaaw_saw_Cd.saw,
        "saw_u",ciaaw_saw_Cd.saw_u,
        "asaw",ciaaw_saw_Cd.asaw,
        "asaw_u",ciaaw_saw_Cd.asaw_u
    );
    PyDict_SetItemString(d, "Cd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_In.element,
        "symbol",ciaaw_saw_In.symbol,
        "z",ciaaw_saw_In.z,
        "saw_max",ciaaw_saw_In.saw_max,
        "saw_min",ciaaw_saw_In.saw_min,
        "saw",ciaaw_saw_In.saw,
        "saw_u",ciaaw_saw_In.saw_u,
        "asaw",ciaaw_saw_In.asaw,
        "asaw_u",ciaaw_saw_In.asaw_u
    );
    PyDict_SetItemString(d, "In", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sn.element,
        "symbol",ciaaw_saw_Sn.symbol,
        "z",ciaaw_saw_Sn.z,
        "saw_max",ciaaw_saw_Sn.saw_max,
        "saw_min",ciaaw_saw_Sn.saw_min,
        "saw",ciaaw_saw_Sn.saw,
        "saw_u",ciaaw_saw_Sn.saw_u,
        "asaw",ciaaw_saw_Sn.asaw,
        "asaw_u",ciaaw_saw_Sn.asaw_u
    );
    PyDict_SetItemString(d, "Sn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sb.element,
        "symbol",ciaaw_saw_Sb.symbol,
        "z",ciaaw_saw_Sb.z,
        "saw_max",ciaaw_saw_Sb.saw_max,
        "saw_min",ciaaw_saw_Sb.saw_min,
        "saw",ciaaw_saw_Sb.saw,
        "saw_u",ciaaw_saw_Sb.saw_u,
        "asaw",ciaaw_saw_Sb.asaw,
        "asaw_u",ciaaw_saw_Sb.asaw_u
    );
    PyDict_SetItemString(d, "Sb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Te.element,
        "symbol",ciaaw_saw_Te.symbol,
        "z",ciaaw_saw_Te.z,
        "saw_max",ciaaw_saw_Te.saw_max,
        "saw_min",ciaaw_saw_Te.saw_min,
        "saw",ciaaw_saw_Te.saw,
        "saw_u",ciaaw_saw_Te.saw_u,
        "asaw",ciaaw_saw_Te.asaw,
        "asaw_u",ciaaw_saw_Te.asaw_u
    );
    PyDict_SetItemString(d, "Te", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_I.element,
        "symbol",ciaaw_saw_I.symbol,
        "z",ciaaw_saw_I.z,
        "saw_max",ciaaw_saw_I.saw_max,
        "saw_min",ciaaw_saw_I.saw_min,
        "saw",ciaaw_saw_I.saw,
        "saw_u",ciaaw_saw_I.saw_u,
        "asaw",ciaaw_saw_I.asaw,
        "asaw_u",ciaaw_saw_I.asaw_u
    );
    PyDict_SetItemString(d, "I", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Xe.element,
        "symbol",ciaaw_saw_Xe.symbol,
        "z",ciaaw_saw_Xe.z,
        "saw_max",ciaaw_saw_Xe.saw_max,
        "saw_min",ciaaw_saw_Xe.saw_min,
        "saw",ciaaw_saw_Xe.saw,
        "saw_u",ciaaw_saw_Xe.saw_u,
        "asaw",ciaaw_saw_Xe.asaw,
        "asaw_u",ciaaw_saw_Xe.asaw_u
    );
    PyDict_SetItemString(d, "Xe", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Cs.element,
        "symbol",ciaaw_saw_Cs.symbol,
        "z",ciaaw_saw_Cs.z,
        "saw_max",ciaaw_saw_Cs.saw_max,
        "saw_min",ciaaw_saw_Cs.saw_min,
        "saw",ciaaw_saw_Cs.saw,
        "saw_u",ciaaw_saw_Cs.saw_u,
        "asaw",ciaaw_saw_Cs.asaw,
        "asaw_u",ciaaw_saw_Cs.asaw_u
    );
    PyDict_SetItemString(d, "Cs", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ba.element,
        "symbol",ciaaw_saw_Ba.symbol,
        "z",ciaaw_saw_Ba.z,
        "saw_max",ciaaw_saw_Ba.saw_max,
        "saw_min",ciaaw_saw_Ba.saw_min,
        "saw",ciaaw_saw_Ba.saw,
        "saw_u",ciaaw_saw_Ba.saw_u,
        "asaw",ciaaw_saw_Ba.asaw,
        "asaw_u",ciaaw_saw_Ba.asaw_u
    );
    PyDict_SetItemString(d, "Ba", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_La.element,
        "symbol",ciaaw_saw_La.symbol,
        "z",ciaaw_saw_La.z,
        "saw_max",ciaaw_saw_La.saw_max,
        "saw_min",ciaaw_saw_La.saw_min,
        "saw",ciaaw_saw_La.saw,
        "saw_u",ciaaw_saw_La.saw_u,
        "asaw",ciaaw_saw_La.asaw,
        "asaw_u",ciaaw_saw_La.asaw_u
    );
    PyDict_SetItemString(d, "La", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ce.element,
        "symbol",ciaaw_saw_Ce.symbol,
        "z",ciaaw_saw_Ce.z,
        "saw_max",ciaaw_saw_Ce.saw_max,
        "saw_min",ciaaw_saw_Ce.saw_min,
        "saw",ciaaw_saw_Ce.saw,
        "saw_u",ciaaw_saw_Ce.saw_u,
        "asaw",ciaaw_saw_Ce.asaw,
        "asaw_u",ciaaw_saw_Ce.asaw_u
    );
    PyDict_SetItemString(d, "Ce", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Pr.element,
        "symbol",ciaaw_saw_Pr.symbol,
        "z",ciaaw_saw_Pr.z,
        "saw_max",ciaaw_saw_Pr.saw_max,
        "saw_min",ciaaw_saw_Pr.saw_min,
        "saw",ciaaw_saw_Pr.saw,
        "saw_u",ciaaw_saw_Pr.saw_u,
        "asaw",ciaaw_saw_Pr.asaw,
        "asaw_u",ciaaw_saw_Pr.asaw_u
    );
    PyDict_SetItemString(d, "Pr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Nd.element,
        "symbol",ciaaw_saw_Nd.symbol,
        "z",ciaaw_saw_Nd.z,
        "saw_max",ciaaw_saw_Nd.saw_max,
        "saw_min",ciaaw_saw_Nd.saw_min,
        "saw",ciaaw_saw_Nd.saw,
        "saw_u",ciaaw_saw_Nd.saw_u,
        "asaw",ciaaw_saw_Nd.asaw,
        "asaw_u",ciaaw_saw_Nd.asaw_u
    );
    PyDict_SetItemString(d, "Nd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Pm.element,
        "symbol",ciaaw_saw_Pm.symbol,
        "z",ciaaw_saw_Pm.z,
        "saw_max",ciaaw_saw_Pm.saw_max,
        "saw_min",ciaaw_saw_Pm.saw_min,
        "saw",ciaaw_saw_Pm.saw,
        "saw_u",ciaaw_saw_Pm.saw_u,
        "asaw",ciaaw_saw_Pm.asaw,
        "asaw_u",ciaaw_saw_Pm.asaw_u
    );
    PyDict_SetItemString(d, "Pm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Sm.element,
        "symbol",ciaaw_saw_Sm.symbol,
        "z",ciaaw_saw_Sm.z,
        "saw_max",ciaaw_saw_Sm.saw_max,
        "saw_min",ciaaw_saw_Sm.saw_min,
        "saw",ciaaw_saw_Sm.saw,
        "saw_u",ciaaw_saw_Sm.saw_u,
        "asaw",ciaaw_saw_Sm.asaw,
        "asaw_u",ciaaw_saw_Sm.asaw_u
    );
    PyDict_SetItemString(d, "Sm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Eu.element,
        "symbol",ciaaw_saw_Eu.symbol,
        "z",ciaaw_saw_Eu.z,
        "saw_max",ciaaw_saw_Eu.saw_max,
        "saw_min",ciaaw_saw_Eu.saw_min,
        "saw",ciaaw_saw_Eu.saw,
        "saw_u",ciaaw_saw_Eu.saw_u,
        "asaw",ciaaw_saw_Eu.asaw,
        "asaw_u",ciaaw_saw_Eu.asaw_u
    );
    PyDict_SetItemString(d, "Eu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Gd.element,
        "symbol",ciaaw_saw_Gd.symbol,
        "z",ciaaw_saw_Gd.z,
        "saw_max",ciaaw_saw_Gd.saw_max,
        "saw_min",ciaaw_saw_Gd.saw_min,
        "saw",ciaaw_saw_Gd.saw,
        "saw_u",ciaaw_saw_Gd.saw_u,
        "asaw",ciaaw_saw_Gd.asaw,
        "asaw_u",ciaaw_saw_Gd.asaw_u
    );
    PyDict_SetItemString(d, "Gd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Tb.element,
        "symbol",ciaaw_saw_Tb.symbol,
        "z",ciaaw_saw_Tb.z,
        "saw_max",ciaaw_saw_Tb.saw_max,
        "saw_min",ciaaw_saw_Tb.saw_min,
        "saw",ciaaw_saw_Tb.saw,
        "saw_u",ciaaw_saw_Tb.saw_u,
        "asaw",ciaaw_saw_Tb.asaw,
        "asaw_u",ciaaw_saw_Tb.asaw_u
    );
    PyDict_SetItemString(d, "Tb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Dy.element,
        "symbol",ciaaw_saw_Dy.symbol,
        "z",ciaaw_saw_Dy.z,
        "saw_max",ciaaw_saw_Dy.saw_max,
        "saw_min",ciaaw_saw_Dy.saw_min,
        "saw",ciaaw_saw_Dy.saw,
        "saw_u",ciaaw_saw_Dy.saw_u,
        "asaw",ciaaw_saw_Dy.asaw,
        "asaw_u",ciaaw_saw_Dy.asaw_u
    );
    PyDict_SetItemString(d, "Dy", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Ho.element,
        "symbol",ciaaw_saw_Ho.symbol,
        "z",ciaaw_saw_Ho.z,
        "saw_max",ciaaw_saw_Ho.saw_max,
        "saw_min",ciaaw_saw_Ho.saw_min,
        "saw",ciaaw_saw_Ho.saw,
        "saw_u",ciaaw_saw_Ho.saw_u,
        "asaw",ciaaw_saw_Ho.asaw,
        "asaw_u",ciaaw_saw_Ho.asaw_u
    );
    PyDict_SetItemString(d, "Ho", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_Er.element,
        "symbol",ciaaw_saw_Er.symbol,
        "z",ciaaw_saw_Er.z,
        "saw_max",ciaaw_saw_Er.saw_max,
        "saw_min",ciaaw_saw_Er.saw_min,
        "saw",ciaaw_saw_Er.saw,
        "saw_u",ciaaw_saw_Er.saw_u,
        "asaw",ciaaw_saw_Er.asaw,
        "asaw_u",ciaaw_saw_Er.asaw_u
    );
    PyDict_SetItemString(d, "Er", element);
    Py_INCREF(element);

    return m;
}

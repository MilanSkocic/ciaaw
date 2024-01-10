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

    return m;
}

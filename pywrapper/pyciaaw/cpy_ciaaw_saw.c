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

    v = PyLong_FromLong(ciaaw_saw_capi_YEAR);
    PyDict_SetItemString(d, "YEAR", v);
    Py_INCREF(v);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_H.element,
        "symbol",ciaaw_saw_capi_H.symbol,
        "z",ciaaw_saw_capi_H.z,
        "saw_max",ciaaw_saw_capi_H.saw_max,
        "saw_min",ciaaw_saw_capi_H.saw_min,
        "saw",ciaaw_saw_capi_H.saw,
        "saw_u",ciaaw_saw_capi_H.saw_u,
        "asaw",ciaaw_saw_capi_H.asaw,
        "asaw_u",ciaaw_saw_capi_H.asaw_u
    );
    PyDict_SetItemString(d, "H", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_He.element,
        "symbol",ciaaw_saw_capi_He.symbol,
        "z",ciaaw_saw_capi_He.z,
        "saw_max",ciaaw_saw_capi_He.saw_max,
        "saw_min",ciaaw_saw_capi_He.saw_min,
        "saw",ciaaw_saw_capi_He.saw,
        "saw_u",ciaaw_saw_capi_He.saw_u,
        "asaw",ciaaw_saw_capi_He.asaw,
        "asaw_u",ciaaw_saw_capi_He.asaw_u
    );
    PyDict_SetItemString(d, "He", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Li.element,
        "symbol",ciaaw_saw_capi_Li.symbol,
        "z",ciaaw_saw_capi_Li.z,
        "saw_max",ciaaw_saw_capi_Li.saw_max,
        "saw_min",ciaaw_saw_capi_Li.saw_min,
        "saw",ciaaw_saw_capi_Li.saw,
        "saw_u",ciaaw_saw_capi_Li.saw_u,
        "asaw",ciaaw_saw_capi_Li.asaw,
        "asaw_u",ciaaw_saw_capi_Li.asaw_u
    );
    PyDict_SetItemString(d, "Li", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Be.element,
        "symbol",ciaaw_saw_capi_Be.symbol,
        "z",ciaaw_saw_capi_Be.z,
        "saw_max",ciaaw_saw_capi_Be.saw_max,
        "saw_min",ciaaw_saw_capi_Be.saw_min,
        "saw",ciaaw_saw_capi_Be.saw,
        "saw_u",ciaaw_saw_capi_Be.saw_u,
        "asaw",ciaaw_saw_capi_Be.asaw,
        "asaw_u",ciaaw_saw_capi_Be.asaw_u
    );
    PyDict_SetItemString(d, "Be", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_B.element,
        "symbol",ciaaw_saw_capi_B.symbol,
        "z",ciaaw_saw_capi_B.z,
        "saw_max",ciaaw_saw_capi_B.saw_max,
        "saw_min",ciaaw_saw_capi_B.saw_min,
        "saw",ciaaw_saw_capi_B.saw,
        "saw_u",ciaaw_saw_capi_B.saw_u,
        "asaw",ciaaw_saw_capi_B.asaw,
        "asaw_u",ciaaw_saw_capi_B.asaw_u
    );
    PyDict_SetItemString(d, "B", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_C.element,
        "symbol",ciaaw_saw_capi_C.symbol,
        "z",ciaaw_saw_capi_C.z,
        "saw_max",ciaaw_saw_capi_C.saw_max,
        "saw_min",ciaaw_saw_capi_C.saw_min,
        "saw",ciaaw_saw_capi_C.saw,
        "saw_u",ciaaw_saw_capi_C.saw_u,
        "asaw",ciaaw_saw_capi_C.asaw,
        "asaw_u",ciaaw_saw_capi_C.asaw_u
    );
    PyDict_SetItemString(d, "C", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_N.element,
        "symbol",ciaaw_saw_capi_N.symbol,
        "z",ciaaw_saw_capi_N.z,
        "saw_max",ciaaw_saw_capi_N.saw_max,
        "saw_min",ciaaw_saw_capi_N.saw_min,
        "saw",ciaaw_saw_capi_N.saw,
        "saw_u",ciaaw_saw_capi_N.saw_u,
        "asaw",ciaaw_saw_capi_N.asaw,
        "asaw_u",ciaaw_saw_capi_N.asaw_u
    );
    PyDict_SetItemString(d, "N", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_O.element,
        "symbol",ciaaw_saw_capi_O.symbol,
        "z",ciaaw_saw_capi_O.z,
        "saw_max",ciaaw_saw_capi_O.saw_max,
        "saw_min",ciaaw_saw_capi_O.saw_min,
        "saw",ciaaw_saw_capi_O.saw,
        "saw_u",ciaaw_saw_capi_O.saw_u,
        "asaw",ciaaw_saw_capi_O.asaw,
        "asaw_u",ciaaw_saw_capi_O.asaw_u
    );
    PyDict_SetItemString(d, "O", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_F.element,
        "symbol",ciaaw_saw_capi_F.symbol,
        "z",ciaaw_saw_capi_F.z,
        "saw_max",ciaaw_saw_capi_F.saw_max,
        "saw_min",ciaaw_saw_capi_F.saw_min,
        "saw",ciaaw_saw_capi_F.saw,
        "saw_u",ciaaw_saw_capi_F.saw_u,
        "asaw",ciaaw_saw_capi_F.asaw,
        "asaw_u",ciaaw_saw_capi_F.asaw_u
    );
    PyDict_SetItemString(d, "F", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Ne.element,
        "symbol",ciaaw_saw_capi_Ne.symbol,
        "z",ciaaw_saw_capi_Ne.z,
        "saw_max",ciaaw_saw_capi_Ne.saw_max,
        "saw_min",ciaaw_saw_capi_Ne.saw_min,
        "saw",ciaaw_saw_capi_Ne.saw,
        "saw_u",ciaaw_saw_capi_Ne.saw_u,
        "asaw",ciaaw_saw_capi_Ne.asaw,
        "asaw_u",ciaaw_saw_capi_Ne.asaw_u
    );
    PyDict_SetItemString(d, "Ne", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Na.element,
        "symbol",ciaaw_saw_capi_Na.symbol,
        "z",ciaaw_saw_capi_Na.z,
        "saw_max",ciaaw_saw_capi_Na.saw_max,
        "saw_min",ciaaw_saw_capi_Na.saw_min,
        "saw",ciaaw_saw_capi_Na.saw,
        "saw_u",ciaaw_saw_capi_Na.saw_u,
        "asaw",ciaaw_saw_capi_Na.asaw,
        "asaw_u",ciaaw_saw_capi_Na.asaw_u
    );
    PyDict_SetItemString(d, "Na", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Mg.element,
        "symbol",ciaaw_saw_capi_Mg.symbol,
        "z",ciaaw_saw_capi_Mg.z,
        "saw_max",ciaaw_saw_capi_Mg.saw_max,
        "saw_min",ciaaw_saw_capi_Mg.saw_min,
        "saw",ciaaw_saw_capi_Mg.saw,
        "saw_u",ciaaw_saw_capi_Mg.saw_u,
        "asaw",ciaaw_saw_capi_Mg.asaw,
        "asaw_u",ciaaw_saw_capi_Mg.asaw_u
    );
    PyDict_SetItemString(d, "Mg", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Al.element,
        "symbol",ciaaw_saw_capi_Al.symbol,
        "z",ciaaw_saw_capi_Al.z,
        "saw_max",ciaaw_saw_capi_Al.saw_max,
        "saw_min",ciaaw_saw_capi_Al.saw_min,
        "saw",ciaaw_saw_capi_Al.saw,
        "saw_u",ciaaw_saw_capi_Al.saw_u,
        "asaw",ciaaw_saw_capi_Al.asaw,
        "asaw_u",ciaaw_saw_capi_Al.asaw_u
    );
    PyDict_SetItemString(d, "Al", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Si.element,
        "symbol",ciaaw_saw_capi_Si.symbol,
        "z",ciaaw_saw_capi_Si.z,
        "saw_max",ciaaw_saw_capi_Si.saw_max,
        "saw_min",ciaaw_saw_capi_Si.saw_min,
        "saw",ciaaw_saw_capi_Si.saw,
        "saw_u",ciaaw_saw_capi_Si.saw_u,
        "asaw",ciaaw_saw_capi_Si.asaw,
        "asaw_u",ciaaw_saw_capi_Si.asaw_u
    );
    PyDict_SetItemString(d, "Si", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_P.element,
        "symbol",ciaaw_saw_capi_P.symbol,
        "z",ciaaw_saw_capi_P.z,
        "saw_max",ciaaw_saw_capi_P.saw_max,
        "saw_min",ciaaw_saw_capi_P.saw_min,
        "saw",ciaaw_saw_capi_P.saw,
        "saw_u",ciaaw_saw_capi_P.saw_u,
        "asaw",ciaaw_saw_capi_P.asaw,
        "asaw_u",ciaaw_saw_capi_P.asaw_u
    );
    PyDict_SetItemString(d, "P", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_S.element,
        "symbol",ciaaw_saw_capi_S.symbol,
        "z",ciaaw_saw_capi_S.z,
        "saw_max",ciaaw_saw_capi_S.saw_max,
        "saw_min",ciaaw_saw_capi_S.saw_min,
        "saw",ciaaw_saw_capi_S.saw,
        "saw_u",ciaaw_saw_capi_S.saw_u,
        "asaw",ciaaw_saw_capi_S.asaw,
        "asaw_u",ciaaw_saw_capi_S.asaw_u
    );
    PyDict_SetItemString(d, "S", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Cl.element,
        "symbol",ciaaw_saw_capi_Cl.symbol,
        "z",ciaaw_saw_capi_Cl.z,
        "saw_max",ciaaw_saw_capi_Cl.saw_max,
        "saw_min",ciaaw_saw_capi_Cl.saw_min,
        "saw",ciaaw_saw_capi_Cl.saw,
        "saw_u",ciaaw_saw_capi_Cl.saw_u,
        "asaw",ciaaw_saw_capi_Cl.asaw,
        "asaw_u",ciaaw_saw_capi_Cl.asaw_u
    );
    PyDict_SetItemString(d, "Cl", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Ar.element,
        "symbol",ciaaw_saw_capi_Ar.symbol,
        "z",ciaaw_saw_capi_Ar.z,
        "saw_max",ciaaw_saw_capi_Ar.saw_max,
        "saw_min",ciaaw_saw_capi_Ar.saw_min,
        "saw",ciaaw_saw_capi_Ar.saw,
        "saw_u",ciaaw_saw_capi_Ar.saw_u,
        "asaw",ciaaw_saw_capi_Ar.asaw,
        "asaw_u",ciaaw_saw_capi_Ar.asaw_u
    );
    PyDict_SetItemString(d, "Ar", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_K.element,
        "symbol",ciaaw_saw_capi_K.symbol,
        "z",ciaaw_saw_capi_K.z,
        "saw_max",ciaaw_saw_capi_K.saw_max,
        "saw_min",ciaaw_saw_capi_K.saw_min,
        "saw",ciaaw_saw_capi_K.saw,
        "saw_u",ciaaw_saw_capi_K.saw_u,
        "asaw",ciaaw_saw_capi_K.asaw,
        "asaw_u",ciaaw_saw_capi_K.asaw_u
    );
    PyDict_SetItemString(d, "K", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Ca.element,
        "symbol",ciaaw_saw_capi_Ca.symbol,
        "z",ciaaw_saw_capi_Ca.z,
        "saw_max",ciaaw_saw_capi_Ca.saw_max,
        "saw_min",ciaaw_saw_capi_Ca.saw_min,
        "saw",ciaaw_saw_capi_Ca.saw,
        "saw_u",ciaaw_saw_capi_Ca.saw_u,
        "asaw",ciaaw_saw_capi_Ca.asaw,
        "asaw_u",ciaaw_saw_capi_Ca.asaw_u
    );
    PyDict_SetItemString(d, "Ca", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Sc.element,
        "symbol",ciaaw_saw_capi_Sc.symbol,
        "z",ciaaw_saw_capi_Sc.z,
        "saw_max",ciaaw_saw_capi_Sc.saw_max,
        "saw_min",ciaaw_saw_capi_Sc.saw_min,
        "saw",ciaaw_saw_capi_Sc.saw,
        "saw_u",ciaaw_saw_capi_Sc.saw_u,
        "asaw",ciaaw_saw_capi_Sc.asaw,
        "asaw_u",ciaaw_saw_capi_Sc.asaw_u
    );
    PyDict_SetItemString(d, "Sc", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Ti.element,
        "symbol",ciaaw_saw_capi_Ti.symbol,
        "z",ciaaw_saw_capi_Ti.z,
        "saw_max",ciaaw_saw_capi_Ti.saw_max,
        "saw_min",ciaaw_saw_capi_Ti.saw_min,
        "saw",ciaaw_saw_capi_Ti.saw,
        "saw_u",ciaaw_saw_capi_Ti.saw_u,
        "asaw",ciaaw_saw_capi_Ti.asaw,
        "asaw_u",ciaaw_saw_capi_Ti.asaw_u
    );
    PyDict_SetItemString(d, "Ti", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_V.element,
        "symbol",ciaaw_saw_capi_V.symbol,
        "z",ciaaw_saw_capi_V.z,
        "saw_max",ciaaw_saw_capi_V.saw_max,
        "saw_min",ciaaw_saw_capi_V.saw_min,
        "saw",ciaaw_saw_capi_V.saw,
        "saw_u",ciaaw_saw_capi_V.saw_u,
        "asaw",ciaaw_saw_capi_V.asaw,
        "asaw_u",ciaaw_saw_capi_V.asaw_u
    );
    PyDict_SetItemString(d, "V", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Cr.element,
        "symbol",ciaaw_saw_capi_Cr.symbol,
        "z",ciaaw_saw_capi_Cr.z,
        "saw_max",ciaaw_saw_capi_Cr.saw_max,
        "saw_min",ciaaw_saw_capi_Cr.saw_min,
        "saw",ciaaw_saw_capi_Cr.saw,
        "saw_u",ciaaw_saw_capi_Cr.saw_u,
        "asaw",ciaaw_saw_capi_Cr.asaw,
        "asaw_u",ciaaw_saw_capi_Cr.asaw_u
    );
    PyDict_SetItemString(d, "Cr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Mn.element,
        "symbol",ciaaw_saw_capi_Mn.symbol,
        "z",ciaaw_saw_capi_Mn.z,
        "saw_max",ciaaw_saw_capi_Mn.saw_max,
        "saw_min",ciaaw_saw_capi_Mn.saw_min,
        "saw",ciaaw_saw_capi_Mn.saw,
        "saw_u",ciaaw_saw_capi_Mn.saw_u,
        "asaw",ciaaw_saw_capi_Mn.asaw,
        "asaw_u",ciaaw_saw_capi_Mn.asaw_u
    );
    PyDict_SetItemString(d, "Mn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Fe.element,
        "symbol",ciaaw_saw_capi_Fe.symbol,
        "z",ciaaw_saw_capi_Fe.z,
        "saw_max",ciaaw_saw_capi_Fe.saw_max,
        "saw_min",ciaaw_saw_capi_Fe.saw_min,
        "saw",ciaaw_saw_capi_Fe.saw,
        "saw_u",ciaaw_saw_capi_Fe.saw_u,
        "asaw",ciaaw_saw_capi_Fe.asaw,
        "asaw_u",ciaaw_saw_capi_Fe.asaw_u
    );
    PyDict_SetItemString(d, "Fe", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Co.element,
        "symbol",ciaaw_saw_capi_Co.symbol,
        "z",ciaaw_saw_capi_Co.z,
        "saw_max",ciaaw_saw_capi_Co.saw_max,
        "saw_min",ciaaw_saw_capi_Co.saw_min,
        "saw",ciaaw_saw_capi_Co.saw,
        "saw_u",ciaaw_saw_capi_Co.saw_u,
        "asaw",ciaaw_saw_capi_Co.asaw,
        "asaw_u",ciaaw_saw_capi_Co.asaw_u
    );
    PyDict_SetItemString(d, "Co", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Ni.element,
        "symbol",ciaaw_saw_capi_Ni.symbol,
        "z",ciaaw_saw_capi_Ni.z,
        "saw_max",ciaaw_saw_capi_Ni.saw_max,
        "saw_min",ciaaw_saw_capi_Ni.saw_min,
        "saw",ciaaw_saw_capi_Ni.saw,
        "saw_u",ciaaw_saw_capi_Ni.saw_u,
        "asaw",ciaaw_saw_capi_Ni.asaw,
        "asaw_u",ciaaw_saw_capi_Ni.asaw_u
    );
    PyDict_SetItemString(d, "Ni", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Cu.element,
        "symbol",ciaaw_saw_capi_Cu.symbol,
        "z",ciaaw_saw_capi_Cu.z,
        "saw_max",ciaaw_saw_capi_Cu.saw_max,
        "saw_min",ciaaw_saw_capi_Cu.saw_min,
        "saw",ciaaw_saw_capi_Cu.saw,
        "saw_u",ciaaw_saw_capi_Cu.saw_u,
        "asaw",ciaaw_saw_capi_Cu.asaw,
        "asaw_u",ciaaw_saw_capi_Cu.asaw_u
    );
    PyDict_SetItemString(d, "Cu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Zn.element,
        "symbol",ciaaw_saw_capi_Zn.symbol,
        "z",ciaaw_saw_capi_Zn.z,
        "saw_max",ciaaw_saw_capi_Zn.saw_max,
        "saw_min",ciaaw_saw_capi_Zn.saw_min,
        "saw",ciaaw_saw_capi_Zn.saw,
        "saw_u",ciaaw_saw_capi_Zn.saw_u,
        "asaw",ciaaw_saw_capi_Zn.asaw,
        "asaw_u",ciaaw_saw_capi_Zn.asaw_u
    );
    PyDict_SetItemString(d, "Zn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Ga.element,
        "symbol",ciaaw_saw_capi_Ga.symbol,
        "z",ciaaw_saw_capi_Ga.z,
        "saw_max",ciaaw_saw_capi_Ga.saw_max,
        "saw_min",ciaaw_saw_capi_Ga.saw_min,
        "saw",ciaaw_saw_capi_Ga.saw,
        "saw_u",ciaaw_saw_capi_Ga.saw_u,
        "asaw",ciaaw_saw_capi_Ga.asaw,
        "asaw_u",ciaaw_saw_capi_Ga.asaw_u
    );
    PyDict_SetItemString(d, "Ga", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Ge.element,
        "symbol",ciaaw_saw_capi_Ge.symbol,
        "z",ciaaw_saw_capi_Ge.z,
        "saw_max",ciaaw_saw_capi_Ge.saw_max,
        "saw_min",ciaaw_saw_capi_Ge.saw_min,
        "saw",ciaaw_saw_capi_Ge.saw,
        "saw_u",ciaaw_saw_capi_Ge.saw_u,
        "asaw",ciaaw_saw_capi_Ge.asaw,
        "asaw_u",ciaaw_saw_capi_Ge.asaw_u
    );
    PyDict_SetItemString(d, "Ge", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_As.element,
        "symbol",ciaaw_saw_capi_As.symbol,
        "z",ciaaw_saw_capi_As.z,
        "saw_max",ciaaw_saw_capi_As.saw_max,
        "saw_min",ciaaw_saw_capi_As.saw_min,
        "saw",ciaaw_saw_capi_As.saw,
        "saw_u",ciaaw_saw_capi_As.saw_u,
        "asaw",ciaaw_saw_capi_As.asaw,
        "asaw_u",ciaaw_saw_capi_As.asaw_u
    );
    PyDict_SetItemString(d, "As", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Se.element,
        "symbol",ciaaw_saw_capi_Se.symbol,
        "z",ciaaw_saw_capi_Se.z,
        "saw_max",ciaaw_saw_capi_Se.saw_max,
        "saw_min",ciaaw_saw_capi_Se.saw_min,
        "saw",ciaaw_saw_capi_Se.saw,
        "saw_u",ciaaw_saw_capi_Se.saw_u,
        "asaw",ciaaw_saw_capi_Se.asaw,
        "asaw_u",ciaaw_saw_capi_Se.asaw_u
    );
    PyDict_SetItemString(d, "Se", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Br.element,
        "symbol",ciaaw_saw_capi_Br.symbol,
        "z",ciaaw_saw_capi_Br.z,
        "saw_max",ciaaw_saw_capi_Br.saw_max,
        "saw_min",ciaaw_saw_capi_Br.saw_min,
        "saw",ciaaw_saw_capi_Br.saw,
        "saw_u",ciaaw_saw_capi_Br.saw_u,
        "asaw",ciaaw_saw_capi_Br.asaw,
        "asaw_u",ciaaw_saw_capi_Br.asaw_u
    );
    PyDict_SetItemString(d, "Br", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Kr.element,
        "symbol",ciaaw_saw_capi_Kr.symbol,
        "z",ciaaw_saw_capi_Kr.z,
        "saw_max",ciaaw_saw_capi_Kr.saw_max,
        "saw_min",ciaaw_saw_capi_Kr.saw_min,
        "saw",ciaaw_saw_capi_Kr.saw,
        "saw_u",ciaaw_saw_capi_Kr.saw_u,
        "asaw",ciaaw_saw_capi_Kr.asaw,
        "asaw_u",ciaaw_saw_capi_Kr.asaw_u
    );
    PyDict_SetItemString(d, "Kr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d}",
        "element",ciaaw_saw_capi_Tc.element,
        "symbol",ciaaw_saw_capi_Tc.symbol,
        "z",ciaaw_saw_capi_Tc.z,
        "saw_max",ciaaw_saw_capi_Tc.saw_max,
        "saw_min",ciaaw_saw_capi_Tc.saw_min,
        "saw",ciaaw_saw_capi_Tc.saw,
        "saw_u",ciaaw_saw_capi_Tc.saw_u,
        "asaw",ciaaw_saw_capi_Tc.asaw,
        "asaw_u",ciaaw_saw_capi_Tc.asaw_u
    );
    PyDict_SetItemString(d, "Tc", element);
    Py_INCREF(element);

    return m;
}

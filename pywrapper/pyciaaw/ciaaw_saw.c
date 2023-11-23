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

    return m;
}

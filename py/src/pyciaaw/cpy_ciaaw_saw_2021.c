#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "ciaaw.h"

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

    v = PyLong_FromLong(ciaaw_saw_YEAR);
    PyDict_SetItemString(d, "YEAR", v);
    Py_INCREF(v);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_H.element,
    "symbol", ciaaw_saw_H.symbol,
    "z", ciaaw_saw_H.z,
    "saw_min", ciaaw_saw_H.saw_min,
    "saw_max", ciaaw_saw_H.saw_max,
    "saw", ciaaw_saw_H.saw,
    "saw_u", ciaaw_saw_H.saw_u,
    "asaw", ciaaw_saw_H.asaw,
    "asaw_u", ciaaw_saw_H.asaw_u,
    "footnotes", ciaaw_saw_H.footnotes
    );
    PyDict_SetItemString(d, "H", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_He.element,
    "symbol", ciaaw_saw_He.symbol,
    "z", ciaaw_saw_He.z,
    "saw_min", ciaaw_saw_He.saw_min,
    "saw_max", ciaaw_saw_He.saw_max,
    "saw", ciaaw_saw_He.saw,
    "saw_u", ciaaw_saw_He.saw_u,
    "asaw", ciaaw_saw_He.asaw,
    "asaw_u", ciaaw_saw_He.asaw_u,
    "footnotes", ciaaw_saw_He.footnotes
    );
    PyDict_SetItemString(d, "He", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Li.element,
    "symbol", ciaaw_saw_Li.symbol,
    "z", ciaaw_saw_Li.z,
    "saw_min", ciaaw_saw_Li.saw_min,
    "saw_max", ciaaw_saw_Li.saw_max,
    "saw", ciaaw_saw_Li.saw,
    "saw_u", ciaaw_saw_Li.saw_u,
    "asaw", ciaaw_saw_Li.asaw,
    "asaw_u", ciaaw_saw_Li.asaw_u,
    "footnotes", ciaaw_saw_Li.footnotes
    );
    PyDict_SetItemString(d, "Li", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Be.element,
    "symbol", ciaaw_saw_Be.symbol,
    "z", ciaaw_saw_Be.z,
    "saw_min", ciaaw_saw_Be.saw_min,
    "saw_max", ciaaw_saw_Be.saw_max,
    "saw", ciaaw_saw_Be.saw,
    "saw_u", ciaaw_saw_Be.saw_u,
    "asaw", ciaaw_saw_Be.asaw,
    "asaw_u", ciaaw_saw_Be.asaw_u,
    "footnotes", ciaaw_saw_Be.footnotes
    );
    PyDict_SetItemString(d, "Be", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_B.element,
    "symbol", ciaaw_saw_B.symbol,
    "z", ciaaw_saw_B.z,
    "saw_min", ciaaw_saw_B.saw_min,
    "saw_max", ciaaw_saw_B.saw_max,
    "saw", ciaaw_saw_B.saw,
    "saw_u", ciaaw_saw_B.saw_u,
    "asaw", ciaaw_saw_B.asaw,
    "asaw_u", ciaaw_saw_B.asaw_u,
    "footnotes", ciaaw_saw_B.footnotes
    );
    PyDict_SetItemString(d, "B", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_C.element,
    "symbol", ciaaw_saw_C.symbol,
    "z", ciaaw_saw_C.z,
    "saw_min", ciaaw_saw_C.saw_min,
    "saw_max", ciaaw_saw_C.saw_max,
    "saw", ciaaw_saw_C.saw,
    "saw_u", ciaaw_saw_C.saw_u,
    "asaw", ciaaw_saw_C.asaw,
    "asaw_u", ciaaw_saw_C.asaw_u,
    "footnotes", ciaaw_saw_C.footnotes
    );
    PyDict_SetItemString(d, "C", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_N.element,
    "symbol", ciaaw_saw_N.symbol,
    "z", ciaaw_saw_N.z,
    "saw_min", ciaaw_saw_N.saw_min,
    "saw_max", ciaaw_saw_N.saw_max,
    "saw", ciaaw_saw_N.saw,
    "saw_u", ciaaw_saw_N.saw_u,
    "asaw", ciaaw_saw_N.asaw,
    "asaw_u", ciaaw_saw_N.asaw_u,
    "footnotes", ciaaw_saw_N.footnotes
    );
    PyDict_SetItemString(d, "N", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_O.element,
    "symbol", ciaaw_saw_O.symbol,
    "z", ciaaw_saw_O.z,
    "saw_min", ciaaw_saw_O.saw_min,
    "saw_max", ciaaw_saw_O.saw_max,
    "saw", ciaaw_saw_O.saw,
    "saw_u", ciaaw_saw_O.saw_u,
    "asaw", ciaaw_saw_O.asaw,
    "asaw_u", ciaaw_saw_O.asaw_u,
    "footnotes", ciaaw_saw_O.footnotes
    );
    PyDict_SetItemString(d, "O", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_F.element,
    "symbol", ciaaw_saw_F.symbol,
    "z", ciaaw_saw_F.z,
    "saw_min", ciaaw_saw_F.saw_min,
    "saw_max", ciaaw_saw_F.saw_max,
    "saw", ciaaw_saw_F.saw,
    "saw_u", ciaaw_saw_F.saw_u,
    "asaw", ciaaw_saw_F.asaw,
    "asaw_u", ciaaw_saw_F.asaw_u,
    "footnotes", ciaaw_saw_F.footnotes
    );
    PyDict_SetItemString(d, "F", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ne.element,
    "symbol", ciaaw_saw_Ne.symbol,
    "z", ciaaw_saw_Ne.z,
    "saw_min", ciaaw_saw_Ne.saw_min,
    "saw_max", ciaaw_saw_Ne.saw_max,
    "saw", ciaaw_saw_Ne.saw,
    "saw_u", ciaaw_saw_Ne.saw_u,
    "asaw", ciaaw_saw_Ne.asaw,
    "asaw_u", ciaaw_saw_Ne.asaw_u,
    "footnotes", ciaaw_saw_Ne.footnotes
    );
    PyDict_SetItemString(d, "Ne", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Na.element,
    "symbol", ciaaw_saw_Na.symbol,
    "z", ciaaw_saw_Na.z,
    "saw_min", ciaaw_saw_Na.saw_min,
    "saw_max", ciaaw_saw_Na.saw_max,
    "saw", ciaaw_saw_Na.saw,
    "saw_u", ciaaw_saw_Na.saw_u,
    "asaw", ciaaw_saw_Na.asaw,
    "asaw_u", ciaaw_saw_Na.asaw_u,
    "footnotes", ciaaw_saw_Na.footnotes
    );
    PyDict_SetItemString(d, "Na", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Mg.element,
    "symbol", ciaaw_saw_Mg.symbol,
    "z", ciaaw_saw_Mg.z,
    "saw_min", ciaaw_saw_Mg.saw_min,
    "saw_max", ciaaw_saw_Mg.saw_max,
    "saw", ciaaw_saw_Mg.saw,
    "saw_u", ciaaw_saw_Mg.saw_u,
    "asaw", ciaaw_saw_Mg.asaw,
    "asaw_u", ciaaw_saw_Mg.asaw_u,
    "footnotes", ciaaw_saw_Mg.footnotes
    );
    PyDict_SetItemString(d, "Mg", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Al.element,
    "symbol", ciaaw_saw_Al.symbol,
    "z", ciaaw_saw_Al.z,
    "saw_min", ciaaw_saw_Al.saw_min,
    "saw_max", ciaaw_saw_Al.saw_max,
    "saw", ciaaw_saw_Al.saw,
    "saw_u", ciaaw_saw_Al.saw_u,
    "asaw", ciaaw_saw_Al.asaw,
    "asaw_u", ciaaw_saw_Al.asaw_u,
    "footnotes", ciaaw_saw_Al.footnotes
    );
    PyDict_SetItemString(d, "Al", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Si.element,
    "symbol", ciaaw_saw_Si.symbol,
    "z", ciaaw_saw_Si.z,
    "saw_min", ciaaw_saw_Si.saw_min,
    "saw_max", ciaaw_saw_Si.saw_max,
    "saw", ciaaw_saw_Si.saw,
    "saw_u", ciaaw_saw_Si.saw_u,
    "asaw", ciaaw_saw_Si.asaw,
    "asaw_u", ciaaw_saw_Si.asaw_u,
    "footnotes", ciaaw_saw_Si.footnotes
    );
    PyDict_SetItemString(d, "Si", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_P.element,
    "symbol", ciaaw_saw_P.symbol,
    "z", ciaaw_saw_P.z,
    "saw_min", ciaaw_saw_P.saw_min,
    "saw_max", ciaaw_saw_P.saw_max,
    "saw", ciaaw_saw_P.saw,
    "saw_u", ciaaw_saw_P.saw_u,
    "asaw", ciaaw_saw_P.asaw,
    "asaw_u", ciaaw_saw_P.asaw_u,
    "footnotes", ciaaw_saw_P.footnotes
    );
    PyDict_SetItemString(d, "P", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_S.element,
    "symbol", ciaaw_saw_S.symbol,
    "z", ciaaw_saw_S.z,
    "saw_min", ciaaw_saw_S.saw_min,
    "saw_max", ciaaw_saw_S.saw_max,
    "saw", ciaaw_saw_S.saw,
    "saw_u", ciaaw_saw_S.saw_u,
    "asaw", ciaaw_saw_S.asaw,
    "asaw_u", ciaaw_saw_S.asaw_u,
    "footnotes", ciaaw_saw_S.footnotes
    );
    PyDict_SetItemString(d, "S", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Cl.element,
    "symbol", ciaaw_saw_Cl.symbol,
    "z", ciaaw_saw_Cl.z,
    "saw_min", ciaaw_saw_Cl.saw_min,
    "saw_max", ciaaw_saw_Cl.saw_max,
    "saw", ciaaw_saw_Cl.saw,
    "saw_u", ciaaw_saw_Cl.saw_u,
    "asaw", ciaaw_saw_Cl.asaw,
    "asaw_u", ciaaw_saw_Cl.asaw_u,
    "footnotes", ciaaw_saw_Cl.footnotes
    );
    PyDict_SetItemString(d, "Cl", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ar.element,
    "symbol", ciaaw_saw_Ar.symbol,
    "z", ciaaw_saw_Ar.z,
    "saw_min", ciaaw_saw_Ar.saw_min,
    "saw_max", ciaaw_saw_Ar.saw_max,
    "saw", ciaaw_saw_Ar.saw,
    "saw_u", ciaaw_saw_Ar.saw_u,
    "asaw", ciaaw_saw_Ar.asaw,
    "asaw_u", ciaaw_saw_Ar.asaw_u,
    "footnotes", ciaaw_saw_Ar.footnotes
    );
    PyDict_SetItemString(d, "Ar", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_K.element,
    "symbol", ciaaw_saw_K.symbol,
    "z", ciaaw_saw_K.z,
    "saw_min", ciaaw_saw_K.saw_min,
    "saw_max", ciaaw_saw_K.saw_max,
    "saw", ciaaw_saw_K.saw,
    "saw_u", ciaaw_saw_K.saw_u,
    "asaw", ciaaw_saw_K.asaw,
    "asaw_u", ciaaw_saw_K.asaw_u,
    "footnotes", ciaaw_saw_K.footnotes
    );
    PyDict_SetItemString(d, "K", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ca.element,
    "symbol", ciaaw_saw_Ca.symbol,
    "z", ciaaw_saw_Ca.z,
    "saw_min", ciaaw_saw_Ca.saw_min,
    "saw_max", ciaaw_saw_Ca.saw_max,
    "saw", ciaaw_saw_Ca.saw,
    "saw_u", ciaaw_saw_Ca.saw_u,
    "asaw", ciaaw_saw_Ca.asaw,
    "asaw_u", ciaaw_saw_Ca.asaw_u,
    "footnotes", ciaaw_saw_Ca.footnotes
    );
    PyDict_SetItemString(d, "Ca", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Sc.element,
    "symbol", ciaaw_saw_Sc.symbol,
    "z", ciaaw_saw_Sc.z,
    "saw_min", ciaaw_saw_Sc.saw_min,
    "saw_max", ciaaw_saw_Sc.saw_max,
    "saw", ciaaw_saw_Sc.saw,
    "saw_u", ciaaw_saw_Sc.saw_u,
    "asaw", ciaaw_saw_Sc.asaw,
    "asaw_u", ciaaw_saw_Sc.asaw_u,
    "footnotes", ciaaw_saw_Sc.footnotes
    );
    PyDict_SetItemString(d, "Sc", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ti.element,
    "symbol", ciaaw_saw_Ti.symbol,
    "z", ciaaw_saw_Ti.z,
    "saw_min", ciaaw_saw_Ti.saw_min,
    "saw_max", ciaaw_saw_Ti.saw_max,
    "saw", ciaaw_saw_Ti.saw,
    "saw_u", ciaaw_saw_Ti.saw_u,
    "asaw", ciaaw_saw_Ti.asaw,
    "asaw_u", ciaaw_saw_Ti.asaw_u,
    "footnotes", ciaaw_saw_Ti.footnotes
    );
    PyDict_SetItemString(d, "Ti", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_V.element,
    "symbol", ciaaw_saw_V.symbol,
    "z", ciaaw_saw_V.z,
    "saw_min", ciaaw_saw_V.saw_min,
    "saw_max", ciaaw_saw_V.saw_max,
    "saw", ciaaw_saw_V.saw,
    "saw_u", ciaaw_saw_V.saw_u,
    "asaw", ciaaw_saw_V.asaw,
    "asaw_u", ciaaw_saw_V.asaw_u,
    "footnotes", ciaaw_saw_V.footnotes
    );
    PyDict_SetItemString(d, "V", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Cr.element,
    "symbol", ciaaw_saw_Cr.symbol,
    "z", ciaaw_saw_Cr.z,
    "saw_min", ciaaw_saw_Cr.saw_min,
    "saw_max", ciaaw_saw_Cr.saw_max,
    "saw", ciaaw_saw_Cr.saw,
    "saw_u", ciaaw_saw_Cr.saw_u,
    "asaw", ciaaw_saw_Cr.asaw,
    "asaw_u", ciaaw_saw_Cr.asaw_u,
    "footnotes", ciaaw_saw_Cr.footnotes
    );
    PyDict_SetItemString(d, "Cr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Mn.element,
    "symbol", ciaaw_saw_Mn.symbol,
    "z", ciaaw_saw_Mn.z,
    "saw_min", ciaaw_saw_Mn.saw_min,
    "saw_max", ciaaw_saw_Mn.saw_max,
    "saw", ciaaw_saw_Mn.saw,
    "saw_u", ciaaw_saw_Mn.saw_u,
    "asaw", ciaaw_saw_Mn.asaw,
    "asaw_u", ciaaw_saw_Mn.asaw_u,
    "footnotes", ciaaw_saw_Mn.footnotes
    );
    PyDict_SetItemString(d, "Mn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Fe.element,
    "symbol", ciaaw_saw_Fe.symbol,
    "z", ciaaw_saw_Fe.z,
    "saw_min", ciaaw_saw_Fe.saw_min,
    "saw_max", ciaaw_saw_Fe.saw_max,
    "saw", ciaaw_saw_Fe.saw,
    "saw_u", ciaaw_saw_Fe.saw_u,
    "asaw", ciaaw_saw_Fe.asaw,
    "asaw_u", ciaaw_saw_Fe.asaw_u,
    "footnotes", ciaaw_saw_Fe.footnotes
    );
    PyDict_SetItemString(d, "Fe", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Co.element,
    "symbol", ciaaw_saw_Co.symbol,
    "z", ciaaw_saw_Co.z,
    "saw_min", ciaaw_saw_Co.saw_min,
    "saw_max", ciaaw_saw_Co.saw_max,
    "saw", ciaaw_saw_Co.saw,
    "saw_u", ciaaw_saw_Co.saw_u,
    "asaw", ciaaw_saw_Co.asaw,
    "asaw_u", ciaaw_saw_Co.asaw_u,
    "footnotes", ciaaw_saw_Co.footnotes
    );
    PyDict_SetItemString(d, "Co", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ni.element,
    "symbol", ciaaw_saw_Ni.symbol,
    "z", ciaaw_saw_Ni.z,
    "saw_min", ciaaw_saw_Ni.saw_min,
    "saw_max", ciaaw_saw_Ni.saw_max,
    "saw", ciaaw_saw_Ni.saw,
    "saw_u", ciaaw_saw_Ni.saw_u,
    "asaw", ciaaw_saw_Ni.asaw,
    "asaw_u", ciaaw_saw_Ni.asaw_u,
    "footnotes", ciaaw_saw_Ni.footnotes
    );
    PyDict_SetItemString(d, "Ni", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Cu.element,
    "symbol", ciaaw_saw_Cu.symbol,
    "z", ciaaw_saw_Cu.z,
    "saw_min", ciaaw_saw_Cu.saw_min,
    "saw_max", ciaaw_saw_Cu.saw_max,
    "saw", ciaaw_saw_Cu.saw,
    "saw_u", ciaaw_saw_Cu.saw_u,
    "asaw", ciaaw_saw_Cu.asaw,
    "asaw_u", ciaaw_saw_Cu.asaw_u,
    "footnotes", ciaaw_saw_Cu.footnotes
    );
    PyDict_SetItemString(d, "Cu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Zn.element,
    "symbol", ciaaw_saw_Zn.symbol,
    "z", ciaaw_saw_Zn.z,
    "saw_min", ciaaw_saw_Zn.saw_min,
    "saw_max", ciaaw_saw_Zn.saw_max,
    "saw", ciaaw_saw_Zn.saw,
    "saw_u", ciaaw_saw_Zn.saw_u,
    "asaw", ciaaw_saw_Zn.asaw,
    "asaw_u", ciaaw_saw_Zn.asaw_u,
    "footnotes", ciaaw_saw_Zn.footnotes
    );
    PyDict_SetItemString(d, "Zn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ga.element,
    "symbol", ciaaw_saw_Ga.symbol,
    "z", ciaaw_saw_Ga.z,
    "saw_min", ciaaw_saw_Ga.saw_min,
    "saw_max", ciaaw_saw_Ga.saw_max,
    "saw", ciaaw_saw_Ga.saw,
    "saw_u", ciaaw_saw_Ga.saw_u,
    "asaw", ciaaw_saw_Ga.asaw,
    "asaw_u", ciaaw_saw_Ga.asaw_u,
    "footnotes", ciaaw_saw_Ga.footnotes
    );
    PyDict_SetItemString(d, "Ga", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ge.element,
    "symbol", ciaaw_saw_Ge.symbol,
    "z", ciaaw_saw_Ge.z,
    "saw_min", ciaaw_saw_Ge.saw_min,
    "saw_max", ciaaw_saw_Ge.saw_max,
    "saw", ciaaw_saw_Ge.saw,
    "saw_u", ciaaw_saw_Ge.saw_u,
    "asaw", ciaaw_saw_Ge.asaw,
    "asaw_u", ciaaw_saw_Ge.asaw_u,
    "footnotes", ciaaw_saw_Ge.footnotes
    );
    PyDict_SetItemString(d, "Ge", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_As.element,
    "symbol", ciaaw_saw_As.symbol,
    "z", ciaaw_saw_As.z,
    "saw_min", ciaaw_saw_As.saw_min,
    "saw_max", ciaaw_saw_As.saw_max,
    "saw", ciaaw_saw_As.saw,
    "saw_u", ciaaw_saw_As.saw_u,
    "asaw", ciaaw_saw_As.asaw,
    "asaw_u", ciaaw_saw_As.asaw_u,
    "footnotes", ciaaw_saw_As.footnotes
    );
    PyDict_SetItemString(d, "As", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Se.element,
    "symbol", ciaaw_saw_Se.symbol,
    "z", ciaaw_saw_Se.z,
    "saw_min", ciaaw_saw_Se.saw_min,
    "saw_max", ciaaw_saw_Se.saw_max,
    "saw", ciaaw_saw_Se.saw,
    "saw_u", ciaaw_saw_Se.saw_u,
    "asaw", ciaaw_saw_Se.asaw,
    "asaw_u", ciaaw_saw_Se.asaw_u,
    "footnotes", ciaaw_saw_Se.footnotes
    );
    PyDict_SetItemString(d, "Se", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Br.element,
    "symbol", ciaaw_saw_Br.symbol,
    "z", ciaaw_saw_Br.z,
    "saw_min", ciaaw_saw_Br.saw_min,
    "saw_max", ciaaw_saw_Br.saw_max,
    "saw", ciaaw_saw_Br.saw,
    "saw_u", ciaaw_saw_Br.saw_u,
    "asaw", ciaaw_saw_Br.asaw,
    "asaw_u", ciaaw_saw_Br.asaw_u,
    "footnotes", ciaaw_saw_Br.footnotes
    );
    PyDict_SetItemString(d, "Br", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Kr.element,
    "symbol", ciaaw_saw_Kr.symbol,
    "z", ciaaw_saw_Kr.z,
    "saw_min", ciaaw_saw_Kr.saw_min,
    "saw_max", ciaaw_saw_Kr.saw_max,
    "saw", ciaaw_saw_Kr.saw,
    "saw_u", ciaaw_saw_Kr.saw_u,
    "asaw", ciaaw_saw_Kr.asaw,
    "asaw_u", ciaaw_saw_Kr.asaw_u,
    "footnotes", ciaaw_saw_Kr.footnotes
    );
    PyDict_SetItemString(d, "Kr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Rb.element,
    "symbol", ciaaw_saw_Rb.symbol,
    "z", ciaaw_saw_Rb.z,
    "saw_min", ciaaw_saw_Rb.saw_min,
    "saw_max", ciaaw_saw_Rb.saw_max,
    "saw", ciaaw_saw_Rb.saw,
    "saw_u", ciaaw_saw_Rb.saw_u,
    "asaw", ciaaw_saw_Rb.asaw,
    "asaw_u", ciaaw_saw_Rb.asaw_u,
    "footnotes", ciaaw_saw_Rb.footnotes
    );
    PyDict_SetItemString(d, "Rb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Sr.element,
    "symbol", ciaaw_saw_Sr.symbol,
    "z", ciaaw_saw_Sr.z,
    "saw_min", ciaaw_saw_Sr.saw_min,
    "saw_max", ciaaw_saw_Sr.saw_max,
    "saw", ciaaw_saw_Sr.saw,
    "saw_u", ciaaw_saw_Sr.saw_u,
    "asaw", ciaaw_saw_Sr.asaw,
    "asaw_u", ciaaw_saw_Sr.asaw_u,
    "footnotes", ciaaw_saw_Sr.footnotes
    );
    PyDict_SetItemString(d, "Sr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Y.element,
    "symbol", ciaaw_saw_Y.symbol,
    "z", ciaaw_saw_Y.z,
    "saw_min", ciaaw_saw_Y.saw_min,
    "saw_max", ciaaw_saw_Y.saw_max,
    "saw", ciaaw_saw_Y.saw,
    "saw_u", ciaaw_saw_Y.saw_u,
    "asaw", ciaaw_saw_Y.asaw,
    "asaw_u", ciaaw_saw_Y.asaw_u,
    "footnotes", ciaaw_saw_Y.footnotes
    );
    PyDict_SetItemString(d, "Y", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Zr.element,
    "symbol", ciaaw_saw_Zr.symbol,
    "z", ciaaw_saw_Zr.z,
    "saw_min", ciaaw_saw_Zr.saw_min,
    "saw_max", ciaaw_saw_Zr.saw_max,
    "saw", ciaaw_saw_Zr.saw,
    "saw_u", ciaaw_saw_Zr.saw_u,
    "asaw", ciaaw_saw_Zr.asaw,
    "asaw_u", ciaaw_saw_Zr.asaw_u,
    "footnotes", ciaaw_saw_Zr.footnotes
    );
    PyDict_SetItemString(d, "Zr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Nb.element,
    "symbol", ciaaw_saw_Nb.symbol,
    "z", ciaaw_saw_Nb.z,
    "saw_min", ciaaw_saw_Nb.saw_min,
    "saw_max", ciaaw_saw_Nb.saw_max,
    "saw", ciaaw_saw_Nb.saw,
    "saw_u", ciaaw_saw_Nb.saw_u,
    "asaw", ciaaw_saw_Nb.asaw,
    "asaw_u", ciaaw_saw_Nb.asaw_u,
    "footnotes", ciaaw_saw_Nb.footnotes
    );
    PyDict_SetItemString(d, "Nb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Mo.element,
    "symbol", ciaaw_saw_Mo.symbol,
    "z", ciaaw_saw_Mo.z,
    "saw_min", ciaaw_saw_Mo.saw_min,
    "saw_max", ciaaw_saw_Mo.saw_max,
    "saw", ciaaw_saw_Mo.saw,
    "saw_u", ciaaw_saw_Mo.saw_u,
    "asaw", ciaaw_saw_Mo.asaw,
    "asaw_u", ciaaw_saw_Mo.asaw_u,
    "footnotes", ciaaw_saw_Mo.footnotes
    );
    PyDict_SetItemString(d, "Mo", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Tc.element,
    "symbol", ciaaw_saw_Tc.symbol,
    "z", ciaaw_saw_Tc.z,
    "saw_min", ciaaw_saw_Tc.saw_min,
    "saw_max", ciaaw_saw_Tc.saw_max,
    "saw", ciaaw_saw_Tc.saw,
    "saw_u", ciaaw_saw_Tc.saw_u,
    "asaw", ciaaw_saw_Tc.asaw,
    "asaw_u", ciaaw_saw_Tc.asaw_u,
    "footnotes", ciaaw_saw_Tc.footnotes
    );
    PyDict_SetItemString(d, "Tc", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ru.element,
    "symbol", ciaaw_saw_Ru.symbol,
    "z", ciaaw_saw_Ru.z,
    "saw_min", ciaaw_saw_Ru.saw_min,
    "saw_max", ciaaw_saw_Ru.saw_max,
    "saw", ciaaw_saw_Ru.saw,
    "saw_u", ciaaw_saw_Ru.saw_u,
    "asaw", ciaaw_saw_Ru.asaw,
    "asaw_u", ciaaw_saw_Ru.asaw_u,
    "footnotes", ciaaw_saw_Ru.footnotes
    );
    PyDict_SetItemString(d, "Ru", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Rh.element,
    "symbol", ciaaw_saw_Rh.symbol,
    "z", ciaaw_saw_Rh.z,
    "saw_min", ciaaw_saw_Rh.saw_min,
    "saw_max", ciaaw_saw_Rh.saw_max,
    "saw", ciaaw_saw_Rh.saw,
    "saw_u", ciaaw_saw_Rh.saw_u,
    "asaw", ciaaw_saw_Rh.asaw,
    "asaw_u", ciaaw_saw_Rh.asaw_u,
    "footnotes", ciaaw_saw_Rh.footnotes
    );
    PyDict_SetItemString(d, "Rh", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Pd.element,
    "symbol", ciaaw_saw_Pd.symbol,
    "z", ciaaw_saw_Pd.z,
    "saw_min", ciaaw_saw_Pd.saw_min,
    "saw_max", ciaaw_saw_Pd.saw_max,
    "saw", ciaaw_saw_Pd.saw,
    "saw_u", ciaaw_saw_Pd.saw_u,
    "asaw", ciaaw_saw_Pd.asaw,
    "asaw_u", ciaaw_saw_Pd.asaw_u,
    "footnotes", ciaaw_saw_Pd.footnotes
    );
    PyDict_SetItemString(d, "Pd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ag.element,
    "symbol", ciaaw_saw_Ag.symbol,
    "z", ciaaw_saw_Ag.z,
    "saw_min", ciaaw_saw_Ag.saw_min,
    "saw_max", ciaaw_saw_Ag.saw_max,
    "saw", ciaaw_saw_Ag.saw,
    "saw_u", ciaaw_saw_Ag.saw_u,
    "asaw", ciaaw_saw_Ag.asaw,
    "asaw_u", ciaaw_saw_Ag.asaw_u,
    "footnotes", ciaaw_saw_Ag.footnotes
    );
    PyDict_SetItemString(d, "Ag", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Cd.element,
    "symbol", ciaaw_saw_Cd.symbol,
    "z", ciaaw_saw_Cd.z,
    "saw_min", ciaaw_saw_Cd.saw_min,
    "saw_max", ciaaw_saw_Cd.saw_max,
    "saw", ciaaw_saw_Cd.saw,
    "saw_u", ciaaw_saw_Cd.saw_u,
    "asaw", ciaaw_saw_Cd.asaw,
    "asaw_u", ciaaw_saw_Cd.asaw_u,
    "footnotes", ciaaw_saw_Cd.footnotes
    );
    PyDict_SetItemString(d, "Cd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_In.element,
    "symbol", ciaaw_saw_In.symbol,
    "z", ciaaw_saw_In.z,
    "saw_min", ciaaw_saw_In.saw_min,
    "saw_max", ciaaw_saw_In.saw_max,
    "saw", ciaaw_saw_In.saw,
    "saw_u", ciaaw_saw_In.saw_u,
    "asaw", ciaaw_saw_In.asaw,
    "asaw_u", ciaaw_saw_In.asaw_u,
    "footnotes", ciaaw_saw_In.footnotes
    );
    PyDict_SetItemString(d, "In", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Sn.element,
    "symbol", ciaaw_saw_Sn.symbol,
    "z", ciaaw_saw_Sn.z,
    "saw_min", ciaaw_saw_Sn.saw_min,
    "saw_max", ciaaw_saw_Sn.saw_max,
    "saw", ciaaw_saw_Sn.saw,
    "saw_u", ciaaw_saw_Sn.saw_u,
    "asaw", ciaaw_saw_Sn.asaw,
    "asaw_u", ciaaw_saw_Sn.asaw_u,
    "footnotes", ciaaw_saw_Sn.footnotes
    );
    PyDict_SetItemString(d, "Sn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Sb.element,
    "symbol", ciaaw_saw_Sb.symbol,
    "z", ciaaw_saw_Sb.z,
    "saw_min", ciaaw_saw_Sb.saw_min,
    "saw_max", ciaaw_saw_Sb.saw_max,
    "saw", ciaaw_saw_Sb.saw,
    "saw_u", ciaaw_saw_Sb.saw_u,
    "asaw", ciaaw_saw_Sb.asaw,
    "asaw_u", ciaaw_saw_Sb.asaw_u,
    "footnotes", ciaaw_saw_Sb.footnotes
    );
    PyDict_SetItemString(d, "Sb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Te.element,
    "symbol", ciaaw_saw_Te.symbol,
    "z", ciaaw_saw_Te.z,
    "saw_min", ciaaw_saw_Te.saw_min,
    "saw_max", ciaaw_saw_Te.saw_max,
    "saw", ciaaw_saw_Te.saw,
    "saw_u", ciaaw_saw_Te.saw_u,
    "asaw", ciaaw_saw_Te.asaw,
    "asaw_u", ciaaw_saw_Te.asaw_u,
    "footnotes", ciaaw_saw_Te.footnotes
    );
    PyDict_SetItemString(d, "Te", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_I.element,
    "symbol", ciaaw_saw_I.symbol,
    "z", ciaaw_saw_I.z,
    "saw_min", ciaaw_saw_I.saw_min,
    "saw_max", ciaaw_saw_I.saw_max,
    "saw", ciaaw_saw_I.saw,
    "saw_u", ciaaw_saw_I.saw_u,
    "asaw", ciaaw_saw_I.asaw,
    "asaw_u", ciaaw_saw_I.asaw_u,
    "footnotes", ciaaw_saw_I.footnotes
    );
    PyDict_SetItemString(d, "I", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Xe.element,
    "symbol", ciaaw_saw_Xe.symbol,
    "z", ciaaw_saw_Xe.z,
    "saw_min", ciaaw_saw_Xe.saw_min,
    "saw_max", ciaaw_saw_Xe.saw_max,
    "saw", ciaaw_saw_Xe.saw,
    "saw_u", ciaaw_saw_Xe.saw_u,
    "asaw", ciaaw_saw_Xe.asaw,
    "asaw_u", ciaaw_saw_Xe.asaw_u,
    "footnotes", ciaaw_saw_Xe.footnotes
    );
    PyDict_SetItemString(d, "Xe", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Cs.element,
    "symbol", ciaaw_saw_Cs.symbol,
    "z", ciaaw_saw_Cs.z,
    "saw_min", ciaaw_saw_Cs.saw_min,
    "saw_max", ciaaw_saw_Cs.saw_max,
    "saw", ciaaw_saw_Cs.saw,
    "saw_u", ciaaw_saw_Cs.saw_u,
    "asaw", ciaaw_saw_Cs.asaw,
    "asaw_u", ciaaw_saw_Cs.asaw_u,
    "footnotes", ciaaw_saw_Cs.footnotes
    );
    PyDict_SetItemString(d, "Cs", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ba.element,
    "symbol", ciaaw_saw_Ba.symbol,
    "z", ciaaw_saw_Ba.z,
    "saw_min", ciaaw_saw_Ba.saw_min,
    "saw_max", ciaaw_saw_Ba.saw_max,
    "saw", ciaaw_saw_Ba.saw,
    "saw_u", ciaaw_saw_Ba.saw_u,
    "asaw", ciaaw_saw_Ba.asaw,
    "asaw_u", ciaaw_saw_Ba.asaw_u,
    "footnotes", ciaaw_saw_Ba.footnotes
    );
    PyDict_SetItemString(d, "Ba", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_La.element,
    "symbol", ciaaw_saw_La.symbol,
    "z", ciaaw_saw_La.z,
    "saw_min", ciaaw_saw_La.saw_min,
    "saw_max", ciaaw_saw_La.saw_max,
    "saw", ciaaw_saw_La.saw,
    "saw_u", ciaaw_saw_La.saw_u,
    "asaw", ciaaw_saw_La.asaw,
    "asaw_u", ciaaw_saw_La.asaw_u,
    "footnotes", ciaaw_saw_La.footnotes
    );
    PyDict_SetItemString(d, "La", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ce.element,
    "symbol", ciaaw_saw_Ce.symbol,
    "z", ciaaw_saw_Ce.z,
    "saw_min", ciaaw_saw_Ce.saw_min,
    "saw_max", ciaaw_saw_Ce.saw_max,
    "saw", ciaaw_saw_Ce.saw,
    "saw_u", ciaaw_saw_Ce.saw_u,
    "asaw", ciaaw_saw_Ce.asaw,
    "asaw_u", ciaaw_saw_Ce.asaw_u,
    "footnotes", ciaaw_saw_Ce.footnotes
    );
    PyDict_SetItemString(d, "Ce", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Pr.element,
    "symbol", ciaaw_saw_Pr.symbol,
    "z", ciaaw_saw_Pr.z,
    "saw_min", ciaaw_saw_Pr.saw_min,
    "saw_max", ciaaw_saw_Pr.saw_max,
    "saw", ciaaw_saw_Pr.saw,
    "saw_u", ciaaw_saw_Pr.saw_u,
    "asaw", ciaaw_saw_Pr.asaw,
    "asaw_u", ciaaw_saw_Pr.asaw_u,
    "footnotes", ciaaw_saw_Pr.footnotes
    );
    PyDict_SetItemString(d, "Pr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Nd.element,
    "symbol", ciaaw_saw_Nd.symbol,
    "z", ciaaw_saw_Nd.z,
    "saw_min", ciaaw_saw_Nd.saw_min,
    "saw_max", ciaaw_saw_Nd.saw_max,
    "saw", ciaaw_saw_Nd.saw,
    "saw_u", ciaaw_saw_Nd.saw_u,
    "asaw", ciaaw_saw_Nd.asaw,
    "asaw_u", ciaaw_saw_Nd.asaw_u,
    "footnotes", ciaaw_saw_Nd.footnotes
    );
    PyDict_SetItemString(d, "Nd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Pm.element,
    "symbol", ciaaw_saw_Pm.symbol,
    "z", ciaaw_saw_Pm.z,
    "saw_min", ciaaw_saw_Pm.saw_min,
    "saw_max", ciaaw_saw_Pm.saw_max,
    "saw", ciaaw_saw_Pm.saw,
    "saw_u", ciaaw_saw_Pm.saw_u,
    "asaw", ciaaw_saw_Pm.asaw,
    "asaw_u", ciaaw_saw_Pm.asaw_u,
    "footnotes", ciaaw_saw_Pm.footnotes
    );
    PyDict_SetItemString(d, "Pm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Sm.element,
    "symbol", ciaaw_saw_Sm.symbol,
    "z", ciaaw_saw_Sm.z,
    "saw_min", ciaaw_saw_Sm.saw_min,
    "saw_max", ciaaw_saw_Sm.saw_max,
    "saw", ciaaw_saw_Sm.saw,
    "saw_u", ciaaw_saw_Sm.saw_u,
    "asaw", ciaaw_saw_Sm.asaw,
    "asaw_u", ciaaw_saw_Sm.asaw_u,
    "footnotes", ciaaw_saw_Sm.footnotes
    );
    PyDict_SetItemString(d, "Sm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Eu.element,
    "symbol", ciaaw_saw_Eu.symbol,
    "z", ciaaw_saw_Eu.z,
    "saw_min", ciaaw_saw_Eu.saw_min,
    "saw_max", ciaaw_saw_Eu.saw_max,
    "saw", ciaaw_saw_Eu.saw,
    "saw_u", ciaaw_saw_Eu.saw_u,
    "asaw", ciaaw_saw_Eu.asaw,
    "asaw_u", ciaaw_saw_Eu.asaw_u,
    "footnotes", ciaaw_saw_Eu.footnotes
    );
    PyDict_SetItemString(d, "Eu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Gd.element,
    "symbol", ciaaw_saw_Gd.symbol,
    "z", ciaaw_saw_Gd.z,
    "saw_min", ciaaw_saw_Gd.saw_min,
    "saw_max", ciaaw_saw_Gd.saw_max,
    "saw", ciaaw_saw_Gd.saw,
    "saw_u", ciaaw_saw_Gd.saw_u,
    "asaw", ciaaw_saw_Gd.asaw,
    "asaw_u", ciaaw_saw_Gd.asaw_u,
    "footnotes", ciaaw_saw_Gd.footnotes
    );
    PyDict_SetItemString(d, "Gd", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Tb.element,
    "symbol", ciaaw_saw_Tb.symbol,
    "z", ciaaw_saw_Tb.z,
    "saw_min", ciaaw_saw_Tb.saw_min,
    "saw_max", ciaaw_saw_Tb.saw_max,
    "saw", ciaaw_saw_Tb.saw,
    "saw_u", ciaaw_saw_Tb.saw_u,
    "asaw", ciaaw_saw_Tb.asaw,
    "asaw_u", ciaaw_saw_Tb.asaw_u,
    "footnotes", ciaaw_saw_Tb.footnotes
    );
    PyDict_SetItemString(d, "Tb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Dy.element,
    "symbol", ciaaw_saw_Dy.symbol,
    "z", ciaaw_saw_Dy.z,
    "saw_min", ciaaw_saw_Dy.saw_min,
    "saw_max", ciaaw_saw_Dy.saw_max,
    "saw", ciaaw_saw_Dy.saw,
    "saw_u", ciaaw_saw_Dy.saw_u,
    "asaw", ciaaw_saw_Dy.asaw,
    "asaw_u", ciaaw_saw_Dy.asaw_u,
    "footnotes", ciaaw_saw_Dy.footnotes
    );
    PyDict_SetItemString(d, "Dy", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ho.element,
    "symbol", ciaaw_saw_Ho.symbol,
    "z", ciaaw_saw_Ho.z,
    "saw_min", ciaaw_saw_Ho.saw_min,
    "saw_max", ciaaw_saw_Ho.saw_max,
    "saw", ciaaw_saw_Ho.saw,
    "saw_u", ciaaw_saw_Ho.saw_u,
    "asaw", ciaaw_saw_Ho.asaw,
    "asaw_u", ciaaw_saw_Ho.asaw_u,
    "footnotes", ciaaw_saw_Ho.footnotes
    );
    PyDict_SetItemString(d, "Ho", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Er.element,
    "symbol", ciaaw_saw_Er.symbol,
    "z", ciaaw_saw_Er.z,
    "saw_min", ciaaw_saw_Er.saw_min,
    "saw_max", ciaaw_saw_Er.saw_max,
    "saw", ciaaw_saw_Er.saw,
    "saw_u", ciaaw_saw_Er.saw_u,
    "asaw", ciaaw_saw_Er.asaw,
    "asaw_u", ciaaw_saw_Er.asaw_u,
    "footnotes", ciaaw_saw_Er.footnotes
    );
    PyDict_SetItemString(d, "Er", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Tm.element,
    "symbol", ciaaw_saw_Tm.symbol,
    "z", ciaaw_saw_Tm.z,
    "saw_min", ciaaw_saw_Tm.saw_min,
    "saw_max", ciaaw_saw_Tm.saw_max,
    "saw", ciaaw_saw_Tm.saw,
    "saw_u", ciaaw_saw_Tm.saw_u,
    "asaw", ciaaw_saw_Tm.asaw,
    "asaw_u", ciaaw_saw_Tm.asaw_u,
    "footnotes", ciaaw_saw_Tm.footnotes
    );
    PyDict_SetItemString(d, "Tm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Yb.element,
    "symbol", ciaaw_saw_Yb.symbol,
    "z", ciaaw_saw_Yb.z,
    "saw_min", ciaaw_saw_Yb.saw_min,
    "saw_max", ciaaw_saw_Yb.saw_max,
    "saw", ciaaw_saw_Yb.saw,
    "saw_u", ciaaw_saw_Yb.saw_u,
    "asaw", ciaaw_saw_Yb.asaw,
    "asaw_u", ciaaw_saw_Yb.asaw_u,
    "footnotes", ciaaw_saw_Yb.footnotes
    );
    PyDict_SetItemString(d, "Yb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Lu.element,
    "symbol", ciaaw_saw_Lu.symbol,
    "z", ciaaw_saw_Lu.z,
    "saw_min", ciaaw_saw_Lu.saw_min,
    "saw_max", ciaaw_saw_Lu.saw_max,
    "saw", ciaaw_saw_Lu.saw,
    "saw_u", ciaaw_saw_Lu.saw_u,
    "asaw", ciaaw_saw_Lu.asaw,
    "asaw_u", ciaaw_saw_Lu.asaw_u,
    "footnotes", ciaaw_saw_Lu.footnotes
    );
    PyDict_SetItemString(d, "Lu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Hf.element,
    "symbol", ciaaw_saw_Hf.symbol,
    "z", ciaaw_saw_Hf.z,
    "saw_min", ciaaw_saw_Hf.saw_min,
    "saw_max", ciaaw_saw_Hf.saw_max,
    "saw", ciaaw_saw_Hf.saw,
    "saw_u", ciaaw_saw_Hf.saw_u,
    "asaw", ciaaw_saw_Hf.asaw,
    "asaw_u", ciaaw_saw_Hf.asaw_u,
    "footnotes", ciaaw_saw_Hf.footnotes
    );
    PyDict_SetItemString(d, "Hf", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ta.element,
    "symbol", ciaaw_saw_Ta.symbol,
    "z", ciaaw_saw_Ta.z,
    "saw_min", ciaaw_saw_Ta.saw_min,
    "saw_max", ciaaw_saw_Ta.saw_max,
    "saw", ciaaw_saw_Ta.saw,
    "saw_u", ciaaw_saw_Ta.saw_u,
    "asaw", ciaaw_saw_Ta.asaw,
    "asaw_u", ciaaw_saw_Ta.asaw_u,
    "footnotes", ciaaw_saw_Ta.footnotes
    );
    PyDict_SetItemString(d, "Ta", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_W.element,
    "symbol", ciaaw_saw_W.symbol,
    "z", ciaaw_saw_W.z,
    "saw_min", ciaaw_saw_W.saw_min,
    "saw_max", ciaaw_saw_W.saw_max,
    "saw", ciaaw_saw_W.saw,
    "saw_u", ciaaw_saw_W.saw_u,
    "asaw", ciaaw_saw_W.asaw,
    "asaw_u", ciaaw_saw_W.asaw_u,
    "footnotes", ciaaw_saw_W.footnotes
    );
    PyDict_SetItemString(d, "W", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Re.element,
    "symbol", ciaaw_saw_Re.symbol,
    "z", ciaaw_saw_Re.z,
    "saw_min", ciaaw_saw_Re.saw_min,
    "saw_max", ciaaw_saw_Re.saw_max,
    "saw", ciaaw_saw_Re.saw,
    "saw_u", ciaaw_saw_Re.saw_u,
    "asaw", ciaaw_saw_Re.asaw,
    "asaw_u", ciaaw_saw_Re.asaw_u,
    "footnotes", ciaaw_saw_Re.footnotes
    );
    PyDict_SetItemString(d, "Re", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Os.element,
    "symbol", ciaaw_saw_Os.symbol,
    "z", ciaaw_saw_Os.z,
    "saw_min", ciaaw_saw_Os.saw_min,
    "saw_max", ciaaw_saw_Os.saw_max,
    "saw", ciaaw_saw_Os.saw,
    "saw_u", ciaaw_saw_Os.saw_u,
    "asaw", ciaaw_saw_Os.asaw,
    "asaw_u", ciaaw_saw_Os.asaw_u,
    "footnotes", ciaaw_saw_Os.footnotes
    );
    PyDict_SetItemString(d, "Os", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ir.element,
    "symbol", ciaaw_saw_Ir.symbol,
    "z", ciaaw_saw_Ir.z,
    "saw_min", ciaaw_saw_Ir.saw_min,
    "saw_max", ciaaw_saw_Ir.saw_max,
    "saw", ciaaw_saw_Ir.saw,
    "saw_u", ciaaw_saw_Ir.saw_u,
    "asaw", ciaaw_saw_Ir.asaw,
    "asaw_u", ciaaw_saw_Ir.asaw_u,
    "footnotes", ciaaw_saw_Ir.footnotes
    );
    PyDict_SetItemString(d, "Ir", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Pt.element,
    "symbol", ciaaw_saw_Pt.symbol,
    "z", ciaaw_saw_Pt.z,
    "saw_min", ciaaw_saw_Pt.saw_min,
    "saw_max", ciaaw_saw_Pt.saw_max,
    "saw", ciaaw_saw_Pt.saw,
    "saw_u", ciaaw_saw_Pt.saw_u,
    "asaw", ciaaw_saw_Pt.asaw,
    "asaw_u", ciaaw_saw_Pt.asaw_u,
    "footnotes", ciaaw_saw_Pt.footnotes
    );
    PyDict_SetItemString(d, "Pt", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Au.element,
    "symbol", ciaaw_saw_Au.symbol,
    "z", ciaaw_saw_Au.z,
    "saw_min", ciaaw_saw_Au.saw_min,
    "saw_max", ciaaw_saw_Au.saw_max,
    "saw", ciaaw_saw_Au.saw,
    "saw_u", ciaaw_saw_Au.saw_u,
    "asaw", ciaaw_saw_Au.asaw,
    "asaw_u", ciaaw_saw_Au.asaw_u,
    "footnotes", ciaaw_saw_Au.footnotes
    );
    PyDict_SetItemString(d, "Au", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Hg.element,
    "symbol", ciaaw_saw_Hg.symbol,
    "z", ciaaw_saw_Hg.z,
    "saw_min", ciaaw_saw_Hg.saw_min,
    "saw_max", ciaaw_saw_Hg.saw_max,
    "saw", ciaaw_saw_Hg.saw,
    "saw_u", ciaaw_saw_Hg.saw_u,
    "asaw", ciaaw_saw_Hg.asaw,
    "asaw_u", ciaaw_saw_Hg.asaw_u,
    "footnotes", ciaaw_saw_Hg.footnotes
    );
    PyDict_SetItemString(d, "Hg", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Tl.element,
    "symbol", ciaaw_saw_Tl.symbol,
    "z", ciaaw_saw_Tl.z,
    "saw_min", ciaaw_saw_Tl.saw_min,
    "saw_max", ciaaw_saw_Tl.saw_max,
    "saw", ciaaw_saw_Tl.saw,
    "saw_u", ciaaw_saw_Tl.saw_u,
    "asaw", ciaaw_saw_Tl.asaw,
    "asaw_u", ciaaw_saw_Tl.asaw_u,
    "footnotes", ciaaw_saw_Tl.footnotes
    );
    PyDict_SetItemString(d, "Tl", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Pb.element,
    "symbol", ciaaw_saw_Pb.symbol,
    "z", ciaaw_saw_Pb.z,
    "saw_min", ciaaw_saw_Pb.saw_min,
    "saw_max", ciaaw_saw_Pb.saw_max,
    "saw", ciaaw_saw_Pb.saw,
    "saw_u", ciaaw_saw_Pb.saw_u,
    "asaw", ciaaw_saw_Pb.asaw,
    "asaw_u", ciaaw_saw_Pb.asaw_u,
    "footnotes", ciaaw_saw_Pb.footnotes
    );
    PyDict_SetItemString(d, "Pb", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Bi.element,
    "symbol", ciaaw_saw_Bi.symbol,
    "z", ciaaw_saw_Bi.z,
    "saw_min", ciaaw_saw_Bi.saw_min,
    "saw_max", ciaaw_saw_Bi.saw_max,
    "saw", ciaaw_saw_Bi.saw,
    "saw_u", ciaaw_saw_Bi.saw_u,
    "asaw", ciaaw_saw_Bi.asaw,
    "asaw_u", ciaaw_saw_Bi.asaw_u,
    "footnotes", ciaaw_saw_Bi.footnotes
    );
    PyDict_SetItemString(d, "Bi", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Po.element,
    "symbol", ciaaw_saw_Po.symbol,
    "z", ciaaw_saw_Po.z,
    "saw_min", ciaaw_saw_Po.saw_min,
    "saw_max", ciaaw_saw_Po.saw_max,
    "saw", ciaaw_saw_Po.saw,
    "saw_u", ciaaw_saw_Po.saw_u,
    "asaw", ciaaw_saw_Po.asaw,
    "asaw_u", ciaaw_saw_Po.asaw_u,
    "footnotes", ciaaw_saw_Po.footnotes
    );
    PyDict_SetItemString(d, "Po", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_At.element,
    "symbol", ciaaw_saw_At.symbol,
    "z", ciaaw_saw_At.z,
    "saw_min", ciaaw_saw_At.saw_min,
    "saw_max", ciaaw_saw_At.saw_max,
    "saw", ciaaw_saw_At.saw,
    "saw_u", ciaaw_saw_At.saw_u,
    "asaw", ciaaw_saw_At.asaw,
    "asaw_u", ciaaw_saw_At.asaw_u,
    "footnotes", ciaaw_saw_At.footnotes
    );
    PyDict_SetItemString(d, "At", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Rn.element,
    "symbol", ciaaw_saw_Rn.symbol,
    "z", ciaaw_saw_Rn.z,
    "saw_min", ciaaw_saw_Rn.saw_min,
    "saw_max", ciaaw_saw_Rn.saw_max,
    "saw", ciaaw_saw_Rn.saw,
    "saw_u", ciaaw_saw_Rn.saw_u,
    "asaw", ciaaw_saw_Rn.asaw,
    "asaw_u", ciaaw_saw_Rn.asaw_u,
    "footnotes", ciaaw_saw_Rn.footnotes
    );
    PyDict_SetItemString(d, "Rn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Fr.element,
    "symbol", ciaaw_saw_Fr.symbol,
    "z", ciaaw_saw_Fr.z,
    "saw_min", ciaaw_saw_Fr.saw_min,
    "saw_max", ciaaw_saw_Fr.saw_max,
    "saw", ciaaw_saw_Fr.saw,
    "saw_u", ciaaw_saw_Fr.saw_u,
    "asaw", ciaaw_saw_Fr.asaw,
    "asaw_u", ciaaw_saw_Fr.asaw_u,
    "footnotes", ciaaw_saw_Fr.footnotes
    );
    PyDict_SetItemString(d, "Fr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ra.element,
    "symbol", ciaaw_saw_Ra.symbol,
    "z", ciaaw_saw_Ra.z,
    "saw_min", ciaaw_saw_Ra.saw_min,
    "saw_max", ciaaw_saw_Ra.saw_max,
    "saw", ciaaw_saw_Ra.saw,
    "saw_u", ciaaw_saw_Ra.saw_u,
    "asaw", ciaaw_saw_Ra.asaw,
    "asaw_u", ciaaw_saw_Ra.asaw_u,
    "footnotes", ciaaw_saw_Ra.footnotes
    );
    PyDict_SetItemString(d, "Ra", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ac.element,
    "symbol", ciaaw_saw_Ac.symbol,
    "z", ciaaw_saw_Ac.z,
    "saw_min", ciaaw_saw_Ac.saw_min,
    "saw_max", ciaaw_saw_Ac.saw_max,
    "saw", ciaaw_saw_Ac.saw,
    "saw_u", ciaaw_saw_Ac.saw_u,
    "asaw", ciaaw_saw_Ac.asaw,
    "asaw_u", ciaaw_saw_Ac.asaw_u,
    "footnotes", ciaaw_saw_Ac.footnotes
    );
    PyDict_SetItemString(d, "Ac", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Th.element,
    "symbol", ciaaw_saw_Th.symbol,
    "z", ciaaw_saw_Th.z,
    "saw_min", ciaaw_saw_Th.saw_min,
    "saw_max", ciaaw_saw_Th.saw_max,
    "saw", ciaaw_saw_Th.saw,
    "saw_u", ciaaw_saw_Th.saw_u,
    "asaw", ciaaw_saw_Th.asaw,
    "asaw_u", ciaaw_saw_Th.asaw_u,
    "footnotes", ciaaw_saw_Th.footnotes
    );
    PyDict_SetItemString(d, "Th", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Pa.element,
    "symbol", ciaaw_saw_Pa.symbol,
    "z", ciaaw_saw_Pa.z,
    "saw_min", ciaaw_saw_Pa.saw_min,
    "saw_max", ciaaw_saw_Pa.saw_max,
    "saw", ciaaw_saw_Pa.saw,
    "saw_u", ciaaw_saw_Pa.saw_u,
    "asaw", ciaaw_saw_Pa.asaw,
    "asaw_u", ciaaw_saw_Pa.asaw_u,
    "footnotes", ciaaw_saw_Pa.footnotes
    );
    PyDict_SetItemString(d, "Pa", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_U.element,
    "symbol", ciaaw_saw_U.symbol,
    "z", ciaaw_saw_U.z,
    "saw_min", ciaaw_saw_U.saw_min,
    "saw_max", ciaaw_saw_U.saw_max,
    "saw", ciaaw_saw_U.saw,
    "saw_u", ciaaw_saw_U.saw_u,
    "asaw", ciaaw_saw_U.asaw,
    "asaw_u", ciaaw_saw_U.asaw_u,
    "footnotes", ciaaw_saw_U.footnotes
    );
    PyDict_SetItemString(d, "U", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Np.element,
    "symbol", ciaaw_saw_Np.symbol,
    "z", ciaaw_saw_Np.z,
    "saw_min", ciaaw_saw_Np.saw_min,
    "saw_max", ciaaw_saw_Np.saw_max,
    "saw", ciaaw_saw_Np.saw,
    "saw_u", ciaaw_saw_Np.saw_u,
    "asaw", ciaaw_saw_Np.asaw,
    "asaw_u", ciaaw_saw_Np.asaw_u,
    "footnotes", ciaaw_saw_Np.footnotes
    );
    PyDict_SetItemString(d, "Np", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Pu.element,
    "symbol", ciaaw_saw_Pu.symbol,
    "z", ciaaw_saw_Pu.z,
    "saw_min", ciaaw_saw_Pu.saw_min,
    "saw_max", ciaaw_saw_Pu.saw_max,
    "saw", ciaaw_saw_Pu.saw,
    "saw_u", ciaaw_saw_Pu.saw_u,
    "asaw", ciaaw_saw_Pu.asaw,
    "asaw_u", ciaaw_saw_Pu.asaw_u,
    "footnotes", ciaaw_saw_Pu.footnotes
    );
    PyDict_SetItemString(d, "Pu", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Am.element,
    "symbol", ciaaw_saw_Am.symbol,
    "z", ciaaw_saw_Am.z,
    "saw_min", ciaaw_saw_Am.saw_min,
    "saw_max", ciaaw_saw_Am.saw_max,
    "saw", ciaaw_saw_Am.saw,
    "saw_u", ciaaw_saw_Am.saw_u,
    "asaw", ciaaw_saw_Am.asaw,
    "asaw_u", ciaaw_saw_Am.asaw_u,
    "footnotes", ciaaw_saw_Am.footnotes
    );
    PyDict_SetItemString(d, "Am", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Cm.element,
    "symbol", ciaaw_saw_Cm.symbol,
    "z", ciaaw_saw_Cm.z,
    "saw_min", ciaaw_saw_Cm.saw_min,
    "saw_max", ciaaw_saw_Cm.saw_max,
    "saw", ciaaw_saw_Cm.saw,
    "saw_u", ciaaw_saw_Cm.saw_u,
    "asaw", ciaaw_saw_Cm.asaw,
    "asaw_u", ciaaw_saw_Cm.asaw_u,
    "footnotes", ciaaw_saw_Cm.footnotes
    );
    PyDict_SetItemString(d, "Cm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Bk.element,
    "symbol", ciaaw_saw_Bk.symbol,
    "z", ciaaw_saw_Bk.z,
    "saw_min", ciaaw_saw_Bk.saw_min,
    "saw_max", ciaaw_saw_Bk.saw_max,
    "saw", ciaaw_saw_Bk.saw,
    "saw_u", ciaaw_saw_Bk.saw_u,
    "asaw", ciaaw_saw_Bk.asaw,
    "asaw_u", ciaaw_saw_Bk.asaw_u,
    "footnotes", ciaaw_saw_Bk.footnotes
    );
    PyDict_SetItemString(d, "Bk", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Cf.element,
    "symbol", ciaaw_saw_Cf.symbol,
    "z", ciaaw_saw_Cf.z,
    "saw_min", ciaaw_saw_Cf.saw_min,
    "saw_max", ciaaw_saw_Cf.saw_max,
    "saw", ciaaw_saw_Cf.saw,
    "saw_u", ciaaw_saw_Cf.saw_u,
    "asaw", ciaaw_saw_Cf.asaw,
    "asaw_u", ciaaw_saw_Cf.asaw_u,
    "footnotes", ciaaw_saw_Cf.footnotes
    );
    PyDict_SetItemString(d, "Cf", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Es.element,
    "symbol", ciaaw_saw_Es.symbol,
    "z", ciaaw_saw_Es.z,
    "saw_min", ciaaw_saw_Es.saw_min,
    "saw_max", ciaaw_saw_Es.saw_max,
    "saw", ciaaw_saw_Es.saw,
    "saw_u", ciaaw_saw_Es.saw_u,
    "asaw", ciaaw_saw_Es.asaw,
    "asaw_u", ciaaw_saw_Es.asaw_u,
    "footnotes", ciaaw_saw_Es.footnotes
    );
    PyDict_SetItemString(d, "Es", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Fm.element,
    "symbol", ciaaw_saw_Fm.symbol,
    "z", ciaaw_saw_Fm.z,
    "saw_min", ciaaw_saw_Fm.saw_min,
    "saw_max", ciaaw_saw_Fm.saw_max,
    "saw", ciaaw_saw_Fm.saw,
    "saw_u", ciaaw_saw_Fm.saw_u,
    "asaw", ciaaw_saw_Fm.asaw,
    "asaw_u", ciaaw_saw_Fm.asaw_u,
    "footnotes", ciaaw_saw_Fm.footnotes
    );
    PyDict_SetItemString(d, "Fm", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Md.element,
    "symbol", ciaaw_saw_Md.symbol,
    "z", ciaaw_saw_Md.z,
    "saw_min", ciaaw_saw_Md.saw_min,
    "saw_max", ciaaw_saw_Md.saw_max,
    "saw", ciaaw_saw_Md.saw,
    "saw_u", ciaaw_saw_Md.saw_u,
    "asaw", ciaaw_saw_Md.asaw,
    "asaw_u", ciaaw_saw_Md.asaw_u,
    "footnotes", ciaaw_saw_Md.footnotes
    );
    PyDict_SetItemString(d, "Md", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_No.element,
    "symbol", ciaaw_saw_No.symbol,
    "z", ciaaw_saw_No.z,
    "saw_min", ciaaw_saw_No.saw_min,
    "saw_max", ciaaw_saw_No.saw_max,
    "saw", ciaaw_saw_No.saw,
    "saw_u", ciaaw_saw_No.saw_u,
    "asaw", ciaaw_saw_No.asaw,
    "asaw_u", ciaaw_saw_No.asaw_u,
    "footnotes", ciaaw_saw_No.footnotes
    );
    PyDict_SetItemString(d, "No", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Lr.element,
    "symbol", ciaaw_saw_Lr.symbol,
    "z", ciaaw_saw_Lr.z,
    "saw_min", ciaaw_saw_Lr.saw_min,
    "saw_max", ciaaw_saw_Lr.saw_max,
    "saw", ciaaw_saw_Lr.saw,
    "saw_u", ciaaw_saw_Lr.saw_u,
    "asaw", ciaaw_saw_Lr.asaw,
    "asaw_u", ciaaw_saw_Lr.asaw_u,
    "footnotes", ciaaw_saw_Lr.footnotes
    );
    PyDict_SetItemString(d, "Lr", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Rf.element,
    "symbol", ciaaw_saw_Rf.symbol,
    "z", ciaaw_saw_Rf.z,
    "saw_min", ciaaw_saw_Rf.saw_min,
    "saw_max", ciaaw_saw_Rf.saw_max,
    "saw", ciaaw_saw_Rf.saw,
    "saw_u", ciaaw_saw_Rf.saw_u,
    "asaw", ciaaw_saw_Rf.asaw,
    "asaw_u", ciaaw_saw_Rf.asaw_u,
    "footnotes", ciaaw_saw_Rf.footnotes
    );
    PyDict_SetItemString(d, "Rf", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Db.element,
    "symbol", ciaaw_saw_Db.symbol,
    "z", ciaaw_saw_Db.z,
    "saw_min", ciaaw_saw_Db.saw_min,
    "saw_max", ciaaw_saw_Db.saw_max,
    "saw", ciaaw_saw_Db.saw,
    "saw_u", ciaaw_saw_Db.saw_u,
    "asaw", ciaaw_saw_Db.asaw,
    "asaw_u", ciaaw_saw_Db.asaw_u,
    "footnotes", ciaaw_saw_Db.footnotes
    );
    PyDict_SetItemString(d, "Db", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Sg.element,
    "symbol", ciaaw_saw_Sg.symbol,
    "z", ciaaw_saw_Sg.z,
    "saw_min", ciaaw_saw_Sg.saw_min,
    "saw_max", ciaaw_saw_Sg.saw_max,
    "saw", ciaaw_saw_Sg.saw,
    "saw_u", ciaaw_saw_Sg.saw_u,
    "asaw", ciaaw_saw_Sg.asaw,
    "asaw_u", ciaaw_saw_Sg.asaw_u,
    "footnotes", ciaaw_saw_Sg.footnotes
    );
    PyDict_SetItemString(d, "Sg", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Bh.element,
    "symbol", ciaaw_saw_Bh.symbol,
    "z", ciaaw_saw_Bh.z,
    "saw_min", ciaaw_saw_Bh.saw_min,
    "saw_max", ciaaw_saw_Bh.saw_max,
    "saw", ciaaw_saw_Bh.saw,
    "saw_u", ciaaw_saw_Bh.saw_u,
    "asaw", ciaaw_saw_Bh.asaw,
    "asaw_u", ciaaw_saw_Bh.asaw_u,
    "footnotes", ciaaw_saw_Bh.footnotes
    );
    PyDict_SetItemString(d, "Bh", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Hs.element,
    "symbol", ciaaw_saw_Hs.symbol,
    "z", ciaaw_saw_Hs.z,
    "saw_min", ciaaw_saw_Hs.saw_min,
    "saw_max", ciaaw_saw_Hs.saw_max,
    "saw", ciaaw_saw_Hs.saw,
    "saw_u", ciaaw_saw_Hs.saw_u,
    "asaw", ciaaw_saw_Hs.asaw,
    "asaw_u", ciaaw_saw_Hs.asaw_u,
    "footnotes", ciaaw_saw_Hs.footnotes
    );
    PyDict_SetItemString(d, "Hs", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Mt.element,
    "symbol", ciaaw_saw_Mt.symbol,
    "z", ciaaw_saw_Mt.z,
    "saw_min", ciaaw_saw_Mt.saw_min,
    "saw_max", ciaaw_saw_Mt.saw_max,
    "saw", ciaaw_saw_Mt.saw,
    "saw_u", ciaaw_saw_Mt.saw_u,
    "asaw", ciaaw_saw_Mt.asaw,
    "asaw_u", ciaaw_saw_Mt.asaw_u,
    "footnotes", ciaaw_saw_Mt.footnotes
    );
    PyDict_SetItemString(d, "Mt", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ds.element,
    "symbol", ciaaw_saw_Ds.symbol,
    "z", ciaaw_saw_Ds.z,
    "saw_min", ciaaw_saw_Ds.saw_min,
    "saw_max", ciaaw_saw_Ds.saw_max,
    "saw", ciaaw_saw_Ds.saw,
    "saw_u", ciaaw_saw_Ds.saw_u,
    "asaw", ciaaw_saw_Ds.asaw,
    "asaw_u", ciaaw_saw_Ds.asaw_u,
    "footnotes", ciaaw_saw_Ds.footnotes
    );
    PyDict_SetItemString(d, "Ds", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Rg.element,
    "symbol", ciaaw_saw_Rg.symbol,
    "z", ciaaw_saw_Rg.z,
    "saw_min", ciaaw_saw_Rg.saw_min,
    "saw_max", ciaaw_saw_Rg.saw_max,
    "saw", ciaaw_saw_Rg.saw,
    "saw_u", ciaaw_saw_Rg.saw_u,
    "asaw", ciaaw_saw_Rg.asaw,
    "asaw_u", ciaaw_saw_Rg.asaw_u,
    "footnotes", ciaaw_saw_Rg.footnotes
    );
    PyDict_SetItemString(d, "Rg", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Cn.element,
    "symbol", ciaaw_saw_Cn.symbol,
    "z", ciaaw_saw_Cn.z,
    "saw_min", ciaaw_saw_Cn.saw_min,
    "saw_max", ciaaw_saw_Cn.saw_max,
    "saw", ciaaw_saw_Cn.saw,
    "saw_u", ciaaw_saw_Cn.saw_u,
    "asaw", ciaaw_saw_Cn.asaw,
    "asaw_u", ciaaw_saw_Cn.asaw_u,
    "footnotes", ciaaw_saw_Cn.footnotes
    );
    PyDict_SetItemString(d, "Cn", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Nh.element,
    "symbol", ciaaw_saw_Nh.symbol,
    "z", ciaaw_saw_Nh.z,
    "saw_min", ciaaw_saw_Nh.saw_min,
    "saw_max", ciaaw_saw_Nh.saw_max,
    "saw", ciaaw_saw_Nh.saw,
    "saw_u", ciaaw_saw_Nh.saw_u,
    "asaw", ciaaw_saw_Nh.asaw,
    "asaw_u", ciaaw_saw_Nh.asaw_u,
    "footnotes", ciaaw_saw_Nh.footnotes
    );
    PyDict_SetItemString(d, "Nh", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Fl.element,
    "symbol", ciaaw_saw_Fl.symbol,
    "z", ciaaw_saw_Fl.z,
    "saw_min", ciaaw_saw_Fl.saw_min,
    "saw_max", ciaaw_saw_Fl.saw_max,
    "saw", ciaaw_saw_Fl.saw,
    "saw_u", ciaaw_saw_Fl.saw_u,
    "asaw", ciaaw_saw_Fl.asaw,
    "asaw_u", ciaaw_saw_Fl.asaw_u,
    "footnotes", ciaaw_saw_Fl.footnotes
    );
    PyDict_SetItemString(d, "Fl", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Mc.element,
    "symbol", ciaaw_saw_Mc.symbol,
    "z", ciaaw_saw_Mc.z,
    "saw_min", ciaaw_saw_Mc.saw_min,
    "saw_max", ciaaw_saw_Mc.saw_max,
    "saw", ciaaw_saw_Mc.saw,
    "saw_u", ciaaw_saw_Mc.saw_u,
    "asaw", ciaaw_saw_Mc.asaw,
    "asaw_u", ciaaw_saw_Mc.asaw_u,
    "footnotes", ciaaw_saw_Mc.footnotes
    );
    PyDict_SetItemString(d, "Mc", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Lv.element,
    "symbol", ciaaw_saw_Lv.symbol,
    "z", ciaaw_saw_Lv.z,
    "saw_min", ciaaw_saw_Lv.saw_min,
    "saw_max", ciaaw_saw_Lv.saw_max,
    "saw", ciaaw_saw_Lv.saw,
    "saw_u", ciaaw_saw_Lv.saw_u,
    "asaw", ciaaw_saw_Lv.asaw,
    "asaw_u", ciaaw_saw_Lv.asaw_u,
    "footnotes", ciaaw_saw_Lv.footnotes
    );
    PyDict_SetItemString(d, "Lv", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Ts.element,
    "symbol", ciaaw_saw_Ts.symbol,
    "z", ciaaw_saw_Ts.z,
    "saw_min", ciaaw_saw_Ts.saw_min,
    "saw_max", ciaaw_saw_Ts.saw_max,
    "saw", ciaaw_saw_Ts.saw,
    "saw_u", ciaaw_saw_Ts.saw_u,
    "asaw", ciaaw_saw_Ts.asaw,
    "asaw_u", ciaaw_saw_Ts.asaw_u,
    "footnotes", ciaaw_saw_Ts.footnotes
    );
    PyDict_SetItemString(d, "Ts", element);
    Py_INCREF(element);

    element = Py_BuildValue("{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}",
    "element", ciaaw_saw_Og.element,
    "symbol", ciaaw_saw_Og.symbol,
    "z", ciaaw_saw_Og.z,
    "saw_min", ciaaw_saw_Og.saw_min,
    "saw_max", ciaaw_saw_Og.saw_max,
    "saw", ciaaw_saw_Og.saw,
    "saw_u", ciaaw_saw_Og.saw_u,
    "asaw", ciaaw_saw_Og.asaw,
    "asaw_u", ciaaw_saw_Og.asaw_u,
    "footnotes", ciaaw_saw_Og.footnotes
    );
    PyDict_SetItemString(d, "Og", element);
    Py_INCREF(element);

    return m;
}
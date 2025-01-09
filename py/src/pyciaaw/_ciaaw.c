#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "ciaaw.h"


PyDoc_STRVAR(module_docstring, "C extension for ciaaw.");

PyDoc_STRVAR(get_saw_doc, 
"get_saw(s: str, abridged: bool, uncertainty: bool) -> float \n\n"
"Get the abridged standard atomic weight. Returns NaN if provided symbol is incorrect or -1 if the element does not have a SAW.");

PyDoc_STRVAR(get_ice_doc, 
"get_ice(s: str, A: int, uncertainty: bool) -> float \n\n"
"Get isotopic composition of the element for the mass number A. Returns NaN if the provided symbol or A are incorrect or -1 if the element does not have an ICE.");

PyDoc_STRVAR(get_nice_doc,
"get_nice(s: str) -> int \n\n"
"Get the number of isotopes in ICE. Returns -1 if the provided symbol is incorrect.");

PyDoc_STRVAR(get_naw_doc, 
"get_naw(s: str, A: int, uncertainty: bool) -> float \n\n"
"Get the nuclide atomic weight of the element for the mass number A. Returns NaN if provided symbol or A are incorrect or -1 if the element does not have an NAW.");
 
PyDoc_STRVAR(get_nnaw_doc,
"get_nnaw(s: str) -> int \n\n"
"Get the number of nuclides in NAW. Returns -1 if the provided symbol is incorrect.");


static PyObject *get_saw(PyObject *self, PyObject *args){
    
    char *s;
    int abridged;
    int uncertainty;
    Py_ssize_t size;
    double res;

    if (!PyArg_ParseTuple(args, "s#pp", &s, &size, &abridged, &uncertainty)){
        return NULL;
    }
    res = ciaaw_get_saw(s, size, (bool) abridged, (bool) uncertainty);
    
    return Py_BuildValue("d", res);
}

static PyObject *get_ice(PyObject *self, PyObject *args){
    
    char *s;
    int A;
    Py_ssize_t size;
    int uncertainty;
    double res;

    if (!PyArg_ParseTuple(args, "s#ip", &s, &size, &A, &uncertainty)){
        return NULL;
    }
    res = ciaaw_get_ice(s, size, A, (bool) uncertainty);
    
    return Py_BuildValue("d", res);
}

static PyObject *get_nice(PyObject *self, PyObject *args){
    
    char *s;
    Py_ssize_t size;
    int res;

    if (!PyArg_ParseTuple(args, "s#", &s, &size)){
        return NULL;
    }
    res = ciaaw_get_nice(s, size);

    return Py_BuildValue("i", res);
}

static PyObject *get_naw(PyObject *self, PyObject *args){
    
    char *s;
    int A;
    Py_ssize_t size;
    int uncertainty;
    double res;

    if (!PyArg_ParseTuple(args, "s#ip", &s, &size, &A, &uncertainty)){
        return NULL;
    }
    res = ciaaw_get_naw(s, size, A, (bool) uncertainty);
    
    return Py_BuildValue("d", res);
}

static PyObject *get_nnaw(PyObject *self, PyObject *args){
    
    char *s;
    Py_ssize_t size;
    int res;

    if (!PyArg_ParseTuple(args, "s#", &s, &size)){
        return NULL;
    }
    res = ciaaw_get_nnaw(s, size);

    return Py_BuildValue("i", res);
}




static PyMethodDef myMethods[] = {  
    {"get_saw",  (PyCFunction) get_saw,  METH_VARARGS, get_saw_doc},
    {"get_ice",  (PyCFunction) get_ice,  METH_VARARGS, get_ice_doc},
    {"get_nice", (PyCFunction) get_nice, METH_VARARGS, get_nice_doc},
    {"get_naw",  (PyCFunction) get_naw,  METH_VARARGS, get_naw_doc},
    {"get_nnaw", (PyCFunction) get_nnaw, METH_VARARGS, get_nnaw_doc},
    { NULL, NULL, 0, NULL }};

static struct PyModuleDef _ciaaw = {PyModuleDef_HEAD_INIT, "_ciaaw", module_docstring, -1, myMethods};



PyMODINIT_FUNC PyInit__ciaaw(void){
    PyObject *m;
    PyObject *d;
    PyObject *v;
    m = PyModule_Create(&_ciaaw);
    d = PyModule_GetDict(m);
    v = PyUnicode_FromFormat("%s", ciaaw_get_version());
    PyDict_SetItemString(d, "__version__", v);
    Py_INCREF(v);
    return m;
}

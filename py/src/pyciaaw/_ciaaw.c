#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdbool.h>
#include <string.h>
#include "ciaaw.h"


PyDoc_STRVAR(module_docstring, "C extension for ciaaw.");

PyDoc_STRVAR(get_saw_doc, 
"get_saw(s: str, abridged: bool, uncertainty: bool) -> float \n\n"
"Get the abridged standard atomic weight. Returns NaN if not found.");

PyDoc_STRVAR(get_ice_doc, 
"get_ice(s: str, A: int, uncertainty: bool) -> float \n\n"
"Get isotopic composition of the element for the mass number A. Returns -NaN if not found.");
 

PyDoc_STRVAR(get_nice_doc,
"get_nice(s: str) -> int \n\n"
"Get the number of isotopes in ICE. Returns -1 if not found.");



static PyObject *get_saw(PyObject *self, PyObject *args){
    
    char *s;
    bool abridged;
    bool uncertainty;
    int size;
    double res;

    if (!PyArg_ParseTuple(args, "spp", &s, &abridged, &uncertainty)){
        return NULL;
    }
    size = strlen(s);
    res = ciaaw_get_saw(s, size, abridged, uncertainty);
    
    return Py_BuildValue("d", res);
}



static PyObject *get_ice(PyObject *self, PyObject *args){
    
    char *s;
    int A;
    int size;
    bool uncertainty;
    double res;

    if (!PyArg_ParseTuple(args, "sip", &s, &A, &uncertainty)){
        return NULL;
    }
    size = strlen(s);
    res = ciaaw_get_ice(s, size, A, uncertainty);
    
    return Py_BuildValue("d", res);
}



static PyObject *get_nice(PyObject *self, PyObject *args){
    
    char *s;
    int size;
    int res;

    if (!PyArg_ParseTuple(args, "s", &s)){
        return NULL;
    }
    size = strlen(s);
    res = ciaaw_get_nice(s, size);

    return Py_BuildValue("i", res);
}



static PyMethodDef myMethods[] = {  
    {"get_saw",  (PyCFunction) get_saw,  METH_VARARGS, get_saw_doc},
    {"get_ice",  (PyCFunction) get_ice,  METH_VARARGS, get_ice_doc},
    {"get_nice", (PyCFunction) get_nice, METH_VARARGS, get_nice_doc},
    { NULL, NULL, 0, NULL }};

static struct PyModuleDef _ciaaw = {PyModuleDef_HEAD_INIT, "_ciaaw", module_docstring, -1, myMethods};



PyMODINIT_FUNC PyInit__ciaaw(void){
     return PyModule_Create(&_ciaaw);
}

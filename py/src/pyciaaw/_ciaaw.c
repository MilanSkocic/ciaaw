#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "ciaaw.h"

//======================================================================
// DOC               
//======================================================================
PyDoc_STRVAR(module_docstring, "C extension for ciaaw.");

PyDoc_STRVAR(saw_doc, 
"saw(s: str, abridged: bool, u: bool) -> float \n\n");

PyDoc_STRVAR(ice_doc, 
"ice(s: str, A: int, u: bool) -> float \n\n");

PyDoc_STRVAR(nice_doc,
"nice(s: str) -> int \n\n");

PyDoc_STRVAR(naw_doc, 
"naw(s: str, A: int, u: bool) -> float \n\n");
 
PyDoc_STRVAR(nnaw_doc,
"nnaw(s: str) -> int \n\n");
//======================================================================


//======================================================================
// FUNCTIONS              
//======================================================================
static PyObject *saw(PyObject *self, PyObject *args){
    char *s;
    int abridged;
    int uncertainty;
    Py_ssize_t size;
    double res;

    if (!PyArg_ParseTuple(args, "s#pp", &s, &size, &abridged, &uncertainty)){
        return NULL;
    }
    res = ciaaw_saw(s, size, (bool) abridged, (bool) uncertainty);
    
    return Py_BuildValue("d", res);
}

static PyObject *ice(PyObject *self, PyObject *args){
    char *s;
    int A;
    Py_ssize_t size;
    int uncertainty;
    double res;

    if (!PyArg_ParseTuple(args, "s#ip", &s, &size, &A, &uncertainty)){
        return NULL;
    }
    res = ciaaw_ice(s, size, A, (bool) uncertainty);
    
    return Py_BuildValue("d", res);
}

static PyObject *_nice(PyObject *self, PyObject *args){
    char *s;
    Py_ssize_t size;
    int res;

    if (!PyArg_ParseTuple(args, "s#", &s, &size)){
        return NULL;
    }
    res = ciaaw_nice(s, size);

    return Py_BuildValue("i", res);
}

static PyObject *naw(PyObject *self, PyObject *args){
    char *s;
    int A;
    Py_ssize_t size;
    int uncertainty;
    double res;

    if (!PyArg_ParseTuple(args, "s#ip", &s, &size, &A, &uncertainty)){
        return NULL;
    }
    res = ciaaw_naw(s, size, A, (bool) uncertainty);
    
    return Py_BuildValue("d", res);
}

static PyObject *nnaw(PyObject *self, PyObject *args){
    char *s;
    Py_ssize_t size;
    int res;

    if (!PyArg_ParseTuple(args, "s#", &s, &size)){
        return NULL;
    }
    res = ciaaw_nnaw(s, size);

    return Py_BuildValue("i", res);
}
//======================================================================


//======================================================================
// METHODS              
//======================================================================
static PyMethodDef myMethods[] = {  
{"saw",  (PyCFunction) saw,  METH_VARARGS, saw_doc},
{"ice",  (PyCFunction) ice,  METH_VARARGS, ice_doc},
{"nice", (PyCFunction) _nice, METH_VARARGS, nice_doc}, // Concflict name nice from Python.h
{"naw",  (PyCFunction) naw,  METH_VARARGS, naw_doc},
{"nnaw", (PyCFunction) nnaw, METH_VARARGS, nnaw_doc},
{ NULL, NULL, 0, NULL }};

static struct PyModuleDef _ciaaw = 
{PyModuleDef_HEAD_INIT, "_ciaaw", module_docstring, -1, myMethods};
//======================================================================


//======================================================================
// INITIALIZATION
//======================================================================
PyMODINIT_FUNC PyInit__ciaaw(void){
    PyObject *m;
    PyObject *d;
    PyObject *v;
    m = PyModule_Create(&_ciaaw);
    d = PyModule_GetDict(m);
    v = PyUnicode_FromFormat("%s", ciaaw_version());
    PyDict_SetItemString(d, "__version__", v);
    Py_INCREF(v);
    return m;
}
//======================================================================

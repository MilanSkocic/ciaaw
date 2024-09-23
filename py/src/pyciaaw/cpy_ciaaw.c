#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "ciaaw.h"


PyDoc_STRVAR(module_docstring, "C extension for ciaaw.");

PyDoc_STRVAR(get_asaw_doc, 
"get_asaw(z: int) --> float \n\n"
"Get the abridged standard atomic weight. Returns -1 if not found.");


static PyObject *get_asaw(PyObject *self, PyObject *args){

    int z;
    double res;
    
    if(!PyArg_ParseTuple(args, "i", &z)){
        PyErr_SetString(PyExc_TypeError, "z must be an int.");
        return NULL;
    }

    res = ciaaw_get_asaw(z);

    return Py_BuildValue("d", res);
}



static PyMethodDef myMethods[] = {  {"get_asaw", (PyCFunction) get_asaw, METH_VARARGS, get_asaw_doc},
                                    { NULL, NULL, 0, NULL }};

static struct PyModuleDef ciaaw = {PyModuleDef_HEAD_INIT, "ciaaw", module_docstring, -1, myMethods};



PyMODINIT_FUNC PyInit_ciaaw(void){
     return PyModule_Create(&ciaaw);
}

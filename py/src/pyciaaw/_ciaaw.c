#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "ciaaw.h"

//----------------------------------------------------------------------
// DOC               
//----------------------------------------------------------------------
PyDoc_STRVAR(module_docstring, "C extension for ciaaw.");

PyDoc_STRVAR(saw_doc, 
"saw(s: str, abridged: bool, u: bool) -> float \n\n");

PyDoc_STRVAR(ice_doc, 
"ice(s: str, A: int, u: bool) -> float \n\n");

PyDoc_STRVAR(ices_doc, 
"ices(s: str) -> array \n\n");

PyDoc_STRVAR(nice_doc,
"nice(s: str) -> int \n\n");

PyDoc_STRVAR(naw_doc, 
"naw(s: str, A: int, u: bool) -> float \n\n");

PyDoc_STRVAR(naws_doc, 
"naws(s: str) -> array \n\n");

PyDoc_STRVAR(nnaw_doc,
"nnaw(s: str) -> int \n\n");
//----------------------------------------------------------------------


Py_buffer create_new_buffer(char *format, Py_ssize_t itemsize, Py_ssize_t ndim, Py_ssize_t *shape){
    Py_buffer buffer;
    Py_ssize_t i, j, size, subsize;
    Py_ssize_t *strides = (Py_ssize_t *)PyMem_Calloc(ndim, sizeof(Py_ssize_t));

    buffer.obj = NULL;
    buffer.suboffsets = NULL;
    buffer.format = format;
    buffer.readonly = 0;
    buffer.itemsize = itemsize;
    buffer.ndim = ndim;
    buffer.shape = shape;

    size = 1;
    for(i=0; i<ndim; i++){
        size *= shape[i];
    }

    strides[ndim-1] = itemsize;
    if(ndim > 1){
        for(i=0; i<(ndim-1); i++){
            subsize = 1;
            for(j=i+1; j<ndim; j++){
                subsize *= shape[j];
            }
            strides[i] = subsize * itemsize;
        }
    }

    buffer.len = size * itemsize;
    buffer.strides = strides;
    buffer.buf = PyMem_Calloc(size, itemsize);

    return buffer;
}


//----------------------------------------------------------------------
// FUNCTIONS              
//----------------------------------------------------------------------
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

static PyObject *ices(PyObject *self, PyObject *args){
    char *s;
    Py_buffer res_buf;
    PyObject *res_mview;
    
    Py_ssize_t ndim = 2;
    Py_ssize_t shape[2] = {0,0};


    if (!PyArg_ParseTuple(args, "s", &s)){
        return NULL;
    }
    shape[1] = ciaaw_nice(s, strlen(s));
    shape[0] = 3;
    res_buf = create_new_buffer("d", sizeof(double), ndim, shape);
    res_buf.buf = (void *)ciaaw_ices(s, strlen(s));
    
    if(res_buf.buf == NULL){Py_RETURN_NONE;}

    res_mview = PyMemoryView_FromBuffer(&res_buf);
    
    return res_mview;
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

static PyObject *naws(PyObject *self, PyObject *args){
    char *s;
    Py_buffer res_buf;
    PyObject *res_mview;
    
    Py_ssize_t ndim = 2;
    Py_ssize_t shape[2] = {0,0};


    if (!PyArg_ParseTuple(args, "s", &s)){
        return NULL;
    }
    shape[1] = ciaaw_nnaw(s, strlen(s));
    shape[0] = 3;
    res_buf = create_new_buffer("d", sizeof(double), ndim, shape);
    res_buf.buf = (void *)ciaaw_naws(s, strlen(s));
    
    if(res_buf.buf == NULL){Py_RETURN_NONE;}

    res_mview = PyMemoryView_FromBuffer(&res_buf);
    
    return res_mview;
}
//----------------------------------------------------------------------


//----------------------------------------------------------------------
// METHODS              
//----------------------------------------------------------------------
static PyMethodDef myMethods[] = {  
{"saw",  (PyCFunction) saw,  METH_VARARGS, saw_doc},
{"ice",  (PyCFunction) ice,  METH_VARARGS, ice_doc},
{"nice", (PyCFunction) _nice, METH_VARARGS, nice_doc}, // Concflict name nice from Python.h
{"ices",  (PyCFunction) ices,  METH_VARARGS, ices_doc},
{"naw",  (PyCFunction) naw,  METH_VARARGS, naw_doc},
{"nnaw", (PyCFunction) nnaw, METH_VARARGS, nnaw_doc},
{"naws",  (PyCFunction) naws,  METH_VARARGS, naws_doc},
{ NULL, NULL, 0, NULL }};

static struct PyModuleDef _ciaaw = 
{PyModuleDef_HEAD_INIT, "_ciaaw", module_docstring, -1, myMethods};
//----------------------------------------------------------------------


//----------------------------------------------------------------------
// INITIALIZATION
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------

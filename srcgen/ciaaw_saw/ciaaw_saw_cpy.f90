module ciaaw_saw_cpy
    !! Generate code for CPython.
    use core
    implicit none


contains

subroutine write_cpython_extension_declaration(fcode)
    !! Generate the cpython module declaration.
    implicit none
    integer(int32), intent(in) :: fcode
        !! File unit of the Python module.

    write(fcode, "(A)") "#define PY_SSIZE_T_CLEAN"
    write(fcode, "(A)") "#include <Python.h>"
    write(fcode, "(A)") '#include "ciaaw.h"'
    write(fcode, "(A)") ""
    write(fcode, "(A)") 'PyDoc_STRVAR(module_docstring, "C extension for saw.");'
    write(fcode, "(A)") ""
    write(fcode, "(A)") "static PyMethodDef myMethods[] = {{ NULL, NULL, 0, NULL }};"
    write(fcode, "(A)") ""
    write(fcode, "(A)") 'static struct PyModuleDef saw = {PyModuleDef_HEAD_INIT, "saw", module_docstring, -1, myMethods};'
    write(fcode, "(A)") ""
    write(fcode, "(A)") "PyMODINIT_FUNC PyInit_saw(void){"
    write(fcode, "(4X, A)") "PyObject *m;"
    write(fcode, "(4X, A)") "PyObject *d;"
    write(fcode, "(4X, A)") "PyObject *v;"
    write(fcode, "(4X, A)") "PyObject *element;"
    write(fcode, "(4X, A)") "m = PyModule_Create(&saw);"
    write(fcode, "(4X, A)") "d = PyModule_GetDict(m);"
    write(fcode, "(A)") ""
end subroutine

subroutine write_cpython_extension_end(fcode)
    !! Generate the cpython module end.
    implicit none
    integer(int32), intent(in) :: fcode
        !! File unit of the Python module.
    write(fcode, "(4X, A)") "return m;"
    write(fcode, "(A)") "}"
end subroutine

end module
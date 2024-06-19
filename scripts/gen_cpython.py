r"""Generate CPython sources."""
import argparse
import tomlkit

newline = "\n"
latest_year = "2021"

def get_year(fpath: str)->str:
    return fpath.split("/")[-1].split("_")[1].split(".")[0]

def get_suffix(year):
    if year == latest_year:
        suffix = ""
    else:
        suffix = "_" + year

    return suffix

def write_module_start(f, year):
    suffix = "_" + year

    f.write("#define PY_SSIZE_T_CLEAN" + newline)
    f.write("#include <Python.h>" + newline)
    f.write(f"#include \"ciaaw.h\"" + newline)
    f.write(newline)
    f.write(f"PyDoc_STRVAR(module_docstring, \"C extension for saw {year:s}.\");" + newline)
    f.write(newline)
    f.write("static PyMethodDef myMethods[] = {{ NULL, NULL, 0, NULL }};" + newline)
    f.write(newline)
    f.write(f"static struct PyModuleDef saw{suffix:s} " + "= {PyModuleDef_HEAD_INIT, \"saw" + f"{suffix:s}" + "\", module_docstring, -1, myMethods};" + newline)

    f.write(f"PyMODINIT_FUNC PyInit_saw{suffix:s}(void)" + "{" + newline)
    f.write("    PyObject *m;" + newline)
    f.write("    PyObject *d;" + newline)
    f.write("    PyObject *v;" + newline)
    f.write("    PyObject *element;" + newline)
    f.write(f"    m = PyModule_Create(&saw{suffix:s});" + newline)
    f.write("    d = PyModule_GetDict(m);" + newline)
    f.write(newline)

def write_year(f, year):
    suffix = get_suffix(year)

    f.write(f"    v = PyLong_FromLong(ciaaw_saw_YEAR{suffix:s});" + newline)
    f.write(f"    PyDict_SetItemString(d, \"YEAR{suffix:s}\", v);" + newline)
    f.write("    Py_INCREF(v);" + newline)
    f.write(newline)

def write_constant(f, symbol, year):
    suffix = get_suffix(year)
    var = "ciaaw_saw_" + symbol + suffix 
    f.write("    element = Py_BuildValue(\"{s:s, s:s, s:i, s:d, s:d, s:d, s:d, s:d, s:d, s:s}\"," + newline)
    f.write(f"    \"element\", {var:s}{suffix:s}.element," + newline)
    f.write(f"    \"symbol\", {var:s}{suffix:s}.symbol," + newline)
    f.write(f"    \"z\", {var:s}{suffix:s}.z," + newline)
    f.write(f"    \"saw_min\", {var:s}{suffix:s}.saw_min," + newline)
    f.write(f"    \"saw_max\", {var:s}{suffix:s}.saw_max," + newline)
    f.write(f"    \"saw\", {var:s}{suffix:s}.saw," + newline)
    f.write(f"    \"saw_u\", {var:s}{suffix:s}.saw_u," + newline)
    f.write(f"    \"asaw\", {var:s}{suffix:s}.asaw," + newline)
    f.write(f"    \"asaw_u\", {var:s}{suffix:s}.asaw_u," + newline)
    f.write(f"    \"footnotes\", {var:s}{suffix:s}.footnotes" + newline)
    f.write("    );" + newline)
    f.write("    PyDict_SetItemString(d, \"" + f"{symbol:s}{suffix:s}" + "\", element);" + newline)
    f.write("    Py_INCREF(element);" + newline)

    f.write(newline)

def write_module_end(f, year):
    f.write("    return m;" + newline)
    f.write("}")


def run(fpath_ast: str, fpath_code: str)->None:
    
    year = get_year(fpath_ast)
    
    fcode = open(fpath_code, "w")
    fast = open(fpath_ast, "r")

    write_module_start(fcode, year)
    write_year(fcode, year)

    ast = tomlkit.load(fast)
    for var in ast.keys():
        symbol = ast[var]["symbol"]
        write_constant(fcode, symbol, year)
    
    write_module_end(fcode, year)

    fast.close()
    fcode.close()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog='gencpython', description='Generate cpython sources.')
    parser.add_argument("ast", help="File path to the Toml file for ast input.")
    parser.add_argument("code", help="File path to the source file for output.")
    args = parser.parse_args() 

    run(args.ast, args.code)

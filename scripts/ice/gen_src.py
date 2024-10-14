r"""Generate sources for Fortran."""
import argparse
import tomlkit

newline = "\n"
NROWS = 10

def get_year(fpath: str)->str:
    return fpath.split("/")[-1].split("_")[1].split(".")[0]

def write_module_start(f):
    f.write("module ciaaw__ice" + newline)
    f.write("    !! Ciaaw ice - Autogenerated"+newline)
    f.write("    !! See [specs](../page/specs/ciaaw_api.html)"+newline)
    f.write("    use ciaaw__common"+newline)
    f.write("    use ciaaw__types" + newline)
    f.write("    private"+newline)
    f.write(newline)

def write_constant(f, symbol, A, value, uncertainty):
    
    n = len(A)

    f.write(f"type(ice_type), parameter, public :: {symbol}_ice = &"+newline)
    f.write(f"ice_type({n:d},transpose(reshape([&" + newline)
    
    k = 1
    for ai, ci, ui in zip(A, value, uncertainty):
        f.write(f"{ai:s}.0_dp,{ci:s}_dp,{ui:s}_dp,&"+newline)
        k += 1

    while (k<=NROWS):
        if k == NROWS:
            f.write(f"-1.0_dp, -1.0_dp, -1.0_dp &"+newline)
        else:
            f.write(f"-1.0_dp, -1.0_dp, -1.0_dp,&"+newline)
        k += 1
    
    f.write(f"], shape=[3, {NROWS:d}])))"+newline)
    
    f.write(newline)

def write_module_end(f):
    f.write("end module ciaaw__ice")


def run(fpath_ast: str, fpath_code: str)->None:
    
    year = get_year(fpath_ast)
    
    fcode = open(fpath_code, "w")
    fast = open(fpath_ast, "r")

    write_module_start(fcode)

    ast = tomlkit.load(fast)
    for var in ast.keys():
        symbol = var
        A = ast[var]["A"]
        value = ast[var]["value"]
        uncertainty = ast[var]["uncertainty"]
        write_constant(fcode, symbol, A, value, uncertainty)
    
    write_module_end(fcode)

    fast.close()
    fcode.close()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog='gensrc', description='Generate source code.')
    parser.add_argument("ast", help="File path to the Toml file for ast input.")
    parser.add_argument("code", help="File path to the source file for output.")
    args = parser.parse_args() 

    run(args.ast, args.code)

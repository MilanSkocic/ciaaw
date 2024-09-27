r"""Generate sources for Fortran."""
import argparse
import tomlkit

newline = "\n"

def write_module_start(f, n):
    f.write("module ciaaw__pte" + newline)
    f.write("    !! Ciaaw pte - Autogenerated"+newline)
    f.write("    !! See [specs](../page/specs/ciaaw_pte.html)"+newline)
    f.write("    use ciaaw__common"+newline)
    f.write("    use ciaaw__types" + newline)
    f.write("    use ciaaw__saw" + newline)
    f.write("    use ciaaw__ice" + newline)
    f.write("    use ciaaw__ice" + newline)
    f.write("    private"+newline)
    f.write(newline)
    f.write(f"type(element_type), parameter, public :: pt({n:d}) = [&"+newline)

def write_constant(f, element, symbol, z, last, has_ice):
    
    e = f"\"{element:s}\"" + ","
    s = f"\"{symbol:s}\"" + ","
    z_ = f"{z:s}" + ","
    saw = f"{symbol:s}_saw" + ","

    if has_ice:
        ice = f"{symbol:s}_ice"
    else:
        ice = f"ice_nan"
    
    if last:
        f.write(f" element_type({e:20s} {s:10s} {z_:10s} {saw:10s} {ice:10s})&" + newline)
    else:
        f.write(f" element_type({e:20s} {s:10s} {z_:10s} {saw:10s} {ice:10s}),&" + newline)
    

def write_module_end(f):
    f.write("]"+newline)
    f.write("end module ciaaw__pte")


def run(fpath_ast_saw: str, fpath_ast_ice: str, fpath_code: str)->None:
    
    fcode = open(fpath_code, "w")
    fast_saw = open(fpath_ast_saw, "r")
    fast_ice = open(fpath_ast_ice, "r")

    ast_saw = tomlkit.load(fast_saw)
    ast_ice = tomlkit.load(fast_ice)
    n = len(ast_saw.keys())
    
    write_module_start(fcode, n)

    for i, var in enumerate(ast_saw.keys()):
        element = ast_saw[var]["element"]
        symbol = ast_saw[var]["symbol"]
        z = ast_saw[var]["z"]
        
        if (i+1) == n:
            last=True
        else:
            last = False

        if var not  in ast_ice.keys():
            has_ice = False
        else:
            has_ice = True

        write_constant(fcode, element, symbol, z, last, has_ice)
    
    write_module_end(fcode)

    fast_saw.close()
    fcode.close()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog='gensrc', description='Generate source code.')
    parser.add_argument("ast_saw", help="File path to the Toml file for ast input.")
    parser.add_argument("ast_ice", help="File path to the Toml file for ast input.")
    parser.add_argument("code", help="File path to the source file for output.")
    args = parser.parse_args() 

    run(args.ast_saw, args.ast_ice, args.code)

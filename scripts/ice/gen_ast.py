r"""Generate language independant representation of ICE."""
import argparse
import tomlkit
from math import sqrt, floor, ceil, log10


# Indexes for the table columns
cix_z = [1, 10]
cix_symbol = [11, 20]
cix_A = [21, 30]
cix_value = [31, 50]
cix_uncertainty = [51, 70]


def get_year(fpath: str)->str:
    return fpath.split("/")[-1].split("_")[1].split(".")[0]

def get_skiprows(fpath: str)->int:
    with open(fpath, "r") as f:
        k = 0
        for line in f:
            if line.startswith("-"):
                break
            else:
                k += 1

    return k+1

def format_symbol(line: str)->str:
    i, j = cix_symbol   
    return line[i-1:j].rstrip()

def format_z(line: str)->str:
    i, j = cix_z  
    return line[i-1:j].rstrip()

def format_A(line: str)->str:
    i, j = cix_A  
    return line[i-1:j].rstrip()

def format_value(line):
    i, j = cix_value 
    value = line[i-1:j].rstrip()

    return value

def format_uncertainty(line):
    i, j = cix_uncertainty
    u = line[i-1:j].rstrip()

    return u
 

def run(fpath_raw: str, fpath_ast:str)->None:
    year = get_year(fpath_raw)
    skiprows = get_skiprows(fpath_raw)
    
    toml = tomlkit.document()
    
    k = 0
    fpath = fpath_raw
    with open(fpath, "r") as f:
        for line in f:
            if k>=(skiprows-1):
                if line.startswith("-"):
                    A = []
                    alist = []
                    vlist = []
                    ulist = []
                    continue
                
                line = line.replace("\n", "")
                symbol = format_symbol(line)
                vlist.append(format_value(line))
                ulist.append(format_uncertainty(line))
                alist.append(format_A(line))
                z = format_z(line)
                toml.update({symbol.upper(): {"z": z,
                                              "A": alist,
                                            "value": vlist, 
                                            "uncertainty": ulist}})
            k += 1

    fpath = fpath_ast
    with open(fpath, "w") as f:
        f.write(tomlkit.dumps(toml))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog='genast', description='Generate toml files from raw data.')
    parser.add_argument("raw", help="File path to the raw data.")
    parser.add_argument("ast", help="File path to the toml file for the ast output.")
    args = parser.parse_args() 

    run(args.raw, args.ast)

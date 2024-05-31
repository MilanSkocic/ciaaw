r"""Generate language independant representation of SAW."""
import argparse
import tomlkit
from math import sqrt, floor, ceil, log10


# Indexes for the table columns
cix_element = [1, 20]
cix_symbol = [21, 30]
cix_z = [31, 40]
cix_saw = [41, 70]
cix_saw_u = [71, 90]
cix_footnote = [91, 100]
cix_asaw = [101, 110]
cix_asaw_u = [111, 120]


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

def format_element(line: str)->str:
    i, j = cix_element
    return line[i-1:j].rstrip()

def format_symbol(line: str)->str:
    i, j = cix_symbol   
    return line[i-1:j].rstrip()

def format_z(line: str)->str:
    i, j = cix_z  
    return line[i-1:j].rstrip()

def format_saw(line):
    i, j = cix_saw 
    saw = line[i-1:j].rstrip()
    i, j = cix_saw_u
    saw_u = line[i-1:j].rstrip()
    
    compute = False
    if ("[" in saw) and ("]" in  saw):
        compute = True
        saw_min, saw_max = saw.replace("[","").replace("]", "").split(",")
    
    if compute:
        saw_max_db = float(saw_max)
        saw_min_db = float(saw_min)

        saw_db = (saw_max_db + saw_min_db)/2.0
        saw_u_db = (saw_max_db - saw_min_db)/(2.0*sqrt(3.0))
        
        n = floor(log10(saw_u_db))
        saw_u_db = ceil(saw_u_db * 10**(-n*1.0))*10**(n*1.0)

        saw = str(round(saw_db, -n))
        saw_u = str(round(saw_u_db, -n))

    else:
        saw_max = "nan"
        saw_min = "nan"

    return saw_max, saw_min, saw, saw_u

def format_asaw(line):
    i, j = cix_asaw
    return line[i-1:j].rstrip()
 
def format_asaw_u(line):
    i, j = cix_asaw_u
    return line[i-1:j].rstrip()

def format_notes(line):
    i, j = cix_footnote
    return line[i-1:j].rstrip()


def run(fpath_raw: str, fpath_ast:str)->None:
    year = get_year(fpath_raw)
    skiprows = get_skiprows(fpath_raw)
    
    toml = tomlkit.document()
    
    k = 0
    fpath = fpath_raw
    with open(fpath, "r") as f:
        for line in f:
            if k >=skiprows :
                line = line.replace("\n", "")
                element = format_element(line)
                symbol = format_symbol(line)
                z = format_z(line)
                saw_max, saw_min, saw, saw_u = format_saw(line)
                asaw = format_asaw(line)
                asaw_u = format_asaw_u(line)
                footnote = format_notes(line)

                toml.update({element.upper(): {"year": year, 
                                        "element": element,
                                        "symbol": symbol,
                                        "z": z,
                                        "saw_min": saw_min,
                                        "saw_max": saw_max,
                                        "saw": saw,
                                        "saw_u": saw_u,
                                        "asaw": asaw,
                                        "asaw_u": asaw_u,
                                        "footnotes": footnote}})
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

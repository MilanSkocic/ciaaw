r"""Format IUPAC"""
import os
import argparse
import csv
import tomlkit

last_year = "2020"


def get_element(nuclide: str)->str:
    """
    Extract the element name from the nuclide name.

    XXXAg -> Ag, A
    """
    for i in range(1, len(nuclide)+1):
        if not nuclide[:i].isdigit():
            break

    return nuclide[i-1:].strip(), nuclide[:i-1].strip()


def clean_year(iupac: str)-> None:
    """
    Create a temporary file where only there are values from the last year.
    """
    fclean = open("naw.csv", "w")
    with open(iupac, "r") as csvfile:
        k = 1
        rows = csv.reader(csvfile)
        for row in rows:
            if k == 3:
                nuclide, value, uncertainty, year = row
                headers = ",".join(row)
                fclean.write(f"{nuclide:10s},{value:20s},{uncertainty:20s},{year:10s}\n")
            
            if k > 4 :
                nuclide, value, uncertainty, year = row
                year = year.split(">")[1].split("<")[0]
                if year == last_year:
                    fclean.write(f"{nuclide:10s},{value:20s},{uncertainty:20s},{year:10s}\n")
                     
            k += 1

    fclean.close()


def generate_data(iupac_clean: str, saw_toml: str)->None:
    """
    Creates the txt file containing the data for the nuclide atomic weights.
    """
    fast_saw = open(saw_toml, "r")
    ast_saw = tomlkit.load(fast_saw)
    
    fdata = open(iupac_clean, "w")

    z, nuclide, A, value, uncertainty, year = ("z", "nuclide", "A", "mass", "uncertainty", "Year/link")
    fdata.write(f"{z:10s}{nuclide:10s}{A:10s}{value:20s}{uncertainty:20s}{year:10s}\n")
    fdata.write("-"*80+"\n")
    
    for e in list(ast_saw.keys()):
        with open("naw.csv", "r") as csvfile:
            
            k = 1
            rows = csv.reader(csvfile)
            
            for row in rows:
                nuclide, value, uncertainty, year = row
                z = ast_saw[e]["z"]
                
                if k > 1:
                    ei, A = get_element(nuclide)
                    if ei == e:
                        fdata.write(f"{z:10s}{ei:10s}{A:10s}{value:20s}{uncertainty:20s}{year:10s}\n")

                k += 1
        fdata.write("-"*80+"\n")
                

                
    fdata.close()
    fast_saw.close()

def run(iupac: str, iupac_clean:str, saw_toml: str)->None:
    
    clean_year(iupac)

    generate_data(iupac_clean, saw_toml)
    
    os.remove("naw.csv")

    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog='cleancsv', description='Clean and format original csv file from CIAAW.')
    parser.add_argument("iupac", help="Original file.")
    parser.add_argument("saw_toml", help="AST file for SAW.")
    parser.add_argument("iupac_clean", help="Cleaned and formatted file.")
    args = parser.parse_args() 

    run(args.iupac, args.iupac_clean, args.saw_toml)

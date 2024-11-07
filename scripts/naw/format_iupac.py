r"""Format IUPAC"""
import argparse
import csv

last_year = "2020"

def run(iupac: str, iupac_clean:str)->None:
    
    fclean = open(iupac_clean, "w")
    elements = [] 
    with open(iupac, "r") as csvfile:
        k = 1
        rows = csv.reader(csvfile)
        for row in rows:
            if k == 3:
                nuclide, value, uncertainty, year = row
                headers = ",".join(row)
                fclean.write(f"{nuclide:10s},{value:20s},{uncertainty:20s},{year:10s}\n")
                fclean.write("-"*60 + "\n")
            
            if k > 4 :
                nuclide, value, uncertainty, year = row
                year = year.split(">")[1].split("<")[0]
                if year == last_year:
                    for i in range(1, len(nuclide)+1):
                        if not nuclide[:i].isdigit():
                            break
                    e = nuclide[i-1:].strip()
                    if e not in elements:
                        elements.append(nuclide[i-1:].strip())
            
            k += 1


    for ei in elements:
        with open(iupac, "r") as csvfile:
            k = 1
            rows = csv.reader(csvfile)
            for row in rows:
                
                if k > 4 :
                    nuclide, value, uncertainty, year = row
                    year = year.split(">")[1].split("<")[0]
                    if year == last_year:
                        for i in range(1, len(nuclide)+1):
                            if not nuclide[:i].isdigit():
                                break
                        e = nuclide[i-1:].strip()
                        if e == ei:
                            fclean.write(f"{nuclide.strip():10s},{value:20s},{uncertainty:20s},{year:10s}\n")

                
                k += 1
    fclean.close()
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog='cleancsv', description='Clean and format original csv file from CIAAW.')
    parser.add_argument("iupac", help="Original file.")
    parser.add_argument("iupac_clean", help="Cleaned and formatted file.")
    args = parser.parse_args() 

    run(args.iupac, args.iupac_clean)

r"""Format IUPAC"""
import argparse
import csv

def run(iupac: str, iupac_clean:str)->None:
    
    fclean = open(iupac_clean, "w")

    with open(iupac, "r") as csvfile:
        rows = csv.reader(csvfile)
        
        k = 1
        for row in rows:
            if k == 3:
                nuclide, value, uncertainty, year = row
                headers = ",".join(row)
                fclean.write(f"{nuclide:10s},{value:20s},{uncertainty:20s},{year:10s}\n")
            if k > 4:
                row[-1] = row[-1].split(">")[1].split("<")[0]
            if row[-1] == "2020":
                nuclide, value, uncertainty, year = row
                fclean.write(f"{nuclide:10s},{value:20s},{uncertainty:20s},{year:10s}\n")
            
            k += 1

    fclean.close()
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog='cleancsv', description='Clean and format original csv file from CIAAW.')
    parser.add_argument("iupac", help="Original file.")
    parser.add_argument("iupac_clean", help="Cleaned and formatted file.")
    args = parser.parse_args() 

    run(args.iupac, args.iupac_clean)

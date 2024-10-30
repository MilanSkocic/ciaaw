r"""Format IUPAC"""
import argparse
import csv

def run(iupac: str, iupac_clean:str)->None:
    pass
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog='cleancsv', description='Clean and format original csv file from CIAAW.')
    parser.add_argument("iupac", help="Original file.")
    parser.add_argument("iupac_clean", help="Cleaned and formatted file.")
    args = parser.parse_args() 

    run(args.iupac, args.iupac_clean)

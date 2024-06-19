r"""Example in python"""
import sys
sys.path.append("../py/src/")
import pyciaaw

print("########## CIAAW VERSION ##########")
print("version ", pyciaaw.__version__)

print("########## CIAAW SAW ##########")
elmt = pyciaaw.H
print("Element: ", elmt["element"])
print("Symbol: ", elmt["symbol"])
print("Z: ", elmt["z"])
print("standard atomic weight max: ", elmt["saw_max"])
print("standard atomic weight min: ", elmt["saw_min"])
print("standard atomic weight: ", elmt["saw"])
print("standard atomic weight uncertainty: ", elmt["saw_u"])
print("abredged standard atomic weight: ", elmt["asaw"])
print("abredged standard atomic weight uncertainty: ", elmt["asaw_u"])
print()

elmt = pyciaaw.F
print("Element: ", elmt["element"])
print("Symbol: ", elmt["symbol"])
print("Z: ", elmt["z"])
print("standard atomic weight max: ", elmt["saw_max"])
print("standard atomic weight min: ", elmt["saw_min"])
print("standard atomic weight: ", elmt["saw"])
print("standard atomic weight uncertainty: ", elmt["saw_u"])
print("abredged standard atomic weight: ", elmt["asaw"])
print("abredged standard atomic weight uncertainty: ", elmt["asaw_u"])

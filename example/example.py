r"""Example in python"""
import sys
sys.path.insert(0, "../py/src/")
import pyciaaw

print("########## CIAAW VERSION ##########")
print("version ", pyciaaw.__version__)

print("########## CIAAW SAW - by atomic number ##########")
print("Abridged Standard Atomic Weight: ", pyciaaw.get_asaw(1))

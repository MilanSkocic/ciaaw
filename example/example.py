r"""Example in python"""
import sys
sys.path.insert(0, "../py/src/")
import pyciaaw

print("########## CIAAW VERSION ##########")
print("version ", pyciaaw.__version__)

print("########## CIAAW SAW  ##########")
print("Abridged Standard Atomic Weight: ", pyciaaw.get_saw("H"))
print("Uncertainty for abridged Standard Atomic Weight: ", pyciaaw.get_saw("H", uncertainty=True))
print("Standard Atomic Weight: ", pyciaaw.get_saw("H", abridged=False, uncertainty=False))
print("Uncertainty for Standard Atomic Weight: ", pyciaaw.get_saw("H", abridged=False, uncertainty=True))


print("########## CIAAW ICE  ##########")
print("N ICE H   = ", pyciaaw.get_nice("H"))
print('ICE H 1   = ', pyciaaw.get_ice("H", A=1))
print('U ICE H 1 = ', pyciaaw.get_ice("H", A=1, uncertainty=True))
print('ICE H 2   = ', pyciaaw.get_ice("H", A=2))
print('U ICE H 2 = ', pyciaaw.get_ice("H", A=2, uncertainty=True))

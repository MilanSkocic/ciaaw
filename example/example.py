#!/usr/bin/env python
r"""EXAMPLE IN PYTHON"""
import sys
sys.path.insert(0, "../py/src/")
import pyciaaw

print("########## CIAAW VERSION ##########")
print("version ", pyciaaw.__version__)

print("########## CIAAW SAW  ##########")
print("ASAW H   = ", pyciaaw.saw("H"))
print("U ASAW H = ", pyciaaw.saw("H", u=True))
print("SAW H    = ", pyciaaw.saw("H", ab=False, u=False))
print("U SAW H  = ", pyciaaw.saw("H", ab=False, u=True))
print("ASAW Tc  = ", pyciaaw.saw("Tc"))

print("########## CIAAW ICE  ##########")
print("N ICE H   = ", pyciaaw.nice("H"))
print('ICE H 1   = ', pyciaaw.ice("H", A=1))
print('U ICE H 1 = ', pyciaaw.ice("H", A=1, u=True))
print('ICE H 2   = ', pyciaaw.ice("H", A=2))
print('U ICE H 2 = ', pyciaaw.ice("H", A=2, u=True))
print("N ICE Tc  = ", pyciaaw.nice("Tc"))
print("N ICE C   = ", pyciaaw.nice("C"))

print("########## CIAAW NAW  ##########")
print('NAW H 2   = ', pyciaaw.naw("H", A=2))
print('U NAW H 2 = ', pyciaaw.naw("H", A=2, u=True))
print("N NAW Tc  = ", pyciaaw.nnaw("Tc"))

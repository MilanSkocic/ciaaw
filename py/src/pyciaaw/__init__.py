"""
SAW: Standard Atomic Weights.

ICE: Isotopic Compositions of the element.

NAW: Nuclide's Atomic Weights.
"""
import platform
import subprocess
import sys
from pathlib import Path

from ._ciaaw import __version__
from . import _ciaaw

def main():
    binary = Path(__file__).parent / "ciaaw"
    if platform.system() == "Windows":
        binary = binary.with_suffix(".exe")

    res = subprocess.run([binary] + sys.argv[1:])
    sys.exit(res.returncode)

def get_saw(s: str, abridged: bool=True, uncertainty: bool=False)->float:
    r"""
    Get the standard atomic weight of the element s.

    Parameters
    ----------
    s: str
        Element symbol.
    abridged: bool, optional
        Flag for the abridged value. Default to True.
    uncertainty: bool, optional
        Flag to get the uncertainty instead of the value. Default to False.

    Returns:
    --------
    saw: float
        Returns NaN if the provided element is incorrect or -1 if the element does not have a standard atomic weight.
    """
    return _ciaaw.get_saw(str(s), bool(abridged), bool(uncertainty))

def get_ice(s:str, A:int, uncertainty: bool=False)->float:
    r"""
    Get the isotopic composition of the element s for the mass number A. 

    Parameters
    ----------
    s: str
        Element symbol.
    A: int
        Mass number.
    uncertainty: bool, optional
        Flag to get the uncertainty instead of the value. Default to False.

    Returns
    -------
    ice: float
        Returns NaN if the provided element or the mass number A are incorrect or -1 if the element does not have an ICE.
    """
    return _ciaaw.get_ice(str(s), int(A), bool(uncertainty))

def get_nice(s:str)->int:
    r"""
    Get the number of isotopes in ICE of the element s.

    Parameters
    ----------
    s: str
        Element symbol.
    
    Returns
    -------
    nice: int
        Returns -1 if the provided element is incorrect.
    """
    return _ciaaw.get_nice(str(s))


def get_naw(s:str, A:int, uncertainty: bool=False)->float:
    r"""
    Get the atomic weight of the nuclide s for the mass number A. 

    Parameters
    ----------
    s: str
        Element symbol.
    A: int
        Mass number.
    uncertainty: bool, optional
        Flag to get the uncertainty instead of the value. Default to False.

    Returns
    -------
    naw: float
        Returns NaN if the provided element or A are incorrect or -1 if the element does not have an NAW.
    """
    return _ciaaw.get_naw(str(s), int(A), bool(uncertainty))

def get_nnaw(s:str)->int:
    r"""
    Get the number of nuclides in NAW of the element s.

    Parameters
    ----------
    s: str
        Element symbol.
    
    Returns
    -------
    nnaw: int
        Returns -1 if the provided element is incorrect.
    """
    return _ciaaw.get_nnaw(str(s))

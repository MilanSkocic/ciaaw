"""CIAAW"""
from ._ciaaw import __version__
from . import _ciaaw

def get_saw(s: str, abridged: bool=True, uncertainty: bool=False)->float:
    r"""
    Get the standard atomic weight. By default the abridged value is provided.
    

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
        Returns NaN if the provided symbol is incorrect or -1 if the element does not have a standard atomic weight.
    """
    return _ciaaw.get_saw(str(s), bool(abridged), bool(uncertainty))

def get_nice(s):
    r"""
    Get the number of isotopes in ICE.

    Parameters
    ----------
    s: str
        Element symbol.
    
    Returns
    -------
    nice: int
        Number of isotopes in ICE. 
        Returns -1 if the provided symbol is incorrect.
    """
    return _ciaaw.get_nice(str(s))

def get_ice(s:str, A:int, uncertainty: bool=False):
    r"""
    Get the isotopic composition of the element for the mass number A. 

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
        Isotopic composition.
        Returns NaN if provided symbol or A are incorrect or -1 if the element does not have an ICE.
    """
    return _ciaaw.get_ice(str(s), int(A), bool(uncertainty))

def get_naw(s:str, A:int, uncertainty: bool=False):
    r"""
    Get the nuclide atomic weight of the element for the mass number A. 

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
        Nuclide atolic weight.
        Returns NaN if provided symbol or A are incorrect or -1 if the element does not have an ICE.
    """
    return _ciaaw.get_naw(str(s), int(A), bool(uncertainty))

def get_nnaw(s):
    r"""
    Get the number of nuclides in NAW.

    Parameters
    ----------
    s: str
        Element symbol.
    
    Returns
    -------
    nice: int
        Number of nuclides in NAW. 
        Returns -1 if the provided symbol is incorrect.
    """
    return _ciaaw.get_nnaw(str(s))

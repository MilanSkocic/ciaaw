"""CIAAW"""
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


def get_nice(s):

    return _ciaaw.get_nice(s)


def get_ice(s:str, A:int, uncertainty: bool=False):
    
    return _ciaaw.get_ice(s, A, uncertainty)

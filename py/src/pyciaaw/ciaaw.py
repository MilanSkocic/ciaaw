"""CIAAW"""
from ._ciaaw import *


def get_saw(s: str, abridged: bool=True, uncertainty: bool=False)->float:
    r"""
    Get the standard atomic weight. By default the abridged value is provided.
    
    If the non abridged value is desired, set abridged to false.
    The uncertainty instead of the value can be retrieved if the uncertainty is set to true.
    Returns NaN if provided symbol is incorrect or -1 if the element does not have a standard atomic weight.

    Parameters
    ----------
    s: str
        Element symbol.
    abridged: bool, optional
        Flag for the abridged value. Default to True.
    uncertainty: bool, optional
        Flag the uncertainty. Default to False.
    """
    return _ciaaw.get_saw(str(s), bool(abridged), bool(uncertainty))

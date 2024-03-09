"""Standard Atomic Weights and Isotopes.

Standard Atomic Weights:
 * The latest values do not have the year as a suffix in their name.
 * Older values can be used and they feature the year as a suffix in their name.
 * The latest values are available at the top level 
 * older values are available in dedicated modules.

The lattest values for saw are from 2021.
"""
from .version import __version__
from . import saw_latest as saw
from . import saw_2021

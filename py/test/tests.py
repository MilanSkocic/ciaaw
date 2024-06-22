r"""Tests"""
import unittest
from pyciaaw import *
from pyciaaw import __version__


class TestVersion(unittest.TestCase):
    r"""Test version module."""

    def test_version(self):
        expected = None
        with open("VERSION", "r") as f:
            expected = f.read().strip()
        value = __version__
        self.assertEqual(value, expected)

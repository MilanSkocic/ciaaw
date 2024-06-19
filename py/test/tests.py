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

class TestYear(unittest.TestCase):
    r"""Test year."""
    def test_year(self):
        value = YEAR
        expected = 2021
        self.assertEqual(value, expected)


class TestSaw(unittest.TestCase):
    r"""Test ciaaw library."""
    def test_asaw(self):
        N = 3
        i = 0
        expected = [0.0] * N
        elements = [{}] * N

        expected[0] = 1.0080
        expected[1] = 12.011
        expected[2] = 20.180

        elements[0] = H
        elements[1] = C
        elements[2] = Ne

        for i in range(N):
            with self.subTest():
                diff = elements[i]["asaw"] - expected[i]
                symbol = elements[i]["symbol"]
                asaw = elements[i]["asaw"]
                self.assertEqual(diff, 0.0, msg=f"   {symbol:s}    {asaw:+23.16f}/{expected[i]}/{diff:+23.16f}")
    

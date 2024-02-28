r"""Tests"""
import unittest
from pyciaaw import saw, version


class TestVersion(unittest.TestCase):
    r"""Test version."""
    def test_version(self):
        value = version.__version__
        expected = "0.1.0"
        self.assertEqual(value, expected)

class TestYear(unittest.TestCase):
    r"""Test year."""
    def test_year(self):
        value = saw.YEAR
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

        elements[0] = saw.H
        elements[1] = saw.C
        elements[2] = saw.Ne

        for i in range(N):
            with self.subTest():
                diff = elements[i]["asaw"] - expected[i]
                symbol = elements[i]["symbol"]
                asaw = elements[i]["asaw"]
                self.assertEqual(diff, 0.0, msg=f"   {symbol:s}    {asaw:+23.16f}/{expected[i]}/{diff:+23.16f}")
    

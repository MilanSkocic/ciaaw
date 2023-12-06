r"""Tests"""
import unittest
from .. import saw
import numpy as np


class TestkH(unittest.TestCase):
    r"""Test ciaaw library."""
    def test_asaw(self):
        N = 2
        i = 0
        expected = [0.0] * N
        elements = [{}] * N

        expected[0] = 1.0080
        expected[1] = 12.011

        elements[0] = saw.H
        elements[1] = saw.C

        for i in range(N):
            with self.subTest():
                diff = elements[i]["asaw"] - expected[i]
                symbol = elements[i]["symbol"]
                asaw = elements[i]["asaw"]
                self.assertEqual(diff, 0.0, msg=f"   {symbol:s}    {asaw:+23.16f}/{expected[i]}/{diff:+23.16f}")
    
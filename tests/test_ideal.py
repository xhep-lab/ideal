"""
Test Python bindings
====================
"""

import unittest

from ideal import umvue_poisson_like


class TestUMVUEPoissonLike(unittest.TestCase):

    def test_zero_cases(self):

        n_exp = 0
        n_mc = 0

        k = 0
        b = 0
        o = 0

        with self.assertRaises(RuntimeError):
            umvue_poisson_like(k, b, o, n_mc, n_exp)

        n_mc = 200

        with self.assertRaises(RuntimeError):
            umvue_poisson_like(k, b, o, n_mc, n_exp)

        n_exp = 100

        self.assertEqual(umvue_poisson_like(k, b, o, n_mc, n_exp), 1.)

        o = 10

        self.assertEqual(umvue_poisson_like(k, b, o, n_mc, n_exp), 0.)

        b = 10

        self.assertEqual(umvue_poisson_like(
            k, b, o, n_mc, n_exp), 0.1251100357211335)

    def test_nmc_lt_nexp(self):
        n_exp = 1000
        n_mc = 500

        k = 10
        b = 10
        o = 10

        self.assertEqual(umvue_poisson_like(
            k, b, o, n_mc, n_exp), 0.0816484507552749)

    def test_nmc_gt_nexp(self):
        n_exp = 1000
        n_mc = 5000

        k = 10
        b = 10
        o = 10

        self.assertEqual(umvue_poisson_like(
            k, b, o, n_mc, n_exp), 0.10582058611122985)


if __name__ == '__main__':
    unittest.main()

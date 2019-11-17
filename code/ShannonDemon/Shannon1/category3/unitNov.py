# https://wikidocs.net/16107
# https://python-guide-kr.readthedocs.io/ko/latest/writing/tests.html

import unittest


def custom_function(x):
    return x + 1


class CustomTests(unittest.TestCase):
    def test_runs(self):
        self.assertEqual(3,custom_function(2))



if __name__ == '__main__':
    unittest.main()

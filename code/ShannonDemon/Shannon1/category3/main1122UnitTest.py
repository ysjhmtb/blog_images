import unittest

'''
https://docs.python.org/3/library/unittest.html 

assertEqual을 쓰시면 됩니다.
assertEqual(ref.total, 20000)
이런식으로~
'''

class CustomTests(unittest.TestCase):
    def test_runs(self):
        self.assertEqual(200,200)

if __name__ == '__main__':
    unittest.main()
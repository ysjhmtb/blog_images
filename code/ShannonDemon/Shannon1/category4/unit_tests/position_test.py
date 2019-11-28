import unittest
from category4.api.position import Position_1128


class CustomTests(unittest.TestCase):
    def Position_1128_firstPosition(self):
        ndqArr = [1559.5]
        vixArr = [14.2]
        ref = Position_1128(ndqArr, vixArr)
        ref.firstPosition(0.5, 0.25, 0.25)
        self.assertEqual(ref.hasLong, True)
        self.assertEqual(ref.hasShort, True)
        self.assertEqual(ref.longStartPrice, ref.shortStartPrice)
        self.assertEqual(ref.cash, 5000.0)
        self.assertEqual(ref.longEntryCount, 1)
        self.assertEqual(ref.longCount, 1)
        self.assertEqual(ref.shortEntryCount, 1)
        self.assertEqual(ref.shortCount, 0)
        self.assertEqual(ref.reserveMoney, 4280.0)

    def test_runs(self):
        self.Position_1128_firstPosition()


if __name__ == '__main__':
    unittest.main()

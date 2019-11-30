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

    def Position_1128_getProfit_long(self):
        ndqArr = [1559.5]
        vixArr = [14.2]
        ref = Position_1128(ndqArr, vixArr)
        ref.firstPosition(0.5, 0.25, 0.25)
        # long 1572.25 : ( (1572.25 - 1559.5) / 0.25 ) * 1 * 0.5 = (12.75 / 0.25) * 1 * 0.5 = 25.5
        self.assertEqual(ref.getProfit(True, 1572.25), 25.5)

    def Position_1128_getProfit_short(self):
        ndqArr = [1559.5]
        vixArr = [14.2]
        ref = Position_1128(ndqArr, vixArr)
        ref.firstPosition(0.5, 0.0, 0.5)
        # short 1572.25 : ( (1559.5 - 1572.25) / 0.25 ) * 2  * 0.5 = (-12.75 / 0.25) * 2 * 0.5 = -51
        self.assertEqual(ref.getProfit(False, 1572.25), -51)

    def Position_1128_checkLiquidation(self):
        ndqArr = [1559.5]
        vixArr = [14.2]
        ref = Position_1128(ndqArr, vixArr)
        ref.firstPosition(0.5, 0.0, 0.5)
        ref.longMaxProfit = 900
        ref.shortMaxProfit = -200
        self.assertTrue(ref.checkLiquidation(559))
        self.assertTrue(ref.checkLiquidation(-721))

    def test_runs(self):
        self.Position_1128_firstPosition()
        self.Position_1128_getProfit_long()
        self.Position_1128_getProfit_short()
        self.Position_1128_checkLiquidation()


if __name__ == '__main__':
    unittest.main()

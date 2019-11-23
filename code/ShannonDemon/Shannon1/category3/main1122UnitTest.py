import unittest
from . import main1122

'''
https://docs.python.org/3/library/unittest.html 

assertEqual을 쓰시면 됩니다.
assertEqual(ref.total, 20000)
이런식으로~
'''

ref = main1122.Position1019(1559.5)


class CustomTests(unittest.TestCase):
    def test_runs(self):
        # 생성자
        self.assertEqual(ref.startPrice, 1559.5)
        self.assertEqual(ref.cash, 5000)
        self.assertEqual(ref.reserveMoney, 3334.0)
        self.assertEqual(ref.posMoney, 226.0)
        self.assertEqual(ref.contractCount, 2)

        # calculateProfit
        self.assertEqual(ref.calculateProfit(1572.25), 204)
        ref.maxProfit = 204

        # checkLiquidation
        self.assertTrue(ref.checkLiquidation(1560))
        self.assertTrue(ref.checkLiquidation(1550))
        self.assertFalse(ref.checkLiquidation(1580))

        # liquidatePostion
        ref.liquidatePostion(1572.25)
        self.assertEqual(ref.totalAsset, 10200.0)

        # startPosition  1559.5
        ref.startPosition(1559.5)
        self.assertEqual(ref.cash, 5100.0)
        self.assertEqual(ref.reserveMoney, 3400.0)
        self.assertEqual(ref.posMoney, 260)
        self.assertEqual(ref.contractCount, 2)

        # updateMaxProfit  1572.25
        ref.updateMaxProfit(1572.25)
        self.assertEqual(ref.maxProfit, 204)




if __name__ == '__main__':
    unittest.main()

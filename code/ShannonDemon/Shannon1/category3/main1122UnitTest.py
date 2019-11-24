import unittest
from category3.main1122 import Position1019, Position1019v2

'''
https://docs.python.org/3/library/unittest.html 

assertEqual을 쓰시면 됩니다.
assertEqual(ref.total, 20000)
이런식으로~
'''


class CustomTests(unittest.TestCase):
    def forPosition1019(self):
        ref = Position1019(1559.5)
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

        # rebalance - rolloverCount
        ref.rolloverCount = 0
        ref.rebalance(1572.25)
        self.assertEqual(ref.rolloverCount, 1)

        # rebalance - wainAndSee*
        ref.waitAndSeeFlag = True
        ref.waitAndSeeCount = 4
        ref.rebalance(1572.25)
        self.assertEqual(ref.waitAndSeeCount, 5)
        ref.rebalance(1572.25)
        self.assertFalse(ref.waitAndSeeFlag)
        self.assertEqual(ref.waitAndSeeCount, 0)

    def Position1019v2_init(self):
        ref = Position1019v2(1559.5)
        self.assertEqual(ref.cash, 9000)
        self.assertEqual(ref.posMoney, 280)
        self.assertEqual(ref.contractCount, 1)

    def Position1019v2_rebalance(self):
        ref = Position1019v2(1559.5)
        ref.rebalanceCount = 20
        ref.rebalance(1572.25)
        self.assertEqual(ref.totalAsset, 10098)
        self.assertEqual(ref.startPrice, 1572.25)
        self.assertEqual(ref.cash, 9088.2)
        self.assertAlmostEqual(ref.posMoney,289.8)

    def test_runs(self):
        self.Position1019v2_init()
        self.Position1019v2_rebalance()


if __name__ == '__main__':
    unittest.main()

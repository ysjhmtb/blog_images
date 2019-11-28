# VIX 15 NDQ 720 0.8
'''
VIX Futures
계약단위 VIX * 1,000 USD
틱단위 0.05
틱가치 $50.00
위탁증거금 8,800
유지증거금 8,000
온라인 수수료 7.5

Micro E-mini NASDAQ 100
계약단위 지수선물가격 * $2
틱단위 0.25 index points
틱가치 $0.50
위탁증거금 792
유지증거금 720
온라인 수수료 2

예) 매수 10계약 3월물 1559.50
매도 10계약 3월물 1572.25
계산:[(1572.25-1559.5)/0.25]X10계약X$5
순이익:USD 2,550
'''


class Position_1128:
    def __init__(self, ndqArr, vixArr):
        self.ndqArr = ndqArr
        self.vixArr = vixArr
        self.hasLong = False
        self.hasShort = False
        self.longStartPrice = None
        self.shortStartPrice = None
        self.totalAsset = 10000
        self.totalArr = []
        self.totalArr.append(self.totalAsset)
        self.cash = 0
        self.reserveMoney = 0
        self.longEntryCount = 0
        self.shortEntryCount = 0
        self.longMaxProfit = 0
        self.shortMaxProfit = 0
        self.CONST_DEPOSIT = 720
        self.longCount = 0
        self.shortCount = 0
        self.waitAndSeeFlag = False
        self.waitAndSeeCount = 0
        self.CONST_FEE = 2
        self.rolloverCount = 0

    def firstPosition(self, cash_ratio, long_ratio, short_ratio):
        assert (cash_ratio + long_ratio + short_ratio) == 1
        if long_ratio > 0.0:
            self.hasLong = True
        if short_ratio > 0.0:
            self.hasShort = True
        if self.hasLong:
            self.longStartPrice = self.ndqArr[0]
        if self.hasShort:
            self.shortStartPrice = self.ndqArr[0]
        self.cash = self.totalAsset * cash_ratio
        self.reserveMoney = self.totalAsset - self.cash
        if self.hasLong:
            self.longEntryCount += 1
            self.longCount = ((self.reserveMoney * (
                        long_ratio / (long_ratio + short_ratio))) // 3) // self.CONST_DEPOSIT
            self.reserveMoney -= (self.longCount * self.CONST_DEPOSIT)
        if self.hasShort:
            self.shortEntryCount += 1
            self.shortCount = ((self.reserveMoney * (
                        short_ratio / (long_ratio + short_ratio))) // 3) // self.CONST_DEPOSIT
            self.reserveMoney -= (self.shortCount * self.CONST_DEPOSIT)

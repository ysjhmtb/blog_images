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
        assert (cash_ratio + long_ratio + short_ratio) == 1.0
        if long_ratio > 0.0:
            self.hasLong = True
        if short_ratio > 0.0:
            self.hasShort = True
        if self.hasLong:
            self.longStartPrice = self.ndqArr['Price'][0]
        if self.hasShort:
            self.shortStartPrice = self.ndqArr['Price'][0]
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

    def rebalance(self):
        self.firstPosition(0.5, 0.5, 0.0)
        for i in range(1, len(self.ndqArr['Price'])):

            # 청산 후 관망
            if self.waitAndSeeFlag:
                if self.waitAndSeeCount < 10:
                    self.waitAndSeeCount += 1
                    continue
                else:
                    self.waitAndSeeFlag = False
                    self.waitAndSeeCount = 0

            # 새로운 진입
            if not self.hasLong:
                vix_i = self.findVixIndex(i)
                if vix_i == -1:
                    vix_i = i

                if self.vixArr['VIX Close'][i] < 15.0:
                    self.restart_long(i, 0.5)
            else:
                # 청산 조건 검사
                if self.checkLiquidation(self.getProfit(True, self.ndqArr['Price'][i])):
                    self.liquidate()
                    continue

                # 최대 수익 업데이트
                self.longMaxProfit = max(self.longMaxProfit, self.getProfit(True, self.ndqArr['Price'][i]))

                # 추가 진입 조건 검사

                if self.checkMoreEntryLong():
                    self.addMoreLong(i)


    def restart_long(self, i, cash_ratio):
        if cash_ratio < 100.0:
            self.hasLong = True
            self.longStartPrice = self.ndqArr['Price'][i]
            self.cash = self.totalAsset * cash_ratio
            self.reserveMoney = self.totalAsset - self.cash
            self.longEntryCount += 1
            self.longCount = (self.reserveMoney // 3) // self.CONST_DEPOSIT
            self.reserveMoney -= (self.longCount * self.CONST_DEPOSIT)

    def checkMoreEntryLong(self):
        if (self.longMaxProfit / self.longCount) > self.CONST_DEPOSIT and self.longEntryCount < 3:
            return True
        else:
            return False

    def addMoreLong(self, i):
        addedCount = (self.reserveMoney // (3 - self.longEntryCount)) // self.CONST_DEPOSIT
        self.longStartPrice = (self.longStartPrice * self.longCount + self.ndqArr['Price'][i] * addedCount) / (
                self.longCount + addedCount)
        self.longCount += addedCount
        self.longEntryCount += 1
        self.reserveMoney -= (self.CONST_DEPOSIT * addedCount)

    def findVixIndex(self, ndqIndex):
        ndqDate = self.ndqArr['Date'][ndqIndex]
        if self.vixArr['Date'][ndqIndex] == ndqDate:
            return ndqIndex
        else:
            j = ndqIndex
            while (j < 2482):
                if self.vixArr['Date'][j] == ndqDate:
                    return j
                else:
                    j += 1
            return -1

    def getProfit(self, isLong, nextPrice):
        if isLong:
            return ((nextPrice - self.longStartPrice) / 0.25) * self.longCount * 0.5
        else:
            return ((self.shortStartPrice - nextPrice) / 0.25) * self.shortCount * 0.5

    def checkLiquidation(self, profit):
        if profit <= (-self.CONST_DEPOSIT * (self.longCount + self.shortCount)):
            return True
        elif profit < (self.longMaxProfit + self.shortMaxProfit) * 0.8:
            return True
        else:
            return False

    def liquidate(self):
        self.hasLong = False
        self.hasShort = False
        self.longStartPrice = None
        self.shortStartPrice = None
        self.totalAsset = self.cash + self.reserveMoney + self.longMaxProfit + self.shortMaxProfit - (
                2 * self.CONST_FEE)
        self.totalArr.append(self.totalAsset)
        self.cash = 0
        self.reserveMoney = 0
        self.longEntryCount = 0
        self.shortEntryCount = 0
        self.longMaxProfit = 0
        self.shortMaxProfit = 0
        self.longCount = 0
        self.shortCount = 0
        self.waitAndSeeFlag = True
        self.waitAndSeeCount = 1

    def drawGraph(self):
        import plotly.express as px
        print("totalArr")
        print(self.totalArr)
        fig = px.line(x=range(len(self.totalArr)), y=self.totalArr)
        fig.show()

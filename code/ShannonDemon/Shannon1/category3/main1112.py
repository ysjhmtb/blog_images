# http://www.cboe.com/products/vix-index-volatility/vix-options-and-futures/vix-index/vix-historical-data
# 계약 단위 VIX * 1,000 USD, 위탁 증거금 6,215 USD, 유지 증거금 5,650 USD

import pandas as pd
import plotly.express as px


def readCsv(path):
    rawdata = pd.read_csv(path)
    # rawdata = rawdata.loc[::-1].reset_index(drop=True)
    return rawdata


raw = readCsv("./vixcurrent.csv")


# it has bugs
class Position:
    def __init__(self, vix):
        self.trustDeposit = 6215
        self.maintainDeposit = 5650
        self.seed = 20000
        self.contractSize = vix * 1000
        self.longCount = ((self.seed - self.trustDeposit) / 2) // self.maintainDeposit
        self.shortCount = self.longCount
        self.cash = self.seed - self.trustDeposit - (self.longCount * self.maintainDeposit) \
                    - (self.shortCount * self.maintainDeposit)
        self.total = (self.longCount * self.maintainDeposit) \
                     + (self.shortCount * self.maintainDeposit) \
                     + self.cash + self.trustDeposit
        self.totalArr = []
        self.totalArr.append(self.total)

    def rebalanceDaily(self, vix):
        fee = self.longCount * 5
        longProfit = ((vix * 1000) - self.contractSize) * self.longCount - fee
        shortProfit = (self.contractSize - (vix * 1000)) * self.shortCount - fee
        self.total = self.cash + self.trustDeposit \
                     + (self.maintainDeposit * self.longCount + longProfit) \
                     + (self.maintainDeposit * self.shortCount + shortProfit)
        self.totalArr.append(self.total)
        self.contractSize = vix * 1000
        self.longCount = ((self.total - self.trustDeposit) / 2) // self.maintainDeposit
        self.shortCount = self.longCount
        self.cash = self.total - self.trustDeposit - (self.longCount * self.maintainDeposit) \
                    - (self.shortCount * self.maintainDeposit)

    def drawGraph(self):
        print("totalArr")
        print(self.totalArr)
        fig = px.line(x=range(len(self.totalArr)), y=self.totalArr)
        fig.show()


# ref = Position(raw['VIX Close'][0])
# for i in range(1, len(raw['VIX Close'])):
#     ref.rebalanceDaily(raw['VIX Close'][i])
#
# ref.drawGraph()

class Position2:
    def __init__(self, vix):
        self.trustDeposit = 6215
        self.maintainDeposit = 5650
        self.seed = 20000 - self.trustDeposit
        self.contractSize = vix * 1000
        self.isLong = True
        self.positionSize = self.seed // self.maintainDeposit
        self.cash = self.seed - self.positionSize * self.maintainDeposit
        self.currTotal = self.seed + self.trustDeposit
        self.totalArr = []
        self.totalArr.append(self.currTotal)
        self.maxProfit = 0

    def update(self, vix):
        profit = 0
        if self.isLong:
            profit = (vix * 1000) - self.contractSize
        else:
            profit = self.contractSize - (vix * 1000)

        if (profit < 0):
            self.currTotal = (profit * self.positionSize) \
                             + (self.positionSize * self.maintainDeposit) + self.cash + self.trustDeposit
            self.totalArr.append(self.currTotal)
            self.contractSize = vix * 1000
            self.isLong = not self.isLong
            self.positionSize = (self.currTotal - self.trustDeposit) // self.maintainDeposit
            self.cash = self.positionSize - self.positionSize * self.maintainDeposit
            self.maxProfit = 0
            return

        if self.maxProfit * 0.9 > profit:
            self.currTotal = (profit * self.positionSize) \
                             + (self.positionSize * self.maintainDeposit) + self.cash + self.trustDeposit
            self.totalArr.append(self.currTotal)
            self.contractSize = vix * 1000
            self.isLong = not self.isLong
            self.positionSize = (self.currTotal - self.trustDeposit) // self.maintainDeposit
            self.cash = self.positionSize - self.positionSize * self.maintainDeposit
            self.maxProfit = 0
            return

        if self.maxProfit < profit:
            self.maxProfit = profit

    def drawGraph(self):
        print("totalArr")
        print(self.totalArr)
        fig = px.line(x=range(len(self.totalArr)), y=self.totalArr)
        fig.show()


ref = Position2(raw['VIX Close'][0])
for i in range(1, len(raw['VIX Close'])):
    ref.update(raw['VIX Close'][i])

ref.drawGraph()
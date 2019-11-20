# http://www.cboe.com/products/vix-index-volatility/vix-options-and-futures/vix-index/vix-historical-data
# 계약 단위 VIX * 1,000 USD, 위탁 증거금 6,215 USD, 유지 증거금 5,650 USD

import pandas as pd
import plotly.express as px


def readCsv(path):
    rawdata = pd.read_csv(path)
    # rawdata = rawdata.loc[::-1].reset_index(drop=True)
    return rawdata


raw = readCsv("./vixcurrent.csv")


class Position:
    def __init__(self, vix):
        self.maintainDeposit = 5650
        self.seed = 20000
        self.vixToUSD = vix * 1000
        if vix < 15:
            self.cash = self.seed * 0.5
            self.longCount = (self.seed - self.cash) / self.maintainDeposit
        elif vix >= 15:
            self.cash = self.seed * 0.8
            self.longCount = (self.seed - self.cash) / self.maintainDeposit
        self.total = self.seed
        self.totalArr = []
        self.totalArr.append(self.total)
        self.rolloverCount = 0

    def rebalance(self, vix):
        if vix > 15:
            diff = (vix * 1000) / self.vixToUSD
            self.total = self.cash + (self.maintainDeposit * self.longCount * diff)
            if self.rolloverCount < 20:
                self.rolloverCount += 1
            elif self.rolloverCount == 20:
                print("rollover\n\n")
                self.rolloverCount = 0
                self.total -= (self.maintainDeposit * self.longCount * diff * 0.05)

            self.totalArr.append(self.total)
            self.vixToUSD = vix * 1000
            self.cash = self.total * 0.8
            self.longCount = (self.total - self.cash) / self.maintainDeposit
        else:
            diff = (vix * 1000) / self.vixToUSD
            self.total = self.cash + (self.maintainDeposit * self.longCount * diff)
            if self.rolloverCount < 20:
                self.rolloverCount += 1
            elif self.rolloverCount == 20:
                print("rollover\n\n")
                self.rolloverCount = 0
                self.total -= (self.maintainDeposit * self.longCount * diff * 0.05)

            self.totalArr.append(self.total)
            self.vixToUSD = vix * 1000
            self.cash = self.total * 0.5
            self.longCount = (self.total - self.cash) / self.maintainDeposit

    def drawGraph(self):
        print("totalArr")
        print(self.totalArr)
        fig = px.line(x=range(len(self.totalArr)), y=self.totalArr)
        fig.show()


ref = Position(raw['VIX Close'][0])
for i in range(1, len(raw['VIX Close'])):
    ref.rebalance(raw['VIX Close'][i])

ref.drawGraph()

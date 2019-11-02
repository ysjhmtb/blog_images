import pandas as pd


class DataPre:
    def readCsv(self, path):
        rawdata = pd.read_csv(path)
        # rawdata = rawdata.loc[::-1].reset_index(drop=True)
        return rawdata
class Position:
    def __init__(self, initialCapital, startPrice, startDate):
        print("init")
        print(startPrice)
        # 초기 자본
        self.initialCapital = initialCapital
        # 롱 포지션 진입 가격
        self.longPrice = startPrice
        # 숏 포지션 진입 가격
        self.shortPrice = startPrice
        # 포지션 진입 시점
        self.positionDate = startDate
        # 롱 포지션 계약 갯수
        self.longCount = (self.initialCapital // 2) // self.longPrice
        # 숏 포지션 계약 갯수
        self.shortCount = (self.initialCapital // 2) // self.shortPrice
        # 롱 포지션 자산
        self.longAsset = self.longPrice * self.longCount
        # 숏 포지션 자산
        self.shortAsset = self.shortPrice * self.shortCount
        # 현금 자산
        self.cashAsset = self.initialCapital - self.longAsset - self.shortAsset
        # 총 자산
        self.totalAsset = self.longAsset + self.shortAsset + self.cashAsset
        # 그래프를 위한 데이터
        self.totalAssetList = []

    def rebalancing(self, updatePrice, updateDate):
        print("rebalancing")
        print(updatePrice)
        print(str(updatePrice / self.longPrice))
        print(str(self.shortPrice / updatePrice))
        # 각 포지션의 평가이익과 평가손실 그리고 현금을 총 자산으로 합치기
        self.longAsset = (updatePrice / self.longPrice) * self.longAsset
        self.shortAsset = (self.shortPrice / updatePrice) * self.shortAsset
        self.totalAsset = self.cashAsset + self.longAsset + self.shortAsset
        self.totalAssetList.append(self.totalAsset)
        # 각 포지션의 계약 갯수와 각 포지션의 자산을 업데이트 하고, 현금 자산 계산하기
        self.longCount = (self.totalAsset // 2) // updatePrice
        self.shortCount = (self.totalAsset // 2) // updatePrice
        self.longAsset = self.longCount * updatePrice
        self.shortAsset = self.shortCount * updatePrice
        self.cashAsset = self.totalAsset - self.longAsset - self.shortAsset
        # 업데이트 된 롱, 숏 포지션 가격
        self.longPrice = updatePrice
        self.shortPrice = updatePrice
        # 업데이트 된 포지션 진입 시점
        self.positionDate = updateDate
        print("total asset  " + str(self.totalAsset))

    def rule5percent(self, pricetocompare, rebaldate):
        if (pricetocompare / self.longPrice >= 1.05):
            print("rebal date  " + rebaldate)
            return True
        elif (self.shortPrice / pricetocompare <= 0.95):
            print("rebal date  " + rebaldate)
            return True
        else:
            return False

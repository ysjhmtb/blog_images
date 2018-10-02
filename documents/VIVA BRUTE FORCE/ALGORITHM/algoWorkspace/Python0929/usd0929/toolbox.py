# toolbox.py

import numpy as np
import matplotlib.pyplot as plt
import csv
import os


# 이전 툴박스, 포지션 클래스에서 약간 수정.

class ToolBox:

    def readFedCsvFiles(self, csvName):
        rawDate = []
        rawUsd = []
        rawTotal = []

        scriptDir = os.path.dirname(__file__)
        relPath = csvName
        absFilePath = os.path.join(scriptDir, relPath)

        f = open(absFilePath, 'r', encoding='utf-8')
        rdr = csv.reader(f)

        for line in rdr:
            rawDate.append(line[0])
            rawUsd.append(line[1])
        f.close()

        if rawDate[0] == 'DATE':
            del rawDate[0]
        if rawUsd[0] == 'DEXKOUS':
            del rawUsd[0]

        # rawTotal
        rawTotal.append(rawDate)
        rawTotal.append(rawUsd)

        rawTotal[1] = self.strToFloat(rawTotal[1])

        return rawTotal

    # rawX의 문자열을 실수로.
    def strToFloat(self, rawX):
        floatX = []

        for i in range(len(rawX)):
            if rawX[i] != '.':
                floatX.append(float(rawX[i]))

            # 숫자가 아니라면 이전 인덱스의 값으로 대체.
            elif rawX[i] == '.':
                if i > 0:
                    if rawX[i - 1] == '.':

                        j = i - 2
                        previousWithNumber = -1
                        while j >= 0:
                            if (rawX[j] != '.'):
                                previousWithNumber = j
                                break
                            j -= 1

                        floatX.append(float(rawX[previousWithNumber]))

                    else:
                        floatX.append(float(rawX[i - 1]))
                else:
                    floatX.append(0)

        return floatX

    # rawX에서 targetValue의 인덱스 찾기
    def findIndexAtValue(self, rawX, targetValue):
        for i in range(len(rawX)):
            if rawX[i] == targetValue:
                return i

    # 입력받은 날짜가 매달 첫째날인지 확인
    def isFirstDayInMonth(self, curDateStr, preDateStr):

        # 오늘 날짜의 월과 이전 날짜의 월이 다르면 오늘 날짜가 이번 달의 첫째날
        # 1981-04-13    인덱스 5가 시작.

        from operator import eq

        curMon = curDateStr[5:7]
        preMon = preDateStr[5:7]

        if (eq(curMon, preMon)):
            return False
        else:
            return True

    # 입력받은 날짜가 매달 마지막 날인지 확인
    def isLastDayInMonth(self, curDateStr, nextDateStr):

        from operator import eq

        curMon = curDateStr[5:7]
        nextMon = nextDateStr[5:7]

        if (eq(curMon, nextMon)):
            return False
        else:
            return True

    # 매일매일의 가격을 첫째날과 비교한 수익률 배열 반환
    def profitsArrComparedWithFirst(self, rawTotal):

        firstDayPrice = 0
        yieldComparedWithFirstList = []

        for i in range(1, len(rawTotal[0]) - 1):

            # 현재 인덱스가 매달 첫째날이라면 가격과 수익률 정보 업데이트.
            if (self.isFirstDayInMonth(rawTotal[0][i], rawTotal[0][i - 1])):
                firstDayPrice = rawTotal[1][i]
                yieldComparedWithFirstList.append(0)
                continue

            # 매달 첫째날이 아니라면 오늘의 가격과 첫째날 가격을 비교.
            yieldComparedWithFirstList.append((rawTotal[1][i] - firstDayPrice) / rawTotal[1][i])

        return yieldComparedWithFirstList

    # XIV
    def xivSimulation(self, rawTotal):

        firstDayPrice = 0
        myPosition = Position()
        print(len(rawTotal[0]))

        for i in range(1, len(rawTotal[0]) - 1):

            # 현재 인덱스가 첫째날이라면
            if (self.isFirstDayInMonth(rawTotal[0][i], rawTotal[0][i - 1])):
                firstDayPrice = rawTotal[1][i]
                continue

            # 포지션 시작 조건 검사
            if (not myPosition.hasPosition and rawTotal[1][i] > (firstDayPrice * 1.05)):
                myPosition.startPosition(rawTotal[1][i], firstDayPrice)
                continue

            # 현재 인덱스 청산 조건 검사
            if (myPosition.hasPosition and myPosition.hasOptionToLiquidate(curMarketPrice=rawTotal[1][i])):

                myPosition.doLiquidation(curMarketPrice=rawTotal[1][i],
                                         curDateStr=rawTotal[0][i],
                                         curIndex=i)

        return myPosition

    # 툴박스 객체 삭제
    def kill(self):
        del self


class Position:

    # 포지션 객체 생성
    def __init__(self):
        self.profitArr = []
        self.hasPosition = False

    # 포지션 시작
    def startPosition(self, positionStartPrice, firstDayPrice):
        self.hasPosition = True
        self.direction = "Short"

        self.positionStartPrice = positionStartPrice
        self.firstDayPrice = firstDayPrice
        self.curGainAndLoss = 0
        self.maxProfit = 0

    # 현재 시장가격에서의 손익 업데이트
    def updateProfitRecords(self, curMarketPrice):
        self.curGainAndLoss = (self.curGainAndLoss - curMarketPrice)

        if (self.curGainAndLoss > self.maxProfit):
            self.maxProfit = self.curGainAndLoss

    # 청산
    def doLiquidation(self, curMarketPrice, curDateStr, curIndex):
        self.curGainAndLoss = (self.positionStartPrice - curMarketPrice)
        self.profitArr.append([curIndex, curDateStr, self.curGainAndLoss,
                               self.curGainAndLoss / self.positionStartPrice])

        self.hasPosition = False
        self.direction = None
        self.positionStartPrice = None
        self.curGainAndLoss = None
        self.maxProfit = None

    # 청산 조건 검사
    def hasOptionToLiquidate(self, curMarketPrice):

        # 손절매
        if (((self.positionStartPrice - curMarketPrice) / self.positionStartPrice) > (-0.1)):
            return True

        # 최대 이익과 비교
        if (self.hasPosition
                and self.curGainAndLoss <= self.maxProfit * 0.8
                and self.maxProfit != 0):
            return True

        return False

'''

https://aaronschlegel.me/black-scholes-formula-python.html


#

S, the spot price of the asset at time t
T, the maturity of the option. Time to maturity is defined as T−t
K, strike price of the option
r, the risk-free interest rate, assumed to be constant between t and T
σ, volatility of underlying asset, the standard deviation of the asset returns


#

N(d)  is the cumulative distribution of the standard normal variable Z

N(d) = {1 / sqrt(2 * pi)} * { integral[-inf, d] e ^ { (-1 / 2) * x^2 } } dx


C(S,t)  is the value at time t of a call option and P(S,t)
is the value at time t of a put option.

C(S, t) = S N(d1) - K { e^{-r (T - t) } } N(d2)

P(S, t) = K { e^{-r (T - t)} } N(-d2) - S N(-d2)




where


d1 = { ln(S/K) + ( r +  { {sigma^2} / 2 } ) * (T - t) } /
        { sigma * sqrt(T - t) }


d2 = d1 - sigma * sqrt(T - t) =
                { ln(S/K) + ( r -  { {sigma^2} / 2 } ) * (T - t) }  /
                { sigma * sqrt(T - t) }




'''


'''

미국의 트레이더였던 제시 리버모어는 큰 돈을 벌다가 결국 파산을 했는데, 
거래 방법 자체가 잘못된 것이었을까요? 
아니면 방법은 옳았지만 베팅비율 조절에 실패한 것일까요?

개골
베팅 실패는 운의 문제가 제일 크죠. 컨트롤할 수 없는 
운 요소를 빼놓고 생각하면 결국 파산까지 이른 베팅 비율이 문제일듯요.

https://ask.fm/cfr0g/answers/150326757866





안녕하세요 개골님. 기초자산 가격이 주어졌을 때, 
그 가격에 상응하는 옵션의 가격을 추론할 수 있을까요? 
그렇게 하려면 어떤 방법론을 사용해야 할까요? 
사용되는 확률 분포가 있을까요? 추천해 주실 문헌이 있는지요? 
읽어주셔서 감사합니다.

개골
옵션 가격 계산은 블랙숄즈 방정식부터 공부하시면 됩니다.

https://ask.fm/cfr0g/answers/150649228522





우선 답변해 주셔서 감사합니다, 개골님. 그런데 제가 질문드렸던 부분은 
기초자산의 가격 데이터만 있는 상황에서 
옵션 시장에서는 옵션이 어느 가격에서 거래될 것인가가 궁금한 것인데, 
이 경우에도 결국 옵션가격을 계산하는 
것이므로 블랙숄즈 모형에서 시작하라는 말씀이신 것이지요?

개골
시장가는 예측이 어렵습니다. 여기에 대해선 수많은 이론이 있지만 
예측을 완벽하게 하는 건 없죠. 
(한다해도 게임이론의 게임상태라 모두가 예측가능한 가격은 불가능합니다) 
하지만 옵션가격은 일단 블랙숄즈의 계산값 근처에서 움직이므로 이걸 
모르고는 이야기가 안될거에요.

https://ask.fm/cfr0g/answers/150652223466


'''


'''

https://brunch.co.kr/@investrecipe/16

# 변동성 - 가격이 올라가고 내려가는 범위. A라는 주식이 시초가에 
         상한가 30%로 시작했는데, 하한가 30%로 바뀌었다면 이 
         주식의 변동성은 60%.
         
# 변동성 계산 - 

2016년 9월 19일    1,000원      변동 없음
2016년 9월 20일    1,100원      변동 100원
2016년 9월 21일    900원        변동 -200원
2016년 9월 22일    1,000원      변동 100원
2016년 9월 23일    1,300원      변동 300원
2016년 9월 26일    1,400원      변동 100원
2016년 9월 27일    1,000원      변동 -400원


평균 변동폭 :
(100 + 200 + 100 + 300 + 100 + 400) / (7 - 1) 
=200

변동비율 : 
7일간 평균 주가 / 7일간 평균 변동폭 = 7일간 변동비율

( (1000 + 1100 + 900 + 1000 + 1300 + 1400 + 1000) / 7 )
/ ( (100 + 200 + 100 + 300 + 100 + 400) / 6 ) 

= 7700 / 200 = 5.5%

꼬리 확인하기 :
9월 23일 변동값은 300원, 9월 27일 변동값은 -400원.
평균 변동 가격은 200원. 23일과 27일이 평균 변동폭보다 많이 움직임.

변동성 범위에서 움직일 확률 : 
(전체 변동성 기준 날짜수 - 전체에서 벗어난 날짜수) 
/ 전체 변동성 기준 날짜수

= (6 - 2) / 6 = 4 / 6 = 0.67 = 67%

이 주식의 7일 동안의 변동성은? :
약 67%의 확률로 5.5% 범위 내에서 가격이 움직인다.


'''





import numpy as np
import scipy.stats as si
import sympy as sy
import sympy.statistics as systats

import matplotlib.pyplot as plt
import csv
import os


class Toolbox:

    # 만일 2018-09-28: 1,109.76 이라면, 현재 가격을 중심으로
    # 행사가격별로 옵션들의 가격을 저장해야 한다. 

    # 유로 콜옵션 심볼릭 연산
    def euro_call_sym(S, K, T, r, sigma):
        # euro_call_sym(50, 100, 1, 0.05, 0.25)
        # S: spot price
        # K: strike price
        # T: time to maturity
        # r: interest rate
        # sigma: volatility of underlying asset

        N = systats.Normal(0.0, 1.0)

        d1 = (sy.ln(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * sy.sqrt(T))
        d2 = (sy.ln(S / K) + (r - 0.5 * sigma ** 2) * T) / (sigma * sy.sqrt(T))

        call = (S * N.cdf(d1) - K * sy.exp(-r * T) * N.cdf(d2))

        return call

    # 유로 풋옵션 심볼릭 연산
    def euro_put_sym(S, K, T, r, sigma):
        # S: spot price
        # K: strike price
        # T: time to maturity
        # r: interest rate
        # sigma: volatility of underlying asset

        N = systats.Normal(0.0, 1.0)

        d1 = (sy.ln(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * sy.sqrt(T))
        d2 = (sy.ln(S / K) + (r - 0.5 * sigma ** 2) * T) / (sigma * sy.sqrt(T))

        put = (K * sy.exp(-r * T) * N.cdf(-d2) - S * N.cdf(-d1))

        return put

    # FRED 데이터를 읽어들이기.
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





























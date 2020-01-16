# ELS_MC_1D.py

import numpy as np
from datetime import date

# 시뮬레이션 횟수
n = 10000
# 이자율
r = 0.0165
# 변동성
vol = 0.1778
# 최초 기준 가격평가일
n0 = date.toordinal(date(2018, 3, 23))
# 1차 조기 상환일
n1 = date.toordinal(date(2018, 9, 19))
# 2차 조기 상환일
n2 = date.toordinal(date(2019, 3, 20))
# 3차 조기 상환일
n3 = date.toordinal(date(2019, 9, 19))
# 4차 조기 상환일
n4 = date.toordinal(date(2020, 3, 19))
# 5차 조기 상환일
n5 = date.toordinal(date(2020, 9, 21))
# 만기 상환일
n6 = date.toordinal(date(2021, 3, 19))
# 조기상환일 벡터
check_day = np.array([n1 - n0, n2 - n0, n3 - n0, n4 - n0, n5 - n0, n6 - n0])
# 1년의 일수
oneyear = 365
# 만기 상환일
tot_date = n6 - n0
# 시간 격자 간격
dt = 1 / oneyear
# 주가 벡터 생성
S = np.zeros([tot_date + 1, 1])
# 기초 자산의 초깃값
S[0] = 100.0
# 조기행사가격 벡터
strike_price = np.array([0.95, 0.95, 0.95, 0.90, 0.90, 0.85]) * S[0]
# 조기상환 횟수
repay_n = len(strike_price)
# 조기행사 시 받게 되는 이자율 벡터
coupon_rate = np.array([0.022, 0.044, 0.066, 0.088, 0.11, 0.132])
# 조기상환 시 페이오프 벡터
payment = np.zeros([repay_n, 1])
# 액면금액
facevalue = 10 ** 4
# 전체 페이오프 벡터
tot_payoff = np.zeros([repay_n, 1])
# 페이오프 벡터
payoff = np.zeros([repay_n, 1])
# 현가 할인 된 페이오프 벡터
discount_payoff = np.zeros([repay_n, 1])
# 낙인 베리어
kib = 0.65 * S[0]
# 더미 이자율
dummy = 0.132
# 조기상환 했을 때의 페이오프 벡터 생성
for j in range(repay_n):
    payment[j] = facevalue * (1 + coupon_rate[j])
# 몬테카를로 시뮬레이션을 이용한 ELS 가격 결정
for i in range(n):
    print(i)
    # 만기상환일 만큼의 랜덤넘버 생성
    z = np.random.normal(0, 1, size=[tot_date, 1])
    # 임의의 주가 경로 생성
    for j in range(tot_date):
        S[j + 1] = S[j] * np.exp((r - 0.5 * vol ** 2) * dt + vol * np.sqrt(dt) * z[j])
    # 조기상환일 체크하여 페이오프 결정
    S_checkday = S[check_day]
    payoff = np.zeros([repay_n, 1])
    # 조기상환이 되지 않은 상태를 의미함. for 문을 빠져나감.
    repay_event = 0
    for j in range(repay_n):
        if S_checkday[j] >= strike_price[j]:
            payoff[j] = payment[j]
            # 조기상환이 된 상태를 의미함.
            repay_event = 1
            break
    # 조기상환이 되지 않고 만기까지 온 경우
    if repay_event == 0:
        # 낙인 배리어 아래로 내려간 적이 없는 경우
        if min(S) > kib:
            payoff[-1] = facevalue * (1 + dummy)
        # 낙인 배리어 아래로 내려간 적이 있는 경우
        else:
            payoff[-1] = facevalue * (S[-1] / S[0])
    # 시뮬레이션마다 페이오프를 더함.
    tot_payoff = tot_payoff + payoff
# 모든 시뮬레이션의 페이오프의 평균을 구함.
mean_payoff = tot_payoff / n
# 페이오프를 무위험 이자율로 할인하여 현재 가격을 구함.
for j in range(repay_n):
    discount_payoff[j] = mean_payoff[j] * np.exp(-r * check_day[j] / oneyear)

# ELS 가격을 구함.
price = np.sum(discount_payoff)
print(price)

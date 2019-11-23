'''

https://fx.kiwoom.com/fxk.template.do?m=m0302000000&

Micro E-mini NASDAQ
위탁 증거금 792 유지 증거금 720
상품코드 MNQ
계약단위 지수선물가격 X $2
틱단위 0.25 Index Points

손익계산 예
예) 매수 10계약 3월물 1559.50
매도 10계약 3월물 1572.25
계산:[(1572.25-1559.5)/0.25]X10계약X$5
순이익:USD 2,550

2010 - 2019 데이터
데이터가 들어오면 롱으로 초기화
다음 가격이 진입 가격보다 낮으면 청산
다음 가격이 들어오면 최대 수익 갱신
다음 가격이 들어오면 최대 수익 80% 하회하면 청산
청산 후 5거래일 동안은 관망

롤오버 마진콜 수수료까지 고려
'''

'''
During his lifetime, Livermore gained and lost several multimillion-dollar fortunes.
He sometimes played hunches, famously selling Union Pacific railroad short
right before the 1906 San Francisco earthquake.

Most notably, he was worth $3 million and $100 million after the 1907 and 1929 market crashes, respectively.
Adjusted for inflation, $100 million in 1929, equals about $1.13 billion in 2016.

He subsequently lost both fortunes. Apart from his success as a securities speculator,
Livermore left traders a working philosophy for trading securities
that emphasizes increasing the size of one's position as it goes in the right direction
and cutting losses quickly.

https://en.wikipedia.org/wiki/Jesse_Lauriston_Livermore

미국의 트레이더였던 제시 리버모어는 큰 돈을 벌다가 결국 파산을 했는데,
거래 방법 자체가 잘못된 것이었을까요? 아니면 방법은 옳았지만 베팅비율 조절에 실패한 것일까요?
개골
베팅 실패는 운의 문제가 제일 크죠. 컨트롤할 수 없는 운 요소를 빼놓고 생각하면 결국 파산까지 이른 베팅 비율이 문제일듯요.
https://ask.fm/cfr0g/answers/150326757866

자본가가 장땡임을 안 건 주식 짤짤이를 취미삼아 시작하고 나서인데, 이게 1%포인트 내외의 변동성에만 베팅하는 단순한 전략을 써도
투자자금만 많으면 그냥 하루 노동소득 이상 쉽게 벌린다는 것이다. 그 이후로 노동관이 바뀜(....)
오후 4:20 · 2015년 12월 1일
https://twitter.com/cfr0g/status/671589636829929472

안녕하세요, 개골님. 주식 짤짤이를 할때 반대되는 포지션을 동시에 보유할 때는 어떤 목적이 있는 것일까요?
예를 들어, long 0.6, short 0.4의 비율로 가져가는 포지션라면 그냥 long 0.2, 현금 0.8로 구성하면 안 되나요?
개골
상관없습니다. 그냥 오르고 떨어지는 (나름으로 계산한) 확률분포를 반영한 배팅 비율인데, 떨어지는 쪽은 굳이 걸지 않고 중립으로 둬도 되긴 하지요.
https://ask.fm/cfr0g/answers/152527338474

답변 감사합니다. 개골님. 그렇다면 만약 개골님이 주식 짤짤이를 하실 때, long 0.7, short 0.2, 현금 0.1로 포지션을 구성하신다면
투자 기간 동안 상승확률을 70%, 하락확률을 20%로 보신다는 것일까요?
개골
네 디테일은 다릅니다만 대충 그런 셈이죠. 주기적으로 밸런싱하구요.
https://ask.fm/cfr0g/answers/152527572970

개골님! 주식 거래에 있어서 해주실 조언 부탁드려요. 거래전략을 세우기 위해 어떤 조언을 해주실 수 있을까요?
개골
가격예측보다 보통 투자금액 배분에 더 신경쓰는 편이 좋습니다.
https://ask.fm/cfr0g/answers/142743688426

개골님의 최고 수익률 주식은 언제 어떤 것이었나요... #저는_지금이_하한가입니다 — 전 거의 대부분의 전략이 5% 경계안에서 꾸준히 먹는 것이라서, 
크게 수익률 난 적은 없습니다. http://ask.fm/a/bembfoj8
오전 1:10 · 2014년 11월 26일
https://twitter.com/cfr0g/status/537277114689802240

최성훈: 보통 옵션 스캘퍼들이 승률이 90% 정도 나왔음. 그런데 저 같는 경우는 70% 정도. 하루 손실폭은 회사에서 정해 주고,
그 손실 한계를 넘을 수 없음. 저는 그 손실 한도에 자주 가는 딜러였음. 저는 손실 한도에 많이 가는 반면 수익을 극대화시키는 것에 초점을 둠.
총 쓸 수 있는 계약이 30계약이면 한번에 들어갈 때 10개씩 3번에 나누어 들어감. 많은 계약을 돈이라고 인식하면 매매를 못하기 때문에 그냥 숫자로 인식함.
시장이라는 것이 항상 들쑥날쑥 할 수는 없음. 한 가지 확실한 것은 위든 아래든 추세는 생긴다는 것. 그럼 그 추세가 생길 때 수익을 극대화시킬 수 있고,
추세가 안 생길 때 손실을 최소화 할 수 있으면 영원한 52%를 만들 수 있을 것이라 생각함. 추세추종이 어려운 것은 기본적으로 인간의 본성을 거스르는
것이기 때문임. 대부분의 사람들은 현재 내가 확보하고 있는 수익이 주는 것을 매우 싫어함. 추세적인 마인드로 생각하면 내가 잘될 때는 계속 공격적으로
베팅을 늘려야 하고 안될 때는 계속 줄여야 함.

박호두 반대매매로 수억을 번 시청자 [박호두 구걸로그] https://youtu.be/RVMoS9DKjQw
'''


class Position1019:
    # price = 1559.5
    def __init__(self, price):
        self.hasLong = True
        self.startPrice = price  # 1559.5
        self.totalAsset = 10000
        self.totalArr = []
        self.totalArr.append(self.totalAsset)
        self.CONST_CASH_RATIO = 0.5
        self.cash = self.totalAsset * self.CONST_CASH_RATIO  # 5,000
        self.reserveMoney = self.totalAsset - self.cash  # 5,000
        self.posMoney = self.reserveMoney // 3  # 1,666
        self.reserveMoney -= self.posMoney  # 5,000 -> 3,334
        self.entryCount = 1
        self.maxProfit = 0
        self.CONST_DEPOSIT = 720
        self.contractCount = self.posMoney // self.CONST_DEPOSIT  # 2
        self.posMoney -= (self.contractCount * self.CONST_DEPOSIT)  # 1,666 -> 226
        self.waitAndSeeFlag = False
        self.waitAndSeeCount = 0
        self.CONST_FEE = 2
        self.rolloverCount = 0

    # price = 1,572.25
    def liquidatePostion(self, price):
        # 5,000 + 3,334 + 226 + 204 + 2 * 720 = 10,204
        # 10,204 - 4 = 10,200
        self.totalAsset = self.cash + self.reserveMoney + self.posMoney \
                          + self.calculateProfit(price) \
                          + (self.contractCount * self.CONST_DEPOSIT) - (2 * self.CONST_FEE)
        self.totalArr.append(self.totalAsset)
        self.cash = 0
        self.reserveMoney = 0
        self.posMoney = 0
        self.entryCount = 0
        self.maxProfit = 0
        self.contractCount = 0
        self.waitAndSeeFlag = True
        self.waitAndSeeCount = 0
        self.hasLong = False
        self.startPrice = None

    # price = 1,572.25
    def calculateProfit(self, price):
        # 계산:[(1572.25-1559.5)/0.25] X 2계약 X $2 = $204
        return ((price - self.startPrice) / 0.25) * self.contractCount * 2

    def checkLiquidation(self, price):
        if price < self.startPrice:
            return True
        elif self.calculateProfit(price) < self.maxProfit * 0.8:
            return True
        else:
            return False

    # price = 1559.5
    def startPosition(self, price):
        self.hasLong = True
        self.startPrice = price
        # 10200 * 0.5 = 5,100
        self.cash = self.totalAsset * self.CONST_CASH_RATIO
        # 10,200 - 5,100 = 5,100
        self.reserveMoney = self.totalAsset - self.cash
        # 1,700
        self.posMoney = self.reserveMoney // 3
        # 5,100 - 1,700 = 3,400
        self.reserveMoney -= self.posMoney
        self.entryCount = 1
        self.maxProfit = 0
        # 1,700 // 720 = 2
        self.contractCount = self.posMoney // self.CONST_DEPOSIT
        # 1,700 - (2 * 720) = 260
        self.posMoney -= (self.contractCount * self.CONST_DEPOSIT)
        self.waitAndSeeFlag = False
        self.waitAndSeeCount = 0

    def checkRollover(self):
        if self.rolloverCount == 20:
            self.rolloverCount += 1
            if self.hasLong:
                self.totalAsset -= self.totalAsset * 0
        else:
            self.rolloverCount += 1

    # price = 1,572.25
    def updateMaxProfit(self, price):
        if self.calculateProfit(price) > self.maxProfit:
            self.maxProfit = self.calculateProfit(price)

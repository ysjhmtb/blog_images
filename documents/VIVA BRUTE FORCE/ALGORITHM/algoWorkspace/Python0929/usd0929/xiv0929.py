'''


Trading volatility? Good luck catching that sharp knife


On the other hand, the “inverse” Vix ETNs,
which bet on Vix falling by selling longer dated volatility index futures,
have been phenomenally lucrative. The VelocityShares Daily Inverse Vix Short-Term ETN
has returned more than 700 per cent since launching at the end of 2010.

Goldman Sachs’ options guru, Krag Gregory, estimates that being short volatility
since the post-crisis nadir in 2009 would have netted an investor returns since then of 4,364 per cent.

But even inverse Vix ETNs can be dangerous. When volatility jumps the losses can be horrific — XIV
lost over a quarter of its value in just one day after the UK voted to leave the EU
 — and in extremis investors can be obliterated.

XIV has a kill switch that can be flicked by the sponsor if it loses more than 80 per cent of its value in a day.

But the bigger worry is that the growth of the complex,
interlinked Vix ETP ecosystem is not just sparking dangers
for investors in individual funds but also the broader market.

This is something that “gnaws” at Peter Tchir,
an analyst at Brean Capital. He points out that VIX ETPs
are new products untested by severe turmoil,
which could reveal pernicious weaknesses and feedback loops.

https://www.ft.com/content/a8589eac-30e0-11e7-9555-23ef563ecf9a






Chris Hyunkwon Chung @Pyramiding

미국 달러 약세가 장기적 추세인 이유

미국달러는 2027년까지 약세 전망

미국 달러는 기축통화를 유지하면서 전 세계에 무제한의 유동성을 수출하고
그 과정에서 미국은 저렴한 상품을 수입. 그러다 한 번의 정치적인 한 수로 밸런스를 맞춤.
달러는 미국의 최대 수출상품.

https://blog.naver.com/mktgguy/221366008156

오후 7:12 - 2018년 9월 27일



'''

# xiv0929.py

from usd0929.toolbox import ToolBox
import matplotlib.pyplot as plt
import numpy as np

toolbox = ToolBox()
rawTotal = toolbox.readFedCsvFiles("DEXKOUS180924.csv")
myPosition = toolbox.xivSimulation(rawTotal)


# optimal allocation

f = 0
fList = []
maxList = []

while f < 15:
    elog1fx = 0
    for k in range(len(myPosition.profitArr)):
        elog1fx += ((1 / len(myPosition.profitArr)) * np.log2(1 + f * myPosition.profitArr[k][3]))
    fList.append(f)
    maxList.append(elog1fx)

    f += 0.01

plt.plot(fList, maxList, label="f1")
plt.legend()
plt.show()

# capital growth

seed = 100
seedList = []
for i in range(len(myPosition.profitArr)):
    seed *= (1 + 5 * myPosition.profitArr[i][3])
    seedList.append(seed)

plt.plot(seedList, label="capital growth")
plt.legend()
plt.show()




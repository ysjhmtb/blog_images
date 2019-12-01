# 생성자에서 NASDAQ, VIX, CASH_RATIO를 입력받아 계산

from category4.api.tool import Toolbox
from category4.api.position import Position_1128

tool = Toolbox()
vix = tool.readCsv("./data/vixcurrent.csv")
vix = tool.transformVixDate(vix)
vix = vix[1511:len(vix)].reset_index(drop=True)
ndq = tool.readCsv_loc("./data/NasdaqFuturesHistoricalData.csv")
ndq = tool.trimData_1127(ndq)
for i in range(len(ndq['Price'])):
    ndq['Price'][i] = tool.strToF_NDQ(ndq['Price'][i])

ref = Position_1128(ndq, vix)
ref.rebalance()
ref.drawGraph()

'''
for i in range(len(ndq)):
    if ndq['Date'][i] == "Nov 11, 2019":
        print("----------------------- Nov 11, 2019")
        print(i)    # 2473
    if vix['Date'][i] == "Nov 11, 2019":
        print("----------------------- Nov 11, 2019")
        print(i)  # 2481

    if ndq['Date'][i] != vix['Date'][i]:
        print(i)
        print(ndq['Date'][i])
        print(vix['Date'][i])


print(vix)
print(ndq)
'''

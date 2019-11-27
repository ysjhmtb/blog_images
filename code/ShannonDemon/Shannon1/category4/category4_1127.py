# 생성자에서 NASDAQ, VIX, CASH_RATIO를 입력받아 계산

from category4.api.tool import Toolbox
import pandas as pd

tool = Toolbox()
vix = tool.readCsv("./data/vixcurrent.csv")
vix = tool.transformVixDate(vix)
vix = vix[1511:len(vix)].reset_index(drop=True)
ndq = tool.readCsv_loc("./data/NasdaqFuturesHistoricalData.csv")

ndq = tool.trimData_1127(ndq)

for i in range(len(ndq)):
    if ndq['Date'][i] != vix['Date'][i]:
        print(i)
        print(ndq['Date'][i])
        print(vix['Date'][i])

print(vix)
print(ndq)

from category1.main1api import *
import plotly.express as px

ref = DataPre()
rawdata = ref.readCsv("./DCOILWTICO.csv")
print(rawdata)
# print(rawdata['날짜'][2].index('년'))

myp = Position(1000000, float(rawdata['DCOILWTICO'][0]), rawdata['DATE'][0])


for i in range(1, len(rawdata['DCOILWTICO'])):
    if rawdata['DCOILWTICO'][i] == ".":
        continue
    # myp.rebalancing(float(rawdata['DCOILWTICO'][i]), rawdata['DATE'][i])
    if (myp.rule5percent(float(rawdata['DCOILWTICO'][i]), rawdata['DATE'][i])):
        myp.rebalancing(float(rawdata['DCOILWTICO'][i]), rawdata['DATE'][i])

print(len(myp.totalAssetList))
fig = px.line(x=range(len(myp.totalAssetList)), y=myp.totalAssetList)
fig.show()

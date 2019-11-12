from category2.getdata import getDataFromNaver

# 신한 S&P500 VIX S/T 선물 ETN B 500045
vix = getDataFromNaver(500045)
# KODEX 레버리지 122630
kospi = getDataFromNaver(122630)

print(type(vix['date'][1]))
print(type(kospi['date'][1]))
print(vix)
print(kospi)


class Position:
    def __init__(self, vixPrice, kospiPrice):
        self.seed = 1000000
        self.vixPrice = vixPrice
        self.kospiPrice = kospiPrice
        self.vixQuant = (self.seed // 2) // self.vixPrice
        self.kospiQuant = (self.seed // 2) // self.kospiPrice
        self.cash = self.seed - (self.vixPrice * self.vixQuant) \
                    - (self.kospiPrice * self.kospiQuant)
        self.totalArr = [self.vixPrice * self.vixQuant + self.kospiPrice * self.kospiQuant \
                         + self.cash]
        print("vix asset: " + str(self.vixPrice * self.vixQuant))
        print("kospi asset: "  + str(self.kospiPrice * self.kospiQuant))
        print("cash asset: " + str(self.cash))
        print("\n\n")

    def rebalance(self, vixPrice, kospiPrice):
        self.vixPrice = vixPrice
        self.kospiPrice = kospiPrice
        total = self.vixPrice * self.vixQuant + \
                self.kospiPrice * self.kospiQuant + \
                self.cash
        self.vixQuant = (total // 2) // self.vixPrice
        self.kospiQuant = (total // 2) // self.kospiPrice
        self.cash = total - (self.vixPrice * self.vixQuant) \
                    - (self.kospiPrice * self.kospiQuant)
        self.totalArr.append(self.vixPrice * self.vixQuant + self.kospiPrice * self.kospiQuant \
                             + self.cash)
        print("vix asset: " + str(self.vixPrice * self.vixQuant))
        print("kospi asset: " + str(self.kospiPrice * self.kospiQuant))
        print("cash asset: " + str(self.cash))
        print("total asset: " + str(self.totalArr[len(self.totalArr) - 1]))


pos = Position(vix['close'][0], kospi['close'][0])
for i in range(1, len(vix)):
    if i % 20 == 0:
        print("vix price: " + str(vix['close'][i]))
        print("kospi price: " + str(kospi['close'][i]))
        pos.rebalance(vix['close'][i], kospi['close'][i])
        print("\n\n")

print(pos.totalArr)
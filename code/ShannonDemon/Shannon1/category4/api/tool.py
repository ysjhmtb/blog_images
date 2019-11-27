import pandas as pd


class Toolbox:
    def readCsv(self, path):
        rawdata = pd.read_csv(path)
        return rawdata

    def readCsv_loc(self, path):
        rawdata = pd.read_csv(path)
        rawdata = rawdata.loc[::-1].reset_index(drop=True)
        return rawdata

    def transformVixDate(self, vix):
        # 1/2/2004 -> Jan 02, 2004
        for i in range(len(vix['Date'])):
            tmp = vix['Date'][i]
            tmpArr = tmp.split("/")
            tmp = ""
            if tmpArr[0] == "1":
                tmp += "Jan "
            elif tmpArr[0] == "2":
                tmp += "Feb "
            elif tmpArr[0] == "3":
                tmp += "Mar "
            elif tmpArr[0] == "4":
                tmp += "Apr "
            elif tmpArr[0] == "5":
                tmp += "May "
            elif tmpArr[0] == "6":
                tmp += "Jun "
            elif tmpArr[0] == "7":
                tmp += "Jul "
            elif tmpArr[0] == "8":
                tmp += "Aug "
            elif tmpArr[0] == "9":
                tmp += "Sep "
            elif tmpArr[0] == "10":
                tmp += "Oct "
            elif tmpArr[0] == "11":
                tmp += "Nov "
            elif tmpArr[0] == "12":
                tmp += "Dec "

            if len(tmpArr[1]) == 1:
                tmp += (str(0) + tmpArr[1] + ", ")
            else:
                tmp += (tmpArr[1] + ", ")

            tmp += tmpArr[2]
            vix['Date'][i] = tmp
        return vix

    def getIdxForDate(self, date, df):
        for i in range(len(df)):
            if date == df['Date'][i]:
                return i
        return -1

    def trimData_1127(self, ndq):
        for i in range(len(ndq)):
            if ndq['Vol.'][i] == "-":
                ndq = ndq.drop(i, 0)
        ndq = ndq.reset_index(drop=True)

        for i in range(len(ndq)):
            if ndq['Vol.'][i] == "0.00%":
                ndq = ndq.drop(i, 0)
        ndq = ndq.reset_index(drop=True)
        return ndq

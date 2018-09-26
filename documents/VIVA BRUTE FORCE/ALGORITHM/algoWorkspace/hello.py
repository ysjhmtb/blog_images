'''

relation	                    result
[[100,ryan,music,2],
[200,apeach,math,2],
[300,tube,computer,3],
[400,con,computer,4],
[500,muzi,music,3],
[600,apeach,music,2]]	            2


유일성(uniqueness) : 릴레이션에 있는 모든 튜플에 대해 유일하게 식별되어야 한다.
최소성(minimality) : 유일성을 가진 키를 구성하는 속성(Attribute) 중 하나라도 제외하는 경우 유일성이 깨지는 것을 의미한다.
                    즉, 릴레이션의 모든 튜플을 유일하게 식별하는 데 꼭 필요한 속성들로만 구성되어야 한다.


유일성은 키가 저장된 맵의 크기를 relation의 크기와 비교하여 판별한다.
최소 단위로 유일성을 검사하고, 이미 유일성을 갖춘 키에는 단위를 추가하지 않도록 하여 최소성을 보장한다.

'''


class Solution:
    resultsSet = set()
    resultsList = []

    def solution(self, relation):

        colsCount = len(relation[0])
        # 가능한 후보 키들의 조합
        # [[0], [0, 1], [0, 2], [0, 3], [0, 2, 3], [0, 1, 2], [0, 1, 3], [0, 1, 2, 3],
        #   [1], [1, 2], [1, 3], [1, 2, 3], [2], [2, 3], [3]]
        keys = self.generateKeys(colsCount=colsCount)

        for i in range(len(keys)):
            keyArr = keys[i]

            if (self.isUnique(keyArr=keyArr, relation=relation)):
                self.resultsList.append(keyArr)

        # [[0], [0, 1], [0, 2], [0, 3], [0, 2, 3], [0, 1, 2], [0, 1, 3], [0, 1, 2, 3], [1, 2], [1, 2, 3]]
        print(self.resultsList)

        self.ensureMinimality()

        import copy
        tempArr = copy.deepcopy(self.resultsList)
        self.resultsList = []

        for i in range(len(tempArr)):
            if (tempArr[i] != "del"):
                self.resultsList.append(tempArr[i])

        # [[0], [1, 2]]
        print(self.resultsList)

        return len(self.resultsList)

    def ensureMinimality(self):

        import copy
        tempArr = copy.deepcopy(self.resultsList)

        i = 0
        while (i < len(tempArr) - 1):

            j = i + 1
            while j < len(tempArr):
                resStr = self.delLeftRight(tempArr[i], tempArr[j])
                if (resStr == "deleteRight"):
                    tempArr[j] = "del"
                elif (resStr == "deleteLeft"):
                    tempArr[i] = "del"

                j += 1

            i += 1

        self.resultsList = tempArr

        return

    def delLeftRight(self, arrL, arrR):

        if (len(arrL) == len(arrR)):
            return "noDelete"
        count = 0

        if (len(arrL) < len(arrR)):

            for i in range(len(arrL)):
                for j in range(len(arrR)):
                    if (arrL[i] == arrR[j]):
                        count += 1

            if (count == len(arrL)):
                return "deleteRight"

        elif (len(arrL) < len(arrR)):

            for i in range(len(arrR)):
                for j in range(len(arrL)):
                    if (arrR[i] == arrL[j]):
                        count += 1
            if (count == len(arrR)):
                return "deleteLeft"

    def isUnique(self, keyArr, relation):
        rowsCount = len(relation)
        keySet = set()
        listToSet = []

        for i in range(len(relation)):
            key = ""

            for j in range(len(keyArr)):
                key += relation[i][keyArr[j]]

            listToSet.append(key)
            keySet.update(listToSet)
            listToSet = []

        return len(keySet) == rowsCount

    def generateKeys(self, colsCount):
        resultsArr = []

        for i in range(colsCount):
            prefixArr = []
            prefixArr.append(i)
            resultsArr.append(prefixArr)
            self.generatingHelper(prefixArr=prefixArr, curLevel=1, limitLevel=colsCount,
                                  startNum=i + 1, resultsArr=resultsArr)

        return resultsArr

    def generatingHelper(self, prefixArr, curLevel,
                         limitLevel, startNum, resultsArr):
        if (curLevel > limitLevel):
            return

        if (startNum > limitLevel - 1):
            return

        toPrefix = []

        for i in range(len(prefixArr)):
            toPrefix.append(prefixArr[i])

        toPrefix.append(startNum)
        resultsArr.append(toPrefix)

        self.generatingHelper(prefixArr, curLevel,
                              limitLevel, startNum + 1, resultsArr)
        self.generatingHelper(toPrefix, curLevel + 1,
                              limitLevel, startNum + 1, resultsArr)


ref = Solution()

relation = [
    ["100", "ryan", "music", "2"],
    ["200", "apeach", "math", "2"],
    ["300", "tube", "computer", "3"],
    ["400", "con", "computer", "4"],
    ["500", "muzi", "music", "3"],
    ["600", "apeach", "music", "2"]
]

print(ref.solution(relation))

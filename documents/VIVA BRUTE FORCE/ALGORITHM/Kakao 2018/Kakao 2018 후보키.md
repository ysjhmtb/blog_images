# Kakao 2018 후보키

<br>

프렌즈대학교 컴퓨터공학과 조교인 제이지는 네오 학과장님의 지시로, 학생들의 인적사항을 정리하는 업무를 담당 하게 되었다. <br>

그의 학부 시절 프로그래밍 경험을 되살려, 모든 인적사항을 데이터베이스에 넣기로 하였고, 이를 위해 정리를 하던 중에 후보키(Candidate Key)에 대한 고민이 필요하게 되었다. <br>

후보키에 대한 내용이 잘 기억나지 않던 제이지는, 정확한 내용을 파악하기 위해 데이터베이스 관련 서적을 확인하여 아래와 같은 내용을 확인하였다. <br>

- 관계 데이터베이스에서 릴레이션(Relation)의 튜플(Tuple)을 유일하게 식별할 수 있는 속성(Attribute) 또는 속성의 집합 중, 다음 두 성질을 만족하는 것을 후보 키(Candidate Key)라고 한다.
  - 유일성(uniqueness) : 릴레이션에 있는 모든 튜플에 대해 유일하게 식별되어야 한다.
  - 최소성(minimality) : 유일성을 가진 키를 구성하는 속성(Attribute) 중 하나라도 제외하는 경우 유일성이 깨지는 것을 의미한다. 즉, 릴레이션의 모든 튜플을 유일하게 식별하는 데 꼭 필요한 속성들로만 구성되어야 한다.

제이지를 위해, 아래와 같은 학생들의 인적사항이 주어졌을 때, 후보 키의 최대 개수를 구하라.

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/images/posting/%EC%B9%B4%EC%B9%B4%EC%98%A4%202018%20%ED%9B%84%EB%B3%B4%ED%82%A41.png">

<br>

위의 예를 설명하면, 학생의 인적사항 릴레이션에서 모든 학생은 각자 유일한 학번을 가지고 있다. 따라서 학번은 릴 레이션의 후보 키가 될 수 있다. 그다음 이름에 대해서는 같은 이름(apeach)을 사용하는 학생이 있기 때문에, 이름 은 후보 키가 될 수 없다. 그러나, 만약 [이름, 전공]을 함께 사용한다면 릴레이션의 모든 튜플을 유일하게 식별 가능 하므로 후보 키가 될 수 있게 된다. 물론 [이름, 전공, 학년]을 함께 사용해도 릴레이션의 모든 튜플을 유일하게 식별 할 수 있지만, 최소성을 만족하지 못하기 때문에 후보 키가 될 수 없다. 따라서, 위의 학생 인적사항의 후보키는 학번, [이름, 전공] 두 개가 된다. <br>

릴레이션을 나타내는 문자열 배열 relation이 매개변수로 주어질 때, 이 릴레이션에서 후보 키의 개수를 return 하 도록 solution 함수를 완성하라. <br>

<br>

**제한사항**

- relation은 2차원 문자열 배열이다.
- relation의 컬럼(column)의 길이는 1 이상 8 이하이며, 각각의 컬럼은 릴레이션의 속성을 나타낸다.
- relation의 로우(row)의 길이는 1 이상 20 이하이며, 각각의 로우는 릴레이션의 튜플을 나타낸다.
- relation의 모든 문자열의 길이는 1 이상 8 이하이며, 알파벳 소문자와 숫자로만 이루어져 있다.
- relation의 모든 튜플은 유일하게 식별 가능하다.(즉, 중복되는 튜플은 없다.)

<br>

**입출력 예**

| relation                                                     | result |
| ------------------------------------------------------------ | ------ |
| [[100,ryan,music,2],[200,apeach,math,2],[300,tube,computer,3], [400,con,computer,4],[500,muzi,music,3],[600,apeach,music,2]] | 2      |

<br>

**입출력 예 설명**

입출력 예 #1 문제에 주어진 릴레이션과 같으며, 후보 키는 2개이다.

<br>

```python
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

```



<br>


# Kakao 2018

<br><br>

## 오픈채팅방

카카오톡 오픈채팅방에서는 친구가 아닌 사람들과 대화를 할 수 있는데, 본래 닉네임이 아닌 가상의 닉네임을 사용하 여 채팅방에 들어갈 수 있다. <br>

신입사원인 김크루는 카카오톡 오픈 채팅방을 개설한 사람을 위해, 다양한 사람들이 들어오고, 나가는 것을 지켜볼 수 있는 관리자창을 만들기로 했다. 채팅방에 누군가 들어오면 다음 메시지가 출력된다. <br>

[닉네임]님이 들어왔습니다. <br>

채팅방에서 누군가 나가면 다음 메시지가 출력된다. [닉네임]님이 나갔습니다. <br>

채팅방에서 닉네임을 변경하는 방법은 다음과 같이 두 가지이다. <br>

<br>

- 채팅방을 나간 후, 새로운 닉네임으로 다시 들어간다.

- 채팅방에서 닉네임을 변경한다.

<br>

닉네임을 변경할 때는 기존에 채팅방에 출력되어 있던 메시지의 닉네임도 전부 변경된다.  <br>

예를 들어, 채팅방에 Muzi와 Prodo라는 닉네임을 사용하는 사람이 순서대로 들어오면 채팅방에는 다음과 같이 메 시지가 출력된다. <br>

Muzi님이 들어왔습니다. Prodo님이 들어왔습니다. <br>

채팅방에 있던 사람이 나가면 채팅방에는 다음과 같이 메시지가 남는다. <br>

Muzi님이 들어왔습니다. Prodo님이 들어왔습니다. Muzi님이 나갔습니다.  <br>

Muzi가 나간후 다시 들어올 때, Prodo 라는 닉네임으로 들어올 경우 기존에 채팅방에 남아있던 Muzi도 Prodo로 다음과 같이 변경된다.  <br>

Prodo님이 들어왔습니다. Prodo님이 들어왔습니다. Prodo님이 나갔습니다. Prodo님이 들어왔습니다. 채팅방은 중복 닉네임을 허용하기 때문에, 현재 채팅방에는 Prodo라는 닉네임을 사용하는 사람이 두 명이 있다. 이 제, 채팅방에 두 번째로 들어왔던 Prodo가 Ryan으로 닉네임을 변경하면 채팅방 메시지는 다음과 같이 변경된다. Prodo님이 들어왔습니다. Ryan님이 들어왔습니다. Prodo님이 나갔습니다. Prodo님이 들어왔습니다. 채팅방에 들어오고 나가거나, 닉네임을 변경한 기록이 담긴 문자열 배열 record가 매개변수로 주어질 때, 모든 기록 이 처리된 후, 최종적으로 방을 개설한 사람이 보게 되는 메시지를 문자열 배열 형태로 return 하도록 solution 함 수를 완성하라.

  <br>

**제한사항** 

- record는 다음과 같은 문자열이 담긴 배열이며, 길이는 1 이상 100,000 이하이다.

- 다음은 record에 담긴 문자열에 대한 설명이다.

  - 모든 유저는 [유저 아이디]로 구분한다.

  - [유저 아이디] 사용자가 [닉네임]으로 채팅방에 입장 - Enter [유저 아이디][닉네임] (ex. Enter

    uid1234 Muzi)

  - [유저 아이디] 사용자가 채팅방에서 퇴장 - Leave [유저 아이디] (ex. Leave uid1234)

  - [유저 아이디] 사용자가 닉네임을 [닉네임]으로 변경 - Change [유저 아이디][닉네임] (ex. Change uid1234 Muzi)

  - 첫 단어는 Enter, Leave, Change 중 하나이다.

  - 각 단어는 공백으로 구분되어 있으며, 알파벳 대문자, 소문자, 숫자로만 이루어져있다.

  - 유저 아이디와 닉네임은 알파벳 대문자, 소문자를 구별한다.

  - 유저 아이디와 닉네임의 길이는 1 이상 10 이하이다.

  - 채팅방에서 나간 유저가 닉네임을 변경하는 등 잘못 된 입력은 주어지지 않는다.







  <br>  <br>

**입출력 예**

| record                                                       | result                                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Enter uid1234 Muzi, Enter uid4567 Prodo,Leave uid1234,Enter uid1234 Prodo,Change uid4567 Ryan] | [Prodo님이 들어왔습니다., Ryan님이 들어왔습 니다., Prodo님이 나갔습니다., Prodo님이 들어 왔습니다.] |

  <br>  <br>

**입출력 예 설명**

입출력 예 #1 문제의 설명과 같다.

<br><br>

```javascript
/*

record

[Enter uid1234 Muzi,
Enter uid4567 Prodo,
Leave uid1234,
Enter uid1234 Prodo,
Change uid4567 Ryan]


result

[Prodo님이 들어왔습니다.,
Ryan님이 들어왔습니다.,
Prodo님이 나갔습니다.,
Prodo님이 들어 왔습니다.]
*/


let solution = function (record) {

    //record를 하나씩 검사한다. 첫번째 단어가 Enter, Leave, Change 중 어떤 것이냐에 따라
    //처리해야 할 내용이 달라진다.
    //Enter, Change의 경우 아이디에 따른 닉네임을 맵에 저장한다.
    //기록이 모두 완료되면 반환할 문장을 구성하자.

    let myMap = new Map();


    for (let i = 0; i < record.length; i++) {
        let recordOne = [];
        recordOne = record[i].split(" ");


        if (recordOne[0] === "Enter") {
            myMap.set(recordOne[1], recordOne[2]);

        } else if (recordOne[0] === "Change") {
            myMap.set(recordOne[1], recordOne[2]);

        }
    }


    let results = [];

    for (let i = 0; i < record.length; i++) {
        let recordOne = [];
        recordOne = record[i].split(" ");

        if (recordOne[0] === "Enter") {
            let resultOne = myMap.get(recordOne[1]) + "님이 들어왔습니다.";
            results.push(resultOne);
        } else if (recordOne[0] === "Leave") {
            let resultOne = myMap.get(recordOne[1]) + "님이 나갔습니다.";
            results.push(resultOne);
        }

    }

    return results;


};

let recordInput = ["Enter uid1234 Muzi", "Enter uid4567 Prodo",
    "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"];

let answer = solution(recordInput);

for (let i = 0; i < answer.length; i++) {
    console.log(answer[i]);
}
```

<br><br><br>

## 실패율

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/ALGORITHM/Kakao%202018/%EC%8B%A4%ED%8C%A8%EC%9C%A81.png"> 

<br>

슈퍼 게임 개발자 오렐리는 큰 고민에 빠졌다. 그녀가 만든 프랜즈 오천성이 대성공을 거뒀지만, 요즘 신규 사용자의 수가 급감한 것이다. 원인은 신규 사용자와 기존 사용자 사이에 스테이지 차이가 너무 큰 것이 문제였다. <br>

이 문제를 어떻게 할까 고민 한 그녀는 동적으로 게임 시간을 늘려서 난이도를 조절하기로 했다. 역시 슈퍼 개발자라 대부분의 로직은 쉽게 구현했지만, 실패율을 구하는 부분에서 위기에 빠지고 말았다. 오렐리를 위해 실패율을 구하는 코드를 완성하라. <br>

- 실패율은 다음과 같이 정의한다.
  - 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

<br>

전체 스테이지의 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages가 매개변 수로 주어질 때, 실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return 하도록 solution 함수를 완성하라.

<br>

**제한사항**

- 스테이지의 개수 N은 `1` 이상 `500` 이하의 자연수이다.

- stages의 길이는 `1` 이상 `200,000` 이하이다.

- stages에는

  ```
  1
  ```

  이상

  ```
  N + 1
  ```

  이하의 자연수가 담겨있다.

  - 각 자연수는 사용자가 현재 도전 중인 스테이지의 번호를 나타낸다.
  - 단, `N + 1` 은 마지막 스테이지(N 번째 스테이지) 까지 클리어 한 사용자를 나타낸다.

- 만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
- 스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다.

<br>

**입출력 예**

| N    | stages                   | result      |
| ---- | ------------------------ | ----------- |
| 5    | [2, 1, 2, 6, 2, 4, 3, 3] | [3,4,2,1,5] |
| 4    | [4,4,4,4,4]              | [4,1,2,3]   |

<br>

**입출력 예 설명**

<br>

입출력 예 #1 <br>

1번 스테이지에는 총 8명의 사용자가 도전했으며, 이 중 1명의 사용자가 아직 클리어하지 못했다. 따 라서 1번 스테이지의 실패율은 다음과 같다.

- 1 번 스테이지 실패율 : 1/8

2번 스테이지에는 총 7명의 사용자가 도전했으며, 이 중 3명의 사용자가 아직 클리어하지 못했다. 따라서 2번 스테 이지의 실패율은 다음과 같다. 

- 2 번 스테이지 실패율 : 3/7

마찬가지로 나머지 스테이지의 실패율은 다음과 같다.

- 3 번 스테이지 실패율 : 2/4 
- 4번 스테이지 실패율 : 1/2 
- 5번 스테이지 실패율 : 0/1

각 스테이지의 번호를 실패율의 내림차순으로 정렬하면 다음과 같다.

- [3,4,2,1,5]

<br>

입출력 예 #2 <br>

모든 사용자가 마지막 스테이지에 있으므로 4번 스테이지의 실패율은 1이며 나머지 스테이지의 실패율은 0이다.

- [4,1,2,3]

<br>



```javascript
/*
N	stages	                    result
5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
4	[4,4,4,4,4]	                [4,1,2,3]


실패율은 다음과 같이 정의한다.
스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수


1)
일단 실패율을 기록하자. 만일 실패율이 1/8이라면 [1,8]로 저장하자.

2)
입력받은 실패율들을 바탕으로 통분을 통해서 크기를 비교하자.
만일 같은 실패율이라면 작은 숫자를 우선 배치하자.




 */

const getFailPro = function (N, stages, target) {

    let numerator = 0;
    let denominator = 0;

    for (let i = 0; i <= stages.length; i++) {

        if (target == stages[i]) {
            numerator++;
        }

        if (target <= stages[i]) {
            denominator++;
        }
    }

    return [numerator, denominator];

};


const getCDRArr = function (failArr) {

    let commonDeno = 1;
    let cdrArr = [];

    for (let i = 0; i < failArr.length; i++) {

        let temp = failArr[i];
        commonDeno *= temp[1];
    }

    for (i = 0; i < failArr.length; i++) {
        let temp = failArr[i];
        let numerator = temp[0];
        let denominator = temp[1];

        numerator *= (commonDeno / denominator);
        temp = [i + 1, numerator, commonDeno];
        cdrArr.push(temp);

    }

    return cdrArr;

};

const getSortedArr = function (cdrArr) {

    //분자만으로 비교해서 배열에 담자.
    //이후 같은 분자를 가진 경우를 조사해서 조정하자.

    let results = [];


    while (cdrArr.length > 0) {

        let arrIndex = -1;
        let maxIndex = -1;
        let maxValue = -1;

        for (let i = 0; i < cdrArr.length; i++) {
            if (cdrArr[i][1] >= maxValue) {
                arrIndex = i;
                maxIndex = cdrArr[i][0];
                maxValue = cdrArr[i][1];
            }

        }

        results.push([maxIndex, maxValue]);
        cdrArr.splice(arrIndex, 1);

    }


    for (let i = 0; i < results.length; i++) {
        for (let j = i + 1; j < results.length; j++) {
            if ((results[i][1] == results[j][1]) && (results[i][0] > results[j][0])) {
                let temp = results[i];
                results[i] = results[j];
                results[j] = temp;
            }
        }
    }

    let realResults = [];
    for (let i = 0; i < results.length; i++) {
        let temp = results[i][0];
        realResults.push(temp);
    }

    return realResults;


};


const solution = function (N, stages) {

    let failArr = [];
    for (let i = 1; i <= N; i++) {
        let temp = getFailPro(N, stages, i);
        failArr.push(temp);
    }

    let cdrArr = getCDRArr(failArr);
    let result = getSortedArr(cdrArr);

    return result;


};


//[ 3, 4, 2, 1, 5 ]
console.log(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]));

//[ 4, 1, 2, 3 ]
console.log(solution(4, [4, 4, 4, 4, 4]));


```

<br><br><br>

## 후보키 

프렌즈대학교 컴퓨터공학과 조교인 제이지는 네오 학과장님의 지시로, 학생들의 인적사항을 정리하는 업무를 담당 하게 되었다. <br>

그의 학부 시절 프로그래밍 경험을 되살려, 모든 인적사항을 데이터베이스에 넣기로 하였고, 이를 위해 정리를 하던 중에 후보키(Candidate Key)에 대한 고민이 필요하게 되었다. <br>

후보키에 대한 내용이 잘 기억나지 않던 제이지는, 정확한 내용을 파악하기 위해 데이터베이스 관련 서적을 확인하여 아래와 같은 내용을 확인하였다. <br>

- 관계 데이터베이스에서 릴레이션(Relation)의 튜플(Tuple)을 유일하게 식별할 수 있는 속성(Attribute) 또는 속성의 집합 중, 다음 두 성질을 만족하는 것을 후보 키(Candidate Key)라고 한다.
  - 유일성(uniqueness) : 릴레이션에 있는 모든 튜플에 대해 유일하게 식별되어야 한다.
  - 최소성(minimality) : 유일성을 가진 키를 구성하는 속성(Attribute) 중 하나라도 제외하는 경우 유일성이 깨지는 것을 의미한다. 즉, 릴레이션의 모든 튜플을 유일하게 식별하는 데 꼭 필요한 속성들로만 구성되어야 한다.

제이지를 위해, 아래와 같은 학생들의 인적사항이 주어졌을 때, 후보 키의 최대 개수를 구하라.

<br>

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/documents/VIVA%20BRUTE%20FORCE/ALGORITHM/Kakao%202018/%ED%9B%84%EB%B3%B4%ED%82%A41.png">

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

<br>

<br>

## 무지의 먹방 라이브






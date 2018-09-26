# Kakao 2018 실패율

<img src="https://raw.githubusercontent.com/ysjhmtb/blog_images/master/images/posting/%EC%B9%B4%EC%B9%B4%EC%98%A4%202018%20%EC%8B%A4%ED%8C%A8%EC%9C%A81.png">

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

<br><br>
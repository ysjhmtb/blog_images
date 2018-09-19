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









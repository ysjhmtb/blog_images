/*
N	stages	                    result
5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
4	[4,4,4,4,4]	                [4,1,2,3]


실패율은 다음과 같이 정의한다.
스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

var quotient = Math.floor(y/x);
var remainder = y % x;


일단 실패율을 기록하자. 이후 실패율과 숫자 크기라는 두 기준으로 정렬하자.
이를 위해서는 분수 계산의 결과를 반환하는 함수를 만들어야 한다.
입력받은 stages의 값들을 하나씩 검사하면서 실패율을 기록하자.



 */


let getProba = function (N, stages, target) {

    let targetQuan = 0;
    let denominator = 0;

    for (let i = 0; i < stages.length; i++) {

        if (target == stages[i]) {
            targetQuan++;
        }

        if (target <= stages[i]) {
            denominator++;
        }
    }

    let quotient = Math.floor(targetQuan / denominator);
    let remainder = targetQuan % denominator;

    return [quotient, remainder];


};

let recordFail = function (keyNum, quotient, remainder) {

    this.keyNum = keyNum;
    this.quotient = quotient;
    this.remainder = remainder;


};


const solution = function (N, stages) {

    for (let i = 1; i <= N; i++) {

        let temp = getProba(N, stages, i);
        let quotient = temp[0];
        let remainder = temp[1];
        console.log(quotient + " " + remainder);
    }



};

solution(5, [2, 1, 2, 6, 2, 4, 3, 3]);
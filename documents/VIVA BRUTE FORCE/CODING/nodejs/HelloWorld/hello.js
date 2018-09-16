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
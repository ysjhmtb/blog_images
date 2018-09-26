# Kakao 2018 오픈채팅방

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

<br>
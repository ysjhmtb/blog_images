/*

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



칼럼 하나씩 가능 여부 조사.
불가능한 칼럼들 중에서 묶어보기. 가능해진 그룹은 더 이상 확대하지 않기.

 */


const isRightKey = function (relation, arrToCheck, rowsCount) {

    keysSet = new Set();

    /*
        arrToCheck = [0]
        arrToCheck = [1,2]
     */

    for (let i = 0; i < relation.length; i++) {

        let key;

        for (let j = 0; j < arrToCheck.length; j++) {
            key += relation[i][arrToCheck[j]];
        }

        keysSet.add(key);

    }

    if (keysSet.size == rowsCount) {
        return true;
    } else {
        return false;
    }

};

const insertKey = function (keysSet, keysArrToInsert) {


    keysSet.add(String(keysArrToInsert));
    console.log(keysSet);

    return keysSet;
};


const hasKeys = function (keysSet, keysArrToCheck) {

    return keysSet.has(String(keysArrToCheck));
};


const solution = function (relation) {

    const columnsCount = relation[0].length;
    const rowsCount = relation.length;
    let keysSet = new Set();

    // 칼럼을 하나씩 키로 기능할 수 있는지 검사.
    for (let i = 0; i < columnsCount; i++) {
        let arrToCheck = [];
        arrToCheck.push(i);

        if (isRightKey(relation, arrToCheck, rowsCount)) {
            keysSet = insertKey(keysSet, arrToCheck);
        }
    }

    // 불가능한 칼럼들 중에서 묶어보기. 가능해진 그룹은 더 이상 확대하지 않기.
    for (let i = 0; i < columnsCount; i++) {

        let tempArr = []

        for (let j = i + 1; j < columnsCount; j++) {

            // 키로 기능할 수 있는 칼럼은 조사하지 않는다.
            if (hasKeys(keysSet, [i])) {
                continue;
            }


        }
    }


};


const relation =
    [["100", "ryan", "music", "2"],
        ["200", "apeach", "math", "2"],
        ["300", "tube", "computer", "3"],
        ["400", "con", "computer", "4"],
        ["500", "muzi", "music", "3"],
        ["600", "apeach", "music", "2"]];

solution(relation);


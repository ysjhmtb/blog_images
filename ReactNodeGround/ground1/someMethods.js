//
//
//
//
// split

const string = 'abc,def,ghi';
const strSplit = string.split(",");

for (let i of strSplit) {
    console.log(i);
}

/*
    abc
    def
    ghi
 */

//
//
//
//
// map

let array1 = [1, 4, 9, 16];
const map1 = array1.map(x => x * 2);
console.log(map1); // [ 2, 8, 18, 32 ]

let numbers = [1, 4, 9];
let roots = numbers.map(Math.sqrt);
console.log(numbers);   // [ 1, 4, 9 ]
console.log(roots);     // [ 1, 2, 3 ]

let kvArray = [{key: 1, value: 10}, {key: 2, value: 20}, {key: 3, value: 30}];
let reformattedArray = kvArray.map(function (obj) {
    let rObj = {};
    rObj[obj.key] = obj.value;
    return rObj;
});

console.log(kvArray);
console.log(reformattedArray);

/*
[ { key: 1, value: 10 },
  { key: 2, value: 20 },
  { key: 3, value: 30 } ]

[ { '1': 10 }, { '2': 20 }, { '3': 30 } ]

 */

let map = Array.prototype.map;
let a = map.call('Hello World', function (x) {
    return x.charCodeAt(0);
});
console.log(a); // [ 72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100 ]


console.log(['1', '2', '3'].map(parseInt)); // [ 1, NaN, NaN ] parseInt는 인자로 두개를 받을 수 있다.

function returnInt(element) {
    // 10진법으로
    return parseInt(element, 10);
}

console.log(['1', '2', '3'].map(returnInt)); // [ 1, 2, 3 ]


//
//
//
//
// join

a = ['바람', '비', '불'];
let myVar1 = a.join();
let myVar2 = a.join(', ');
console.log(myVar1);    // 바람,비,불
console.log(myVar2);    // 바람, 비, 불

//
//
//
//
// reduce
// https://bit.ly/2QrTPnn


// reduce vs map

let data = [1, 2, 3];
let initialValue = [];

let reducer = function (accumulator, value) {
    accumulator.push(value * 2);
    return accumulator;
};

let result = data.reduce(reducer, initialValue);
console.log(result);    // [ 2, 4, 6 ]

let result2 = data.map(x => x * 2);
console.log(result2);   // [ 2, 4, 6 ]


// reduce vs filter

data = [1, 2, 3, 4, 5, 6];
initialValue = [];

reducer = function (accumulator, value) {

    if (value % 2 != 0) {
        accumulator.push(value);
    }
    return accumulator;

};

let result1 = data.reduce(reducer, initialValue);
console.log(result1);   //  [ 1, 3, 5 ]

result2 = data.filter(x => x % 2 != 0);
console.log(result2);   //  [ 1, 3, 5 ]


// reduce vs filter + map

data = [1, 2, 3, 4, 5, 6];
initialValue = [];

reducer = function (accumulator, value) {
    if (value % 2 != 0)
        accumulator.push(value * 2);

    return accumulator;
};

result1 = data.reduce(reducer, initialValue);
console.log(result1);   //  [ 2, 6, 10 ]

result2 = data.filter(x => x % 2 != 0).map(x => x * 2);
console.log(result2);   //  [ 2, 6, 10 ]


// initial value 주의하기
data = ["vote1", "vote2", "vote1", "vote2", "vote2"];
reducer = (accumulator, value, index, array) => {
    if (accumulator[value]) {
        accumulator[value] = accumulator[value] + 1;
    } else {
        accumulator[value] = 1;
    }

    return accumulator;
};

const getVote = data.reduce(reducer, {});
console.log(getVote);   //  { vote1: 2, vote2: 3 }


// flatten

data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
const flatArrayReducer = (accumulator, value, index, array) => {
    return accumulator.concat(value);
};
const flattenedData = data.reduce(flatArrayReducer, []);
console.log(flattenedData); //  [ 1, 2, 3, 4, 5, 6, 7, 8, 9 ]


// flattenMap

const input = [
    {
        "title": "슈퍼맨",
        "year": "2005",
        "cast": ["장동건", "권상우", "이동욱", "차승원"]
    },
    {
        "title": "스타워즈",
        "year": "2013",
        "cast": ["차승원", "신해균", "장동건", "김수현"]
    },
    {
        "title": "고질라",
        "year": "1997",
        "cast": []
    }
];
const flatMapReducer = (accumulator, value, index, array) => {
    const key = "cast";
    if (value.hasOwnProperty(key) && Array.isArray(value[key])) {
        value[key].forEach(val => {
            if (accumulator.indexOf(val) === -1) {
                accumulator.push(val);
            }
        });
    }
    return accumulator;
};
const flattenCastArray = input.reduce(flatMapReducer, []);

console.log(flattenCastArray);
// ['장동건', '권상우', '이동욱', '차승원', '신해균', '김수현']

//
//
//
//
// trim

let str = "       Hello World!       ";
console.log(str.trim());






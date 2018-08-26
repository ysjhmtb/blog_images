# Node.js 교과서와 ES6



`Node.js 교과서 `에서 다음의 함수를 만났다. 아직 ES6에 익숙하지 못함을 절감했는데, 이번 기회로 몇 가지 내용을 정리하려고 한다.

```javascript
const parseCookies = (cookie = '') =>
    cookie
        .split(';')
        .map(v => v.split('='))
        .map(([k, ...vs]) => [k, vs.join('=')])
        .reduce((acc, [k, v]) => {
            acc[k.trim()] = decodeURIComponent(v);
            return acc;
        }, {});




const parseCookies = (cookie = '') =>
    cookie
        .split(';')
        .map(v => {
            console.log('v : ' + v);
            console.log('v.split(\'=\') : ' + v.split('='));
            return v.split('=');
        })
        .map(([k, ...vs]) => {
            console.log('k : ' + k);
            console.log('vs : ' + vs);
            console.log('vs.join(\'=\') : ' + vs.join('='));
            console.log('[k, vs.join(\'=\')] : ' + [k, vs.join('=')]);

            return [k, vs.join('=')];
        })
        .reduce((acc, [k, v]) => {

            console.log('acc : ' + acc);
            console.log('[k, v] : ' + [k, v]);
            console.log('k.trim() : ' + k.trim());

            acc[k.trim()] = decodeURIComponent(v);
            console.log('acc[k.trim()] : ' + acc[k.trim()])
            return acc;
        }, {});

/*
v : name=zerocho
v.split('=') : name,zerocho

v : year=1994
v.split('=') : year,1994

k : name
vs : zerocho
vs.join('=') : zerocho
[k, vs.join('=')] : name,zerocho

k : year
vs : 1994
vs.join('=') : 1994
[k, vs.join('=')] : year,1994

acc : [object Object]
[k, v] : name,zerocho
k.trim() : name
acc[k.trim()] : zerocho

acc : [object Object]
[k, v] : year,1994
k.trim() : year
acc[k.trim()] : 1994

{ name: 'zerocho', year: '1994' }
 */

console.log(parseCookies('name=zerocho;year=1994'));
//{ name: 'zerocho', year: '1994' }
```

   

## Default Parameters

[ES6 for beginners](https://codeburst.io/es6-tutorial-for-beginners-5f3c4e7960be) 의 설명처럼 디폴트 패러미터는 함수를 선언하면서 선언되는 매개변수로 함수를 호출하면서 변경될 수 있다. 지금 여기서는 `(cookie = '')` 로 작성되어 있다.

   

## 템플릿 문자열 



```javascript

const num3 = 1;
const num4 = 2;
const result2 = 3;
const string2 = `${num3} 더하기 ${num4} 는 '${result2}'`;
console.log(string2)    // 1 더하기 2 는 '3'
```

   

## 객체 리터럴



```javascript
let sayNode = function () {
    console.log('Node');
};

let es = 'ES';

const newObject = {
    sayJS(){
        console.log('JS');
    },
    sayNode,
    [es + 6]: 'Fantastic',
};

newObject.sayNode();            // Node
newObject.sayJS();              // Js
console.log(newObject.ES6);     // Fantastic
```



   

## 화살표 함수 



```javascript

var relationship1 = {
    name: 'zero',
    friends: ['nero', 'hero', 'xero'],
    logFriends: function () {
        var that = this;

        /*
        relationship1을 가리키는 this를 that에 저장.
        각자 다른 함수 스코프의 this를 가지므로 that이라는 변수를 사용해서 relationship1에 간접적으로 접근.
         */
        this.friends.forEach(function (friend) {
            console.log(friend);
        });
    },
};
relationship1.logFriends();
/*
nero
hero
xero
*/


const relationship2 = {
    name: 'zero',
    friends: ['nero', 'hero', 'xero'],
    logFriends(){

        /*

        바깥 스코프인 logFriends() this를 그대로 사용할 수 있다.
        상위 스코프의 this를 그대로 물려받은 것이다.
         */

        this.friends.forEach(friend => {
            console.log(this.name, friend);
        });
    },
};
relationship2.logFriends();
/*
zero nero
zero hero
zero xero
*/
```



## 비구조화 할당 



```javascript


const candyMachine = {
    status: {
        name: 'node',
        count: 5,
    },
    getCandy(){
        this.status.count--;
        return this.status.count;
    }
};


//candyMachine 객체 안의 속성을 찾아서 변수와 매칭해 준다.
const { getCandy, status: { count } } = candyMachine;

//{ getCandy: [Function: getCandy], status: { count: 5 } }
console.log({ getCandy, status: { count } });



//배열의 비구조화
const array = ['node.js',{},10,true];
const [node, obj, , bool] = array;

//[ 'node.js', {}, <1 empty item>, true ]
console.log([node, obj, , bool]);


```



## 프로미스



```javascript

const condition = true;

const promise = new Promise((resolve, reject) => {
   if(condition){
       resolve('성공');
   } else{
       reject('실패');
   }
});

promise
    .then((message) => {
        console.log(message);
    })
    .catch((error) => {
        console.error(error);
    });
// 성공



```





## [자바스크립트에서 당장 사용해야 할 5가지의 배열 메소드들 (Array)](http://blog.kazikai.net/?p=16)

```javascript
//배열에서 특정값
var isExist = (array.indexOf(“특정값”)!== -1 )


//filter
var arr = [    
  {"name":"apple", "count": 2},    
  {"name":"orange", "count": 5},    
  {"name":"pear", "count": 3},    
  {"name":"orange", "count": 16}
];    
var newArr = arr.filter(function(item){    
  return item.name === "orange";
});  
console.log("Filter results:",newArr);


//forEach
var array = [1,2,3,4,5];
array.forEach( function( v, i ){
  if( v === 3 ){
    console.log( v + ":" + i); // 3:2 가 나온다.
  }
});


//map
var a = [1,2,3,4,5];
// undefined
var b = a.forEach( function(v, i){ console.log(v); return v+1;}});
// [2,3,4,5,6]
var c = a.map( function(v, i){ console.log(v); return v+1;});


//reduce
var a= ["a","b","c","d","e","a","b","a","c","c","c"];
var b = a.reduce(function(x,y){
  console.log("x:", x);
  console.log("y:", y);
  x[y] = ++x[y]|| 1;
  return x;
},{});
console.log(b);
```



## for of loop



```javascript
let arr = [2,3,4,1];
for (let value of arr) {
    console.log(value);
}   // 2 3 4 1


let string = "Javascript";
for (let char of string) {
 console.log(char);
}
```





## Spread attributes



```javascript
let SumElements = (...arr) => {
 console.log(arr); // [10, 20, 40, 60, 90]
let sum = 0;
 for (let element of arr) {
  sum += element;
 }
 console.log(sum); // 220. 
}
SumElements(10, 20, 40, 60, 90); // Note we are not passing array here. Instead we are passing the elements as arguments. 



Math.max(10, 20, 60, 100, 50, 200); // returns 200.

let arr = [10, 20, 60];
Math.max(arr); // Shows error. Doesn't accept an array.

let arr = [10, 20, 60];
Math.max(...arr); // 60 
```



## Sets



```javascript

var sets = new Set();
sets.add('a');
sets.add('b');
sets.add('a'); // We are adding duplicate value.
for (let element of sets) {
    console.log(element);
} //a b



var sets = New Set([1,5,6,8,9]);
sets.size; // returns 5. Size of the size.
sets.has(1); // returns true. 
sets.has(10); // returns false.
```





## Static methods



```javascript
class Example {
 static Callme() {
 console.log("Static method");
 }
}
Example.Callme();
```





## Getters and Setters



```javascript

class People {
    constructor(name) {
        this.name = name;
    }
    getName() {
        return this.name;
    }
    setName(name) {
        this.name = name;
    }
}

let person = new People("Jon Snow");
console.log(person.getName());
person.setName("Dany");
console.log(person.getName());
```


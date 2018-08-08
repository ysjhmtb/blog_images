// 2-3. 객체 리터럴의 변화
const obj = {
    a: 1,
    b: 2,
}


var sayNode = function () {
    console.log('Node');
};
var es = 'ES';
var oldObject = {
    sayJS: function () {
        console.log('JS');
    },
    sayNode: sayNode,

};

oldObject[es + 6] = 'Fantastic';

oldObject.sayNode();
oldObject.sayJS();
console.log(oldObject.ES6)


console.log('----- ----- -----');

//ES6
const newObject = {
    sayJS() {
        console.log('JS');
    },
    sayNode,
    [es + 6]: 'Fantastic',
}

newObject.sayNode();    // Node
newObject.sayJS();      // JS
console.log(newObject.ES6); //Fantastic



// 2-4. 화살표 함수
const add2 = (x, y) => {
    return x + y;
};

const add3 = (x, y) => (x + y);
const add4 = (x, y) => x + y;


const relationship2 = {
    name: 'zero',
    friends: ['nero','hero','xero'],
    logFriends(){
        this.friends.forEach(friend => {
            console.log(this.name, friend);
        });
    },
};
relationship2.logFriends();







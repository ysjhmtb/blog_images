// 2-5. 비구조화 할당(destructuring)

const candyMachine = {
    status: {
        name: 'node',
        count: 5,
    },

    getCandy() {
        this.status.count--;
        return this.status.count;
    }
};


const {status, getCandy} = candyMachine;


console.log(status);    //{ name: 'node', count: 5 }
console.log(getCandy);  //[Function: getCandy]

/*
candyMachine.getCandy() // 4
getCandy()              // undefined. 왜냐하면 this를 찾을 수가 없다.

 */

console.log(candyMachine.getCandy());       //4
console.log(getCandy.call(candyMachine));   //3


const array = ['nodejs', {}, 10, true];


const [node, obj, , bool] = array;


console.log(obj);   //{}








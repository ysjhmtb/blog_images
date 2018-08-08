// 2-6. rest 문법과 Q&A

const array = ['nodejs', {}, 10, true];
const [node, obj, ...bool] = array;

console.log(bool);  //[ 10, true ]


const m = (x, y) => console.log(x, y);
m(5, 6);


const n = (x, ...y) => console.log(x, y);
n(6, 7, 8);   // 6 [ 7, 8 ]


const p = (...rest) => console.log(rest);
p(5, 6, 7, 8, 9);


const x = {a:1, b:2};
let y = x;
x.a = 3;
console.log(y.a); //3







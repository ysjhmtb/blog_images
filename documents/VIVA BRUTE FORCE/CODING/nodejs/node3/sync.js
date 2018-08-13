
const fs = require('fs');

console.log('시작');


// fs 메서드들은 뒤에 Sync를 붙이면 동기식으로 작동한다.
let data = fs.readFileSync('./readme.txt');
console.log('1번', data.toString());

data = fs.readFileSync('./readme.txt');
console.log('2번', data.toString());

data = fs.readFileSync('./readme.txt');
console.log('3번', data.toString());

console.log('끝');

// 이 방법이 더 많이 사용될 것 같지만, callback hell이 더 많이 사용된다.
// 왜냐하면 지금 사용한 방법은 blocking이다. 따라서 한 가지 작업에 오랜 시간이 소요되면,
// 지금 하는 작업을 처리하느라 다른 일을 처리할 수 없게 된다.


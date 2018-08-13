
const path = require('path');

console.log(path.sep);
console.log(path.delimiter);


console.log(path.dirname(__filename));
console.log(path.extname(__filename));
console.log(path.basename(__filename));
console.log(path.parse(__filename));

console.log(path.isAbsolute('/'));

//path.join     절대 경로 무시하고 합침
//path.resolve  절대 경로 고려하고 합침
console.log('join');
console.log(path.join(__dirname,'..','..','/CODING'));
console.log('resolve');
console.log(path.resolve(__dirname,'..','..','/CODING'));


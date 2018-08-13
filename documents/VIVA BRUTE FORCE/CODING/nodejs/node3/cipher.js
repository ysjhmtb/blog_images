
const crypto = require('crypto');



const cipher = crypto.createCipher('aes-256-cbc','열쇠');

// 이것은비밀번호 >> utf8 >> base64
let result = cipher.update('이것은비밀번호','utf8','base64');
result += cipher.final('base64');

console.log('암호', result);


//똑같은 열쇠를 사용해서 복호화 해야 한다.
const decipher = crypto.createDecipher('aes-256-cbc','열쇠');

//암호문 >> base64 >> utf8
let result2 = decipher.update(result,'base64', 'utf8');
result2 += decipher.final('utf8');

console.log('평문', result2);
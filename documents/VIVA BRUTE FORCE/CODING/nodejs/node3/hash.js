
const crypto = require('crypto');

//단방향 암호화
console.log(crypto.createHash('sha512').update('비밀번호').digest('base64'));






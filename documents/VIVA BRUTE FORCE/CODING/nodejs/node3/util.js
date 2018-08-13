const util = require('util');
const crypto = require('crypto');

const dontuseme = util.deprecate((x, y) => {
    console.log(x + y);
}, '이 함수는 2018년 12월 부로 지원하지 않습니다.');

dontuseme(1, 2);


/*
primise를 지원하지 않는
(error, data) => {} 꼴의 콜백은
util.promisify로 프라미스로 만들 수 있다.
 */

const randomBytesPromise = util.promisify(crypto.randomBytes);
const pbkdf2Promise = util.promisify(crypto.pbkdf2);



crypto.randomBytes(64,(err,buf) => {
    const salt = buf.toString('base64');
    //랜덤 바이트이기 때문에 값이 매번 달라진다.
    console.log('salt', salt);

    /*
    인자 : 비밀번호 / salt / 반복 횟수 / 출력 바이트 / 해시 알고리즘


    기존 문자열에 salt라고 불리는 문자열을 붙인 후 해시 알고리즘을 반복해서 적용하는 것.
    sha512로 변환된 결과값을 다시 sha512로 변환하는 과정을 10만번 반복.
     */
    crypto.pbkdf2('해시충돌해결하자', salt, 100000, 64, 'sha512', (err, key) => {
        console.log('password', key.toString('base64'));
    });
});



randomBytesPromise(64)
    .then((buf) => {
        const salt = buf.toString('base64');
        return pbkdf2Promise('이것은비밀번호이다', salt, 651395, 64, 'sha512');

    })
    .then((key) => {
        console.log('password', key.toString('base64'));
    })
    .catch((err) => {
       console.error(err);
    });


(async () => {
    const buf = await randomBytesPromise(64);
    const salt = buf.toString('base64');
    const key = pbkdf2Promise('비밀번호', salt, 651395, 64, 'sha512');

    console.log('password', key.toString('base64'));
})();
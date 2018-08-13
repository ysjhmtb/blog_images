// setInterval(() => {
//    console.log('시작');
//    try{
//        throw new Error('서버를 고장내주마');
//    }catch (error) {
//        //서버가 죽지 않고 계속 운영되게 해준다. 권장은 아니다.
//        console.error(error);
//    }
// }, 1000);
//
//
//
//
// const fs = require('fs');
// //로그 남기기
// setInterval( () => {
//    fs.unlink('./asdfasd.js', (err) => {
//
//        if(err){
//            console.log('시작');
//            console.log(err);
//            console.log('끝');
//        }
//    });
// }, 1000);


process.on('uncaughtException', (err) => {
   console.error('예기치 못한 에러', err);
});

setInterval(() => {
   throw new Error('서버를 고장내주마');
}, 1000);

setTimeout(() => {
   console.log('실행됩니다');
}, 2000);



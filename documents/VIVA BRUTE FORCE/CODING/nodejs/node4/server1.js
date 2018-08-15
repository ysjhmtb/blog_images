const http = require('http');
const fs = require('fs');

/*
http 기본 포트(80)
https (443)
기본 포트는 생략 가능

1024 아래 포트는 다른 프로그램이 사용 중일 확률이 높다.
 */


const server = http.createServer((reg, res) => {

    console.log('서버 실행');
    fs.readFile('./server2.html', (err,data) => {
        if(err){
            throw err;
        }

        res.end(data);
    });


}).listen(8081);

server.on('listening', () => {
   console.log('8081번 포트에서 서버 대기 중입니다.');
});

server.on('error', (error) => {
   console.error(error);
});

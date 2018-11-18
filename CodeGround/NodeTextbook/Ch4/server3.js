const http = require('http');

// CREDIT: 유인동님이 알려주신 함수
// https://github.com/ZeroCho/nodejs-book/blob/master/ch4/4.2/server3.js
const parseCookies = (cookie = '') =>
  cookie
    .split(';')
    .map(v => v.split('='))
    .reduce((acc, [k, v]) => {
      acc[k.trim()] = decodeURIComponent(v);
      return acc;
    }, {});


http.createServer((req,res)=>{
    
    const cookies = parseCookies(req.headers.cookie);
    console.log(cookies);   // { mycookie: 'test' }
    console.dir(req.headers.cookie);    // 'mycookie=test'
    console.log(req.url.cookies);   // undefined
    res.writeHead(200,{'Set-Cookie':'mycookie=test'});
    res.end('Hello Cookie');
}).listen(8082, ()=>{
    console.log('8082번 포트에서 서버 대기 중입니다.');
});


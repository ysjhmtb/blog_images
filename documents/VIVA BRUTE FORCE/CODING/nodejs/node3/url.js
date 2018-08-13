


const url = require('url');

const URL = url.URL;
const myURL = new URL('http://www.kyobobook.co.kr/product/detailViewKor.laf?ejkGb=KOR&mallGb=KOR&barcode=9791160505221&orderClick=LEA&Kc=');

console.log('new URL() : ', myURL);
console.log('url.format() : ', url.format(myURL));
console.log('-----------------------------------');


const parsedUrl = url.parse('http://www.kyobobook.co.kr/product/detailViewKor.laf?ejkGb=KOR&mallGb=KOR&barcode=9791160505221&orderClick=LEA&Kc=');
console.log('url.parse() : ', parsedUrl);



/*
기존 방식(url.parse)은 호스트가 없을 때도 사용할 수 있다.
WHATWG 방식(url.URL)은 search 처리가 편리하다.
 */







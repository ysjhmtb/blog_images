

const url = require('url');
const querystring = require('querystring');

const parsedUrl = url.parse('http://www.gilbut.co.kr/book/bookView.aspx?bookcode=BN002045&page=1&sernewbook=Y&orderby=pdate&TF=T');
const query = querystring.parse(parsedUrl.query);

console.log('querystring.parse() : ', query);
console.log('querystring.stringfy() : ', querystring.stringify(query));



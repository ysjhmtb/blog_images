
const fs = require('fs');
const zlib = require('zlib');

/*
기존에 사용하던 방법

const readStream = fs.createReadStream('readme4.txt');
const writeStream = fs.createWriteStream('writeme3.txt');
readStream.pipe(writeStream);

*/

//새로운 방법
// const readStream = fs.copyFile('./readme4.txt', './writeme4.txt', (err) => {
//    console.log(err);
// });


//파일 압축해서 쓰자
const zlibStream = zlib.createGzip();
const readStream = fs.createReadStream('readme4.txt');
const writeStream = fs.createWriteStream('writeme3.txt');
readStream.pipe(zlibStream).pipe(writeStream);
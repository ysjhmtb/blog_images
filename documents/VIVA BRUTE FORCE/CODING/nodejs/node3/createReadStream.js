
const fs = require('fs');

//16바이트씩 읽자.
const readStream = fs.createReadStream('./readme3.txt', { highWaterMark: 16});
const data = [];

readStream.on('data', (chunk) => {

    data.push(chunk);
    console.log('data', chunk, chunk.length);
});

readStream.on('end', () => {
   console.log('end', Buffer.concat(data).toString());
});

readStream.on('error', (err) => {
    console.log('error', err);

});
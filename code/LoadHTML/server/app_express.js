// https://infodbbase.tistory.com/37

const express = require('express');
const app = express();
const fs = require('fs');

app.listen(3303, function () {
    console.log('server start');
});

app.get('/', function (req, res) {
    fs.readFile('../client/index.html', function (error, data) {
        if (error) {
            console.log(error);
        } else {
            res.writeHead(200, { 'Content-Type': 'text/html' });
            res.end(data);
        }
    });
});
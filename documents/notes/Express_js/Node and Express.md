<br>

# Node and Express

<br>

## MySQL in Mac

```bash
# https://zzsza.github.io/development/2018/01/18/Install-MySQL-mac/

$ brew install mysql
$ mysql.server start
$ mysql_secure_installation # root 비밀번호 설정
$ mysql -u root -p # log in
$ status # setting
$ brew services start mysql
$ mysql --host=<HOST IP> -u root --password="PASSWORD"

# https://tableplus.io/blog/2018/10/how-to-start-stop-restart-mysql-server.html

```

<br>

## MySQL Driver and Connection

```bash
# https://blog.teamtreehouse.com/install-node-js-npm-mac

$ brew install node
$ node -v
$ npm -v

$ brew update
$ brew upgrade node 

$ brew uninstall node


# https://www.w3schools.com/nodejs/nodejs_mysql.asp

$ npm install mysql

```

<br>

```bash
# https://stackoverflow.com/questions/44946270/er-not-supported-auth-mode-mysql-server
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password'

# https://to-dy.tistory.com/58
mysql> ALTER user 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY '변경할비밀번호';

```

<br>

```javascript
// https://www.w3schools.com/nodejs/nodejs_mysql.asp

/*
On Windows      Shift + Alt + F
On Mac          Shift + Option + F
On Ubuntu       Ctrl + Shift + I

*/
const mysql = require('mysql')
const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234"
});

con.connect(function(err){
    if(err) throw err;
    console.log("Connected");
});
```

<br>

## Creating a Database

```javascript

// https://www.w3schools.com/nodejs/nodejs_mysql_create_db.asp

const mysql = require('mysql')

const con = mysql.createConnection({
    host:"localhost",
    user:"root",
    password:"kaon1234"
});

con.connect(function(err){
    if(err) throw err;
    console.log("Connected");
    con.query("CREATE DATABASE mydb", function(err, result){
        if(err) throw err;
        console.log("Database created");
    });
});
```

<br>

## Creating a Table

```javascript


// https://www.w3schools.com/nodejs/nodejs_mysql_create_table.asp

const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function (err) {
    if (err) throw err;
    console.log("Connected");
    // const sql = "CREATE TABLE customers (name VARCHAR(255), address VARCHAR(255))";
    const sql = "ALTER TABLE customers ADD COLUMN id INT AUTO_INCREMENT PRIMARY KEY";
    con.query(sql, function (err, result) {
        if (err) throw err;
        console.log("Table created");
    });
});
```

<br>

## Insert Into Table

```javascript
// https://www.w3schools.com/nodejs/nodejs_mysql_insert.asp

const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function (err) {
    if (err) throw err;
    console.log("Connected");
    const sql = "INSERT INTO customers (name, address) VALUES ('Company Inc','Highway 37')";
    con.query(sql,function(err,result){
        if(err) throw err;
        console.log("1 record inserted");
    });
});


```

<br>

## Insert Multiple Records

```javascript

const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function (err) {
    if (err) throw err;
    console.log("Connected");

    const sql = "INSERT INTO customers (name, address) VALUES ?";
    const values = [
        ['John', 'Highway 71'],
        ['Peter', 'Lowstreet 4'],
        ['Amy', 'Apple st 652'],
        ['Hannah', 'Mountain 21'],
        ['Michael', 'Valley 345'],
        ['Sandy', 'Ocean blvd 2'],
        ['Betty', 'Green Grass 1'],
        ['Richard', 'Sky st 331'],
        ['Susan', 'One way 98'],
        ['Vicky', 'Yellow Garden 2'],
        ['Ben', 'Park Lane 38'],
        ['William', 'Central st 954'],
        ['Chuck', 'Main Road 989'],
        ['Viola', 'Sideway 1633']
    ];

    con.query(sql, [values], function (err, result) {
        if (err) throw err;
        console.log("Number of records inserted: " + result.affectedRows);
    });
});
```

<br>

## Selecting From a Table

```javascript
const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function(err){
    if(err) throw err;

    con.query("SELECT * FROM customers", function(err, result, fields){
        if(err) throw err;
        console.log(result);
    });
});


```

<br>

## Selecting Columns

```javascript
const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function(err){
    if(err) throw err;
    con.query("SELECT name, address FROM customers", function(err, result, fields){
        if(err) throw err;
        console.log(result);
    });
});
```

<br>

## Select With a Filter

```javascript
const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function (err) {
    if (err) throw err;

    con.query("SELECT * FROM customers WHERE address = 'Park Lane 38'", function (err, result) {
        if (err) throw err;
        console.log(result);
    });

});
```

<br>

## Wildcard Characters

```javascript
const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function(err){
    if(err) throw err;
    con.query("SELECT * FROM customers WHERE address LIKE 's%'", function(err, result){
        if(err) throw err;
        console.log(result);
    })
})
```

<br>

## Escaping Query Values

```javascript
var adr = 'Mountain 21';
var sql = 'SELECT * FROM customers WHERE address = ' + mysql.escape(adr);
con.query(sql, function (err, result) {
  if (err) throw err;
  console.log(result);
});
```

```javascript
var adr = 'Mountain 21';
var sql = 'SELECT * FROM customers WHERE address = ?';
con.query(sql, [adr], function (err, result) {
  if (err) throw err;
  console.log(result);
});
```

```javascript
var name = 'Amy';
var adr = 'Mountain 21';
var sql = 'SELECT * FROM customers WHERE name = ? OR address = ?';
con.query(sql, [name, adr], function (err, result) {
  if (err) throw err;
  console.log(result);
});
```

<br>

## Sort the Result

```javascript
const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function (err) {
    if (err) throw err;

    con.query("SELECT * FROM customers ORDER BY name", function (err, result) {
        if (err) throw (err);
        console.log(result);
    });
});
```

<br>

## ORDER BY DESC

```javascript
const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function (err) {
    if (err) throw err;

    con.query("SELECT * FROM customers ORDER BY name DESC", function (err, result) {
        if (err) throw err;
        console.log(result);
    });
});
```

<br>

## Delete Record

```javascript
const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function(err){
    if(err) throw err;
    const sql = "DELETE FROM customers WHERE address = 'Mountain 21'";
    con.query(sql, function(err, result){
        if(err) throw err;
        console.log("Number of records deleted: " + result.affectedRows);
    });
});
```

<br>

## Delete a Table

```javascript
const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function(err){
    if(err) throw err;
    const sql = "DROP TABLE customers";
    con.query(sql, function(err, result){
        if(err) throw err;
        console.log("Table deleted");
    });
});


```

<br>

## Drop Only if Exist

```javascript
const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function(err){
    if(err) throw err;
    const sql = "DROP TABLE IF EXISTS customers";
    con.query(sql, function(err, result){
        if(err) throw err;
        console.log("Table deleted");
        console.log(result);
    });
});


```

<br>

## Update Table

```javascript

const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function (err) {
    if (err) throw err;
    const sql = "UPDATE customers SET address = 'Canyon 123' WHERE address = 'Valley 345'";
    con.query(sql, function (err, result) {
        if (err) throw err;
        console.log(result.affectedRows + "record(s) updated");
    });
})
```

<br>

## Limit the Result

```javascript

const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function (err) {
    if (err) throw err;
    const sql = "SELECT * FROM customers LIMIT 5";
  // sql = "SELECT * FROM customers LIMIT 5 OFFSET 2";
  // sql = "SELECT * FROM customers LIMIT 2, 5";
    con.query(sql, function (err, result) {
        if (err) throw err;
        console.log(result);
    });
});
```

<br>

## Join

```javascript
const mysql = require('mysql');

const con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "kaon1234",
    database: "mydb"
});

con.connect(function(err){
    if(err) throw err;
    const sql = "SELECT users.name AS user, products.name AS favorite FROM users JOIN products ON users.favorite_product = products.id";
    con.query(sql, function(err, result){
        if(err) throw err;
        console.log(result);
    });
});
```

<br>

## [Express.js 시작하기](<http://webframeworks.kr/getstarted/expressjs/>)

```bash
#  익스프레스 설치
$ npm install express -g
$ npm install -g express-generator

# my-app 폴더가 생성되고 익스프레스 모듈과 함께 서버 구동에 필요한 각종 파일들이 폴더 하위에 자동으로 생성
$ express my-app

# 필요한 모듈 설치: NPM은 프로젝트 폴더의 package.json 파일을 열고 dependencies 값을 이용해 의존성 모듈을 다운로드하게 됩니다. 다운로드된 파일들은 node_modules 폴더에 저장됩니다.
$ npm install

# 프로그램 구동. 익스프레스는 별도 설정이 없다면 기본적으로 3000번 포트를 사용합니다. 웹 브라우져를 열고 http://localhost:3000으로 접속합니다.
$ npm start


```

<br><br>

```javascript
const express = require('express');
const cors = require('cors');
const userJson = require('./user');
const locationJson = require('./location');

const API_PORT = process.env.PORT || 3002;
const app = express();
app.use(cors());
const router = express.Router();


// gets userData from JSON

router.get("/getUserData", (req, res) => {
    return res.json(userJson);
});

// gets locationData from JSON

router.get("/getLocationData", (req, res) => {
    return res.json(locationJson);
});

// append /api for our http requests
app.use("/api", router);

// launch our backend into a port
app.listen(API_PORT, () => console.log(`LISTENING ON PORT ${API_PORT}`));
```

<br>

<br>

## [Node.js(Express)와 MySQL 연동](<https://poiemaweb.com/nodejs-mysql>)

```bash
$ mkdir express-mysql
$ cd express-mysql
$ npm init --yes
$ npm install express mysql --save --save-exact
```

<br>

```json
// package.json

{
  "name": "express-mysql",
  "version": "1.0.0",
  "description": "",
  "main": "index.js",
  "scripts": {
    "start": "node index"
  },
  "dependencies": {
    "express": "4.17.1",
    "mysql": "2.17.1"
  }
}
```

<br>

```javascript
// 다음은 루트 디렉터리에 index.js를 생성한다.
// index.js
console.log('Hello world')
```

<br>

```bash
# 애플리케이션을 실행하여 콘솔에 ‘Hello world’가 출력되는 것을 확인한다.
$ npm start
```

<br>

```sql
CREATE DATABASE my_db;

USE my_db;

CREATE TABLE Persons
(
id int,
name varchar(255),
age int
);

INSERT INTO Persons (id, name, age)
VALUES (1, 'John Doe', 20);

SELECT * FROM Persons;
```

<br>

```javascript
// index.js를 아래와 같이 변경한다.

var mysql      = require('mysql');
var connection = mysql.createConnection({
  host     : 'localhost',
  user     : '< MySQL username >',
  password : '< MySQL password >',
  port     : < port >,
  database : 'my_db'
});

connection.connect();

connection.query('SELECT * from Persons', function(err, rows, fields) {
  if (!err)
    console.log('The solution is: ', rows);
  else
    console.log('Error while performing Query.', err);
});

connection.end();
```

<br>

```javascript
// index.js를 아래와 같이 변경한다.

var express    = require('express');
var mysql      = require('mysql');
var dbconfig   = require('./config/database.js');
var connection = mysql.createConnection(dbconfig);

var app = express();

// configuration ===============================================================
app.set('port', process.env.PORT || 3000);

app.get('/', function(req, res){
  res.send('Root');
});

app.get('/persons', function(req, res){

  connection.query('SELECT * from Persons', function(err, rows) {
    if(err) throw err;

    console.log('The solution is: ', rows);
    res.send(rows);
  });
});

app.listen(app.get('port'), function () {
  console.log('Express server listening on port ' + app.get('port'));
});
```

<br>

```javascript
// config/database.js
module.exports = {
  host     : 'localhost',
  user     : '< MySQL username >',
  password : '< MySQL password >',
  port     : < port >,
  database : 'my_db'
};
```

<br>

```
http://localhost:3000/persons
```


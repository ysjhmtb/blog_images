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
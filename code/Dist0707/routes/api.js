const express = require('express');
const router = express.Router();
const bodyParser = require('body-parser');
const multer = require('multer');
const excelToJson = require('convert-excel-to-json');
const fs = require('fs');
const UnderlyingAsset = require('../models/underlyingAsset');


const preprocessingData = (data) => {
    /*
    {"FRED Graph":[
        {"Date":"2014-06-29T15:00:00.000Z","Price":1960.23},
        {"Date":"2014-06-30T15:00:00.000Z","Price":1973.32},
    */

    // console.log(data['FRED Graph'][1]['Price']);

    let result = {};

    for (let i = 0; i < data['FRED Graph'].length; i++) {

        const key = JSON.stringify(data['FRED Graph'][i]['Date']).substring(1, 11);
        let value = JSON.stringify(data['FRED Graph'][i]['Price']).substring(0, 7);
        value = parseFloat(value);

        if (isNaN(value)) {
            continue;
        }

        result[key] = value;

    }

    result = JSON.stringify(result);

    const fileAndMongo = () => {

        const makingJson = () => {
            return new Promise((resolve, reject) => {
                fs.writeFile("./uploads/underlyingAsset.json", result, (err) => {
                    if (err) {
                        console.log(err);
                        return;
                    }
                    console.log("file has been created");
                    resolve();

                });
                
            });
        }

        makingJson().then(() => {
            console.log("Read json file and insert data to MongoDB");

            // Read json file and insert data to MongoDB

            let rawdata = fs.readFileSync("./uploads/underlyingAsset.json");
            let jsondata = [];
            
            jsondata.push(JSON.parse(rawdata));

            // https://stackoverflow.com/questions/38824349/how-to-convert-an-object-to-an-array-of-key-value-pairs-in-javascript

            let dataArr = Object.keys(jsondata[0]).map((key) => {
                return [key, jsondata[0][key]];
            });

            console.log(dataArr);
            
            // still not working
            UnderlyingAsset.collection.insertMany(jsondata, (err, docs) => {
                if (err) {
                    return console.error(err);
                } else {
                    console.log("Multiple documents inserted to Collection");
                }
            });
        });

    };

    fileAndMongo();

};

const storage = multer.diskStorage({ //multers disk storage settings
    destination: function (req, file, cb) {
        cb(null, './uploads/')
    },
    filename: function (req, file, cb) {
        const datetimestamp = Date.now();
        cb(null, file.fieldname + '-' + datetimestamp + '.' + file.originalname.split('.')[file.originalname.split('.').length - 1])
    }
});

const upload = multer({ //multer settings
    storage: storage,
    fileFilter: function (req, file, callback) { // file filter
        if (['xls', 'xlsx'].indexOf(file.originalname.split('.')[file.originalname.split('.').length - 1]) === -1) {
            return callback(new Error('Wrong extension type'));
        }
        callback(null, true);
    }
}).single('file');


router.post('/upload', (req, res, next) => {

    console.log('hello /api/upload');

    upload(req, res, function (err) {
        if (err) {
            res.json({ error_code: 1, err_desc: err });
            return;
        }

        /** Multer gives us file info in req.file object */
        if (!req.file) {
            res.json({ error_code: 1, err_desc: "No file passed" });
            return;
        }

        const result = excelToJson({
            sourceFile: req.file.path,
            columnToKey: {
                A: 'Date',
                B: 'Price'
            }
        });

        preprocessingData(result);
        res.redirect('/api/');
    });
});

router.get('/', (req, res, next) => {
    // res.sendFile(path.join(__dirname,'../../views','index.ejs'));
    // res.sendFile(__dirname + "../views/index.ejs");
    res.sendFile('/views/index.html', { 'root': '../Dist0707/' });
    console.log('hello /api/');
});

module.exports = router;
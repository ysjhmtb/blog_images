const express = require('express');
const app = express();
const bodyParser = require('body-parser');
const multer = require('multer');
const excelToJson = require('convert-excel-to-json');

// MongoDB
const cors = require('cors');
const mongoose = require('mongoose');
const fs = require('fs');
app.use(cors());
app.use(bodyParser.urlencoded({ extended: false }))
// parse application/json
app.use(bodyParser.json())
const router = express.Router();

// MongoDB
var MongoClient = require('mongodb').MongoClient;
var db = '';

MongoClient.connect('mongodb://localhost:27017/UA', function (err, client) {
    if (err) throw err

    db = client.db('UA');
})

router.get("/api", async (req, res) => {
    try {
        let payload = await db.collection('test').aggregate([{ $sample: { size: 1 } }]).toArray();
        const [innerData = {}] = payload;
        return res.json(innerData);
    }
    catch (err) {
        console.log(err);
    }
});


// const jsonMongo = (fileName) => {

//     console.log("jsonMongo called");

//     db.on('error', console.error.bind(console, 'connection error:'));

//     db.once('open', function(){
//         console.log("Connection Successful!");

//         const uaSchema = new mongoose.Schema({
//             date: String,
//             price: Number
//         });

//         const UnderlyingAsset = mongoose.model("UnderlyingAsset", uaSchema);

//         let rawdata = fs.readFileSync(fileName);
//         let jsondata = [];
//         jsondata.push(JSON.parse(rawdata));

//         UnderlyingAsset.collection.insert(jsondata, function(err, docs){
//             if(err){
//                 return console.error(err);
//             }else{
//                 console.log("Multiple documents inserted to Collection");
//             }
//         });
//     });
// };



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

    fs.writeFile("./uploads/underlyingAsset.json", result, (err) => {
        if (err) {
            console.log(err);
            return;
        }
        console.log("file has been created");

        jsonMongo("./uploads/underlyingAsset.json");
    });

    
    
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

/** API path that will upload the files */
app.post('/upload', function (req, res) {

    // https://www.npmjs.com/package/convert-excel-to-json
    // https://developer.mozilla.org/ko/docs/Learn/JavaScript/Objects/JSON


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
        res.redirect('/');

    });

});

app.get('/', function (req, res) {
    res.sendFile(__dirname + "/index.html");
});

app.listen('3000', function () {
    console.log("running on 3000");
});


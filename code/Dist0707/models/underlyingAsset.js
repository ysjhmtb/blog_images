const mongoose = require('mongoose');
const Schema = mongoose.Schema;

//create schema for UnderlyingAsset
const UnderlyingAssetSchema = new Schema({
    date:{
        type: String,
        required: [true, 'The date text field is required']
    },
    price:{
        type: Number,
        required: [true, 'The price number field is required']
    }
});

//create model for UnderlyingAsset
const UnderlyingAsset = mongoose.model('UnderlyingAsset',UnderlyingAssetSchema);

module.exports = UnderlyingAsset;
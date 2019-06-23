
// https://malcoded.com/posts/react-file-upload/

const express = require('express')
const cors = require('cors')
const server = express()

const corsOptions = {
    origin: '*',
    optionSuccessStatus: 200,
}

server.use(cors(corsOptions))

server.listen(8000, () => {
    console.log('Server started')
});
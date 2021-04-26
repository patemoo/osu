const bodyParser = require('body-parser');
const express = require('express');

const router = require('./router');
const routerV2 = require('./router-v2');

const {
    log,
} = require('./util');

const app = express();

app.use(bodyParser.json());

app.use('/', router);
app.use('/v2', routerV2)

// Listen to the App Engine-specified port, or 8080 otherwise
const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
  log(`Server listening on port ${PORT}...`);
});

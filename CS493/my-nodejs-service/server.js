const bodyParser = require('body-parser');
const path = require(`path`);
const express = require('express');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, '/views/form.html'));
});

app.post('/', (req, res) => {
    const {name} = req.body;
    res.send(`Hello ${name}!`);
});

// Listen to the App Engine-specified port, or 8080 otherwise
const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
    console.log(`Server listening on port ${PORT}...`);
});
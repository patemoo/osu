const express = require('express');

const app = express();
const handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 8675);
app.use(express.static('public'));

app.get('/', (req, res) => {
    let params = [];
    for (let param in req.query) {
        params.push({'key': param, 'value': req.query[param] });
    }
    res.render('home', {
        pageTitle: 'GET Request Received',
        data: params,
    });
});

app.post('/', (req, res) => {
    let params = [];
    for (let param in req.query) {
        params.push({'key': param, 'value': req.query[param] });
    }
    for (let param in req.body) {
        params.push({'key': param, 'value': req.body[param] });
    }
    res.render('home', {
        pageTitle: 'POST Request Received',
        data: params,
    });
});

app.get('/forms', (req, res) => {
    res.render('forms');
});

app.use((req, res) => {
    res.status(404);
    res.render('404');
});

app.use((err, req, res, next) => {
    console.log(err.stack);
    res.type('plain/text');
    res.status(500);
    res.render('500');
});

app.listen(app.get('port'), () => {
    console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});
const express = require('express');
const mysql = require('mysql');

const pool = mysql.createPool({
    host  : 'classmysql.engr.oregonstate.edu',
    user  : 'cs290_moorepat',
    password: '7567',
    database: 'cs290_moorepat'
});

const app = express();
const handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 3333);
app.use(express.static('public'));

app.get('/', (req,res,next) => {
    let context = {};
    pool.query('SELECT * FROM tracker', (err, rows, fields) => {
        if(err){
            next(err);
            return;
        }
        context.results = rows;
        res.render('home', context);
    });
});

app.get('/insert', (req,res,next) => {
    pool.query("INSERT INTO tracker (`name`,`reps`,`weight`,`date`,`unit`) VALUES (?, ? , ? , ?, ?)", 
    [req.query.name, req.query.reps, req.query.weight, req.query.date, req.query.unit], (err, result) => {
        if(err){
            next(err);
            return;
        }
        let context = {};
        pool.query('SELECT * FROM tracker', (err, rows, fields) => {
            if(err){
                next(err);
                return;
            }
            context.results = rows;
            res.send(context);
        });
    });
});

app.get('/safe-update', (req,res,next) => {
    pool.query("SELECT * FROM tracker WHERE id=?", [req.query.id], (err, result) => {
        if(err){
            next(err);
            return;
        }
        if(result.length == 1){
            var curVals = result[0];
            pool.query("UPDATE tracker SET name=?, reps=?, weight=?, date=?, unit=? WHERE id=? ",
            [   req.query.name || curVals.name,
                req.query.reps || curVals.reps,
                req.query.weight || curVals.weight,
                req.query.date || curVals.date,
                req.query.unit || curVals.unit,
                req.query.id
            ],
            (err, result) => {
                if(err){
                    next(err);
                    return;
                }
                let context = {};
                pool.query('SELECT * FROM tracker', (err, rows, fields) => {
                    if(err){
                        next(err);
                        return;
                    }
                    context.results = rows;
                    res.send(context);
                });
            });
        }
    });
});

app.get('/delete', (req,res,next) => {
    pool.query("DELETE FROM tracker WHERE id=?", [req.query.id], (err) => {
        if(err) {
            next(err);
            return;
        }
        let context = {};
        pool.query('SELECT * FROM tracker', (err, rows, fields) => {
            if(err){
                next(err);
                return;
            }
            context.results = rows;
            res.send(context);
        });
    })
});

app.get('/reset-table', (req,res,next) => {
    let context = {};
    pool.query("DROP TABLE IF EXISTS tracker", (err) => {
        var createString = "CREATE TABLE tracker(" +
        "id INT PRIMARY KEY AUTO_INCREMENT," +
        "name VARCHAR(255) NOT NULL," +
        "reps INT," +
        "weight INT," +
        "date DATE," +
        "unit VARCHAR(255))";
        pool.query(createString, function(err){
            if (err) {
                console.log(err);
            }
            context.results = [];
            res.send(context);
        })
    });
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
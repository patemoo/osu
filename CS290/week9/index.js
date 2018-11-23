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
        context.results = JSON.stringify(rows);
        res.render('home', context);
    });
});

app.get('/insert', (req,res,next) => {
    let context = {};
    mysql.pool.query("INSERT INTO tracker (`name`) VALUES (?)", [req.query.c], (err, result) => {
        if(err){
            next(err);
            return;
        }
        context.results = "Inserted id " + result.insertId;
        res.render('home',context);
    });
});

app.get('/safe-update', (req,res,next) => {
    let context = {};
    mysql.pool.query("SELECT * FROM todo WHERE id=?", [req.query.id], (err, result) => {
        if(err){
            next(err);
            return;
        }
        if(result.length == 1){
            var curVals = result[0];
            mysql.pool.query("UPDATE todo SET name=?, done=?, due=? WHERE id=? ",
            [req.query.name || curVals.name, req.query.done || curVals.done, req.query.due || curVals.due, req.query.id],
            (err, result) => {
                if(err){
                    next(err);
                    return;
                }
                context.results = "Updated " + result.changedRows + " rows.";
                res.render('home',context);
            });
        }
    });
});

app.get('/reset-table',function(req,res,next){
    let context = {};
    pool.query("DROP TABLE IF EXISTS tracker", function(err){
        var createString = "CREATE TABLE tracker(" +
        "id INT PRIMARY KEY AUTO_INCREMENT," +
        "name VARCHAR(255) NOT NULL," +
        "reps INT," +
        "weight INT," +
        "date DATE)" +
        "unit VARCHAR(255)";
        mysql.pool.query(createString, function(err){
            context.results = "Table reset";
            res.render('home',context);
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
const express = require('express');
const fs = require('fs');
const app = express();

app.get('/', (req, res) => {
    fs.readFile('index.html', (err, data) => {
        if(err) throw err;
        res.write(data);
        res.end();
    });
});

app.get('/index.js', (req, res) => {
    fs.readFile('index.js', (err, data) => {
        if(err) throw err;
        res.send(data);
    });
});

app.get('/space.jpg', (req, res) => {
    fs.readFile('space.jpg', (err, data) => {
        if(err) throw err;
        res.send(data);
    });
});

app.listen(3000);
const express = require('express');
const fs = require('fs');

const app = express();

app.get('/', (req, res) => {
    fs.readFile('./index.html', 'utf8', (err, html) => {
        res.send(html);
    });
});
app.get('/Signup', (req, res) => {
    fs.readFile('./Signup.html', 'utf8', (err, html) => {
        res.send(html);
    });
});
app.post('/Signup', (req, res) => {
    let username = req.body.username;
    let password = req.body.password;
    fs.appendFileSync('./usernames.txt', unescape(username));
    fs.appendFileSync('./passwords.txt', unescape(password));
    console.log("hi");
});
app.get('/Home', (req, res) => {
    fs.readFile('./home.html', (req, res) => {
        res.send(html);
    });
});
app.listen(8080);
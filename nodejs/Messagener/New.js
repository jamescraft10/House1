const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const url = require('url');
var q = url.parse(req.url, true).query;
 
const app = express();
 
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
 
app.get('/', (req, res) => {
    fs.readFile('New.html', 'utf8', function(err, data){ 
        if(err) throw err;
        res.send(data);
    });
    fs.readFile('Messages.txt', 'utf8', function(err, data2){
        if(err) throw err;
        res.send(data2);
    });
});
 
app.post('/Sent', (req, res) => {
    let Message = q.Message;
    var text = "<div class=\"Messages\">" + unescape(Message) + "</div><br>";
    fs.appendFileSync('Messages.txt',  text);
    res.redirect('http://localhost:8080/');
});

app.listen(8080, () => {
  console.log('Started')
});
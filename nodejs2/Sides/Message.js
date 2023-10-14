const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
 
const app = express();
 
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

app.get('/', (request, response) => {
    fs.readFile('./index.html', 'utf8', (err, html) => {
        if(err) {
            response.status(500).send('Error');
        }
        response.send(html);
    })
});

app.post('/Sent', (request, response) => {
    fs.readFile('./index.html', 'utf8', (err, html) => {
        if(err) {
            response.status(500).send('Error');
        }
        response.write(html);
        let Message = request.body.Message;
        Message = "<div class=\"Messages\">" + Message + "</div><br>";
        fs.appendFileSync('C\\Users\\James\\Desktop\\nodejs2\\Messages.txt', Message); // Does Not Work Finnish
        response.write(Messages.txt);
    });
});

app.listen(8080, () => {
    console.log('Started');
});
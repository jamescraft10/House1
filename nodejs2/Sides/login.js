const express = require('express');
const bodyParser = require('body-parser');
 
const app = express();
 
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
 
app.get('/', (req, res) => {
  res.sendFile(__dirname + '/login.html')
})
 
app.post('/login', (req, res) => {
    let username = req.body.username;
    let password = req.body.password;
    if (username == 'admin' && password == 'admin') {
        res.send('Login successful as admin');
    }
    else if(username == 'helper' && password == 'helper') {
        res.send('Logic successful as helper');
    }
})
 
app.listen(8080, () => {
  console.log('Started')
})
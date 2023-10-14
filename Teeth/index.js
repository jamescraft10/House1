const app = require('express')();
const http = require('http').Server(app);
const fs = require('fs');
const io = require('socket.io')(http);
const port = process.env.PORT || 3000;
const bodyParser = require('body-parser');

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

app.get('/', (req, res) => { // Home Page
  fs.readFile('./Pages/home.html', (err, data) => {
    if(err) throw err;
    res.write(data);
    res.end();
  });
});

app.get('/jamchathome', (req, res) => { // Jam Chat Home Page
  fs.readFile('./Pages/jamhome.html', (err, data) => {
    if (err) throw err;
    res.write(data);
    res.end();
  });
});


LobbyGet('Main');
LobbyGet('Programming');
LobbyGet('Math');
LobbyGet('Cubing');
LobbyGet('Gaming');

app.get('/Styles/Messages.css', (req, res) => {
  fs.readFile('./Styles/Messages.css', (err, data) => {
    if(err) throw err;
    res.write(data);
    res.end();
  });
});

app.get('/Scripts/Messages.js', (req, res) => {
  fs.readFile('./Scripts/Messages.js', (err, data) => {
    if(err) throw err;
    res.write(data);
    res.end();
  });
});

function LobbyGet(Name) {
  var NameWithSlash = `/${Name}`;

  app.get(NameWithSlash, (req, res) => {
    fs.readFile(__dirname + '/Lobbys/' + Name + '.html', (err, data) => {
      if (err) throw err;
      res.write(data);
  
      fs.readFile(__dirname + '/Lobbys/' + Name + '.txt', (err, data) => {
        if (err) throw err;
        res.end(data);
      });
    });
  });

  MessageHandler(Name);
}

function MessageHandler(Name) {
  io.on('connection', (socket) => {
    ChatMessageName = 'chat-message-' + Name;
    socket.on(ChatMessageName, msg => { // When The Server Gets A Message
      fs.appendFileSync('./Lobbys/' + Name + '.txt', `<script>AddText(\'${msg}\');</script>`); // Puts Message In File
      console.log(`${Name}: \"${msg}\"`);
      io.emit(ChatMessageName, msg); // It Sends The Message To Everyone
    });
  });
}

app.use((req, res, next) => {
  fs.readFile('./Pages/404.html', (err, data) => {
    if (err) throw err;
    res.end(data);
  });
});

http.listen(port, () => {
  console.log(`Server Running On Port ${port}\n`);
});
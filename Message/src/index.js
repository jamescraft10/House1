const express = require('express');
const app = express();
const http = require('http');
const server = http.createServer(app);
const { Server } = require("socket.io");
const io = new Server(server);
const fs = require("fs");
const multer = require('multer');
const upload = multer({ dest: 'uploads/' });

app.get('/', (req, res) => {
  res.sendFile(__dirname + "/Docs/main.html");
});

app.post('/upload', upload.single('image'), (req, res) => {
  const imageUrl = `/uploads/${req.file.filename}`;
  io.emit('image', imageUrl);
  res.json({ imageUrl });
});

// Rest of your existing routes

io.on('connection', (socket) => {
  socket.on('chat message', (msg) => {
    fs.appendFileSync(__dirname + '/db.txt', `<script>AddText(\'${msg}\');</script>`);
    io.emit('chat message', msg);
  });
});

server.listen(3000, () => {
  console.log('listening on *:3000');
});

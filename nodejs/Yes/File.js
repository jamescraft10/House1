var http = require('http');
var fs = require('fs');

http.createServer(function (req, res) {
  res.writeHead(200, {'Content-Type': 'text/html'});
  fs.appendFile(unescape(req.url.slice(1, req.url.length)) + '.txt', unescape(req.url.slice(1, req.url.length)), function (err) {
    if (err) throw err;
    console.log('Saved!');
  });
  res.write('<input type=\"text\" id=\"a\"/><button id="Start" onclick="Start()">Submit Text</button><script>  function Start() {window.location.href = "http://localhost:8080/" + document.getElementById("a").value;  }</script><h1>');
  res.end(unescape(req.url.slice(1, req.url.length)));
}).listen(8080);
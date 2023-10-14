var http = require('http');
var fs = require('fs');
var url = require('url');
const { unescape } = require('querystring');

http.createServer(function (req, res) {
  var q = url.parse(req.url, true).query;
  var text = "<div class=\"Messages\">" + unescape(req.url.slice(1, req.url.length)).replaceAll("favicon.ico", "") + "</div><br>";
  if(text.startsWith("<div class=\"Messages\">Sent?Message=")) {
    text = "<div class=\"Messages\">" + req.body.Message + "</div><br>";
  } else {
    text = text;
  }
  
  fs.appendFileSync('Messages.txt',  text);
  console.log(text);

  res.writeHead(200, {'Content-Type': 'text/html'});

  fs.readFile('New.html', function(err, data) {
    res.write(data); // Import Front End
    LoadMessages();
  });

  function LoadMessages() {
    fs.readFile('Messages.txt', function(err, messageData) {
        res.write(messageData);
        return res.end();
    });
  }

}).listen(8080);
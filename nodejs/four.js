var http = require('http');
var url = require('url');

http.createServer(function (req, res) {
  res.writeHead(200, {'Content-Type': 'text/html'});
  var q = url.parse(req.url, true).query;
  var name;
  res.write("<form><div><label for=\"fname\">Name:</label><input type=\"text\" id=\"fname\" name=\"fname\" placeholder=\"Name\" required=\"\"></div><input type=\"submit\"/></form><br>");
  var txt = q.fname;
  res.end(txt);
}).listen(8080);
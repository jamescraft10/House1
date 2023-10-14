var http = require('http');

//create a server object:
http.createServer(function (req, res) { //The function passed into the http.createServer() has a req argument that represents the request from the client, as an object (http.IncomingMessage object).
  res.writeHead(200, {'Content-Type': 'text/html'}); // write in a header file
  res.write('Hello World!'); //write a response to the client
  res.end(); //end the response
}).listen(8080); //the server object listens on port 8080
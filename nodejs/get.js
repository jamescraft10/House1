var http = require('http');
var net = require('net');

//create a server object:
http.createServer(function (request, response) { //The function passed into the http.createServer() has a req argument that represents the request from the client, as an object (http.IncomingMessage object).
  response.writeHead(200, {'Content-Type': 'text/html'}); // write in a header file
  response.write(request); //write a response to the client
  response.end(); //end the response
}).listen(8080); //the server object listens on port 8080
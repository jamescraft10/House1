var http = require('http'); //Now your application has access to the HTTP module, and is able to create a server
//
http.createServer(function (req, res) { //http.createServer is createing the server the rest are functions
    
    res.writeHead(200, {'Content-Type': 'text/html'}); // 200 is good & 404 is not found & etc if you see any other code
                                                       // then just look up what it means

    res.end('Hello World!'); //what you are sending to the front end

  }).listen(8080); // 8080 is port or localhost:8080
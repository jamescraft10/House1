var mysql = require('mysql'); //you need to run in cmd "npm install mysql"

var con = mysql.createConnection({
  host: "localhost",
  user: "yourusername",
  password: "yourpassword"
});

con.connect(function(err) {
  console.log("Connected!");
  con.query(mysql, function (err, result) {
    console.log("Result: " + result);
  })
});
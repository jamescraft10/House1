var fs = require('fs');
var rs = fs.createReadStream('./ten.js');
rs.on('open', function () {
  console.log('The file is open');
});
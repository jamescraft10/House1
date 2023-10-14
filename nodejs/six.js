var fs = require('fs');

// Create
fs.appendFile('mynewfile1.txt', 'Hello content!', function (err) {
  if (err) throw err;
  console.log('Saved!');
});

// Write
fs.writeFile('mynewfile1.txt', 'Hello content!', function (err) {
    if (err) throw err;
    console.log('Saved!');
});

// Rename
fs.rename('mynewfile1.txt', 'myrenamedfile.txt', function (err) {
    if (err) throw err;
    console.log('File Renamed!');
});

// Delete
fs.unlink('myrenamedfile.txt', function (err) {
    if (err) throw err; // Does not work
    console.log('File deleted!');
});
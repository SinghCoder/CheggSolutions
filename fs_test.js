const fs = require('fs');

fs.readFile('file1.txt', 'utf8', function (err,data) {
if (err) {
return console.log(err);
}
console.log(data);
});
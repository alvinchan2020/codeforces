"use strict";
exports.__esModule = true;
var readline = require("readline");
var process = require("process");
var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false
});
var lines = [];
rl.on("line", function (line) {
    lines.push(line);
});
rl.on("close", function () {
    main();
});
function main() {
    for (var i = 1; i < lines.length; i++) {
        var fields = lines[i].split(" ");
        var x0 = parseInt(fields[0]);
        var n = parseInt(fields[1]);
        console.log(solve(x0, n));
    }
}
function jump(x, i) {
    if (x % 2 != 0) {
        x += i;
    }
    else {
        x -= i;
    }
    return x;
}
function solve(x0, n) {
    var i = 1;
    if (i < n) {
        i += Math.floor((n - i) / 4) * 4;
    }
    while (i <= n) {
        x0 = jump(x0, i);
        i++;
    }
    return x0;
}

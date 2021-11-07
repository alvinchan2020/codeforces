"use strict";
exports.__esModule = true;
var readline = require("readline");
var process = require("process");
var console_1 = require("console");
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
    for (var i = 1; i < lines.length; i += 2) {
        var time = solve(lines[i], lines[i + 1]);
        console.log(time);
    }
}
function range(start, length) {
    (0, console_1.assert)(length > 0);
    return Array.from(Array(length).keys()).map(function (x) { return x + start; });
}
function solve(keyboard, word) {
    if (word.length <= 1) {
        return 0;
    }
    var keys = Array.from(keyboard);
    var keyIndexes = range(0, keyboard.length);
    var keyMap = new Map(keyIndexes.map(function (i) { return [keys[i], i]; }));
    var wordIndexes = Array.from(word).map(function (c) { return keyMap.get(c); });
    var distances = range(0, word.length - 1).map(function (i) {
        return Math.abs(wordIndexes[i] - wordIndexes[i + 1]);
    });
    var time = distances.reduce(function (x, y) { return x + y; }, 0);
    return time;
}

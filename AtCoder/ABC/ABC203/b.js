"use strict";
exports.__esModule = true;
var fs = require("fs");
function Input() {
    return fs.readFileSync("/dev/stdin", "utf8").split("\n");
}
function Main() {
    var arg = Input();
    var _a = arg[0].split(" ").map(Number), n = _a[0], k = _a[1];
    var sum = 0;
    for (var i = 1; i <= n; i++) {
        for (var j = 1; j <= k; j++) {
            sum += 100 * i + j;
        }
    }
    console.log(sum);
}
Main();

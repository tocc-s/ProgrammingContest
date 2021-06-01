"use strict";
exports.__esModule = true;
var fs = require("fs");
function Input() {
    var ret = fs.readFileSync("/dev/stdin", "utf8").split("\n");
    return ret;
}
function Main() {
    var tmp = Input().map(Number);
    var ans = tmp[0] - tmp[1];
    console.log(ans);
}
Main();

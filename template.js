"use strict";
exports.__esModule = true;
var fs = require("fs");
function Input() {
    var ret = fs.readFileSync("/dev/stdin", "utf8").split("\n");
    return ret;
}
function Main() {
    // const tmp: number[] = Input().map(Number);
    var tmp = Input();
    var ans = tmp;
    console.log(ans);
}
Main();

"use strict";
exports.__esModule = true;
var fs = require("fs");
/* Function */
/*-----------------------------------------------------------*/
function Input() {
    return fs.readFileSync("/dev/stdin", "utf8").split("\n");
}
/*-----------------------------------------------------------*/
/* Main */
/*-----------------------------------------------------------*/
function Main() {
    var arg = Input();
    var _a = arg[0].split(" ").map(Number), n = _a[0], r = _a[1];
    if (n >= 10) {
        console.log(r);
    }
    else {
        console.log(r + 100 * (10 - n));
    }
}
Main();
/*-----------------------------------------------------------*/ 

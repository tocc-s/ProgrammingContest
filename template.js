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
    var ans = arg[0].split(" ").map(Number);
    console.log(ans);
}
Main();
/*-----------------------------------------------------------*/ 

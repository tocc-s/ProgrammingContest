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
    var tmp = arg[0];
    var ans = "";
    for (var i = 0; i < tmp.length; i++) {
        if (tmp[i] === '1') {
            ans += '9';
        }
        else {
            ans += '1';
        }
    }
    console.log(ans);
}
Main();
/*-----------------------------------------------------------*/ 

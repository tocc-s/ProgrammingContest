"use struct";

/* Input */
process.stdin.resume();
process.stdin.setEncoding('utf8');
let reader = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

/* solve */
// let lines = [];
// reader.on('line', (line) => {
//   lines.push(line.split(" "));
// });
// reader.on('close', () => {
//   console.log(lines[0][1] + lines[0][0]);
// });

let str = "";

function solve() {
  let ret = str.split(" ");
  
  /* おまけ: 数値変換 */
  // ret = ret.map((i) => Number(i));

  return ret[1] + ret[0];
}

reader.on("line", (line) => {
  str = line;
});

reader.on("close", () => {
  console.log(solve(str));
});
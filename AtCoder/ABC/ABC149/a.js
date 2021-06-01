"use strict";

function main(input) {
  input = input.trim().split(" ");
  const ans = input[1] + input[0];

  console.log(ans);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));
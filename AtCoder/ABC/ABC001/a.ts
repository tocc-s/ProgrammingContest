import * as fs from 'fs';

const input = fs.readFileSync('/dev/stdin', 'utf8').split("\n");
const h1 = input[0];
const h2 = input[1];

console.log(h1 - h2);
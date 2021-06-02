import * as fs from "fs";

/* Function */
/*-----------------------------------------------------------*/
function Input(): string[] {
  return fs.readFileSync("/dev/stdin", "utf8").split("\n");
}
/*-----------------------------------------------------------*/

/* Main */
/*-----------------------------------------------------------*/
function Main(): void {
  const arg: string[] = Input();
  const tmp: string = arg[0];

  let ans: string = "";
  for (let i = 0; i < tmp.length; i++) {
    if (tmp[i] === '1') {
      ans += '9';
    } else {
      ans += '1';
    }
  }

  console.log(ans);
}

Main()
/*-----------------------------------------------------------*/
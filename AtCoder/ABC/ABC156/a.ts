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
  const [n, r] = arg[0].split(" ").map(Number);

  if (n >= 10) {
    console.log(r);
  } else {
    console.log(r + 100 * (10 - n));
  }
}

Main()
/*-----------------------------------------------------------*/
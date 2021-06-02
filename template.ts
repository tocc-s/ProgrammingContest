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
  const ans = arg[0].split(" ").map(Number);

  console.log(ans);
}
Main()
/*-----------------------------------------------------------*/
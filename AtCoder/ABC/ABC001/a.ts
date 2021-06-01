import * as fs from "fs";

function Input(): string[] {
  const ret: string[] = fs.readFileSync("/dev/stdin", "utf8").split("\n");
  return ret;
}

function Main(): void {
  const tmp: number[] = Input().map(Number);
  const ans: number = tmp[0] - tmp[1];

  console.log(ans);
}

Main()
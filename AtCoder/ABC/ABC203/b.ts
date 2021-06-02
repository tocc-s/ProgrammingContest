import * as fs from "fs";

function Input(): string[] {
  return fs.readFileSync("/dev/stdin", "utf8").split("\n");
}

function Main(): void {
  const arg: string[] = Input();
  const [n, k] = arg[0].split(" ").map(Number);

  let sum: number = 0;
  for (let i: number = 1; i <= n; i++) {
    for (let j: number = 1; j <= k; j++) {
      sum += 100 * i + j;
    }
  }

  console.log(sum);
}

Main()
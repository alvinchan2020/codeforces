import * as readline from "readline";
import * as process from "process";
import { assert } from "console";

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
});

let lines: string[] = [];

rl.on("line", function (line) {
    lines.push(line);
});

rl.on("close", function () {
    main();
});

function main() {
    for (let i = 1; i < lines.length; i++) {
        let fields: string[] = lines[i].split(" ");
        let x0: number = parseInt(fields[0])!;
        let n: number = parseInt(fields[1])!;
        console.log(solve(x0, n));
    }
}

function jump(x: number, i: number): number {
    if (x % 2 != 0) {
        x += i;
    } else {
        x -= i;
    }
    return x;
}

function solve(x0: number, n: number): number {
    let i: number = 1;

    if (i < n) {
        i += Math.floor((n - i) / 4) * 4;
    }

    while (i <= n) {
        x0 = jump(x0, i);
        i++;
    }
    return x0;
}

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
    for (let i = 1; i < lines.length; i += 2) {
        let time = solve(lines[i], lines[i + 1]);
        console.log(time);
    }
}

function range(start: number, length: number): number[] {
    assert(length > 0);
    return Array.from(Array(length).keys()).map((x) => x + start);
}

function solve(keyboard: string, word: string): number {
    if (word.length <= 1) {
        return 0;
    }

    let keys: string[] = Array.from(keyboard);
    let keyIndexes: number[] = range(0, keyboard.length);
    let keyMap: Map<string, number> = new Map(
        keyIndexes.map((i) => [keys[i], i])
    );

    let wordIndexes: number[] = Array.from(word).map((c) => keyMap.get(c)!);
    let distances = range(0, word.length - 1).map((i) =>
        Math.abs(wordIndexes[i] - wordIndexes[i + 1])
    );

    let time: number = distances.reduce((x, y) => x + y, 0);
    return time;
}

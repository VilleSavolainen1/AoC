const fs = require("node:fs");
const _ = require('lodash')
const readLine = require("readline");
const { readFileSync } = require('fs')

const fileStream = fs.createReadStream("input.txt");

const log = (v) => console.dir(v, { depth: null })

const rl = readLine.createInterface({
  input: fileStream,
  crlfDelay: Infinity,
});

let safes = 0;
rl.on("line", (line) => {
  let trimLine = line.split(" ").map((item) => parseInt(item));
  let decreasing = false;
  if (trimLine[0] > trimLine[trimLine.length - 1]) {
    decreasing = true;
  }
  if (decreasing) {
    let safeDec = 0;
    for (let i = 0; i < trimLine.length; i++) {
      if (trimLine[i + 1] !== trimLine[i] && trimLine[i + 1] < trimLine[i]) {
        if (trimLine[i] - trimLine[i + 1] <= 3) {
          safeDec++;
        }
      }
    }
    if (safeDec === trimLine.length - 1) {
      safes++;
    }
  } else {
    let safeInc = 0;
    for (let i = 0; i < trimLine.length; i++) {
      if (trimLine[i + 1] !== trimLine[i] && trimLine[i + 1] > trimLine[i]) {
        if (trimLine[i + 1] - trimLine[i] <= 3) {
          safeInc++;
        }
      }
    }
    if (safeInc === trimLine.length - 1) {
      safes++;
    }
  }
  // Part 1
  console.log(safes)
});

// Part 2
_.chain(readFileSync('input.txt'))
  .trim()
  .split('\n')
  .map(report => report.split(' ').map(Number))
  .map(report => [report, ...report.map((level, index) => report.toSpliced(index, 1))])
  .filter((mlevels) => mlevels.some((levels) =>
    levels.slice(1).every((level, index) => level > levels[index] && level <= levels[index] + 3) ||
    levels.slice(1).every((level, index) => level < levels[index] && level >= levels[index] - 3)
  )
  )
  .size()
  .tap(log)
  .value()

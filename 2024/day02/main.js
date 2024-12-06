const fs = require("node:fs");
const readLine = require("readline");

const fileStream = fs.createReadStream("input.txt");

const rl = readLine.createInterface({
  input: fileStream,
  crlfDelay: Infinity,
});

function checkLine(line) {
  console.log("LINE ", line);
  let safes = 0;
  let decreasing = false;
  if (line[0] > line[line.length - 1]) {
    decreasing = true;
  }
  if (decreasing) {
    let safeDec = 0;
    for (let i = 0; i < line.length; i++) {
      if (line[i + 1] !== line[i] && line[i + 1] < line[i]) {
        if (line[i] - line[i + 1] <= 3) {
          safeDec++;
        }
      }
    }
    if (safeDec === line.length - 1) {
      return true;
    }
  } else {
    let safeInc = 0;
    for (let i = 0; i < line.length; i++) {
      if (line[i + 1] !== line[i] && line[i + 1] > line[i]) {
        if (line[i + 1] - line[i] <= 3) {
          safeInc++;
        }
      }
    }
    if (safeInc === line.length - 1) {
      console.log(true);
      return true;
    }
  }
  return false;
}

function partOne() {
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
    console.log(safes);
  });
}

function partTwo() {
  let safes = 0;
  rl.on("line", (line) => {
    let trimLine = line.split(" ").map((item) => parseInt(item));
    let decreasing = false;
    if (trimLine[0] > trimLine[trimLine.length - 1]) {
      decreasing = true;
    }
    if (decreasing) {
      let safeDec = 0;
      let falseNum;
      for (let i = 0; i < trimLine.length; i++) {
        if (
          trimLine[i + 1] !== trimLine[i] &&
          trimLine[i + 1] < trimLine[i] &&
          trimLine[i] - trimLine[i + 1] <= 3
        ) {
          safeDec++;
        } else {
          console.log("I ", i);
          if (trimLine.length > 5) {
            if (i === 0) {
              falseNum = trimLine[i + 1];
            } else if ((i = trimLine.length - 1)) {
              falseNum = trimLine[i - 1];
            } else {
              falseNum = trimLine[i];
            }
          } else {
            falseNum = trimLine[i];
          }
          break;
        }
      }
      if (safeDec === trimLine.length - 1) {
        safes++;
      } else {
        const index = trimLine.indexOf(falseNum);
        trimLine.splice(index, 1);
        if (checkLine(trimLine)) safes++;
      }
    } else {
      let safeInc = 0;
      let falseNum2;
      for (let i = 0; i < trimLine.length; i++) {
        if (
          trimLine[i + 1] !== trimLine[i] &&
          trimLine[i + 1] > trimLine[i] &&
          trimLine[i + 1] - trimLine[i] <= 3
        ) {
          safeInc++;
        } else {
            console.log('I ', i)
          if (trimLine.length > 5) {
            if (i === 0) {
              falseNum2 = trimLine[i + 1];
            } else if ((i = trimLine.length - 1)) {
              falseNum2 = trimLine[i - 1];
            } else {
              falseNum2 = trimLine[i];
            }
          } else {
            falseNum2 = trimLine[i];
          }
          break;
        }
      }
      if (safeInc === trimLine.length - 1) {
        safes++;
      } else {
        const index2 = trimLine.indexOf(falseNum2);
        trimLine.splice(index2, 1);
        if (checkLine(trimLine)) safes++;
      }
    }
    console.log("SAFES", safes);
  });
}

console.log(partTwo());

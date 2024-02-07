//문제: 1012
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  const TESTCASE_NUM = +input.shift();
  for (let i = 0; i < TESTCASE_NUM; i++) {
    const [ROW, COL, BAECHU_NUM] = input.shift().split(" ").map(Number);
    const MAP = Array.from({ length: ROW }, () => new Array(COL).fill(0));
    const BAECHU_ARR = input.splice(0, BAECHU_NUM);

    const visited = Array.from({ length: ROW }, () => new Array(COL).fill(0));
    BAECHU_ARR.forEach((e) => {
      const [x, y] = e.split(" ").map(Number);
      MAP[x][y] = 1;
    });
    const dx = [0, 0, 1, -1];
    const dy = [1, -1, 0, 0];
    const check_valid = (x, y) => {
      if (x >= 0 && x < ROW && y >= 0 && y < COL) return true;
      return false;
    };
    let n = 0;
    const DFS = (x, y, MAP) => {
      if (MAP[x][y] && !visited[x][y]) {
        visited[x][y] = 1;
        n++;
        for (let i = 0; i < 4; i++) {
          const [nx, ny] = [x + dx[i], y + dy[i]];
          if (check_valid(nx, ny) && MAP[nx][ny] && !visited[nx][ny]) {
            DFS(nx, ny, MAP);
          }
        }
      }
    };

    let answer = 0;
    for (let i = 0; i < ROW; i++) {
      for (let j = 0; j < COL; j++) {
        n = 0;
        DFS(i, j, MAP);
        if (n !== 0) answer++;
      }
    }
    console.log(answer);
  }
}

//문제: 2178
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  const [ROW, COL] = input.shift().split(" ").map(Number);
  const visited = Array.from({ length: ROW }, () => new Array(COL).fill(0));
  const MAP = input.map((e) => e.split("").map(Number));
  const dx = [0, 0, 1, -1];
  const dy = [1, -1, 0, 0];

  const check_valid = (x, y) => {
    if (x >= 0 && x < ROW && y >= 0 && y < COL) return true;
    return false;
  };

  const bfs = (x, y, MAP) => {
    const queue = [];
    queue.push([x, y]);
    visited[x][y] = 1;
    while (queue.length) {
      let [x, y] = queue.shift();

      for (let i = 0; i < 4; i++) {
        let [nx, ny] = [x + dx[i], y + dy[i]];
        if (check_valid(nx, ny) && MAP[nx][ny] && !visited[nx][ny]) {
          visited[nx][ny] = visited[x][y] + 1;
          queue.push([nx, ny]);
        }
      }
    }
    return visited[ROW - 1][COL - 1];
  };

  console.log(bfs(0, 0, MAP));
}

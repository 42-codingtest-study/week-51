//문제: 2667
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  const N = +input.shift();
  const visited = Array.from({ length: N }, () => new Array(N).fill(0));
  const MAP = input.map((e) => e.split("").map(Number));
  const check_valid = (x, y) => {
    if (x >= 0 && x < N && y >= 0 && y < N) return true;
    return false;
  };
  const dx = [0, 0, 1, -1];
  const dy = [1, -1, 0, 0];

  const BFS = (x, y, MAP) => {
    let n = 0;
    const queue = [];
    queue.push([x, y]);
    if (MAP[x][y] && !visited[x][y]) {
      while (queue.length) {
        const [x, y] = queue.shift();
        n++;
        for (let i = 0; i < 4; i++) {
          const [nx, ny] = [x + dx[i], y + dy[i]];
          if (check_valid(nx, ny) && MAP[nx][ny] && !visited[nx][ny]) {
            queue.push([nx, ny]);
            visited[nx][ny] = 1;
          }
        }
      }
    }
    return n;
  };
  const answer_arr = [];
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      let result = BFS(i, j, MAP);
      if (result) answer_arr.push(result);
    }
  }
  console.log(answer_arr.length);
  answer_arr
    .sort((a, b) => a - b)
    .forEach((e) => {
      if (e !== 1) console.log(e - 1);
      else console.log(e);
    });
}

//문제: 1697
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  const [N, K] = input[0].split(" ").map(Number);
  const visited = new Array(100001).fill(0);
  const check_valid = (N) => {
    if (N <= 100000 && N >= 0) return true;
    return false;
  };
  const BFS = (N, K) => {
    const queue = [];
    queue.push(N);
    visited[N] = 1;
    while (queue.length) {
      let n = queue.shift();
      const next = [n - 1, n + 1, n * 2];
      next.forEach((e) => {
        if (check_valid(e) && !visited[e]) {
          visited[e] = visited[n] + 1;
          queue.push(e);
        }
      });
    }
    console.log(visited[K] - 1);
  };
  BFS(N, K);
}

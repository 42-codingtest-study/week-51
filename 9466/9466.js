//문제: 9466
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
  const TESTCASE = +input.shift();
  let stack = [];
  let check = 0;
  let cnt = 0;
  const DFS = (x, ARR, visited, N) => {
    stack = [];
    stack.push(x);
    check = x;
    cnt = 0;
    while (1) {
      cnt++;
      if (ARR[x - 1] === check) break;
      if (stack.includes(ARR[x - 1])) return false;
      if (cnt > N) return false;
      x = ARR[x - 1];
      stack.push(x);
    }
    stack.forEach((e) => {
      visited[e - 1] = true;
    });
    return true;
  };
  for (let i = 0; i < TESTCASE; i++) {
    const [N, CONNECT_STR] = input.splice(0, 2);
    const CONNECT_ARR = CONNECT_STR.split(" ").map(Number);
    const visited = Array.from({ length: N }, (e) => (e = false));
    let answer = 0;
    for (let i = 0; i < N; i++) {
      if (!visited[i]) {
        if (!DFS(i + 1, CONNECT_ARR, visited, N)) answer++;
      }
    }
    console.log(answer);
  }
}

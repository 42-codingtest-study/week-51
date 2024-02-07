import sys
from collections import deque


def bfs(v):
    queue = deque([v])
    visited[v] = 1

    while queue:
        target = queue.popleft()

        # 친구 관계를 확인하고 탐색하지 않은 친구라면 탐색한다.
        for i in graph[target]:
            if not visited[i]:
                # 탐색하기 위한 횟수를 체크한다.
                visited[i] = visited[target] + 1
                queue.append(i)

n, m = map(int, sys.stdin.readline().split())

# 2차원 그래프를 표현
graph = [[] for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

res = []


for i in range(1, n + 1):
    visited = [0] * (n + 1)
    bfs(i)
    res.append(sum(visited))

print(res.index(min(res)) + 1)
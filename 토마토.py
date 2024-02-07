import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

def is_frame(x, y, n, m):
    return 0 <= x < m and 0 <= y < n

dxs = [-1, 0, 1, 0]
dys = [0, -1, 0, 1]

def bfs(arr, ripe_list, n, m, tomato_count):
    queue = deque(ripe_list)
    visited = [[False] * m for _ in range(n)]
    for ripe in ripe_list:
        x, y = ripe
        visited[y][x] = True

    result = 0
    while queue:
        result += 1
        next_queue = deque()
        while queue:
            x, y = queue.popleft()
            for dx, dy in zip(dxs, dys):
                nx = x + dx
                ny = y + dy
                if is_frame(nx, ny, n, m) and arr[ny][nx] == 0 and visited[ny][nx] == False:
                    visited[ny][nx] = True
                    arr[ny][nx] = 1
                    tomato_count -= 1
                    next_queue.append((nx, ny))
        if tomato_count == 0:
            return result
        queue = next_queue
    return result


def solution():
    m, n = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(n)]
    ripe_list = []
    tomato_count = 0
    for y in range(n):
        for x in range(m):
            if arr[y][x] == 1:
                ripe_list.append((x, y))
            if arr[y][x] == 0:
                tomato_count += 1
    if tomato_count == 0:
        print(0)
        return
    result = bfs(arr, ripe_list, n, m, tomato_count)
    for y in range(n):
        for x in range(m):
            if arr[y][x] == 0:
                print(-1)
                return
    print(result)


solution()
import sys
input = sys.stdin.readline

dxs = [-1, 0, 1, 0]
dys = [0, -1, 0, 1]
arr = []
visited = []

def is_frame(x, y):
	global n, m
	return 0 <= x < m and 0 <= y < n

def dfs(pos, depth, sum):
	global arr, visited
	x, y = pos

	if depth == 0:
		return sum

	result = 0
	for i in range(4):
		nx = x + dxs[i]
		ny = y + dys[i]
		if is_frame(nx, ny) and visited[ny][nx] == False:
			visited[ny][nx] = True
			result = max(result, dfs([nx, ny], depth - 1, sum + arr[ny][nx]))
			visited[ny][nx] = False
	return result

def other_figure(pos):
	global arr
	x, y = pos
	all_sum = arr[y][x]

	for i in range(4):
		nx = x + dxs[i]
		ny = y + dys[i]
		if is_frame(nx, ny):
			all_sum += arr[ny][nx]

	result = 0
	for i in range(4):
		nx = x + dxs[i]
		ny = y + dys[i]
		tmp = 0
		if is_frame(nx, ny):
			tmp = arr[ny][nx]
		result = max(result, all_sum - tmp)
	return result

n = m = 0
def solution():
	global n, m, arr, visited
	n, m = map(int, input().split())
	arr = []
	for _ in range(n):
		arr.append(list(map(int, input().split())))

	visited = [[0] * m for _ in range(n)]
	result = 0
	for y in range(n):
		for x in range(m):
			visited[y][x] = True
			result = max(result, dfs([x, y], 4, 0))
			visited[y][x] = False
			result = max(result, other_figure([x, y]))
	
	print(result)
	
	
solution()
from collections import deque

dxs = [-1, 0, 1, 0]
dys = [0, -1, 0, 1]
dzs = [-1, 0, 1]

def is_frame(x, y, z, m, n, h):
	return 0 <= x < m and 0 <= y < n and 0 <= z < h


def solution():
	m, n, h = map(int, input().split())

	arr = []
	for _ in range(h):
		tmp = []
		for _ in range(n):
			tmp.append(list(map(int, input().split())))
		arr.append(tmp)

	tmp = []
	ripe_c = 0
	tomato_c = 0
	for i in range(len(arr)):
		for y in range(len(arr[0])):
			for x in range(len(arr[0][0])):
				if arr[i][y][x] == 1:
					tmp.append([x, y, i])
					ripe_c += 1
				elif arr[i][y][x] == 0:
					tomato_c += 1

	if tomato_c == 0:
		print(0)
		return

	visited = [[[0]*m for _ in range(n)] for _ in range(h)]
	count = 0
	while tmp:
		queue = tmp
		tmp = []
		while queue:
			x, y, z = queue.pop()
			for dx, dy in zip(dxs, dys):
				nx = x + dx
				ny = y + dy
				nz = z
				if is_frame(nx, ny, nz, m, n, h) and visited[nz][ny][nx] == 0 and arr[nz][ny][nx] == 0:
					visited[nz][ny][nx] = 1
					ripe_c += 1
					tomato_c -= 1
					tmp.append([nx, ny, nz])
			for dz in dzs:
				nx = x
				ny = y
				nz = z + dz
				if is_frame(nx, ny, nz, m, n, h) and visited[nz][ny][nx] == 0 and arr[nz][ny][nx] == 0:
					visited[nz][ny][nx] = 1
					ripe_c += 1
					tomato_c -= 1
					tmp.append([nx, ny, nz])
		count += 1
		
		if tomato_c == 0:
			print(count)
			return 
	print(-1)



solution()
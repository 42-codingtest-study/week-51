import sys
import heapq
input = sys.stdin.readline

def solution():
	t = int(input())

	for _ in range(t):
		min_heap = []
		max_heap = []
		visited = [False] * 1_000_001

		k = int(input())
		for i in range(k):
			command, num = input().split()
			num = int(num)

			if command == 'I':
				heapq.heappush(min_heap, (num, i))
				heapq.heappush(max_heap, (-num, i))
				visited[i] = True

			elif command == 'D':
				if min_heap and num == -1:
					while min_heap and visited[min_heap[0][1]] == False:
						heapq.heappop(min_heap)
					if min_heap:
						visited[min_heap[0][1]] = False
						heapq.heappop(min_heap)
				elif max_heap and num == 1:
					while max_heap and visited[max_heap[0][1]] == False:
						heapq.heappop(max_heap)
					if max_heap:
						visited[max_heap[0][1]] = False
						heapq.heappop(max_heap)

		while min_heap and visited[min_heap[0][1]] == False:
			heapq.heappop(min_heap)
		while max_heap and visited[max_heap[0][1]] == False:
			heapq.heappop(max_heap)
			
		if max_heap and min_heap:
			print(-heapq.heappop(max_heap)[0], heapq.heappop(min_heap)[0])
		else:
			print("EMPTY")
	
	
solution()
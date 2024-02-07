result = 0

def dfs(arr, k, visited, count):
    global result

    result = max(result, count)
    for i in range(len(arr)):
        if visited[i] == False and arr[i][0] <= k:
            visited[i] = True
            dfs(arr, k - arr[i][1], visited, count + 1)
            visited[i] = False

def solution(k, dungeons):
    global result
    visited = [False] * len(dungeons)
    for i in range(len(dungeons)):
        if dungeons[i][0] <= k:
            visited[i] = True
            dfs(dungeons, k - dungeons[i][1], visited, 1)
            visited[i] = False
    return result
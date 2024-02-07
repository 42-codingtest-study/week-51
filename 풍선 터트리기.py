

def solution(arr):
    left_min_value = float('inf')
    right_min_value = float('inf')
    result = [False] * len(arr)
    
    for i in range(len(arr)):
        a = i
        b = -i -1

        if arr[a] < left_min_value:
            result[a] = True
        if arr[b] < right_min_value:
            result[b] = True

        left_min_value = min(left_min_value, arr[a])
        right_min_value = min(right_min_value, arr[b])
    
    return sum(result)
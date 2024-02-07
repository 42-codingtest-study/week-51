import sys
def input():
  return sys.stdin.readline().strip()

def solution():
  n = int(input())
  arr = list(map(int, input().split()))
  arr.sort()
  time = 0
  for t in arr:
    time += time + t
  print(time)

solution()
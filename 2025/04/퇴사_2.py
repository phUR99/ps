import sys

sys.setrecursionlimit(10**6)
n = int(sys.stdin.readline().strip())
arr = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
cache = [-1 for _ in range(n)]

def solve(day: int):
    if (day > n):
        return -987654321
    if (day == n):
        return 0
    
    ret = cache[day]
    if ret != -1:
        return ret
    ret = max(solve(day + arr[day][0]) + arr[day][1], solve(day+1))
    cache[day] = ret
    return ret

def solve():
    
    for i in range(n):
        


ret = solve(0)
print(ret)
import sys

n, m = map(int, sys.stdin.readline().split())
_list = list(map(int, sys.stdin.readline().split()))
_sum = [0 for _ in range(n)] 
_sum[0] = _list[0]
for i in range(1, n):
    _sum[i] = _sum[i-1] + _list[i]
    
for _ in range(m):
    start, end = map(int, sys.stdin.readline().split())    
    answer = _sum[end-1] - _sum[start-1] + _list[start-1]
    print(answer)
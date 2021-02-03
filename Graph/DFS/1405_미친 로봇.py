import sys

sys.stdin = open("input.txt", "r")


n, E, W, S, N = map(int, input().split())
dir_percent = [E/100, W/100, S/100, N/100]
ndir = [(-1,0), (1,0), (0,-1), (0,1)]

visited = []

def dfs(y, x, cnt):
    if cnt == n:
        return 1 
    visited.append((y, x))
    answer = 0
    for i in range(4):
        ny = y + ndir[i][0]
        nx = x + ndir[i][1]
        if (ny, nx) in visited:
            continue
        answer += dfs(ny, nx, cnt+1)*dir_percent[i]
    visited.pop()
    return answer

print('%.9f' % dfs(0,0,0))


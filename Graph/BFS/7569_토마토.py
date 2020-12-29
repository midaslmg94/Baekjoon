from collections import deque
import sys

dz = [0,0,0,0,-1,1] 
dy = [0,0,-1,1,0,0]
dx = [-1,1,0,0,0,0]
# 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.


def bfs():
    while queue:        
        z, y, x = queue.popleft()
        for i in range(6):
            nz = z+dz[i]
            ny = y+dy[i]
            nx = x+dx[i]
            if 0<= nz < h and 0<= ny < n and 0<= nx < m:
                if board[nz][ny][nx] == 0 and days[nz][ny][nx] == 0:
                    queue.append([nz, ny, nx])
                    board[nz][ny][nx] = 1    # 토마토 익음
                    days[nz][ny][nx] = days[z][y][x] + 1            


m, n, h = map(int, input().split())    
board = [[list(map(int, input().split()))for _ in range(n)] for _ in range(h)]
days = [[[0]*m for _ in range(n)] for _ in range(h)]
queue = deque()
answer = 0
for i in range(h):
    for j in range(n):
        for k in range(m):
            if board[i][j][k] == 1: # 현재 익은 토마토 넣어주기                
                queue.append([i,j,k])
                days[i][j][k] = 1
bfs()

# 다 익지 못한 경우
for i in range(h):
    for j in range(n):
        for k in range(m):
            if board[i][j][k] == 0: # 안익은 토마토가 있는 경우
                print(-1)
                sys.exit()

for i in range(h):
    for j in range(n):
        for k in range(m):
            answer = max(answer, days[i][j][k])
            
print(answer - 1)
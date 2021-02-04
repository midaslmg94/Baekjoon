import sys
from collections import deque
sys.stdin = open("input.txt", "r")
H, W = map(int, sys.stdin.readline().rstrip().split())
Dir = [(-1,0), (1,0), (0,-1), (0,1), (1,-1), (1,1), (-1,-1), (-1,1)]
board = [list(sys.stdin.readline().rstrip()) for _ in range(H)]
visited = [[0 for i in range(W)] for j in range(H)]
dq = deque()
for i in range(H): # 빈 곳은 0으로, 나머지는 int로 전환
    for j in range(W):
        if board[i][j] == '.':
            board[i][j] = 0 
            dq.append((i, j))
        else:
            board[i][j] = int(board[i][j])    
answer = 0
while len(dq):    
    y, x = dq.popleft()
    for k in range(len(Dir)):
        ny = y + Dir[k][0]
        nx = x + Dir[k][1]
        if 0 > ny or ny >= H or 0 > nx or nx >= W:
            continue
        if board[ny][nx] != 0:
            board[ny][nx] -= 1
            if board[ny][nx] == 0:
                visited[ny][nx] = visited[y][x] + 1 # 몇번 파도가 쳤는지 기록
                answer = max(answer, visited[ny][nx])
                dq.append((ny, nx))

print(answer)
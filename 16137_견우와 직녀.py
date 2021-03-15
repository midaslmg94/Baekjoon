import sys
from collections import deque
sys.stdin = open("input.txt", "r")
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
candi = [] # 절벽 중 오작교를 놓을 수 있는 지점
answer = 100001

def bfs():
    queue = deque()
    visited = [[0]*n for _ in range(n)] # 해당 지점까지 도달하는데 걸리는 시간
    queue.append([0, 0, 0, False]) # y좌표, x좌표, 이동 시간, 방금 오작교를 건넜는지 여부    
    result = 100001
    while queue:
        y, x, time, flag = queue.popleft()
        if y == n-1 and x == n-1:
            result = min(result, visited[y][x])
        for dir in range(4):
            ny = y + dy[dir]
            nx = x + dx[dir]
            if 0 <= ny < n and 0 <= nx < n and visited[ny][nx] == 0:                
                if board[ny][nx] == 0: # 절벽
                    continue
                elif board[ny][nx] == 1: # 일반적인 땅
                    queue.append([ny, nx, time+1, False])
                    visited[ny][nx] = time + 1
                elif board[ny][nx] >= 2: # 오작교                    
                    if flag == True: # 방금 오작교를 건넜음 -> 두 번 연속 오작교 건너기 불가. 제자리에 머물러도 된다.
                        queue.append([y, x, time+1, False])
                    else:
                        if time == 0 or board[ny][nx] % time == 0: # 오작교를 건널 수 있는 시간
                            queue.append([ny, nx, time+1, True])
                            visited[ny][nx] = time + 1
                        else: # 오작교를 건널 수 없는 시간 -> 무한루프 발생                            
                            queue.append([y, x, time+1, False])           
                            print("s")                 
    return result


for y in range(n):
    for x in range(n):
        if board[y][x] == 0: # 절벽인 경우
            col, row = 0, 0
            for k in range(4):
                ny = y + dy[k]     
                nx = x + dx[k]
                if 0 <= ny < n and 0 <= nx < n:
                    # 세로 확인
                    if k == 0 or k == 1:
                        if board[ny][nx] == 0:
                            col += 1
                    # 가로 확인
                    else:
                        if board[ny][nx] == 0:
                            row += 1
            if col >= 1 and row >= 1: # 절벽이 교차하는 지점
                continue
            candi.append([y,x])
        if board[y][x] >= 2: # 오작교 놓을 수 있음
            candi.append([y,x])
print(candi)            
for y, x in candi:
    board[y][x] = m # 해당 지점에 오작교를 1개 놓음
    print(y, x)
    answer = min(answer, bfs())
    board[y][x] = 0
    
print(answer)
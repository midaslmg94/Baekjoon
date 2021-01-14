import sys
sys.stdin = open("input.txt","r")
n, m = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(n)]
visited = [[False]*m for _ in range(n)]
answer = -1
dy = [0,0,1,-1]
dx = [1,-1,0,0]

def fuck_block(y, x):
    result = 0 
    #ㅗ (현재 좌표 ㅡ의 가운데)
    if y >= 1 and x >= 1 and x < m - 1:
        result = max(result, board[y][x - 1] + board[y][x] + board[y - 1][x] + board[y][x + 1]) 
    #ㅏ (현재 좌표 ㅣ의 가운데)
    if y >= 1 and y < n - 1 and x < m - 1:
        result = max(result, board[y - 1][x] + board[y][x] + board[y][x + 1] + board[y + 1][x]) 
    #ㅜ (현재 좌표 ㅡ의 가운데)
    if y >= 0 and y < n - 1 and x < m - 1:
        result = max(result, board[y][x - 1] + board[y][x] + board[y + 1][x] + board[y][x + 1]) 
    #ㅓ (현재 좌표 ㅣ의 가운데)
    if y >= 1 and y < n - 1 and x >= 1:
        result = max(result, board[y - 1][x] + board[y][x] + board[y][x - 1] + board[y + 1][x]) 

    return result

def dfs(y, x, count):       
    if count == 4: # 4개 블록을 다 골랐으면
        return board[y][x]
    result = 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0<=ny and ny<n and 0<=nx and nx<m and not visited[ny][nx]:
            visited[ny][nx] = True
            result = max(result, board[y][x] + dfs(ny, nx, count+1))
            visited[ny][nx] = False      
    return result
for i in range(n):
    for j in range(m):
        visited[i][j] = True
        answer= max(answer, dfs(i, j, 1))
        answer = max(answer, fuck_block(i, j))
        visited[i][j] = False
print(answer)
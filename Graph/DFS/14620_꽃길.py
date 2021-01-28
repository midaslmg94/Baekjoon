import sys
sys.stdin = open("input.txt", "r")

flower_dir = [(0,0),(-1,0),(1,0),(0,-1),(0,1)] # 현위치, 상, 하, 좌, 우

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
visited = [[False] * n for _ in range(n)]
answer = 987654321

def check(y, x):
    global n
    for dy, dx in flower_dir:
        ny = y + dy
        nx = x + dx
        if 0>ny or ny>n-1 or 0>nx or nx>n-1 or visited[ny][nx]:
            return False
    return True

def calculate(y, x):
    global n
    result = 0
    for dy, dx in flower_dir:
        ny = y + dy
        nx = x + dx
        result += board[ny][nx]
    return result


# 3개 꽃 고르기
# 서로 겹치지 않게 하기
# 오른쪽 끝까지 갔으면 다음 줄로 넘어갈 수 있도록 하기
def dfs(x, cost, cnt):
    global answer
    if cnt == 3:
        answer = min(answer, cost) 
        return    
    for i in range(x, n):
        for j in range(1, n):
            if check(i, j):
                visited[i][j] = True                
                for dy, dx in flower_dir:
                    visited[i+dy][j+dx] = True
                dfs(i, cost + calculate(i, j), cnt+1)
                visited[i][j] = False
                for dy, dx in flower_dir:
                    visited[i+dy][j+dx] = False
                
dfs(1, 0, 0)        
print(answer)
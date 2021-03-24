import sys, copy
sys.setrecursionlimit(10 ** 5)
from collections import deque
sys.stdin = open("input.txt", "r")
dy = [-1,1,0,0]
dx = [0,0,-1,1]

visited = set()

def maxIce(y, x):    
    visited.add((y, x))
    ret = 1
    for k in range(4):
        ny = y + dy[k]
        nx = x + dx[k]
        if 0<= ny < 2**N and 0 <= nx < 2**N:
            if (ny, nx) not in visited and board[ny][nx] > 0:
                ret += maxIce(ny, nx)   
    return ret
def melt():
    melt_ice = []
    for y in range(2**N):
        for x in range(2**N):
            ice = 0
            if board[y][x] == 0: 
                continue
            for k in range(4):
                ny = y + dy[k]
                nx = x + dx[k]
                if 0 <= ny < 2**N and 0 <= nx < 2**N :
                    if board[ny][nx] >= 1:
                        ice += 1
            if ice < 3:
                melt_ice.append([y, x])
    
    for y, x in melt_ice:
        board[y][x] -= 1
    return

def rotate(L):
    global board
    K = 2**L
    for i in range(0,2**N, K):
        for j in range(0, 2**N, K):
            new_board = [board[r][j:j+K] for r in range(i, i+K)]
            for y in range(K):
                for x in range(K):
                    board[i+x][j+K-1-y] = new_board[y][x]            
            
            
    # for r in range(2**N):
    #     for c in range(2**N):
    #         print(board[r][c], end=' ')
    #     print()
    # print("\n=============")
    #board = copy.deepcopy(new_board)
    
    return

N, Q = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(2**N)]
magic = list(map(int, input().split()))

for L in magic:
    rotate(L)
    melt()

# 남아있는 얼음의 총합
sumOfIce = 0
for i in range(2**N):
    for j in range(2**N):
        sumOfIce += board[i][j]

# 남아있는 얼음 중 가장 큰 덩어리가 차지 하는 칸의 개수
maxOfCnt = 0
cnt = 0
for y in range(2**N):
    for x in range(2**N):        
        if (y, x) not in visited and board[y][x] > 0:   
            maxOfCnt = max(maxOfCnt, maxIce(y, x))

print(sumOfIce)
print(maxOfCnt)
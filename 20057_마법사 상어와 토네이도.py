import sys, copy
sys.stdin = open("input.txt", "r")

dy = [0,1,0,-1] # 좌 하 우 상
dx = [-1,0,1,0]

# 흩날리는 모래의 비율
spreadPer = [ 
                [0,0,0.02,0,0],
                [0,0.1,0.07,0.01,0], 
                [0.05,0,0,0,0], 
                [0,0.1,0.07,0.01,0], 
                [0,0,0.02,0,0]
            ]

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

sy, sx = n//2, n//2 # 시작 좌표
moveA, moveB = 1, 2 # 진행방향으로 이동하는 칸 수
cnt = 1    # 이동 횟수
answer = 0


def Print():
    for i in range(n):
        for j in range(n):
            print(board[i][j], end=' ')
        print()
    print("\n======================\n")



def rotate(num): # 진행 방향에 맞게 흩날리는 모래의 비율 회전
    # zip함수를 쓰면 오른쪽으로 90도 회전이 되어서 4에서 num을 빼줌
    num = 4 - num # 왼쪽으로 90도로 회전: (0: 정방향, 1 : 90도, 2:180도, 3:270도)
    global spreadPer, tmpPer
    rotatePer = copy.deepcopy(spreadPer)
    for _ in range(num):
        tmpPer = []
        for item in zip(*rotatePer):
            tmpPer.append(list(reversed(item)))
        rotatePer = copy.deepcopy(tmpPer)
    #print(rotatePer)
    return rotatePer

def spread(y, x, dir):
    global board, answer
    my = [-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2]
    mx = [-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2]
    spread_sand = rotate(dir)
    ret = board[y][x] # 움직일 모래
    restSand = 0
    for i in range(25):        
        mmy = y + my[i]
        mmx = x + mx[i]
        if 0 > mmy or mmy > n-1 or 0 > mmx or mmx > n-1: # 모래가 범위를 벗어남 -> 정답에 추가
            answer += int(board[y][x] * spread_sand[my[i]][mx[i]])
        else: # 다른 칸에 모래가 쌓임
            board[mmy][mmx] += int(board[y][x] * spread_sand[my[i]][mx[i]])            
        ret -= int(board[y][x] * spread_sand[my[i]][mx[i]])
    # 진행방향으로 1칸 더 간 곳에 모래가 쌓임
    ny = y+dy[dir]
    nx = x+dx[dir]
    if 0<=ny<n and 0<=nx<n:
        board[ny][nx] += ret
    board[y][x] = 0

def move(dir):
    global sy, sx, cnt
    sy += dy[dir]
    sx += dx[dir]
    cnt += 1    
    spread(sy, sx, dir)
    #Print()
    if cnt == n**2:
        exit(0)

while True:
    for _ in range(moveA): # 왼쪽으로 이동 : 1, 3, 5 .. 칸 움직임       
        move(0)
    for _ in range(moveA): # 아래쪽으로 이동 : 1, 3, 5 .. 칸 움직임
        move(1)
    for _ in range(moveB): # 오른쪽으로 이동 : 2, 4, 6 .. 칸 움직임
        move(2)
    for _ in range(moveB): # 위쪽으로 이동 : 2, 4, 6 .. 칸 움직임
        move(3)
    moveA += 2
    moveB += 2


print(answer)
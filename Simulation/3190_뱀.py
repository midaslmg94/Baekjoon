import sys
from collections import deque
sys.stdin = open("input.txt", "r")

dy = [0,1,0,-1] # 우 하 좌 상. 오른쪽으로 도는 모양. 왼쪽으로 돌려면 (dir+3) % 4
dx = [1,0,-1,0] 

n = int(input())
k = int(input())
board = [[0]*(n+1) for _ in range(n+1)] # 1:사과, -1: 빈자리
cmd = [' ' for _ in range(10001)]
snake = deque()
for _ in range(k):
    y, x = map(int, input().split())
    board[y][x] = 1

l = int(input())
oper = deque()
for _ in range(l):
    t, d = map(str, input().split())
    cmd[int(t)] = d
 
d = 0 # 진행 방향
time = 0
snake.append((1,1))
board[1][1] = -1
while True:    
    time += 1
    head_y, head_x = snake[0]    
    head_y = head_y + dy[d]
    head_x = head_x + dx[d]

    # 범위 벗어남 또는 자기의 일부분과 마주침 -> 종료
    if 1 > head_y or head_y > n or 1 > head_x or head_x >n or board[head_y][head_x] == -1: 
        break

    if board[head_y][head_x] == 1: # 사과 : 길이가 늘어남
        snake.appendleft((head_y, head_x))
        board[head_y][head_x] = -1      
    else: # 빈 칸 : 꼬리가 하나 줄어들음
        snake.appendleft((head_y, head_x))
        tail_y, tail_x = snake.pop()
        board[tail_y][tail_x] = 0
        board[head_y][head_x] = -1

    if cmd[time] == 'D':
        d = (d+1) % 4
    if cmd[time] == 'L':
        d = (d+3) % 4
print(time)
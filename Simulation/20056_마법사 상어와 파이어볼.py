import sys, copy
from collections import deque

sys.stdin = open("input.txt", "r")
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]

n, m, k = map(int, input().split())
board = [[deque() for _ in range(n)] for _ in range(n)]


def Print():
    for i in range(n):
        for j in range(n):
            print(board[i][j], end=' ')
        print()
    print("-----------------------")
    print()


for i in range(m):
    r, c, m, s, d = map(int, input().split())
    board[r-1][c-1].append([m, s, d])

for _ in range(k):    
    # 이동하는 중에는 같은 칸에 여러 개의 파이어볼이 있을 수도 있다.
    #Print()
    new_board = [[deque() for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            while len(board[i][j]) > 0: # 이 부분이 if로 되어 있어서 파이어볼을 1개만 처리했었다
                next_y, next_x = i, j
                cur_m, cur_s, cur_d = board[i][j].popleft()
                next_y = (next_y + (cur_s * dy[cur_d])) % n
                next_x = (next_x + (cur_s * dx[cur_d])) % n
                # for _ in range(cur_s): # 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.    
                #     next_y = (next_y + dy[cur_d]) % n
                #     next_x = (next_x + dx[cur_d]) % n
                new_board[next_y][next_x].append([cur_m, cur_s, cur_d])
    board = copy.deepcopy(new_board)    
    # 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
    for i in range(n):
        for j in range(n):
            isEven, isOdd = False, False 
            sumMass, sumSpeed = 0, 0 # 합쳐진 파이어볼의 질량, 속도
            newMass, newSpeed = 0, 0 # 나누어져 새로 만들어진 파이어볼의 질량, 속도
            if len(board[i][j]) >= 2:                
                lenBall = len(board[i][j])
                while board[i][j]:
                    curMass, curSpeed, curDir = board[i][j].popleft()
                    sumMass += curMass
                    sumSpeed += curSpeed
                    if curDir % 2 == 0:
                        isEven = True
                    else:
                        isOdd = True           
                newMass = sumMass // 5  # 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
                newSpeed = sumSpeed // lenBall # 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
                if newMass == 0:    # 질량이 0인 파이어볼은 소멸되어 없어진다.
                    continue
                # 파이어볼은 4개의 파이어볼로 나누어진다.
                # 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
                if isEven == True and isOdd == True: # 방향이 홀수, 짝수가 섞여 있음 -> 방향이 1, 3, 5, 7
                    for newDir in range(1, 8, 2):
                        board[i][j].append([newMass, newSpeed, newDir])
                else:
                    for newDir in range(0, 8, 2):
                        board[i][j].append([newMass, newSpeed, newDir])           

answer = 0
for i in range(n):
    for j in range(n):
        if len(board[i][j]):
            for ball in board[i][j]:
                answer += ball[0]

print(answer)
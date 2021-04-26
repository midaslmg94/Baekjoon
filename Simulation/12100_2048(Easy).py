import copy
import sys
from itertools import product

sys.stdin = open("../input.txt", "r")

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
candi = list(product('LRUD', repeat=5))  # 최대 5번 움직임
answer = 0


def tilting(board, dir):
    checked = set()  # 이미 한번 합쳐진 블록
    if dir == 'L':  # 왼쪽으로 기울이기
        for i in range(n):
            for j in range(1, n):
                if board[i][j] == 0: continue
                y = i
                x = j
                while True:
                    x -= 1
                    if x < 0:
                        break
                    if board[y][x] != 0:
                        if (y, x) in checked:  # 이미 한번 합쳐진 블록이 있음
                            board[y][x + 1] = board[i][j]
                            board[i][j] = 0
                        elif board[y][x] == board[i][j]:  # 겹치는 블록과 합치기 가능
                            board[i][j] += board[y][x]
                            board[y][x] = board[i][j]
                            board[i][j] = 0
                            checked.add((y, x))
                        else:  # 겹치는 블록과 합치기 불가
                            if board[y][x] != 0:
                                board[y][x + 1] = board[i][j]
                            else:
                                board[y][x + 1] = board[i][j]
                                board[i][j] = 0
                        break

    elif dir == 'R':  # 오른쪽으로 기울이기
        for i in range(n):
            for j in range(n - 1):
                if board[i][j] == 0: continue
                y = i
                x = j
                while True:
                    x += 1
                    if x >= n:
                        break
                    if board[y][x] != 0:
                        if (y, x) in checked:  # 이미 한번 합쳐진 블록이 있음
                            board[y][x - 1] = board[i][j]
                            board[i][j] = 0
                        elif board[y][x] == board[i][j]:  # 겹치는 블록과 합치기 가능
                            board[i][j] += board[y][x]
                            checked.add((y, x))
                        else:  # 겹치는 블록과 합치기 불가
                            if board[y][x] != 0:
                                board[y][x - 1] = board[i][j]
                            else:
                                board[y][x - 1] = board[i][j]
                                board[i][j] = 0
                        break
    elif dir == 'U':  # 위쪽으로 기울이기
        for i in range(1, n):
            for j in range(n):
                if board[i][j] == 0: continue
                y = i
                x = j
                while True:
                    y -= 1
                    if y < 0:
                        break
                    if board[y][x] != 0:
                        if (y, x) in checked:  # 이미 한번 합쳐진 블록이 있음
                            board[y + 1][x] = board[i][j]
                            board[i][j] = 0
                        elif board[y][x] == board[i][j]:  # 겹치는 블록과 합치기 가능
                            board[i][j] += board[y][x]
                            checked.add((y, x))
                        else:  # 겹치는 블록과 합치기 불가
                            if board[y][x] != 0:
                                board[y + 1][x] = board[i][j]
                            else:
                                board[y + 1][x] = board[i][j]
                                board[i][j] = 0
                        break
    else:  # 아래로 기울이기
        for i in range(n - 1):
            for j in range(n):
                if board[i][j] == 0: continue
                y = i
                x = j
                while True:
                    y += 1
                    if y >= n:
                        break
                    if board[y][x] != 0:
                        if (y, x) in checked:  # 이미 한번 합쳐진 블록이 있음
                            board[y - 1][x] = board[i][j]
                            board[i][j] = 0
                        elif board[y][x] == board[i][j]:  # 겹치는 블록과 합치기 가능
                            board[i][j] += board[y][x]
                            checked.add((y, x))
                        else:  # 겹치는 블록과 합치기 불가
                            if board[y][x] != 0:
                                board[y - 1][x] = board[i][j]
                            else:
                                board[y - 1][x] = board[i][j]
                                board[i][j] = 0
                        break
    return board


def moveBoard(candi):
    tmp_board = copy.deepcopy(board)
    global answer
    for item in candi:
        tmp_board = tilting(tmp_board, item)
        for i in range(n):
            for j in range(n):
                answer = max(answer, tmp_board[i][j])
    # print(*tmp_board)


for item in candi:
    moveBoard(item)
print(answer)

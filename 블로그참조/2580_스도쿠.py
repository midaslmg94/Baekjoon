import sys
sys.stdin = open("input.txt", "r")
board = [list(map(int, input().split())) for _ in range(9)]
emptySpace = [(i, j) for i in range(9) for j in range(9) if board[i][j] == 0]


def candidating(y, x):  # 빈칸에 들어갈 수 있는 숫자 후보 : 스도쿠 규칙에 따라 가로,세로,3x3 칸 내에 겹치는 숫자가 없어야 함
    numbers = [i+1 for i in range(9)]
    # 행 / 열 검사
    for k in range(9):
        if board[y][k] in numbers:
            numbers.remove(board[y][k])
        if board[k][x] in numbers:
            numbers.remove(board[k][x])
    # 3*3 검사
    y = y//3
    x = x//3
    for i in range(y*3, (y+1)*3):
        for j in range(x*3, (x+1)*3):
            if board[i][j] in numbers:
                numbers.remove(board[i][j])
    return numbers


def dfs(count):
    if count == len(emptySpace):
        for row in board:
            print(*row)
        return
    (i, j) = emptySpace[count]
    candi = candidating(i, j)  # 빈칸에 들어갈 수 있는 숫자 후보
    for num in candi:
        board[i][j] = num
        dfs(count+1)
        board[i][j] = 0


dfs(0)

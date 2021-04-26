import sys
from collections import defaultdict

sys.stdin = open("../input.txt", "r")
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, -1, -1, -1, 0, 1, 1, 1]
board = [[0] * 4 for _ in range(4)]
#fish = defaultdict(list)
fish = []
shark = []


def _print():
    for i in range(4):
        for j in range(4):
            print(board[i][j], end=' ')
        print()


def _input():
    for i in range(4):
        _input = list(map(int, input().split()))
        for j in range(4):  # 현재 물고기의 번호, 방향 저장
            board[i][j] = [_input[j * 2], _input[j * 2 + 1] - 1]
            #fish[_input[j * 2]].append([_input[j * 2 + 1] - 1, i, j])
            fish.append([_input[j*2], _input[j*2+1]-1, i, j]) # 번호, 방향, y, x
    fish.sort(key= lambda x: x[0]) # 번호순 정렬
    print(fish)
    return


def moveFish():
    # global board
    for fishIdx, fishDir, y, x in fish:
        print(fishIdx)
        print("===================== 이동 전 ")
        _print()
        for k in range(8):
            ny = y + dy[(fishDir + k) % 8]  # 45도 회전
            nx = x + dx[(fishDir + k) % 8]
            if 0 > ny or ny > 3 or 0 > nx or nx > 3:  # 범위 초과
                continue
            if board[ny][nx][0] == -1:  # 상어가 있음
                continue
                # 비어있거나 물고기가 있는경우 : 둘의 위치 바꿈
            board[y][x], board[ny][nx] = board[ny][nx], board[y][x]
            break
        print("이동 후 ")
        _print()
    return


def moveShark(y, x, ret):
    moveFish()
    return


def solve():
    shark.append([0, 0])
    fishNum = board[0][0][0]
    print(fishNum)
    fish[fishNum] = 0
    moveShark(0, 0, 0)
    return


_input()
solve()

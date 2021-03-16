import sys
from collections import deque

n, m = map(int, input().split())
board = [list(map(str, input().rstrip())) for _ in range(n)]
#visited = [[False] * m for _ in range(n)]
visited = [[[[False] * m for _ in range(n)] for _ in range(m)] for _ in range(n)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

_red = []
_blue = []
_goal = []

def bfs(red, blue):
    queue = deque()
    result = -1
    ry, rx = red[0]
    by, bx = blue[0]
    queue.append([ry, rx, by, bx, 0])
    visited[ry][rx][by][bx] = True
    while queue:
        ry, rx, by, bx, turn = queue.popleft()
        if turn > 10:
            break
        if board[ry][rx] == 'O' and board[by][bx] != 'O':  # 빨강구슬만 탈출
            result = turn
            break
        for k in range(4):
            ny_red = ry
            nx_red = rx
            ny_blue = by
            nx_blue = bx
            while True:  # 빨간 구슬 이동
                if board[ny_red][nx_red] != '#' and board[ny_red][nx_red] != 'O':
                    ny_red += dy[k]
                    nx_red += dx[k]
                else:
                    if board[ny_red][nx_red] == '#':
                        ny_red -= dy[k]
                        nx_red -= dx[k]
                    break

            while True:  # 파란 구슬 이동
                if board[ny_blue][nx_blue] != '#' and board[ny_blue][nx_blue] != 'O':
                    ny_blue += dy[k]
                    nx_blue += dx[k]
                else:
                    if board[ny_blue][nx_blue] == '#':
                        ny_blue -= dy[k]
                        nx_blue -= dx[k]
                    break

            if ny_red == ny_blue and nx_red == nx_blue:  # 두 구슬이 겹친 경우
                if board[ny_red][nx_red] != 'O':
                    dist_red = abs(ny_red - ry) + abs(nx_red - rx)
                    dist_blue = abs(ny_blue - by) + abs(nx_blue - bx)
                    if dist_red < dist_blue:  # 파란 구슬이 더 많이 이동
                        ny_blue -= dy[k]
                        nx_blue -= dx[k]
                    else:
                        ny_red -= dy[k]
                        nx_red -= dx[k]
            # if visited[ny_red][nx_red] == False or visited[ny_blue][nx_blue] == False:
            #     queue.append([ny_red, nx_red, ny_blue, nx_blue, turn + 1])
            #     print("sss")
            #     visited[ny_red][nx_red] = True
            #     visited[ny_blue][nx_blue] = True
            if visited[ny_red][nx_red][ny_blue][nx_blue] is False:
                queue.append([ny_red, nx_red, ny_blue, nx_blue, turn + 1])
                visited[ny_red][nx_red][ny_blue][nx_blue] = True
    return result


for i in range(n):
    for j in range(m):
        if board[i][j] == 'R':
            _red.append([i, j])
        elif board[i][j] == 'B':
            _blue.append([i, j])

answer = bfs(_red, _blue)
print(answer)
import sys
from collections import deque

sys.stdin = open("../input.txt", "r")

N, K = map(int, input().split())
belt = deque(map(int, input().split()))
robot = deque([0] * N) # 2N이 아닌 이유?
up = 0  # 올라가는 위치
down = N - 1 # 내려가는 위치
zero_count = 0  # 내구도가 0인 칸의 개수
answer = 0
while zero_count < K:
    answer += 1
    # 벨트 한 칸 회전, 로봇도 같이 이동
    belt.rotate(1)
    robot.rotate(1)
    robot[down] = 0     # 내려가는 위치는 삭제

    # 로봇 이동
    for i in range(down-1, 0, -1):
        if robot[i]:
            if robot[i+1] == 0 and belt[i+1] > 0:
                # 떨어지는 칸이 아니라면 이동
                if i+1 != down:
                    robot[i+1] = robot[i]
                robot[i] = 0
                belt[i+1] -= 1
                if belt[i+1] == 0:
                    zero_count += 1
    # 로봇 올림
    if belt[0] > 0 and robot[0] == 0:
        belt[0] -= 1
        robot[0] = answer
        if belt[0] == 0:
            zero_count += 1
print(answer)

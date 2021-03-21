import sys, copy
from collections import deque
sys.stdin = open("input.txt", "r")

n, k = map(int, input().split())
belt = list(map(int, input().split()))
robot = [0 for _ in range(2*n)]
robot_deq = deque()
time = 0
while True:    
    time += 1   
    # 벨트 한칸 회전 -> 올라온 로봇도 같이 이동, 내구도 감소 X
    tmp_belt = copy.deepcopy(belt)
    tmp_robot = copy.deepcopy(robot)
    for i in range(len(tmp_belt)):
        tmp_belt[i] = belt[(i-1) % len(belt)]
        tmp_robot[i] = robot[(i-1) % len(robot)]
        if i == n-1: # n-1에 올라가면 로봇 내려감
            tmp_robot[i] = 0
    belt = copy.deepcopy(tmp_belt)
    robot = copy.deepcopy(tmp_robot)

    # 로봇 이동 -> 내구도 -1씩 감소, 내리는 위치면 로봇 내려감
    move_robot = copy.deepcopy(robot)
    for i in range(len(robot)-1, -1, -1):
        if belt[i] == 0 or robot[i] == 1: # 다음칸이 내구도가 0 이거나 로봇이 있으면 로봇 이동 불가
            continue        
        move_robot[i] = robot[(i-1) % len(robot)]
        if i == n-1: # 로봇이 내리는 위치
            move_robot[i] = 0
        belt[i] -= move_robot[i]
    robot = copy.deepcopy(move_robot)

    # 로봇 새롭게 올리기
    if robot[0] == 0 and belt[0] > 0:
        robot[0] = 1
        belt[0] -= 1

    # 내구도 확인
    ret = 0
    for i in belt:
        if i == 0:
            ret += 1
    if ret >= k:
        break
print(time)


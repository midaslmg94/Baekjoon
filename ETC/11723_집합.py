import sys

s = set()
n = int(input())

for _ in range(n):
    tmp = sys.stdin.readline().strip().split()
    if len(tmp) == 1:
        command = tmp[0]
        if command == "all":
            s = set([j for j in range(1,21)])
        elif command == "empty":
            s = set()
    else:
        command, value = tmp[0], tmp[1]
        value = int(value) # 정수형으로 바꿔주는 것 잊지말기
        if command == "add":
            s.add(value)
        elif command == "remove":
            if value in s:
                s.discard(value)
        elif command == "check":
            if value in s:
                print(1)
            else:
                print(0)
        elif command == "toggle":
            if value in s:
                s.discard(value)
            else:
                s.add(value)


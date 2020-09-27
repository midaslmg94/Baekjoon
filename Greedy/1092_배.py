import sys
read = sys.stdin.readline

N = int(read())
crane = list(map(int, read().split()))
M = int(read())
box = list(map(int, read().split()))

crane.sort(reverse=True)
box.sort(reverse=True)

if max(box) > max(crane):  # 담을 수 없는 경우
    print(-1)
    sys.exit()
else:
    answer = 0
    while(True):
        if not box: break  # 박스가 비어있지 않는 동안 실행
        for i in range(len(crane)):
            for j in range(len(box)):
                if crane[i] >= box[j]:
                    del box[j]
                    break
        answer += 1
print(answer)
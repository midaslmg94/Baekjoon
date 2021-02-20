import sys
n = int(input())
solutionList = list(map(int, input().split()))
solutionList.sort()
p1, p2, p3 = 0,0,0
ans_p1, ans_p2, ans_p3 = 0,0,0
answer = sys.maxsize
for i in range(n):
    p1, p2 = 0, n-1
    p3 = i    
    while p1 < p2:
        if p1 == p3: # 같은 용액을 2번 고르는 경우 방지
            p1 += 1
        if p2 == p3:
            p2 -=1
        if p1 == p2:
            break
        result = solutionList[p1] + solutionList[p2] + solutionList[p3]
        if abs(result) < answer: # 절대값이 작은게 0에 가까운 값
            ans_p1 = p1
            ans_p2 = p2
            ans_p3 = p3
            answer = abs(result)
        if result < 0: 
            p1 += 1
        elif result > 0:
            p2 -= 1
        else: # 세 용액의 합이 0이 된 경우. 정답  
            answer = [solutionList[ans_p1], solutionList[ans_p2], solutionList[ans_p3]]
            print(*sorted(answer))
            exit(0)    
answer = [solutionList[ans_p1],solutionList[ans_p2],solutionList[ans_p3]]
print(*sorted(answer))
import sys
sys.stdin = open("input.txt","r")

n, k = map(int, input().split())
dolls = list(map(int, input().split()))

answer = 100000000

lion = []
for i in range(len(dolls)):
    if dolls[i] == 1:
        lion.append(i)
        
# 윈도우의 크기 = end - start = 라이언 인형의 개수
start = 0
end = k-1
if len(lion) < k: # 라이언의 개수가 K개 미만임 -> -1 출력 후 종료
    print(-1)
    exit(0)

while True:
    doll = lion[end] - lion[start] + 1 
    answer = min(answer, doll)
    if end == len(lion)-1: # 마지막까지 탐색 완료
        break
    start += 1 
    end += 1
print(answer)
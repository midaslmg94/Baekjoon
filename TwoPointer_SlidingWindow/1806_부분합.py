import sys
sys.stdin = open("input.txt", "r")
# 투 포인터로 풀기
n,s = map(int, input().split())
_list = list(map(int, input().split()))

start, end, cur = 0, 0, 0
answer = 987654321

while True:    
    if cur >= s:
        answer = min(answer, end - start)
        cur -= _list[start]
        start += 1
    elif end == n:
        break
    else:
        cur += _list[end]
        end += 1
if answer == 987654321:
    answer = 0        
print(answer)


# 부분합으로 풀기
n,s = map(int, input().split())
_list = list(map(int, input().split()))
prefix = [0]*(n+1)
start, end = 0, 1

for i in range(1, n+1):
    prefix[i] = prefix[i-1] + _list[i-1]

answer = 1000001
while start < n:
    if prefix[end] - prefix[start] >= s:
        answer = min(answer, end-start)        
        start += 1
    else:
        if end < n:
            end += 1
        else:
            start += 1
   
if answer == 1000001:
    answer = 0        
print(answer)
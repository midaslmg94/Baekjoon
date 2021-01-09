import sys
sys.stdin = open("input.txt", "r")

H, W = map(int,input().split())
blocks = list(map(int, input().split()))

answer = 0
def rainning(n):    
    max_left = -100001
    max_right = -100001
    # 해당 칸 보다 왼쪽 지점 중 가장 큰 값을 찾음
    for i in range(n):
        max_left = max(max_left, blocks[i])
    # 해당 칸 보다 오른쪽 지점 중 가장 큰 값을 찾음
    for i in range(n+1, len(blocks)):
        max_right = max(max_right, blocks[i])
    
    result = [max_left, max_right]
    return result


for i in range(1, len(blocks)-1): # 양 끝은 빗물이 쌓일 수 없음
    left, right = rainning(i)
    if blocks[i] >= left or blocks[i] >= right: continue # 가장 높은곳은 빗물이 안고임
    answer += min(left, right) - blocks[i]   
print(answer)
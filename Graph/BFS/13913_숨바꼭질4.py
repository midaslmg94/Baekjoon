from collections import deque
import sys
sys.stdin = open("input.txt", "r")

n,k = map(int, input().split())

visited = [-1]*100001
path = [] # 지금까지 방문 경로 저장
def bfs(start, target):
    queue = deque() 
    queue.append((n,0))
    visited[start] = start
    while queue:
        cur, cur_time = queue.popleft()        
        if cur == target:  # 동생을 찾음
            idx = cur
            while idx != start:
                path.append(idx)
                idx = visited[idx] # 이 부분을 잘 모르겠다.
            path.append(start)
            return cur_time
        if cur+1 < 100001 and visited[cur+1] == -1 :
            queue.append((cur+1,cur_time+1))
            visited[cur+1] = cur
             
        if cur-1 >= 0 and visited[cur-1] == -1 :
            queue.append((cur-1,cur_time+1))
            visited[cur-1] = cur
            
        if cur*2 < 100001 and visited[cur*2] == -1 :
            queue.append((cur*2,cur_time+1))
            visited[cur*2] = cur


print(bfs(n,k))
print(*path[::-1]) # 뒤에서 부터 출력
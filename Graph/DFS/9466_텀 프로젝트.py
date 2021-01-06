import sys
sys.setrecursionlimit(111111) # 재귀 깊이 설정

sys.stdin = open("input.txt", "r")

def dfs(cur):   
    global cnt, visited, done
    visited[cur] = True
    nextNode = student_mate[cur]
    if not visited[nextNode]: # 다음 노드를 방문하지 않았다면 방문
        dfs(nextNode)
    else: 
        if not done[nextNode]: # 사이클이 형성되었다.
            i = nextNode
            while i != cur: # 팀원들을 모두 센다
                cnt += 1 
                i = student_mate[i]
            cnt+=1 # 자기 자신을 센다
    done[cur] = True 

for _ in range(int(input())): # 테스트 케이스 반복하며 실행
    n = int(input())    
    student_mate = list(map(lambda x : int(x)-1, input().split()))
    visited = [False]*n  # 방문 체크 배열
    done = [False]*n  # 팀 매칭 여부(사이클 존재 여부)
    cnt = 0
    for i in range(n):
        if not visited[i]:
            dfs(i)   
    print(n-cnt)
    
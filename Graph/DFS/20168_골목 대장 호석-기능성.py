import sys
sys.stdin = open("input.txt", "r")

n, m, a, b, c = map(int, input().split())

board = [[] for _ in range(n+1)]
visited = [[False] for _ in range(n+1)]
answer = sys.maxsize    

def dfs(start, end, cost, maxShame):
    visited[start] = True
    global answer
    if start == end:
        answer = min(answer, maxShame)
        return
    for item in board[start]:
        nextNode = item[0]
        nextCost = item[1]
        if visited[nextNode] == True: continue
        if nextCost > cost: continue
        visited[nextNode] = True        
        dfs(nextNode, end, cost - nextCost, max(maxShame, nextCost))
        visited[nextNode] = False

for _ in range(m):
    n1, n2, cost = map(int, input().split())        
    board[n1].append((n2, cost))
    board[n2].append((n1, cost))

dfs(a,b,c,0)
if answer == sys.maxsize:
    answer = -1
print(answer)


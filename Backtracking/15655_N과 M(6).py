# 조합 
n, m = map(int, input().split())
data = list(map(int, input().split()))
data.sort()
result = []
checked = [False]*n
def dfs(idx, count):
    if count == m:        
        print(*result)
        return
    for i in range(idx, len(data)):
        if checked[i] == True: continue
        checked[i] = True
        result.append(data[i])
        dfs(i, count+1)
        result.pop()
        checked[i] = False
    
    
dfs(0, 0)
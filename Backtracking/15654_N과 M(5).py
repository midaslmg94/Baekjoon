n, m = map(int, input().split())
data = list(map(int, input().split()))
data.sort()
checked = [False]*n
result = [0]*m

def dfs(count):
    if count == m:
        print(*result)
        return
    for i in range(len(data)):
        if checked[i] == True: continue
        checked[i] = True
        result[count]=data[i]
        dfs(count+1)
        checked[i] = False
 
 
dfs(0)
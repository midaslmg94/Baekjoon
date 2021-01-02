n, m = map(int, input().split())
result = []
def dfs(idx, count):
    if count == m:
        print(*result)
        return
    for i in range(idx, n):
        result.append(i+1)
        dfs(i, count+1)
        result.pop()

dfs(0, 0)
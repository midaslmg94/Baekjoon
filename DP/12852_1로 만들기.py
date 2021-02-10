x = int(input())
dp = [0]*(x+1)
before_path = [0]*(x+1)

dp[1] = 0
before_path[1] = -1

for i in range(2,x+1):
    dp[i] = dp[i-1] + 1
    before_path[i] = i-1
    if i%2==0 and dp[i] > dp[i//2]+1:
        dp[i] = dp[i//2]+1
        before_path[i] = i//2
    if i%3==0 and dp[i] > dp[i//3]+1:
        dp[i] = dp[i//3]+1
        before_path[i] = i//3

print(dp[x])
while x != -1:
    print(x, end=' ')
    x = before_path[x]


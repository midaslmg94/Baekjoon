import sys, math

#에라토스테네스의 체
prime = [True]*(1005000) 
prime[1] = False # 1은 소수가 아님
m = int(math.sqrt(1005000))
for i in range(2, m+1):
    if prime[i] == True:
        for j in range(i+i, 1005000, i):
            prime[j] = False  

# 소수 판별 알고리즘 : 제곱근까지 구하기
def isPrime(x):
    if x == 1:
        return False
    for i in range(2, int(math.sqrt(x))+1):
        if x % i == 0:
            return False
    return True
    
    
def isPalindrome(x):
    x = str(x)
    tmp = x[::-1]
    if x == tmp:
        return True
    else:
        return False

n = int(input())
while True:
    if isPalindrome(n):
        if isPrime(n):
            print(n)
            exit(0)
    n += 1
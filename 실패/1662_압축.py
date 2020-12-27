''' 
https://jaimemin.tistory.com/1264
블로그를 참조하여 재귀로 풀려고 했지만, 정답이 다르게 나온다
어느 부분이 틀린지 모르겠다.
'''

s = input()
stack = []
visited = [0 for i in range(50)]

def func(start, end):
    result = 0    
    for i in range(start, end):
        if s[i] == '(':
            repeatNum = int(s[i-1]) # 여는 괄호 바로 앞에 있는 숫자만큼 반복           
            result += repeatNum * func(i+1, visited[i]) - 1            
            i = visited[i] # 닫힌 괄호 다음으로 넘어감
            continue
        result+=1
    return result

# 괄호 쌍 인덱스 전처리 
for i in range(len(s)):
    if s[i]=='(':
        stack.append(i)
    elif s[i]==')':
        visited[stack[-1]] = i
        stack.pop()
print(func(0, len(s)))
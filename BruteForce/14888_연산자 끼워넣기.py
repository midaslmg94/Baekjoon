from itertools import permutations

n = int(input())
numbers = list(map(int, input().split()))
#  차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수
_sum, _sub, _mul, _div = map(int, input().split())
s = '+'*_sum + '-'*_sub + '*'*_mul + "/"*_div
operators = list(s)
answer = 0
permu_operators = list(permutations(operators, len(operators)))

max_value = -2e9
min_value = 2e9

for oper in permu_operators:
    result = numbers[0]
    idx = 1
    for item in oper:
        if item == '+':
            result += numbers[idx]
        elif item == '-':
            result -= numbers[idx]
        elif item == '*':
            result *= numbers[idx]
        elif item == '/':
            if result < 0 : # 음수일 경우
                result = -(result)
                result = result // numbers[idx]
                result = -(result)
            else:
                result = result // numbers[idx]
        idx += 1
    max_value = max(max_value, result)
    min_value = min(min_value, result)
    
print(max_value)
print(min_value)
        
    



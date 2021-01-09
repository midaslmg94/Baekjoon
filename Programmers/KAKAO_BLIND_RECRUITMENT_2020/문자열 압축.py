def cal(arr):
    result = ''
    num = 1
    #print("in func : ", arr)
    for i in range(len(arr)-1):
        if arr[i] == arr[i+1]:
            num+=1 
        else:
            if num == 1: result += arr[i]
            else: result += str(num)+arr[i]
            num = 1
    if num == 1: result += arr[len(arr)-1]
    else: result += str(num)+arr[len(arr)-1]
    return result

def solution(s):
    answer = len(s) # 압축을 아예 못하는 경우    
    # 길이가 정해짐 2...n/2 까지 탐색
    for length in range(1, (len(s)//2)+1):
        tmp = []
        for i in range(0, len(s), length):
            tmp.append(s[i:i+length])        
        res = cal(tmp)
        answer = min(len(res), answer)
        #print(res)
    return answer
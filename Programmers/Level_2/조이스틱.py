import string
# 실패 https://programmers.co.kr/learn/courses/30/lessons/42860
def solution(name):
    answer = 0
    idx = 0
    alpha = list(string.ascii_uppercase)
    curName = 'A'*len(name)
    diff_alpha = 0 # 알파벳 차이 (상, 하 커서)
    diff_idx = 0 # 커서 이동 차이(좌, 우 커서)
    while True:        
        if curName == name: 
            break
        if curName[idx] != name[idx]:
            diff_alpha = abs(ord(curName[idx])- ord(name[idx])) # ord : 문자 -> 아스키코드
            if diff_alpha >= 13: # 위, 아래 커서 선택 : 알파벳 차이가 13이상 나면 이전 알파벳(아래 커서)으로 탐색하는게 더 빠름
                diff_alpha = 26 - diff_alpha 
                
                
            if len(name) - (idx - diff_idx) < (idx - diff_idx): # 여기까지 오는데 좌, 우 커서중 더 적게 걸리는 것 선택
                answer += len(name) - (idx - diff_idx)                
            else:
                answer += (idx - diff_idx)
            answer += diff_alpha   
            diff_idx = idx
            curName = list(curName)
            curName[idx] = name[idx]
            curName = ''.join(curName)
        #print(curName, answer)
        idx += 1
    return answer
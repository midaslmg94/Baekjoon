def solution(S):
    ans = 0
    if "aaa" in S:
        return -1
    if S[0] != 'a':
        S = "aa"+S
        ans += 2
    if S[len(S)-1] != 'a':
        S = S + "aa"
        ans += 2
    for i in range(len(S)-3):
        tmp = S[i:i+3]
        if "aa" in tmp:
            continue
        elif 'a' not in tmp:
            
            ans+=4
        elif tmp[0] == 'a':

        elif tmp[1] == 'a':
        else



    return ans
s = "dog"
print(solution(s))
import bisect
from collections import defaultdict

def solution(words, queries):
    answer = []
    # value를 list로 할 것이므로 defaultdict를 사용해서 value를 list로 초기화한다
    forward = defaultdict(list)
    backward = defaultdict(list)
    
    # key:문자의 길이, value:문자 
    for word in words:
        forward[len(word)].append(word)
        backward[len(word)].append(word[::-1]) # 와일드카드가 접미사에 붙은 경우 
    
    # 문자를 사전순으로 정렬
    for f_word in forward.values():
        f_word.sort()
    for b_word in backward.values():
        b_word.sort()
        
    for query in queries:           
        if query[0] == '?': # 접두사 -> 역순으로 정렬된 리스트에서 이분탐색    
            query = query[::-1]
            le = bisect.bisect_left(backward[len(query)], query.replace('?', 'a'))
            ri = bisect.bisect_left(backward[len(query)], query.replace('?', 'z'))
        else: # 접미사
            le = bisect.bisect_left(forward[len(query)], query.replace('?', 'a'))
            ri = bisect.bisect_left(forward[len(query)], query.replace('?', 'z'))   
        answer.append(ri-le)        
    return answer
import heapq
def solution(operations):
    answer = []
    heap = []
    for item in operations:
        oper = item.split()[0]
        oper_num = int(item.split()[1])
        if oper == 'I':
            heap.append(oper_num)
        else:
            if len(heap)==0:
                continue
            elif oper_num == 1: # 최댓값 삭제
                heapq._heapify_max(heap)
                heapq._heappop_max(heap)
            else:
                heapq.heapify(heap)
                heapq.heappop(heap)
    if len(heap) == 0:
        answer = [0,0]
    else:
        heapq._heapify_max(heap)
        max_num = heapq._heappop_max(heap)
        
        heapq.heapify(heap)
        min_num = heapq.heappop(heap)
        answer = [max_num, min_num]
    return answer
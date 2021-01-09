from collections import deque
import math
def solution(progresses, speeds):
    answer = []
    completed = []
    for i in range(len(progresses)):
        days = (100 - progresses[i])/speeds[i]
        completed.append(math.ceil(days))
    queue = deque()
    for i in range(len(completed)):
        if not queue:
            queue.append(completed[i])
        elif queue[0]<completed[i]: # 해당 작업까지만 배포 가능
            answer.append(len(queue))
            queue.clear()
            queue.append(completed[i])
        else: # 다음 작업도 함께 배포 가능
            queue.append(completed[i])              
        
    answer.append(len(queue))
    # print(answer)
    # print(len(queue))
    return answer
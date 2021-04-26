import sys
from sys import stdin
from collections import defaultdict
sys.stdin = open("../input.txt", "r")

n, k = map(int, stdin.readline().rstrip().split())
_list = list(map(int, stdin.readline().rstrip().split()))
_dict = defaultdict(int)
_dict[_list[0]] = 1
start = 0
end = 1
answer = 1
while end < n:
    if _dict[_list[end]] < k:  # 수열에 포함되는 정수가 k개 미만, 두번째 포인터(end)가 리스트의 마지막에 도달할 때 까지.
        _dict[_list[end]] += 1
        end += 1
        answer = max(answer, end - start)
    else:
        _dict[_list[start]] -= 1
        start += 1
print(answer)

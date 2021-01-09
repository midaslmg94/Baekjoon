import sys
sys.stdin = open("input.txt", "r")
n = int(input())
student = [list(map(str, input().split())) for _ in range(n)]
student.sort(key = lambda x : (-int(x[1]), int(x[2]), -int(x[3]), x[0]))
#answer = sorted(student, key = lambda x : (-int(x[1]), int(x[2]), -int(x[3]), x[0]))
#print(answer)

for name in student:
    print(''.join(name[0]))


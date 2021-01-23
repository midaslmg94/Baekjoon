import sys
trees = {}
tree_num = 0 

for line in sys.stdin: # 입력이 계속들어오는 경우 : 개행 문자가 들어올 때 까지 입력받기
    if line == '\n':
        break
    tree = line.rstrip()
    tree_num += 1
    if tree in trees:
        trees[tree] += 1
    else:
        trees[tree] = 1

sorted_trees = sorted(trees.items(), key=lambda x:x[0]) # key를 기준으로 정렬


for k, v in sorted_trees:
    percentage = round((v/tree_num)*100, 4) # 소숫점 넷째자리까지 출력
    print(k, '%.4f' %percentage) # 50.0000 까지 출력하기 위함

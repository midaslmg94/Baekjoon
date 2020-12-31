import sys, copy
sys.stdin = open("input.txt", "r")

n,m,k = map(int, input().split())
board = [[0]*m for _ in range(n)]


def canAttach(y, x): 
    for i in range(r):
        for j in range(c):
            if sticker[i][j] == 1 and board[i][j] == 1:  # 해당 위치에 스티커를 붙일 수 없음 -> 0리턴
                return 0
    
    for i in range(r):
        for j in range(c):
            if sticker[i][j] == 1:                 
                board[i+y][j+x] = 1
    return 1
    

def attach(cnt): # 회전의 횟수. 0 : 회전안함, 1 : 90도 회전, .. 3 : 270도 회전
    # 모양의 스티커를 붙일 수 있으면 붙인 뒤, 1을 리턴한다.
    global r, c, sticker
    if cnt : # 회전을 해야한다면
        tmp = []
        for item in zip(*sticker): # 꼭 * 이게 들어감
            tmp.append(list(reversed(item)))
        sticker = copy.deepcopy(tmp)        
        r, c = c, r
    
    for i in range(n):
        for j in range(m):
            if n-i<r or m-j<c: break
            if canAttach(i, j): # 해당 위치에 스티커를 붙인다면
                return 1    
    return 0 # 이 모양의 스티커는 붙이지 못함




if __name__ == "__main__":
    for _ in range(k):
        r,c = map(int, input().split())
        sticker = [list(map(int, input().split())) for _ in range(r)]
        for cnt in range(4):
            if attach(cnt):
                break
        
    answer = 0
    for i in range(n):
        for j in range(m):
            answer += board[i][j]       
            
    print(answer)
import sys, math
from collections import deque
sys.stdin = open("input.txt", "r")

def bfs(x, y):    
    queue = deque()
    queue.append([x,y]) 
    visited = []
    while queue:
        x, y = queue.popleft()               
        visited.append([x,y])
        if x == festival_x and y == festival_y: # 목적지에 도착
            print("happy")
            return
        # 현재 위치에서 갈 수 있는 편의점을 큐에 넣는다.
        for nx, ny in store:
            dist = abs(x - nx) + abs(y - ny) # 맨하튼 거리
            if 1000 >= dist and [nx, ny] not in visited: # 맥주를 먹으며 갈 수 있는 거리라면 큐에 넣는다
                queue.append([nx, ny])
                visited.append([nx, ny])
    print("sad")


for _ in range(int(input())):
    n = int(input()) # 편의점의 개수
    sang_x, sang_y = map(int,input().split()) # 상근이의 집 좌표 (출발)
    # store = []
    # for _ in range(n):
    #     store_x, store_y = map(int, input().split()) # 편의점 좌표
    #     store.append([store_x, store_y]) 
    #store = list(map(int, input().split()) for _ in range(n))
    
    store = [list(map(int, input().split())) for _ in range(n)] # 조금 더 파이써닉 하게 짰음
    
    festival_x, festival_y = map(int, input().split()) # 락 페스티벌 좌표 (도착)
    store.append([festival_x, festival_y])  # 락 페스티벌에 도착했는지 확인하기 위해 리스트에 삽입
    bfs(sang_x, sang_y)
    
    
    
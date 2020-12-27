### BFS & DFS

<br>

> BFS 구현

```python
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

from collections import deque
visited_BFS = [False]*9    
def bfs(start):
    queue = deque([start])
    visited_BFS[start] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        # 아직 방문하지 않은 인접 노드를 큐에 삽입
        for i in graph[v]:
            if not visited_BFS[i]:
                queue.append(i)
                visited_BFS[i] = True
bfs(1)
```


<br>


> DFS 구현
```python
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]
visited_DFS = [False]*9

def dfs(start):
    visited_DFS[start] = True
    print(start, end=' ')
    for i in graph[start]:
        if not visited_DFS[i]:
            dfs(i)
dfs(1)

```
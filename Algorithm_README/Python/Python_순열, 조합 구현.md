### 백트래킹과 itertools를 활용해 순열, 조합 구하기
<br>

> 순열
- *itertools* 
    
    ```python
    from itertools import permutations, combinations
    data = ['a', 'b', 'c']
    result = list(permutations(data, 3)) 
    print(result)

    #[('a', 'b', 'c'), ('a', 'c', 'b'), ('b', 'a', 'c'), ('b', 'c', 'a'), ('c', 'a', 'b'), ('c', 'b', 'a')]
    ```
    <br>    
    
- *backtracking*
    ```python    
    def dfs(level):
        if level == r: # r개를 뽑은 경우
            print(result)
            return
        for i in range(len(n)):
            if checked[i] == True: continue
            result[level] = n[i]
            checked[i] = True
            dfs(level+1)
            checked[i] = False       

    n = [i+1 for i in range(3)]
    r = 2 # r개 뽑기
    result = [0] * r
    checked = [False] * len(n)
    dfs(0)
    #   [1, 2]
    #   [1, 3]
    #   [2, 1]
    #   [2, 3]
    #   [3, 1]
    #   [3, 2]
    ```


> 조합
- *itertools* 
    
    ```python
    from itertools import permutations, combinations
    data = ['a', 'b', 'c']
    result = list(combinations(data, 2)) # 조합
    print(result)

    #[('a', 'b'), ('a', 'c'), ('b', 'c')]
    ```
    <br>
- *backtracking*
    ```python
    def dfs(level, BeginWith):
        if level == r: # r개를 뽑은 경우
            print(result)
            return
        for i in range(BeginWith, len(n)):
            result[level] = n[i]
            dfs(level+1, i+1)       

    n = [i for i in range(10)]
    r = 6 # r개 뽑기
    result = [0] * r
    dfs(0, 0)

    #   [1, 2, 3]
    #   [1, 2, 4]
    #   [1, 2, 5]
    #   [1, 3, 4]
    #   [1, 3, 5]
    #   [1, 4, 5]
    #   [2, 3, 4]
    #   [2, 3, 5]
    #   [2, 4, 5]
    #   [3, 4, 5]
    ```


> 중복순열
- *itertools* 
    ```python
    from itertools import product

    n = [i+1 for i in range(3)]
    r = 2

    result = list(product(n, repeat=r)) 

    print(result)
    # [
    #   (1, 1), (1, 2), (1, 3), 
    #   (2, 1), (2, 2), (2, 3), 
    #   (3, 1), (3, 2), (3, 3)
    # ]
    ```
    <br>

- *backtracking*
    ```python
    def dfs(count):
    if count == m:
        print(*result)
        return
    for i in range(1,n+1):
        result.append(i)
        dfs(count+1)
        result.pop()

    dfs(0)
    ```
    <br>

> 중복조합
- *itertools* 
    ```python
    from itertools import combinations_with_replacement

    n = [i+1 for i in range(3)]
    r = 2

    result = list(combinations_with_replacement(n, r))  # 중복조합에서는 repeat가 안들어간다.

    print(result)
    # [
    #   (1, 1), (1, 2), (1, 3), 
    #   (2, 2), (2, 3), 
    #   (3, 3)
    #    ] 
    ```
    <br>

- *backtracking*
    ```python        
    result = []
    def dfs(idx, count):
        if count == m:
            print(*result)
            return
        for i in range(idx, n):
            result.append(i+1)
            dfs(i, count+1)
            result.pop()

    dfs(0, 0)
    ```
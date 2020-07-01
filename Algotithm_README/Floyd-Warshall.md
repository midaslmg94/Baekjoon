## Floyd-Warshall



> Floyd-Warshall은 모든 정점에 대해 모든 다른 정점에 대한 최단 경로를 다 구하는 것이다.
>
> 또한, 음수 가중치의 경우도 구할 수 있다.
>
> 알고리즘은 비교적 간단하다.



- 관련 문제

  - [백준 11404번 플로이드](https://www.acmicpc.net/problem/11404)

    

- 기본 개념

  - 3중 for loop 사용
  
  - 방향, 무방향 그래프 둘다 사용가능, 사이클이 생기면 안된다
  
  - 음의 가중치 적용 가능
  
  - a->b로 가는 최단거리가 a->c->b보다 크면 그 값을 갱신한다
  
  - 아래의 조건문이 핵심이다
  
    ```c++
    if (arr[i][k] + arr[k][j] < arr[i][j]) { // k를 거쳐가는게 더 작으면
    	arr[i][j] = arr[i][k] + arr[k][j]; // arr[i][j] 값 갱신
    }
    ```
  
    
  
- 시간 복잡도

  - O(n^3)

    

- floyd 구현

  - 입력

    ```c++
    #define INF 987654321
    int main() {
    	cin >> n >> m;
    	for (int i = 0; i < m; i++) {
    		cin >> from >> to >> cost;
    		if (arr[from][to] != 0) { // 노드 A에서 노드 B로 직행하는 방법이 2개 이상인 경우
    			arr[from][to] = min(arr[from][to], cost); // 방향 그래프
    		}
    		else {
    			arr[from][to] = cost;
    		}
    	}
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) {
    			if (i == j)continue;
    			if (arr[i][j] == 0)
    				arr[i][j] = INF; // 갈 수 없는 곳은 무한대
    		}
    	}
    ```
  
  - floyd() 
  
    ```c++
    void floyd() {
    	for (int k = 1; k <= n; k++) {// k : 거쳐가는 노드
    		for (int i = 1; i <= n; i++) { // i : from
    			for (int j = 1; j <= n; j++) { // j : to
    				if (arr[i][k] + arr[k][j] < arr[i][j]) { // k를 거쳐가는게 더 작으면
    					arr[i][j] = arr[i][k] + arr[k][j]; // 값 갱신
    				}
    			}
    		}
    	}
    }
    ```
  
    - 각 반복문의 위치가 중요하다. 
      - 가장 `바깥 loop`이 **거쳐**가는 노드
      - `두번째 loop`는 **출발**하는 노드
      - 가장 `안쪽 loop`는 **도착**하는 노드
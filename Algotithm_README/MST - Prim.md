## MST(Minimum Spanning Tree)



> MST는 최소 신장 트리로, 신장 트리를 의미하는 Spanning Tree는 그래프 내의 모든 정점을 포함하는 트리를 의미한다. 이 중 가중치가 최소가 되는 트리가 최소 신장 트리 MST 이다.
>
> MST를 구현하는 방법에는 대표적으로 Prim 알고리즘과 Kruskal 알고리즘이 있다. 여기서는 Prim 알고리즘을 사용하였다.
>
> 통신망, 도로망, 유통망 등에서 길이, 구축 비용, 전송 시간등을 최소로 구축하려는 경우 사용된다



- 관련 문제

  - [백준 1197번 최소 스패닝 트리](https://www.acmicpc.net/problem/1197)

  - [백준 1922번 네트워크 연결](https://www.acmicpc.net/problem/1922)

    

- 기본 개념

  - 하나의 정점에서 시작
  
  - 간선의 가중치의 합이 최소이다
  
  - 사이클이 포함되어서는 안된다.
  
    
  
- 시간 복잡도

  - O(ElogV)  --> E : 간선의 개수, V : 정점의 개수

- Prim 알고리즘 방식

  - 우선순위 큐(min-heap으로 구현)

  - 입력
  
    ```c++
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
    	// a와 b를 연결하는데 cost만큼 든다.
    	cin >> a >> b >> cost;
    	v[a].push_back({ b,cost });// 정점, 가중치 순으로 push
    	v[b].push_back({ a,cost });
    }
    	prim(1); // 1번 정점부터 시작
    ```
  
  - Prim() 
  
    ```c++
    void prim(int start) {
    	visit[start] = true;
    	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // 연결점, 비용, 최소힙이라 가중치가 작은게 나옴
    	for (int i = 0; i < v[start].size(); i++) {
    		int nextNode = v[start][i].first;
    		int nextCost = v[start][i].second;
    		pq.push({ nextCost, nextNode });// first를 기준으로 최소힙을 구성하므로 비용을 first에 넣음 
    	}
    	int ans = 0;
    	while (!pq.empty()) {
    		int cost = pq.top().first;
    		int cur = pq.top().second;
    		pq.pop();
    		if (visit[cur])
    			continue;
    		visit[cur] = true;
    		ans += cost;
    		// 다음 정점을 큐에 넣음
    		for (int i = 0; i < v[cur].size(); i++) {
    			int next = v[cur][i].first;
    			int next_cost = v[cur][i].second;
    			pq.push({ next_cost, next });
    		}
    	}
    	cout << ans;
    }
    ```
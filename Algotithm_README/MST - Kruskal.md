## MST(Minimum Spanning Tree) - Kruskal



> MST는 최소 신장 트리로, 신장 트리를 의미하는 Spanning Tree는 그래프 내의 모든 정점을 포함하는 트리를 의미한다. 이 중 가중치가 최소가 되는 트리가 최소 신장 트리 MST 이다.
>
> MST를 구현하는 방법에는 대표적으로 Prim 알고리즘과 Kruskal 알고리즘이 있다. 여기서는 Kruskal 알고리즘을 사용하였다.
>
> 통신망, 도로망, 유통망 등에서 길이, 구축 비용, 전송 시간등을 최소로 구축하려는 경우 사용된다



- 최소 스패닝 트리란?

  - 스패닝 트리란 방향이 없는 그래프에서 모든 노드를 포함하면서, 순환되는 경로를 제거한 형태이다.

  - 이 스패닝 트리에서 가중치의 합을 최소로 만드는 스패닝 트리를 '최소 스패닝 트리(Minimal Spanning Tree)' 라고 한다.

    

- 관련 문제

  - [백준 1197번 최소 스패닝 트리](https://www.acmicpc.net/problem/1197)

  - [백준 1922번 네트워크 연결](https://www.acmicpc.net/problem/1922)

    

- 기본 개념

  - 사이클이 포함되지 않는다 
  
  - 탐욕적인 방법(Greedy)를 사용한다.
  
  - 각 단계에서 사이클을 이루지 않는 **최소 비용 간선**을 선택한다
  
  - 사실상 Union-Find와 거의 똑같다
  
    
  
- 동작 방식

  1. 모든 간선들의 가중치를 오름차순으로 정렬

  2. 가중치가 가장 작은 간선을 선택

  3. 2번에서 선택한 간선이 연결하려는 2개의 노드가 아직 연결되지 않은 상태라면 2개의 노드를 연결한다.

  4. 위의 과정을 반복한다.

     

- 시간 복잡도

  - 

- Kruskal 알고리즘 방식

  - 사이클 발생유무를 확인하기 위해 Union-Find 사용한다.

  - 입력

    ```c++
    
    ```
    
  - findParent() 

    ```c++
    int findParent(int n1) {
    	if (n1 != parent[n1]) {
    		return parent[n1] = findParent(parent[n1]);
    	}
    	else {
    		return n1;
    	}
    }
    ```
    
  - mergeParent()

    ```c++
    void mergeParent(int n1, int n2) { // n1<n2라고 가정
    	n1 = findParent(n1);
    	n2 = findParent(n2);
    	if (n1 != n2) {	
    		parent[n2] = n1;
    	}
    }
    ```

  - main()

    ```c++
    int main() {
    	ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
    	freopen("input.txt", "r", stdin);
    	cin >> n >> m;
    	for (int i = 1; i <= n; i++) {
    		parent[i] = i;
    	}
    	for (int i = 1; i <= m; i++) {
    		cin >> n1 >> n2 >> cost;
    		graph.push_back({cost,{n1,n2}});
    	}
    	sort(graph.begin(), graph.end()); // 최소 비용을 구하기 위해 정렬
    	int cnt = 0;
    	for (int i = 0; i < graph.size(); i++) {
    		int cur_cost = graph[i].first;
    		int home1 = min(graph[i].second.first, graph[i].second.second);
    		int home2 = max(graph[i].second.first, graph[i].second.second);
    		if (findParent(home1) != findParent(home2)) { // 부모가 다른 애들만, 합침!!!!	이걸 넣어야 시간초과가 안난다.
    			mergeParent(home1, home2);
    			/*result += cur_cost; // 문제마다 다른 조건들
    			cnt++;*/ 
    		}
    		if (cnt == n - 2) { break; } // 문제마다 다른 조건들 
    	}
    	cout << result;
    }
    ```

    
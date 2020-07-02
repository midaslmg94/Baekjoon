## Union-Find



> Union-Find에 대해 알아보자
>
> 유니온 파인드는 자료구조 이므로 단독으로 쓰이기 보다, 알고리즘(크루스칼 등)에 활용된다



- 관련 문제

  - [백준 1717번 집합의 표현](https://www.acmicpc.net/problem/1717)

  - [백준 1976번 여행 가자](https://www.acmicpc.net/problem/1976)

    

- 기본 개념

  - 유니온 파인드는 '집합'을 관리하는 자료구조이며 서로소 집합(Disjoint Set) 이라고도 불린다.
  - 유니온 파인드를 활용하면 다음과 같은 작업을 할 수 있다.
  - 원소 A와 원소 B가 같은 집합에 속하는지 확인 -- Find 함수
    - 원소 A가 속한 집합과 원소 B가 속한 집합을 병합 -- Union 함수 
  
    
  
- 방식

  - 초기화

  ``` c++
  for (int i = 0; i <= n; i++) {
  		parent[i] = i; 
  	}
  ```
  
  - Union 함수 
  
  ```c++
  void Union(int n1, int n2) {// 부모를 합칠 때는 일반적으로 더 작은 값 쪽으로 합친다
  	n1 = Find(n1); 
  	n2 = Find(n2);
  	// n1<n2 로 가정
  	if (n1 != n2) {
  		if (n1 < n2)
  			parent[n2] = n1;
  		else
  			parent[n1] = n2;
  	}
  }
  ```
  
  - Find 함수 
  
  ```c++
  int Find(int n1) { // n1이 어떤 집합에 포함되어 있는지 찾는 연산
  	if (n1 == parent[n1]) {// 루트 노드인 경우
  		return n1;
  	}
  	else {
  		return parent[n1] = Find(parent[n1]);
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
  		if (findParent(home1) != findParent(home2)) { // 부모가 다른 애들만, 합침!!!!	
  			mergeParent(home1, home2);
  		}		
  	}
  }
  ```
  
  


- 시간복잡도

  - Union 함수 : O(log N)
  - Find 함수 : O(log N)



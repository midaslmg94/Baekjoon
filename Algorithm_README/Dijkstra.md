## Dijkstra



> Dijkstra는 비용이 있는 그래프에서 최단 거리를 찾는 알고리즘이다.
>
> 최단 거리와 관련된 그래프 알고리즘에는 대표적으로 다음의 3개의 알고리즘도 존재한다. 
>
> - **다익스트라 알고리즘** : 하나의 시작점에 대해 다른 모든 정점들까지의 최단 경로를 구함
> - **벨만포드 알고리즘** : 음의 가중치 고려
> - **플로이드 와샬 알고리즘** : 모든 정점에 대해 다른 모든 정점에 대한 최단경로를 구함
>
> 이 중 기본이 되는 다익스트라 알고리즘을 정리해보았다. 
>
> *[참고자료 ](https://jason9319.tistory.com/307)*



- 관련 문제

  - [백준 1753번 최단경로](https://www.acmicpc.net/problem/1753)

  - [SWEA 1249 보급로](https://swexpertacademy.com/main/code/problem/problemDetail.do)

    

- 기본 개념

  - 다익스트라 알고리즘은 **하나의 시작점**에 대해 최단 경로를 찾는다.
  
    - 다시 말해 A에서 시작하면 B,C,D,E,F에 대한 최단 경로를 구한다는 것이다.
  
  - 음의 가중치는 고려하지 않는다.(음의 가중치를 고려한 최단거리 그래프 알고리즘은 **벨만포드 알고리즘**)
  
  - 최단거리를 구하기 위해 이전에 구했던 최단거리를 구하고, 갱신이 이루어지므로 DP이기도 하다.
  
  - 다익스트라 알고리즘에 사용되는 자료구조는 **우선순위 큐**이다.
  
  - 우선순위 큐는 기본적으로 **최대 힙**으로 짜여있기 때문에, 최단거리를 구하기 위해서는 **최소 힙**으로 만들어 주어야 한다.
  
    - 최소 힙으로 만드는 방법은 다양하게 있지만(구조체 활용 등), 비용의 값을 음수 화(-) 해서 처리하는 것이 가장 간편하다.
  
    
  
- 전제 조건 

  - 방문 노드와 연결되어 있지 않은 노드까지의 거리는 무한대이다.
- 자기 자신으로 돌아와서 방문하는 거리는 0이다
  
  
  
- 시간복잡도

  - O(Elog(V))

    - 정점의 개수 : V

    - 간선의 개수 : E

      

- 구현 로직

  - 시작 노드에서 각 노드까지의 최단 거리를 기록하는 배열(일차원)  생성

  - 아직 방문하지 않은 정점들 중 거리가 가장 짧은 정점을 방문
  
  - 해당 정점에서 인접하고 아직 방문하지 않은 정점들의 거리를 갱신
  
    ![image-20200126234830740](C:\Users\midas\AppData\Roaming\Typora\typora-user-images\image-20200126234830740.png)
  
  
  
- 구현코드 

  - 방법 1(인접 리스트) : [백준 1753번 최단경로](https://www.acmicpc.net/problem/1753) 소스코드

  ```c++
  #include<iostream>
  #include<vector>
  #include<queue>
  const int MAX = 20001;
  const int INF = 987654321;
  
  using namespace std;
  int V, E, K;
  vector<pair<int, int>>graph[MAX];
  
  vector<int> dijkstra(int start, int vertex) {
  	vector<int>distance(vertex, INF); //start지점을 기준으로 거리
  	distance[start] = 0; //자기 자신은 0
  	priority_queue<pair<int, int>>pq; //cost, vertex
  	pq.push({ 0, start }); // 초기비용과 시작지점
  
  	while (!pq.empty()) {
  		int cost = -pq.top().first; // 최소값을 저장하기 위해 음수로 저장했으므로 꺼낼때 다시 -를 붙인다.
  		int curVertex = pq.top().second; // 현재 방문한 정점
  		pq.pop();
  	
  		if (distance[curVertex] < cost) { // 현재비용이 더 적으면 굳이 더 갈필요가 없다
  			continue;
  		}
  		//curVertex와 연결된 정점 전부 확인
  		for (int i = 0; i < graph[curVertex].size(); i++) {
  			int neighbor = graph[curVertex][i].first;
  			int neighborCost = cost + graph[curVertex][i].second;
  
  			// 최소 경로 발견 시 업데이트
  			if (distance[neighbor] > neighborCost) {
  				distance[neighbor] = neighborCost;
  				pq.push({ -neighborCost, neighbor }); //최소 값을 꺼내기 위해 음수로 저장
  			}
  		}
  	}
  	return distance;
  }
  int main() {
  	ios::sync_with_stdio(false);
  	cin.tie(NULL);
  	cin >> V >> E >> K;
  	V++;//정점 번호 : 1부터 시작
  	for (int i = 0; i < E; i++) {
  		int source, destination, cost;
  		cin >> source >> destination >> cost;
  		graph[source].push_back({ destination, cost });
  	}
  	vector<int> result = dijkstra(K, V); // 시작점, 정점의 개수
  	for (int i = 1; i < V; i++) {
  		if (result[i] == INF) {
  			cout << "INF\n";
  		}
  		else {
  			cout << result[i] << "\n";
  		}
  	}
  	return 0;
  }
  
  ```
  
  - 방법 2(인접행렬+BFS) : [SWEA 1249 보급로](https://swexpertacademy.com/main/code/problem/problemDetail.do) 소스코드
  
  ```c++
  #include<iostream>
  #include<queue>
  #include<vector>
  #include<string.h>
  #include<algorithm>
  using namespace std;
  int arr[100][100];
  int d[100][100];
  int dy[4] = { 0,0,-1,1 };
  int dx[4] = { 1,-1,0,0 };
  int n;
  
  void dijkstra() {
  	memset(d, -1, sizeof(d));
  	priority_queue<pair<int, pair<int, int>>>pq; // cost, 노드1, 노드2
  	// cost가 낮은 순으로 최소 힙을 구현해야하기 때문에, first에 cost를 놓는다
  	pq.push({ 0,{0,0} }); // 시작지점은 0,0
  	while (!pq.empty()) {
  		int cost = -pq.top().first;
  		int y = pq.top().second.first;
  		int x = pq.top().second.second;
  		pq.pop();
  		if (d[y][x] == -1)
  			d[y][x] = cost;
  		for (int k = 0; k < 4; k++) {
  			int ny = y + dy[k];
  			int nx = x + dx[k];
  			if (0 > nx || nx >= n || 0 > ny || ny >= n)continue;
  			int ncost = -cost - arr[ny][nx];
  			if (d[ny][nx] == -1)
  				pq.push({ ncost,{ny,nx} });
  		}
  	}
  }
  int main() {
  	/*ios::sync_with_stdio(false);
  	cin.tie(0);	cout.tie();*/
  	freopen("input.txt", "r", stdin);
  	int t=1;
  	int c;
  	cin >> c;
  	while (t<=c) {	
  		cin >> n;
  		for (int i = 0; i < n; i++) {
  			for (int j = 0; j < n; j++) {
  				scanf("%1d", &arr[i][j]); // 입력이 띄어쓰기 없이 01102 처럼 들어올때 씀
  			}
  		}
  		dijkstra();
  		cout << "#" << t << ' '<<d[n-1][n-1]<< "\n";
  		t++;
  	}
  
  }
  ```
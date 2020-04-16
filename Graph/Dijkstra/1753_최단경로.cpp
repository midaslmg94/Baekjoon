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

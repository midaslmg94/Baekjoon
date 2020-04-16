#include<iostream>
#include<vector>
#include<queue>
const int MAX = 1001;
const int INF = 987654321;
using namespace std;
int N,M=0;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int end) {
	//시작점부터 다른 노드들까지 가는데 비용을 저장하는 벡터 생성
	vector<int>dist(N+1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq; //연결된 정점, 비용 저장
	pq.push({ start,0 });

	while (!pq.empty()) {
		int vertex = pq.top().first;
		int cost = -pq.top().second; // 이 부분을 (-)처리 안해줌
		pq.pop();
		if (dist[vertex] < cost) {
			continue;
		}
		for (int i = 0; i < graph[vertex].size(); i++) {
			int nextVertex = graph[vertex][i].first;
			int nextCost = cost + graph[vertex][i].second; // 이 부분 실수

			if (nextCost < dist[nextVertex]) { // 최소비용 갱신, 이 부분 실수 
				dist[nextVertex] = nextCost;
				pq.push({nextVertex, -nextCost});
			}

		}
	}

	return dist;
}


int main() {
	cin >> N >> M; // 도시 개수(정점), 버스 개수(간선)
	for (int i = 0; i < M; i++) {
		int start, destination, cost;
		cin >> start >> destination >> cost;
		graph[start].push_back({ destination, cost });
	}
	int target_start, target_destination;
	cin >> target_start >> target_destination;
	vector<int>result = dijkstra(target_start, target_destination);

	cout << result[target_destination];
}
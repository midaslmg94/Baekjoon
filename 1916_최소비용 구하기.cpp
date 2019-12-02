#include<iostream>
#include<vector>
#include<queue>
const int MAX = 1001;
const int INF = 987654321;
using namespace std;
int N,M=0;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int end) {
	//���������� �ٸ� ������� ���µ� ����� �����ϴ� ���� ����
	vector<int>dist(N+1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq; //����� ����, ��� ����
	pq.push({ start,0 });

	while (!pq.empty()) {
		int vertex = pq.top().first;
		int cost = -pq.top().second; // �� �κ��� (-)ó�� ������
		pq.pop();
		if (dist[vertex] < cost) {
			continue;
		}
		for (int i = 0; i < graph[vertex].size(); i++) {
			int nextVertex = graph[vertex][i].first;
			int nextCost = cost + graph[vertex][i].second; // �� �κ� �Ǽ�

			if (nextCost < dist[nextVertex]) { // �ּҺ�� ����, �� �κ� �Ǽ� 
				dist[nextVertex] = nextCost;
				pq.push({nextVertex, -nextCost});
			}

		}
	}

	return dist;
}


int main() {
	cin >> N >> M; // ���� ����(����), ���� ����(����)
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
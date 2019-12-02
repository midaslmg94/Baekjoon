#include<iostream>
#include<vector>
#include<queue>
const int MAX = 20001;
const int INF = 987654321;

using namespace std;
int V, E, K;
vector<pair<int, int>>graph[MAX];

vector<int> dijkstra(int start, int vertex) {
	vector<int>distance(vertex, INF); //start������ �������� �Ÿ�
	distance[start] = 0; //�ڱ� �ڽ��� 0
	priority_queue<pair<int, int>>pq; //cost, vertex
	pq.push({ 0, start }); // �ʱ���� ��������

	while (!pq.empty()) {
		int cost = -pq.top().first; // �ּҰ��� �����ϱ� ���� ������ ���������Ƿ� ������ �ٽ� -�� ���δ�.
		int curVertex = pq.top().second; // ���� �湮�� ����
		pq.pop();
	
		if (distance[curVertex] < cost) { // �������� �� ������ ���� �� ���ʿ䰡 ����
			continue;
		}
		//curVertex�� ����� ���� ���� Ȯ��
		for (int i = 0; i < graph[curVertex].size(); i++) {
			int neighbor = graph[curVertex][i].first;
			int neighborCost = cost + graph[curVertex][i].second;

			// �ּ� ��� �߰� �� ������Ʈ
			if (distance[neighbor] > neighborCost) {
				distance[neighbor] = neighborCost;
				pq.push({ -neighborCost, neighbor }); //�ּ� ���� ������ ���� ������ ����
			}
		}
	}
	return distance;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E >> K;
	V++;//���� ��ȣ : 1���� ����
	for (int i = 0; i < E; i++) {
		int source, destination, cost;
		cin >> source >> destination >> cost;
		graph[source].push_back({ destination, cost });
	}
	vector<int> result = dijkstra(K, V); // ������, ������ ����
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

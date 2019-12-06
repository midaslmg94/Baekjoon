#include<iostream>
#include<vector>
#include<queue>
#include<string>
/*  dijkstra �����ؼ� Ǯ���*/
const int MAX =1001;
const int INF = 987654321;
using namespace std;
vector<pair<int, int>> graph[MAX];

class PQ { // priority queue�� ����� �ڷ����� ����
public:
	int n; 
	int cost; 
	PQ(int n, int cost) {
		this->n = n;
		this->cost = cost;
	}
	bool operator>(const PQ& a) {
		return this->cost > a.cost;
	}
};
priority_queue<PQ, vector<PQ>, greater<>> pq;  // priority queue�� �ڷ����� PQ, push�Ҷ� PQ�� ������
int dist[MAX];
int connect[MAX];
int connectCnt = 0;
void dijkstra() { // ���ͽ�Ʈ�� ����.. ������ �ߴ��Ͱ� ������ �����
	pq.push(PQ(1,0)); // priority queue�� �ڷ����� PQ�̹Ƿ� PQ�� ��������
	dist[1] = 0;
	while (!pq.empty()) {
		int n = pq.top().n;
		int cost = pq.top().cost;
		pq.pop();
		if (dist[n] < cost) {
			continue;
		}
		for (int i = 0; i < graph[n].size(); i++) {
			int next = graph[n][i].first; // graph[i][n]�� �ƴ϶�, graph[n][i]
			int next_cost = graph[n][i].second+cost; // ���ݱ����� ���� ���ϴ°� ��������
			if (dist[next] > next_cost) { // ��� ����
				dist[next] = next_cost;
				connect[next] = n;
				connectCnt++;
				pq.push({ next, next_cost });
			}
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c }); // first : node, second : cost
		graph[b].push_back({ a,c });
	}
	dijkstra();
	cout << N - 1 << "\n";
	for (int i= 2; i <=N; i++) { // 1���� �����ϰ� �ٸ� ����� ���� ���?.. �� �κ��� �� �𸣰ڴ�
		cout << i << " " << connect[i] << "\n";
	}
}
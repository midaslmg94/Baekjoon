#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define INF 987654321
#define MAX 1001
#define pii pair<int,int>
using namespace std;

bool visit[MAX];
int N, M;
vector<pair<int, int>>graph[MAX];
int dist[MAX][MAX];
queue<pii>answer;

void dijkstra(int idx) {
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	for (int i = 0; i < graph[idx].size(); i++) {
		pq.push({ graph[idx][i].second, graph[idx][i].first }); // 비용, 정점
	}
	visit[idx] = true;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (visit[cur])continue;
		visit[cur] = true;		
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int next_cost = graph[cur][i].second;
			pq.push({ next_cost, next });			
		}
		

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c }); // 정점, 비용
		graph[b].push_back({ a,c });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (i != j)
				dist[i][j] = INF;
	}
	dijkstra(1);
	cout << answer.size() << endl;
	while (!answer.empty()) {
		cout << answer.front().first << ' ' << answer.front().second << endl;
		answer.pop();
	}
}
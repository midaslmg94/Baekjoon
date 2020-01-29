#include<iostream>
#include<vector>
#include<queue>
#define INF 12'345'678
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;
int n, m;
int a, b, cost;
vector<pii>v[MAX];
bool visit[MAX];
/*
 각 컴퓨터를 연결하는데 필요한 비용이 주어졌을 때 
 모든 컴퓨터를 연결하는데 필요한 최소비용을 출력하라. 
 모든 컴퓨터를 연결할 수 없는 경우는 없다.
 --> 프림 알고리즘, 우선순위 큐 사용
*/

void prim(int start) {
	visit[start] = true;
	priority_queue< pii, vector< pii>, greater<pii>>pq; // 연결점, 비용, 최소힙이라 가중치가 작은게 나옴
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		// a와 b를 연결하는데 cost만큼 든다.
		cin >> a >> b >> cost;
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}
	prim(1); // 1번 컴퓨터부터 시작
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
#define endl "\n"
#define MAX 1001
#define INF 1e9
#define pii pair<int,int>
using namespace std;
int n, m, x;
vector<pii>map[MAX];


int dijkstra(int start, int end) {
	vector<int>dist(n + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)continue;
		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].first;
			int next_cost = cost + map[cur][i].second;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next_cost,next });
			}
		}
	}
	return dist[end];

}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> x;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
	}
	int result = -INF;
	for (int i = 1; i <= n; i++) {		
		result = max(result, dijkstra(i, x) + dijkstra(x, i));
	}
	cout << result;
	return 0;
}
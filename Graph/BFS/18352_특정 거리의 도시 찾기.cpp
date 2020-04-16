#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAX 300000+1
#define endl "\n"
using namespace std;
vector<vector<int>>map(MAX);
bool visit[MAX];
int n, m, k, x;
void bfs(int start) {
	int dist = 0; // 몇만큼 갔는지
	queue<int>q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur = q.front();
			q.pop();
			for (int j = 0; j < map[cur].size(); j++) {
				int next = map[cur][j];
				if (visit[next])continue;
				visit[next] = true;
				q.push(next);
			}
		}
		dist++;
		if (dist == k && !q.empty()) {
			priority_queue<int, vector<int>, greater<int>>pq;
			while (!q.empty()) {
				pq.push(q.front());
				q.pop();
			}
			while (!pq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
			return;
		}
	}
	cout << -1;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> k >> x; // 도시, 도로, 가야할 거리, 시작 도시
	int c1; int c2;
	for (int i = 0; i < m; i++) {
		cin >> c1 >> c2;
		map[c1].push_back(c2);
	}
	bfs(x);

}
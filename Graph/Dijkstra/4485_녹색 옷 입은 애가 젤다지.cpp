#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 125 
#define INF 987654321
#define pii pair<int,pair<int, int>>
using namespace std;
int n;
int t = 1;
int map[MAX][MAX];
int dist[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	while (true) {
		cin >> n;
		if (n == 0)return 0;
		memset(map, 0, sizeof(map));
		memset(dist, 0, sizeof(dist));
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				dist[i][j] = INF;
			}
		}
		priority_queue<pii, vector<pii>,greater<pii>>pq; // cost, nextNode
		dist[0][0] = map[0][0];
		pq.push({ dist[0][0],{0,0}});
		while (!pq.empty()) {
			int cost = pq.top().first;
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			visit[y][x] = true;
			pq.pop();
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (0 > ny || ny >= n || 0 > nx || nx >= n)continue;
				if (visit[ny][nx])continue;
				dist[ny][nx] = min(dist[ny][nx], dist[y][x] + map[ny][nx]);
				visit[ny][nx] = true;
				pq.push({ dist[ny][nx], {ny,nx} });
			}
		}	
		cout << "Problem " << t << ": " << dist[n - 1][n - 1] << endl;
		t++;

	}

}
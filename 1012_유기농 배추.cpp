#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int map[50][50];
bool visit[50][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int t, n, m, k;
int cnt=0;
void bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();		
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !visit[ny][nx]&&map[ny][nx]==1) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
	}
	cnt++;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> t;
	// i, y, n : 가로(y축)
	// j, x, m : 세로(x축)
	while (t--) {
		cin >> m >> n >> k;
		int x = 0;
		int y = 0;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					bfs(i, j);
				}
			}
		}
		cout << cnt<<"\n";
		// 초기화
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		cnt = 0;
	}
}
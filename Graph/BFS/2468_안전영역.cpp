#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#define endl "\n"
#define MAX 100
using namespace std;
int n;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
//int cnt = 0;
int res = -1;
int height=-1;
int section = 0;
void bfs(int y, int x, int h) {
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
			if (0 <= ny && ny < n && 0 <= nx && nx < n && !visit[ny][nx]) {
				if (map[ny][nx] > h) {
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			height = max(height, tmp); // 지역의 최대 높이를 구함
			map[i][j] = tmp;
		}
	}

	for (int h = 0; h <= height; h++) {
		memset(visit, false, sizeof(visit));
		section = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > h &&!visit[i][j]) {
					section++;
					bfs(i, j, h);
				}
			}
		}				
		res = max(res, section);
	}
	//dfs(0, 0, 0);
	cout << res;
	
}

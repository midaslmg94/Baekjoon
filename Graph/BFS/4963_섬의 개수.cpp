#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int map[50][50];
bool visit[50][50];
int dy[8] = { 1,-1,0,  0, -1,  1, -1, 1 }; // 좌, 우 
int dx[8] = { 0, 0, 1, -1,-1, -1,  1, 1 }; // 상, 하
int w, h;
int cnt = 0; // 섬의 개수

void bfs(int y, int x) {
	visit[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		y = q.front().first; // 이걸 int ny = q.front().first
		x = q.front().second; // int nx = q.front().second 로 했음
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 > ny || ny >= h || 0 > nx || nx >= w || visit[ny][nx])continue;
			if (map[ny][nx] == 1) { // 육지이면
				q.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}				
	}
	cnt++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) exit(0);

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visit[i][j]&&map[i][j]==1) {//방문하지 않고, 육지에서만 출발
					bfs(i, j);					
				}
			}
		}
		cout << cnt << "\n";
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		cnt = 0;
	}
}
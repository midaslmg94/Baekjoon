#include<iostream>
#include<queue>
#include<string.h>
#define MAX 100
using namespace std;
int n;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dist[MAX][MAX];

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int idx = 1;
int min_dist = 987654321;
void masking(int y, int x, int idx) { // 섬을 다른 숫자로 바꿈
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x] = true;
	map[y][x] = idx;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 <= ny && ny < n && 0 <= nx && nx < n && visit[ny][nx] == false && map[ny][nx] != 0) {
				map[ny][nx] = idx;
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

int bfs(int y, int x) {// 최단거리 찾기
	queue<pair<int, int>>q;
	q.push({ y,x });	
	int flag = map[y][x]; // 출발한 섬의 정보
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		dist[y][x]++;
		for (int k = 0; k < 4; k++) {// 좌, 우, 하, 상
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 <= ny && ny < n && 0 <= nx && nx < n && visit[ny][nx] == false) {				
				visit[ny][nx] = true;
				if (map[ny][nx] != flag) {
					if (map[ny][nx] == 0) { // 다리를 이음
						dist[ny][nx] = dist[y][x] + 1;
					}
					else { // 새로운 섬에 도착
						return dist[ny][nx];
					}
				}
				q.push({ ny,nx });
			}
		}
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0 && visit[i][j] == false) {
				masking(i, j, idx);
				idx++;
			}
		}
	}
	memset(visit, false, sizeof(visit));
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0) {
				int dist = bfs(i, j);
				min_dist = min(dist, min_dist);
			}
		}
	}
	cout << min_dist;
}
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#define MAX 100
using namespace std;
int n, m;
int map[MAX][MAX];
int backup[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int answer = 1;
void prt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}
void masking(int y, int x, int idx) {
	map[y][x] = idx;
	visit[y][x] = true;
	for (int k = 0; k < 4; k++) {
		int ny = dy[k] + y;
		int nx = dx[k] + x;
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (visit[ny][nx] || map[ny][nx] == 0) continue;
		map[ny][nx] = idx;
		masking(ny, nx, idx);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) // 섬을 구분하여 칠하기 위해 -1로 변경
				map[i][j] = -1;
		}
	}
	int idx = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1) {
				masking(i, j, idx);
				idx++;
			}
		}
	}
	prt();
	memset(visit, false, sizeof(visit));
	memcpy(backup, map, sizeof(backup));
}
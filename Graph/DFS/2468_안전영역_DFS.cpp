#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#define MAX 100
using namespace std;
int n;
int max_height=-1;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int answer = 1;
void dfs(int y, int x, int h) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (visit[ny][nx] || map[ny][nx] <= h) continue;
		dfs(ny, nx, h);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	freopen("input.txt", "r", stdin);
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			map[i][j]=tmp;
			max_height = max(tmp, max_height);
		}
	}
	for (int height = 1; height <= max_height; height++) {
		memset(visit, false, sizeof(visit));
		int area = 0; // 해당 높이일 때 안잠긴 영역의 개수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > height && !visit[i][j]) { // 안잠긴 지점
					area++;
					dfs(i, j, height);
				}
				else {
					visit[i][j] = true;
				}
			}
		}
		answer = max(answer, area);
	}
	cout << answer;
}
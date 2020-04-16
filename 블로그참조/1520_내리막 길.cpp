#include<iostream>
#include<string.h>
#define MAX 500
#define pii pair<int, int>
using namespace std;
int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dp[MAX][MAX]; // (y, x) 지점일 때 존재하는 경로의 갯수

int dy[4] = { 0,0,1,-1 }; 
int dx[4] = { 1,-1,0,0};

int dfs(int y, int x) {
	if (y == n - 1 && x == m - 1) { // 마지막에 도달		
		return 1;
	}
	if (visit[y][x]) // 방문한 지점이라면
		return dp[y][x];  // 왜?..
	visit[y][x] = true;

	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (0 <= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] < map[y][x]) { // 범위 내부, 내리막 길
			dp[y][x]+=dfs(ny, nx);
		}
	}
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cout << dfs(0, 0);
}
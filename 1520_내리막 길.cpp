#include<iostream>
#include<string.h>
#define MAX 500
#define pii pair<int, int>
using namespace std;
int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dp[MAX][MAX]; // (y, x) ������ �� �����ϴ� ����� ����

int dy[4] = { 0,0,1,-1 }; 
int dx[4] = { 1,-1,0,0};

int dfs(int y, int x) {
	if (y == n - 1 && x == m - 1) { // �������� ����		
		return 1;
	}
	if (visit[y][x]) // �湮�� �����̶��
		return dp[y][x];  // ��?..
	visit[y][x] = true;

	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (0 <= ny && ny < n && 0 <= nx && nx < m && map[ny][nx] < map[y][x]) { // ���� ����, ������ ��
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
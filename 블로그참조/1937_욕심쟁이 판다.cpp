#include<iostream>
#include<algorithm>
#define endl "\n"
#define MAX 500
#define pii pair<int, pair<int,int>>
using namespace std;

int map[MAX][MAX];
int dp[MAX][MAX]; // i,j의 위치에서 판다가 있을 경우 살 수 있는 최대 날
int n;
int result = -1;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

int dfs(int y, int x) {		
	if (dp[y][x] != 0)
		return dp[y][x];
	dp[y][x] = 1;
	for (int k = 0; k < 4; k++) {
		int ny = dy[k] + y;
		int nx = dx[k] + x;
		if (0 > ny || ny >= n || 0 > nx || nx >= n)continue; // 범위 초과
		if (map[ny][nx] <= map[y][x])continue;	// 이전보다 대나무 적음
		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
		
	}
	return dp[y][x];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >>map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0) {
				result = max(result,dfs(i, j));
			}
		}
	}
	cout << result;
	return 0;
}
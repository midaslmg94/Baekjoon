#include<iostream>
#include<algorithm>
#define MAX 20+1
using namespace std;
char map[MAX][MAX];
int r, c;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
bool visit[27]; // 'A' = 65 , 'B' = 66 ... 'Z' = 90  --> index로 바꿈
int cnt = 1;
int res = 1;
void dfs(int y, int x, int cnt) {
	int idx = map[y][x] - 64;
	visit[idx] = true;
	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		int n_idx = map[ny][nx]-64;
		if (0 <= ny && ny < r && 0 <= nx && nx < c && !visit[n_idx]) {
			visit[n_idx] = true;		
			dfs(ny, nx, cnt+1);
			visit[n_idx] = false; // 왜 이부분을 넣지?
		}
	}
	res = max(res, cnt); // 왜 res?..
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < c; j++) {
			map[i][j] = tmp[j];
		}
	}
	dfs(0, 0,1);
	cout << res;
}
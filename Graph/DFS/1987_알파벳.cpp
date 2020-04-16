#include<iostream>
#include<algorithm>
#define MAX 20
using namespace std;
char map[MAX][MAX];
bool visit[MAX][MAX];
bool alpha[26]; // 해당 알파벳이 쓰였는지
int result = -1;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int r, c;
bool is_move = true;
void dfs(int y, int x, int depth) {
	// 탈출조건이 뭘까 더이상 전진할 곳이 없을 경우!
	if (is_move == false) {
		cout << result << endl;
		return;
	}
	result = max(result, depth);
	char cur_alpha = map[y][x];
	int cur_idx = cur_alpha - 65;
	visit[y][x] = true;
	alpha[cur_idx] = true;
	for (int k = 0; k < 4; k++) {
		int ny = dy[k] + y;
		int nx = dx[k] + x;
		if (0 > ny || ny >= r || 0 > nx || nx >= c || visit[ny][nx] == true) continue;
		char next_alpha = map[ny][nx];
		int next_idx = next_alpha - 65;
		if (alpha[next_idx] == true) {
			is_move = false;
			continue;
		}
		is_move = true;
		visit[ny][nx] = true;
		alpha[next_idx] = true;
		dfs(ny, nx, depth + 1);
		visit[ny][nx] = false;
		alpha[next_idx] = false;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> r >> c;
	string str;
	for (int i = 0; i < r; i++) {
		cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j] = str[j];
		}
	}
	dfs(0, 0, 1);
	cout << result;
}
#include<iostream>
#include<queue>
using namespace std;
int n;
char arr[5][20000];
bool visit[5][20000];
char shape[5][3];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
char zero[5][3] = {
	'#','#','#',
	'#','.', '#',
	'#','.', '#',
	'#','.', '#',
	'#','#','#'
};
char one[5][1] = {
	'#',
	'#',
	'#',
	'#',
	'#'
};
char three[5][3] = {
	'#','#','#',
	' ',' ', '#',
	'#','#','#',
	' ',' ', '#',
	'#','#','#'
};
char seven[5][3] = {
	'#','#','#',
	' ',' ', '#',
	' ',' ','#',
	' ',' ','#',
	' ',' ','#'
};
void bfs(int y, int x, int row, int col) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x] = true;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < col && 0 <= nx && nx < row && arr[ny][ny] == '#' && visit[ny][nx] == false) {
				visit[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);
	cin >> n;
	int row = n / 5;
	int col = 5;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			char tmp; cin >> arr[i][j];
		}
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (arr[i][j] == '#' && !visit[i][j]) {
				bfs(i, j, row, col);
			}
		}
	}
}
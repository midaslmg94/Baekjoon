#include<iostream>
#include<algorithm>
#include<queue>
#define endl "\n"
#define MAX 100
using namespace std;
int n, m, k;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dx[5] = { 0,0,1,-1,0 };
int dy[5] = { 1,-1,0,0,0 };
int section = 1;
void prt() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "-----------------\n";
}
void fulfill(int down_x, int down_y, int up_x, int up_y) {
	for (int i = down_y; i >= up_y; i--) {
		for (int j = down_x; j <= up_x; j++) {
			map[i][j] = -1;
		}		
	}
}
int bfs(int y, int x) {
	int cnt = 0;
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x];
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int k = 0; k < 5; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 <= ny && ny < m && 0 <= nx && nx < n && !visit[ny][nx] && map[ny][nx] == 0) {
				map[ny][nx] = section;
				cnt++;
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> m >> n >> k;
	int down_y;
	int down_x;
	int up_y;
	int up_x;
	for (int i = 0; i < k; i++) {
		cin >> down_x >> down_y >> up_x >> up_y;
		down_y = abs(m - 1 - down_y);
		map[down_y][down_x] = 1;
		up_y = abs(m + 1 - up_y);
		up_y = up_y - 1;
		up_x = up_x - 1;
		map[up_y][up_x] = 1;
		fulfill(down_x ,down_y,up_x ,up_y);
		//prt();
	}
	priority_queue<int>q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				int n = bfs(i, j);
				section++;
				q.push(-n);				
			}
		}
	}

	cout << q.size() << endl;	
	while (!q.empty()) {
		cout << -q.top() << ' ';
		q.pop();
	}
}

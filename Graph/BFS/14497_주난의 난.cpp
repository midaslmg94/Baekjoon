#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 300+1
using namespace std;
char map[MAX][MAX];
bool visit[MAX][MAX];
int n, m;
int start_y, start_x; // 주난의 위치
int choco_y, choco_x; // 범인의 위치
int answer = 0;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
void prt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

void bfs() {
	queue<pair<int, int>>q;
	while (true) {
		q.push({ start_y,start_x });
		memset(visit, false, sizeof(visit));
		answer++;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			visit[y][x] = true;
			for (int k = 0; k < 4; k++) {
				int ny = dy[k] + y;
				int nx = dx[k] + x;
				if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;
				if (visit[ny][nx])continue;
				visit[ny][nx] = true;
				if (map[ny][nx] == '0') {
					q.push({ ny,nx });
				}
				else if (map[ny][nx] == '1') {
					map[ny][nx] = '0';
				}
				else if (map[ny][nx] == '#') {
					return;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	cin >> start_y >> start_x >> choco_y >> choco_x;
	start_y--; start_x--; choco_y--; choco_x--; // 시작점을 0,0부터 하기 위해
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
		}
	}
	bfs();
	cout << answer;
	return 0;
}
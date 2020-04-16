#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string.h>
#define endl "\n"
#define MAX 1000
#define INF 99
#define pii pair<pair<int,int>,int>
using namespace std;
int map[MAX][MAX];
int dist[MAX][MAX][2]; // i,j까지 오는데 걸린거리, 벽을 부쉈는지 안부쉈는지(부쉈으면 0, 안부쉈으면 1)
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int n, m;
int answer = INF;

int bfs() {
	queue<pii>q;
	q.push(make_pair(make_pair(0,0),1)); // 0,0 1
	dist[0][0][1] = 1; // 시작하는 칸은 빈 공간
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second;
		if (y == n - 1 && x == m - 1) {
			return dist[y][x][block];
		}
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 > ny || ny >= n || 0 > nx || nx >= m)continue; // 범위 초과			
			if (map[ny][nx] == 1) { // 벽을 만남
				if (block == 1) { // 아직 벽을 안부순 상태
					dist[ny][nx][0] = dist[y][x][1] + 1;
					q.push(make_pair(make_pair(ny, nx),0));
				}
			}
			else if (map[ny][nx] == 0) { // 빈 공간
				if (dist[ny][nx][block] == 0) { // 방문을 안했다면
					dist[ny][nx][block] = dist[y][x][block] + 1;
					q.push(make_pair(make_pair(ny, nx), block));
				}
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	cout << bfs();
	return 0;
}
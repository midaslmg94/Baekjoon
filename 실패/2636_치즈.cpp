#include<bits/stdc++.h>
#define endl "\n"
#define MAX 100
using namespace std;
int n, m;
// 바깥공기와 내부공기를 따로 관리하는게 중요
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int cheese[MAX][MAX]; // 0:빈공간, 1:치즈, 2:바깥공기, 3:녹을 치즈
bool visit[MAX][MAX];
enum { EMPTY = 0, CHEESE, AIR, PREAIR };
void bfs_air() {
	queue<pair<int, int>>q;
	memset(visit, 0, sizeof(visit));
	q.push({ 0,0 });
	cheese[0][0] = AIR;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		visit[y][x] = true;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;
			if (visit[ny][nx])continue;
			if (cheese[ny][nx] == EMPTY) {
				visit[ny][nx] = true;
				cheese[ny][nx] = AIR;
				q.push({ ny,nx });
			}
		}
	}
}
void bfs_melting() {
	queue<pair<int, int>>q;
	memset(visit, 0, sizeof(visit));
	q.push({ 0,0 });
	cheese[0][0] = AIR;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		visit[y][x] = true;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 > ny || ny >= n || 0 > nx || nx >= m)continue;
			if (visit[ny][nx])continue;
			
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheese[i][j];
		}
	}
	int cheese_cnt = 0;
	int answer = 0;
	while (true) {
		// 치즈가 녹아 없어졌는지 확인
		bool isClear = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cheese[i][j] == CHEESE) {
					isClear = false;
				}
			}
		}
		// 치즈가 전부 녹았다면 결과 출력 후 종료
		if (isClear) {
			cout << answer << endl;
			cout << cheese_cnt;
			return 0;
		}		
		bfs_air();// 바깥공기 체크		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << cheese[i][j] << ' ';
			}
			cout << endl;
		}
		bfs_melting();// 치즈 녹이기
		// 남은 치즈 개수 세기
		cheese_cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cheese[i][j] == CHEESE) cheese_cnt++;
			}
		}
		// 1시간 지남
		answer++;
		return 0;
	}

	return 0;
}
#include<iostream>
#include<queue>
#define MAX 1001
using namespace std;
int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

int destoryWall = 1;
bool canGo(int y, int x) {
	bool flag = false;
	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (0 <= ny && ny < n && 0 <= nx && nx < m && !visit[ny][nx]&& map[ny][nx] == 0) {// 한 군데라도 갈수잇음
			flag = true;
			return flag;
		}
	}
	return flag;
}

void destory() {

}
// 벽은 상하좌우 다 부셔봐야 함
void bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x] = true;
	int dist = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (canGo(y, x)) { // 한 군데라도 뚫려있다면
			for (int k = 0; k < 4; k++) {
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (0 <= ny && ny < n && 0 <= nx && nx < m && !visit[ny][nx] && map[ny][nx]==0) {
					q.push({ ny, nx });
					visit[ny][nx] = true;
				}
			}
		}
		else { // 벽을 하나 부셔야함
			bool flag = false;
			for (int k = 0; k < 4; k++) {// 벽을 하나 부시고도 탈출할 수 없는 경우 : -1 출력하고 종료
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (0 <= ny && ny < n && 0 <= nx && nx < m && !visit[ny][nx]) {
					map[ny][nx] = 0;
				}
				flag = canGo(ny, nx);
			}
		}
		dist++;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie();
	freopen("input.txt", "r", stdin);

	cin >> n, m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	bfs(1, 1);
}